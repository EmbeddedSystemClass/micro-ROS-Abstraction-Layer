/********************************LIbraries******************************************************/
#include "microros_al/microros_config.h"
#ifdef freertos
	#include "microros_al/SCHEDULING/microros_sche_freertos.h"
#else
	#include "microros_al/SCHEDULING/microros_sche_nuttx.h"

#endif
#include "stdint.h"
/********************************Variables******************************************************/


/**************************Public Functions definitions*****************************************/

void uros_task_create(char *name, void *fun, uint8_t priority, uint16_t stack_size);
void uros_task_delete(void *thread_id);
void uros_task_delay(uint16_t time_ms);
void uros_task_periodic(uint16_t time_ms);
int8_t uros_task_getpriority(void *thread_id);
void uros_task_setpriority(void *thread_id,int8_t priority);
void uros_task_yield();

#ifdef freertos
	osThreadId uros_task_getid();
#else
	pid_t uros_task_getid();
#endif
