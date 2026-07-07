#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adt_list.h"
#include "repository.h"
#include "weapon.h"
#include "helper.h"


void putInWeapon(list L){
    
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
    insertWeapon(L, W);
}

void deleteWeaponUI(list L){

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

    removeWeapon(L, name);

    printf("\nWEAPON CORRECTLY REMOVED");   
}

void foundWeapon(list L){

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

    searchWeapon(L, name);

    printWeapon(getWeapon(L));
}

void completeInformation(list L){

    list tmp = L;
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



