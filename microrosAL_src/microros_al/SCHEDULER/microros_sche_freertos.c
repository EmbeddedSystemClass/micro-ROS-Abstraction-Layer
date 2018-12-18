/******************************************************************************************
* freeRTOS scheduler AL implementation for microROS.
* This AL module, include the functions necessary to implement tasks and scheduler
* TODO:
*- Improve the selection of priority
* ****************************************************************************************/

/***************************Libraries & includes******************************************/
#include "microros_al/SCHEDULING/microros_sche_freertos.h"

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

void freertos_task_create(char *name, void *fun, uint8_t priority, uint16_t stack_size){
//TODO: Add custom priority to unify with nuttx
  osThreadDef(name, fun, osPriorityNormal, 0, stack_size);
  osThreadCreate(osThread(name), NULL);
}

/**************************************************************************
 * Description: This function delete the task with the ID given.
 * Arguments: thread_id -> ID of the task to delete.
 * Return: Nothing
 * Notes:
 **************************************************************************/

void freertos_task_delete(osThreadId thread_id){
//Giving an ID, delete a Task.
	osThreadTerminate (thread_id);
}

/**************************************************************************
 * Description: This function "sleep" the task for a number of ms.
 * Arguments: time_ms -> number of miliseconds to "sleep" the task
 * Return:Nothing
 * Notes:
  **************************************************************************/

void freertos_task_delay(uint16_t time_ms){
//TODO: Give a description.
//osDelay function it's vTaskDelay but giving the possibility
//To wait in ms instead of systems tick

	osDelay(time_ms);
}

/**************************************************************************
 * Description:Change the priority of a task to the max priority
 * 			   periodically and then come back to the default priority.
 * Arguments: time_ms ->  Period of changing the priority of the task.
 * Return: Nothing
 * Notes:
  **************************************************************************/

void freertos_task_periodic(uint16_t time_ms){
//This function give maximun priority to a task with a determinist period.

	TickType_t xLastWakeTime;

	const TickType_t xDelayms = pdMS_TO_TICKS(time_ms);

	xLastWakeTime = xTaskGetTickCount();

	vTaskDelayUntil( &xLastWakeTime, xDelayms );
}

/**************************************************************************
 * Description: Returns the priority of the task.
 * Arguments: thread_id -> ID of the Task
 * Return: Priority of the task.
 * Notes:
 **************************************************************************/

int8_t freertos_task_getpriority(osThreadId thread_id){
//This function gets the priority of a task
	return osThreadGetPriority (thread_id);
}

/**************************************************************************
 * Description: Set a different priority to the task.
 * Arguments: thread_id -> ID of the task, priority -> New priority of the task
 * Return: Nothing
 * Notes:
 **************************************************************************/

void freertos_task_setpriority(osThreadId thread_id,int8_t priority){
//This function set the priority of the thread.
	osThreadSetPriority (thread_id,priority);
}

/**************************************************************************
 * Description: Pass control to next thread that is in state.
 * Arguments: Nothing
 * Return: Nothing
 * Notes:
 **************************************************************************/

void freertos_task_yield(){
//This function pass control to the next thread in the scheduler.
	osThreadYield ();
}

/**************************************************************************
 * Description: Get the ID of the Task
 * Arguments: Nothing
 * Return: The ID of the Task.
 * Notes:
 **************************************************************************/

osThreadId freertos_task_getid(){
//Obtains the ID of a task
	return osThreadGetId();
}
