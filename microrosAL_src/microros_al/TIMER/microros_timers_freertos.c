/******************************************************************************************
* freeRTOS timer AL implementation for microROS.
* This AL module, include the functions necessary to work with a timer.
* TODO:
* -OneShot Timer
*
*
*Developed by Acutronics Robotics, for microROS project.
* ****************************************************************************************/


/***************************Libraries & includes******************************************/
#include "microros_al/TIMER/microros_timer_freertos.h"

/**********************************Variables**********************************************/
TIM_HandleTypeDef aux[4];
int timers[4]={TIM1,TIM2,TIM3,TIM4};

/**********************************Private Functions*************************************/

static uint8_t check_config(uint8_t timer_num,uint32_t period){
  if(timer_num<0 || timer_num>4){
    printf("Timer number Out of range \n");
    return 0;
  }

  //Then we check if the period is also in range
  if(period<0 || period > 4294967296){
    //This number is because we have a timer of 32 Bits
    printf("Timer period out of range\n");
    return 0;
  }
  return 1;
}

/**********************************Public Functions**************************************/

/**************************************************************************
 * Description: This function is function is to modify the period of the
 * timer when is already working.
 * Arguments:  timer_num-> Timer that you want to use (1~4), period ->
 *  is the period of the timer (0 ~4294967296) in ms
 * Return: Nothing
 * Notes:
 **************************************************************************/
uint8_t freertos_timer_period(uint8_t timer_num, uint32_t period){

	if(!check_config(timer_num,period)) return 0;

	TIM_ClockConfigTypeDef sClockSourceConfig;
	TIM_MasterConfigTypeDef sMasterConfig;

	timer_num=timer_num-1;

	aux[timer_num].Init.Period = period;

	if (HAL_TIM_Base_Init(&aux[timer_num]) != HAL_OK)
	{
		_Error_Handler(__FILE__, __LINE__);
	}

	sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	if (HAL_TIM_ConfigClockSource(&aux[timer_num], &sClockSourceConfig) != HAL_OK)
	{
		_Error_Handler(__FILE__, __LINE__);
	}

	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&aux[timer_num], &sMasterConfig) != HAL_OK)
	{
		_Error_Handler(__FILE__, __LINE__);
	}

	return 1;
}

/**************************************************************************
 * Description: This function configure the timer.
 * Arguments:  timer_num-> Timer that you want to use (1~4), period ->
 *  is the period of the timer (0 ~4294967296) in ms
 * Return:  1 or 0, if the configuration was a success.
 * Notes:
 **************************************************************************/

uint8_t freertos_timer_config(uint8_t timer_num, uint32_t period){

	if(!check_config(timer_num,period)) return 0;

	timer_num=timer_num-1;

	aux[timer_num].Instance = (TIM_TypeDef *)timers[timer_num];
	aux[timer_num].Init.Prescaler = 16400;
	#ifdef STM32F407xx

	#elif STM32L1XX
		//TODO: Check the correct preescaler for this MCU
	#endif
	aux[timer_num].Init.CounterMode = TIM_COUNTERMODE_UP;
	freertos_timer_period(timer_num+1, period);

	return 1;
}

/**************************************************************************
 * Description: Start the specified timer.
 * Arguments: Timer_num -> Number of the timer to be use.
 * Return: If success 1 otherwise 0
 * Notes:
 **************************************************************************/

uint8_t freertos_timer_start(uint8_t timer_num){

  if(HAL_TIM_Base_Start_IT(&aux[timer_num-1]) != HAL_OK) return 1;
  return 0;

}

/**************************************************************************
 * Description: Stop the specified timer.
 * Arguments: Timer_num -> Number of the timer to be use.
 * Return: If success 1 otherwise 0.
 * Notes:
 **************************************************************************/

uint8_t freertos_timer_stop(uint8_t timer_num){
  if(HAL_TIM_Base_Stop_IT(&aux[timer_num-1]) != HAL_OK) return 1;
  return 0;
}

/**************************************************************************
 * Description: This function is only related with freertos because it
 * handle the interruptions
 * Arguments: Timer_num -> Number of the timer to be use.
 * Return: Nothing.
 * Notes:
 **************************************************************************/

void freertos_timer_handler(uint8_t timer_num){
	  HAL_TIM_IRQHandler(&aux[timer_num-1]);
}
