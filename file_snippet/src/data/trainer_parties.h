< //
static const struct TrainerMonNoItemDefaultMoves sParty_Sawyer1[] = {
    {
    .iv = 0,
    .lvl = 21,
    .species = SPECIES_GEODUDE,
    }
};

static const struct TrainerMonNoItemDefaultMoves sParty_Mewtwo[] = {
    {
    .iv = 0,
    .lvl = 3,
    .species = SPECIES_CHARIZARD,
    }
};

static const struct TrainerMonNoItemCustomMoves sParty_EarlAndEva[] = {
	{
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_CHIKORITA,
	.moves = {MOVE_RAZOR_LEAF, MOVE_NONE, MOVE_NONE, MOVE_NONE}
    },
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_TYROGUE,
	.moves = {MOVE_HELPING_HAND, MOVE_NONE, MOVE_NONE, MOVE_NONE}
    }
};

static const struct TrainerMonNoItemDefaultMoves sParty_GruntBrineBeach1[] = {
    {
    .iv = 0,
    .lvl = 20,
    .species = SPECIES_WOOPER,
    },
	{
    .iv = 0,
    .lvl = 22,
    .species = SPECIES_ZUBAT,
    }
};

static const struct TrainerMonNoItemDefaultMoves sParty_GruntBrineBeach2[] = {
    {
    .iv = 0,
    .lvl = 23,
    .species = SPECIES_WARTORTLE,
    }
};

static const struct TrainerMonNoItemDefaultMoves sParty_GruntBrineBeach3[] = {
	{
    .iv = 0,
    .lvl = 22,
    .species = SPECIES_GOLPPY,
    },
    {
    .iv = 0,
    .lvl = 21,
    .species = SPECIES_CARVANHA,
    }
};

static const struct TrainerMonNoItemDefaultMoves sParty_ShellyBrineBeach[] = {
    {
    .iv = 50,
    .lvl = 25,
    .species = SPECIES_CROCONAW,
    },
    {
    .iv = 50,
    .lvl = 24,
    .species = SPECIES_NIDORINA,
    }
};

static const struct TrainerMonNoItemCustomMoves sParty_Tycho[] = {
	{
    .iv = 0,
    .lvl = 25,
    .species = SPECIES_PIKACHU,
	.moves = {MOVE_SHOCK_WAVE,MOVE_SURF,MOVE_NONE,MOVE_NONE},
    }
};

static const struct TrainerMonNoItemDefaultMoves sParty_Caden[] = {
	{
    .iv = 0,
    .lvl = 23,
    .species = SPECIES_HITMONTOP,
    }
};

static const struct TrainerMonNoItemDefaultMoves sParty_Chevis[] = {
	{
    .iv = 0,
    .lvl = 23,
    .species = SPECIES_WAILMER,
    },
    {
    .iv = 0,
    .lvl = 24,
    .species = SPECIES_GOLDEEN,
    }
};

static const struct TrainerMonNoItemDefaultMoves sParty_GruntRhyoliteCanyon1[] = {
	{
    .iv = 0,
    .lvl = 33,
    .species = SPECIES_NUMEL,
    },
    {
    .iv = 0,
    .lvl = 33,
    .species = SPECIES_SEVIPER,
    }
};

static const struct TrainerMonNoItemDefaultMoves sParty_GruntRhyoliteCanyon2[] = {
	{
    .iv = 0,
    .lvl = 33,
    .species = SPECIES_GLIGAR,
    },
    {
    .iv = 0,
    .lvl = 33,
    .species = SPECIES_GROWLITHE,
    }
};

static const struct TrainerMonNoItemDefaultMoves sParty_GruntRhyoliteCanyon3[] = {
	{
    .iv = 0,
    .lvl = 32,
    .species = SPECIES_HOUNDOUR,
    },
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_ARBOK,
    }
};

static const struct TrainerMonNoItemDefaultMoves sParty_GruntRhyoliteCanyon4[] = {
	{
    .iv = 0,
    .lvl = 35,
    .species = SPECIES_CHARMELEON,
    },
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_MIGHTYENA,
    }
};

static const struct TrainerMonNoItemDefaultMoves sParty_TabithaRhyoliteCanyon[] = {
	{
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_MIGHTYENA,
    },
	{
    .iv = 0,
    .lvl = 35,
    .species = SPECIES_SKARMORY,
    },
    {
    .iv = 0,
    .lvl = 36,
    .species = SPECIES_MAGMAR,
    }
};

