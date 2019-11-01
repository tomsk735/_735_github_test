/*******************************************************************************
*                   : TUSUR
* File              : main.cpp
* IDE               : Apache NetBeans
* Version           : 11.1
* Last modified     : 30.10.2019
* 
* Authors           : Zaitsev Michael, Koryshev Nikolay, Mazurok Oleg
* Support mail      : dev.humwer@gmail.com
* 
* Description       : Code Morze and work with GPIO
*
********************************************************************************/
#include "main.h"
#include "morze.h"
#include "rxtx.h"

// StrobePin1    PORT_Pin_0
// StrobePin2    PORT_Pin_3
// RXPin       PORT_Pin_1
// TXPin       PORT_Pin_2

void clk_CoreConfig (uint32_t div, uint32_t mul);
void button_Init    (void);
bool button_State   (void);
void PinInitA       (PORT_OE_TypeDef mode, uint16_t pin);

int main()
{   
    uint8_t counter = 0, symbol_tx[8], symbol_rx[8], numbBit = 0, tempValue = 255;
    //clk_CoreConfig(RST_CLK_CPU_PLLsrcHSEdiv1, RST_CLK_CPU_PLLmul10);
    button_Init();
    PinInitA(PORT_OE_OUT, TXPin);
    PinInitA(PORT_OE_IN, RXPin);
    PinInitA(PORT_OE_OUT, StrobePin1);
    PinInitA(PORT_OE_IN, StrobePin2);
    
    while(1) {
        
        
        if (PORT_ReadInputDataBit(MDR_PORTA, StrobePin2)) {
            ClearSymbol(symbol_rx);
            ReceiveSymbol(symbol_rx);
            tempValue = MorzeToChar(symbol_rx);
            tempValue == 255 ? printf("Symbol is undefined! \n") : printf("Char: %c \n", tempValue);
        }
        // Read button
        while (!button_State()) {
            counter++;
            Delay(500);
            if (counter == 4) printf("DEBUG INFO: Completed char! \n");
        }
        // Define sign
        if (counter > 0) {
            if (counter == 1) {
                symbol_tx[numbBit] = '.';
                numbBit++;
                printf("DEBUG INFO: %s \n", symbol_tx);
            }
            else if (counter < 4) {
                symbol_tx[numbBit] = '-';
                numbBit++;
                printf("DEBUG INFO: %s \n", symbol_tx);
            }
            else {
                 for (numbBit; numbBit < 8; ++numbBit)
                    symbol_tx[numbBit] = 'x';
            }
            // If end symbol
            if (numbBit == 8) {
                numbBit = 0;
                TransmitSymbol(symbol_tx);
                tempValue = MorzeToChar(symbol_tx);
                tempValue == 255 ? printf("Symbol is undefined! \n") : printf("Char: %c \n", tempValue);
            }
    }
        
        if (counter != 0) {
            //printf("numbSymb: %d \n", numbBit);
        }
        counter = 0;
        
    }
}

void PinInitA(PORT_OE_TypeDef mode, uint16_t pin)
{
    PORT_InitTypeDef PORT_InitStructure;
    PORT_InitStructure.PORT_OE = mode;
    PORT_InitStructure.PORT_FUNC = PORT_FUNC_PORT;
    PORT_InitStructure.PORT_MODE = PORT_MODE_DIGITAL;
    PORT_InitStructure.PORT_SPEED = PORT_SPEED_SLOW;
    PORT_InitStructure.PORT_Pin = (pin);
    PORT_Init(MDR_PORTA, &PORT_InitStructure);
}

void clk_CoreConfig(uint32_t div, uint32_t mul) {
 //Реинициализация настроек тактирования
 //RST_CLK_DeInit();
 //Включение тактирования от внешнего источника HSE (High Speed External)
 RST_CLK_HSEconfig(RST_CLK_HSE_ON);
 //Проверка статуса HSE
 if (RST_CLK_HSEstatus() == ERROR) while (1);
 //Настройка делителя/умножителя частоты CPU_PLL(фазовая подстройка частоты)
 RST_CLK_CPU_PLLconfig(div, mul);
 //Включение CPU_PLL
 RST_CLK_CPU_PLLcmd(ENABLE);
 //Проверка статуса CPU_PLL
 if (RST_CLK_CPU_PLLstatus() == ERROR) while (1);
 //Коммутация выхода CPU_PLL на вход CPU_C3
 RST_CLK_CPU_PLLuse(ENABLE);
 //Выбор источника тактирования ядра процессора
 RST_CLK_CPUclkSelection(RST_CLK_CPUclkCPU_C3);
 //Подача тактовой частоты на PORTC, PORTD
 RST_CLK_PCLKcmd(RST_CLK_PCLK_PORTC, ENABLE);
 RST_CLK_PCLKcmd(RST_CLK_PCLK_PORTD, ENABLE);
} 

void button_Init(void) {
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
bool button_State(void) {
    return PORT_ReadInputDataBit(MDR_PORTD, PORT_Pin_5);
} 