/*******************************************************************************
*  TUSUR
* File              : main.c
* Compiler          : IAR for ARM 
* Version           : 6.30.1.3142
* Last modified     : 03.03.2019
*
* Support mail      : nsp@fb.tusur.ru ( Nediak S.P.)
*
* Target MCU        : MCU: MDR1986
* Description       : Program for create 
*                   : random list of 735 group
*
********************************************************************************/


#include <stdlib.h>     // for rand()
#include <stdio.h>      // for FILE

#include "_735_list.h"

#define _735_MEMBER       20 
#define microGroupMembers 2

// Global variables
 int randArray[_735_MEMBER];       // random number from 0 to 19

 FILE *outFile;
// ---------------------------------------------------------------------- 
void fprintSTR(int N_str){ // print one string of FIO 
     char ch,  // character for print
        *pCh;  // pointer
     
     // ini with first simbol
     pCh = & _735_List[ N_str ][ 0 ];   // pCh - address of first simbol of FIO
     ch  = *pCh;                         // ch - ASCII code of the simbol
       
       while ( ch ){
	 fprintf(outFile, "%c", ch ); 
	 pCh++;
	 ch = *pCh;
       } 
      fprintf(outFile, "\n");         // for new string in file 
}//fprintSTR
//------------------------------------------------------
int createRandList(int randArray[_735_MEMBER], int N ){
   int errorCode = 0,
       GroupMembers =  microGroupMembers,       // ini GroupMembers
       i, j, randN;
   
     
   // ini first random number
   randN = rand(  ) % _735_MEMBER;
   fprintSTR( randN );                // print one string from 735 list
   GroupMembers--;
   i = 0; 
   randArray[ i ] = randN;
   i++;
   
   // loop for list create
   while( i <  _735_MEMBER ){
     
     randN = rand(  ) % _735_MEMBER;
     
     for ( j = 0; j < i; j++){
      if ( randArray[ j ] == randN)
	goto NEXT_ITER;
     }// j
     // print FIO
     fprintSTR( randN );                // print one string from 735 list
     // print new string for group
     if( --GroupMembers == 0 ){
        fprintf(outFile, "\n");         // for new string in file 
	GroupMembers = microGroupMembers;
     }
     // remember new number 
     randArray[ i ] = randN;
     i++;
     
NEXT_ITER: i = i ; // for remove warning;     
   }// while( i <  _735_MEMBER )
   
   return errorCode;
}// readFile -----------------------------------------------

void main(void){
  int errorCode = 0;
  
  // Open file for random list
   outFile = fopen("$PROJ_DIR$\\_735_randList.txt", "w");
     
   if( NULL == outFile ){
      errorCode = __LINE__;
      goto EXIT;
   }// if( NULL == outFile )  
   
   fprintf(outFile, "   %s  %s\n\n", __DATE__, __TIME__ );
    
   errorCode = createRandList(randArray,_735_MEMBER );     // 
  
EXIT: 
  errorCode = errorCode;     // to remove warnings
  fclose(outFile);
  
  while(1){
  }//while(1)

}// main
