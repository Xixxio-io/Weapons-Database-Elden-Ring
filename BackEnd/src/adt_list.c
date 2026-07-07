#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "weapon.h"
#include "adt_list.h"

struct node
{
    Weapon weapon;
    int count;
    struct node* next;
};

static int powerUpCount();

/*
static list getFirst(list L);
*/

/*
static list getTail(list L);
*/

list initList(){

    list L = NULL;
    return L;
}

list insertWeapon(list L, Weapon W){

    struct node* tmp;
    tmp = malloc(sizeof(struct node));

    tmp->weapon = W;
    tmp->next = NULL;
    tmp->count = powerUpCount();

    return L;
}

list removeWeapon(list L, char* name){

    int pos = getPosition(L, name);

    if(pos == 0)
    {    
        list tmp = L;
        L = L->next;
        free(tmp);
        return L;
    }
    
    list current = L;

    for(int i = 0; i < pos-1; i++)
    {
        current = current->next;
    }

    list to_remove = current->next;
    current->next = to_remove->next;
    free(to_remove);
    
    return L;
}

Weapon searchWeapon(list L, char* name){
    
    list tmp;
    int found = 0;

    if(L == NULL)
    {
        printf("\nTHERE ARE NO WEAPON WHAT A FUCKKKK!!!");
        return NULL;
    }

    while(tmp != NULL)
    {
        if(strcmp(getName(tmp->weapon), name) == 0)
        {
            found = 1;
            return tmp->weapon;
        }

        tmp = tmp->next;
    }

    if(found == 0)
    {
        printf("\nI'AM SORRY TO SAY THAT BUT YOU DON'T HAVE THAT THING");
        return NULL;
    }
}

int getPosition(list L, char* name){

    int pos = 0;
    list tmp = L;

    while(tmp != NULL)
    {
        if(strcmp(getName(getWeapon(tmp)), name) == 0){
            return pos;
        }
        
        tmp = tmp->next;
        pos++;
    }
   
    return pos;
}

void printALL(list L){

    while(L != NULL)
    {
        printWeapon(L->weapon);
        L = L->next; 
    }
    
    printf("\nQUESTO È TUTTO!\n");
}

/* GETTER */

Weapon getWeapon(list L){
    return L->weapon;
}

list getNext(list L){
    return L->next;
}

/* HELPER */

static int powerUpCount(){
    static int count;
    return count++;
}

/*
static list getFirst(list L){
    return L;
}
*/

/*
static list getTail(list L){
    list tmp;

    tmp = L;
    L = L->next;
    free(tmp);
    return L;
}
*/