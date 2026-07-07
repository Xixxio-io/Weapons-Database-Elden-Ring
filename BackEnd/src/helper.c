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





