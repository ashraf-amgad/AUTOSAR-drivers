#include "Platform_Types.h"


typedef struct
{
volatile uint32 TIR;
volatile uint32 TDTR;
volatile uint32 TDLR;
volatile uint32 TDHR;
} CAN_TxMailBox_TypeDef;


typedef struct
{
volatile uint32 RIR;
volatile uint32 RDTR;
volatile uint32 RDLR;
volatile uint32 RDHR;
} CAN_FIFOMailBox_TypeDef;



typedef struct
{
volatile uint32 FR1;
volatile uint32 FR2;
} CAN_FilterRegister_TypeDef;


typedef struct
{
volatile uint32 MCR;
volatile uint32 MSR;
volatile uint32 TSR;
volatile uint32 RF0R;
volatile uint32 RF1R;
volatile uint32 IER;
volatile uint32 ESR;
volatile uint32 BTR;
volatile uint32 RESERVED0[88];
CAN_TxMailBox_TypeDef sTxMailBox[3];
CAN_FIFOMailBox_TypeDef sFIFOMailBox[2];
volatile uint32 RESERVED1[12];
volatile uint32 FMR;
volatile uint32 FM1R;
volatile uint32 RESERVED2[1];
volatile uint32 FS1R;
volatile uint32 RESERVED3[1];
volatile uint32 FFA1R;
volatile uint32 RESERVED4[1];
volatile uint32 FA1R;
volatile uint32 RESERVED5[8];
CAN_FilterRegister_TypeDef sFilterRegister[14];
} CAN_TypeDef;


#define PERIPH_BASE					 ((uint32)0x40000000)
#define APB1PERIPH_BASE					 ((uint32)PERIPH_BASE)
#define APB2PERIPH_BASE 		((uint32)(PERIPH_BASE + 0x10000))
#define AHBPERIPH_BASE 			((uint32)(PERIPH_BASE + 0x20000))


#define CAN1_BASE      ((uint32)(APB1PERIPH_BASE + 0x6400))
#define CAN2_BASE      ((uint32)(APB1PERIPH_BASE + 0x6800))

#define CAN1           ((CAN_TypeDef *) CAN1_BASE)
#define CAN2           ((CAN_TypeDef *) CAN2_BASE)



#define CAN1_MCR			(CAN1->MCR)
#define CAN1_MSR			(CAN1->MSR)
#define CAN1_TSR			(CAN1->TSR)
#define CAN1_RF0R			(CAN1->RF0R)
#define CAN1_RF1R			(CAN1->RF1R)
#define CAN1_IER			(CAN1->IER)
#define CAN1_ESR			(CAN1->ESR)	
#define CAN1_BTR			(CAN1->BTR)
#define CAN1_FMR			(CAN1->FMR)
#define CAN1_FM1R			(CAN1->FM1R)
#define CAN1_FS1R			(CAN1->FS1R)
#define CAN1_FFA1R		(CAN1->FFA1R)
#define CAN1_FA1R			(CAN1->FA1R)



#define CAN1_TI0R			(CAN1->sTxMailBox[0].TIR)
#define CAN1_TDT0R		(CAN1->sTxMailBox[0].TDTR)	
#define CAN1_TDL0R		(CAN1->sTxMailBox[0].TDLR)	
#define CAN1_TDH0R		(CAN1->sTxMailBox[0].TDHR)


#define CAN1_TI1R			(CAN1->sTxMailBox[1].TIR)
#define CAN1_TDT1R		(CAN1->sTxMailBox[1].TDTR)	
#define CAN1_TDL1R		(CAN1->sTxMailBox[1].TDLR)	
#define CAN1_TDH1R		(CAN1->sTxMailBox[1].TDHR)

#define CAN1_TI2R			(CAN1->sTxMailBox[2].TIR)
#define CAN1_TDT2R		(CAN1->sTxMailBox[2].TDTR)	
#define CAN1_TDL2R		(CAN1->sTxMailBox[2].TDLR)	
#define CAN1_TDH2R		(CAN1->sTxMailBox[2].TDHR)




#define CAN1_RI0R			(CAN1->sFIFOMailBox[0].RIR)
#define CAN1_RDT0R		(CAN1->sFIFOMailBox[0].RDTR)	
#define CAN1_RDL0R		(CAN1->sFIFOMailBox[0].RDLR)	
#define CAN1_RDH0R		(CAN1->sFIFOMailBox[0].RDHR)

#define CAN1_RI1R			(CAN1->sFIFOMailBox[1].RIR)
#define CAN1_RDT1R		(CAN1->sFIFOMailBox[1].RDTR)	
#define CAN1_RDL1R		(CAN1->sFIFOMailBox[1].RDLR)	
#define CAN1_RDH1R		(CAN1->sFIFOMailBox[1].RDHR)



#define CAN1_F0R1			(CAN1->sFilterRegister[0].FR0)
#define CAN1_F0R2			(CAN1->sFilterRegister[0].FR1)
#define CAN1_F1R1			(CAN1->sFilterRegister[1].FR0)
#define CAN1_F1R2			(CAN1->sFilterRegister[1].FR1)
#define CAN1_F2R1			(CAN1->sFilterRegister[2].FR0)
#define CAN1_F2R2			(CAN1->sFilterRegister[2].FR1)
#define CAN1_F3R1			(CAN1->sFilterRegister[3].FR0)
#define CAN1_F3R2			(CAN1->sFilterRegister[3].FR1)

#define CAN1_F4R1			(CAN1->sFilterRegister[4].FR0)
#define CAN1_F4R2			(CAN1->sFilterRegister[4].FR1)
#define CAN1_F5R1			(CAN1->sFilterRegister[5].FR0)
#define CAN1_F5R2			(CAN1->sFilterRegister[5].FR1)
#define CAN1_F6R1			(CAN1->sFilterRegister[6].FR0)
#define CAN1_F6R2			(CAN1->sFilterRegister[6].FR1)
#define CAN1_F7R1			(CAN1->sFilterRegister[7].FR0)
#define CAN1_F7R2			(CAN1->sFilterRegister[7].FR1)

#define CAN1_F8R1			(CAN1->sFilterRegister[8].FR0)
#define CAN1_F8R2			(CAN1->sFilterRegister[8].FR1)
#define CAN1_F9R1			(CAN1->sFilterRegister[9].FR0)
#define CAN1_F9R2			(CAN1->sFilterRegister[9].FR1)
#define CAN1_F10R1		(CAN1->sFilterRegister[10].FR0)
#define CAN1_F10R2		(CAN1->sFilterRegister[10].FR1)
#define CAN1_F11R1		(CAN1->sFilterRegister[11].FR0)
#define CAN1_F11R2		(CAN1->sFilterRegister[11].FR1)

#define CAN1_F12R1		(CAN1->sFilterRegister[12].FR0)
#define CAN1_F12R2		(CAN1->sFilterRegister[12].FR1)
#define CAN1_F13R1		(CAN1->sFilterRegister[13].FR0)
#define CAN1_F13R2		(CAN1->sFilterRegister[13].FR1)
