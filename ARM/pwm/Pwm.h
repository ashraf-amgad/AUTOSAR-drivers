/**
  ******************************************************************************
  *
  * @Module: PWM
  * @FileName: Pwm.h
  * @Description: Header file for  PWM Module.
  * @version: 1.0.0
  * @date:    xx-xx-2020
  * @Authors: Ashraf Amgad
  *
  ******************************************************************************
  */

#ifndef __PWM_H__
#define __PWM_H__

/**@ATTENTION
 * I CHANGED (UINT16 DUTYCYCLE) TO (FLOAT32 DUTYCYCLE) TO MAKE IT SIMPLE FOR THE USER.
 * INSTEED OF USING DUTY CYCLE AS REGISTER NUMBER AND RATIO OF ARR REGISTER IT WILL BE PERCENTAGE NUMBER ONLY. 
 */

#define PWM_VENDOR_ID    (1000U)
#define PWM_MODULE_ID    (120U)
#define PWM_INSTANCE_ID  (0U)

#define PWM_SW_MAJOR_VERSION 		(1U)
#define PWM_SW_MINOR_VERSION 		(0U)
#define PWM_SW_PATCH_VERSION 		(0U)

/* AUTOSAR Version 4.0.3 */
#define PWM_AR_RELEASE_MAJOR_VERSION   (4U)
#define PWM_AR_RELEASE_MINOR_VERSION   (0U)
#define PWM_AR_RELEASE_PATCH_VERSION   (3U)


/*****************************************************************************************
*                                   Include Headres                                     *
*****************************************************************************************/

#include "Pwm_Cfg.h"
/*---------------------------------------*/
/* AUTOSAR checking between Can_cfg.h and Can.h files */
#if ((PWM_AR_RELEASE_MAJOR_VERSION != PWM_CFG_AR_RELEASE_MAJOR_VERSION)\
 ||  (PWM_AR_RELEASE_MINOR_VERSION != PWM_CFG_AR_RELEASE_MINOR_VERSION)\
 ||  (PWM_AR_RELEASE_PATCH_VERSION != PWM_CFG_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Pwm_cfg.h does not match the expected version"
#endif


/* Software Version checking between Pwm_cfg.h and Pwm.h files */
#if  ( (PWM_SW_MAJOR_VERSION != PWM_CFG_SW_MAJOR_VERSION)\
    || (PWM_SW_MINOR_VERSION != PWM_CFG_SW_MINOR_VERSION)\
    || (PWM_SW_PATCH_VERSION != PWM_CFG_SW_PATCH_VERSION) )
#error "The SW version of Pwm_cfg.h does not match the expected version"
#endif



#include "Common_Macros.h"
/*---------------------------------------*/
/* Software Version checking between Pwm_GeneralTypes.h and Pwm.h files */
#if  ( (PWM_SW_MAJOR_VERSION != COMMON_MACROS_SW_MAJOR_VERSION)\
    || (PWM_SW_MINOR_VERSION != COMMON_MACROS_SW_MINOR_VERSION)\
    || (PWM_SW_PATCH_VERSION != COMMON_MACROS_SW_PATCH_VERSION) )
#error "The SW version of Common_Macros.h does not match the expected version"
#endif


#include "Pwm_reg.h"


#define PWM_UNINIT  (0)
#define PWM_INIT	(1)


#define MAX_NUMBER_OF_SUPORTED_CHANNELS 	((uint8) 12)



/* timer 2 channel 1 */
#define Pwm_Channel_1		( (Pwm_ChannelType) 0)

/* timer 2 channel 2 */
#define Pwm_Channel_2		( (Pwm_ChannelType) 1)

/* timer 2 channel 3 */
#define Pwm_Channel_3		( (Pwm_ChannelType) 2)

/* timer 2 channel 4 */
#define Pwm_Channel_4		( (Pwm_ChannelType) 3)

/* timer 3 channel 1 */
#define Pwm_Channel_5		( (Pwm_ChannelType) 4)

/* timer 3 channel 2 */
#define Pwm_Channel_6		( (Pwm_ChannelType) 5)

/* timer 3 channel 3 */
#define Pwm_Channel_7		( (Pwm_ChannelType) 6)

/* timer 3 channel 4 */
#define Pwm_Channel_8		( (Pwm_ChannelType) 7)

/* timer 4 channel 1 */
#define Pwm_Channel_9		( (Pwm_ChannelType) 8)

/* timer 4 channel 2 */
#define Pwm_Channel_10		( (Pwm_ChannelType) 9)

/* timer 4 channel 3 */
#define Pwm_Channel_11		( (Pwm_ChannelType) 10)

/* timer 4 channel 4 */
#define Pwm_Channel_12		( (Pwm_ChannelType) 11)

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/

typedef  uint8  Pwm_ServiceId;


