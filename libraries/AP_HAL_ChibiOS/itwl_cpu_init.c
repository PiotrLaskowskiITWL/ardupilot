
#include "hal.h"

//void __cpu_init(void) __attribute__((used));    // wymuszamy użycie symbolu w finalnym ELF
void __cpu_init(void);

void __cpu_init(void) 
{
    //zaświeć niebieskiego LEDa
    RCC->AHB4ENR |= RCC_AHB4ENR_GPIOAEN; //włącz zegar portu A
    //GPIOA->AFRL = (GPIOA->AFRL & ~(0xF<<(4*4))) | (0<<(4*4)); //PA4 LED_BLUE  OUTPUT LOW GPIO(28) 
    
    GPIOA->MODER &= ~(3U << (4 * 2));   // ustaw PA4 jako wyjście
    GPIOA->MODER |=  (1U << (4 * 2));
    GPIOA->ODR &= ~(1U << 4);           //PA4 LED_BLUE  aktywny niski poziom  

    //SCB_EnableICache();
    //SCB_EnableDCache();
    
    //return 1;     błąd do testowania kompilacji
}