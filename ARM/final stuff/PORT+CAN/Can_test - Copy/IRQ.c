#include "IRQ.h"


/**
  \brief   Enable Interrupt
  \details Enables a device specific interrupt in the NVIC interrupt controller.
  \param [in]      IRQn  Device specific interrupt number.
  \note    IRQn must not be negative.
 */
static __inline void NVIC_EnableIRQ(IRQn_Type IRQn)
{
  if ((int32)(IRQn) >= 0)
  {
    NVIC->ISER[(((uint32)IRQn) >> 5UL)] = (uint32)(1UL << (((uint32)IRQn) & 0x1FUL));
  }
}


