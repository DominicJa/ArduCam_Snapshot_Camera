/*
 * tim.h
 *
 *  Created on: Aug 3, 2025
 *      Author: domin
 */

#ifndef TIM_H_
#define TIM_H_

void tim3_ms_delay(uint32_t delay);
void tim3_debounce_init(void);
void tim3_start(void);

#define SR_UIF		(1U<<0)

#endif /* TIM_H_ */