#define  PWM_INIT_SID                             ( (Pwm_ServiceId)0x00 )
#define  PWM_DEINIT_SID                           ( (Pwm_ServiceId)0x01 )
#define  PWM_SET_DUTY_CYCLE_SID                   ( (Pwm_ServiceId)0x02 )
#define  PWM_SET_PERIOD_AND_DUTY_SID              ( (Pwm_ServiceId)0x03 )
#define  PWM_SET_OUTPUT_TO_IDLE_SID               ( (Pwm_ServiceId)0x04 )
#define  PWM_GET_OUTPUT_STATE_SID   			  ( (Pwm_ServiceId)0x05 )
#define  PWM_DISABLE_NOTIFICATION_SID     		  ( (Pwm_ServiceId)0x06 )
#define  PWM_ENABLE_NOTIFICATION_SID              ( (Pwm_ServiceId)0x07 )
#define  PWM_GET_VERSION_INFO_SID                 ( (Pwm_ServiceId)0x08 )



/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/

typedef  uint8  Pwm_DetErrorType;


#define PWM_E_PARAM_CONFIG              	 ( (Pwm_DetErrorType)0x10 )
#define PWM_E_UNINIT              			 ( (Pwm_DetErrorType)0x11 )
#define PWM_E_PARAM_CHANNEL                	 ( (Pwm_DetErrorType)0x12 )
#define PWM_E_PERIOD_UNCHANGEABLE          	 ( (Pwm_DetErrorType)0x13 )
#define PWM_E_ALREADY_INITIALIZED          	 ( (Pwm_DetErrorType)0x14 )
#define PWM_E_PARAM_POINTER                	 ( (Pwm_DetErrorType)0x15 )




/*******************************************************************************
 *                      Module Data Types                                      *
 *******************************************************************************/


typedef uint32*  Ptr2Reg;


/* Numeric identifier of a PWM channel. range (8 : 32) */
typedef uint8	 Pwm_ChannelType;


/* Definition of the period of a PWM channel. range (8 : 32) */
typedef float32	 Pwm_PeriodType;


/* Definition of the Duty Cycle of a PWM channel. range (8 : 32) */
typedef float32	 Pwm_DutyCycleType;


/* Output state of a PWM channel. */
typedef enum
{
	PWM_LOW, PWM_HIGH
	
}Pwm_OutputStateType, Pwm_IdleStateType, Pwm_PolarityType;





/* Definition of the type of edge notification of a PWM channel. */
typedef enum
{
	PWM_RISING_EDGE, PWM_FALLING_EDGE, PWM_BOTH_EDGES
	
}Pwm_EdgeNotificationType;





/* Defines the class of a PWM channel. */
typedef enum
{
	PWM_VARIABLE_PERIOD, PWM_FIXED_PERIOD, PWM_FIXED_PERIOD_SHIFTED
	
}Pwm_ChannelClassType;


/* Defines Aligned modes of a PWM channel. */
typedef enum
{
	 PWM_Edge_aligned_mode, PWM_Center_aligned_mode
	
}Pwm_AlignedModeType;



/* Defines Activation of a PWM channel. */
typedef enum
{
	 PWM_ChannelActive, PWM_ChannelNotActive
	
}Pwm_ChannelActivationType;



typedef struct
{
	
	/* Assigned Pwm channel */
	Pwm_ChannelType 	ChannelId;
	
	
	/* Center aligned mode selection */
	Pwm_AlignedModeType 	CenterAlignedModeSelection;
	
	
	/* Polarity ( high or low ) */
	Pwm_PolarityType 	Polarity;
	
	
	/* Channel class */
	Pwm_ChannelClassType 	ChannelClass;
	
	
	/* Default value for period */
	Pwm_PeriodType		PeriodDefault;
	
	
	/* Default value for duty cycle */
	Pwm_DutyCycleType 	DutyCycleDefault;
	
	
	/* Idle state high or low */
	Pwm_IdleStateType 	IdleState;
	
	/* channel activation */
	Pwm_ChannelActivationType		ChannelActivation;
	
	
}Pwm_ChannelConfigurationType;







typedef struct
{
	Pwm_ChannelConfigurationType    Pwm_Channel_Configuration[MAX_NUMBER_OF_SUPORTED_CHANNELS];   /*array of the configured BRS */
	
}Pwm_ConfigType;



/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

extern const Pwm_ConfigType Pwm_Configrations;


void Pwm_Init(const Pwm_ConfigType* ConfigPtr);


void Pwm_DeInit(void);

/**@ATTENTION
 * I CHANGED (UINT16 DUTYCYCLE) TO (FLOAT32 DUTYCYCLE) TO MAKE IT SIMPLE FOR THE USER.
 * INSTEED OF USING DUTY CYCLE AS REGISTER NUMBER AND RATIO OF ARR REGISTER IT WILL BE PERCENTAGE NUMBER ONLY. 
 */
void Pwm_SetDutyCycle(Pwm_ChannelType ChannelNumber, float32 DutyCycle );


void Pwm_SetPeriodAndDuty(Pwm_ChannelType ChannelNumber, Pwm_PeriodType Period, uint16 DutyCycle );


void Pwm_SetOutputToIdle(Pwm_ChannelType ChannelNumber );


Pwm_OutputStateType Pwm_GetOutputState(Pwm_ChannelType ChannelNumber);


void Pwm_DisableNotification(Pwm_ChannelType ChannelNumber );


void Pwm_EnableNotification(Pwm_ChannelType ChannelNumber, Pwm_EdgeNotificationType Notification );


void Pwm_GetVersionInfo(Std_VersionInfoType* versioninfo);



#endif /* PWM_H_ */



