#include "Can.h"


Can_PduType test_massage;


int main()
{
	
			
	/* enable clock of CAN_peripheral */

	RCC->APB1ENR |= RCC_APB1ENR_CAN1EN;
	//RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1 ,ENABLE);
	
	/* enable clock of CAN_peripheral Pins*/
	RCC->APB2ENR |= (RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN);
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOA ,ENABLE);
	
	
	/* GPIO CONFIGRATIONS ------------------------------------------------------*/
	/*=====================*/
	
	/* set PORTA_PIN_11 (CAN_RX) to input pull up/down after clear the pin posistion configrations */
	GPIOA->CRH &= ~(GPIO_CRH_CNF11 | GPIO_CRH_MODE11);
	GPIOA->CRH |= GPIO_CRH_CNF11_1;
	
	
	/* set PORTA_PIN_12 (CAN_TX) to output push pull after clear the pin posistion configrations */
	GPIOA->CRH &= ~(GPIO_CRH_CNF12 | GPIO_CRH_MODE12);
	GPIOA->CRH |= (GPIO_CRH_CNF12_1 | GPIO_CRH_MODE12);
	
	
	


	

	Can_Init(&Can_Configrations);
	
	test_massage.id = 0x123;
	test_massage.DLC = 1;
	test_massage.sdu[0] = 'a';
	
	uint32 i = 0;
	uint32 delay = 0x00ffffff;
	
	while(1)
	{
			
			Can_Write( CAN_HOH_0_HandleType , &test_massage);
			test_massage.sdu[0]++;
			for(i=0 ;i<delay ;i++);
	
	}
	

}

