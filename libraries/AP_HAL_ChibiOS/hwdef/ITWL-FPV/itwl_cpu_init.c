#include <stm32h7xx.h>
//#include "ch.h"
//#include "hal.h"

//void __cpu_init(void) __attribute__((used, alias("__cpu_init_my")));
void __cpu_init(void) 
{
    //zaświeć niebieskiego LEDa
    RCC->AHB4ENR |= RCC_AHB4ENR_GPIOAEN; //włącz zegar portu A
    GPIOA->AFRL = (GPIOA->AFRL & ~(0xF<<(4*4))) | (0<<(4*4)); //PA4 LED_BLUE  OUTPUT LOW GPIO(28) 
    GPIOA->MODER = (GPIOA->MODER & ~(3<<(4*2))) | (1<<(4*2)); //PA4 LED_BLUE  OUTPUT LOW GPIO(28)
    GPIOA->ODR &= ~(1<<4); //PA4 LED_BLUE  aktywny niski poziom  s

    //hal.rcc->enable_peripheral_clock(AP_HAL::RCC::Peripheral::GPIOA);
    //hal.gpio->pinMode(28, AP_HAL::GPIO::OUTPUT); //LED_BLUE
    //hal.gpio->write(28, 0); //LED_BLUE on   
    
    //RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    //palSetPad(GPIOA, 4);       //PA4 LED_BLUE  OUTPUT LOW GPIO(28)  
    //palClearPad(GPIOA, 4);     //PA4 LED_BLUE  OUTPUT HIGH GPIO(28)

    //nie uruchmiaj cache bez wcześniejszego skonfigurowania MPU
    #if CORTEX_MODEL == 7
    //SCB_EnableICache();
    //SCB_EnableDCache();
    #endif
}