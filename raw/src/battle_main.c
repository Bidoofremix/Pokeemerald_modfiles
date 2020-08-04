< //
static const u8 sText_ShedinjaJpnName[] = _("ヌケニン"); // Nukenin

const struct TrainerBall gTrainerBallTable[] = {
    {TRAINER_CLASS_TEAM_AQUA, ITEM_NET_BALL},
    {TRAINER_CLASS_AQUA_ADMIN, ITEM_NET_BALL},
    {TRAINER_CLASS_AQUA_LEADER, ITEM_MASTER_BALL},
    {TRAINER_CLASS_AROMA_LADY, ITEM_FRIEND_BALL},
    {TRAINER_CLASS_RUIN_MANIAC, ITEM_DUSK_BALL},
    {TRAINER_CLASS_INTERVIEWER, ITEM_REPEAT_BALL},
    {TRAINER_CLASS_TUBER_F, ITEM_DIVE_BALL},
    {TRAINER_CLASS_TUBER_M, ITEM_DIVE_BALL},
    {TRAINER_CLASS_SIS_AND_BRO, ITEM_POKE_BALL},
    {TRAINER_CLASS_COOLTRAINER, ITEM_ULTRA_BALL},
    {TRAINER_CLASS_HEX_MANIAC, ITEM_DUSK_BALL},
    {TRAINER_CLASS_LADY, ITEM_LUXURY_BALL},
    {TRAINER_CLASS_BEAUTY, ITEM_LOVE_BALL},
    {TRAINER_CLASS_RICH_BOY, ITEM_LUXURY_BALL},
    {TRAINER_CLASS_POKEMANIAC, ITEM_MOON_BALL},
    {TRAINER_CLASS_SWIMMER_M, ITEM_DIVE_BALL},
    {TRAINER_CLASS_BLACK_BELT, ITEM_HEAVY_BALL},
    {TRAINER_CLASS_GUITARIST, ITEM_FAST_BALL},
    {TRAINER_CLASS_KINDLER, ITEM_POKE_BALL},
    {TRAINER_CLASS_CAMPER, ITEM_NEST_BALL},
    {TRAINER_CLASS_OLD_COUPLE, ITEM_POKE_BALL},
    {TRAINER_CLASS_BUG_MANIAC, ITEM_NET_BALL},
    {TRAINER_CLASS_PSYCHIC, ITEM_DREAM_BALL},
    {TRAINER_CLASS_GENTLEMAN, ITEM_LUXURY_BALL},
    {TRAINER_CLASS_ELITE_FOUR, ITEM_ULTRA_BALL},
    {TRAINER_CLASS_LEADER, ITEM_ULTRA_BALL},
    {TRAINER_CLASS_SCHOOL_KID, ITEM_POKE_BALL},
    {TRAINER_CLASS_SR_AND_JR, ITEM_POKE_BALL},
    {TRAINER_CLASS_POKEFAN, ITEM_POKE_BALL},
    {TRAINER_CLASS_EXPERT, ITEM_ULTRA_BALL},
    {TRAINER_CLASS_YOUNGSTER, ITEM_POKE_BALL},
    {TRAINER_CLASS_CHAMPION, ITEM_CHERISH_BALL},
    {TRAINER_CLASS_FISHERMAN, ITEM_LURE_BALL},
    {TRAINER_CLASS_TRIATHLETE, ITEM_FAST_BALL},
    {TRAINER_CLASS_DRAGON_TAMER, ITEM_ULTRA_BALL},
    {TRAINER_CLASS_BIRD_KEEPER, ITEM_QUICK_BALL},
    {TRAINER_CLASS_NINJA_BOY, ITEM_QUICK_BALL},
    {TRAINER_CLASS_BATTLE_GIRL, ITEM_HEAVY_BALL},
    {TRAINER_CLASS_PARASOL_LADY, ITEM_POKE_BALL},
    {TRAINER_CLASS_SWIMMER_F, ITEM_DIVE_BALL},
    {TRAINER_CLASS_PICNICKER, ITEM_FRIEND_BALL},
    {TRAINER_CLASS_TWINS, ITEM_POKE_BALL},
    {TRAINER_CLASS_SAILOR, ITEM_DIVE_BALL},
    {TRAINER_CLASS_COLLECTOR, ITEM_REPEAT_BALL},
    {TRAINER_CLASS_PKMN_TRAINER_3, ITEM_PREMIER_BALL},
    {TRAINER_CLASS_PKMN_BREEDER, ITEM_TIMER_BALL},
    {TRAINER_CLASS_PKMN_RANGER, ITEM_SAFARI_BALL},
    {TRAINER_CLASS_TEAM_MAGMA, ITEM_NEST_BALL},
    {TRAINER_CLASS_MAGMA_ADMIN, ITEM_NEST_BALL},
    {TRAINER_CLASS_MAGMA_LEADER, ITEM_MASTER_BALL},
    {TRAINER_CLASS_LASS, ITEM_POKE_BALL},
    {TRAINER_CLASS_BUG_CATCHER, ITEM_NET_BALL},
    {TRAINER_CLASS_HIKER, ITEM_HEAVY_BALL},
    {TRAINER_CLASS_YOUNG_COUPLE, ITEM_LOVE_BALL},
    {TRAINER_CLASS_WINSTRATE, ITEM_GREAT_BALL},
    {TRAINER_CLASS_PKMN_TRAINER_2, ITEM_HEAVY_BALL},
	{TRAINER_CLASS_MEWTWO, ITEM_MASTER_BALL},
    {0xFF, ITEM_POKE_BALL},
};

