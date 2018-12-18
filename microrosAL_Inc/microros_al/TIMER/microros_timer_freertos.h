/********************************LIbraries******************************************************/
#include "microros_al/microros_config.h"
#include <stdlib.h>
#include <stdio.h>
#ifdef STM32F407xx
	#include "stm32f4xx_hal.h"
#elif STM32L1XX
	#include "stm32l1xx_hal.h"
#endif

/********************************Variables******************************************************/


/**************************Public Functions definitions*****************************************/
uint8_t freertos_timer_period(uint8_t timer_num, uint32_t period);
uint8_t freertos_timer_config(uint8_t timer_num, uint32_t period);
uint8_t freertos_timer_start(uint8_t timer_num);
uint8_t freertos_timer_stop(uint8_t timer_num);
void freertos_timer_handler(uint8_t timer_num);
