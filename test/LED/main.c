#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
typedef unsigned int uint;

void led_red_bsrr()
{
	/*rgb 全亮
	GPIOB->BSRR |= (1<<21);
	GPIOB->BSRR |= (1<<16);
	GPIOB->BSRR |= (1<<17);

	rgb全灭
	GPIOB->BSRR |= (1<<5);
	GPIOB->BSRR |= (1<<0);
	GPIOB->BSRR |= (1<<1);
	*/

	GPIOB->BSRR |= (1<<21);
	GPIOB->BSRR |= (1<<0);
	GPIOB->BSRR |= (1<<1);
}

void led_green_bsrr()
{
	GPIOB->BSRR |= (1<<5);
	GPIOB->BSRR |= (1<<16);
	GPIOB->BSRR |= (1<<1);
}

void led_blue_bsrr()
{
	GPIOB->BSRR |= (1<<5);
	GPIOB->BSRR |= (1<<0);
	GPIOB->BSRR |= (1<<17);
}


void led_red_brr()
{
	/*
	GPIOB->BRR |= (1<<5);
	GPIOB->BRR |= (1<<0);
	GPIOB->BRR |= (1<<1);

	GPIOB->BRR &= ~(1<<5);
	GPIOB->BRR &= ~(1<<0);
	GPIOB->BRR &= ~(1<<1);*/

	GPIOB->BRR |= (1<<5);
	GPIOB->BRR &= ~(1<<0);
	GPIOB->BRR &= ~(1<<1);

}

void led_green_brr()
{
	GPIOB->BRR &= ~(1<<5);
	GPIOB->BRR |= (1<<0);
	GPIOB->BRR &= ~(1<<1);
}

void led_blue_brr()
{
	GPIOB->BRR &= ~(1<<5);
	GPIOB->BRR &= ~(1<<0);
	GPIOB->BRR |= (1<<1);
}

void led_all_on()
{
	GPIOB->ODR &= ~(1<<5);
	GPIOB->ODR &= ~(1<<0);
	GPIOB->ODR &= ~(1<<1);
}
void led_red()
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_5);
	GPIO_SetBits(GPIOB,GPIO_Pin_0);
	GPIO_SetBits(GPIOB,GPIO_Pin_1);
}

void led_green()
{
	GPIO_SetBits(GPIOB,GPIO_Pin_5);
	GPIO_ResetBits(GPIOB,GPIO_Pin_0);
	GPIO_SetBits(GPIOB,GPIO_Pin_1);
}

void led_blue()
{
	GPIO_SetBits(GPIOB,GPIO_Pin_5);
	GPIO_SetBits(GPIOB,GPIO_Pin_0);
	GPIO_ResetBits(GPIOB,GPIO_Pin_1);
}

void led_out()
{
	GPIOB->ODR |= (1<<5);
	GPIOB->ODR |= (1<<0);
	GPIOB->ODR |= (1<<1);
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

void select_led(uint16_t a)
{
	switch(a)
	{
		//001
		case 1:
			{
				GPIO_ResetBits(GPIOB,GPIO_Pin_5);	
				GPIO_ResetBits(GPIOB,GPIO_Pin_0);	
				GPIO_SetBits(GPIOB,GPIO_Pin_1);	
			}
			break;
		//010
		case 2:
			{
				GPIO_ResetBits(GPIOB,GPIO_Pin_5);	
				GPIO_SetBits(GPIOB,GPIO_Pin_0);	
				GPIO_ResetBits(GPIOB,GPIO_Pin_1);	
			}
			break;
		//011
		case 3:
			{
				GPIO_ResetBits(GPIOB,GPIO_Pin_5);	
				GPIO_SetBits(GPIOB,GPIO_Pin_0);	
				GPIO_SetBits(GPIOB,GPIO_Pin_1);	
			}
			break;
		//100
		case 4:
			{
				GPIO_SetBits(GPIOB,GPIO_Pin_5);	
				GPIO_ResetBits(GPIOB,GPIO_Pin_0);	
				GPIO_ResetBits(GPIOB,GPIO_Pin_1);	
			}
			break;
		//101
		case 5:
			{
				GPIO_SetBits(GPIOB,GPIO_Pin_5);	
				GPIO_ResetBits(GPIOB,GPIO_Pin_0);	
				GPIO_SetBits(GPIOB,GPIO_Pin_1);	
			}
			break;
		//111
		case 6:
			{
				GPIO_SetBits(GPIOB,GPIO_Pin_5);	
				GPIO_SetBits(GPIOB,GPIO_Pin_0);	
				GPIO_SetBits(GPIOB,GPIO_Pin_1);	
			}
			break;
		default:break;
	}
}

int main(void)
{

	//开启端口GPIO_B时钟
	RCC->APB2ENR |= (1<<3);

	//配置端口GPIO_PB0为输出  GREEN
	GPIOB->CRL &= ~( (0xf) << (4*0));//清零
	GPIOB->CRL |= ( (1) << (4*0));

	//配置端口GPIO_PB1为输出  BLUE
	GPIOB->CRL &= ~( (0xf) << (4*1));//清零
	GPIOB->CRL |= ( (1) << (4*1));

	//配置端口GPIO_PB5为输出  RED
	GPIOB->CRL &= ~( (0xf) << (4*5));//清零
	GPIOB->CRL |= ( (1) << (4*5));


	GPIOB->ODR |= (1<<5);//red 灭
	GPIOB->ODR |= (1<<0);//green 灭
	GPIOB->ODR |= (1<<1);//blue 灭



	GPIOB->BSRR &= ~0xffffffff;//清零
	GPIOB->BRR  &= ~0xffff;//清零



	while(1)
	{
		int i;
		for(i=1; i<7 ; ++i)	
		{
			select_led(i);
			delay_ms(9);
			led_out();
		}
	}
	/*
	GPIOB->ODR &= ~(1<<5);
	GPIOB->ODR &= ~(1<<0);
	GPIOB->ODR &= ~(1<<1);
	*/
}






void SystemInit(void){}
	
	
	
