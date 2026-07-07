#include <stdio.h>
#include <stdlib.h>
#include "adt_list.h"
#include "weapon.h"
#include "repository.h"

void loadDataBase(list* L){

    FILE* fp;
    fp = fopen("file/database.txt", "r");

    if(fp == NULL)
    {
        printf("\nERRORE APERTURA FILE\n");
        return;
    }

    Weapon tmp;
    char name[100], description[100], category[100];
    int quantity;

    while(fscanf(fp, "%99[^;]; %99[^;];%99[^;];%d", name, description, category, &quantity) == 4)
    {
        tmp = createWeapon(name, description, category, quantity);
        insertWeapon(*L, tmp);
    }

    printf("\nDATABASE CARICATO\n");
    fclose(fp);

    return;
}


void saveDataBase(list* L){

    FILE* fp;
    fp = fopen("file/database.txt", "w");

    if(fp == NULL)
    {
        printf("\nERRORE APERTURA FILE\n");
        return;
    }

    while(*L != NULL)
    {
        Weapon tmp = getWeapon(*L);
        fprintf(fp, "%s;%s;%s;%d\n", getName(tmp), getDescription(tmp), getCategory(tmp), getQuantity(tmp));
        *L = getNext(*L);
    }

    printf("\nDATABASE AGGIORNATO\n");
    fclose(fp);

    return;
}

void resetDataBase(){

    FILE* fp;
    fp = fopen("file/database.txt", "w");
    
    if(fp == NULL)
    {
        printf("\nERRORE APERTURA FILE\n");
        return;
    }

    fclose(fp);

    printf("\nDATABASE RESETTATO CORRETTAMENTE");
}

