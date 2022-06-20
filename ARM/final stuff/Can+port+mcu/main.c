#include "Can.h"
#include "Mcu.h"

Can_PduType test_massage;


int main()
{
	
			

	Mcu_Init(&Mcu_Configuration);	
	Mcu_InitClock(CLOCK_CONFIG_0);
	
	Port_Init(&Port_Configuration);
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

