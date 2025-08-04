#include "stm32f4xx.h"
#include "external_switch.h"

#define PB4_PIN		(1U<<4)
#define PB5_PIN		(1U<<5)
#define PB14_PIN	(1U<<14)
#define PB15_PIN	(1U<<15)

int pl_switch = 0;
int pr_switch = 0;
int td_switch = 0;
int tu_switch = 0;

void do_nothing()
{

}

int main(void)
{
	gpiob_switch_init();

    /* Loop forever */
	while(1){
		pl_switch = (GPIOB->IDR & PB4_PIN);
		pr_switch = (GPIOB->IDR & PB5_PIN);
		td_switch = (GPIOB->IDR & PB14_PIN);
		tu_switch = (GPIOB->IDR & PB15_PIN);
	}
}
