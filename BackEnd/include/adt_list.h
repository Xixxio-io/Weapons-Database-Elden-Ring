#ifndef LIST_H
#define LIST_H
#include "weapon.h"

typedef struct node* list;

list initList();
list insertWeapon(list L, Weapon W);
list removeWeapon(list L, char* name);
Weapon searchWeapon(list L, char* name);
void printALL(list L);

/* GETTER */
Weapon getWeapon(list L);
list getNext(list L);
int getPosition(list L, char* name);

#endif
