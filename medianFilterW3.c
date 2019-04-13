/*******************************************************************************
*  TUSUR
* File              : medianFilterW3.c
* Compiler          : IAR for ARM 
* Version           : 6.30.1.3142
* Last modified     : 13.04.2019
*
* Support mail      : nsp@fb.tusur.ru ( Nediak S.P.)
*
* Target MCU        : MCU: MDR1986
*
* Description       : Median filter with 3 points window
*                   :
*******************************************************************************/
int medianWz3(int a, int b, int c); // returns median of { a, b, c} 
//------------------------------------------------------------------------------
int medianFilter( int outArray[],  // filtered array    (output)
		  int inArray[],   // source  array      (input)
		  int ArraySize )  // size of the array  (input)
{
    int //err = 0,
        i;           // working variable
    // test for parameters correct          TODO
    
    //ini (copy) boundary members of outArray
    outArray[ 0 ]             = inArray[ 0 ];
    outArray[ ArraySize - 1 ] = inArray[ ArraySize - 1 ];
    
    // main filter loop
    for( i = 1; i < ArraySize - 1; i++ ) 
     
      outArray[ i ] = medianWz3( inArray[ i - 1 ], inArray[ i ], inArray[ i + 1] );
    
    return 0;  // return err;          TODO
}//medianFilter
//------------------------------------------------------------------------------
int medianWz3(int a, int b, int c) // returns median of { a, b, c}
{
    int z;
    
    if( b < a ){ // then exchange a and b
      z = a;
      a = b;
      b = z;
    }// if
    
    // look for median of a, b, c
    if ( c <= a) return a;
    
    if ( b <= c) return b;
    
    return c;
    
}// medianWz3()