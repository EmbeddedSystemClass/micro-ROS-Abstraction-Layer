/********************************LIbraries******************************************************/
#include "microros_al/microros_config.h"
#include <nuttx/spi/spi.h>
#include "stdlib.h"
#include "stdint.h"

/********************************Variables******************************************************/


/**************************Public Functions definitions*****************************************/
void nuttx_spi_write(uint8_t regaddr, int8_t regval,uint8_t len );
uint32_t nuttx_spi_read(uint8_t regaddr,uint8_t len );
void nuttx_spi_config();
uint32_t nuttx_spi_hal_aux(struct spi_dev_s *spi);
