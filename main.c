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
* On based          : github.com/tomsk735/_735_github_test/tree/samoylova
*
* Target MCU        : MCU: MDR1986
* Description       : Modified program for create random list of 735 group
*
********************************************************************************/


#include <stdlib.h>     // for rand()
#include <stdio.h>      // for FILE

static volatile unsigned sizeMG = 2; // Size of MicroGroups
const unsigned sizeG = 20; // Size of Group
FILE *randList;

typedef struct Person
{
  char* fullName; // Full Name of Person
  unsigned Was : 1; // If has been
  unsigned None : 1; // If absent - 0, present - 1
} infoPerson;

infoPerson Group735[] = { // List of Groups
  {"1. Baranov Dmitry", 0, 1}, {"2. Borisova Catherine", 0, 1},
  {"3. Gaifulina Anastasia", 0, 1}, {"4. Goncharova Angelica", 0, 1},
  {"5. Dykhova Anna", 0, 1}, {"6. Zabaturina Irina", 0, 1},
  {"7. Zaitsev Mikhail", 0, 1}, {"8. Koryshev Nikolay ", 0, 1},
  {"9. Kurtova Marina", 0, 1}, {"10. Latypov Nail", 0, 0},
  {"11. Lysyh Alexey", 0, 0}, {"12. Mazurok Oleg", 0, 1}, 
  {"13. Mironov Danila", 0, 1}, {"14. Osipov Daniil", 0, 1}, 
  {"15. Popova Daryana", 0, 1}, {"16. Saryglar Saikho", 0, 1}, 
  {"17. Saryglar Chechena", 0, 1}, {"18. Tatarenko Vladislav", 0, 1},
  {"19. Terekhin Alexander", 0, 1}, {"20. Fedorov Evgeny", 0, 1},
};

void sort(infoPerson *MG, int size){ // Grouping
  int randNum, i, tempVar = 0; // Random Number, Counter Cycle, Temp var
  char *tempFullName; // Temporary save full name of previous person
  randList = fopen("$PROJ_DIR$\\735_randList.txt", "w"); // Write to file
  for (i = 0; i < size; i++) {
    randNum = rand()%size; // Random number from 0 to (size-1)
    if (MG[randNum].Was == 1 || MG[randNum].None == 0) { // If Was or None
      i--; continue;
    }
    else
    {
      tempVar++;
      if (tempVar == sizeMG) { // If micro group is full
        tempVar = 0;
        Group735[randNum].Was = 1;
        fprintf(randList, "Micro group: %s and %s \n", 
                tempFullName, Group735[randNum].fullName);
      }
      Group735[randNum].Was = 1;
      tempFullName = Group735[randNum].fullName;
    }
  }
  fclose(randList);
}

void main(void){
  sort(Group735, sizeG);
}

