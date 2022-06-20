#ifndef __CAN_CFG_H__
#define __CAN_CFG_H__


#define CAN_CFG_SW_MAJOR_VERSION 		(1U)
#define CAN_CFG_SW_MINOR_VERSION 		(0U)
#define CAN_CFG_SW_PATCH_VERSION 		(0U)

/* AUTOSAR Version 4.0.3 */
#define CAN_CFG_AR_RELEASE_MAJOR_VERSION   (4U)
#define CAN_CFG_AR_RELEASE_MINOR_VERSION   (0U)
#define CAN_CFG_AR_RELEASE_PATCH_VERSION   (3U)



#include "Std_Types.h"
/*---------------------------------------*/
/* AUTOSAR checking between Can_cfg.h and Std_Types.h files */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != CAN_CFG_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != CAN_CFG_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != CAN_CFG_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Can_cfg.h does not match the expected version"
#endif


/* Software Version checking between Can_cfg.h and Can.h files */
#if  ( (STD_TYPES_SW_MAJOR_VERSION != CAN_CFG_SW_MAJOR_VERSION)\
    || (STD_TYPES_SW_MINOR_VERSION != CAN_CFG_SW_MINOR_VERSION)\
    || (STD_TYPES_SW_PATCH_VERSION != CAN_CFG_SW_PATCH_VERSION) )
#error "The SW version of Can_cfg.h does not match the expected version"
#endif




/**************************/


/* Pre-compile option for Development Error Detect */
#define CAN_DEV_ERROR_DETECT                (STD_ON)

/* Pre-compile option for Version Info API */
#define CAN_VERSION_INFO_API                (STD_ON)


#define CAN_0_ID										(0U)

#define CAN_MAX_NUM_OF_CONTROLLER 	(1U)

#define CAN_CPU_CLOCK_REF						(0U)

/* CAN_TIME_TRIGGER can be set either to STD_DISABLE or STD_ENABLE */
#define	CAN_TIME_TRIGGER														STD_DISABLE

/* CAN_AUTO_BUS_OFF can be set either to STD_DISABLE or STD_ENABLE */
#define	CAN_AUTO_BUS_OFF															STD_DISABLE

/* CAN_AUTO_WAKEUP can be set either to STD_DISABLE or STD_ENABLE */
#define	CAN_AUTO_WAKEUP															STD_DISABLE

/* CAN_NON_AUTO_RETRANS can be set either to STD_DISABLE or STD_ENABLE */
#define	CAN_NON_AUTO_RETRANS												STD_ENABLE

/* CAN_RECEIVE_FIFO_LOCKED_MODE can be set either to STD_DISABLE or STD_ENABLE */
#define	CAN_RECEIVE_FIFO_LOCKED_MODE								STD_DISABLE

/* CAN_TRANSMIT_FIFO_PRIORITY can be set either to STD_DISABLE or STD_ENABLE */ 
#define	CAN_TRANSMIT_FIFO_PRIORITY									STD_DISABLE

// CAN_MODE can be a value of CAN_Mode_Normal ,CAN_Mode_Silent ,CAN_Mode_LoopBack or CAN_Mode_Silent_LoopBac
//#define	CAN_MODE																		CAN_Mode_Normal



/* CAN_PRESCALER ranges from 1 to 1024. */
#define CAN_PRESCALER											   					(5U)


#define CAN_MAX_BAUDRATE			(1000)
#define CAN_CONTROLLER_DEFAULT_BAUDRATE								(CAN_CONTROLLER_BAUDRATE_250_Khz)


#define CAN_CHANGE_BAUDRATE_SUPPORT				(STD_ON)
#define MAX_NUMBER_OF_SUPORTED_BAUDRATE			(3U)



#define CAN_CONTROLLER_BAUDRATE_250_Khz				        (0U)
#define CAN_CONTROLLER_BAUDRATE_250_Khz_PROPSEG				(0U)
#define CAN_CONTROLLER_BAUDRATE_250_Khz_SEG1					(1U)
#define CAN_CONTROLLER_BAUDRATE_250_Khz_SEG2					(2U)
#define CAN_CONTROLLER_BAUDRATE_250_Khz_SJW						(3U)

