/********************************LIbraries******************************************************/
#include "microros_al/microros_config.h"
#include "stm32f4xx_hal.h"
#include "stdlib.h"
#include "stdint.h"
#include "cmsis_os.h"

/********************************Variables******************************************************/


/**************************Public Functions definitions*****************************************/
void freertos_i2c_write(uint8_t device_addr,uint8_t data, int8_t addr);
uint32_t freertos_i2c_read(uint8_t device_addr,uint8_t regaddr,uint8_t len );
void freertos_i2c_init();
