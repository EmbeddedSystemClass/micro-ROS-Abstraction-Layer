/********************************LIbraries******************************************************/
#include "stdint.h"
#include "unistd.h"
#include "sys/types.h"
#include <stdio.h>
/********************************Variables******************************************************/


/**************************Public Functions definitions*****************************************/

void nuttx_task_create(char *name, void *fun, int8_t priority, uint16_t stack_size);
void nuttx_task_delete(pid_t pid);
void nuttx_task_delay(uint16_t time_ms);
void nuttx_task_periodic(uint16_t time_ms);
int8_t nuttx_task_getpriority(pid_t pid);
void nuttx_task_setpriority(pid_t pid, uint8_t priority);
void nuttx_task_yield();
pid_t nuttx_task_getid();
