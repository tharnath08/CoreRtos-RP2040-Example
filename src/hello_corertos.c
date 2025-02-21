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







void tast_hello(){
    printf("Hello RTOS\n");
    taskDelay(1000);
}

void task2(){
    printf("hello from Task2\n");
    taskDelay(2000);
}

int main( void )
{
    stdio_init_all();
    uint32_t clk_freq = clock_get_hz(clk_sys);

    initSystick(0);



    // initRTOS(clk_freq);
    gpio_init(6);
    gpio_set_dir(6, GPIO_OUT);
    gpio_put(6,1);
    
    
    // printTaskDetails();
    createTask(tast_hello,1024, 2);
    // printTaskDetails();
    createTask(task2,1024,1);
    // printTaskDetails();
    startScheduler();

    while(1);

    return 0;
}
