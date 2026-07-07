#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adt_list.h"
#include "repository.h"
#include "weapon.h"
#include "UI.h"
#include "helper.h"

void main_Hub(int* choice);

int main(){

    int choice = 0;
    list L = initList();

    loadDataBase(&L);

    do{

        clearScreen();

        choice = 0;

        main_Hub(&choice);

            switch(choice)
            {
        
                case 1: 

                    putInWeapon(&L);
                    break;

                case 2: 

                    deleteWeapon(&L);
                    break;

                case 3:

                    viewWeapon(&L);
                    break;

                case 4:

                    completeInformation(&L);
                    break;

                case 0:

                    printf("\nWait a moment...");
                    saveDataBase(&L);
                    printf("\nExit...");
                    break;

                default:
            
                printf("\nDAMN GOD!!! Press the right button FUCK YOU!");
            }

        if(choice != 0){
            printf("\nPress ENTER to continue...");
            getchar();
        }

    }while(choice != 0);




}

void main_Hub(int* choice){

    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                    ELDEN RING DATABASE                       ║\n");
    printf("╠═════╦════════════════════════════════════════════════════════╣\n");
    printf("║  1  ║ Insert Weapon                                          ║\n");
    printf("║  2  ║ Remove Weapon                                          ║\n");
    printf("║  3  ║ Search Weapon                                          ║\n");
    printf("║  4  ║ Complete Report                                        ║\n");
    printf("║  0  ║ Exit                                                   ║\n");
    printf("╚═════╩════════════════════════════════════════════════════════╝\n");
    printf("\nChoice > ");

    scanf("%d", choice);
    getchar();

    return;
}
