 //*******************************************************************************
//*
//* Copyright (C) 2019 TUSUR, FB, Lysykh Alexey
//*
//* File              : main.c
//* Compiler          : IAR EWB IDE
//* Version           : 1.0
//* Created File      : 07.06.2019
//* Last modified     : 07.06.2019
//*
//* Support mail      : lexa1597@gmail.com
//* Target MCU        : MCU: Milandr 1986BE9x
//*
//* Description       : Work with  stack
//*
//********************************************************************************
/*
CODE_SELECTION:
0 - Command stack overflow PUSH
1 - Write constant to register R13
2 - Summation register R13 with R1
3 - Recursion stack overflow
4 - Passing function parameters through the stack
5 - Alternate stack
*/
#define CODE_SELECTION 0 

int recursion(void)
{
  return recursion();
}

int send_params(int a, int b, int c, int d, int e, int f, int g)
{
  return (a+b+c+d+e+f+g);    
}

void main()
{
  #if CODE_SELECTION == 0 
    while(1) //(Warning)
    {
      __asm("PUSH {R1}");
    }
  #elif CODE_SELECTION == 1
    __asm( "MOV R13, #10"); // R13 = 10 (ERROR)
  #elif CODE_SELECTION == 2
    __asm( "MOV R1, #8888\n" "ADD R13, R1"); // R1 = 8888, R13=(R1+R13) (WARNING)
  #elif CODE_SELECTION == 3
    recursion();
  #elif CODE_SELECTION == 4
    int sum = send_params(0x1,0x2,0x3,0x4,0x5,0x6,0x7); // Stack params
  #elif CODE_SELECTION == 5
    __asm( "MOV R0, #0x2\n" "MSR CONTROL, R0"); // CONTROL
  #endif
    
  return;
}