/********************************Libraries******************************************************/
#include <fcntl.h>
#include <poll.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

/********************************Variables******************************************************/


/**************************Public Functions definitions*****************************************/
void nuttx_uart_open();
void nuttx_uart_close();
uint8_t nuttx_uart_write(char *buffer);
uint8_t nuttx_uart_read(char *buffer_out);
bool nuttx_uart_poll();
void nuttx_uart_config();
