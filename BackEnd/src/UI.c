#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "adt_list.h"
#include "repository.h"
#include "weapon.h"
#include "helper.h"

void putInWeapon(list* L){
    
    char name[25], description[100], category[50], choice;
    int quantity;
    Weapon W;

    do{

        /* DO-WHILE NAME */
        do{
            clearScreen();

            printf("\nInsert the weapon's name > ");
            fgets(name, sizeof(name), stdin);

            for(size_t i = 0; i < sizeof(name); i++)
            {
                name[i] = tolower(name[i]);
            }

            if(strchr(name, '\n') == NULL)
            {
                printf("\nYou have exceeded the maximum number of characters: (%lu)", sizeof(name) -1);
                clearInputBuffer();

                continue;
            }

            name[strcspn(name, "\n")] = '\0';

            if(strlen(name) == 0){

                printf("\nThe string is empty!");
                continue;
            }

            do{ 
                printf("\nThe name | %s | is correct?", name);
                printf("\n(Y/N) > ");

                scanf(" %c", &choice);
                clearInputBuffer();
                choice = tolower(choice);

                if(ifExist(name, *L) == 1){

                    printf("\nThe weapon is already insert!\n");
                    printf("\nIncreasing the Quantity...\n");

                    return;
                }

                if(choice != 'y' && choice != 'n')
                {
                    printf("\nPlease insert only Y or N!\n");
                }

                if(choice == 'N' || choice == 'n'){
                    printf("\nExit...\n");
                    return;
                }

            }while(choice != 'y' && choice != 'Y');

        }while(choice != 'y' && choice != 'Y');

        clearScreen();

        do{
            printf("\nDo you wanna add a description?");
            printf("\n(Y/N) > ");

            scanf(" %c", &choice);
            clearInputBuffer();

            choice = tolower(choice);

            if(choice != 'y' && choice != 'n')
            printf("\nPlease insert only Y or N!\n");

        }while(choice != 'y' && choice != 'n'); 

        if(choice == 'N' || choice == 'n'){
            strcpy(description, "-");
        }

        /* DO-WHILE DESCRIPTION */
        if(choice == 'Y' || choice == 'y'){

            do{
                clearScreen();

                printf("\nInsert the description > ");
                fgets(description, sizeof(description), stdin);

                if(strchr(description, '\n') == NULL)
                {
                    printf("\nYou have exceeded the maximum number of characters: (%lu)", sizeof(description) -1);
                    clearInputBuffer();

                    continue;
                }

                description[strcspn(description, "\n")] = '\0';

                if(strlen(description) == 0)
                {
                    printf("\nThe string is empty!");
                    continue;
                }

                do{
                    printf("\nThe following description is correct? > %s", description);
                    printf("\n(Y/N) > ");

                    scanf(" %c", &choice);
                    clearInputBuffer();

                    choice = tolower(choice);

                    if(choice != 'y' && choice != 'n')
                    printf("\nPlease insert only Y or N!\n");
                }while(choice != 'y' && choice != 'n');

            }while(choice != 'y' && choice != 'Y');
        }    

        /* DO-WHILE CATEGORY */
        do{
            clearScreen();
            choose_Category(category);
           
            do{
                printf("\nAre you sure to confirm: %s", category);
                printf("\n(Y/N): ");

                scanf(" %c", &choice);
                clearInputBuffer();

                choice = tolower(choice);

                if(choice != 'y' && choice != 'n')
                {
                printf("\nPlease insert only Y or N!\n");
                }

            }while(choice != 'y' && choice != 'n');

        }while(choice != 'y' && choice != 'Y');

        quantity = 1;

        clearScreen();
        printf("\n");
        printf("╔══════════════════════════════════════════════════════════════╗\n");
        printf("║                    ELDEN RING WEAPON                         ║\n");
        printf("╠══════════════════════════════════════════════════════════════╣\n");
        printf("║ Name        : %-46s ║\n", name);
        printf("║ Description : %-46s ║\n", description);
        printf("║ Category    : %-46s ║\n", category);                         
        printf("╚══════════════════════════════════════════════════════════════╝\n");

        do{
            printf("\nInsert Weapon?");
            printf("\n(Y/N) > ");

            scanf(" %c", &choice);
            clearInputBuffer();

            choice = tolower(choice);

            if(choice != 'y' && choice != 'n')
            {
                printf("\nPlease insert only Y or N!\n");
            }

        }while(choice != 'y' && choice != 'n');

    }while(choice != 'Y' && choice != 'y');
        W = createWeapon(name, description, category, quantity);
        *L = insertWeapon(*L, W);
    }

/*
*
* Mission of today
* verify if the weapon that the user is going to insert
* is already in. 
* I need a function the read all the weapon's name and 
* compare it with the weapon's name to insert.
* The function has to return a bool, if the weapon
* is already in i have to increase the quantity of that weapon
* if not i continue the insert.
*
**/

void deleteWeapon(list* L){

    char name[30];

    if(*L == NULL)
    {
        printf("\nYou don't have any registred! You can't Delete\n");
        return;
    }

    do{
        printf("\nYOOOO PUT THE NAME HERE -> ");
        fgets(name, 30, stdin);
        name[strcspn(name, "\n")] = '\0';

    }while(strlen(name) == 0);

    *L = removeWeapon(*L, name);

    printf("\nWEAPON CORRECTLY REMOVED");   
}

void viewWeapon(list* L){

    char name[30], category[50];
    int choice;
    Weapon W;

    if(*L == NULL)
    {
        printf("\nYou don't have any weapon registred!\n");
        return;        
    }

    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                      SEARCH WEAPON                           ║\n");
    printf("╠═════╦════════════════════════════════════════════════════════╣\n");
    printf("║  1  ║ Search by Name                                         ║\n");
    printf("║  2  ║ Search by Category                                     ║\n");
    printf("║  0  ║ Back                                                   ║\n");
    printf("╚═════╩════════════════════════════════════════════════════════╝\n");

    printf("\nChoice > ");
    scanf("%d", &choice);
    getchar();

    switch(choice){

        case 1: 

            do{
                printf("\nInsert the name of the weapon to research > ");
                fgets(name, 30, stdin);
                name[strcspn(name, "\n")] = '\0';

            }while(strlen(name) == 0);

            W = searchWeaponbyName(*L, name);
            printWeapon(W);
            break;

        case 2:

            W = searchWeaponbyCategory(*L, choose_Category(category));
            printWeapon(W);
            break;

        case 0:
            printf("\nExit...\n");
            break;

        default:
            printf("\nPlease select a value from (0) to (2)\n");

    }
}

void completeInformation(list* L){

    list tmp = *L;
    int countWeapon[40] = {0};
    int totalWeapons = 0;

    if(tmp == NULL)
    {
        printf("\nYou don't have any weapon registred!\n");
        return;  
    }

    clearScreen();
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                    COMPLETE REPORT                           ║\n");
    printf("╠══════════════════════════════════════════════════════════════╣\n");

    while(tmp != NULL)
    {
        getInfo(getCategory(getWeapon(tmp)), countWeapon);
        tmp = getNext(tmp);
        totalWeapons++;
    }

    printf("╠══════════════════════════════════════════════════════════════╣\n");
    printf("║ Total Weapons%47d ║\n", totalWeapons);
    printf("╚══════════════════════════════════════════════════════════════╝\n");
}
