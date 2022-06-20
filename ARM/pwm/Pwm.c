#include "Pwm.h"
#include "Pwm_reg.h"
#include "Det.h"


static uint8 PWM_Status = PWM_UNINIT;


/**@ATTENTION
 * I CHANGED (UINT16 DUTYCYCLE) TO (FLOAT32 DUTYCYCLE) TO MAKE IT SIMPLE FOR THE USER.
 * INSTEED OF USING DUTY CYCLE AS REGISTER NUMBER AND RATIO OF ARR REGISTER IT WILL BE PERCENTAGE NUMBER ONLY. 
 */



#if (PWM_DEV_ERROR_DETECT == STD_ON)
/* AUTOSAR Version checking between Det and PWM Modules */
#if ((DET_AR_MAJOR_VERSION != PWM_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != PWM_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != PWM_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif
#endif


/************************************************************************************
* Service Name: PWM_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): Config: Pointer to driver configuration.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the module.
************************************************************************************/
void Pwm_Init( const Pwm_ConfigType* Config )
{
	boolean error = FALSE;
	uint8 Channel_Counter = 0;
	float32 Temp_Period = 0;
	float32  Temp_DutyCycle = 0;
	
	#if (PWM_DEV_ERROR_DETECT == STD_ON)
	
		if (PWM_Status != PWM_UNINIT)
		{
			Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_INIT_SID, PWM_E_UNINIT);
			error = TRUE;
		}
		
		if (Config == NULL_PTR)
		{
			Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_INIT_SID, PWM_E_PARAM_CONFIG);
			error = TRUE;
		}
		
		else 
		{
			/* No action needed */
		}
		
	#endif
		if(error == FALSE)
		{
			
			for (Channel_Counter = 0 ; Channel_Counter < MAX_NUMBER_OF_SUPORTED_CHANNELS ;Channel_Counter++)
			{
				Temp_Period = Pwm_Configrations.Pwm_Channel_Configuration[Channel_Counter].PeriodDefault;
				Temp_DutyCycle = Pwm_Configrations.Pwm_Channel_Configuration[Channel_Counter].DutyCycleDefault;	
				
				switch (Pwm_Configrations.Pwm_Channel_Configuration[Channel_Counter].ChannelId)
				{
					
					/*******************  Pwm_Channel_1  *******************/
					
					case Pwm_Channel_1:
						if(Pwm_Configrations.Pwm_Channel_Configuration[Channel_Counter].Polarity == PWM_LOW)
						{	
							/* configure timer_2 channel_1 in pwm mode_2 (HIGH - FALSE) ,set preload_enable and fast_enable*/
							TIM2->CCMR1 |=  (TIM_CCMR1_OC1M | TIM_CCMR1_OC1PE | TIM_CCMR1_OC1FE);
						}
						
						else
						{	
							/* configure timer_2 channel_1 in pwm mode_2 (HIGH - FALSE) ,set preload_enable and fast_enable*/
							TIM2->CCMR1 |=  (TIM_CCMR1_OC1M_0 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1PE | TIM_CCMR1_OC1FE);
						}
						
		
						if(Pwm_Configrations.Pwm_Channel_Configuration[Channel_Counter].CenterAlignedModeSelection == PWM_Center_aligned_mode)
						{	
							/* set auto reload prelaod and choose center alignment mode 1 */
							TIM2->CR1 |= ( TIM_CR1_ARPE | TIM_CR1_CMS_0);
						}
							
						else
						{	
							/* set auto reload prelaod and choose edge alignment */
							TIM2->CR1 |= TIM_CR1_ARPE;
						}
								
							
						/* set PRESCALLER to 1 */
						TIM2->PSC  = 0;

						
						/* set ARR */
						TIM2->ARR = ( Temp_Period * PWM_CPU_CLOCK_REF ) / 2 ; 
						
						
						/* CCR1 determine duty cycle of channel_1 */
						TIM2->CCR1 = (Temp_DutyCycle * TIM2->ARR);
						
						if(Pwm_Configrations.Pwm_Channel_Configuration[Channel_Counter].ChannelActivation == PWM_HIGH)	
						{
							/* enable channel_1*/
							TIM2->CCER  |=   TIM_CCER_CC1E;
						}
						
						else
						{
							/* enable channel_1*/
							TIM2->CCER  &=   ~TIM_CCER_CC1E;
						}
						
						/* enable the counter of timer 2*/
						TIM2->CR1 |= TIM_CR1_CEN;	
					break;					
						
						
					/*******************  Pwm_Channel_2  *******************/
					
					case Pwm_Channel_2:
						if(Pwm_Configrations.Pwm_Channel_Configuration[Channel_Counter].Polarity == PWM_LOW)
						{	
							/* configure timer_2 channel_1 in pwm mode_2 (HIGH - FALSE) ,set preload_enable and fast_enable*/
							TIM2->CCMR1 |=  (TIM_CCMR1_OC2M | TIM_CCMR1_OC2PE | TIM_CCMR1_OC2FE);
						}
						
						else
						{	
							/* configure timer_2 channel_1 in pwm mode_2 (HIGH - FALSE) ,set preload_enable and fast_enable*/
							TIM2->CCMR1 |=  (TIM_CCMR1_OC2M_0 | TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2PE | TIM_CCMR1_OC2FE);
						}
						
		
						if(Pwm_Configrations.Pwm_Channel_Configuration[Channel_Counter].CenterAlignedModeSelection == PWM_Center_aligned_mode)
						{	
							/* set auto reload prelaod and choose center alignment mode 1 */
							TIM2->CR1 |= ( TIM_CR1_ARPE | TIM_CR1_CMS_0);
						}
							
						else
						{	
							/* set auto reload prelaod and choose edge alignment */
							TIM2->CR1 |= TIM_CR1_ARPE;
						}
								
							
						/* set PRESCALLER to 1 */
						TIM2->PSC  = 0;
						
						
						/* set ARR */
						TIM2->ARR = ( Temp_Period * PWM_CPU_CLOCK_REF ) / 2 ; 
						
						
						/* CCR1 determine duty cycle of channel_1 */
						TIM2->CCR2 = ( Temp_DutyCycle * (TIM2->ARR) );
						
							
						if(Pwm_Configrations.Pwm_Channel_Configuration[Channel_Counter].ChannelActivation == PWM_HIGH)	
						{
							/* enable channel_2*/
							TIM2->CCER  |=   TIM_CCER_CC2E;
						}
						
						else
						{
							/* enable channel_2*/
							TIM2->CCER  &=   ~TIM_CCER_CC2E;
						}
						
						/* enable the counter of timer 2*/
						TIM2->CR1 |= TIM_CR1_CEN;	
					break;	
					
					
					
					/*******************  Pwm_Channel_3  *******************/
					
					case Pwm_Channel_3:
						if(Pwm_Configrations.Pwm_Channel_Configuration[Channel_Counter].Polarity == PWM_LOW)
						{	
							/* configure timer_2 channel_1 in pwm mode_2 (HIGH - FALSE) ,set preload_enable and fast_enable*/
							TIM2->CCMR2 |=  (TIM_CCMR2_OC3M | TIM_CCMR2_OC3PE | TIM_CCMR2_OC3FE);
						}
						
						else
						{	
							/* configure timer_2 channel_1 in pwm mode_2 (HIGH - FALSE) ,set preload_enable and fast_enable*/
							TIM2->CCMR2 |=  (TIM_CCMR2_OC3M_0 | TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3PE | TIM_CCMR2_OC3FE);
						}
						
		
						if(Pwm_Configrations.Pwm_Channel_Configuration[Channel_Counter].CenterAlignedModeSelection == PWM_Center_aligned_mode)
						{	
							/* set auto reload prelaod and choose center alignment mode 1 */
							TIM2->CR1 |= ( TIM_CR1_ARPE | TIM_CR1_CMS_0);
						}
							
						else
						{	
							/* set auto reload prelaod and choose edge alignment */
							TIM2->CR1 |= TIM_CR1_ARPE;
						}
								
							
						/* set PRESCALLER to 1 */
						TIM2->PSC  = 0;
						
						
						/* set ARR */
						TIM2->ARR = ( Temp_Period * PWM_CPU_CLOCK_REF ) / 2 ; 
						
						
						/* CCR1 determine duty cycle of channel_1 */
						TIM2->CCR3 = ( Temp_DutyCycle * (TIM2->ARR) );
						
							
						if(Pwm_Configrations.Pwm_Channel_Configuration[Channel_Counter].ChannelActivation == PWM_HIGH)	
						{
							/* enable channel_3*/
							TIM2->CCER  |=   TIM_CCER_CC3E;
						}
						
						else
						{
							/* enable channel_3*/
							TIM2->CCER  &=   ~TIM_CCER_CC3E;
						}
						
						/* enable the counter of timer 2*/
						TIM2->CR1 |= TIM_CR1_CEN;	
					break;
						
						
						
						/*******************  Pwm_Channel_4  *******************/
					
					case Pwm_Channel_4:
						if(Pwm_Configrations.Pwm_Channel_Configuration[Channel_Counter].Polarity == PWM_LOW)
						{	
							/* configure timer_2 channel_1 in pwm mode_2 (HIGH - FALSE) ,set preload_enable and fast_enable*/
							TIM2->CCMR2 |=  (TIM_CCMR2_OC4M | TIM_CCMR2_OC4PE | TIM_CCMR2_OC4FE);
						}
						
						else
						{	
							/* configure timer_2 channel_1 in pwm mode_2 (HIGH - FALSE) ,set preload_enable and fast_enable*/
							TIM2->CCMR2 |=  (TIM_CCMR2_OC4M_0 | TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4PE | TIM_CCMR2_OC4FE);
						}
						
		
						if(Pwm_Configrations.Pwm_Channel_Configuration[Channel_Counter].CenterAlignedModeSelection == PWM_Center_aligned_mode)
						{	
							/* set auto reload prelaod and choose center alignment mode 1 */
							TIM2->CR1 |= ( TIM_CR1_ARPE | TIM_CR1_CMS_0);
						}
							
						else
						{	
							/* set auto reload prelaod and choose edge alignment */
							TIM2->CR1 |= TIM_CR1_ARPE;
						}
								
							
						/* set PRESCALLER to 1 */
						TIM2->PSC  = 0;
						
						
						/* set ARR */
						TIM2->ARR = ( Temp_Period * PWM_CPU_CLOCK_REF ) / 2 ; 
						
						
						/* CCR1 determine duty cycle of channel_1 */
						TIM2->CCR4 = ( Temp_DutyCycle * (TIM2->ARR) );
						
							
						if(Pwm_Configrations.Pwm_Channel_Configuration[Channel_Counter].ChannelActivation == PWM_HIGH)	
						{
							/* enable channel_4*/
							TIM2->CCER  |=   TIM_CCER_CC4E;
						}
						
						else
						{
							/* enable channel_4*/
							TIM2->CCER  &=   ~TIM_CCER_CC4E;
						}
						
						/* enable the counter of timer 2*/
						TIM2->CR1 |= TIM_CR1_CEN;	
					break;
						
						
						
						/*******************  Pwm_Channel_5  *******************/
					
					case Pwm_Channel_5:
						if(Pwm_Configrations.Pwm_Channel_Configuration[Channel_Counter].Polarity == PWM_LOW)
						{	
							/* configure timer_2 channel_1 in pwm mode_2 (HIGH - FALSE) ,set preload_enable and fast_enable*/
							TIM3->CCMR1 |=  (TIM_CCMR1_OC1M | TIM_CCMR1_OC1PE | TIM_CCMR1_OC1FE);
						}
						
						else
						{	
							/* configure timer_2 channel_1 in pwm mode_2 (HIGH - FALSE) ,set preload_enable and fast_enable*/
							TIM3->CCMR1 |=  (TIM_CCMR1_OC1M_0 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1PE | TIM_CCMR1_OC1FE);
						}
						
		
						if(Pwm_Configrations.Pwm_Channel_Configuration[Channel_Counter].CenterAlignedModeSelection == PWM_Center_aligned_mode)
						{	
							/* set auto reload prelaod and choose center alignment mode 1 */
							TIM3->CR1 |= ( TIM_CR1_ARPE | TIM_CR1_CMS_0);
						}
							
						else
						{	
							/* set auto reload prelaod and choose edge alignment */
							TIM2->CR1 |= TIM_CR1_ARPE;
						}
								
							
						/* set PRESCALLER to 1 */
						TIM2->PSC  = 0;
						
						
						/* set ARR */
						TIM3->ARR = ( Temp_Period * PWM_CPU_CLOCK_REF ) / 2 ; 
						
						
						/* CCR1 determine duty cycle of channel_1 */
						TIM3->CCR1 = ( Temp_DutyCycle * (TIM3->ARR) );
						
							
						if(Pwm_Configrations.Pwm_Channel_Configuration[Channel_Counter].ChannelActivation == PWM_HIGH)	
						{
							/* enable channel_5*/
							TIM3->CCER  |=   TIM_CCER_CC1E;
						}
						
						else
						{
							/* enable channel_5*/
							TIM3->CCER  &=   ~TIM_CCER_CC1E;
						}
						
						/* enable the counter of timer 2*/
						TIM3->CR1 |= TIM_CR1_CEN;	
					break;
						
						
						
						/*******************  Pwm_Channel_6  *******************/
					
					case Pwm_Channel_6:
						if(Pwm_Configrations.Pwm_Channel_Configuration[Channel_Counter].Polarity == PWM_LOW)
						{	
							/* configure timer_2 channel_1 in pwm mode_2 (HIGH - FALSE) ,set preload_enable and fast_enable*/
							TIM3->CCMR2 |=  (TIM_CCMR1_OC2M | TIM_CCMR1_OC2PE | TIM_CCMR1_OC2FE);
						}
						
						else
						{	
							/* configure timer_2 channel_1 in pwm mode_2 (HIGH - FALSE) ,set preload_enable and fast_enable*/
							TIM3->CCMR1 |=  (TIM_CCMR1_OC2M_0 | TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2PE | TIM_CCMR1_OC2FE);
						}
						
		
						if(Pwm_Configrations.Pwm_Channel_Configuration[Channel_Counter].CenterAlignedModeSelection == PWM_Center_aligned_mode)
						{	
							/* set auto reload prelaod and choose center alignment mode 1 */
							TIM3->CR1 |= ( TIM_CR1_ARPE | TIM_CR1_CMS_0);
						}
							
						else
						{	
							/* set auto reload prelaod and choose edge alignment */
							TIM3->CR1 |= TIM_CR1_ARPE;
						}
								
							
						/* set PRESCALLER to 1 */
						TIM2->PSC  = 0;
						
						
						/* set ARR */
						TIM3->ARR = ( Temp_Period * PWM_CPU_CLOCK_REF ) / 2 ; 
						
						
						/* CCR1 determine duty cycle of channel_1 */
						TIM3->CCR1 = ( Temp_DutyCycle * (TIM3->ARR) );
						
							
						if(Pwm_Configrations.Pwm_Channel_Configuration[Channel_Counter].ChannelActivation == PWM_HIGH)	
						{
							/* enable channel_6*/
							TIM3->CCER  |=   TIM_CCER_CC2E;
						}
						
						else
						{
							/* enable channel_6*/
							TIM3->CCER  &=   ~TIM_CCER_CC2E;
						}
						
						/* enable the counter of timer 2*/
						TIM3->CR1 |= TIM_CR1_CEN;	
					break;
						
						
						
						/*******************  Pwm_Channel_7  *******************/
					
					case Pwm_Channel_7:
						if(Pwm_Configrations.Pwm_Channel_Configuration[Channel_Counter].Polarity == PWM_LOW)
						{	
							/* configure timer_2 channel_1 in pwm mode_2 (HIGH - FALSE) ,set preload_enable and fast_enable*/
							TIM3->CCMR2 |=  (TIM_CCMR2_OC3M | TIM_CCMR2_OC3PE | TIM_CCMR2_OC3FE);
						}
						
						else
						{	
							/* configure timer_2 channel_1 in pwm mode_2 (HIGH - FALSE) ,set preload_enable and fast_enable*/
							TIM3->CCMR2 |=  (TIM_CCMR2_OC3M_0 | TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3PE | TIM_CCMR2_OC3FE);
						}
						
		
						if(Pwm_Configrations.Pwm_Channel_Configuration[Channel_Counter].CenterAlignedModeSelection == PWM_Center_aligned_mode)
						{	
							/* set auto reload prelaod and choose center alignment mode 1 */
							TIM3->CR1 |= ( TIM_CR1_ARPE | TIM_CR1_CMS_0);
						}
							
						else
						{	
							/* set auto reload prelaod and choose edge alignment */
							TIM3->CR1 |= TIM_CR1_ARPE;
						}
								
							
						/* set PRESCALLER to 1 */
						TIM3->PSC  = 0;
						
						
						/* set ARR */
						TIM3->ARR = ( Temp_Period * PWM_CPU_CLOCK_REF ) / 2 ; 
						
						
						/* CCR1 determine duty cycle of channel_1 */
						TIM3->CCR1 = ( Temp_DutyCycle * (TIM3->ARR) );
						
							
						if(Pwm_Configrations.Pwm_Channel_Configuration[Channel_Counter].ChannelActivation == PWM_HIGH)	
						{
							/* enable channel_7*/
							TIM3->CCER  |=   TIM_CCER_CC3E;
						}
						
						else
						{
							/* enable channel_7*/
							TIM3->CCER  &=   ~TIM_CCER_CC3E;
						}
						
						/* enable the counter of timer 2*/
						TIM3->CR1 |= TIM_CR1_CEN;	
					break;
						
						
						
						/*******************  Pwm_Channel_8  *******************/
					
					case Pwm_Channel_8:
						if(Pwm_Configrations.Pwm_Channel_Configuration[Channel_Counter].Polarity == PWM_LOW)
						{	
							/* configure timer_2 channel_1 in pwm mode_2 (HIGH - FALSE) ,set preload_enable and fast_enable*/
							TIM3->CCMR2 |=  (TIM_CCMR2_OC4M | TIM_CCMR2_OC4PE | TIM_CCMR2_OC4FE);
						}
						
						else
						{	
							/* configure timer_2 channel_1 in pwm mode_2 (HIGH - FALSE) ,set preload_enable and fast_enable*/
							TIM3->CCMR2 |=  (TIM_CCMR2_OC4M_0 | TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4PE | TIM_CCMR2_OC4FE);
						}
						
		
						if(Pwm_Configrations.Pwm_Channel_Configuration[Channel_Counter].CenterAlignedModeSelection == PWM_Center_aligned_mode)
						{	
							/* set auto reload prelaod and choose center alignment mode 1 */
							TIM3->CR1 |= ( TIM_CR1_ARPE | TIM_CR1_CMS_0);
						}
							
						else
						{	
							/* set auto reload prelaod and choose edge alignment */
							TIM3->CR1 |= TIM_CR1_ARPE;
						}
								
							
						/* set PRESCALLER to 1 */
						TIM3->PSC  = 0;
						
						
						/* set ARR */
						TIM3->ARR = ( Temp_Period * PWM_CPU_CLOCK_REF ) / 2 ; 
						
						
						/* CCR1 determine duty cycle of channel_1 */
						TIM3->CCR1 = ( Temp_DutyCycle * (TIM3->ARR) );
						
							
						if(Pwm_Configrations.Pwm_Channel_Configuration[Channel_Counter].ChannelActivation == PWM_HIGH)	
						{
							/* enable channel_8*/
							TIM3->CCER  |=   TIM_CCER_CC4E;
						}
						
						else
						{
							/* enable channel_8*/
							TIM3->CCER  &=   ~TIM_CCER_CC4E;
						}
						
						/* enable the counter of timer 2*/
						TIM3->CR1 |= TIM_CR1_CEN;	
					break;
						
						
						
						/*******************  Pwm_Channel_9  *******************/
					
					case Pwm_Channel_9:
						if(Pwm_Configrations.Pwm_Channel_Configuration[Channel_Counter].Polarity == PWM_LOW)
						{	
							/* configure timer_2 channel_1 in pwm mode_2 (HIGH - FALSE) ,set preload_enable and fast_enable*/
							TIM4->CCMR1 |=  (TIM_CCMR1_OC1M | TIM_CCMR1_OC1PE | TIM_CCMR1_OC1FE);
						}
						
						else
						{	
							/* configure timer_2 channel_1 in pwm mode_2 (HIGH - FALSE) ,set preload_enable and fast_enable*/
							TIM4->CCMR1 |=  (TIM_CCMR1_OC1M_0 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1PE | TIM_CCMR1_OC1FE);
						}
						
		
						if(Pwm_Configrations.Pwm_Channel_Configuration[Channel_Counter].CenterAlignedModeSelection == PWM_Center_aligned_mode)
						{	
							/* set auto reload prelaod and choose center alignment mode 1 */
							TIM4->CR1 |= ( TIM_CR1_ARPE | TIM_CR1_CMS_0);
						}
							
						else
						{	
							/* set auto reload prelaod and choose edge alignment */
							TIM4->CR1 |= TIM_CR1_ARPE;
						}
								
							
						/* set PRESCALLER to 1 */
						TIM4->PSC  = 0;
						
						
						/* set ARR */
						TIM4->ARR = ( Temp_Period * PWM_CPU_CLOCK_REF ) / 2 ; 
						
						
						/* CCR1 determine duty cycle of channel_1 */
						TIM4->CCR1 = ( Temp_DutyCycle * (TIM4->ARR) );
						
							
						if(Pwm_Configrations.Pwm_Channel_Configuration[Channel_Counter].ChannelActivation == PWM_HIGH)	
						{
							/* enable channel_9*/
							TIM4->CCER  |=   TIM_CCER_CC1E;
						}
						
						else
						{
							/* enable channel_9*/
							TIM4->CCER  &=   ~TIM_CCER_CC1E;
						}
						
						/* enable the counter of timer 2*/
						TIM4->CR1 |= TIM_CR1_CEN;	
					break;
						
						
						
						/*******************  Pwm_Channel_10  *******************/
					
					case Pwm_Channel_10:
						if(Pwm_Configrations.Pwm_Channel_Configuration[Channel_Counter].Polarity == PWM_LOW)
						{	
							/* configure timer_2 channel_1 in pwm mode_2 (HIGH - FALSE) ,set preload_enable and fast_enable*/
							TIM4->CCMR1 |=  (TIM_CCMR1_OC2M | TIM_CCMR1_OC2PE | TIM_CCMR1_OC2FE);
						}
						
						else
						{	
							/* configure timer_2 channel_1 in pwm mode_2 (HIGH - FALSE) ,set preload_enable and fast_enable*/
							TIM4->CCMR1 |=  (TIM_CCMR1_OC2M_0 | TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2PE | TIM_CCMR1_OC2FE);
						}
						
		
						if(Pwm_Configrations.Pwm_Channel_Configuration[Channel_Counter].CenterAlignedModeSelection == PWM_Center_aligned_mode)
						{	
							/* set auto reload prelaod and choose center alignment mode 1 */
							TIM4->CR1 |= ( TIM_CR1_ARPE | TIM_CR1_CMS_0);
						}
							
						else
						{	
							/* set auto reload prelaod and choose edge alignment */
							TIM4->CR1 |= TIM_CR1_ARPE;
						}
								
							
						/* set PRESCALLER to 1 */
						TIM4->PSC  = 0;
						
						
						/* set ARR */
						TIM4->ARR = ( Temp_Period * PWM_CPU_CLOCK_REF ) / 2 ; 
						
						
						/* CCR1 determine duty cycle of channel_1 */
						TIM4->CCR1 = ( Temp_DutyCycle * (TIM4->ARR) );
						
							
						if(Pwm_Configrations.Pwm_Channel_Configuration[Channel_Counter].ChannelActivation == PWM_HIGH)	
						{
							/* enable channel_10*/
							TIM4->CCER  |=   TIM_CCER_CC2E;
						}
						
						else
						{
							/* enable channel_10*/
							TIM4->CCER  &=   ~TIM_CCER_CC2E;
						}
						
						/* enable the counter of timer 2*/
						TIM4->CR1 |= TIM_CR1_CEN;	
					break;
						
						
						/*******************  Pwm_Channel_11  *******************/
					
					case Pwm_Channel_11:
						if(Pwm_Configrations.Pwm_Channel_Configuration[Channel_Counter].Polarity == PWM_LOW)
						{	
							/* configure timer_2 channel_1 in pwm mode_2 (HIGH - FALSE) ,set preload_enable and fast_enable*/
							TIM4->CCMR2 |=  (TIM_CCMR2_OC3M | TIM_CCMR2_OC3PE | TIM_CCMR2_OC3FE);
						}
						
						else
						{	
							/* configure timer_2 channel_1 in pwm mode_2 (HIGH - FALSE) ,set preload_enable and fast_enable*/
							TIM4->CCMR2 |=  (TIM_CCMR2_OC3M_0 | TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3PE | TIM_CCMR2_OC3FE);
						}
						
		
						if(Pwm_Configrations.Pwm_Channel_Configuration[Channel_Counter].CenterAlignedModeSelection == PWM_Center_aligned_mode)
						{	
							/* set auto reload prelaod and choose center alignment mode 1 */
							TIM4->CR1 |= ( TIM_CR1_ARPE | TIM_CR1_CMS_0);
						}
							
						else
						{	
							/* set auto reload prelaod and choose edge alignment */
							TIM4->CR1 |= TIM_CR1_ARPE;
						}
								
							
						/* set PRESCALLER to 1 */
						TIM4->PSC  = 0;
						
						
						/* set ARR */
						TIM4->ARR = ( Temp_Period * PWM_CPU_CLOCK_REF ) / 2 ; 
						
						
						/* CCR1 determine duty cycle of channel_1 */
						TIM4->CCR1 = ( Temp_DutyCycle * (TIM4->ARR) );
						
							
						if(Pwm_Configrations.Pwm_Channel_Configuration[Channel_Counter].ChannelActivation == PWM_HIGH)	
						{
							/* enable channel_11*/
							TIM4->CCER  |=   TIM_CCER_CC3E;
						}
						
						else
						{
							/* enable channel_11*/
							TIM4->CCER  &=   ~TIM_CCER_CC3E;
						}
						
						/* enable the counter of timer 2*/
						TIM4->CR1 |= TIM_CR1_CEN;	
					break;
						
						
						/*******************  Pwm_Channel_12  *******************/
					
					case Pwm_Channel_12:
						if(Pwm_Configrations.Pwm_Channel_Configuration[Channel_Counter].Polarity == PWM_LOW)
						{	
							/* configure timer_2 channel_1 in pwm mode_2 (HIGH - FALSE) ,set preload_enable and fast_enable*/
							TIM4->CCMR2 |=  (TIM_CCMR2_OC4M | TIM_CCMR2_OC4PE | TIM_CCMR2_OC4FE);
						}
						
						else
						{	
							/* configure timer_2 channel_1 in pwm mode_2 (HIGH - FALSE) ,set preload_enable and fast_enable*/
							TIM4->CCMR2 |=  (TIM_CCMR2_OC4M_0 | TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4PE | TIM_CCMR2_OC4FE);
						}
						
		
						if(Pwm_Configrations.Pwm_Channel_Configuration[Channel_Counter].CenterAlignedModeSelection == PWM_Center_aligned_mode)
						{	
							/* set auto reload prelaod and choose center alignment mode 1 */
							TIM4->CR1 |= ( TIM_CR1_ARPE | TIM_CR1_CMS_0);
						}
							
						else
						{	
							/* set auto reload prelaod and choose edge alignment */
							TIM4->CR1 |= TIM_CR1_ARPE;
						}
								
							
						/* set PRESCALLER to 1 */
						TIM4->PSC  = 0;
						
						
						/* set ARR */
						TIM4->ARR = ( Temp_Period * PWM_CPU_CLOCK_REF ) / 2 ; 
						
						
						/* CCR1 determine duty cycle of channel_1 */
						TIM4->CCR1 = ( Temp_DutyCycle * (TIM4->ARR) );
						
							
						if(Pwm_Configrations.Pwm_Channel_Configuration[Channel_Counter].ChannelActivation == PWM_HIGH)	
						{
							/* enable channel_12*/
							TIM4->CCER  |=   TIM_CCER_CC4E;
						}
						
						else
						{
							/* enable channel_12*/
							TIM4->CCER  &=   ~TIM_CCER_CC4E;
						}
						
						/* enable the counter of timer 2*/
						TIM4->CR1 |= TIM_CR1_CEN;	
					break;
						
					}
					
				}
				
			PWM_Status = PWM_INIT;
		}
		
}



