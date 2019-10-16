#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "mstn_clk.h"
#include "MDR32F9Qx_port.h"
#include "MDR32F9Qx_rst_clk.h"

#define BitBandAliasBase 0x42000000
#define PORTC 0xB8000
#define FUNC 0x08


int32_t Get_bit_word_addr(int32_t byte_offset, int32_t bit_number) {
    int32_t bit_word_offset = (byte_offset*32) + (bit_number*4);
    int32_t bit_word_addr = BitBandAliasBase + bit_word_offset;
    
    return bit_word_addr;
}

void set_bit(int32_t byte_offset, int32_t bit_number) {
  *((volatile unsigned long *)(Get_bit_word_addr(byte_offset, bit_number))) = 1;
}

void reset_bit(int32_t byte_offset, int32_t bit_number) {
  *((volatile unsigned long *)(Get_bit_word_addr(byte_offset, bit_number))) = 0;
}

int main(int argc, char *argv[])
{
    
    PORT_InitTypeDef PortCInit; 
 
    PortCInit.PORT_Pin = PORT_Pin_2; 
    PortCInit.PORT_OE = PORT_OE_OUT; 
    PortCInit.PORT_FUNC = PORT_FUNC_PORT; 
    PortCInit.PORT_MODE = PORT_MODE_DIGITAL; 
 
    PORT_Init(MDR_PORTC, &PortCInit);
 
    
    int32_t byte_func = PORTC;
    printf("Hello World!\n");
    
    while(1)
    {
        set_bit(byte_func, 2); //PORTC0 MODE[1:0] = 01 
        Delay(1000);
        printf("Set bit \n");
        reset_bit(byte_func, 2); //PORTC0 MODE[1:0] = 00
        Delay(1000);
    }
    
    return EXIT_SUCCESS;
}