const struct OamData gOamData_831ACA8 =
// >

< //
static u8 CreateNPCTrainerParty(struct Pokemon *party, u16 trainerNum, bool8 firstTrainer)
{
	
	// custom pokeballs and dynamic levels
	
    u32 nameHash = 0;
    u32 personalityValue;
    u8 fixedIV;
    s32 i, j;
    u8 monsCount;
	u8 level = 0;
	u8 enemyHighestLevel = 0;

	// vanilla function
	u8 playerHighestLevel = GetHighestLevelInPlayerParty();
	
	
    if (trainerNum == TRAINER_SECRET_BASE)
        return 0;

    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER && !(gBattleTypeFlags & (BATTLE_TYPE_FRONTIER
                                                                        | BATTLE_TYPE_EREADER_TRAINER
                                                                        | BATTLE_TYPE_TRAINER_HILL)))
    {
        if (firstTrainer == TRUE)
            ZeroEnemyPartyMons();

        if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
        {
            if (gTrainers[trainerNum].partySize > 3)
                monsCount = 3;
            else
                monsCount = gTrainers[trainerNum].partySize;
        }
        else
        {
            monsCount = gTrainers[trainerNum].partySize;
        }

        for (i = 0; i < monsCount; i++)
        {

            if (gTrainers[trainerNum].doubleBattle == TRUE)
                personalityValue = 0x80;
            else if (gTrainers[trainerNum].encounterMusic_gender & 0x80)
                personalityValue = 0x78;
            else
                personalityValue = 0x88;

            for (j = 0; gTrainers[trainerNum].trainerName[j] != EOS; j++)
                nameHash += gTrainers[trainerNum].trainerName[j];

            switch (gTrainers[trainerNum].partyFlags)
            {
            case 0:
            {
                const struct TrainerMonNoItemDefaultMoves *partyData = gTrainers[trainerNum].party.NoItemDefaultMoves;

                for (j = 0; gSpeciesNames[partyData[i].species][j] != EOS; j++)
                    nameHash += gSpeciesNames[partyData[i].species][j];

                personalityValue += nameHash << 8;
                fixedIV = partyData[i].iv * 31 / 255;
				
				level = dynamicLevel(playerHighestLevel, partyData[i].lvl);
				CreateMon(&party[i], partyData[i].species, level, fixedIV, TRUE, personalityValue, OT_ID_RANDOM_NO_SHINY, 0);
				//CreateMon(&party[i], partyData[i].species, partyData[i].lvl, fixedIV, TRUE, personalityValue, OT_ID_RANDOM_NO_SHINY, 0);
                break;
            }
            case F_TRAINER_PARTY_CUSTOM_MOVESET:
            {
                const struct TrainerMonNoItemCustomMoves *partyData = gTrainers[trainerNum].party.NoItemCustomMoves;

                for (j = 0; gSpeciesNames[partyData[i].species][j] != EOS; j++)
                    nameHash += gSpeciesNames[partyData[i].species][j];

                personalityValue += nameHash << 8;
                fixedIV = partyData[i].iv * 31 / 255;
                
				level = dynamicLevel(playerHighestLevel, partyData[i].lvl);
				CreateMon(&party[i], partyData[i].species, level, fixedIV, TRUE, personalityValue, OT_ID_RANDOM_NO_SHINY, 0);
				// CreateMon(&party[i], partyData[i].species, partyData[i].lvl, fixedIV, TRUE, personalityValue, OT_ID_RANDOM_NO_SHINY, 0);

                for (j = 0; j < MAX_MON_MOVES; j++)
                {
                    SetMonData(&party[i], MON_DATA_MOVE1 + j, &partyData[i].moves[j]);
                    SetMonData(&party[i], MON_DATA_PP1 + j, &gBattleMoves[partyData[i].moves[j]].pp);
                }
                break;
            }
            case F_TRAINER_PARTY_HELD_ITEM:
            {
                const struct TrainerMonItemDefaultMoves *partyData = gTrainers[trainerNum].party.ItemDefaultMoves;

                for (j = 0; gSpeciesNames[partyData[i].species][j] != EOS; j++)
                    nameHash += gSpeciesNames[partyData[i].species][j];

                personalityValue += nameHash << 8;
                fixedIV = partyData[i].iv * 31 / 255;
            
				level = dynamicLevel(playerHighestLevel, partyData[i].lvl);
				CreateMon(&party[i], partyData[i].species, level, fixedIV, TRUE, personalityValue, OT_ID_RANDOM_NO_SHINY, 0);  
				// CreateMon(&party[i], partyData[i].species, partyData[i].lvl, fixedIV, TRUE, personalityValue, OT_ID_RANDOM_NO_SHINY, 0);

                SetMonData(&party[i], MON_DATA_HELD_ITEM, &partyData[i].heldItem);
                break;
            }
            case F_TRAINER_PARTY_CUSTOM_MOVESET | F_TRAINER_PARTY_HELD_ITEM:
            {
                const struct TrainerMonItemCustomMoves *partyData = gTrainers[trainerNum].party.ItemCustomMoves;

                for (j = 0; gSpeciesNames[partyData[i].species][j] != EOS; j++)
                    nameHash += gSpeciesNames[partyData[i].species][j];

                personalityValue += nameHash << 8;
                fixedIV = partyData[i].iv * 31 / 255;
				
				level = dynamicLevel(playerHighestLevel, partyData[i].lvl);
				CreateMon(&party[i], partyData[i].species, level, fixedIV, TRUE, personalityValue, OT_ID_RANDOM_NO_SHINY, 0);
                // CreateMon(&party[i], partyData[i].species, partyData[i].lvl, fixedIV, TRUE, personalityValue, OT_ID_RANDOM_NO_SHINY, 0);

                SetMonData(&party[i], MON_DATA_HELD_ITEM, &partyData[i].heldItem);

                for (j = 0; j < MAX_MON_MOVES; j++)
                {
                    SetMonData(&party[i], MON_DATA_MOVE1 + j, &partyData[i].moves[j]);
                    SetMonData(&party[i], MON_DATA_PP1 + j, &gBattleMoves[partyData[i].moves[j]].pp);
                }
                break;
            }
            }
            for (j = 0; gTrainerBallTable[j].classId != 0xFF; j++)
            {
                if (gTrainerBallTable[j].classId == gTrainers[trainerNum].trainerClass)
                    break;
            }
            SetMonData(&party[i], MON_DATA_POKEBALL, &gTrainerBallTable[j].Ball);
        }

        gBattleTypeFlags |= gTrainers[trainerNum].doubleBattle;
    }

    return gTrainers[trainerNum].partySize;
}

static u8 dynamicLevel(u8 playerHighestLevel, u8 standardLevel)
{
	
	u8 level;
	
	level = (int)((playerHighestLevel * 1.1) - 2);
	
	if (level < standardLevel)
		level = standardLevel;
	if (level > 100)
		level = 100;
	
	return level;
}

void VBlankCB_Battle(void)
// >