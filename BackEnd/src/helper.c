#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adt_list.h"
#include "repository.h"
#include "weapon.h"

/* HELPER FUNCTIONS */

static void print_Weapon_Menu();
static void print_Swords_Menu();
static void print_HeavySword_Menu();
static void print_Polearms_Menu();
static void print_FistsANDClaw_Menu();
static void print_Ranged_Menu();
static void print_Catalysts_Menu();
static void print_Utility_Menu();

typedef enum {
    DAGGERS,
    STRAIGHT_SWORDS,
    GREATSWORDS,
    COLOSSAL_SWORDS,
    THRUSTING_SWORDS,
    HEAVY_THRUSTING_SWORDS,
    CURVED_SWORDS,
    CURVED_GREATSWORDS,
    KATANAS,
    GREAT_KATANAS,
    TWINBLADES,

    AXES,
    GREATAXES,
    HAMMERS,
    FLAILS,
    GREAT_HAMMERS,
    COLOSSAL_WEAPONS,

    SPEARS,
    GREAT_SPEARS,
    HALBERDS,
    REAPERS,
    WHIPS,

    FISTS,
    CLAWS,
    BEAST_CLAWS,
    HAND_TO_HAND_ARTS,

    LIGHT_BOWS,
    BOWS,
    GREATBOWS,
    CROSSBOWS,
    BALLISTAS,

    GLINTSTONE_STAFFS,
    SACRED_SEALS,

    TORCHES,
    TOOLS,

    THRUSTING_SHIELDS,
    THROWING_BLADES,
    BACKHAND_BLADES,
    LIGHT_GREATSWORDS,

    NUM_CATEGORIES
} WeaponCategory;


void getInfo(char* category, int countWeapon[]){

    const char* weaponAsset[] = {
        "Daggers",
        "Straight Swords",
        "Greatswords",
        "Colossal Swords",
        "Thrusting Swords",
        "Heavy Thrusting Swords",
        "Curved Swords",
        "Curved Greatswords",
        "Katanas",
        "Great Katanas",
        "Twinblades",

        "Axes",
        "Greataxes",
        "Hammers",
        "Flails",
        "Great Hammers",
        "Colossal Weapons",

        "Spears",
        "Great Spears",
        "Halberds",
        "Reapers",
        "Whips",

        "Fists",
        "Claws",
        "Beast Claws",
        "Hand-to-Hand Arts",

        "Light Bows",
        "Bows",
        "Greatbows",
        "Crossbows",
        "Ballistas",

        "Glintstone Staffs",
        "Sacred Seals",

        "Torches",
        "Tools",

        "Thrusting Shields",
        "Throwing Blades",
        "Backhand Blades",
        "Light Greatswords"
    };


    for(int i = 0; i < NUM_CATEGORIES; i++){
        if(strcmp(weaponAsset[i], category) == 0){
            countWeapon[i] += 1;
        }
    }

    for(int i = 0; i < NUM_CATEGORIES; i++){
        printf("\n%s: %d",weaponAsset[i], countWeapon[i]);
    }
}

void clearScreen(void){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}


char* choose_Category(char* category){

    do{

        printf("\nYOOOOOOO choose the category now :)");

        int choice;

        print_Weapon_Menu();
        printf( "Put the choice right here --> ");
        scanf("%d", &choice);
        getchar();

        switch(choice)
        {

            case 1: 

                print_Swords_Menu();
                printf("Put the choice right here --> ");
            

                break;

            case 2: 

                print_HeavySword_Menu();
                printf("Put the choice right here --> ");


                break;

            case 3:

                print_Polearms_Menu();
                printf("Put the choice right here --> ");


                break;

            case 4:

                print_FistsANDClaw_Menu();
                printf("Put the choice right here --> ");


                break;

            case 5:

                print_Ranged_Menu();
                printf("Put the choice right here --> ");


                break;

            case 6:

                print_Catalysts_Menu();
                printf("Put the choice right here --> ");


                break;

            case 7:

                print_Utility_Menu();
                printf("Put the choice right here --> ");


                break;

            case 0:
                
                printf("\nExit...");
                break;

            default:
            printf("\nDAMN GOD!!! Press the right button FUCK YOU!");
        }

    }while(strlen(category) == 0);

    return category;
}


/* ORGANISATION MANU AND SUB-MENU */

