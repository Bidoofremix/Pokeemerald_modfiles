< //
    [TRAINER_NONE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _(""),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .partySize = 0,
        .party = {.NoItemDefaultMoves = NULL},
    },

	[TRAINER_MEWTWO] =
	{
		.partyFlags = 0,
		.trainerClass = TRAINER_CLASS_MEWTWO,
		.encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
	    .trainerPic = TRAINER_PIC_MEWTWO,
        .trainerName = _(""),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Mewtwo),
        .party = {.NoItemDefaultMoves = sParty_Mewtwo},
	},

    [TRAINER_EARL_AND_EVA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_OLD_COUPLE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_OLD_COUPLE,
        .trainerName = _("EARL & EVA"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_EarlAndEva1),
        .party = {.NoItemCustomMoves = sParty_EarlAndEva1},
    },
	
    [TRAINER_SAWYER_1] =
// >