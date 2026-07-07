#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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

/* SWITCH FOR EACH MENU */

static char* switch_FOR_Swords(int choice, char* string);
static char* switch_FOR_heavySword(int choice, char* string);
static char* switch_FOR_Polearms(int choice, char* string);
static char* switch_FOR_FistsANDClaw(int choice, char* string);
static char* switch_FOR_Ranged(int choice, char* string);
static char* switch_FOR_Catalysts(int choice, char* string);
static char* switch_FOR_Utility(int choice, char* string);

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

        clearScreen();

        int choice, index;
        char string[75];

        print_Weapon_Menu();
        printf("\nchoice > ");
        scanf("%d", &choice);
        getchar();

        switch(choice)
        {

            case 1: 

                print_Swords_Menu();
                printf("choice > ");
                
                scanf("%d", &index);
                getchar();

                strcpy(category, switch_FOR_Swords(index, string));

                break;

            case 2: 

                print_HeavySword_Menu();
                printf("choice > ");

                scanf("%d", &index);
                getchar();

                strcpy(category, switch_FOR_heavySword(index, string));

                break;

            case 3:

                print_Polearms_Menu();
                printf("choice > ");

                scanf("%d", &index);
                getchar();

                strcpy(category, switch_FOR_Polearms(index, string));

                break;

            case 4:

                print_FistsANDClaw_Menu();
                printf("choice > ");

                scanf("%d", &index);
                getchar();

                strcpy(category, switch_FOR_FistsANDClaw(index, string));

                break;

            case 5:

                print_Ranged_Menu();
                printf("choice > ");

                scanf("%d", &index);
                getchar();

                strcpy(category, switch_FOR_Ranged(index, string));

                break;

            case 6:

                print_Catalysts_Menu();
                printf("choice > ");

                scanf("%d", &index);
                getchar();

                strcpy(category, switch_FOR_Catalysts(index, string));

                break;

            case 7:

                print_Utility_Menu();
                printf("choice > ");

                scanf("%d", &index);
                getchar();

                strcpy(category, switch_FOR_Utility(index, string));

                break;

            default:
            printf("\nInsert an option between 1 to 7 (0 to exit)\n");
        }

    }while(strlen(category) == 0);

    return category;
}

int isValidName(const char *str){

    while(*str){

        if(!isalpha(*str) && *str != ' ')
            return 0;

        str++;
    }

    return 1;
}

void clearInputBuffer(void){

    int c;

    while((c = getchar()) != '\n' && c != EOF);
}

int ifExist(char* name, list L){

    list tmp = L;

    while(tmp != NULL)
    {
        if(strcmp(getName(getWeapon(L)), name) == 0){

            increaseQuantity(getWeapon(tmp));
            return 1;
        }
        tmp = getNext(tmp);
    }

    return 0;
}




/* ORGANISATION MANU AND SUB-MENU */

