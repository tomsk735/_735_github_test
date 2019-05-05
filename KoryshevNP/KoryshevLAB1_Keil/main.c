  /*******************************************************************************
*
* Copyright (C) 2019 MITUS Koryshev Nikolay
*
* File              : main.c
* Compiler          : Armcc.exe V5.06 update 6
* Version           : 5.27
* Created File      : 09.04.2019
* Last modified     : 05.05.2019
*
* Support mail      : koryshev1997@gmail.com
*
* Target MCU        : MCU: Milandr MDR1986BE9x
* Description       : Bitwise access to the data
*                   : 

* Hardware          : .sch .pcb
*
********************************************************************************/

#define REG0_ADDR 0x20000000
#define REG0 *((volatile unsigned long *) (REG0_ADDR))

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

static char bait = 4;

int main(void){
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
	return 0;	
}
