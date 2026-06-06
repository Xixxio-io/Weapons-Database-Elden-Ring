#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adt_list.h"
#include "repository.h"
#include "weapon.h"


void PutInWeapon(){
    
    char name[25], description[100], category[50];
    int quantity;

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

    createWeapon(name, description, category, quantity);
}
