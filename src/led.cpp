#include "led.h"
//Функция инициализации светодиода VD7
void led_Init(void)
{
    //Создание структуры для инициализации порта
    PORT_InitTypeDef PORT_InitStructure;
    //Настройки порта: вывод, функция ввода/вывода, цифровой режим, максимальная скорость, Pin2
    PORT_InitStructure.PORT_OE = PORT_OE_OUT;
    PORT_InitStructure.PORT_FUNC = PORT_FUNC_PORT;
    PORT_InitStructure.PORT_MODE = PORT_MODE_DIGITAL;
    PORT_InitStructure.PORT_SPEED = PORT_SPEED_MAXFAST;
    PORT_InitStructure.PORT_Pin = (PORT_Pin_2);
    PORT_Init(MDR_PORTC, &PORT_InitStructure);
}

//Функция записи состояния (1:0) светодиода VD7
void led_Write(bool on_off)
{
    PORT_WriteBit(MDR_PORTC, PORT_Pin_2, on_off ? Bit_SET : Bit_RESET);
}