/************************************************************************************
* Service Name: PWM_GetVersionInfo
* Service ID[hex]: 0x08
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): versioninfo: Pointer to where to store the version information of this module.
* Return value: None
* Description: This function returns the version information of this module.
************************************************************************************/
void Pwm_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
	
}


/************************************************************************************
* Service Name: 		Pwm_SetDutyCycle
* Service ID[hex]: 		0x02
* Sync/Async:	 		Synchronous
* Reentrancy: 			Reentrant
* Parameters (in): 		ChannelNumber:  Numeric identifier of the PWM
						DutyCycle: 		Min=0x0000 Max=0x8000
* Parameters (inout): 	None
* Parameters (out): 	None
* Return value: 		None
* Description: Service sets the duty cycle of the PWM channel.
************************************************************************************/

void Pwm_SetDutyCycle(Pwm_ChannelType ChannelNumber, float32 DutyCycle )
{
	
	boolean error; 
	//Error check
	#if (PWM_DEV_ERROR_DETECT == STD_ON)
		if (PWM_Status == PWM_UNINIT)
		{
			Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_SET_DUTY_CYCLE_SID, PWM_E_UNINIT);
			error = TRUE;
		}
		
		if (ChannelNumber > MAX_NUMBER_OF_SUPORTED_CHANNELS)
		{
			Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_SET_DUTY_CYCLE_SID, PWM_E_PARAM_CHANNEL);
			error = TRUE;
		}
		
		if (Pwm_Configrations.Pwm_Channel_Configuration->ChannelClass == PWM_FIXED_PERIOD_SHIFTED)
		{
			Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_SET_DUTY_CYCLE_SID, PWM_E_PERIOD_UNCHANGEABLE);
			error = TRUE;		
		}
		
		else 
		{
			error = FALSE;
		}
	#endif
	
		
	if(error == FALSE)
	{
	
		switch (Pwm_Configrations.Pwm_Channel_Configuration[ChannelNumber].ChannelId)
		{
			case Pwm_Channel_1:
				
				/* CCR1 determine duty cycle of channel_1 */
				TIM2->CCR1 = ( DutyCycle * (TIM2->ARR) );
				
				/*PWM mode 1 */
				TIM2->CCER  &= ~(TIM_CCER_CC1E);
				TIM2->CCMR1 &= ~(TIM_CCMR1_OC1M);
				TIM2->CCMR1 |=  (TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1);
				TIM2->CCER  |=  TIM_CCER_CC1E;
				
			break;
			
			case Pwm_Channel_2:
				/* CCR1 determine duty cycle of channel_2 */
				TIM2->CCR2 = ( DutyCycle * (TIM2->ARR) );
			
				/*PWM mode 1 */
				TIM2->CCER  &= ~(TIM_CCER_CC2E);
				TIM2->CCMR1 &= ~(TIM_CCMR1_OC2M);
				TIM2->CCMR1 |=  (TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_1);
				TIM2->CCER  |=  TIM_CCER_CC2E;
			break;
			
			case Pwm_Channel_3:
				/* CCR1 determine duty cycle of channel_3 */
				TIM2->CCR3 = ( DutyCycle * (TIM2->ARR) );
			
				/*PWM mode 1 */
				TIM2->CCER  &= ~(TIM_CCER_CC3E);
				TIM2->CCMR2 &= ~(TIM_CCMR2_OC3M);
				TIM2->CCMR2 |=  (TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3M_1);
				TIM2->CCER  |=  TIM_CCER_CC3E;
			break;
			
			case Pwm_Channel_4:
				/* CCR1 determine duty cycle of channel_4 */
				TIM2->CCR4 = ( DutyCycle * (TIM2->ARR) );
			
				/*PWM mode 1 */
				TIM2->CCER  &= ~(TIM_CCER_CC4E);
				TIM2->CCMR1 &= ~(TIM_CCMR2_OC4M);
				TIM2->CCMR1 |=  (TIM_CCMR2_OC4M_2 | TIM_CCMR2_OC4M_1);
				TIM2->CCER  |=  TIM_CCER_CC4E;
			break;
			
			case Pwm_Channel_5:
				/* CCR1 determine duty cycle of channel_5 */
				TIM3->CCR1 = ( DutyCycle * (TIM3->ARR) );
			
				/*PWM mode 1 */
				TIM3->CCER  &= ~(TIM_CCER_CC1E);
				TIM3->CCMR1 &= ~(TIM_CCMR1_OC1M);
				TIM3->CCMR1 |=  (TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1);
				TIM3->CCER  |=  TIM_CCER_CC1E;
			break;
			
			case Pwm_Channel_6:
				/* CCR1 determine duty cycle of channel_6 */
				TIM3->CCR2 = ( DutyCycle * (TIM3->ARR) );
			
				/*PWM mode 1 */
				TIM3->CCER  &= ~(TIM_CCER_CC2E);
				TIM3->CCMR1 &= ~(TIM_CCMR1_OC2M);
				TIM3->CCMR1 |=  (TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_1);
				TIM3->CCER  |=  TIM_CCER_CC2E;
			break;
			
			case Pwm_Channel_7:
				/* CCR1 determine duty cycle of channel_7 */
				TIM3->CCR3 = ( DutyCycle * (TIM3->ARR) );
			
				/*PWM mode 1 */
				TIM3->CCER  &= ~(TIM_CCER_CC3E);
				TIM3->CCMR2 &= ~(TIM_CCMR2_OC3M);
				TIM3->CCMR2 |=  (TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3M_1);
				TIM3->CCER  |=  TIM_CCER_CC3E;	
			break;
		
			case Pwm_Channel_8:
				/* CCR1 determine duty cycle of channel_8 */
				TIM3->CCR4 = ( DutyCycle * (TIM3->ARR) );
			
				/*PWM mode 1 */
				TIM3->CCER  &= ~(TIM_CCER_CC4E);
				TIM3->CCMR2 &= ~(TIM_CCMR2_OC4M);
				TIM3->CCMR2 |=  (TIM_CCMR2_OC4M_2 | TIM_CCMR2_OC4M_1);
				TIM3->CCER  |=  TIM_CCER_CC4E;
			break;
			
			case Pwm_Channel_9:
				/* CCR1 determine duty cycle of channel_9 */
				TIM4->CCR1 = ( DutyCycle * (TIM4->ARR) );
			
				/*PWM mode 1 */
				TIM4->CCER  &= ~(TIM_CCER_CC1E);
				TIM4->CCMR1 &= ~(TIM_CCMR1_OC1M);
				TIM4->CCMR1 |=  (TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1);
				TIM4->CCER  |=  TIM_CCER_CC1E;
			break;
			
			case Pwm_Channel_10:
				/* CCR1 determine duty cycle of channel_10 */
				TIM4->CCR2 = ( DutyCycle * (TIM4->ARR) );
			
				/*PWM mode 1 */
				TIM4->CCER  &= ~(TIM_CCER_CC2E);
				TIM4->CCMR1 &= ~(TIM_CCMR1_OC2M);
				TIM4->CCMR1 |=  (TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_1);
				TIM4->CCER  |=  TIM_CCER_CC2E;
			break;
		
			case Pwm_Channel_11:
				/* CCR1 determine duty cycle of channel_11 */
				TIM4->CCR3 = ( DutyCycle * (TIM4->ARR) );
			
				/*PWM mode 1 */
				TIM4->CCER  &= ~(TIM_CCER_CC3E);
				TIM4->CCMR2 &= ~(TIM_CCMR2_OC3M);
				TIM4->CCMR2 |=  (TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3M_1);
				TIM4->CCER  |=  TIM_CCER_CC3E;
			break;
			
			case Pwm_Channel_12:
				/* CCR1 determine duty cycle of channel_12 */
				TIM4->CCR4 = ( DutyCycle * (TIM4->ARR) );
			
				/*PWM mode 1 */
				TIM4->CCER  &= ~(TIM_CCER_CC4E);
				TIM4->CCMR2 &= ~(TIM_CCMR2_OC4M);
				TIM4->CCMR2 |=  (TIM_CCMR2_OC4M_2 | TIM_CCMR2_OC4M_1);
				TIM4->CCER  |=  TIM_CCER_CC4E;
			break;
		}
		
	}
	else
	{
		/* No action needed */
	}
	
}

