/*
 * sch.c
 *
 *  Created on: Nov 19, 2018
 *      Author: uia94411
 */

/**
 * Struct TaskType
 * TaskType structure is used to define the parameters required in order to
 * configure a task.
 */
#include <std_types.h>

typedef struct
{
    uint16 interval;          /**< Defines how often a task will run  */
    uint32 next_tick;          /**< Stores the last tick task was ran  */
    void (*func)(void);         /**< Function pointer to the task  */
} Sch_Task_Type;

typedef struct
{
    uint8_t size;
    Sch_Task_Type * tasks;
} Sch_Cfg_Type;

#ifdef __cplusplus
extern "C"{
#endif

void Sch_Init(Sch_Cfg_Type * cfg_ptr);
void Sch_Main(void);

#ifdef __cplusplus
} // extern "C"
#endif

