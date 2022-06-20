#ifndef __PWM_REG_H__
#define __PWM_REG_H__



#include "Platform_Types.h"





typedef struct
{
  volatile uint16 CR1;
  uint16  RESERVED0;
  volatile uint16 CR2;
  uint16  RESERVED1;
  volatile uint16 SMCR;
  uint16  RESERVED2;
  volatile uint16 DIER;
  uint16  RESERVED3;
  volatile uint16 SR;
  uint16  RESERVED4;
  volatile uint16 EGR;
  uint16  RESERVED5;
  volatile uint16 CCMR1;
  uint16  RESERVED6;
  volatile uint16 CCMR2;
  uint16  RESERVED7;
  volatile uint16 CCER;
  uint16  RESERVED8;
  volatile uint16 CNT;
  uint16  RESERVED9;
  volatile uint16 PSC;
  uint16  RESERVED10;
  volatile uint16 ARR;
  uint16  RESERVED11;
  volatile uint16 RCR;
  uint16  RESERVED12;
  volatile uint16 CCR1;
  uint16  RESERVED13;
  volatile uint16 CCR2;
  uint16  RESERVED14;
  volatile uint16 CCR3;
  uint16  RESERVED15;
  volatile uint16 CCR4;
  uint16  RESERVED16;
  volatile uint16 BDTR;
  uint16  RESERVED17;
  volatile uint16 DCR;
  uint16  RESERVED18;
  volatile uint16 DMAR;
  uint16  RESERVED19;
} TIM_TypeDef;



/*!< Peripheral memory map */
#define PERIPH_BASE				((uint32)0x40000000)
#define APB1PERIPH_BASE       		PERIPH_BASE
#define APB2PERIPH_BASE       	(PERIPH_BASE + 0x10000)
#define AHBPERIPH_BASE        	(PERIPH_BASE + 0x20000)


#define TIM2_BASE             (APB1PERIPH_BASE + 0x0000)
#define TIM3_BASE             (APB1PERIPH_BASE + 0x0400)
#define TIM4_BASE             (APB1PERIPH_BASE + 0x0800)


#define TIM2                ((TIM_TypeDef *) TIM2_BASE)
#define TIM3                ((TIM_TypeDef *) TIM3_BASE)
#define TIM4                ((TIM_TypeDef *) TIM4_BASE)


/******************  Bit definition for TIM_CCMR1 register  *******************/

#define  TIM_CCMR1_CC1S                      ((uint16)0x0003)            /*!< CC1S[1:0] bits (Capture/Compare 1 Selection) */
#define  TIM_CCMR1_CC1S_0                    ((uint16)0x0001)            /*!< Bit 0 */
#define  TIM_CCMR1_CC1S_1                    ((uint16)0x0002)            /*!< Bit 1 */

#define  TIM_CCMR1_OC1FE                     ((uint16)0x0004)            /*!< Output Compare 1 Fast enable */
#define  TIM_CCMR1_OC1PE                     ((uint16)0x0008)            /*!< Output Compare 1 Preload enable */

#define  TIM_CCMR1_OC1M                      ((uint16)0x0070)            /*!< OC1M[2:0] bits (Output Compare 1 Mode) */
#define  TIM_CCMR1_OC1M_0                    ((uint16)0x0010)            /*!< Bit 0 */
#define  TIM_CCMR1_OC1M_1                    ((uint16)0x0020)            /*!< Bit 1 */
#define  TIM_CCMR1_OC1M_2                    ((uint16)0x0040)            /*!< Bit 2 */

#define  TIM_CCMR1_OC1CE                     ((uint16)0x0080)            /*!< Output Compare 1Clear Enable */

#define  TIM_CCMR1_CC2S                      ((uint16)0x0300)            /*!< CC2S[1:0] bits (Capture/Compare 2 Selection) */
#define  TIM_CCMR1_CC2S_0                    ((uint16)0x0100)            /*!< Bit 0 */
#define  TIM_CCMR1_CC2S_1                    ((uint16)0x0200)            /*!< Bit 1 */

#define  TIM_CCMR1_OC2FE                     ((uint16)0x0400)            /*!< Output Compare 2 Fast enable */
#define  TIM_CCMR1_OC2PE                     ((uint16)0x0800)            /*!< Output Compare 2 Preload enable */

#define  TIM_CCMR1_OC2M                      ((uint16)0x7000)            /*!< OC2M[2:0] bits (Output Compare 2 Mode) */
#define  TIM_CCMR1_OC2M_0                    ((uint16)0x1000)            /*!< Bit 0 */
#define  TIM_CCMR1_OC2M_1                    ((uint16)0x2000)            /*!< Bit 1 */
#define  TIM_CCMR1_OC2M_2                    ((uint16)0x4000)            /*!< Bit 2 */

#define  TIM_CCMR1_OC2CE                     ((uint16)0x8000)            /*!< Output Compare 2 Clear Enable */


/******************  Bit definition for TIM_CCMR2 register  *******************/
#define  TIM_CCMR2_CC3S                      ((uint16)0x0003)            /*!< CC3S[1:0] bits (Capture/Compare 3 Selection) */
#define  TIM_CCMR2_CC3S_0                    ((uint16)0x0001)            /*!< Bit 0 */
#define  TIM_CCMR2_CC3S_1                    ((uint16)0x0002)            /*!< Bit 1 */

