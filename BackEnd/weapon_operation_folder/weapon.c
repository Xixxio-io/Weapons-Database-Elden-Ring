#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "weapon.h"

struct weapon
{
    char name[50];
    char description[100];
    char category[25];
    int quantity;
};

Weapon createWeapon(char* name, char* description, char* category, int quantity){

Weapon W = malloc(sizeof(Weapon));

/* name */
strcpy(W->name, name);

/* description */
strcpy(W->description, description);

/* category */
strcpy(W->category, category);

/* quantity */
W->quantity = quantity;

return W;
}

void printWeapon(Weapon W){

printf("\nName: %s", W->name);

printf("\nDescription: %s", W->description);

printf("\nCategory: %s", W->category);

printf("\nThis is the <%ss> you have: %d", W->name, W->quantity);

return;
}

/* GETTER */

char* getName(Weapon W){
    return W->name;
}

char* getDescription(Weapon W){
    return W->description;
}

char* getCategory(Weapon W){
    return W->category;
}

int getQuantity(Weapon W){
    return W->quantity;
}