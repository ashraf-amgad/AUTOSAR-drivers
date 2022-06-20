#include "Can.h"
#include "Can_reg.h"
#include "CanIf_Cbk.h"
#include "Det.h"


static uint8 CAN_Status = CAN_CS_UNINIT;
const Can_ControllerBaudrateConfigType *CAN_BaudRate_Ptr = NULL_PTR;
const CanHardwareObjectType *CAN_HOH_Ptr = NULL_PTR;
const CanHwFilterType *CAN_Filter_Ptr= NULL_PTR;


#if (CAN_DEV_ERROR_DETECT == STD_ON)
/* AUTOSAR Version checking between Det and Dio Modules */
#if ((DET_AR_MAJOR_VERSION != CAN_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != CAN_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != CAN_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif
#endif


/************************************************************************************
* Service Name: CAN_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): Config: Pointer to driver configuration.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the module.
************************************************************************************/
void Can_Init( const Can_ConfigType* Config )
{
	boolean error = FALSE;
	
	#if (CAN_DEV_ERROR_DETECT == STD_ON)
	
		if (CAN_Status != CAN_CS_UNINIT)
		{
			Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_INIT_SID, CAN_E_TRANSITION);
			error = TRUE;
		}
		
		if (Config == NULL_PTR)
		{
			Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_INIT_SID, CAN_E_PARAM_POINTER);
			error = TRUE;
		}
		
		else 
		{
			/* No action needed */
		}
		
	#endif
		if(error == FALSE)
		{
			CAN_Status = CAN_CS_STOPPED;
			
			
			/* Exit from sleep mode */
			CAN1_MCR &= ~((uint32)(0x01 << 1));

			/* Request initialisation */
			CAN1_MCR |= ((uint32)(0x01 << 0));
				
			/* Wait the acknowledge */	
			while ((CAN1_MSR & (0x01)) != 0x01);	
			
			
			
			if (CAN_TIME_TRIGGER == STD_ENABLE)
			{
				CAN1_MCR |= ((uint32)(0x01 << 7));
			}
			else
			{
				CAN1_MCR &= ~((uint32)(0x01 << 7));
			}

			/* Set the automatic bus-off management */
			if (CAN_AUTO_BUS_OFF == STD_ENABLE)
			{
				CAN1_MCR |= ((uint32)(0x01 << 6));
			}
			else
			{
				CAN1_MCR &= ~((uint32)(0x01 << 6));
			}

			/* Set the automatic wake-up mode */
			if (CAN_AUTO_WAKEUP == STD_ENABLE)
			{
				CAN1_MCR |= ((uint32)(0x01 << 5));
			}
			else
			{
				CAN1_MCR &= ~((uint32)(0x01 << 5));
			}

			/* Set the no automatic retransmission */
			if (CAN_NON_AUTO_RETRANS == STD_ENABLE)
			{
				CAN1_MCR |= ((uint32)(0x01 << 4));
			}
			else
			{
				CAN1_MCR &= ~((uint32)(0x01 << 4));
			}

			/* Set the receive FIFO locked mode */
			if (CAN_RECEIVE_FIFO_LOCKED_MODE == STD_ENABLE)
			{
				CAN1_MCR |= ((uint32)(0x01 << 3));
			}
			else
			{
				CAN1_MCR &= ~((uint32)(0x01 << 3));
			}


			/* Set the transmit FIFO priority */
			if (CAN_TRANSMIT_FIFO_PRIORITY == STD_ENABLE)
			{
				CAN1_MCR |= ((uint32)(0x01 << 2));
			}
			else
			{
				CAN1_MCR &= ~((uint32)(0x01 << 2));
			}
			
			
			uint8 CAN_BaudRate_Counter = 0;
			CAN_BaudRate_Ptr = Can_Configrations.Can_ControllerBaudrateConfigSet;
			
			/* Set the bit timing register */
			/* Normal mode */
			CAN1_BTR &= ~((uint32)(0xC0000000));
			
			for(CAN_BaudRate_Counter = 0 ; CAN_BaudRate_Counter < MAX_NUMBER_OF_SUPORTED_BAUDRATE ; CAN_BaudRate_Counter++)
			{
			
				if(CAN_BaudRate_Ptr[CAN_BaudRate_Counter].CanControllerBaudRate == CAN_CONTROLLER_DEFAULT_BAUDRATE)
				{
					uint8 Ph_Seg1 = CAN_BaudRate_Ptr[CAN_BaudRate_Counter].CanControllerPropSeg + CAN_BaudRate_Ptr[CAN_BaudRate_Counter].CanControllerSeg1;
					CAN1_BTR |= (uint32) ((uint32) (Ph_Seg1 << 16)) |\
															 ((uint32) (CAN_BaudRate_Ptr[CAN_BaudRate_Counter].CanControllerSeg2 << 20)) |\
															 ((uint32) (CAN_BaudRate_Ptr[CAN_BaudRate_Counter].CanControllerSyncJumpWidth << 24)) |\
															 ((uint32) ((CAN_PRESCALER - 1) << 0));
					
					break;
				}
				
				else
				{
						/* No action needed */
				}
				
			}
			
			/* Request leave initialisation */
			CAN1_MCR &= ~((uint32)(0x01 << 0));
			
			/* Wait the acknowledge */	
			while ( (CAN1_MSR & (0x01)) == 0x01 );
		
			
			
			CAN_HOH_Ptr = Can_Configrations.CanHardwareObjectSet;
			uint8 CAN_filter_Counter = 0;
			uint8 CAN_HOH_Counter = 0;
			uint8 Temp_BufferNum = 0;
			uint32 filter_number_bit_pos = 0;
			
			for(CAN_HOH_Counter = 0 ; CAN_HOH_Counter < MAX_NUMBER_OF_FILTERS ; CAN_HOH_Counter++)
			{
					if(CAN_HOH_Ptr[CAN_HOH_Counter].CanObjectType == CanObjectType_RECEIVE)
					{
							Temp_BufferNum = CAN_HOH_Ptr[CAN_HOH_Counter].CanBufferNum;
							filter_number_bit_pos = ((uint32) 0x01) << Temp_BufferNum;
						
							/* Initialisation mode for the filter */
							CAN1_FMR |= ((uint32)(0x01 << 0));
						
							/* Filter Deactivation */
							CAN1_FA1R &= ~(uint32)filter_number_bit_pos;
						
							for(CAN_filter_Counter = 0 ; CAN_filter_Counter < MAX_NUMBER_OF_FILTERS ; CAN_filter_Counter++)
							{
									if (CAN_Filter_Ptr[CAN_filter_Counter].CanFilterNumber == Temp_BufferNum)
									{
										
										CAN_Filter_Ptr = &(Can_Configrations.CanHwFilterSet[CAN_filter_Counter]);
					
									}	
									else
									{
										/* No action needed */
									}						
							}
							
							if(CAN_Filter_Ptr->CanFilterScale == CAN_FilterScale_16bit)
							{
									/* 16-bit scale for the filter */
									CAN1_FS1R &= ~(uint32)filter_number_bit_pos;
								
									/* --> check stdlib function definition for more details <-- */
									/*---------------------------------------------------------------*/
									/* First 16-bit identifier and First 16-bit mask */
								/* Or First 16-bit identifier and Second 16-bit identifier */
								CAN1->sFilterRegister[CAN_Filter_Ptr->CanFilterNumber].FR1 = 
								( (0x0000FFFF & (uint32)(CAN_Filter_Ptr->CanFilterReg2 & 0x0000FFFF) ) << 16) |
									(0x0000FFFF & (uint32)(CAN_Filter_Ptr->CanFilterReg1 & 0x0000FFFF) );

								/* Second 16-bit identifier and Second 16-bit mask */
								/* Or Third 16-bit identifier and Fourth 16-bit identifier */
								CAN1->sFilterRegister[CAN_Filter_Ptr->CanFilterNumber].FR2 = 
								( (0x0000FFFF & (uint32)(CAN_Filter_Ptr->CanFilterReg2 >> 16 ) ) << 16) |
									(0x0000FFFF & (uint32)(CAN_Filter_Ptr->CanFilterReg1 >> 16 ) );
							
							}
							

							else if (CAN_Filter_Ptr->CanFilterScale == CAN_FilterScale_32bit)
							{
								/* 32-bit scale for the filter */
								CAN1_FS1R |= (uint32)filter_number_bit_pos;
								
								/* 32-bit identifier or First 32-bit identifier */
								CAN1->sFilterRegister[CAN_Filter_Ptr->CanFilterNumber].FR1 = 
								(0x7FF00000 & (uint32)(CAN_Filter_Ptr->CanFilterReg1 ) << 21);
								
								/* 32-bit mask or Second 32-bit identifier */
								CAN1->sFilterRegister[CAN_Filter_Ptr->CanFilterNumber].FR1 = 
								(0x7FF00000 & (uint32)(CAN_Filter_Ptr->CanFilterReg2 ) << 21);
							}
							else 
							{
								/* No action needed */
							} 
										

						
							/* Filter Mode */
							if (CAN_Filter_Ptr->CanFilterMode == CAN_FilterMode_IdMask)
							{
								/*Id/Mask mode for the filter*/
								CAN1_FM1R &= ~(uint32)filter_number_bit_pos;
							}
							else if(CAN_Filter_Ptr->CanFilterMode == CAN_FilterMode_IdList)
							{
								/*Identifier list mode for the filter*/
								CAN1->FM1R |= (uint32)filter_number_bit_pos;
							}
							else
							{
								/* No action needed */
							}

							/* Filter FIFO assignment */
							if (CAN_Filter_Ptr->CanFilterFiFoAssignment == CAN_Filter_FIFO0)
							{
								/* FIFO 0 assignation for the filter */
								CAN1_FFA1R &= ~(uint32)filter_number_bit_pos;
							}

							else if (CAN_Filter_Ptr->CanFilterFiFoAssignment == CAN_Filter_FIFO1)
							{
								/* FIFO 1 assignation for the filter */
								CAN1_FFA1R |= (uint32)filter_number_bit_pos;
							}
							
							/* No action needed */
						
							/* Filter activation */
								CAN1_FA1R |= filter_number_bit_pos;

							/* Leave the initialisation mode for the filter */
							CAN1_FMR &= ~(0x01 << 0);
							
					}
					
			}
			
	}
		
	CAN_Status = CAN_CS_STARTED;
		
}