#define CAN_CONTROLLER_BAUDRATE_500_Khz			        	(1U)
#define CAN_CONTROLLER_BAUDRATE_500_Khz_PROPSEG				(4U)
#define CAN_CONTROLLER_BAUDRATE_500_Khz_SEG1					(5U)
#define CAN_CONTROLLER_BAUDRATE_500_Khz_SEG2					(6U)
#define CAN_CONTROLLER_BAUDRATE_500_Khz_SJW						(7U)

#define CAN_CONTROLLER_BAUDRATE_750_Khz				        (2U)
#define CAN_CONTROLLER_BAUDRATE_750_Khz_PROPSEG				(8U)
#define CAN_CONTROLLER_BAUDRATE_750_Khz_SEG1					(9U)
#define CAN_CONTROLLER_BAUDRATE_750_Khz_SEG2					(10U)
#define CAN_CONTROLLER_BAUDRATE_750_Khz_SJW						(11U)




/********************************/
#define CAN_UNINIT     			( 0x00U )
#define CAN_READY      			( 0x01U )


#define MAX_DATA_LENGTH         (8U)
#define IS_CAN_DLC(DLC)       ((DLC) <= ((uint8_t)MAX_DATA_LENGTH) )



#define CAN_FilterMode_IdMask       (0x00)  /*!< identifier/mask mode */
#define CAN_FilterMode_IdList       (0x01)  /*!< identifier list mode */
#define IS_CAN_FILTER_MODE(MODE) (((MODE) == CAN_FilterMode_IdMask) || \
                                  ((MODE) == CAN_FilterMode_IdList))



#define CAN_FilterScale_16bit       (0x00) /*!< Two 16-bit filters */
#define CAN_FilterScale_32bit       (0x01) /*!< One 32-bit filter */
#define IS_CAN_FILTER_SCALE(SCALE) (((SCALE) == CAN_FilterScale_16bit) || \
                                    ((SCALE) == CAN_FilterScale_32bit))
																		
#define CAN_Filter_FIFO0             (0x00)  /*!< Filter FIFO 0 assignment for filter x */
#define CAN_Filter_FIFO1             (0x01)  /*!< Filter FIFO 1 assignment for filter x */
#define IS_CAN_FILTER_FIFO(FIFO) (((FIFO) == CAN_FilterFIFO0) || \
                                  ((FIFO) == CAN_FilterFIFO1))
																	
																	
#define IS_CAN_FILTER_NUMBER(NUMBER) ((NUMBER) <= 13)


#define MAX_NUMBER_OF_FILTERS		(13U)
#define MAX_NUMBER_OF_MAILBOXES (3u)


/* enum */
#define CanHandleType_BASIC       		( 0x00U )
#define CanHandleType_FULL        		( 0x01U )

#define CanObjectType_RECEIVE   		 ( 0x00U )
#define CanObjectType_TRANSMIT    	 ( 0x01U )




#define CanIdType_EXTENDED   		 ( 0x00U )
#define CanIdType_MIXED      		 ( 0x01U ) 
#define CanIdType_STANDARD    	 ( 0x02U )

#define IS_CAN_STDID(STDID)   ((STDID) <= ((uint32_t)0x7FF))
#define IS_CAN_EXTID(EXTID)   ((EXTID) <= ((uint32_t)0x1FFFFFFF))






//#define MAX_NUMBER_OF_HARDWARE_OBJECT_Assigned_To_HRH		(3U)
//#define MAX_NUMBER_OF_HARDWARE_OBJECT_Assigned_To_HTH		(3U)
#define MAX_NUMBER_OF_HARDWARE_OBJECT	((6U))









#define CAN_Filter_0_Num		(0U)
#define CAN_Filter_1_Num		(1U)
#define CAN_Filter_2_Num		(2U)
#define CAN_Filter_3_Num		(3U)
#define CAN_Filter_4_Num		(4U)
#define CAN_Filter_5_Num		(5U)
#define CAN_Filter_6_Num		(6U)
#define CAN_Filter_7_Num		(7U)
#define CAN_Filter_8_Num		(8U)
#define CAN_Filter_9_Num		(11U)
#define CAN_Filter_10_Num		(10U)
#define CAN_Filter_11_Num		(11U)
#define CAN_Filter_12_Num		(12U)
#define CAN_Filter_13_Num		(13U)


