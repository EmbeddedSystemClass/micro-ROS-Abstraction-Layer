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

/*******************************Libraries**************************************/
#include "microros_al/microros_al.h"
/*******************************Variables**************************************/
int fd0; //file descriptor for the peripheral

/**********************************Public Functions**************************************/

#ifdef nuttx

/**************************************************************************
 * Description: This function configure the UART port.
 * Arguments: Nothing
 * Return: Nothing
 * Notes:TODO:Change the flags of nonblocking lecture to get from the configuration
 **************************************************************************/

void nuttx_uart_open(){

  #ifdef CONFIG_ARCH_CHIP_STM32F407ZG
    //Open call to the olimex board
    fd0 = open("/dev/ttyS0", O_RDWR | O_NONBLOCK); //O_NONBLOCK Temporary implementation
  #elif CONFIG_ARCH_CHIP_STM32L152RC
    //Open call to the STM32L1Discovery board
    fd0 = open("/dev/ttyS1", O_RDWR);
  #endif

  if(fd0<0){
    printf("Error opening the port\r\n");
    return 0;
  }
  return 1;
}

/**************************************************************************
 * Description: This function close the auxiliary UART port
 * Arguments:Nothing
 * Return: Nothing
 * Notes:
 **************************************************************************/
void nuttx_uart_close(){
  //Close the UART connection
    close(fd0);
}

/**************************************************************************
 * Description: Send over the UART the data that you want.
 * Arguments: Char array to be send over the UART
 * Return: Return the number of bytes send or the 0 if it doesn't send anything
 * Notes:
 **************************************************************************/

uint8_t nuttx_uart_write(char *buffer){
  //This funciton check how many char you want to send and send through the UART
  //Argument: The array of characters to send
  //Return: It returns a 1 if it send the same number of characters as the buffer
  //size.


  int len = strlen(buffer); //Take the number of characters
  int ret=0; // Variable to save the number of bytes send

  ret=write(fd0,buffer,sizeof(char)*len);// Write the data

  if(len==ret) return ret;
  else return 0;
}

/**************************************************************************
 * Description: This function receive the data available in the UART.
 * Arguments: buffer_out -> Array to be saved the data received.
 * Return: The number of bytes received.
 * Notes:	//TODO: Create a global variable with the size of the buffer
 * - Implement the lecture like a interruption?
 **************************************************************************/

uint8_t nuttx_uart_read(char *buffer_out){

  //Each MCU have be default a different UART set
  #ifdef CONFIG_ARCH_CHIP_STM32F407ZG
    char buffer[CONFIG_USART3_RXBUFSIZE]={};
  #elif CONFIG_ARCH_CHIP_STM32L152RC
    //char buffer[CONFIG_USART2_RXBUFSIZE]={};
  #endif
  //Reading the data avaliable
  //It returns -1 if any data is available
  int ret = read(fd0,&buffer,sizeof(buffer));

  memcpy(buffer_out,buffer,strlen(buffer));

  return ret;
}

/**************************************************************************
 * Description: Check if there is any data available in the UART.
 * Arguments: Nothing
 * Return:
 * Notes:
 **************************************************************************/

bool nuttx_uart_poll(){

  struct pollfd pfd;
  pfd.fd=fd0;
  pfd.events=POLLIN;
  pfd.revents=0;
  uint8_t ret=poll(&pfd,1,10);
  //If a data is available return 1 otherwise, return 0
  return ret;
}

/**************************************************************************
 * Description:
 * Arguments:
 * Return:
 * Notes:
 **************************************************************************/

void nuttx_uart_config(){
  //TODO
  // -DMA
  // - Interruptions
  // - Reconfiguration parameters (BauRate, bitstop...)
  // - TImeout of Poll
  // - If the reading is blocking
  #ifdef CONFIG_ARCH_CHIP_STM32F407ZG
    //Read call to the olimex board
  #elif CONFIG_ARCH_CHIP_STM32L152RC
    //Read call to the STM32L1Discovery board
  #endif
}
#endif
