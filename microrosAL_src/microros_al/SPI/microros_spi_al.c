/******************************************************************************************
* SPI AL implementation for microROS.
* This AL module, include the functions necessary to implement SPI peripheral
* TODO:
*
*
*Developed by Acutronics Robotics, for microROS project.
* ****************************************************************************************/


/***************************Libraries & includes******************************************/
#include "microros_al/SPI/microros_spi_al.h"
#include "microros_al/microros_config.h"

/**********************************Variables**********************************************/

/**********************************Private Functions*************************************/


/**********************************Public Functions**************************************/

/**************************************************************************
 * Description: This function writes a define value to a register address.
 * Arguments: regaddr ->  Register address where we want to write a value,
 * regval -> Value to write, len -> Length of the data that we want to write
 * Return: Nothing
 * Notes:
 **************************************************************************/

void uros_spi_write(uint8_t regaddr, int8_t regval,uint8_t len ){
	#ifdef nuttx
	nuttx_spi_write(regaddr,regval,len);
	#else
	freertos_spi_write(regaddr,regval,len);
	#endif
}

/**************************************************************************
 * Description: Read the value of a register.
 * Arguments: regaddr -> address to be read,
 * len -> Number of bytes that will be returned
 * Return:
 * Notes:
 **************************************************************************/
uint32_t uros_spi_read(uint8_t regaddr,uint8_t len ){
	#ifdef nuttx
	return nuttx_spi_read(regaddr,len);
	#else
	return freertos_spi_read(regaddr,len );
	#endif
}

/**************************************************************************
 * Description: Function to set the SPI configuration in freeRTOS.
 * Arguments:Nothing
 * Return:Nothing
 * Notes:
 **************************************************************************/
void uros_spi_config(){
	#ifdef nuttx
	nuttx_spi_config();
	#else
	freertos_spi_config();
	#endif
}

/**************************************************************************
 * Description:
 * Arguments:
 * Return:
 * Notes:
 **************************************************************************/
void uros_spi_aux(void *spi){
	#ifdef nuttx
	nuttx_spi_hal_aux(spi);
	#else
	#endif
}