#define CAN_MailBox_1 			(0U)
#define CAN_MailBox_2 			(1U)
#define CAN_MailBox_3 			(2U)
#define CAN_MailBox_Any 		(3U)

#define CAN_HRH_0		(0U)
#define CAN_HRH_1		(1U)
#define CAN_HRH_2		(2U)
#define CAN_HTH_0		(3U)
#define CAN_HTH_1		(4U)
#define CAN_HTH_2		(5U)

#define CAN_HOH_0_HandleType 			(CanHandleType_BASIC)
#define CAN_HOH_0_ObjectType 			(CanObjectType_RECEIVE)
#define CAN_HOH_0_Count 								(1U)
#define CAN_HOH_0_IdType 					(CanIdType_STANDARD)
#define CAN_HOH_0_Buffer_Num 			(CAN_Filter_0_Num)


#define CAN_HOH_1_HandleType 			(CanHandleType_BASIC)
#define CAN_HOH_1_ObjectType 			(CanObjectType_RECEIVE)
#define CAN_HOH_1_Count 								(1U)
#define CAN_HOH_1_IdType 					(CanIdType_STANDARD)
#define CAN_HOH_1_Buffer_Num 			(CAN_Filter_1_Num)


#define CAN_HOH_2_HandleType 			(CanHandleType_BASIC)
#define CAN_HOH_2_ObjectType 			(CanObjectType_RECEIVE)
#define CAN_HOH_2_Count 								(1U)
#define CAN_HOH_2_IdType 					(CanIdType_STANDARD)
#define CAN_HOH_2_Buffer_Num 			(CAN_Filter_2_Num)


#define CAN_HOH_3_HandleType 			(CanHandleType_BASIC)
#define CAN_HOH_3_ObjectType 			(CanObjectType_TRANSMIT)
#define CAN_HOH_3_Count 								(1U)
#define CAN_HOH_3_IdType 					(CanIdType_STANDARD)
#define CAN_HOH_3_Buffer_Num 			(CAN_MailBox_Any)


#define CAN_HOH_4_HandleType 			(CanHandleType_BASIC)
#define CAN_HOH_4_ObjectType 			(CanObjectType_TRANSMIT)
#define CAN_HOH_4_Count 								(1U)
#define CAN_HOH_4_IdType 					(CanIdType_STANDARD)
#define CAN_HOH_4_Buffer_Num 			(CAN_MailBox_Any)

#define CAN_HOH_5_HandleType 			(CanHandleType_BASIC)
#define CAN_HOH_5_ObjectType 			(CanObjectType_TRANSMIT)
#define CAN_HOH_5_Count 								(1U)
#define CAN_HOH_5_IdType 					(CanIdType_STANDARD)
#define CAN_HOH_5_Buffer_Num 			(CAN_MailBox_Any)




#define CAN_Filter_0_Mode						 (CAN_FilterMode_IdMask)
#define CAN_Filter_0_Scale					 (CAN_FilterScale_32bit)
#define CAN_Filter_0_FiFoAssignment	 (CAN_Filter_FIFO0)
#define CAN_Filter_0_Reg1	 					 			(0x050)
#define CAN_Filter_0_Reg2	 					 			(0x7ff)

#define CAN_Filter_1_Mode						 (CAN_FilterMode_IdMask)
#define CAN_Filter_1_Scale					 (CAN_FilterScale_32bit)
#define CAN_Filter_1_FiFoAssignment	 (CAN_Filter_FIFO0)
#define CAN_Filter_1_Reg1	 					 			(0x100)
#define CAN_Filter_1_Reg2	 					 			(0x7ff)

#define CAN_Filter_2_Mode						 (CAN_FilterMode_IdMask)
#define CAN_Filter_2_Scale					 (CAN_FilterScale_32bit)
#define CAN_Filter_2_FiFoAssignment	 (CAN_Filter_FIFO0)
#define CAN_Filter_2_Reg1	 					 			(0x110)
#define CAN_Filter_2_Reg2	 					 			(0x7ff)








/***********************************************/

#endif