/************************************************************************************
* Service Name: Can_GetVersionInfo
* Service ID[hex]: 0x07
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): versioninfo: Pointer to where to store the version information of this module.
* Return value: None
* Description: This function returns the version information of this module.
************************************************************************************/
void Can_GetVersionInfo( Std_VersionInfoType* versioninfo )
{
	
}

/************************************************************************************
* Service Name: Can_CheckBaudrate
* Service ID[hex]: 0x0e
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Controller: CAN Controller to check for the support of a certain baudrate
					Baudrate: Baudrate to check in kbps
* Parameters (inout): None
* Parameters (out): None
* Return value: Std_ReturnType  E_OK: Baudrate supported by the CAN Controller  
								E_NOT_OK: Baudrate not supported / invalid CAN controller
* Description: This service shall check, if a certain CAN controller supports a requested baudrate.
************************************************************************************/
Std_ReturnType Can_CheckBaudrate( uint8 Controller, const uint16 Baudrate )
{
	uint8 Check_BaudRate_counter = 0;
	boolean error; 
	//Error check
	#if (CAN_DEV_ERROR_DETECT == STD_ON)
		if (CAN_Status == CAN_CS_UNINIT)
		{
			Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_CHECK_BAUDRATE_SID, CAN_E_UNINIT);
			error = TRUE;
		}
		
		if (Controller > CAN_MAX_NUM_OF_CONTROLLER)
		{
			Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_CHECK_BAUDRATE_SID, CAN_E_PARAM_CONTROLLER);
			error = TRUE;
		}
		
		if (Baudrate > CAN_MAX_BAUDRATE)
		{
			Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_CHECK_BAUDRATE_SID, CAN_E_PARAM_BAUDRATE);
			error = TRUE;
		}
		
		else 
		{
			error = FALSE;
		}
	#endif
	
	CAN_BaudRate_Ptr = Can_Configrations.Can_ControllerBaudrateConfigSet;
		
	if(error == FALSE)
	{
	
		for(Check_BaudRate_counter=0;Check_BaudRate_counter<MAX_NUMBER_OF_SUPORTED_BAUDRATE;Check_BaudRate_counter++)
		{
			
			if(CAN_BaudRate_Ptr[Check_BaudRate_counter].CanControllerBaudRate == Baudrate)
			{
					return E_OK;
			}
			
			else
			{
					return E_NOT_OK;
			}
			
		}
	
	}
	else
	{
		/* No action needed */
	}
	
}

