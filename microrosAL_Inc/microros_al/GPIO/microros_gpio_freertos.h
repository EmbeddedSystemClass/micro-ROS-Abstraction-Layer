/********************************LIbraries******************************************************/
#include "microros_al/microros_config.h"
#include "stdint.h"
#include "stdlib.h"
#include "stdbool.h"
#include "stm32f4xx_hal.h"

/********************************Variables******************************************************/


/**************************Public Functions definitions*****************************************/
void freertos_gpio_config(uint8_t pin, uint8_t mode);
void freertos_digital_write(uint8_t pin, uint8_t value);
bool freertos_digital_read(uint8_t pin);

