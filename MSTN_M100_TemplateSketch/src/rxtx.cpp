/*******************************************************************************
*                   : TUSUR
* File              : rxtx.cpp
* IDE               : Apache NetBeans
* Version           : 11.1
* Last modified     : 30.10.2019
* 
* Authors           : Zaitsev Michael, Koryshev Nikolay, Mazurok Oleg
* Support mail      : dev.humwer@gmail.com
* 
* Description       : Code Morze and work with GPIO
*
********************************************************************************/
#include "type_custom.h"
#include "rxtx.h"

void TransmitSymbol (uint8_t *symb) { 
 
    printf("Start transmit symbol...\n"); 
 
    PORT_SetBits(MDR_PORTA, StrobePin1); 
 
    for(uint8_t i = 0; i < 8; i++) { 
        if(symb[i] == '.') 
            PORT_SetBits(MDR_PORTA, TXPin); 
        else if(symb[i] == '-') 
            PORT_ResetBits(MDR_PORTA, TXPin); 
        else
            break;
        Delay(200); 
    } 
    PORT_ResetBits(MDR_PORTA, StrobePin1); 
    printf("End transmit symbol!\n"); 
    PORT_ResetBits(MDR_PORTA, TXPin);
}

void ReceiveSymbol(uint8_t *symb)
{
    printf("Start receive symbol!\n");
    
    uint8_t i = 0;
    
    while(PORT_ReadInputDataBit(MDR_PORTA, StrobePin2))
    {
        if(PORT_ReadInputDataBit(MDR_PORTA, RXPin) != 0) 
            symb[i] = '.';
        else 
            symb[i] = '-';
        i++;
        Delay(200);
    }
    printf("End receive symbol!\n");
    printf("Sign: %s \n", symb);
}