/************************************************************************************
* Service Name: Can_ChangeBaudrate
* Service ID[hex]: 0x0d
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): Controller: CAN Controller, whose baudrate shall be changed
					Baudrate: Requested baudrate in kbps
* Parameters (inout): None
* Parameters (out): None
* Return value: Std_ReturnType  E_OK: Service request accepted, baudrate change started 
								E_NOT_OK: Service request not accepted
* Description: This service shall change the baudrate of the CAN controller.
************************************************************************************/
Std_ReturnType Can_ChangeBaudrate( uint8 Controller, const uint16 Baudrate )
{
	int Check_BaudRate_counter = 0;
	
	for(Check_BaudRate_counter=0;Check_BaudRate_counter<MAX_NUMBER_OF_SUPORTED_BAUDRATE;Check_BaudRate_counter++)
	{
		if(Can_Configrations.Can_ControllerBaudrateConfigSet[Check_BaudRate_counter].CanControllerBaudRate == Baudrate)
		{
			
			 CAN1_BTR |= ( (Can_Configrations.Can_ControllerBaudrateConfigSet[Check_BaudRate_counter].CanControllerPropSeg) +
										(Can_Configrations.Can_ControllerBaudrateConfigSet[Check_BaudRate_counter].CanControllerSeg1 << 16) );
		
		
			
		return E_OK;
		}
		
		
		else
				return E_NOT_OK;
 }
}

