#ifndef WEAPON_H
#define WEAPON_H

typedef struct weapon* Weapon;

Weapon createWeapon(char* name, char* description, char* category, int quantity);
void printWeapon(Weapon W);

/* GETTER */
char* getName(Weapon W);
char* getDescription(Weapon W);
char* getCategory(Weapon W);
int getQuantity(Weapon W);

#endif