/************************************************************************************
* Service Name: Pwm_SetPeriodAndDuty
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelNumber: Numeric identifier of the PWM
					Period: Period of the PWM signal
					DutyCycle: Min=0x0000 Max=0x8000
* Parameters (inout): None
* Parameters (out): None
* Return value: 	None
* Description: Service sets the period and the duty cycle of a PWM channel.
************************************************************************************/
void Pwm_SetPeriodAndDuty(Pwm_ChannelType ChannelNumber, Pwm_PeriodType Period, uint16 DutyCycle )
{
	boolean error; 
	//Error check
	#if (PWM_DEV_ERROR_DETECT == STD_ON)
		if (PWM_Status == PWM_UNINIT)
		{
			Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_SET_PERIOD_AND_DUTY_SID, PWM_E_UNINIT);
			error = TRUE;
		}
		
		if (ChannelNumber > MAX_NUMBER_OF_SUPORTED_CHANNELS)
		{
			Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_SET_PERIOD_AND_DUTY_SID, PWM_E_PARAM_CHANNEL);
			error = TRUE;
		}
		
		if (Pwm_Configrations.Pwm_Channel_Configuration->ChannelClass == PWM_FIXED_PERIOD_SHIFTED)
		{
			Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_SET_PERIOD_AND_DUTY_SID, PWM_E_PERIOD_UNCHANGEABLE);
			error = TRUE;		
		}
		
		else 
		{
			error = FALSE;
		}
	#endif
	
		
	if(error == FALSE)
	{
	
		
	
	}
	else
	{
		/* No action needed */
	}
	
}

