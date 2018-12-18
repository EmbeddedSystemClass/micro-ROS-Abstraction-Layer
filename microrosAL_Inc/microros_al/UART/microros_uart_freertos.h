/********************************Libraries******************************************************/
#include <fcntl.h>
#include "stm32f4xx_hal.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>


/********************************Variables******************************************************/


/**************************Public Functions definitions*****************************************/
void freertos_uart_open();
void freertos_uart_close();
uint8_t freertos_uart_write(char *buffer);
uint8_t freertos_uart_read(char *buffer_out);
bool freertos_uart_poll();
void freertos_uart_config();
