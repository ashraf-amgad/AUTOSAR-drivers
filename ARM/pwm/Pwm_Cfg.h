#ifndef __PWM_CFG_H__
#define __PWM_CFG_H__


#define PWM_CFG_SW_MAJOR_VERSION 		(1U)
#define PWM_CFG_SW_MINOR_VERSION 		(0U)
#define PWM_CFG_SW_PATCH_VERSION 		(0U)

/* AUTOSAR Version 4.0.3 */
#define PWM_CFG_AR_RELEASE_MAJOR_VERSION   (4U)
#define PWM_CFG_AR_RELEASE_MINOR_VERSION   (0U)
#define PWM_CFG_AR_RELEASE_PATCH_VERSION   (3U)



#include "Std_Types.h"
/*---------------------------------------*/
/* AUTOSAR checking between Pwm_cfg.h and Std_Types.h files */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PWM_CFG_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PWM_CFG_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PWM_CFG_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Pwm_cfg.h does not match the expected version"
#endif


/* Software Version checking between Pwm_cfg.h and Pwm.h files */
#if  ( (STD_TYPES_SW_MAJOR_VERSION != PWM_CFG_SW_MAJOR_VERSION)\
    || (STD_TYPES_SW_MINOR_VERSION != PWM_CFG_SW_MINOR_VERSION)\
    || (STD_TYPES_SW_PATCH_VERSION != PWM_CFG_SW_PATCH_VERSION) )
#error "The SW version of Pwm_cfg.h does not match the expected version"
#endif




/**************************/


/* Pre-compile option for Development Error Detect */
#define PWM_DEV_ERROR_DETECT                (STD_ON)

/* Pre-compile option for Version Info API */
#define PWM_VERSION_INFO_API                (STD_ON)



#define PWM_CPU_CLOCK_REF						(0U)


/** @ATTENTION 
  * ALL OF THE CHANNELS OF THE SAME TIMERS HAVE THE SAME PERIOD, 
  * Timer 2 ---> ch_1, ch_2, ch_3, ch_4
  * Timer 3 ---> ch_5, ch_6, ch_7, ch_8
  * Timer 3 ---> ch_9, ch_10, ch_11, ch_12 
  * IF YOU CHANGED A PERIOD OF ONE, IT WILL CHANGE THE PERIOD OF OTHER THREE.
  */
  
#define PWM_Channel_1_AlignedMode			(PWM_Center_aligned_mode)
#define PWM_Channel_1_Polarity				(PWM_LOW)
#define PWM_Channel_1_ChannelClass			(PWM_VARIABLE_PERIOD)
#define PWM_Channel_1_Period_Default		(0)
#define PWM_Channel_1_DutyCycle_Default		(0)
#define PWM_Channel_1_IdleState				(PWM_LOW)
#define PWM_Channel_1_ChannelActivation		(PWM_ChannelActive)




#define PWM_Channel_2_AlignedMode			(PWM_Center_aligned_mode)
#define PWM_Channel_2_Polarity				(PWM_LOW)
#define PWM_Channel_2_ChannelClass			(PWM_VARIABLE_PERIOD)
#define PWM_Channel_2_Period_Default		(0)
#define PWM_Channel_2_DutyCycle_Default		(0)
#define PWM_Channel_2_IdleState				(PWM_LOW)
#define PWM_Channel_2_ChannelActivation		(PWM_ChannelActive)



#define PWM_Channel_3_AlignedMode			(PWM_Center_aligned_mode)
#define PWM_Channel_3_Polarity				(PWM_LOW)
#define PWM_Channel_3_ChannelClass			(PWM_VARIABLE_PERIOD)
#define PWM_Channel_3_Period_Default		(0)
#define PWM_Channel_3_DutyCycle_Default		(0)
#define PWM_Channel_3_IdleState				(PWM_LOW)
#define PWM_Channel_3_ChannelActivation		(PWM_ChannelActive)



#define PWM_Channel_4_AlignedMode			(PWM_Center_aligned_mode)
#define PWM_Channel_4_Polarity				(PWM_LOW)
#define PWM_Channel_4_ChannelClass			(PWM_VARIABLE_PERIOD)
#define PWM_Channel_4_Period_Default		(0)
#define PWM_Channel_4_DutyCycle_Default		(0)
#define PWM_Channel_4_IdleState				(PWM_LOW)
#define PWM_Channel_4_ChannelActivation		(PWM_ChannelActive)



