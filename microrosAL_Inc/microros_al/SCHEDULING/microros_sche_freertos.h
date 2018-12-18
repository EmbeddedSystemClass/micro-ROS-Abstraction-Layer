/********************************LIbraries******************************************************/
#include "stdint.h"
#include "cmsis_os.h"

/********************************Variables******************************************************/


/**************************Public Functions definitions*****************************************/

void freertos_task_create(char *name, void *fun, uint8_t priority, uint16_t stack_size);
void freertos_task_delete(osThreadId thread_id);
void freertos_task_delay(uint16_t time_ms);
void freertos_task_periodic(uint16_t time_ms);
int8_t freertos_task_getpriority(osThreadId thread_id);
void freertos_task_setpriority(osThreadId thread_id,int8_t priority);
void freertos_task_yield();
osThreadId freertos_task_getid();
