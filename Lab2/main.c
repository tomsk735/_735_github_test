/*******************************************************************************
*                   : TUSUR
* File              : main.c
* Compiler          : IAR for ARM 
* Version           : 6.30.1.3142
* Last modified     : 04.06.2019
* 
* Author            : Mazurok Oleg
* Support mail      : dev.humwer@gmail.com
* 
* Description       : Work with stack
*
********************************************************************************/
// For run to needed code, you must uncomment needed #define
//#define RECURSIVEFUNC
//#define CHANGESP
//#define ADDSP
//#define ARRAYTOFUNC
//#define PARAMSTOFUNC
//#define TURNSP
  
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
  #ifdef RECURSIVEFUNC
  {
    func(); // Recursive function (WARNING)
  }
  #endif
  #ifdef CHANGESP
  {
    __asm( "MOV R13, #10"); // R13 = 10 (ERROR)
  }
  #endif
  #ifdef ADDSP
  {
    __asm( "MOV R1, #9999\n" "ADD R1, R1"); // R1 = 9999, R13=(R1+R13) (WARNING)
  }
  #endif
  #ifdef ARRAYTOFUNC
  {
    int sum = func3(16,32,48,64,80,96); // Stack params
  }
  #endif
  #ifdef PARAMSTOFUNC
  {
    int array[5] = {1,2,3,4,5}; // Stack params
    func2(array);
  }
  #endif
  #ifdef TURNSP
  {
    __asm( "MOV R0, #0x2\n" "MSR CONTROL, R0"); // Two stack pointer
  }
  #endif
}

