#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include "mstn_usb.h"

#define REG0_ADDR 0x20000000
#define REG0 *((volatile unsigned long *) (REG0_ADDR))

void set_bit(int bit_num) {
    *((volatile unsigned long *)(REG0_ADDR + 0x2000000 + (bit_num<<2))) = 1;
};

int get_bit(int bit_num) {
    return *((volatile unsigned long *)(REG0_ADDR + 0x2000000 + (bit_num<<2)));
};

void sort(char **list, int n) {
    REG0 = 0;
    int new_num;
    for(int register i = 0; i < n; i++) {
        do {
           new_num = rand()%n;
        } while(get_bit(new_num));
        set_bit(new_num);
        printf("%s\n", list[new_num]);
    }
}

int main(int argc, char *argv[]) {
    while (USB_GetStatus() != PERMITTED);
    
    const int _735_len = 20;
    char* _735_list[] = {
       "1. Baranov Dmitriy",
       "2. ========================",
       "3. Gaifulina Anastasia",
       "4. Goncharova Anzhelika",
       "5. Dyhova Anna",
       "6. ========================",
       "7. Zaytsev Mikhail Olegovich",
       "8. ========================",
       "9. Koryshev Nikolay Pavlovich ",
       "10. ========================",
       "11. ========================",
       "12. Mazurok Oleg Olegovich ",
       "13. Mironov Danila",
       "14. Osipov Daniil Andreevich",
       "15. ========================",
       "16. ========================",
       "17. ========================",
       "18. ========================",
       "19. ========================",
       "20. Fedorov Evgeniy Andreevich",
   };
    
   sort(_735_list, _735_len);
   return EXIT_SUCCESS;
}
