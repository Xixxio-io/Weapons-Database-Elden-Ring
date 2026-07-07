#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adt_list.h"
#include "repository.h"
#include "weapon.h"

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
        printf("%s: %d",weaponAsset[i], countWeapon[i]);
    }
}

