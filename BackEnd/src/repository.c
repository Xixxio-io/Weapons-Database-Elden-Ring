#include <stdio.h>
#include <stdlib.h>
#include "adt_list.h"
#include "weapon.h"
#include "repository.h"

void loadDataBase(list* L){

    FILE* fp;
    fp = fopen("BackEnd/file/database.txt", "r");

    int n = 0;

    if(fp == NULL)
    {
        printf("\nERROR: FILE DOESN'T OPEN\n");
        return;
    }

    Weapon tmp;
    char name[100], description[100], category[100];
    int quantity;

    while(fscanf(fp, "%99[^;]; %99[^;];%99[^;];%d", name, description, category, &quantity) == 4)
    {

        tmp = createWeapon(name, description, category, quantity);
        *L = insertWeapon(*L, tmp);

        n++;
    }

    printf("Weapon Charged: %d", n);

    printf("\nDATABASE CHARGED\n");
    fclose(fp);

    return;
}


void saveDataBase(list* L){

    FILE* fp;
    fp = fopen("BackEnd/file/database.txt", "w");

    list tmp_L = *L;

    if(fp == NULL)
    {
        printf("\nERROR: FILE DOESN'T OPEN\n");
        return;
    }

    while(tmp_L != NULL)
    {
        Weapon tmp = getWeapon(tmp_L);
        fprintf(fp, "%s;%s;%s;%d\n", getName(tmp), getDescription(tmp), getCategory(tmp), getQuantity(tmp));
        tmp_L = getNext(tmp_L);
    }

    printf("\nDATABASE UPDATED\n");
    fclose(fp);

    return;
}

void resetDataBase(){

    FILE* fp;
    fp = fopen("BackEnd/file/database.txt", "w");
    
    if(fp == NULL)
    {
        printf("\nERROR: FILE DOESN'T OPEN\n");
        return;
    }

    fclose(fp);

    printf("\nDATABASE RESTORED");
}

