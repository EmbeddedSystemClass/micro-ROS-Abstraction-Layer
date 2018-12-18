/******************************************************************************************
* freeRTOS SPI AL implementation for microROS.
* This AL module, include the functions necessary to work with SPI
* TODO:
* -SPI DMA
* -Add the option to receive 4 bytes.
*
*Developed by Acutronics Robotics, for microROS project.
* ****************************************************************************************/

/***************************Libraries & includes******************************************/
#include "microros_al/SPI/microros_spi_freertos.h"


/**********************************Variables**********************************************/
SPI_HandleTypeDef hspi1;

/**********************************Private Functions*************************************/


/**********************************Public Functions**************************************/

/**************************************************************************
 * Description: This function writes a define value to a register address.
 * Arguments: regaddr ->  Register address where we want to write a value,
 * regval -> Value to write, len -> Length of the data that we want to write
 * Return: Nothing
 * Notes:
 **************************************************************************/
void freertos_spi_write(uint8_t regaddr, int8_t regval,uint8_t len ){
	//Revisar!
	HAL_SPI_Transmit(&hspi1,&regaddr,1,10);//Transmit the register dir that you want to read
	HAL_SPI_Transmit(&hspi1,&regval,len,10);
}

/**************************************************************************
 * Description: Read the value of a register.
 * Arguments: regaddr -> address to be read,
 * len -> Number of bytes that will be returned
 * Return:
 * Notes:
 **************************************************************************/
uint32_t freertos_spi_read(uint8_t regaddr,uint8_t len ){
	uint32_t regval=0;

	HAL_SPI_Transmit(&hspi1,&regaddr,1,10);//Transmit the register dir that you want to read
	HAL_SPI_Receive(&hspi1,&regval,len,10);//Then receive from the sensor the data
	if(len == 2 ){
		uint16_t msb, lsb;

		msb = (regval & 0xFF);
		lsb = (regval & 0xFF00) >> 8;

		regval = (msb << 8) | lsb;
	}
	else if(len==3){
		uint16_t v1, v2,v3;

		v1=(regval & 0xFF);
		v2=(regval & 0xFF00) >>8;
		v3=(regval & 0xFFFF00) >> 16;


		regval = (v1 << 16) | (v2 << 8) | v3;
	}
	return regval;
}

/**************************************************************************
 * Description: Function to set the SPI configuration in freeRTOS.
 * Arguments:Nothing
 * Return:Nothing
 * Notes:
 **************************************************************************/
void freertos_spi_config(){

	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	hspi1.Instance = SPI1;
	hspi1.Init.Mode = SPI_MODE_MASTER;
	hspi1.Init.Direction = SPI_DIRECTION_2LINES;
	hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
	hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
	hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
	hspi1.Init.NSS = SPI_NSS_SOFT;
	hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_128;
	hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
	hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
	hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
	hspi1.Init.CRCPolynomial = 10;
	if (HAL_SPI_Init(&hspi1) != HAL_OK)
	{
		_Error_Handler(__FILE__, __LINE__);
	}
}