#define  TIM_CCMR2_OC3FE                     ((uint16)0x0004)            /*!< Output Compare 3 Fast enable */
#define  TIM_CCMR2_OC3PE                     ((uint16)0x0008)            /*!< Output Compare 3 Preload enable */

#define  TIM_CCMR2_OC3M                      ((uint16)0x0070)            /*!< OC3M[2:0] bits (Output Compare 3 Mode) */
#define  TIM_CCMR2_OC3M_0                    ((uint16)0x0010)            /*!< Bit 0 */
#define  TIM_CCMR2_OC3M_1                    ((uint16)0x0020)            /*!< Bit 1 */
#define  TIM_CCMR2_OC3M_2                    ((uint16)0x0040)            /*!< Bit 2 */

#define  TIM_CCMR2_OC3CE                     ((uint16)0x0080)            /*!< Output Compare 3 Clear Enable */

#define  TIM_CCMR2_CC4S                      ((uint16)0x0300)            /*!< CC4S[1:0] bits (Capture/Compare 4 Selection) */
#define  TIM_CCMR2_CC4S_0                    ((uint16)0x0100)            /*!< Bit 0 */
#define  TIM_CCMR2_CC4S_1                    ((uint16)0x0200)            /*!< Bit 1 */

#define  TIM_CCMR2_OC4FE                     ((uint16)0x0400)            /*!< Output Compare 4 Fast enable */
#define  TIM_CCMR2_OC4PE                     ((uint16)0x0800)            /*!< Output Compare 4 Preload enable */

#define  TIM_CCMR2_OC4M                      ((uint16)0x7000)            /*!< OC4M[2:0] bits (Output Compare 4 Mode) */
#define  TIM_CCMR2_OC4M_0                    ((uint16)0x1000)            /*!< Bit 0 */
#define  TIM_CCMR2_OC4M_1                    ((uint16)0x2000)            /*!< Bit 1 */
#define  TIM_CCMR2_OC4M_2                    ((uint16)0x4000)            /*!< Bit 2 */

#define  TIM_CCMR2_OC4CE                     ((uint16)0x8000)            /*!< Output Compare 4 Clear Enable */

/*******************  Bit definition for TIM_CR1 register  ********************/
#define  TIM_CR1_CEN                         ((uint16)0x0001)            /*!< Counter enable */
#define  TIM_CR1_UDIS                        ((uint16)0x0002)            /*!< Update disable */
#define  TIM_CR1_URS                         ((uint16)0x0004)            /*!< Update request source */
#define  TIM_CR1_OPM                         ((uint16)0x0008)            /*!< One pulse mode */
#define  TIM_CR1_DIR                         ((uint16)0x0010)            /*!< Direction */

#define  TIM_CR1_CMS                         ((uint16)0x0060)            /*!< CMS[1:0] bits (Center-aligned mode selection) */
#define  TIM_CR1_CMS_0                       ((uint16)0x0020)            /*!< Bit 0 */
#define  TIM_CR1_CMS_1                       ((uint16)0x0040)            /*!< Bit 1 */

#define  TIM_CR1_ARPE                        ((uint16)0x0080)            /*!< Auto-reload preload enable */

#define  TIM_CR1_CKD                         ((uint16)0x0300)            /*!< CKD[1:0] bits (clock division) */
#define  TIM_CR1_CKD_0                       ((uint16)0x0100)            /*!< Bit 0 */
#define  TIM_CR1_CKD_1                       ((uint16)0x0200)            /*!< Bit 1 */



/*******************  Bit definition for TIM_CCER register  *******************/
#define  TIM_CCER_CC1E                       ((uint16)0x0001)            /*!< Capture/Compare 1 output enable */
#define  TIM_CCER_CC1P                       ((uint16)0x0002)            /*!< Capture/Compare 1 output Polarity */
#define  TIM_CCER_CC1NE                      ((uint16)0x0004)            /*!< Capture/Compare 1 Complementary output enable */
#define  TIM_CCER_CC1NP                      ((uint16)0x0008)            /*!< Capture/Compare 1 Complementary output Polarity */
#define  TIM_CCER_CC2E                       ((uint16)0x0010)            /*!< Capture/Compare 2 output enable */
#define  TIM_CCER_CC2P                       ((uint16)0x0020)            /*!< Capture/Compare 2 output Polarity */
#define  TIM_CCER_CC2NE                      ((uint16)0x0040)            /*!< Capture/Compare 2 Complementary output enable */
#define  TIM_CCER_CC2NP                      ((uint16)0x0080)            /*!< Capture/Compare 2 Complementary output Polarity */
#define  TIM_CCER_CC3E                       ((uint16)0x0100)            /*!< Capture/Compare 3 output enable */
#define  TIM_CCER_CC3P                       ((uint16)0x0200)            /*!< Capture/Compare 3 output Polarity */
#define  TIM_CCER_CC3NE                      ((uint16)0x0400)            /*!< Capture/Compare 3 Complementary output enable */
#define  TIM_CCER_CC3NP                      ((uint16)0x0800)            /*!< Capture/Compare 3 Complementary output Polarity */
#define  TIM_CCER_CC4E                       ((uint16)0x1000)            /*!< Capture/Compare 4 output enable */
#define  TIM_CCER_CC4P                       ((uint16)0x2000)            /*!< Capture/Compare 4 output Polarity */
#define  TIM_CCER_CC4NP                      ((uint16)0x8000)            /*!< Capture/Compare 4 Complementary output Polarity */

/*----------------------------------------------------------------------------*/

#endif


