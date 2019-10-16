#include "main.h"
#include "clk.h"
#include "led.h"
#include "button.h"

int main(void)
{
    //Создание переменной для записи текущего состояния кнопки
    uint8_t state = 0;
    
    //Инициализация модулей
    clk_CoreConfig();
    led_Init();
    button_Init();
    
    while (1)
    {
        //Считывание текущего состояния кнопки SA4
        state = button_State();
        //Запись состояния кнопки на вывод светодиода VD7
        led_Write(!state);
    }
}
