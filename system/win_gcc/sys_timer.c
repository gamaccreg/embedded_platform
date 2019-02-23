/*
 * systimer.c
 *
 *  Created on: Nov 19, 2018
 *      Author: uia94411
 */

#include <windows.h>
#include <sys_timer.h>

#define MS 1000
#define S  (1000*MS)

static uint32 volatile Sys_Tick = 0;
LARGE_INTEGER time1, time2, freq;
sint64 delta;
const sint64  waitTime = 10*MS; //10ms

void Sys_TimerInit(void)
{
    Sys_Tick = 0;
    QueryPerformanceCounter(&time1);
    QueryPerformanceFrequency(&freq);
}

void Sys_TimerHandler(void)
{

    if(delta >= waitTime){
        Sys_Tick += 10;
        QueryPerformanceCounter(&time1);
        QueryPerformanceFrequency(&freq);
    }

    QueryPerformanceCounter(&time2);
    delta = time2.QuadPart-time1.QuadPart;
    delta *= 1000000;
    delta /= freq.QuadPart;


}

uint32_t Sys_GetTimer(void)
{
    return Sys_Tick;
}


