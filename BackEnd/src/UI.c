#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adt_list.h"
#include "repository.h"
#include "weapon.h"
#include "helper.h"


void putInWeapon(list* L){
    
    char name[25], description[100], category[50];
    int quantity;
    Weapon W;

    do{
        printf("\nPUT THE FUCKING NAME HERE (pls!): ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';

    }while(strlen(name) != 0);

    do{
        printf("\nPLEASE MY N**GA PUT SOMETHING ELSE: ");
        fgets(description, sizeof(description), stdin);
        description[strcspn(description, "\n")] = '\0';

    }while(strlen(description) != 0);

    do{
        printf("\nYOOOOOOO GIVE ME THE CATEGORY NOW: ");
        fgets(category, sizeof(category), stdin);
        category[strcspn(category, "\n")] = '\0';

    }while(strlen(category) != 0);

    quantity = 1;

    W = createWeapon(name, description, category, quantity);
    *L = insertWeapon(*L, W);
}

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

    }while(strlen(name) != 0);

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

            }while(strlen(name) != 0);

            W = searchWeaponbyName(*L, name);
            printWeapon(W);
            break;

        case 2:

            do{
                printf("\nYOOOO PUT THE CATEGORY HERE -> ");
                fgets(category, 50, stdin);
                category[strcspn(category, "\n")] = '\0';

            }while(strlen(category) != 0);

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



