#include "button.h"
//Функция инициализации кнопки SA4
void button_Init(void)
{
    //Создание структуры для инициализации порта
    PORT_InitTypeDef PORT_InitStructure;
    //Настройки порта: ввод, функция ввода/вывода, цифровой режим, минимальная скорость, Pin5
    PORT_InitStructure.PORT_OE = PORT_OE_IN;
    PORT_InitStructure.PORT_FUNC = PORT_FUNC_PORT;
    PORT_InitStructure.PORT_MODE = PORT_MODE_DIGITAL;
    PORT_InitStructure.PORT_SPEED = PORT_SPEED_SLOW;
    PORT_InitStructure.PORT_Pin = (PORT_Pin_5);
    PORT_Init(MDR_PORTD, &PORT_InitStructure);
}

//Функция считывания текущего состояния кнопки SA4
uint8_t button_State(void)
{
    return PORT_ReadInputDataBit(MDR_PORTD, PORT_Pin_5);
}