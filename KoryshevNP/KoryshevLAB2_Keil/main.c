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

//If you want to choose one version of program, change number of VERSION
#define VERSION1

#ifdef VERSION2
int function1(int a, int b, int c, int d, int e, int f) {
	return (a+b+c+d+e+f);
}

int main(void){
  int sum = function1(1,2,3,4,5,6);
  return 0;
}
#endif

#ifdef VERSION1
int function1() {
	function1();
}

int main(void){
  function1();
  return 0;
}
#endif
