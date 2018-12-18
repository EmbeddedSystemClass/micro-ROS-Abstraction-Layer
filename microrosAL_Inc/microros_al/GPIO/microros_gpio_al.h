/********************************Libraries******************************************************/
#include "microros_al/microros_config.h"

#ifdef freertos
	#include <microros_al/GPIO/microros_gpio_freertos.h>
#endif
#ifdef nuttx
	#include <microros_al/GPIO/microros_gpio_nuttx.h>
#endif

#include "stdint.h"
#include "stdbool.h"

/********************************Variables & Def*************************************************/
#define INPUT 0xf1
#define OUTPUT 0xf2
#define INTERRUPTION 0xf3
#define HIGH 1
#define LOW 0

/**************************Public Functions definitions*****************************************/
void uros_gpio_config(uint8_t pin, uint8_t mode);
void uros_gpio_write(uint8_t pin, uint8_t value);
bool uros_gpio_read(uint8_t pin);