static const struct TrainerMonItemCustomMovesAbilityShiny sParty_MasterBug[] = {
    {
    .iv = 0,
    .lvl = 15,
	.moves = {MOVE_REVENGE, MOVE_BULK_UP, MOVE_BUG_BITE, MOVE_NONE},
    .heldItem = ITEM_NONE,
    .abilityNum = 1,
    .shiny = 0,
    .species = SPECIES_PINSIR,
    },
    {
    .iv = 0,
    .lvl = 15,
	.moves = {MOVE_AERIAL_ACE, MOVE_QUICK_ATTACK, MOVE_ROCK_SMASH, MOVE_SILVER_WIND},
    .heldItem = ITEM_NONE,
    .abilityNum = 1,
    .shiny = 0,
    .species = SPECIES_SCYTHER,
    },
    {
    .iv = 0,
    .lvl = 15,
	.moves = {MOVE_CONFUSION, MOVE_GIGA_DRAIN, MOVE_STRUGGLE_BUG, MOVE_GUST},
    .heldItem = ITEM_NONE,
    .abilityNum = 2,
    .shiny = 0,
    .species = SPECIES_DUSTOX,
    },
};

static const struct TrainerMonItemCustomMovesAbilityShiny sParty_MasterNormal[] = {
    {
    .iv = 100,
    .lvl = 30,
	.moves = {MOVE_SPORE, MOVE_FOCUS_PUNCH, MOVE_NONE, MOVE_NONE},
    .heldItem = ITEM_BRIGHT_POWDER,
    .abilityNum = 0,
    .shiny = 0,
    .species = SPECIES_SMEARGLE,
    },
    {
    .iv = 100,
    .lvl = 30,
	.moves = {MOVE_STOMP, MOVE_ATTRACT, MOVE_ROLLOUT, MOVE_MILK_DRINK},
    .heldItem = ITEM_KINGS_ROCK,
    .abilityNum = 0,
    .shiny = 0,
    .species = SPECIES_MILTANK,
    },
    {
    .iv = 100,
    .lvl = 30,
	.moves = {MOVE_DRILL_PECK, MOVE_NONE, MOVE_NONE, MOVE_NONE},
    .heldItem = ITEM_CHOICE_BAND,
    .abilityNum = 2,
    .shiny = 1,
    .species = SPECIES_FEAROW,
    },
};

static const struct TrainerMonItemCustomMovesAbilityShiny sParty_Gandiv[] = {
    {
    .iv = 255,
    .lvl = 30,
	.moves = {MOVE_BOOMBURST, MOVE_NONE, MOVE_NONE, MOVE_NONE},
    .heldItem = ITEM_CHOICE_SCARF,
    .abilityNum = 2,
    .shiny = 0,
    .species = SPECIES_EXPLOUD,
    },
    {
    .iv = 255,
    .lvl = 30,
	.moves = {MOVE_DAZZLING_GLEAM, MOVE_LIGHT_SCREEN, MOVE_REFLECT, MOVE_NONE},
    .heldItem = ITEM_LIGHT_CLAY,
    .abilityNum = 2,
    .shiny = 0,
    .species = SPECIES_GARDEVOIR,
    },
    {
    .iv = 255,
    .lvl = 30,
	.moves = {MOVE_BOOMBURST, MOVE_THUNDERBOLT, MOVE_NONE, MOVE_NONE},
    .heldItem = ITEM_LIFE_ORB,
    .abilityNum = 0,
    .shiny = 0,
    .species = SPECIES_ELECTRODE,
    }, 
	{
    .iv = 255,
    .lvl = 30,
	.moves = {MOVE_FORESIGHT, MOVE_SHADOW_BALL, MOVE_FOCUS_BLAST, MOVE_NONE},
    .heldItem = ITEM_LEFTOVERS,
    .abilityNum = 0,
    .shiny = 0,
    .species = SPECIES_DUSKNOIR,
    },
};
static const struct TrainerMonItemCustomMovesAbilityShiny sParty_Renee[] = {
    {
    .iv = 255,
    .lvl = 30,
	.moves = {MOVE_FLARE_BLITZ, MOVE_HIGH_JUMP_KICK, MOVE_NONE, MOVE_NONE},
    .heldItem = ITEM_FOCUS_SASH,
    .abilityNum = 2,
    .shiny = 0,
    .species = SPECIES_BLAZIKEN,
    },
    {
    .iv = 255,
    .lvl = 30,
	.moves = {MOVE_DRAGON_DANCE, MOVE_WATERFALL, MOVE_EARTHQUAKE, MOVE_NONE},
    .heldItem = ITEM_LIFE_ORB,
    .abilityNum = 0,
    .shiny = 1,
    .species = SPECIES_GYARADOS,
    },
    {
    .iv = 255,
    .lvl = 30,
	.moves = {MOVE_SHELL_SMASH, MOVE_ICICLE_SPEAR, MOVE_ROCK_BLAST, MOVE_ICE_SHARD},
    .heldItem = ITEM_KINGS_ROCK,
    .abilityNum = 2,
    .shiny = 0,
    .species = SPECIES_CLOYSTER,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_GruntAquaHideout1[] = {
// >