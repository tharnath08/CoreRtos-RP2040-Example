#include <stdio.h>
#include "rtos_config.h"
#define TARGET_RP2040
#include "CoreRTOS.h"
#include "scheduler.h"

#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "pico/cyw43_arch.h"
#include "hardware/clocks.h"
#include "hardware/exception.h"
#include "hardware/gpio.h"  // Include for GPIO functions



bool flag = false;

void SysTick_Handler(){
    bool state = gpio_get(6);
    gpio_put(6, !state);
    printf("hello");
}

void HardFault_Handler(void) {
    volatile uint32_t *stackFrame;
}

void tast_hello(){
    while(1){
        printf("Hello RTOS\n");
        taskDelay(1000);
    }
}

void task2(){
    while(1){    
        printf("hello from Task2\n");
        taskDelay(2000);
    }
}

int main( void )
{
    stdio_init_all();
    
    
    // printTaskDetails();
    createTask(tast_hello,256, 2);
    // printTaskDetails();
    createTask(task2,256,1);
    // printTaskDetails();
    startScheduler();

    while(1);

    return 0;
}
