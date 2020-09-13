< //
    if (gTrainers[gTrainerBattleOpponent_A].trainerClass == TRAINER_CLASS_CHAMPION)
        return B_TRANSITION_CHAMPION;
    
	if (gTrainers[gTrainerBattleOpponent_A].trainerClass == TRAINER_CLASS_MEWTWO)
        return B_TRANSITION_WHITEFADE;

    if (gTrainers[gTrainerBattleOpponent_A].trainerClass == TRAINER_CLASS_TEAM_MAGMA
// >

< //
    case SPECIES_LUGIA:
    case SPECIES_HO_OH:
        CreateBattleStartTask(B_TRANSITION_BLUR, MUS_RG_VS_DEN);
        break;
	case SPECIES_GYARADOS:
		CreateBattleStartTask(B_TRANSITION_WAVE, MUS_RG_VS_TORE);
        break;
    case SPECIES_MEW:
// >

< //
static u8 GetSumOfEnemyPartyLevel(u16 opponentId, u8 numMons)
{
    u8 i;
    u8 sum;
    u32 count = numMons;

    if (gTrainers[opponentId].partySize < count)
        count = gTrainers[opponentId].partySize;

    sum = 0;

    switch (gTrainers[opponentId].partyFlags)
    {
    case 0:
        {
            const struct TrainerMonNoItemDefaultMoves *party;
            party = gTrainers[opponentId].party.NoItemDefaultMoves;
            for (i = 0; i < count; i++)
                sum += party[i].lvl;
        }
        break;
    case F_TRAINER_PARTY_CUSTOM_MOVESET:
        {
            const struct TrainerMonNoItemCustomMoves *party;
            party = gTrainers[opponentId].party.NoItemCustomMoves;
            for (i = 0; i < count; i++)
                sum += party[i].lvl;
        }
        break;
    case F_TRAINER_PARTY_HELD_ITEM:
        {
            const struct TrainerMonItemDefaultMoves *party;
            party = gTrainers[opponentId].party.ItemDefaultMoves;
            for (i = 0; i < count; i++)
                sum += party[i].lvl;
        }
        break;
    case F_TRAINER_PARTY_CUSTOM_MOVESET | F_TRAINER_PARTY_HELD_ITEM:
        {
            const struct TrainerMonItemCustomMoves *party;
            party = gTrainers[opponentId].party.ItemCustomMoves;
            for (i = 0; i < count; i++)
                sum += party[i].lvl;
        }
        break;
	case F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_ABILITY:
		{    
			const struct TrainerMonItemDefaultMovesAbilityShiny *party;
			party = gTrainers[opponentId].party.ItemDefaultMovesAbilityShiny;
            for (i = 0; i < count; i++)
                sum += party[i].lvl;
		}
		break;
	case F_TRAINER_PARTY_CUSTOM_MOVESET | F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_ABILITY:
		{    
			const struct TrainerMonItemCustomMovesAbilityShiny *party;
			party = gTrainers[opponentId].party.ItemCustomMovesAbilityShiny;
            for (i = 0; i < count; i++)
                sum += party[i].lvl;
		}
		break;
	}

    return sum;
}

u8 GetWildBattleTransition(void)
// >