#define PWM_Channel_5_AlignedMode			(PWM_Center_aligned_mode)
#define PWM_Channel_5_Polarity				(PWM_LOW)
#define PWM_Channel_5_ChannelClass			(PWM_VARIABLE_PERIOD)
#define PWM_Channel_5_Period_Default		(0)
#define PWM_Channel_5_DutyCycle_Default		(0)
#define PWM_Channel_5_IdleState				(PWM_LOW)
#define PWM_Channel_5_ChannelActivation		(PWM_ChannelActive)



#define PWM_Channel_6_AlignedMode			(PWM_Center_aligned_mode)
#define PWM_Channel_6_Polarity				(PWM_LOW)
#define PWM_Channel_6_ChannelClass			(PWM_VARIABLE_PERIOD)
#define PWM_Channel_6_Period_Default		(0)
#define PWM_Channel_6_DutyCycle_Default		(0)
#define PWM_Channel_6_IdleState				(PWM_LOW)
#define PWM_Channel_6_ChannelActivation		(PWM_ChannelActive)




#define PWM_Channel_7_AlignedMode			(PWM_Center_aligned_mode)
#define PWM_Channel_7_Polarity				(PWM_LOW)
#define PWM_Channel_7_ChannelClass			(PWM_VARIABLE_PERIOD)
#define PWM_Channel_7_Period_Default		(0)
#define PWM_Channel_7_DutyCycle_Default		(0)
#define PWM_Channel_7_IdleState				(PWM_LOW)
#define PWM_Channel_7_ChannelActivation		(PWM_ChannelActive)




#define PWM_Channel_8_AlignedMode			(PWM_Center_aligned_mode)
#define PWM_Channel_8_Polarity				(PWM_LOW)
#define PWM_Channel_8_ChannelClass			(PWM_VARIABLE_PERIOD)
#define PWM_Channel_8_Period_Default		(0)
#define PWM_Channel_8_DutyCycle_Default		(0)
#define PWM_Channel_8_IdleState				(PWM_LOW)
#define PWM_Channel_8_ChannelActivation		(PWM_ChannelActive)




#define PWM_Channel_9_AlignedMode			(PWM_Center_aligned_mode)
#define PWM_Channel_9_Polarity				(PWM_LOW)
#define PWM_Channel_9_ChannelClass			(PWM_VARIABLE_PERIOD)
#define PWM_Channel_9_Period_Default		(0)
#define PWM_Channel_9_DutyCycle_Default		(0)
#define PWM_Channel_9_IdleState				(PWM_LOW)
#define PWM_Channel_9_ChannelActivation		(PWM_ChannelActive)



#define PWM_Channel_10_AlignedMode			(PWM_Center_aligned_mode)
#define PWM_Channel_10_Polarity				(PWM_LOW)
#define PWM_Channel_10_ChannelClass			(PWM_VARIABLE_PERIOD)
#define PWM_Channel_10_Period_Default		(0)
#define PWM_Channel_10_DutyCycle_Default	(0)
#define PWM_Channel_10_IdleState			(PWM_LOW)
#define PWM_Channel_10_ChannelActivation	(PWM_ChannelActive)



#define PWM_Channel_11_AlignedMode			(PWM_Center_aligned_mode)
#define PWM_Channel_11_Polarity				(PWM_LOW)
#define PWM_Channel_11_ChannelClass			(PWM_VARIABLE_PERIOD)
#define PWM_Channel_11_Period_Default		(0)
#define PWM_Channel_11_DutyCycle_Default	(0)
#define PWM_Channel_11_IdleState			(PWM_LOW)
#define PWM_Channel_11_ChannelActivation	(PWM_ChannelActive)




#define PWM_Channel_12_AlignedMode			(PWM_Center_aligned_mode)
#define PWM_Channel_12_Polarity				(PWM_LOW)
#define PWM_Channel_12_ChannelClass			(PWM_VARIABLE_PERIOD)
#define PWM_Channel_12_Period_Default		(0)
#define PWM_Channel_12_DutyCycle_Default	(0)
#define PWM_Channel_12_IdleState			(PWM_LOW)
#define PWM_Channel_12_ChannelActivation	(PWM_ChannelActive)



#define PWM_Channel_1_AlignedMode			(PWM_Center_aligned_mode)
#define PWM_Channel_1_Polarity				(PWM_LOW)
#define PWM_Channel_1_ChannelClass			(PWM_VARIABLE_PERIOD)
#define PWM_Channel_1_Period_Default		(0)
#define PWM_Channel_1_DutyCycle_Default		(0)
#define PWM_Channel_1_IdleState				(PWM_LOW)
#define PWM_Channel_1_ChannelActivation		(PWM_ChannelActive)
/***********************************************/

#endif

