< //
    if (gTrainers[gTrainerBattleOpponent_A].trainerClass == TRAINER_CLASS_CHAMPION)
        return B_TRANSITION_CHAMPION;
    
	if (gTrainers[gTrainerBattleOpponent_A].trainerClass == TRAINER_CLASS_MEWTWO)
        return B_TRANSITION_WHITEFADE;

    if (gTrainers[gTrainerBattleOpponent_A].trainerClass == TRAINER_CLASS_TEAM_MAGMA
// >