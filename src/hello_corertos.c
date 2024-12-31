#include <stdio.h>

#include "CoreRTOS.h"
#include "scheduler.h"

#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "pico/cyw43_arch.h"

void tast_hello(){
    printf("Hello RTOS\n");
}

void task2(){
    printf("hello from Task2\n");
}

int main( void )
{
    stdio_init_all();
    
    CreateTask(tast_hello, 2);
    CreateTask(task2,1);
    startScheduler();

    return 0;
}
