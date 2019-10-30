/*******************************************************************************
*                   : TUSUR
* File              : morze.cpp
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
#include "morze.h"

uint8_t arrayOfMorzeSymbols[] = {'.', 'x', 'x', 'x', 'x', 'x', 'x', 'x',  // E 0
                                 '-', 'x', 'x', 'x', 'x', 'x', 'x', 'x',  // T 1
                                 '.', '.', 'x', 'x', 'x', 'x', 'x', 'x',  // I 2
                                 '-', '-', 'x', 'x', 'x', 'x', 'x', 'x',  // M 3
                                 '.', '.', '.', 'x', 'x', 'x', 'x', 'x',  // S 4
                                 '-', '-', '-', 'x', 'x', 'x', 'x', 'x',  // O 5
                                 '.', '.', '.', '.', 'x', 'x', 'x', 'x',  // H 6
                                 '-', '.', 'x', 'x', 'x', 'x', 'x', 'x',  // N 7
                                 '.', '-', 'x', 'x', 'x', 'x', 'x', 'x',  // A 8
                                 '-', '-', '.', 'x', 'x', 'x', 'x', 'x',  // G 9
                                 '.', '.', '-', 'x', 'x', 'x', 'x', 'x',  // U 10
                                 '-', '-', '.', '.', 'x', 'x', 'x', 'x',  // Z 11
                                 '.', '.', '.', '-', 'x', 'x', 'x', 'x',  // V 12
                                 '-', '-', '.', '-', 'x', 'x', 'x', 'x',  // Q 13
                                 '.', '-', '-', 'x', 'x', 'x', 'x', 'x',  // W 14
                                 '-', '.', '.', 'x', 'x', 'x', 'x', 'x',  // D 15
                                 '.', '-', '-', '-', 'x', 'x', 'x', 'x',  // J 16
                                 '-', '.', '.', '.', 'x', 'x', 'x', 'x',  // B 17
                                 '.', '-', '.', 'x', 'x', 'x', 'x', 'x',  // R 18
                                 '-', '.', '-', 'x', 'x', 'x', 'x', 'x',  // K 19
                                 '.', '-', '.', '.', 'x', 'x', 'x', 'x',  // L 20
                                 '-', '.', '-', '.', 'x', 'x', 'x', 'x',  // C 21
                                 '.', '.', '-', '.', 'x', 'x', 'x', 'x',  // F 22
                                 '-', '.', '-', '-', 'x', 'x', 'x', 'x',  // Y 23
                                 '.', '-', '-', '.', 'x', 'x', 'x', 'x',  // P 24
                                 '-', '.', '.', '-', 'x', 'x', 'x', 'x',  // X 25
                                 '.', '-', '-', '-', '-', 'x', 'x', 'x',  // 1 26
                                 '.', '.', '-', '-', '-', 'x', 'x', 'x',  // 2 27
                                 '.', '.', '.', '-', '-', 'x', 'x', 'x',  // 3 28
                                 '.', '.', '.', '.', '-', 'x', 'x', 'x',  // 4 29
                                 '.', '.', '.', '.', '.', 'x', 'x', 'x',  // 5 30
                                 '-', '.', '.', '.', '.', 'x', 'x', 'x',  // 6 31
                                 '-', '-', '.', '.', '.', 'x', 'x', 'x',  // 7 32
                                 '-', '-', '-', '.', '.', 'x', 'x', 'x',  // 8 33
                                 '-', '-', '-', '-', '.', 'x', 'x', 'x',  // 9 34
                                 '-', '-', '-', '-', '-', 'x', 'x', 'x',  // 0 35
                                 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x',  // SPACE 36 
                                 '-', '.', '.', '.', '.', '.', '.', 'x'   // ! 37  
};
uint8_t arrayOfSymbols[] = {'E', 'T', 'I', 'M', 'S', 'O', 'H', 'N',
                            'A', 'G', 'U', 'Z', 'V', 'Q', 'W', 'D',
                            'J', 'B', 'R', 'K', 'L', 'C', 'F', 'Y', 
                            'P', 'X', '1', '2', '3', '4', '5', '6', 
                            '7', '8', '9', '0', ' ', '!'
};

uint8_t MorzeToChar (uint8_t *symb) {
    bool flagCheckSymbol = false;
    uint8_t numbSymb = 255;
    uint8_t sizeArray = sizeof(arrayOfSymbols)/sizeof(uint8_t);
    for (uint8_t i = 0; i < sizeArray; ++i) {
        flagCheckSymbol = false;
        for (uint8_t j = 0; j < 8; ++j) {
            if (symb[j] == arrayOfMorzeSymbols[j+(i*8)])
                flagCheckSymbol = true;
            else {
                flagCheckSymbol = false;
                break;
            }
        } 
        if (flagCheckSymbol == true) {
            
            numbSymb = i;
            break;
        }
    }
    
    ClearSymbol(symb);
    
    if (numbSymb != 255) {
        for (uint8_t i = 0; i < sizeArray; ++i)
        {
            if (i == numbSymb) return arrayOfSymbols[i];
        }
    }
    else return 255;
}

void ClearSymbol(uint8_t *symb) {
    for (uint8_t i = 0; i < 8; ++i)
        symb[i] = 'x';
}


