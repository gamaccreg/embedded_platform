/*
 ============================================================================
 Name        : coop_scheduler.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <sch.h>
#include <sch_cfg.h>

#include <dio.h>
#include <dio_cfg.h>

#include <sys_timer.h>

#include <tls.h>


int main(void) {
    Dio_Init();
    Sys_TimerInit();
    Sch_Init(&Sch_Cfg);

    Sch_Main();
	return 0;
}


static uint8 counter;

void Task_1000ms(void)
{
    if (Dio_ReadChannel(DIO_START) == STD_HIGH) {
        counter = 0;
    }
    tls_printf("\rTime: %02d:%02d:%02d", (counter/60/60)%24, (counter/60)%60, counter%60);
    counter++;
}

void Task_50ms(void)
{
}
