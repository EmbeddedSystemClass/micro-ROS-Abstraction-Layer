/********************************LIbraries******************************************************/
#include "microros_al/microros_config.h"
#include <nuttx/i2c/i2c_master.h>
#include "stdlib.h"
#include "stdint.h"

/********************************Variables******************************************************/


/**************************Public Functions definitions*****************************************/
void nuttx_i2c_write(uint8_t device_addr,uint8_t regaddr, int8_t regval,uint8_t len );
uint32_t nuttx_i2c_read(uint8_t device_addr,uint8_t regaddr,uint8_t len );
uint8_t nuttx_i2c_hal_aux(struct i2c_master_s *i2c);
