/*******************************************************************************
*  TUSUR
* File              : main_5.c                 // Modify 04.04.2019
* Compiler          : IAR for ARM 
* Version           : 6.30.1.3142
* Last modified     : 28.03.2019
*
* Support mail      : nsp@fb.tusur.ru ( Nediak S.P.)
*
* Target MCU        : MCU: MDR1986
* Description       : Program for create 
*                   : random list of 735 group
*                   : with absent or not. See _735_Names5.h    
********************************************************************************/


#include <stdlib.h>     // for rand()
#include <time.h>
#include <stdio.h>      // for FILE
#include <string.h>

//##################### editing block ##########################################
#include "_735_Names5.h"

#define _735_MEMBER       21 
#define microGroupMembers 4
//##################### The end of editing block ###############################

// Global variables
 int randArray[_735_MEMBER];       // random number from 0 to 19

 FILE *outFile;
 
 int _735_members;                 // number of members who are present
 
//-----------------------------------------------------------------------
 void calculateMembers(void){
   int i;
   
   _735_members = 0;
   
   for (i = 0; i < _735_MEMBER; i++){
     if ( ' ' == _735_List[ i ][ 3 ] )
       _735_members++;
   }//i
 }//calculateMembers
 
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
   j = 0;                                                           // 28.03.19
   while( j <   _735_MEMBER ){     //    while(1) - bad code, it may be hang 
     
     randN = rand(  ) % _735_MEMBER;
     
     if( ' ' == _735_List[ randN ][ 3 ] ){
       fprintSTR( randN );                    // print one string from 735 list
       GroupMembers--;
       i = 0; 
       randArray[ i ] = randN;
       i++;
       break;
     }// if _ else
     
     j++;
   }//  while( i <   _735_MEMBER )                                   // 28.03.19
   
   // loop for list create
   //while( i <  _735_MEMBER ){                                      // 26.03.19
   while( i <  _735_members ){                                       // 26.03.19 
     
     randN = rand(  ) % _735_MEMBER;
     
     if ( ' ' != _735_List[ randN ][ 3 ] )                           // 26.03.19 
        goto NEXT_ITER;
     
     for ( j = 0; j < i; j++){
      if ( randArray[ j ] == randN ) 
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
  
  int errorCode = 0,
      iseconds;
  //char str__TIME__[10];
  // Open file for random list
   outFile = fopen("$PROJ_DIR$\\_735_randList5.txt", "w");
     
   if( NULL == outFile ){
      errorCode = __LINE__;
      goto EXIT;
   }// if( NULL == outFile )  
   
   fprintf(outFile, "   %s  %s\n\n", __DATE__, __TIME__ );

// rand() initialization
//   strcpy(str__TIME__, __TIME__);
//   iseconds =  ( (str__TIME__[6] & 0x0f) << 4 ) + (str__TIME__[7] & 0x0f);
   iseconds =  ( (__TIME__[6] & 0x0f) << 4 ) + (__TIME__[7] & 0x0f);
   srand( iseconds );
   //srand(735);                                                   // 26.03.2019
   
   calculateMembers();  // who are present
    
   errorCode = createRandList(randArray,_735_MEMBER );     // 
  
EXIT: 
  errorCode = errorCode;     // to remove warnings
  fclose(outFile);
  
  while(1){
  }//while(1)

}// main