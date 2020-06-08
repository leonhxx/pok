#include "activity.h"
#include "deployment.h"
#include <arinc653/error.h>
#include <arinc653/partition.h>
#include <arinc653/process.h>
#include <arinc653/types.h>
/*****************************************************/
/*  This file was automatically generated by Ocarina */
/*  Do NOT hand-modify this file, as your            */
/*  changes will be lost when you re-run Ocarina     */
/*****************************************************/
PROCESS_ID_TYPE arinc_threads[POK_CONFIG_NB_THREADS];

/*******************************/
/* pok_error_handler_worker   */
/******************************/

void pok_error_handler_worker() {

  ERROR_STATUS_TYPE error_status;
  RETURN_CODE_TYPE ret;
  /*  The variables error and thread are createdto store the thread-id and */
  /*  the error-idwhen a fault is raised*/
  /*  We prefer to force a default value to the variableserror and thread*/
  /*  Here, we declare the fault handler as ready andthat faulty thread-id */
  /*  and error-id must be storedin the thread and error variables*/
  while (1) {
    STOP_SELF();
    GET_ERROR_STATUS(&(error_status), &(ret));
    switch (error_status.FAILED_PROCESS_ID) {
    case 1: {
      switch (error_status.ERROR_CODE) {
      case DEADLINE_MISSED: {
        pok_error_ignore(DEADLINE_MISSED, 1);

        break;
      }
      case APPLICATION_ERROR: {
        pok_error_ignore(APPLICATION_ERROR, 1);

        break;
      }
      case NUMERIC_ERROR: {
        pok_error_ignore(NUMERIC_ERROR, 1);

        break;
      }
      case ILLEGAL_REQUEST: {
        pok_error_ignore(ILLEGAL_REQUEST, 1);

        break;
      }
      case STACK_OVERFLOW: {
        pok_error_ignore(STACK_OVERFLOW, 1);

        break;
      }
      case MEMORY_VIOLATION: {
        pok_error_ignore(MEMORY_VIOLATION, 1);

        break;
      }
      case HARDWARE_FAULT: {
        pok_error_ignore(HARDWARE_FAULT, 1);

        break;
      }
      case POWER_FAIL: {
        pok_error_ignore(POWER_FAIL, 1);

        break;
      }
      }

      break;
    }
      /*  Here, we declare the error handling mecanisms for the task*/
    }
  }
  /*  IMPORTANT : this main function creates all resources (ports, data, */
  /*  tasks/threads/processes used by this   node*/
}

/***********/
/* main   */
/**********/

int main() {

  PROCESS_ATTRIBUTE_TYPE tattr;
  RETURN_CODE_TYPE ret;
  tattr.ENTRY_POINT = thr2_job;
  tattr.DEADLINE = 600000000;
  tattr.PERIOD = 1000000000;
  tattr.STACK_SIZE = 4000;
  tattr.TIME_CAPACITY = 1;
  CREATE_PROCESS(&(tattr), &(arinc_threads[1]), &(ret));
  /*  This thread was mapped from a thread component containedin this */
  /*  process. The function it executes is also generatedin the file */
  /*  activity.c.*/
  CREATE_ERROR_HANDLER(pok_error_handler_worker, 8192, &(ret));
  /*  One thread inside the partition can raise faults.We start the error */
  /*  handle to treat these potentialfaults.*/
  SET_PARTITION_MODE(NORMAL, &(ret));
  /*  Now, we created all resources of the process. Consequently,this thread */
  /*  will not be used any more and it will be keptin a dormant state. By */
  /*  doing that, we also allow one morethread in this partition*/
  return (0);
}
