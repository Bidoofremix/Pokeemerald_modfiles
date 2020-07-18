< //
// Maximum value for a female Pokémon is 254 (MON_FEMALE) which is 100% female.
// 255 (MON_GENDERLESS) is reserved for genderless Pokémon.
#define PERCENT_FEMALE(percent) min(254, ((percent * 255) / 100))

const struct BaseStats gBaseStats[] =
{
    [SPECIES_NONE] = {0},

    [SPECIES_{0}] = 
    {
        .baseHP = 45,
        .baseAttack = 49,
        .baseDefense = 49,
        .baseSpAttack = 65,
        .baseSpDefense = 65,
        .baseSpeed = 45,
        .type1 = TYPE_GRASS,
        .type2 = TYPE_POISON,
        .catchRate = 45,
        .expYield = 64,
        .evYield_HP = 0,
        .evYield_Attack = 0,
        .evYield_Defense = 0,
        .evYield_Speed = 0,
        .evYield_SpAttack = 1,
        .evYield_SpDefense = 0,
        .item1 = ITEM_NONE,
        .item2 = ITEM_NONE,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = 70,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_GRASS,
        .abilities = {ABILITY_OVERGROW, ABILITY_NONE},
        .abilityHidden = ABILITY_CHLOROPHYLL,
        .bodyColor = BODY_COLOR_GREEN,
