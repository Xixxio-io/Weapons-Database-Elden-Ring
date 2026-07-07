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

    Weapon W = malloc(sizeof(struct weapon));

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

    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                    ELDEN RING WEAPON                         ║\n");
    printf("╠══════════════════════════════════════════════════════════════╣\n");
    printf("║ Name        : %-46s ║\n", W->name);
    printf("║ Description : %-46s ║\n", W->description);
    printf("║ Category    : %-46s ║\n", W->category);    
    printf("║ Category    : %-46d ║\n", W->quantity);                   
    printf("╚══════════════════════════════════════════════════════════════╝\n");

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

void increaseQuantity(Weapon W){
    W->quantity++;
}