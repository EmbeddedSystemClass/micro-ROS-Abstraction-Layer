/******************************************************************************************
* I2C AL implementation for microROS.
* This AL module, include the functions necessary to implement GPIO control(Read and Write)
* TODO:
*
*
*Developed by Acutronics Robotics, for microROS project.
* ****************************************************************************************/


/***************************Libraries & includes******************************************/
#include "microros_al/I2C/microros_i2c_al.h"
#include "microros_al/microros_config.h"

/**********************************Variables**********************************************/


/**********************************Private Functions*************************************/


/**********************************Public Functions**************************************/

/**************************************************************************
 * Description: This function sends the data to I2C bus.
 * Arguments: Nothing
 * Return: Nothing
 * Notes:
 **************************************************************************/

void uros_i2c_write(uint8_t device_addr,uint8_t regaddr, int8_t regval,uint8_t len ){
  #ifdef nuttx
    nuttx_i2c_write( device_addr,regaddr,regval,len );
  #else
   // freertos_i2c_write(device_addr,regval, regaddr,len);
  #endif
}

/**************************************************************************
 * Description: Read the value of a given I2C register.
 * Arguments: device_addr -> Address of the device to work with, regaddr ->
 * 	Value to read, len -> size of the data that we're going to receive in
 * 	bytes.
 * Return: Value of the register.
 * Notes:
 **************************************************************************/

uint32_t uros_i2c_read(uint8_t device_addr,uint8_t regaddr,uint8_t len ){
  #ifdef nuttx
    return nuttx_i2c_read(device_addr,regaddr,len );
  #else
    return freertos_i2c_read( device_addr, regaddr, len );
  #endif
}

/**************************************************************************
 * Description:This is an auxiliary function that gets the peripherals data
 * in NuttX and give the possibility to use in the AL.
 * In freertos it's not necessary to implement anything.
 * Arguments:The I2C profile.
 * Return:
 * Notes: Only if you want to use POSIX
 **************************************************************************/
uint32_t uros_i2c_hal_aux(void *aux){
  #ifdef nuttx
    return nuttx_i2c_hal_aux(aux);
  #else
    //nothing to add
  #endif

}


/**************************************************************************
 * Description: This function setup the I2C port.
 * Arguments: Nothing
 * Return:Nothing
 * Notes:
 **************************************************************************/
void uros_i2c_init(){
	#ifdef nuttx
  nuttx_i2c_init();
	#else
	freertos_i2c_init();
	#endif
}
