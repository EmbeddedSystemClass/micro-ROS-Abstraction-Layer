/********************************Libraries******************************************************/
#include "microros_al/microros_config.h"

#ifdef freertos
	#include <microros_al/TIMER/microros_timer_freertos.h>
#endif


/********************************Variables & Def*************************************************/


/**************************Public Functions definitions*****************************************/
uint8_t uros_timer_period(uint8_t timer_num, uint32_t period);
uint8_t uros_timer_config(uint8_t timer_num, uint32_t period);
uint8_t uros_timer_start(uint8_t timer_num);
uint8_t uros_timer_stop(uint8_t timer_num);
