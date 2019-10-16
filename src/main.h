#ifndef MAIN_H
#define MAIN_H

/**
 * Внимание! 
 * В состав стандартной библиотеки MSTN-M100 входят некоторые модули стандартной 
 * библиотеки MDR32F9Qx, распространяемой компанией Миландр (https://github.com/eldarkg/emdr1986x-std-per-lib).
 * Использована версия библиотек, актуальная на 04.10.2016.
 * Библиотека собрана с константой препроцессора "USE_MDR1986VE9x".
 * Уровень оптимизации -O2.
 * Список задействованных модулей библиотеки MDR32F9Qx:
 * MDR32F9Qx_adc
 * MDR32F9Qx_bkp
 * MDR32F9Qx_comp
 * MDR32F9Qx_dac
 * MDR32F9Qx_eeprom
 * MDR32F9Qx_i2c
 * MDR32F9Qx_port
 * MDR32F9Qx_power
 * MDR32F9Qx_rst_clk
 * MDR32F9Qx_ssp
 * MDR32F9Qx_timer
 * MDR32F9Qx_uart
 * MDR32F9Qx_usb
 * 
 * Для конфигурации Таймера 1 предлагается использовать функции, определенные в модуле MDR32F9Qx_timer
 * (заг. файл C:\Intec\MSTN\M100\Inc\SPL_MDR\MDR32F9Qx_timer.h).
 * 
 * Приоритеты прерываний, используемые в библиотеке MSTNLib (0 - наивысший приоритет, 7 - наименьший):
 * SysTick_IRQ - приоритет 0
 * USB_IRQ - приоритет 1
 * UART_IRQ - приоритет 3
 * TIMER2_IRQ, TIMER3_IRQ - приоритет 3 (пользовательское прерывание, устанавливаемое функцией TMR2CH4_AttachInterrupt() модуля mstn_pwm
 *                           и внешние прерывания, устанавливаемые функцией EINT_AttachExtInt() модуля mstn_external_interrupt)
 * 
 * Категорически не рекомендуется изменять приоритеты прерываний USB_IRQ и SysTick_IRQ и устанавливать 
 * приоритеты других прерываний выше или равными приоритету прерывания USB_IRQ.
 * В противном случае корректная работа ПО, собранного на основе библиотеки MSTNLib, не гарантируется.
 */

#include "mstn_types.h"

extern const _MainArgs MAIN_ARGS_STATE = MAIN_ARGS_DISABLE;
extern const _StatesJp1 JP1_STATE = JP1_ADC;


#endif /* MAIN_H */

