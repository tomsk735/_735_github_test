 //*******************************************************************************
//*
//* Copyright (C) 2019 TUSUR, FB, Lysykh Alexey
//*
//* File              : main.c
//* Compiler          : IAR EWB IDE
//* Version           : 1.0
//* Created File      : 07.06.2019
//* Last modified     : 07.06.2019
//*
//* Support mail      : lexa1597@gmail.com
//* Target MCU        : MCU: Milandr 1986BE9x
//*
//* Description       : Work with bit
//*
//********************************************************************************
#define REG0_ADDR 0x20000000
#define REG0 *((volatile unsigned long *) (REG0_ADDR))

void set_bit(int bit_num) {
  *((volatile unsigned long *)(REG0_ADDR + 0x2000000 + bit_num*4)) = 1;
}

void reset_bit(int bit_num) {
  *((volatile unsigned long *)(REG0_ADDR + 0x2000000 + bit_num*4)) = 0;
}

static char bait = 0;

struct bitField{
  char flag_a : 1; char flag_b : 1;
  char flag_c : 1; char flag_d : 1;
  char flag_e : 1; char flag_f : 1;
  char flag_g : 1; char flag_h : 1;
} _bitField;

void main(void){
  // Work with Bit Field
  _bitField.flag_d = 1; _bitField.flag_b = 1;// set 10 to field
  _bitField.flag_d = 0; _bitField.flag_b = 0;// reset to 0
  // Work with Bit Banding
  set_bit(1); // Set 10th bit
  set_bit(3); // Set 10th bit
  reset_bit(1); // Reset 10th bit
  reset_bit(3); // Reset 10th bit
  // Handwork with bits
  bait |= (1<<1); bait |= (1<<3); // set 10 to var «bait»
  bait &=~(1<<1); bait &=~(1<<3);// reset var «bait» to 0
}