/******************************************************************************************
* GPIO AL implementation for microROS.
* This AL module, include the functions necessary to implement GPIO control(Read and Write)
* TODO:
* -Interruptions. Problem cleaning the flags and the handle functions
* -ADC
*
*Developed by Acutronics Robotics, for microROS project.
* ****************************************************************************************/


/***************************Libraries & includes******************************************/
#include "microros_al/GPIO/microros_gpio_al.h"
#include "microros_al/microros_config.h"


/**********************************Variables**********************************************/


/**********************************Private Functions*************************************/


/**********************************Public Functions**************************************/

/**************************************************************************
 * Description: This function configure the working mode of each GPIO pin.
 * Arguments: Pin to setup (0~13) and mode(INPUT,OUTPUT,INTERRUPTION)
 * Return: Nothing
 * Notes: Interruption is not working yet.
 **************************************************************************/
void uros_gpio_config(uint8_t pin, uint8_t mode){
   #ifdef nuttx
    nuttx_gpio_config(pin,mode);
   #else
    freertos_gpio_config(pin,mode);
  #endif
}

/**************************************************************************
 * Description: This function write a value to the selected pin.
 * Arguments: Pin to write(0~13) and value (HIGH, LOW).
 * Return: Nothing.
 * Notes:
 **************************************************************************/
void uros_gpio_write(uint8_t pin, uint8_t value){
  #ifdef nuttx
    nuttx_digital_write(pin,value);
  #else
    freertos_digital_write(pin,value);
  #endif
}

/**************************************************************************
 * Description: This function reads the value of a pin.
 * Arguments: Pin(0~13).
 * Return: The value of the pin (0 or 1).
 * Notes:
 **************************************************************************/
bool uros_gpio_read(uint8_t pin){
  #ifdef nuttx
    return nuttx_digital_read(pin);
  #else
    return freertos_digital_read(pin);
  #endif
}
