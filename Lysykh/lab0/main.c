 //*******************************************************************************
//*
//* Copyright (C) 2019 TUSUR, FB, Lysykh Alexey
//*
//* File              : main.c
//* Compiler          : IAR EWB IDE
//* Version           : 1.0
//* Created File      : 03.06.2019
//* Last modified     : 03.06.2019
//*
//* Support mail      : lexa1597@gmail.com
//* Target MCU        : MCU: Milandr 1986BE9x
//*
//* Description       : BCD to Ascii
//*
//********************************************************************************
#include <stdio.h>

char main ()
{
  unsigned char res;
  unsigned char s1;
  unsigned char s2;
  unsigned char bcd; 	
  printf("Vvedite chislo ot 0 do 99:\n");
  scanf("%hhx",&bcd);
  unsigned char c=bcd&0xf0; 
  if(c<0x10) 
    {	
      res=(bcd | 0x30); 		
      printf("%d",res); 	
    }
  else	
    {		
      s1=bcd;		
      s2=bcd;	
      s2=(s2&0x0f);	
      s2=(s2 | 0x30); 		
      s1=(s1>>4); 		
      s1=(s1 | 0x030); 
      printf("Ascii in Dec:%d %d\n",s1,s2);	
      printf("Ascii in Hex:%hhx %hhx",s1,s2);
    }
  return 0;
}