/************************************************************************************
* Service Name: Can_SetControllerMode
* Service ID[hex]: 0x03
* Sync/Async: Asynchronous
* Reentrancy: Non Reentrant
* Parameters (in): Controller: CAN controller for which the status shall be changed
					Transition: Transition value to request new CAN controller state
* Parameters (inout): None
* Parameters (out): None
* Return value: Can_ReturnType  CAN_OK: request accepted
							    CAN_NOT_OK: request not accepted, a development error occurred
* Description: This function performs software triggered state transitions of the CAN controller State machine.
************************************************************************************/
Can_ReturnType Can_SetControllerMode( uint8 Controller, Can_StateTransitionType Transition )
{
	boolean error; 
	//Error check
	#if (CAN_DEV_ERROR_DETECT == STD_ON)
		if (CAN_Status != CAN_CS_UNINIT)
		{
			Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_CHECK_BAUDRATE_SID, CAN_E_UNINIT);
			error = TRUE;
		}
		
		if (Controller > CAN_MAX_NUM_OF_CONTROLLER)
		{
			Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_CHECK_BAUDRATE_SID, CAN_E_PARAM_CONTROLLER);
			error = TRUE;
		}
		

		else 
		{
			error = FALSE;
		}
	#endif
		if(FALSE != error)
		{
				if((Transition == CAN_T_START) && (CAN_Status != CAN_CS_STOPPED))
				{
					Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_CHECK_BAUDRATE_SID, CAN_E_UNINIT);
					error = TRUE;
				}
				else
				{
						/* normal mode */
						CAN1_MCR &= ~((uint32)(0x01 << 0));
					  CAN_Status = CAN_CS_STARTED;
				}
				
				if((Transition == CAN_T_STOP) && ((CAN_Status != CAN_CS_STOPPED) || (CAN_Status != CAN_CS_STARTED)) )
				{
					Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_CHECK_BAUDRATE_SID, CAN_E_UNINIT);
					error = TRUE;
				}
				else
				{
						/* silent and loopback */
					 /* cancel pending massage */
					CAN1_BTR |= ((uint32)(0xC0000000));
					CAN1_TSR |= ((uint32)(0x00808080));
					 CAN_Status = CAN_CS_STOPPED;
				}
				
				if((Transition == CAN_T_SLEEP) && ((CAN_Status != CAN_CS_STOPPED) || (CAN_Status != CAN_CS_SLEEP)) )
				{
					Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_CHECK_BAUDRATE_SID, CAN_E_UNINIT);
					error = TRUE;
				}
				else
				{
						/* sleep mode */
						CAN1_MCR &= ~((uint32)(0x01 << 1));
					  CAN_Status = CAN_CS_SLEEP;
				}
				
				if((Transition == CAN_T_WAKEUP) && ((CAN_Status != CAN_CS_STOPPED) || (CAN_Status != CAN_CS_SLEEP)) )
				{
					Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_CHECK_BAUDRATE_SID, CAN_E_UNINIT);
					error = TRUE;
				}
				else
				{
						CAN_Status = CAN_CS_STOPPED;
				}	
		
		}
		
		if(error == TRUE)
		{
			return CAN_NOT_OK;
		}
		else /*(error == FALSE)*/
		{
			return CAN_OK;
		}
			
}

