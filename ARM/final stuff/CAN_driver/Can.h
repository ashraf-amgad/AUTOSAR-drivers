/**
  ******************************************************************************
  *
  * @Module: CAN
  * @FileName: CAN.h
  * @Description: Header file for  CAN Module.
  * @version: 1.0.0
  * @date:    xx-xx-2020
  * @Authors: Ahmed Khamis && Ashraf Amgad && Islam Elsnousy && Toka abdelhakim
  *
  ******************************************************************************
  */

#ifndef __CAN_H__
#define __CAN_H__



#define CAN_VENDOR_ID    (1000U)
#define CAN_MODULE_ID    (120U)
#define CAN_INSTANCE_ID  (0U)

#define CAN_SW_MAJOR_VERSION 		(1U)
#define CAN_SW_MINOR_VERSION 		(0U)
#define CAN_SW_PATCH_VERSION 		(0U)

/* AUTOSAR Version 4.0.3 */
#define CAN_AR_RELEASE_MAJOR_VERSION   (4U)
#define CAN_AR_RELEASE_MINOR_VERSION   (0U)
#define CAN_AR_RELEASE_PATCH_VERSION   (3U)


/*****************************************************************************************
*                                   Include Headres                                     *
*****************************************************************************************/

#include "Can_GeneralTypes.h"
/*---------------------------------------*/
/* AUTOSAR checking between Can_GeneralTypes.h and Can.h files */
#if ((CAN_AR_RELEASE_MAJOR_VERSION != CAN_GENERAL_TYPES_AR_RELEASE_MAJOR_VERSION)\
 ||  (CAN_AR_RELEASE_MINOR_VERSION != CAN_GENERAL_TYPES_AR_RELEASE_MINOR_VERSION)\
 ||  (CAN_AR_RELEASE_PATCH_VERSION != CAN_GENERAL_TYPES_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of CAN_GeneralTypes.h does not match the expected version"
#endif


/* Software Version checking between Can_GeneralTypes.h and Can.h files */
#if  ( (CAN_SW_MAJOR_VERSION != CAN_GENERAL_TYPES_SW_MAJOR_VERSION)\
    || (CAN_SW_MINOR_VERSION != CAN_GENERAL_TYPES_SW_MINOR_VERSION)\
    || (CAN_SW_PATCH_VERSION != CAN_GENERAL_TYPES_SW_PATCH_VERSION) )
#error "The SW version of CAN_GeneralTypes.h does not match the expected version"
#endif



#include "Can_Cfg.h"
/*---------------------------------------*/
/* AUTOSAR checking between Can_cfg.h and Can.h files */
#if ((CAN_AR_RELEASE_MAJOR_VERSION != CAN_CFG_AR_RELEASE_MAJOR_VERSION)\
 ||  (CAN_AR_RELEASE_MINOR_VERSION != CAN_CFG_AR_RELEASE_MINOR_VERSION)\
 ||  (CAN_AR_RELEASE_PATCH_VERSION != CAN_CFG_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Can_cfg.h does not match the expected version"
#endif


/* Software Version checking between Can_cfg.h and Can.h files */
#if  ( (CAN_SW_MAJOR_VERSION != CAN_CFG_SW_MAJOR_VERSION)\
    || (CAN_SW_MINOR_VERSION != CAN_CFG_SW_MINOR_VERSION)\
    || (CAN_SW_PATCH_VERSION != CAN_CFG_SW_PATCH_VERSION) )
#error "The SW version of Can_cfg.h does not match the expected version"
#endif


#include "ComStack_Types.h"
/*---------------------------------------*/
/* AUTOSAR checking between CAN_GeneralTypes.h and CAN.h files */
#if ((CAN_AR_RELEASE_MAJOR_VERSION != COMSTACK_TYPES_AR_RELEASE_MAJOR_VERSION)\
 ||  (CAN_AR_RELEASE_MINOR_VERSION != COMSTACK_TYPES_AR_RELEASE_MINOR_VERSION)\
 ||  (CAN_AR_RELEASE_PATCH_VERSION != COMSTACK_TYPES_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif


/* Software Version checking between CAN_GeneralTypes.h and CAN.h files */
#if  ( (CAN_SW_MAJOR_VERSION != COMSTACK_TYPES_SW_MAJOR_VERSION)\
    || (CAN_SW_MINOR_VERSION != COMSTACK_TYPES_SW_MINOR_VERSION)\
    || (CAN_SW_PATCH_VERSION != COMSTACK_TYPES_SW_PATCH_VERSION) )