/************************************************************************************
* Service Name: Pwm_SetOutputToIdle
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelNumber: Numeric identifier of the PWM.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Service sets the PWM output to the configured Idle state.
************************************************************************************/
void Pwm_SetOutputToIdle( Pwm_ChannelType ChannelNumber )
{
	boolean error; 
	//Error check
	#if (PWM_DEV_ERROR_DETECT == STD_ON)
		if (PWM_Status == PWM_UNINIT)
		{
			Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_SET_PERIOD_AND_DUTY_SID, PWM_E_UNINIT);
			error = TRUE;
		}
		
		if (ChannelNumber > MAX_NUMBER_OF_SUPORTED_CHANNELS)
		{
			Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_SET_PERIOD_AND_DUTY_SID, PWM_E_PARAM_CHANNEL);
			error = TRUE;
		}
		
		else 
		{
			error = FALSE;
		}
	#endif
	
		
	if(error == FALSE)
	{
		switch (Pwm_Configrations.Pwm_Channel_Configuration[ChannelNumber].ChannelId)
		{
			case Pwm_Channel_1:
				TIM2->CCMR1 &= ~(TIM_CCMR1_OC1M);
				if(Pwm_Configrations.Pwm_Channel_Configuration[ChannelNumber].IdleState == PWM_HIGH)
				{
					TIM2->CCMR1 |= (TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_0);
				}
				else //(Pwm_Configrations.Pwm_Channel_Configuration[ChannelNumber].IdleState == PWM_HIGH)
				{
					TIM2->CCMR1 |= (TIM_CCMR1_OC1M_2);
				}
			break;
			
			case Pwm_Channel_2:
				TIM2->CCMR1 &= ~(TIM_CCMR1_OC2M);
				if(Pwm_Configrations.Pwm_Channel_Configuration[ChannelNumber].IdleState == PWM_HIGH)
				{
					TIM2->CCMR1 |= (TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_0);
				}
				else //(Pwm_Configrations.Pwm_Channel_Configuration[ChannelNumber].IdleState == PWM_HIGH)
				{
					TIM2->CCMR1 |= (TIM_CCMR1_OC2M_2);
				}
			break;
			
			case Pwm_Channel_3:
				TIM2->CCMR2 &= ~(TIM_CCMR2_OC3M);
				if(Pwm_Configrations.Pwm_Channel_Configuration[ChannelNumber].IdleState == PWM_HIGH)
				{
					TIM2->CCMR2 |= (TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3M_0);
				}
				else //(Pwm_Configrations.Pwm_Channel_Configuration[ChannelNumber].IdleState == PWM_HIGH)
				{
					TIM2->CCMR2 |= (TIM_CCMR2_OC3M_2);
				}
			break;
			
			case Pwm_Channel_4:
				TIM2->CCMR2 &= ~(TIM_CCMR2_OC4M);
				if(Pwm_Configrations.Pwm_Channel_Configuration[ChannelNumber].IdleState == PWM_HIGH)
				{
					TIM2->CCMR2 |= (TIM_CCMR2_OC4M_2 | TIM_CCMR2_OC4M_0);
				}
				else //(Pwm_Configrations.Pwm_Channel_Configuration[ChannelNumber].IdleState == PWM_HIGH)
				{
					TIM2->CCMR2 |= (TIM_CCMR2_OC4M_2);
				}
			break;
			
			case Pwm_Channel_5:
				TIM3->CCMR1 &= ~(TIM_CCMR1_OC1M);
				if(Pwm_Configrations.Pwm_Channel_Configuration[ChannelNumber].IdleState == PWM_HIGH)
				{
					TIM3->CCMR1 |= (TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_0);
				}
				else //(Pwm_Configrations.Pwm_Channel_Configuration[ChannelNumber].IdleState == PWM_HIGH)
				{
					TIM3->CCMR1 |= (TIM_CCMR1_OC1M_2);
				}
			break;
			
			case Pwm_Channel_6:
				TIM3->CCMR1 &= ~(TIM_CCMR1_OC2M);
				if(Pwm_Configrations.Pwm_Channel_Configuration[ChannelNumber].IdleState == PWM_HIGH)
				{
					TIM3->CCMR1 |= (TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_0);
				}
				else //(Pwm_Configrations.Pwm_Channel_Configuration[ChannelNumber].IdleState == PWM_HIGH)
				{
					TIM3->CCMR1 |= (TIM_CCMR1_OC2M_2);
				}
			break;
			
			case Pwm_Channel_7:
				TIM3->CCMR2 &= ~(TIM_CCMR2_OC3M);
				if(Pwm_Configrations.Pwm_Channel_Configuration[ChannelNumber].IdleState == PWM_HIGH)
				{
					TIM3->CCMR2 |= (TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3M_0);
				}
				else //(Pwm_Configrations.Pwm_Channel_Configuration[ChannelNumber].IdleState == PWM_HIGH)
				{
					TIM3->CCMR2 |= (TIM_CCMR2_OC3M_2);
				}
			break;
		
			case Pwm_Channel_8:
				TIM3->CCMR2 &= ~(TIM_CCMR2_OC4M);
				if(Pwm_Configrations.Pwm_Channel_Configuration[ChannelNumber].IdleState == PWM_HIGH)
				{
					TIM3->CCMR2 |= (TIM_CCMR2_OC4M_2 | TIM_CCMR2_OC4M_0);
				}
				else //(Pwm_Configrations.Pwm_Channel_Configuration[ChannelNumber].IdleState == PWM_HIGH)
				{
					TIM3->CCMR2 |= (TIM_CCMR2_OC4M_2);
				}
			break;
			
			case Pwm_Channel_9:
				TIM4->CCMR1 &= ~(TIM_CCMR1_OC1M);
				if(Pwm_Configrations.Pwm_Channel_Configuration[ChannelNumber].IdleState == PWM_HIGH)
				{
					TIM4->CCMR1 |= (TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_0);
				}
				else //(Pwm_Configrations.Pwm_Channel_Configuration[ChannelNumber].IdleState == PWM_HIGH)
				{
					TIM4->CCMR1 |= (TIM_CCMR1_OC1M_2);
				}
			break;
			
			case Pwm_Channel_10:
				TIM4->CCMR1 &= ~(TIM_CCMR1_OC2M);
				if(Pwm_Configrations.Pwm_Channel_Configuration[ChannelNumber].IdleState == PWM_HIGH)
				{
					TIM4->CCMR1 |= (TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_0);
				}
				else //(Pwm_Configrations.Pwm_Channel_Configuration[ChannelNumber].IdleState == PWM_HIGH)
				{
					TIM4->CCMR1 |= (TIM_CCMR1_OC2M_2);
				}
			break;
		
			case Pwm_Channel_11:
				TIM4->CCMR2 &= ~(TIM_CCMR2_OC3M);
				if(Pwm_Configrations.Pwm_Channel_Configuration[ChannelNumber].IdleState == PWM_HIGH)
				{
					TIM4->CCMR2 |= (TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3M_0);
				}
				else //(Pwm_Configrations.Pwm_Channel_Configuration[ChannelNumber].IdleState == PWM_HIGH)
				{
					TIM4->CCMR2 |= (TIM_CCMR2_OC3M_2);
				}
			break;
			
			case Pwm_Channel_12:
				TIM4->CCMR2 &= ~(TIM_CCMR2_OC4M);
				if(Pwm_Configrations.Pwm_Channel_Configuration[ChannelNumber].IdleState == PWM_HIGH)
				{
					TIM4->CCMR2 |= (TIM_CCMR2_OC4M_2 | TIM_CCMR2_OC4M_0);
				}
				else //(Pwm_Configrations.Pwm_Channel_Configuration[ChannelNumber].IdleState == PWM_HIGH)
				{
					TIM4->CCMR2 |= (TIM_CCMR2_OC4M_2);
				}
			break;
		}
	}
	
	else
	{
		/* No action needed */
	}
}

/************************************************************************************/