static void print_Weapon_Menu(){

    printf(
        "╔══════════════════════════════╗\n"
        "║      WEAPON CATEGORIES       ║\n"
        "╠══════════════════════════════╣\n"
        "║ 1. Swords                    ║\n"
        "║ 2. Heavy Weapons             ║\n"
        "║ 3. Polearms                  ║\n"
        "║ 4. Fists & Claws             ║\n"
        "║ 5. Ranged Weapons            ║\n"
        "║ 6. Magic Catalysts           ║\n"
        "║ 7. Utility                   ║\n"
        "║                              ║\n"
        "║ 0. Back                      ║\n"
        "╚══════════════════════════════╝\n"
    );
}
static void print_Swords_Menu(){

    printf(
        "╔══════════════════════════════╗\n"
        "║           SWORDS             ║\n"
        "╠══════════════════════════════╣\n"
        "║  1. Daggers                  ║\n"
        "║  2. Straight Swords          ║\n"
        "║  3. Greatswords              ║\n"
        "║  4. Colossal Swords          ║\n"
        "║  5. Thrusting Swords         ║\n"
        "║  6. Heavy Thrusting Swords   ║\n"
        "║  7. Curved Swords            ║\n"
        "║  8. Curved Greatswords       ║\n"
        "║  9. Katanas                  ║\n"
        "║ 10. Great Katanas            ║\n"
        "║ 11. Twinblades               ║\n"
        "║ 12. Light Greatswords        ║\n"
        "║                              ║\n"
        "║  0. Back                     ║\n"
        "╚══════════════════════════════╝\n"
    );
}
static void print_HeavySword_Menu(){

    printf(
        "╔══════════════════════════════╗\n"
        "║       HEAVY WEAPONS          ║\n"
        "╠══════════════════════════════╣\n"
        "║  1. Axes                     ║\n"
        "║  2. Greataxes                ║\n"
        "║  3. Hammers                  ║\n"
        "║  4. Flails                   ║\n"
        "║  5. Great Hammers            ║\n"
        "║  6. Colossal Weapons         ║\n"
        "║                              ║\n"
        "║  0. Back                     ║\n"
        "╚══════════════════════════════╝\n"
    );
}
static void print_Polearms_Menu(){

    printf(
        "╔══════════════════════════════╗\n"
        "║          POLEARMS            ║\n"
        "╠══════════════════════════════╣\n"
        "║  1. Spears                   ║\n"
        "║  2. Great Spears             ║\n"
        "║  3. Halberds                 ║\n"
        "║  4. Reapers                  ║\n"
        "║  5. Whips                    ║\n"
        "║                              ║\n"
        "║  0. Back                     ║\n"
        "╚══════════════════════════════╝\n"
        "Choice > "
    );
}
static void print_FistsANDClaw_Menu(){

    printf(
        "╔══════════════════════════════╗\n"
        "║       FISTS & CLAWS          ║\n"
        "╠══════════════════════════════╣\n"
        "║  1. Fists                    ║\n"
        "║  2. Claws                    ║\n"
        "║  3. Beast Claws              ║\n"
        "║  4. Hand-to-Hand Arts        ║\n"
        "║                              ║\n"
        "║  0. Back                     ║\n"
        "╚══════════════════════════════╝\n"
    );
}
static void print_Ranged_Menu(){

    printf(
        "╔══════════════════════════════╗\n"
        "║       RANGED WEAPONS         ║\n"
        "╠══════════════════════════════╣\n"
        "║  1. Light Bows               ║\n"
        "║  2. Bows                     ║\n"
        "║  3. Greatbows                ║\n"
        "║  4. Crossbows                ║\n"
        "║  5. Ballistas                ║\n"
        "║                              ║\n"
        "║  0. Back                     ║\n"
        "╚══════════════════════════════╝\n"
    );
}
static void print_Catalysts_Menu(){

    printf(
        "╔══════════════════════════════╗\n"
        "║       MAGIC CATALYSTS        ║\n"
        "╠══════════════════════════════╣\n"
        "║  1. Glintstone Staffs        ║\n"
        "║  2. Sacred Seals             ║\n"
        "║                              ║\n"
        "║  0. Back                     ║\n"
        "╚══════════════════════════════╝\n"
    );
}
static void print_Utility_Menu(){

    printf(
        "╔══════════════════════════════╗\n"
        "║           UTILITY            ║\n"
        "╠══════════════════════════════╣\n"
        "║  1. Torches                  ║\n"
        "║  2. Tools                    ║\n"
        "║  3. Thrusting Shields        ║\n"
        "║  4. Throwing Blades          ║\n"
        "║  5. Backhand Blades          ║\n"
        "║                              ║\n"
        "║  0. Back                     ║\n"
        "╚══════════════════════════════╝\n"
    );
}


/* SWITCH FOR EACH MENU */

/*
*
* FOR THE FUTURE ME 
* make the functions that create the switch of each sub-menu
* each function has to return back an char* [strings]
* when the strings return back to the "choose_Category" function
* save the string into an array of string "category" passed as a paramater
* to the function. Next close the function and push back the category to the function "putInWeapon"
*
*/

