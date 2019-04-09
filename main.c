/*******************************************************************************
*                   : TUSUR
* File              : main.c
* Compiler          : IAR for ARM 
* Version           : 6.30.1.3142
* Last modified     : 08.04.2019
* 
* Author            : Mazurok Oleg
* Support mail      : dev.humwer@gmail.com
* 
*
* Target MCU        : MCU: MDR1986
* Description       : Work with bits
*
********************************************************************************/

#define REG0_ADDR 0x20000000
#define REG0 *((volatile insigned long *) (REG0_ADDR))

void set_bit(int bit_num) {
  *((volatile unsigned long *)(REG0_ADDR + 0x2000000 + bit_num)) = 1;
}

void reset_bit(int bit_num) {
  *((volatile unsigned long *)(REG0_ADDR + 0x2000000 + bit_num)) = 0;
}

struct bitField{
  char flag_a : 1; char flag_b : 1;
  char flag_c : 1; char flag_d : 1;
  char flag_e : 1; char flag_f : 1;
  char flag_g : 1; char flag_h : 1;
} _bitField;

static char bait = 4;

void main(void){
  // Work with Bit Field
  _bitField.flag_a = 1;
  _bitField.flag_a = 0;
  // Work with Bit Banding
  set_bit(0);
  reset_bit(0);
  // Handwork with bits
  
  bait |= (1<<0); // set 1 for 0th bit
  bait &=~(1<<0); // set 0 for 0th bit
  
  bait ^= (1<<0); // (Now, bit 0th = 0) inversion 
  bait ^= (1<<0); // (Now, bit 0th = 1) inversion 
}

