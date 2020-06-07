// <
    [ABILITY_LEVITATE] = 1,
	[ABILITY_FLUTTER] = 1,
    [ABILITY_LIGHTNING_ROD] = 1,
// >

// <
    else if (GetBattlerAbility(battlerId) == ABILITY_LEVITATE)
#R  else if (GetBattlerAbility(battlerId) == ABILITY_LEVITATE || GetBattlerAbility(battlerId) == ABILITY_FLUTTER)
        return FALSE;
// >

// <
    if (moveType == TYPE_GROUND && !IsBattlerGrounded(battlerDef))
    {
        modifier = UQ_4_12(0.0);
        if (recordAbilities && (GetBattlerAbility(battlerDef) == ABILITY_LEVITATE || GetBattlerAbility(battlerDef) == ABILITY_FLUTTER))
        {
            gLastUsedAbility = GetBattlerAbility(battlerDef);
            gMoveResultFlags |= (MOVE_RESULT_MISSED | MOVE_RESULT_DOESNT_AFFECT_FOE);
            gLastLandedMoves[battlerDef] = 0;
            gBattleCommunication[6] = moveType;
            RecordAbilityBattle(battlerDef, GetBattlerAbility(battlerDef));
        }
    }
// >

// <
        if (moveType == TYPE_GROUND && abilityDef == ABILITY_LEVITATE && !(gFieldStatuses & STATUS_FIELD_GRAVITY))
#R      if (moveType == TYPE_GROUND && (abilityDef == ABILITY_LEVITATE || abilityDef == ABILITY_FLUTTER) && !(gFieldStatuses & STATUS_FIELD_GRAVITY))
            modifier = UQ_4_12(0.0);
// >