static void print_Weapon_Menu(){

    clearScreen();
    printf("\nChoice one of the following MACRO-CATEGORIES\n");

    printf(
        "\n"
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
        "╚══════════════════════════════╝\n"
    );
}
static void print_Swords_Menu(){

    clearScreen();
    printf("\nChoose one of the following categories");

    printf(
        "\n"
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

    clearScreen();
    printf("\nChoose one of the following categories");

    printf(
        "\n"
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

    clearScreen();
    printf("\nChoose one of the following categories");

    printf(
        "\n"
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

    clearScreen();
    printf("\nChoose one of the following categories");

    printf(
        "\n"
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

    clearScreen();
    printf("\nChoose one of the following categories");

    printf(
        "\n"
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

    clearScreen();
    printf("\nChoose one of the following categories");

    printf(
        "\n"
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

    clearScreen();
    printf("\nChoose one of the following categories");

    printf(
        "\n"
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

static char* switch_FOR_Swords(int choice, char* string){

    switch(choice)
    {
        case 1:
            strcpy(string, "Daggers");
            break;

        case 2:
            strcpy(string, "Straight Swords");
            break;

        case 3:
            strcpy(string, "Greatswords");
            break;

        case 4:
            strcpy(string, "Colossal Swords");
            break;

        case 5:
            strcpy(string, "Thrusting Swords");
            break;

        case 6:
            strcpy(string, "Heavy Thrusting Swords");
            break;

        case 7:
            strcpy(string, "Curved Swords");
            break;

        case 8:
            strcpy(string, "Curved Greatswords");
            break;

        case 9:
            strcpy(string, "Katanas");
            break;

        case 10:
            strcpy(string, "Great Katanas");
            break;

        case 11:
            strcpy(string, "Twinblades");
            break;

        case 12:
            strcpy(string, "Light Greatswords");
            break;

        case 0:
            printf("\npress ENTER to return back...");
            getchar();
            break;

        default:
        printf("\nInsert an option between 1 to 12 (0 to exit)\n");
    }

    return string;
}
static char* switch_FOR_heavySword(int choice, char* string){

    switch(choice)
    {
        case 1:
            strcpy(string, "Axes");
            break;

        case 2:
            strcpy(string, "Greataxes");
            break;

        case 3:
            strcpy(string, "Hammers");
            break;

        case 4:
            strcpy(string, "Flails");
            break;

        case 5:
            strcpy(string, "Great Hammers");
            break;

        case 6:
            strcpy(string, "Colossal Weapons");
            break;

        case 0:
            printf("\npress ENTER to return back...");
            getchar();
            break;

        default:
        printf("\nInsert an option between 1 to 6 (0 to exit)\n");
    }

    return string;
}
static char* switch_FOR_Polearms(int choice, char* string){

    switch(choice)
    {
        case 1:
            strcpy(string, "Spears");
            break;

        case 2:
            strcpy(string, "Great Spears");
            break;

        case 3:
            strcpy(string, "Halberds");
            break;

        case 4:
            strcpy(string, "Reapers");
            break;

        case 5:
            strcpy(string, "Whips");
            break;

        case 0:
            printf("\npress ENTER to return back...");
            getchar();
            break;

        default:
        printf("\nInsert an option between 1 to 5 (0 to exit)\n");
    }

    return string;
}
static char* switch_FOR_FistsANDClaw(int choice, char* string){

    switch(choice)
    {
        case 1:
            strcpy(string, "Fists");
            break;

        case 2:
            strcpy(string, "Claws");
            break;

        case 3:
            strcpy(string, "Beast Claws");
            break;

        case 4:
            strcpy(string, "Hand-to-Hand Arts");
            break;

        case 0:
            printf("\npress ENTER to return back...");
            getchar();
            break;

        default:
        printf("\nInsert an option between 1 to 4 (0 to exit)\n");
    }

    return string;
}
static char* switch_FOR_Ranged(int choice, char* string){

    switch(choice)
    {
        case 1:
            strcpy(string, "Light Bows");
            break;

        case 2:
            strcpy(string, "Bows");
            break;

        case 3:
            strcpy(string, "Greatbows");
            break;

        case 4:
            strcpy(string, "Crossbows");
            break;

        case 5:
            strcpy(string, "Ballistas");
            break;

        case 0:
            printf("\npress ENTER to return back...");
            getchar();
            break;

        default:
        printf("\nInsert an option between 1 to 5 (0 to exit)\n");
    }

    return string;
}
static char* switch_FOR_Catalysts(int choice, char* string){

    switch(choice)
    {
        case 1:
            strcpy(string, "Glintstone Staffs");
            break;

        case 2:
            strcpy(string, "Sacred Seals");
            break;

        case 0:
            printf("\npress ENTER to return back...");
            getchar();
            break;

        default:
        printf("\nInsert an option as 1 or 2 (0 to exit)\n");
    }

    return string;
}
static char* switch_FOR_Utility(int choice, char* string){

    switch(choice)
    {
        case 1:
            strcpy(string, "Torches");
            break;

        case 2:
            strcpy(string, "Tools");
            break;

        case 3:
            strcpy(string, "Thrusting Shields");
            break;

        case 4:
            strcpy(string, "Throwing Blades");
            break;

        case 5:
            strcpy(string, "Backhand Blades");
            break;

        case 0:
            printf("\npress ENTER to return back...");
            getchar();
            break;

        default:
        printf("\nInsert an option between 1 to 5 (0 to exit)\n");
    }

    return string;

}
