//Функция настройки тактовой частоты МК
#include "clk.h"
//Функция настройки тактовой частоты МК
void clk_CoreConfig(void)
{
    //Реинициализация настроек тактирования
    RST_CLK_DeInit();
    //Включение тактирования от внешнего источника HSE (High Speed External)
    RST_CLK_HSEconfig(RST_CLK_HSE_ON);
    //Проверка статуса HSE
    if (RST_CLK_HSEstatus() == ERROR) while (1);
    //Настройка делителя/умножителя частоты CPU_PLL(фазовая подстройка частоты)
    RST_CLK_CPU_PLLconfig(RST_CLK_CPU_PLLsrcHSEdiv1, RST_CLK_CPU_PLLmul4);
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


