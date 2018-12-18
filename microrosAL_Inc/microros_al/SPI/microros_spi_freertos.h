/********************************LIbraries******************************************************/
#include "microros_al/microros_config.h"
#include "stm32f4xx_hal.h"
#include "stdlib.h"
#include <stdint.h>

/********************************Variables******************************************************/


/**************************Public Functions definitions*****************************************/
void freertos_spi_write(uint8_t regaddr, int8_t regval,uint8_t len );
uint32_t freertos_spi_read(uint8_t regaddr,uint8_t len );
void freertos_spi_config();

