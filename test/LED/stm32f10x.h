//外设 perirhral

typedef unsigned int uint;

#define PERIPH_BASE      (0x40000000)
#define APB1_PERIPH_BASE PERIPH_BASE
#define APB2_PERIPH_BASE (PERIPH_BASE+0x10000)
#define AHB_PERIPH_BASE  (PERIPH_BASE+0x20000)

/**/
#define RCC_BASE   (AHB_PERIPH_BASE+0x1000)

#define RCC_APB2ENR  *(uint *)(RCC_BASE+0x18)

#define GPIOA_BASE (APB2_PERIPH_BASE+0x0800)
#define GPIOB_BASE (APB2_PERIPH_BASE+0x0c00)
#define GPIOC_BASE (APB2_PERIPH_BASE+0x1000)
#define GPIOD_BASE (APB2_PERIPH_BASE+0x1400)
#define GPIOE_BASE (APB2_PERIPH_BASE+0x1800)
#define GPIOF_BASE (APB2_PERIPH_BASE+0x2000)
#define GPIOG_BASE (APB2_PERIPH_BASE+0x2400)

/**/

#define GPIOA_CRL    *(uint *)(GPIOA_BASE+0x00)
#define GPIOA_CRH    *(uint *)(GPIOA_BASE+0x04)
/*-----------端口配置寄存器-----------*/
#define GPIOA_CRL    *(uint *)(GPIOA_BASE+0x00)
#define GPIOA_CRH    *(uint *)(GPIOA_BASE+0x04)
#define GPIOB_CRL    *(uint *)(GPIOB_BASE+0x00)
#define GPIOB_CRH    *(uint *)(GPIOB_BASE+0x04)
#define GPIOC_CRL    *(uint *)(GPIOC_BASE+0x00)
#define GPIOC_CRH    *(uint *)(GPIOC_BASE+0x04)
#define GPIOD_CRL    *(uint *)(GPIOD_BASE+0x00)
#define GPIOD_CRH    *(uint *)(GPIOD_BASE+0x04)
#define GPIOE_CRL    *(uint *)(GPIOE_BASE+0x00)
#define GPIOE_CRH    *(uint *)(GPIOE_BASE+0x04)
#define GPIOF_CRL    *(uint *)(GPIOF_BASE+0x00)
#define GPIOF_CRH    *(uint *)(GPIOF_BASE+0x04)
#define GPIOG_CRL    *(uint *)(GPIOG_BASE+0x00)
#define GPIOG_CRH    *(uint *)(GPIOG_BASE+0x04)
/*----------------------*/
#define GPIOA_ODR    *(uint *)(GPIOA_BASE+0x0c)
#define GPIOB_ODR    *(uint *)(GPIOB_BASE+0x0c)
#define GPIOC_ODR    *(uint *)(GPIOC_BASE+0x0c)
#define GPIOD_ODR    *(uint *)(GPIOD_BASE+0x0c)
#define GPIOE_ODR    *(uint *)(GPIOE_BASE+0x0c)
#define GPIOF_ODR    *(uint *)(GPIOF_BASE+0x0c)
#define GPIOG_ODR    *(uint *)(GPIOG_BASE+0x0c)


#define GPIOA_BSRR *(uint *)(GPIOA_BASE+0x10)
#define GPIOB_BSRR *(uint *)(GPIOB_BASE+0x10)
#define GPIOC_BSRR *(uint *)(GPIOC_BASE+0x10)
#define GPIOD_BSRR *(uint *)(GPIOD_BASE+0x10)
#define GPIOE_BSRR *(uint *)(GPIOE_BASE+0x10)
#define GPIOF_BSRR *(uint *)(GPIOF_BASE+0x10)
#define GPIOG_BSRR *(uint *)(GPIOG_BASE+0x10)


#define GPIOA_BRR *(uint *)(GPIOA_BASE+0x14)
#define GPIOB_BRR *(uint *)(GPIOB_BASE+0x14)
#define GPIOC_BRR *(uint *)(GPIOC_BASE+0x14)
#define GPIOD_BRR *(uint *)(GPIOD_BASE+0x14)
#define GPIOE_BRR *(uint *)(GPIOE_BASE+0x14)
#define GPIOF_BRR *(uint *)(GPIOF_BASE+0x14)
#define GPIOG_BRR *(uint *)(GPIOG_BASE+0x14)
