/*******************************************************************************
*                   : TUSUR
* File              : main_5.c
* Compiler          : IAR for ARM 
* Version           : 6.30.1.3142
* Last modified     : 23.04.2019
* 
* Author            : Zaytsev Mikhail
* Support mail      : 735_zmo@fb.tusur.ru
* 
*
* Target MCU        : MCU: MDR1986
* Description       : Work with bits. Bit-Band. 
*
********************************************************************************/

#define REG0_ADDR 0x20000000
#define REG0 *((volatile insigned long *) (REG0_ADDR))

void set_bit(int bit_num) {
  *((volatile unsigned long *)(REG0_ADDR + 0x2000000 + bit_num*4)) = 1;
}

void reset_bit(int bit_num) {
  *((volatile unsigned long *)(REG0_ADDR + 0x2000000 + bit_num*4)) = 0;
}

struct bitField{
  char flag_a : 1; char flag_b : 1;
  char flag_c : 1; char flag_d : 1;
  char flag_e : 1; char flag_f : 1;
  char flag_g : 1; char flag_h : 1;
} _bitField;

static char byte = 4;

void main(void){
  
  //Bit Field
  _bitField.flag_a = 1;
  _bitField.flag_a = 0;
  
  //Bit Banding
  set_bit(8);
  reset_bit(8);
  
  // Handwork with bits
  byte |= (1<<0); // set 1 for 0th bit
  byte &=~(1<<0); // set 0 for 0th bit
  
}