#error "The SW version of PBcfg.c does not match the expected version"
#endif


#include "Common_Macros.h"
/*---------------------------------------*/
/* Software Version checking between CAN_GeneralTypes.h and CAN.h files */
#if  ( (CAN_SW_MAJOR_VERSION != COMMON_MACROS_SW_MAJOR_VERSION)\
    || (CAN_SW_MINOR_VERSION != COMMON_MACROS_SW_MINOR_VERSION)\
    || (CAN_SW_PATCH_VERSION != COMMON_MACROS_SW_PATCH_VERSION) )
#error "The SW version of PBcfg.c does not match the expected version"
#endif

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/

typedef  uint8  Can_ServiceId;


#define  CAN_INIT_SID                             ( (Can_ServiceId)0x00 )
#define  CAN_GET_VERSION_INFO_SID                 ( (Can_ServiceId)0x07 )
#define  CAN_CHECK_BAUDRATE_SID                   ( (Can_ServiceId)0x0e )
#define  CAN_CHANGE_BAUDRATE_SID                  ( (Can_ServiceId)0x0f )
#define  CAN_SET_CONTROLLER_MODE_SID              ( (Can_ServiceId)0x03 )
#define  CAN_DISABLE_CONTROLLER_INTERRUPTS_SID    ( (Can_ServiceId)0x04 )
#define  CAN_ENABLE_CONTROLLER_INTERRUPTS_SID     ( (Can_ServiceId)0x05 )
#define  CAN_CHECK_WAKEUP_SID                     ( (Can_ServiceId)0x0b )
#define  CAN_WRITE_SID                            ( (Can_ServiceId)0x06 )
#define  CAN_MAIN_FUNCTION_WRITE_SID              ( (Can_ServiceId)0x01 )
#define  CAN_MAIN_FUNCTION_READ_SID               ( (Can_ServiceId)0x08 )
#define  CAN_MAIN_FUNCTION_BUSOFF_SID             ( (Can_ServiceId)0x09 )
#define  CAN_MAIN_FUNCTION_WAKEUP_SID             ( (Can_ServiceId)0x0a )
#define  CAN_MAINFUNCTION_MODE_SID                ( (Can_ServiceId)0x0c )


/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/

typedef  uint8  Can_DetErrorType;


#define CAN_E_PARAM_POINTER              ((Can_DetErrorType)0x01)
#define CAN_E_PARAM_HANDLE               ((Can_DetErrorType)0x02)
#define CAN_E_PARAM_DLC                  ((Can_DetErrorType)0x03)
#define CAN_E_PARAM_CONTROLLER           ((Can_DetErrorType)0x04)
#define CAN_E_UNINIT                     ((Can_DetErrorType)0x05)
#define CAN_E_TRANSITION                 ((Can_DetErrorType)0x06)
#define CAN_E_DATALOST                   ((Can_DetErrorType)0x07)
/* this error is not in the scope of autosar sws but we need it in function like Can_ChangeBaudrate() */
#define CAN_E_PARAM_BAUDRATE             ((Can_DetErrorType)0x08)





/*******************************************************************************
 *                      Module Data Types                                      *
 *******************************************************************************/


typedef uint32*  Ptr2Reg;


typedef struct Can_Pdu
{
   PduIdType     swPduHandle ;  /* PDU ID */
   uint8         DLC;           /* DLC */
   Can_IdType    id ;           /* ID */
   uint8*        sdu ;          /* Data */
}Can_PduType; /*This type is used to provide ID, DLC and SDU from CAN interface to CAN driver.*/



typedef enum
{
    CAN_T_START, /*CAN controller transition value to request state STARTED.*/
    CAN_T_STOP,  /*CAN controller transition value to request state STOPPED.*/
    CAN_T_SLEEP, /*CAN controller transition value to request state SLEEP.*/
    CAN_T_WAKEUP /*CAN controller transition value to request state STOPPED from state SLEEP.*/
}Can_StateTransitionType;



typedef enum
{
    CAN_OK, 		/*success*/
    CAN_NOT_OK, /*error occurred or wakeup event occurred during sleep transition*/
    CAN_BUSY 		/*transmit request could not be processed because no transmit object was available*/
}Can_ReturnType;

