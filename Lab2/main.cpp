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

int recursion(void){
  return recursion();
}

int send_params(int a, int b, int c, int d, int e, int f){
  return (a+b+c+d+e+f);    
}

void main()
{
  
  //int sum = send_params(0x1,0x2,0x3,0x4,0x5,0x6); // Stack params
  
  //recursion();
    
  //__asm( "MOV R1, #8888\n" "ADD R13, R1"); // R1 = 8888, R13=(R1+R13) (WARNING)
  
  //__asm( "MOV R13, #10"); // R13 = 10 (ERROR)
  
  __asm( "MOV R0, #0x2\n" "MSR CONTROL, R0"); // CONTROL
  
  /*
  while(1) //(Warning)
  {
    __asm(
          "PUSH {R1}"
          );
  }
  */
  return;
}






