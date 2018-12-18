/******************************************************************************************
* freeRTOS GPIO AL implementation for microROS.
* This AL module, include the functions necessary to implement GPIO control(Read and Write)
* TODO:
* -Interruptions. Problem cleaning the flags and the handle functions
* -ADC
*
*Developed by Acutronics Robotics, for microROS project.
* ****************************************************************************************/


/***************************Libraries & includes******************************************/
#include "microros_al/microros_al.h"


/**********************************Variables**********************************************/


/**********************************Private Functions*************************************/


/**********************************Public Functions**************************************/

#ifdef freertos

/**************************************************************************
 * Description: This function configure the working mode of each GPIO pin.
 * Arguments: Pin to setup (0~13) and mode(INPUT,OUTPUT,INTERRUPTION)
 * Return: Nothing
 * Notes: Interruption is not working yet.
 **************************************************************************/

void freertos_gpio_config(uint8_t pin, uint8_t mode){
	//Previous the use of this function, you need to bring up the port that you're looking for to use

	//First we check if the pins are in the available range
	if(pin<0 || pin >13){
		printf("Pin out of range\r\n");
		return ;
	}


	GPIO_InitTypeDef GPIO_InitStruct;

	//To save power only enables the GPIO clk in function of which pin we choose
	if(pin == 0 || pin == 1 || pin == 5) __HAL_RCC_GPIOB_CLK_ENABLE();
	else if(pin >= 2 || pin<=5) __HAL_RCC_GPIOE_CLK_ENABLE();
	else if(pin >= 6 || pin<=9) __HAL_RCC_GPIOG_CLK_ENABLE();
	else __HAL_RCC_GPIOA_CLK_ENABLE();


	//Choosing which mode do we want to use
	if(mode==0xf1)GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	else if(mode==0xf2)GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	else if(mode==0xf3)GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;

	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

	switch(pin) {
	//Only valid for Olimex Board
		case 0 :
		GPIO_InitStruct.Pin = GPIO_PIN_7;
		HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
		break;

		case 1 :
		GPIO_InitStruct.Pin = GPIO_PIN_6;
		HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
		break;

		case 2 :
		GPIO_InitStruct.Pin = GPIO_PIN_2;
		HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
		break;

		case 3 :
		GPIO_InitStruct.Pin = GPIO_PIN_4;
		HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
		break;

		case 4 :
		GPIO_InitStruct.Pin = GPIO_PIN_5;
		HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
		break;

		case 5 :
		GPIO_InitStruct.Pin = GPIO_PIN_6;
		HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
		break;

		case 6 :
		GPIO_InitStruct.Pin = GPIO_PIN_7;
		HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);
		break;

		case 7 :
		GPIO_InitStruct.Pin = GPIO_PIN_8;
		HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);
		break;

		case 8 :
		GPIO_InitStruct.Pin = GPIO_PIN_12;
		HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);
		break;

		case 9 :
		GPIO_InitStruct.Pin = GPIO_PIN_15;
		HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);
		break;

		case 10 :
		GPIO_InitStruct.Pin = GPIO_PIN_4;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
		break;

		case 11 :
		GPIO_InitStruct.Pin = GPIO_PIN_5;
		HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
		break;

		case 12 :
		GPIO_InitStruct.Pin = GPIO_PIN_6;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
		break;

		case 13 :
		GPIO_InitStruct.Pin = GPIO_PIN_5;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
		break;
		//Add analog pins
	}
}

/**************************************************************************
 * Description: This function write a value to the selected pin.
 * Arguments: Pin to write(0~13) and value (HIGH, LOW).
 * Return: Nothing.
 * Notes:
 **************************************************************************/


void freertos_digital_write(uint8_t pin, uint8_t value){

	switch(pin){
		case 0 :
			 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, value);
		break;
		case 1 :
			 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, value);
		break;
		case 2 :
			 HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2, value);
		break;
		case 3 :
			 HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, value);
		break;
		case 4 :
			 HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, value);
		break;
		case 5 :
			 HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, value);
		break;
		case 6 :
			 HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, value);
		break;
		case 7 :
			 HAL_GPIO_WritePin(GPIOG, GPIO_PIN_8, value);
		break;
		case 8 :
			 HAL_GPIO_WritePin(GPIOG, GPIO_PIN_12, value);
		break;
		case 9 :
			 HAL_GPIO_WritePin(GPIOG, GPIO_PIN_15, value);
		break;
		case 10 :
			 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, value);
		break;
		case 11 :
			 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, value);
		break;
		case 12 :
			 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, value);
		break;
		case 13 :
			 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, value);
		break;
	}
}

/**************************************************************************
 * Description: This function reads the value of a pin.
 * Arguments: Pin(0~13).
 * Return: The value of the pin (0 or 1).
 * Notes:
 **************************************************************************/


bool freertos_digital_read(uint8_t pin){

	uint8_t result=0;
	switch(pin){
		case 0 :
			result=HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7);
		break;
		case 1 :
			result=HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6);
		break;
		case 2 :
			result=HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_2);
		break;
		case 3 :
			result=HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_4);
		break;
		case 4 :
			result=HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_5);
		break;
		case 5 :
			result=HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_6);
		break;
		case 6 :
			result=HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_7);
		break;
		case 7 :
			result=HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_8);
		break;
		case 8 :
			result=HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_12);
		break;
		case 9 :
			result=HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_15);
		break;
		case 10 :
			result=HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4);
		break;
		case 11 :
			result=HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5);
		break;
		case 12 :
			 HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6);
		break;
		case 13 :
			 HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5);
		break;
	}
	return result;
}

/*************************************************************************/
/**********************************WIP***********************************/
/***********************************************************************/

/*bool freertos_int_attach(uint8_t pin){
	//TODO: Set priority
  if(pin<0 || pin>13) return 0; //Out of range the pin

//Setting interruption handler to each pin
  if(pin == 2){
	 HAL_NVIC_SetPriority(EXTI2_IRQn, 0, 0);
	 HAL_NVIC_EnableIRQ(EXTI2_IRQn);
  }
  else if(pin == 3|| pin == 10){
	 HAL_NVIC_SetPriority(EXTI4_IRQn, 0, 0);
	 HAL_NVIC_EnableIRQ(EXTI4_IRQn);
  }
  else if(pin==8 || pin==9){
	 HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
	 HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
  }
  else{
	  //Pins include: 0,1,4,5,6,7,11,12,13
	 HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
	 HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
  }
  return 1;

}

bool freertos_int_disattach(uint8_t pin){

  if(pin<0 || pin>13) return 0; //Out of range the pin

  //Setting interruption handler to each pin
  if(pin == 2) HAL_NVIC_DisableIRQ(EXTI2_IRQn);
  else if(pin == 3|| pin == 10)HAL_NVIC_DisableIRQ(EXTI4_IRQn);
  else if(pin==8 || pin==9)HAL_NVIC_DisableIRQ(EXTI15_10_IRQn);
  else HAL_NVIC_DisableIRQ(EXTI9_5_IRQn); //Pins include: 0,1,4,5,6,7,11,12,13

  return 1;
}

//Interruption handlers
//TODO: WIP Stil under work, needs to clean the interruption
void EXTI2_IRQHandler(void)
{
	printf("foo2\r\n");
	HAL_GPIO_EXTI_Callback(15);
}
void EXTI4_IRQHandler(void)
{
	printf("foo4\r\n");
}
void EXTI9_5_IRQHandler(void)
{

	printf("foo9-5\r\n");
}
void EXTI15_10_IRQHandler(void)
{
	printf("foo15-10\r\n");
}*/


# endif
