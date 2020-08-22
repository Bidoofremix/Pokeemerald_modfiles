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