/************************************************************************************
* Service Name: Can_DisableControllerInterrupts
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Controller CAN controller for which interrupts shall be disabled.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: This function disables all interrupts for this CAN controller.
************************************************************************************/
void Can_DisableControllerInterrupts( uint8 Controller )
{
	
}

/************************************************************************************
* Service Name: Can_EnableControllerInterrupts
* Service ID[hex]: 0x05
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Controller: CAN controller for which interrupts shall be re-enabled.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: This function enables all allowed interrupts.
************************************************************************************/
void Can_EnableControllerInterrupts( uint8 Controller )
{
	
}

/************************************************************************************
* Service Name: Can_CheckWakeup
* Service ID[hex]: 0x0b
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): Controller: Controller to be checked for a wakeup.
* Parameters (inout): None
* Parameters (out): None
* Return value: Can_ReturnType CAN_OK: A wakeup was detected for the given controller. 
							   CAN_NOT_OK: No wakeup was detected for the given controller.
* Description: This function checks if a wakeup has occurred for the given controller.
************************************************************************************/
Can_ReturnType Can_CheckWakeup( uint8 Controller )
{
	
}

/************************************************************************************
* Service Name: Can_Write
* Service ID[hex]: 0x06
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Hth  information which HW-transmit handle shall be used for transmit. Implicitly this is also the information about the controller to use because the Hth numbers are unique inside one hardware unit.
				   PduInfo Pointer to SDU user memory, DLC and Identifier.
* Parameters (inout): None
* Parameters (out): None
* Return value: Can_ReturnType
								CAN_OK: Write command has been accepted 
								CAN_NOT_OK: development error occurred 
								CAN_BUSY: No TX hardware buffer available or pre-emptive call of Can_Write that can't be implemented re-entrant
* Description: --
************************************************************************************/
Can_ReturnType Can_Write( Can_HwHandleType Hth, const Can_PduType* PduInfo )
{
	
	
	
}


