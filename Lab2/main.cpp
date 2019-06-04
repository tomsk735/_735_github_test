/*******************************************************************************
*
* Copyright (C) 2019 TUSUR, FB, Zaytsev Mikhail
*
* File              : main.cpp
* Compiler          : IAR EWB IDE 6.30
* Version           : 1.0
* Created File      : 02.06.2019
* Last modified     : 04.06.2019
*
* Support mail      : mihail25.98@gmail.com
* Target MCU        : MCU: Milandr 1986BE9x
*
* Description       : Work with stack
*
********************************************************************************/

/*
CODE_SELECTION:
0 - Переполнение стека с помощью команды PUSH
1 - Запись константы в регистр R13
2 - Суммирование регистров R13 и R1
3 - Переполнение стека при помощи рекурсии
4 - Передача параметров функции через стек
5 - Переключение на альтернативный стек
*/
#define CODE_SELECTION 0 


int recursion(void){
  return recursion();
}

int send_params(int a, int b, int c, int d, int e, int f){
  return (a+b+c+d+e+f);    
}

void main()
{
  
  if(CODE_SELECTION == 0){
    while(1) //(Warning)
    {
      __asm(
            "PUSH {R1}"
            );
    }
  }
  
  if(CODE_SELECTION == 1){
    __asm( "MOV R13, #10"); // R13 = 10 (ERROR)
  }
  
  if(CODE_SELECTION == 2){
    __asm( "MOV R1, #8888\n" "ADD R13, R1"); // R1 = 8888, R13=(R1+R13) (WARNING)
  }
  
  if(CODE_SELECTION == 3){
    recursion();
  }
  
  if(CODE_SELECTION == 4){
    int sum = send_params(0x1,0x2,0x3,0x4,0x5,0x6); // Stack params
  }
    
  if(CODE_SELECTION == 5){
    __asm( "MOV R0, #0x2\n" "MSR CONTROL, R0"); // CONTROL
  }
    
  return;
}
