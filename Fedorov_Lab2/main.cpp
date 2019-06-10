/*******************************************************************************
*
* Copyright (C) 2019 TUSUR, FB, Fedorov Evgeniy
*
* File              : main.cpp
* Compiler          : IAR EWB IDE 8.32
* Version           : 1.0
* Created File      : 05.06.2019
* Last modified     : 09.06.2019
*
* Support mail      : ...@gmail.com
* Target MCU        : MCU: Milandr 1986BE9x
*
* Description       : Work with stack
*
********************************************************************************/

/*
PROGRAMM x
0 - перполнение с помощью рекурсии
1 - запись константы в R13
2 - суммирование регистров R13 и R1
3 - передача параметров функции через стек
4 - переключение на альтернативный стек
*/
#define PROGRAMM 4

int Func(void){
  return Func();
}

int Func1(int a, int b, int c, int d, int e, int f){
  return (a+b+c+d+e+f);    
}

void main()
{
  
#if PROGRAMM == 0 
    Func(); //Error
  
#elif PROGRAMM == 1
    __asm( "MOV R13, #10"); // Error R13 = 10
  
#elif PROGRAMM == 2
    __asm( "MOV R1, #8888\n" "ADD R13, R1"); // Warning R1 = 8888, R13=(R1+R13) 
  
#elif PROGRAMM == 3
   int sum = Func1(0x1,0x2,0x3,0x4,0x5,0x6); // Stack params
  
#elif PROGRAMM == 4
    __asm( "MOV R0, #0x2\n" "MSR CONTROL, R0"); // CONTROL    
    
#endif
    
}