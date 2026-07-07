#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adt_list.h"
#include "repository.h"
#include "weapon.h"
#include "helper.h"

void putInWeapon(list* L){
    
    char name[25], description[100], category[50], choice;
    int quantity;
    Weapon W;

    do{

        do{
            printf("\nPUT THE FUCKING NAME HERE (pls!): ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';

        }while(strlen(name) == 0);

        do{
            printf("\nPLEASE MY N**GA PUT SOMETHING ELSE: ");
            fgets(description, sizeof(description), stdin);
            description[strcspn(description, "\n")] = '\0';

        }while(strlen(description) == 0);

        choose_Category(category);

        quantity = 1;

        printf("\n=== WEAPON SUMMARY ===\n");
        printf("Name: %s\n", name);
        printf("Description: %s\n", description);
        printf("Category: %s\n", category);

        printf("\nInsert Weapon? (Y/N): ");
        scanf(" %c", &choice);
        getchar();

    }while(choice != 'Y' && choice != 'y');

    W = createWeapon(name, description, category, quantity);
    *L = insertWeapon(*L, W);

}

/*
*   
*FOR THE FUTURE ME
*remebmber to insert in the function putInWeapon the option
*yes or no for every section of the weapon, power up the 
*UI for every section, verify if the weapon the user is going
*to insert is already in, in that case search the weapon and 
*increase hi quantity
*P.S. ---BECOME PROFESSIONAL WITH THE PRINTF---
+
*/



void deleteWeapon(list* L){

    char name[30];

    if(L == NULL)
    {
        printf("\nTHERE ARE NO WEAPON WHAT A FUCKKKK!!!");
        return;        
    }

    do{
        printf("\nYOOOO PUT THE NAME HERE -> ");
        fgets(name, 30, stdin);
        name[strcspn(name, "\n")] = '\0';

    }while(strlen(name) == 0);

    removeWeapon(*L, name);

    printf("\nWEAPON CORRECTLY REMOVED");   
}

void viewWeapon(list* L){

    char name[30], category[50];
    int choice = 0;
    Weapon W;

    if(L == NULL)
    {
        printf("\nTHERE ARE NO WEAPON WHAT A FUCKKKK!!!");
        return;        
    }

    printf("\n1. Press (1) to search a weapon by name");
    printf("\n2. Press (2) to search a weapon by category");
    printf("\n0. Press (0) to exit");

    switch(choice){

        case 1: 

            do{
                printf("\nYOOOO PUT THE NAME HERE -> ");
                fgets(name, 30, stdin);
                name[strcspn(name, "\n")] = '\0';

            }while(strlen(name) == 0);

            W = searchWeaponbyName(*L, name);
            printWeapon(W);
            break;

        case 2:

            do{
                printf("\nYOOOO PUT THE CATEGORY HERE -> ");
                fgets(category, 50, stdin);
                category[strcspn(category, "\n")] = '\0';

            }while(strlen(category) == 0);

            W = searchWeaponbyCategory(*L, category);
            printWeapon(W);
            break;

        case 0:
            printf("\nExit...");
            break;

        default:
            printf("\nMANNNNN please press the right button");

    }
}

void completeInformation(list* L){

    list tmp = *L;
    int countWeapon[40] = {0};

    if(tmp == NULL)
    {
        printf("\nTHERE ARE NO WEAPON WHAT A FUCKKKK!!!");
        return;  
    }

    while(tmp != NULL)
    {
        getInfo(getCategory(getWeapon(tmp)), countWeapon);
        tmp = getNext(tmp);
    }
}
