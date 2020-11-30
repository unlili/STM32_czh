#include "stm32f10x.h"
typedef unsigned int uint;

void led_red_bsrr()
{
	/*rgb 全亮
	GPIOB_BSRR |= (1<<21);
	GPIOB_BSRR |= (1<<16);
	GPIOB_BSRR |= (1<<17);

	rgb全灭
	GPIOB_BSRR |= (1<<5);
	GPIOB_BSRR |= (1<<0);
	GPIOB_BSRR |= (1<<1);
	*/

	GPIOB_BSRR |= (1<<21);
	GPIOB_BSRR |= (1<<0);
	GPIOB_BSRR |= (1<<1);
}

void led_green_bsrr()
{
	GPIOB_BSRR |= (1<<5);
	GPIOB_BSRR |= (1<<16);
	GPIOB_BSRR |= (1<<1);
}

void led_blue_bsrr()
{
	GPIOB_BSRR |= (1<<5);
	GPIOB_BSRR |= (1<<0);
	GPIOB_BSRR |= (1<<17);
}


void led_red_brr()
{
	/*
	GPIOB_BRR |= (1<<5);
	GPIOB_BRR |= (1<<0);
	GPIOB_BRR |= (1<<1);

	GPIOB_BRR &= ~(1<<5);
	GPIOB_BRR &= ~(1<<0);
	GPIOB_BRR &= ~(1<<1);*/

	GPIOB_BRR |= (1<<5);
	GPIOB_BRR &= ~(1<<0);
	GPIOB_BRR &= ~(1<<1);

}

void led_green_brr()
{
	GPIOB_BRR &= ~(1<<5);
	GPIOB_BRR |= (1<<0);
	GPIOB_BRR &= ~(1<<1);
}

void led_blue_brr()
{
	GPIOB_BRR &= ~(1<<5);
	GPIOB_BRR &= ~(1<<0);
	GPIOB_BRR |= (1<<1);
}

void led_all_on()
{
	GPIOB_ODR &= ~(1<<5);
	GPIOB_ODR &= ~(1<<0);
	GPIOB_ODR &= ~(1<<1);
}
void led_red()
{
	GPIOB_ODR &= ~(1<<5);
	GPIOB_ODR |= (1<<0);//green 灭
	GPIOB_ODR |= (1<<1);//blue 灭
}

void led_green()
{
	GPIOB_ODR |= (1<<5);//red 灭
	GPIOB_ODR &= ~(1<<0);
	GPIOB_ODR |= (1<<1);//blue 灭
}

void led_blue()
{
	GPIOB_ODR |= (1<<5);//red 灭
	GPIOB_ODR |= (1<<0);//green 灭
	GPIOB_ODR &= ~(1<<1);
}

void led_out()
{
	GPIOB_ODR |= (1<<5);
	GPIOB_ODR |= (1<<0);
	GPIOB_ODR |= (1<<1);
}


//微秒级的延时
void delay_us(uint delay_us)
{    
  volatile unsigned int num;
  volatile unsigned int t;
 
  
  for (num = 0; num < delay_us; num++)
  {
    t = 11;
    while (t != 0)
    {
      t--;
    }
  }
}

//毫秒级的延时
void delay_ms(uint delay_ms)
{    
  volatile unsigned int num;
  for (num = 0; num < delay_ms; num++)
  {
    delay_us(1000);
  }
}

void led_on(char a)
{
	switch(a)
	{
		case 'r' : led_red(); break;
		case 'g' : led_green(); break;
		case 'b' : led_blue(); break;
		default  : led_all_on(); break;
	}
}

int main(void)
{

	//开启端口GPIO_B时钟
	RCC_APB2ENR |= (1<<3);

	//配置端口GPIO_PB0为输出  GREEN
	GPIOB_CRL &= ~( (0xf) << (4*0));//清零
	GPIOB_CRL |= ( (1) << (4*0));

	//配置端口GPIO_PB1为输出  BLUE
	GPIOB_CRL &= ~( (0xf) << (4*1));//清零
	GPIOB_CRL |= ( (1) << (4*1));

	//配置端口GPIO_PB5为输出  RED
	GPIOB_CRL &= ~( (0xf) << (4*5));//清零
	GPIOB_CRL |= ( (1) << (4*5));


	GPIOB_ODR |= (1<<5);//red 灭
	GPIOB_ODR |= (1<<0);//green 灭
	GPIOB_ODR |= (1<<1);//blue 灭



	GPIOB_BSRR &= ~0xffffffff;//清零
	GPIOB_BRR  &= ~0xffff;//清零



	for(;;)
	{
		led_on('q');
		delay_ms(100);
		led_out();
		delay_ms(100);


		led_on('q');
		delay_ms(100);
		led_out();
		delay_ms(100);


		led_on('1');
		delay_ms(100);
		led_out();
		delay_ms(100);

	}

	/*
	GPIOB_ODR &= ~(1<<5);
	GPIOB_ODR &= ~(1<<0);
	GPIOB_ODR &= ~(1<<1);
	*/

}

void SystemInit(void){}
	
