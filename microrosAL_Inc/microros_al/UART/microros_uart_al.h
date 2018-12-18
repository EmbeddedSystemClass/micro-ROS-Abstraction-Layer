/********************************LIbraries******************************************************/
#include "microros_al/microros_config.h"

#ifdef freertos
	#include "microros_al/UART/microros_uart_freertos.h"
#else 
	
#endif
#include "microros_al/UART/microros_uart_nuttx.h"
/********************************Variables & Def*************************************************/


/**************************Public Functions definitions*****************************************/
void uros_uart_open();
void uros_uart_close();
uint8_t uros_uart_write(char *buffer);
uint8_t uros_uart_read(char *buffer_out);
bool uros_uart_poll();
void uros_uart_config();
