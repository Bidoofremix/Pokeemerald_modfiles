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

< //
    if (HasObedientBitSet(gBattlerAttacker)) // only if species is Mew or Deoxys
    {
        if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && GetBattlerPosition(gBattlerAttacker) == 2)
            return 0;
        if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
            return 0;
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            return 0;
        if (!IsOtherTrainer(gBattleMons[gBattlerAttacker].otId, gBattleMons[gBattlerAttacker].otName))
            return 0;
        if (FlagGet(FLAG_BADGE08_GET))
            return 0;

        obedienceLevel = 10;

        if (FlagGet(FLAG_BADGE01_GET))
            obedienceLevel = 20;
        if (FlagGet(FLAG_BADGE02_GET))
            obedienceLevel = 30;
        if (FlagGet(FLAG_BADGE03_GET))
            obedienceLevel = 40;
        if (FlagGet(FLAG_BADGE04_GET))
            obedienceLevel = 50;
        if (FlagGet(FLAG_BADGE05_GET))
            obedienceLevel = 60;
        if (FlagGet(FLAG_BADGE06_GET))
            obedienceLevel = 70;
        if (FlagGet(FLAG_BADGE07_GET))
            obedienceLevel = 80;
    }

    if (gBattleMons[gBattlerAttacker].level <= obedienceLevel)
// >