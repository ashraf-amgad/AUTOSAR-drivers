#include "Motion_App.h"
#include "../Gpio_driver/GPIO.h"


const Motion_Commands_Type 	Motion_App_Configrations =
{
		 Stop_Command_Id	   , Stop_Command_Type ,
		 Forward_Command_Id  , Forward_Command_Type ,
		 Backword_Command_Id , Backword_Command_Type ,
};





void Motor_Speed(uint8_t 	Command_Type , uint8_t	Data)
{
	uint32_t counter=0;
		
	
		switch (Command_Type)
		{
			
				case Stop_Command_Type:
				case Forward_Command_Type:
						GPIO_voidSetPinValue(GPIOC ,GPIO_PIN_13 ,GPIO_SET);
						for(counter=0 ;counter<0x100000 ;counter++);
						GPIO_voidSetPinValue(GPIOC ,GPIO_PIN_13 ,GPIO_RESET);
						for(counter=0 ;counter<0x100000 ;counter++);
				break;
				
				
				case Backword_Command_Type:
					Data += 100;
						GPIO_voidSetPinValue(GPIOC ,GPIO_PIN_13 ,GPIO_SET);
						for(counter=0 ;counter<0x1000000 ;counter++);
						GPIO_voidSetPinValue(GPIOC ,GPIO_PIN_13 ,GPIO_RESET);
						for(counter=0 ;counter<0x1000000 ;counter++);					
					break;
				
				
				default:
					break;
						
		}

}


