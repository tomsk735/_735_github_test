/*******************************************************************************
*                   : TUSUR
* File              : main.c
* Compiler          : IAR for ARM 
* Version           : 6.30.1.3142
* Last modified     : 03.06.2019
* 
* Author            : Mazurok Oleg
* Support mail      : dev.humwer@gmail.com
* 
* Description       : Work with stack
*
********************************************************************************/

int func(void)
{
  return func();
}

int func2(int a[5])
{
  return (a[0]+a[1]+a[2]+a[3]+a[4]);
}

int func3(int a, int b, int c, int d, int e, int f)
{
  return (a+b+c+d+e+f);    
}

void main(void)
{
  
  //func(); // Отвечает за рекурсивный вызов функции без условия выхода
  
  //__asm( "MOV R13, #10"); // Попытка напрямую записать значение в SP
  
  //__asm( "MOV R1, #9999\n" "ADD R1, R1"); // Изменение значения в SP
  
  //int sum = func3(16,32,48,64,80,96); // Передача параметров в функцию
  
  /*
  int array[5] = {1,2,3,4,5}; // Передача массива в функцию
  func2(array);
  */
  
  //__asm( "MOV R0, #0x2\n" "MSR CONTROL, R0"); // Переключение указателя стека
}

