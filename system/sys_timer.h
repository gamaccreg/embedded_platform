/*
 * systimer.h
 *
 *  Created on: Nov 19, 2018
 *      Author: uia94411
 */

#ifndef SYS_TIMER_H_
#define SYS_TIMER_H_
#include <std_types.h>

void Sys_TimerInit(void);
void Sys_TimerHandler(void);
uint32 Sys_GetTimer(void);



#endif /* SYS_TIMER_H_ */
