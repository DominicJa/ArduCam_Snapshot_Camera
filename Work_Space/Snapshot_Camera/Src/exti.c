#include "exti.h"


#define GPIOBEN			(1U<<1)
#define SYSCFGEn		(1U<<14)


void pbpins_exti_init(void)
{
	/*Disable global interrupts*/
	_disable_irq();

	/*Enable block access for GPIOB*/
	RCC->AHB1ENR |= GPIOBEN;

	/*Set PB4, PB5, PB14, PB15 as input*/
	GPIOB->MODER &= ~(3U<<8);
	GPIOB->MODER &= ~(3U<<10);
	GPIOB->MODER &= ~(3U<<28);
	GPIOB->MODER &= ~(3U<<30);

	/*Enable clock access to SYSCFG (I need to do more research on what this is)*/
	RCC->APB2ENR |= SYSCFGEN;

	/*Select PORTB for EXTI4*/
	/*Select PORTB for EXTI5*/
	/*Select PORTB for EXTI14*/
	/*Select PORTB for EXTI15*/

}

