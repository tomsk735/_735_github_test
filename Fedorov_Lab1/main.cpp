 /*******************************************************************************
*                   : TUSUR
* File              : main.c
* Compiler          : Armcc.exe V5.06
* Version           : 5.27
* Last modified     : 27.05.2019
* 
* Author            : Eugene Fedorov
* Support mail      : ...@mail.ru
* 
*
* Target MCU        : MCU: MDR1986
* Description       : Bit-Band
* 
* Individual number	: 20
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


struct byte {
    unsigned a0: 1;
    unsigned a1: 1;
    unsigned a2: 1;
    unsigned a3: 1;
    unsigned a4: 1;
    unsigned a5: 1;
    unsigned a6: 1;
    unsigned a7: 1;
};
 
union Byte {
    unsigned char value;
    struct byte bitfield;
};
 
static char byte = 0;

int main(void){
  //Bit Field
	  union Byte x;
    x.value = 20; 
	 x.value = 0;
	
  //Bit Banding
  set_bit(2);
  set_bit(4);
  reset_bit(2);
  reset_bit(4);
  
  // Handwork with bits
  byte |= (1<<2); // set 4
	byte |= (1<<4); // set 16
  byte &=~(1<<2); 
	byte &=~(1<<4); // reset to 0
  return 0;
}
