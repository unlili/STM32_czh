#include "stm32f10x.h"
typedef unsigned int uint;


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
	GPIOB_ODR |= (1<<5);//red 灭
	GPIOB_ODR |= (1<<0);//green 灭
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

	for(;;)
	{
		led_red();
		delay_ms(9);
		led_out();

		led_green();
		delay_ms(9);
		led_out();

		led_blue();
		delay_ms(9);
		led_out();

	}

	/*
	GPIOB_ODR &= ~(1<<5);
	GPIOB_ODR &= ~(1<<0);
	GPIOB_ODR &= ~(1<<1);
	*/

}






void SystemInit(void){}
	
	
	