/* we might need it later */
/* typedef float64 McuClockReferencePointType; */


typedef struct
{
	/* Specifies the baudrate of the controller in kbps */
	uint16 CanControllerBaudRate; /* Range min=0 to max=2000 */

	/* Specifies propagation delay in time quantas */
	uint8 CanControllerPropSeg; /* Range min=0 to max=255 */

	/* Specifies phase segment 1 in time quantas*/
	uint8 CanControllerSeg1; /* Range min=0 to max=255 */

	/* Specifies phase segment 2 in time quantas*/
	uint8 CanControllerSeg2; /* Range min=0 to max=255 */

	/* Specifies the synchronization jump width for the controller in time quantas*/
	uint8 CanControllerSyncJumpWidth; /* Range min=0 to max=255 */

}Can_ControllerBaudrateConfigType;






typedef struct
{
	uint8  CanFilterNumber;             /* the id of the filter */

	uint8  CanFilterMode;               /* list or mask */

	uint8  CanFilterScale;              /* 16 or 32 */

	uint8  CanFilterFiFoAssignment;     /* the filter is either assignment to FIFO1 or FIFO2 */

	uint32  CanFilterReg1;              /* reg1 */

	uint32  CanFilterReg2;              /* reg2 */


} CanHwFilterType;


typedef struct
{


    uint8 CanHandleType;    /* Specifies the type (Full-CAN or Basic-CAN) of a hardware object. */


    uint8   CanObjectType; /* Specifies if the HardwareObject is used as Transmit or as Receive object */


    uint16 CanHwObjectCount; /*   Number of hardware objects used to implement one HOH. In case of a
                              *   HRH this parameter defines the number of elements in the hardware FIFO
                              *   or the number of shadow buffers, in case of a HTH it defines the number of
                              *   hardware objects used for multiplexed transmission or for a hardware FIFO
                              *   used by a FullCAN HTH.*/



    uint16 CanObjectId;/* Holds the handle ID of HRH or HTH. The value of this parameter is unique
                        *   in a given CAN Driver, and it should start with 0 and continue without any gaps.
                        *   The HRH and HTH Ids share a common ID range.
                        *   Example: HRH0-0, HRH1-1, HTH0-2, HTH1-3 */



   uint16 CanBufferNum; /*it represents the number of either the filter or mailbox its assigned to in the objecttype */

    uint8 CanIdType; /* Specifies the IdValuetype (EXTENDED , STANDARD or MIXED ) */


} CanHardwareObjectType;


//typedef struct
//{

//	uint8		MailBox_Number;
//	uint8		MailBox_HOH_AssignedTo;

//}Can_MailBoxType;



typedef struct
{
	Can_ControllerBaudrateConfigType    Can_ControllerBaudrateConfigSet[MAX_NUMBER_OF_SUPORTED_BAUDRATE];   /*array of the configured BRS */
	CanHardwareObjectType  							CanHardwareObjectSet[MAX_NUMBER_OF_HARDWARE_OBJECT];                /* array of the configured HOH */
	CanHwFilterType  										CanHwFilterSet[MAX_NUMBER_OF_FILTERS];                              /* array of the configured filters */
//	Can_MailBoxType 										MailBox_Number[MAX_NUMBER_OF_MAILBOXES];                            /*array of the available mailboxes */

}Can_ConfigType;



/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/
extern const Can_ConfigType Can_Configrations;

void Can_Init(const Can_ConfigType* Config);


void Can_GetVersionInfo(Std_VersionInfoType* versioninfo);


Std_ReturnType Can_CheckBaudrate(uint8 Controller , const uint16 Baudrate);


Std_ReturnType Can_ChangeBaudrate(uint8 Controller , const uint16 Baudrate);


Can_ReturnType Can_SetControllerMode(uint8 Controller , Can_StateTransitionType Transition);


void Can_DisableControllerInterrupts(uint8 Controller);


void Can_EnableControllerInterrupts(uint8 Controller);


Can_ReturnType Can_CheckWakeup(uint8 Controller);


Can_ReturnType Can_Write(Can_HwHandleType Hth , const Can_PduType* PduInfo);


void Can_MainFunction_Write(void);


void Can_MainFunction_Read(void);


void Can_MainFunction_BusOff(void);


void Can_MainFunction_Wakeup(void);


void Can_MainFunction_Mode(void);



#endif /* CAN_H_ */



