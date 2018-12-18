/******************************************************************************************
* Scheduler AL implementation for microROS.
* This AL module, include the functions necessary to implement tasks and scheduler
* TODO:
*
* ****************************************************************************************/
#include "microros_al/SCHEDULING/microros_sche_al.h"
#include "microros_al/microros_config.h"
/***************************Libraries & includes******************************************/


/**********************************Variables**********************************************/


/**********************************Private Functions*************************************/


/**********************************Public Functions**************************************/

/**************************************************************************
 * Description:This function creates a task attaching to a function,
 * 			   giving a priority and a stack size.
 * Arguments: name-> A human understandable name, fun -> function to attach
 * 			  priority -> priority of the function,
 * 			  stack_size-> Stack size of the task.
 * Return: Nothing
 * Notes:
 **************************************************************************/

void uros_task_create(char *name, void *fun, uint8_t priority, uint16_t stack_size){
	#ifdef freertos
	freertos_task_create(name,fun,priority,stack_size);
	#else
	nuttx_task_create(name,fun,priority,stack_size);
	#endif
}

/**************************************************************************
 * Description: This function delete the task with the ID given.
 * Arguments: thread_id -> ID of the task to delete.
 * Return: Nothing
 * Notes:
 **************************************************************************/



void uros_task_delete(void *thread_id){
	#ifdef freertos
		freertos_task_delete(thread_id);
	#else
		nuttx_task_delete(thread_id);
	#endif
}


/**************************************************************************
 * Description: This function "sleep" the task for a number of ms.
 * Arguments: time_ms -> number of miliseconds to "sleep" the task
 * Return:Nothing
 * Notes:
  **************************************************************************/

void uros_task_delay(uint16_t time_ms){
	#ifdef freertos
		freertos_task_delay(time_ms);
	#else
		nuttx_task_delay(time_ms);
	#endif
}

/**************************************************************************
 * Description:Change the priority of a task to the max priority
 * 			   periodically and then come back to the default priority.
 * Arguments: time_ms ->  Period of changing the priority of the task.
 * Return: Nothing
 * Notes:
  **************************************************************************/

void uros_task_periodic(uint16_t time_ms){
	#ifdef freertos
		freertos_task_periodic(time_ms);
	#else
		nuttx_task_periodic(time_ms);
	#endif
}

/**************************************************************************
 * Description: Returns the priority of the task.
 * Arguments: thread_id -> ID of the Task
 * Return: Priority of the task.
 * Notes:
 **************************************************************************/


int8_t uros_task_getpriority(void *thread_id){
	#ifdef freertos
		return freertos_task_getpriority(thread_id);
	#else
		return nuttx_task_getpriority(thread_id);
	#endif
}

/**************************************************************************
 * Description: Set a different priority to the task.
 * Arguments: thread_id -> ID of the task, priority -> New priority of the task
 * Return: Nothing
 * Notes:
 **************************************************************************/


void uros_task_setpriority(void *thread_id,int8_t priority){
	#ifdef freertos
		freertos_task_setpriority(thread_id,priority);
	#else
		nuttx_task_setpriority( thread_id, priority);
	#endif
}

/**************************************************************************
 * Description: Pass control to next thread that is in state.
 * Arguments: Nothing
 * Return: Nothing
 * Notes:
 **************************************************************************/

void uros_task_yield(){
	#ifdef freertos
		freertos_task_yield();
	#else
		nuttx_task_yield();
	#endif
}

/**************************************************************************
 * Description: Get the ID of the Task
 * Arguments: Nothing
 * Return: The ID of the Task.
 * Notes:
 **************************************************************************/
#ifdef freertos
osThreadId uros_task_getid(){
	return freertos_task_getid();
#else
pid_t uros_task_getid(){
	return nuttx_task_getid();
#endif
}
