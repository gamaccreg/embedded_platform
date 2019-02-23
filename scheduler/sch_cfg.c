/*
 * sch_cfc.c
 *
 *  Created on: Nov 19, 2018
 *      Author: uia94411
 */

#include <sch.h>
#include <sch_cfg.h>

/* Configuration - edit to add new tasks */
void Task_1000ms(void);
void Task_50ms(void);

static Sch_Task_Type tasks[] = {
    {
        1000,        //interval in milliseconds
        0,           // offset: set equal to interval so the task is called on the first recurrence
        Task_1000ms  //Task container; implement in your application
    },
    {
        50,          //interval in milliseconds
        0,           // offset: set equal to interval so the task is called on the first recurrence
        Task_50ms  //Task container; implement in your application
    },
};
/* End of Configuration - edit to add new tasks */

/* Scheduler configuration; call Sch_Init(&Sch_Cfg) at startup */
Sch_Cfg_Type Sch_Cfg = {
    sizeof(tasks)/sizeof(tasks[0]),
    tasks
};
