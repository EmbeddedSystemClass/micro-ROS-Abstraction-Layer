/******************************************************************************************
* freeRTOS auxiliary UART AL implementation for microROS.
* This AL module, include the functions necessary to work with an auxiliary UART
* TODO:
* -Could open different UART
* -Close
* -On running reconfiguration of the UART
* -Some errors sending integers
*
*Developed by Acutronics Robotics, for microROS project.
* ****************************************************************************************/


/***************************Libraries & includes******************************************/
#include "microros_al/microros_al.h"
#include <string.h>
/**********************************Variables**********************************************/

UART_HandleTypeDef huart;
/**********************************Private Functions*************************************/


/**********************************Public Functions**************************************/

#ifdef freertos

/**************************************************************************
 * Description: This function configure the UART port.
 * Arguments: Nothing
 * Return: Nothing
 * Notes:
 **************************************************************************/

void freertos_uart_open(){

	#ifdef STM32F407xx
		__HAL_RCC_GPIOB_CLK_ENABLE();
		huart.Instance = USART3;
		huart.Init.BaudRate = 115200;
		huart.Init.WordLength = UART_WORDLENGTH_8B;
		huart.Init.StopBits = UART_STOPBITS_1;
		huart.Init.Parity = UART_PARITY_NONE;
		huart.Init.Mode = UART_MODE_TX_RX;
		huart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
		huart.Init.OverSampling = UART_OVERSAMPLING_16;
		if (HAL_UART_Init(&huart) != HAL_OK)
		{
			_Error_Handler(__FILE__, __LINE__);
		}
	#elif STM32L1XX
		//Añadir inicializacion del reloj
		huart.Instance = USART2;
		huart.Init.BaudRate = 115200;
		huart.Init.WordLength = UART_WORDLENGTH_8B;
		huart.Init.StopBits = UART_STOPBITS_1;
		huart.Init.Parity = UART_PARITY_NONE;
		huart.Init.Mode = UART_MODE_TX_RX;
		huart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
		huart.Init.OverSampling = UART_OVERSAMPLING_16;
		if (HAL_UART_Init(&huart) != HAL_OK)
		{
			_Error_Handler(__FILE__, __LINE__);
		}
	#endif

}

/**************************************************************************
 * Description: This function close the auxiliary UART port
 * Arguments:
 * Return:
 * Notes:
 **************************************************************************/

void freertos_uart_close(){
	//TODO
}

/**************************************************************************
 * Description: Send over the UART the data that you want.
 * Arguments: Char array to be send over the UART
 * Return: Return the number of bytes send or the 0 if it doesn't send anything
 * Notes:
 **************************************************************************/

uint8_t freertos_uart_write(char *buffer){
	//This function send a number of bytes thought the USART
	//First we check the number of bytes to send and then send it with a timeout of 100 ms

	uint8_t len =strlen(buffer);
	uint8_t state;
	state=HAL_UART_Transmit(&huart, (uint8_t *)buffer,len,100);

	if(state==HAL_OK) return len;
	return 0;
}

/**************************************************************************
 * Description: This function receive the data available in the UART.
 * Arguments: buffer_out -> Array to be saved the data received.
 * Return: The number of bytes received.
 * Notes:	//TODO: Create a global variable with the size of the buffer
 * - Implement the lecture like a interruption?
 **************************************************************************/

uint8_t freertos_uart_read( char *buffer_out){

	//Cleaning the buffer
	memset(buffer_out,'\0',strlen(buffer_out));
	//Receiving the data
	if(HAL_UART_Receive(&huart, (uint8_t*)buffer_out, 256, 1)==HAL_OK){
		//The buffer is full, returning the success
		return 1;
	}
	if((uint8_t*)strlen(buffer_out)!=NULL){
		//The buffer is not full, but we have some data
		return 1;
	}
	//Timeout without any data.
	return 0;


}

/**************************************************************************
 * Description: Check if there is any data available in the UART.
 * Arguments: Nothing
 * Return:
 * Notes:
 **************************************************************************/

bool freertos_uart_poll()
{
	//This function check the USART to see if there are any new data with a timeout of 10mS
	//This is a modification of the function UART_WaitOnFlagUntilTimeout

	uint32_t Timeout=10;//10 ms timeout
	uint32_t Flag=UART_FLAG_RXNE;//With this flag we can see if the UART is empty or no.
	FlagStatus Status=RESET;
	__HAL_LOCK(&huart);
	uint32_t Tickstart =HAL_GetTick();
	//We check the USART bus several times until the timeout finish.
	while((__HAL_UART_GET_FLAG(&huart, Flag) ? SET : RESET) == Status)
	{

		if(Timeout != HAL_MAX_DELAY)
		{
			if((Timeout == 0U)||((HAL_GetTick() - Tickstart ) > Timeout))
			{

				CLEAR_BIT(huart.Instance->CR1, (USART_CR1_RXNEIE | USART_CR1_PEIE | USART_CR1_TXEIE));
				CLEAR_BIT(huart.Instance->CR3, USART_CR3_EIE);

				huart.gState  = HAL_UART_STATE_READY;
				huart.RxState = HAL_UART_STATE_READY;


				__HAL_UNLOCK(&huart);
				return 0;
			}
		}
	}
	__HAL_UNLOCK(&huart);
	return 1;
}

/**************************************************************************
 * Description:
 * Arguments:
 * Return:
 * Notes:
 **************************************************************************/

void freertos_uart_config(){
	//TODO
}

#endif
