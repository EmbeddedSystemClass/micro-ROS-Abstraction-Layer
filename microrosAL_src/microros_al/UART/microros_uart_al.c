/******************************************************************************************
* UART AL implementation for microROS.
* This AL module, include the functions necessary to implement GPIO control(Read and Write)
* TODO:
* -Could open different UART
* -Close
* -On running reconfiguration of the UART
*
*Developed by Acutronics Robotics, for microROS project.
* ****************************************************************************************/


/***************************Libraries & includes******************************************/
#include "microros_al/UART/microros_uart_al.h"
#include "microros_al/microros_config.h"


/**********************************Variables**********************************************/


/**********************************Private Functions*************************************/


/**********************************Public Functions**************************************/

/**************************************************************************
 * Description: This function configure the UART port.
 * Arguments: Nothing
 * Return: Nothing
 * Notes:
 **************************************************************************/

void uros_uart_open(){
    #ifdef nuttx
      nuttx_uart_open();
    #else
      //freertos_uart_open();
    #endif
}

/**************************************************************************
 * Description: This function close the auxiliary UART port
 * Arguments:
 * Return:
 * Notes:
 **************************************************************************/
void uros_uart_close(){
    #ifdef nuttx
      nuttx_uart_close();
    #else
      //freertos_uart_close();
    #endif
}

/**************************************************************************
 * Description: Send over the UART the data that you want.
 * Arguments: Char array to be send over the UART
 * Return: Return the number of bytes send or the 0 if it doesn't send anything
 * Notes:
 **************************************************************************/
uint8_t uros_uart_write(char *buffer){
	uint8_t ret=0;
  #ifdef nuttx
    ret=nuttx_uart_write(buffer);
  #else
    //ret=freertos_uart_write(buffer);
  #endif

  return ret;
}

/**************************************************************************
 * Description: This function receive the data available in the UART.
 * Arguments: buffer_out -> Array to be saved the data received.
 * Return: The number of bytes received.
 * Notes:
 **************************************************************************/

uint8_t uros_uart_read(char *buffer_out){
	uint8_t ret=0;
  #ifdef nuttx
    ret=nuttx_uart_read(buffer_out);
  #else
    //ret=freertos_uart_read(buffer_out);
  #endif

  return ret;
}

/**************************************************************************
 * Description: Check if there is any data available in the UART.
 * Arguments: Nothing
 * Return:
 * Notes:
 **************************************************************************/

bool uros_uart_poll(){
    int ret=0;
    #ifdef nuttx
      ret=nuttx_uart_poll();
    #else
      //ret=freertos_uart_poll();
    #endif

    return ret;
}
/**************************************************************************
 * Description:
 * Arguments:
 * Return:
 * Notes:
 **************************************************************************/
void uros_uart_config(){

    #ifdef nuttx
      nuttx_uart_config();
    #else
      //freertos_uart_config();
    #endif

}
