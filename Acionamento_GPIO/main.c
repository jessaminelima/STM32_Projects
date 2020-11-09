/*
 ******************************************************************************
 * File Name          : main.c
 * Created by         : Jessamine Lima
 ******************************************************************************
 */

#include "stm32f10x.h" 

void gpio_init(void);
void delaySystick_ms(uint32_t delay);

int main()
{
	 int i;
	 gpio_init();
	 while(1)
	 {
		  // Toggle L_1
		  for(i=0;i<2;i++)
      {
			    GPIOB->ODR ^= (1 << 12);
		      delaySystick_ms(25);	
			}
		  // Toggle L_2
		  for(i=0;i<2;i++)
      {
			    GPIOB->ODR ^= (1 << 13);
		      delaySystick_ms(25);	
			}
		  // Toggle L_3
		  for(i=0;i<2;i++)
      {
			    GPIOB->ODR ^= (1 << 14);
		      delaySystick_ms(25);	
			}
		  // Toggle L_4
		  for(i=0;i<2;i++)
      {
			    GPIOB->ODR ^= (1 << 15);
		      delaySystick_ms(25);	
			}
		  // Toggle L_5
		  for(i=0;i<2;i++)
      {
			    GPIOB->ODR ^= (1 << 6);
		      delaySystick_ms(25);	
			}
		  // Toggle L_6
		  for(i=0;i<2;i++)
      {
			    GPIOB->ODR ^= (1 << 7);
		      delaySystick_ms(25);	
			}
		  // Toggle L_7
		  for(i=0;i<2;i++)
      {
			    GPIOB->ODR ^= (1 << 8);
		      delaySystick_ms(25);	
			}
		  // Toggle L_8
		  for(i=0;i<2;i++)
      {
			    GPIOB->ODR ^= (1 << 9);
		      delaySystick_ms(25);	
			}

	 }
}

void gpio_init()
{
    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN | RCC_APB2ENR_IOPCEN;       // Enableing the Clock
	  GPIOB->CRL = 0;
	  GPIOB->CRH = 0;
	
	  GPIOB->CRL |= GPIO_CRL_MODE6_0;
	  GPIOB->CRL |= GPIO_CRL_MODE7_0;
	 	GPIOB->CRH |= GPIO_CRH_MODE8_0;
	  GPIOB->CRH |= GPIO_CRH_MODE9_0;
	  GPIOB->CRH |= GPIO_CRH_MODE12_0;
	 	GPIOB->CRH |= GPIO_CRH_MODE13_0;
	  GPIOB->CRH |= GPIO_CRH_MODE14_0;
	  GPIOB->CRH |= GPIO_CRH_MODE15_0;
}

void delaySystick_ms(uint32_t delay)                               // Function to configure the SysTick
{
    SysTick->LOAD = (SystemCoreClock/1000) - 1;                    // Takes the default Clock and divide to get the Cycles per ms
    SysTick->VAL = 0;                                              // Making the SysTick initial value as 0
	  SysTick->CTRL |= (1 << SysTick_CTRL_ENABLE_Pos)|(1 << SysTick_CTRL_CLKSOURCE_Pos); //ENABLING SYSTEM CLOCK, CLKSOURCE AND SYSTICK ENABLE
	  for(int i = 0; i < delay; i++)
	  {
		    while((SysTick->CTRL & (1 << SysTick_CTRL_COUNTFLAG_Pos)) == 0);
	  }	
	  SysTick->CTRL = 0;                                              // Disable the Systick
}


