/******************************************************************************************
* microROS timer AL implementation.
* This AL module, include the functions necessary to work with a timer.
* TODO:
* -OneShot Timer
*
*
*Developed by Acutronics Robotics, for microROS project.
* ****************************************************************************************/


/***************************Libraries & includes******************************************/
#include "microros_al/TIMER/microros_timer_al.h"
#include "microros_al/microros_config.h"

/**********************************Variables**********************************************/

/**********************************Private Functions*************************************/

/**********************************Public Functions**************************************/

/**************************************************************************
 * Description: This function is function is to modify the period of the
 * timer when is already working.
 * Arguments:  timer_num-> Timer that you want to use (1~4), period ->
 *  is the period of the timer (0 ~4294967296) in ms
 * Return: Nothing
 * Notes:
 **************************************************************************/

uint8_t uros_timer_period(uint8_t timer_num, uint32_t period){
	#ifdef nuttx
		return nuttx_timer_period(timer_num,period);
	#else
		return freertos_timer_period(timer_num,period);
	#endif
}

/**************************************************************************
 * Description: This function configure the timer.
 * Arguments:  timer_num-> Timer that you want to use (1~4), period ->
 *  is the period of the timer (0 ~4294967296) in ms
 * Return:  1 or 0, if the configuration was a success.
 * Notes:
 **************************************************************************/
uint8_t uros_timer_config(uint8_t timer_num, uint32_t period){
	#ifdef nuttx
		return nuttx_timer_config(timer_num,period);
	#else
		return freertos_timer_config(timer_num,period);
	#endif
}

/**************************************************************************
 * Description: Start the specified timer.
 * Arguments: Timer_num -> Number of the timer to be use.
 * Return: If success 1 otherwise 0
 * Notes:
 **************************************************************************/
uint8_t uros_timer_start(uint8_t timer_num){
	#ifdef nuttx
		return nuttx_timer_start(timer_num);
	#else
		return freertos_timer_start(timer_num);
	#endif
}

/**************************************************************************
 * Description: Stop the specified timer.
 * Arguments: Timer_num -> Number of the timer to be use.
 * Return: If success 1 otherwise 0.
 * Notes:
 **************************************************************************/
uint8_t uros_timer_stop(uint8_t timer_num){
	#ifdef nuttx
		return nuttx_timer_stop(timer_num);
	#else
		return freertos_timer_stop(timer_num);
	#endif
}
