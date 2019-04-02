#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include "mstn_usb.h"

typedef struct _person {
    char *name;
    unsigned is_printed: 1;
} person;

void sort(person *list, int n) {
    int new_num;
    for(int register i = 0; i < n; i++) {
        do {
           new_num = rand()%n;
        } while(list[new_num].is_printed);
        list[new_num].is_printed = 1;
        printf("%s\n", list[new_num].name);
    }
}

int main(int argc, char *argv[]) {
    while (USB_GetStatus() != PERMITTED);
    const int _735_len = 20;
    person _735_list[] = {
       {"1. Baranov Dmitriy", 0},
       {"2. ========================", 0},
       {"3. Gaifulina Anastasia", 0},
       {"4. Goncharova Anzhelika", 0},
       {"5. Dyhova Anna", 0},
       {"6. ========================", 0},
       {"7. Zaytsev Mikhail Olegovich", 0},
       {"8. ========================", 0},
       {"9. Koryshev Nikolay Pavlovich ", 0},
       {"10. ========================", 0},
       {"11. ========================", 0},
       {"12. Mazurok Oleg Olegovich ", 0},
       {"13. Mironov Danila", 0},
       {"14. Osipov Daniil Andreevich", 0},
       {"15. ========================", 0},
       {"16. ========================", 0},
       {"17. ========================", 0},
       {"18. ========================", 0},
       {"19. ========================", 0},
       {"20. Fedorov Evgeniy Andreevich", 0},
   };
   sort(_735_list, _735_len);
   printf("sizeof(person) = %d\n", sizeof(person));
   return EXIT_SUCCESS;
}
