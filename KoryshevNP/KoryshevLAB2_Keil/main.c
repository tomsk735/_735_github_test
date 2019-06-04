 /*******************************************************************************
*                   : TUSUR
* File              : main.c
* Compiler          : Armcc.exe V5.06
* Version           : 5.27
* Last modified     : 04.06.2019
* 
* Author            : Koryshev Nikolay
* Support mail      : koryshev1997@gmail.com
* 
*
* Target MCU        : MCU: MDR1986
* Description       : Work with stack. 
* 
*
********************************************************************************/

#include <stdlib.h>
#include <stdio.h>
int function1(int a, int b, int c, int d, int e, int f) {
	return (a+b+c+d+e);
}

int main(void){
  int sum = function1(1,2,3,4,5,6);
  return 0;
}

/*void main(void) {
__asm (
	"MOV  R1, #9999\n"
	"ADD  SP, R1"
);
}*/
