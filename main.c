#include <stdlib.h>
#include <stdio.h>
#include "mstn_usb.h"

typedef struct _person {
    char *name;
    int num: 5;
} person;

void sort(person *list, int n) {
    int new_num;
    for(int i = 0; i < n; i++) {
        do {
           new_num = rand()%n;
        } while(list[new_num].num != -1);
        list[new_num].num = new_num;
        printf("%s\n", list[new_num].name);
    }
}

int main(int argc, char *argv[]) {
    while (USB_GetStatus() != PERMITTED);
    const int _735_len = 20;
    person _735_list[] = {
       {"1. Baranov Dmitriy", -1},
       {"2. ========================", -1},
       {"3. Gaifulina Anastasia", -1},
       {"4. Goncharova Anzhelika", -1},
       {"5. Dyhova Anna", -1},
       {"6. ========================", -1},
       {"7. Zaytsev Mikhail Olegovich", -1},
       {"8. ========================", -1},
       {"9. Koryshev Nikolay Pavlovich ", -1},
       {"10. ========================", -1},
       {"11. ========================", -1},
       {"12. Mazurok Oleg Olegovich ", -1},
       {"13. Mironov Danila", -1},
       {"14. Osipov Daniil Andreevich", -1},
       {"15. ========================", -1},
       {"16. ========================", -1},
       {"17. ========================", -1},
       {"18. ========================", -1},
       {"19. ========================", -1},
       {"20. Fedorov Evgeniy Andreevich", -1},
   };
   sort(_735_list, _735_len);
   printf("sizeof = %d\n", sizeof(person));
   return EXIT_SUCCESS;
}
