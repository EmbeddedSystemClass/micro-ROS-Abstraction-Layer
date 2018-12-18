/********************************LIbraries******************************************************/
#include "microros_al/microros_config.h"

#ifdef freertos
	#include "microros_al/I2C/microros_i2c_freertos.h"
#else
	#include "microros_al/I2C/microros_i2c_nuttx.h"
#endif

/********************************Variables & Def*************************************************/


/**************************Public Functions definitions*****************************************/
void uros_i2c_write(uint8_t device_addr,uint8_t regaddr, int8_t regval,uint8_t len );
uint32_t uros_i2c_read(uint8_t device_addr,uint8_t regaddr,uint8_t len );
uint32_t uros_i2c_hal_aux(void *aux);
void uros_i2c_config();
