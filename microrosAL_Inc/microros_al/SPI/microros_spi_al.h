/********************************LIbraries******************************************************/
#include "microros_al/microros_config.h"

#ifdef freertos
	#include "microros_al/SPI/microros_spi_freertos.h"
#endif
#ifdef nuttx
	#include "microros_al/SPI/microros_spi_nuttx.h"
#endif
#include "stdint.h"

/********************************Variables******************************************************/


/**************************Public Functions definitions*****************************************/
void uros_spi_write(uint8_t regaddr, int8_t regval,uint8_t len );
uint32_t uros_spi_read(uint8_t regaddr,uint8_t len );
void uros_spi_config();
void uros_spi_aux();
