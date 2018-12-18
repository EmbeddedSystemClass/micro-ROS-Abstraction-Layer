#include "microros_config.h"

#ifdef GPIO
	#include <microros_al/GPIO/microros_gpio_al.h>
#endif
#ifdef UART
	#include <microros_al/UART/microros_uart_al.h>
#endif
#ifdef SCHEDULING
	#include <microros_al/SCHEDULING/microros_sche_al.h>
#endif
#ifdef TIMER
	#include <microros_al/TIMER/microros_timer_al.h>
#endif
#ifdef I2C
	#include <microros_al/I2C/microros_i2c_al.h>
#endif
#ifdef SPI
	#include <microros_al/SPI/microros_spi_al.h>
#endif

#ifdef nuttx
	#include <nuttx/config.h>
#endif 
