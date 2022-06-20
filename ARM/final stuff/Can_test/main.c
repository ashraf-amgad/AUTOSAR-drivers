#include "Can.h"
#include "Can_reg.h"



Can_PduType* test_massage;


int main()
{
	RCC->APB2ENR |= (RCC_APB2ENR_AFIOEN | RCC_APB2ENR_IOPAEN);
	RCC->APB1ENR |= (RCC_APB1ENR_CAN1EN);
	
	uint8 data[8];
	data[0]='a';
	data[2]='b';
	data[3]='c';
	data[4]=32;

	
	
	test_massage->DLC = 1; 
	test_massage->id  = 0x121; 
	test_massage->sdu = data; 

	Can_Init(&Can_Configrations);
	
//	uint32 delay   = 0x00ff;
//	uint32 counter = 0x00;
	while(1)
	{
			Can_Write( CAN_HOH_0_HandleType , test_massage);
			//for(counter = 0 ; counter < delay ; counter++);
	
	}
	

}

