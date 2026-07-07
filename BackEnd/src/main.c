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


    printf("\n1. Press (1) to insert the weapon in the database");
    printf("\n2. Press (2) to remove a weapon [ I will need the name :) ]");
    printf("\n3. Press (3) to view a weapon/s chosed by u");
    printf("\n4. Press (4) to receive a complete report");
    printf("\n0. Press (0) to exit");

    printf("\n--> Put here your choice: ");
    scanf("%d", choice);
    getchar();

    return;
}
