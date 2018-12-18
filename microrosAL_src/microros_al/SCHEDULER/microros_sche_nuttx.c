/******************************************************************************************
* freeRTOS scheduler AL implementation for microROS.
* This AL moudle, include the functions necessary to implement tasks and scheduler
* TODO:
* - Periodic sleep
* - Change and get priority of a task
* - Yield is correctly working??
* ****************************************************************************************/

/***************************Libraries & inlcudes******************************************/
#include "microros_al/SCHEDULING/microros_sche_nuttx.h"



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
 * Notes: As higher the priority number, higher the priority.(Minimun prio 1)
 **************************************************************************/

void nuttx_task_create(char *name, void *fun, int8_t priority, uint16_t stack_size){
  task_create(name,priority,stack_size, fun, NULL);
}

/**************************************************************************
 * Description: This function delete the task with the ID given.
 * Arguments: thread_id -> ID of the task to delete.
 * Return: Nothing
 * Notes: In the menuconfig must be set the signal options (In RTOS config)
 **************************************************************************/

void nuttx_task_delete(pid_t pid){
  kill(pid,SIGSTOP);//First it's necessary to stop the thread
  kill(pid,SIGKILL);
}

/**************************************************************************
 * Description: This function "sleep" the task for a number of ms.
 * Arguments: time_ms -> number of miliseconds to "sleep" the task
 * Return:Nothing
 * Notes:
  **************************************************************************/

void nuttx_task_delay(uint16_t time_ms){
  nxsig_usleep(time_ms*1000);
}

/**************************************************************************
 * Description:Change the priority of a task to the max priority
 * 			   periodically and then come back to the default priority.
 * Arguments: time_ms ->  Period of changing the priority of the task.
 * Return: Nothing
 * Notes:
  **************************************************************************/

void nuttx_task_periodic(uint16_t time_ms){
  //TODO
}

/**************************************************************************
 * Description: Returns the priority of the task.
 * Arguments: thread_id -> ID of the Task
 * Return: Priority of the task.
 * Notes:
 **************************************************************************/

int8_t nuttx_task_getpriority(pid_t pid){
  //TODO
/*  FAR struct tcb_s *tcb;
  tcb=sched_gettcb(pid);
  int i=tcb->affinity;
  printf("prioridad %d\r\n");*/
}

/**************************************************************************
 * Description: Set a different priority to the task.
 * Arguments: thread_id -> ID of the task, priority -> New priority of the task
 * Return: Nothing
 * Notes:
 **************************************************************************/

void nuttx_task_setpriority(pid_t pid, uint8_t priority){
//TODO
//  FAR struct tcb_s *tcb;
//  tcb=sched_gettcb(pid);
//  nxsched_reprioritize(tcb,priority);
}

/**************************************************************************
 * Description: Pass control to next thread that is in state.
 * Arguments: Nothing
 * Return: Nothing
 * Notes:
 **************************************************************************/

void nuttx_task_yield(){
  //hay que pararlo??
  sched_yield();// Tampooco funciona bien
}

/**************************************************************************
 * Description: Get the ID of the Task
 * Arguments: Nothing
 * Return: The ID of the Task.
 * Notes:
 **************************************************************************/

pid_t nuttx_task_getid(){
  return getpid();
}
