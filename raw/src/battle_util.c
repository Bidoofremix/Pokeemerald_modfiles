< //
    [ABILITY_LEVITATE] = 1,
	[ABILITY_FLUTTER] = 1,
    [ABILITY_LIGHTNING_ROD] = 1,
// >

< //
    else if (GetBattlerAbility(battlerId) == ABILITY_LEVITATE)
#R  else if (GetBattlerAbility(battlerId) == ABILITY_LEVITATE || GetBattlerAbility(battlerId) == ABILITY_FLUTTER)
        return FALSE;
// >

< //
    case ABILITY_STRONG_JAW:
        if (gBattleMoves[move].flags & FLAG_STRONG_JAW_BOOST)
			// change Strong Jaw boost to 30%
			//MulModifier(&modifier, UQ_4_12(1.5));
           MulModifier(&modifier, UQ_4_12(1.3));
        break;
	case ABILITY_PUNK_ROCK:
		if (gBattleMoves[move].flags & FLAG_SOUND)
			MulModifier(&modifier, UQ_4_12(1.3));
		break;
    case ABILITY_MEGA_LAUNCHER:
// >

< //
    case ABILITY_DRY_SKIN:
        if (moveType == TYPE_FIRE)
            MulModifier(&modifier, UQ_4_12(1.25));
        break;
	case ABILITY_PUNK_ROCK:
		if (gBattleMoves[move].flags & FLAG_SOUND)
			MulModifier(&modifier, UQ_4_12(0.5));
    case ABILITY_FLUFFY:
// >

< //
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

< //
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

< //
    switch (GetBattlerHoldEffect(battlerAtk, TRUE))
    {
    case HOLD_EFFECT_THICK_CLUB:
        if ((gBattleMons[battlerAtk].species == SPECIES_CUBONE || gBattleMons[battlerAtk].species == SPECIES_MAROWAK || gBattleMons[battlerAtk].species == SPECIES_ALOLAN_MAROWAK) && IS_MOVE_PHYSICAL(move))
            MulModifier(&modifier, UQ_4_12(2.0));
        break;
    case HOLD_EFFECT_DEEP_SEA_TOOTH:
// >
	
< //
u8 TryWeatherFormChange(u8 battler)
{
    u8 ret = 0;
    bool32 weatherEffect = WEATHER_HAS_EFFECT;

    if (gBattleMons[battler].species == SPECIES_CASTFORM)
    {
        if (gBattleMons[battler].ability != ABILITY_FORECAST || gBattleMons[battler].hp == 0)
        {
            ret = 0;
        }
        else if (!weatherEffect && !IS_BATTLER_OF_TYPE(battler, TYPE_NORMAL))
        {
            SET_BATTLER_TYPE(battler, TYPE_NORMAL);
            ret = 1;
        }
        else if (!weatherEffect)
        {
            ret = 0;
        }
        else if (!(gBattleWeather & (WEATHER_RAIN_ANY | WEATHER_SUN_ANY | WEATHER_HAIL_ANY)) && !IS_BATTLER_OF_TYPE(battler, TYPE_NORMAL))
        {
            SET_BATTLER_TYPE(battler, TYPE_NORMAL);
            ret = 1;
        }
        else if (gBattleWeather & WEATHER_SUN_ANY && !IS_BATTLER_OF_TYPE(battler, TYPE_FIRE))
        {
            SET_BATTLER_TYPE(battler, TYPE_FIRE);
            ret = 2;
        }
        else if (gBattleWeather & WEATHER_RAIN_ANY && !IS_BATTLER_OF_TYPE(battler, TYPE_WATER))
        {
            SET_BATTLER_TYPE(battler, TYPE_WATER);
            ret = 3;
        }
        else if (gBattleWeather & WEATHER_HAIL_ANY && !IS_BATTLER_OF_TYPE(battler, TYPE_ICE))
        {
            SET_BATTLER_TYPE(battler, TYPE_ICE);
            ret = 4;
        }
    }
    // else if (gBattleMons[battler].species == SPECIES_CHERRIM)
    // {
        // if (gBattleMons[battler].ability != ABILITY_FLOWER_GIFT || gBattleMons[battler].hp == 0)
            // ret = 0;
        // else if (gBattleMonForms[battler] == 0 && weatherEffect && gBattleWeather & WEATHER_SUN_ANY)
            // ret = 2;
        // else if (gBattleMonForms[battler] != 0 && (!weatherEffect || !(gBattleWeather & WEATHER_SUN_ANY)))
            // ret = 1;
    // }

    return ret;
}

static const u16 sWeatherFlagsInfo[][3] =
// >

< //
static bool32 TryChangeBattleTerrain(u32 battler, u32 statusFlag, u8 *timer)
{
    if (!(gFieldStatuses & statusFlag))
    {
        gFieldStatuses &= ~(STATUS_FIELD_MISTY_TERRAIN | STATUS_FIELD_GRASSY_TERRAIN | EFFECT_ELECTRIC_TERRAIN | EFFECT_PSYCHIC_TERRAIN);
        gFieldStatuses |= statusFlag;

        if (GetBattlerHoldEffect(battler, TRUE) == HOLD_EFFECT_TERRAIN_EXTENDER)
            *timer = 8;
        else
            *timer = 5;

        gBattlerAttacker = gBattleScripting.battler = battler;
        return TRUE;
    }

    return FALSE;
}

static bool32 ShouldChangeFormHpBased(u32 battler)
{
    // Ability,     form >, form <=, hp divided
    // static const u16 forms[][4] =
    // {
        // {ABILITY_ZEN_MODE, SPECIES_DARMANITAN, SPECIES_DARMANITAN_ZEN, 2},
        // {ABILITY_SHIELDS_DOWN, SPECIES_MINIOR, SPECIES_MINIOR_CORE, 2},
        // {ABILITY_SCHOOLING, SPECIES_WISHIWASHI_SCHOOL, SPECIES_WISHIWASHI, 4},
    // };
    // u32 i;

    // for (i = 0; i < ARRAY_COUNT(forms); i++)
    // {
        // if (gBattleMons[battler].ability == forms[i][0])
        // {
            // if (gBattleMons[battler].species == forms[i][2]
                // && gBattleMons[battler].hp > gBattleMons[battler].maxHP / forms[i][3])
            // {
                // gBattleMons[battler].species = forms[i][1];
                // return TRUE;
            // }
            // if (gBattleMons[battler].species == forms[i][1]
                // && gBattleMons[battler].hp <= gBattleMons[battler].maxHP / forms[i][3])
            // {
                // gBattleMons[battler].species = forms[i][2];
                // return TRUE;
            // }
        // }
    // }
    return FALSE;
}

static u8 ForewarnChooseMove(u32 battler)
// >

< //
static u32 CalcMoveBasePowerAfterModifiers(u16 move, u8 battlerAtk, u8 battlerDef, u8 moveType, bool32 updateFlags)
{
    u32 i;
    u32 holdEffectAtk, holdEffectParamAtk;
    u16 basePower = CalcMoveBasePower(move, battlerAtk, battlerDef);
    u16 holdEffectModifier;
    u16 modifier = UQ_4_12(1.0);

    // attacker's abilities
    switch (GetBattlerAbility(battlerAtk))
    {
    case ABILITY_TECHNICIAN:
        if (basePower <= 60)
           MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case ABILITY_FLARE_BOOST:
        if (gBattleMons[battlerAtk].status1 & STATUS1_BURN && IS_MOVE_SPECIAL(move))
           MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case ABILITY_TOXIC_BOOST:
        if (gBattleMons[battlerAtk].status1 & STATUS1_PSN_ANY && IS_MOVE_PHYSICAL(move))
           MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case ABILITY_RECKLESS:
        if (gBattleMoves[move].flags & FLAG_RECKLESS_BOOST)
           MulModifier(&modifier, UQ_4_12(1.2));
        break;
    case ABILITY_IRON_FIST:
        if (gBattleMoves[move].flags & FLAG_IRON_FIST_BOOST)
           MulModifier(&modifier, UQ_4_12(1.2));
        break;
    case ABILITY_SHEER_FORCE:
        if (gBattleMoves[move].flags & FLAG_SHEER_FORCE_BOOST)
           MulModifier(&modifier, UQ_4_12(1.3));
        break;
    case ABILITY_SAND_FORCE:
        if (moveType == TYPE_STEEL || moveType == TYPE_ROCK || moveType == TYPE_GROUND)
           MulModifier(&modifier, UQ_4_12(1.3));
        break;
    case ABILITY_RIVALRY:
        if (GetGenderFromSpeciesAndPersonality(gBattleMons[battlerAtk].species, gBattleMons[battlerAtk].personality) != MON_GENDERLESS
            && GetGenderFromSpeciesAndPersonality(gBattleMons[battlerDef].species, gBattleMons[battlerDef].personality) != MON_GENDERLESS)
        {
            if (GetGenderFromSpeciesAndPersonality(gBattleMons[battlerAtk].species, gBattleMons[battlerAtk].personality)
             == GetGenderFromSpeciesAndPersonality(gBattleMons[battlerDef].species, gBattleMons[battlerDef].personality))
               MulModifier(&modifier, UQ_4_12(1.25));
            else
               MulModifier(&modifier, UQ_4_12(0.75));
        }
        break;
    case ABILITY_ANALYTIC:
        if (GetBattlerTurnOrderNum(battlerAtk) == gBattlersCount - 1 && move != MOVE_FUTURE_SIGHT && move != MOVE_DOOM_DESIRE)
           MulModifier(&modifier, UQ_4_12(1.3));
        break;
    case ABILITY_TOUGH_CLAWS:
        if (gBattleMoves[move].flags & FLAG_MAKES_CONTACT)
           MulModifier(&modifier, UQ_4_12(1.3));
        break;
    case ABILITY_STRONG_JAW:
        if (gBattleMoves[move].flags & FLAG_STRONG_JAW_BOOST)
           MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case ABILITY_MEGA_LAUNCHER:
        if (gBattleMoves[move].flags & FLAG_MEGA_LAUNCHER_BOOST)
           MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case ABILITY_WATER_BUBBLE:
        if (moveType == TYPE_WATER)
           MulModifier(&modifier, UQ_4_12(2.0));
        break;
    case ABILITY_STEELWORKER:
        if (moveType == TYPE_STEEL)
           MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case ABILITY_PIXILATE:
        if (moveType == TYPE_FAIRY && gBattleStruct->ateBoost[battlerAtk])
            MulModifier(&modifier, UQ_4_12(1.2));
        break;
    case ABILITY_GALVANIZE:
        if (moveType == TYPE_ELECTRIC && gBattleStruct->ateBoost[battlerAtk])
            MulModifier(&modifier, UQ_4_12(1.2));
        break;
    case ABILITY_REFRIGERATE:
        if (moveType == TYPE_ICE && gBattleStruct->ateBoost[battlerAtk])
            MulModifier(&modifier, UQ_4_12(1.2));
        break;
    case ABILITY_AERILATE:
        if (moveType == TYPE_FLYING && gBattleStruct->ateBoost[battlerAtk])
            MulModifier(&modifier, UQ_4_12(1.2));
        break;
    case ABILITY_NORMALIZE:
        if (moveType == TYPE_NORMAL && gBattleStruct->ateBoost[battlerAtk])
            MulModifier(&modifier, UQ_4_12(1.2));
        break;
    }

    // field abilities
    if ((IsAbilityOnField(ABILITY_DARK_AURA) && moveType == TYPE_DARK)
        || (IsAbilityOnField(ABILITY_FAIRY_AURA) && moveType == TYPE_FAIRY))
    {
        if (IsAbilityOnField(ABILITY_AURA_BREAK))
            MulModifier(&modifier, UQ_4_12(0.75));
        else
            MulModifier(&modifier, UQ_4_12(1.25));
    }

    // attacker partner's abilities
    if (IsBattlerAlive(BATTLE_PARTNER(battlerAtk)))
    {
        switch (GetBattlerAbility(BATTLE_PARTNER(battlerAtk)))
        {
        case ABILITY_BATTERY:
            if (IS_MOVE_SPECIAL(move))
                MulModifier(&modifier, UQ_4_12(1.3));
            break;
        }
    }

    // target's abilities
    switch (GetBattlerAbility(battlerDef))
    {
    case ABILITY_HEATPROOF:
    case ABILITY_WATER_BUBBLE:
        if (moveType == TYPE_FIRE)
            MulModifier(&modifier, UQ_4_12(0.5));
        break;
    case ABILITY_DRY_SKIN:
        if (moveType == TYPE_FIRE)
            MulModifier(&modifier, UQ_4_12(1.25));
        break;
    case ABILITY_FLUFFY:
        if (IsMoveMakingContact(move, battlerAtk))
            MulModifier(&modifier, UQ_4_12(0.5));
        if (moveType == TYPE_FIRE)
            MulModifier(&modifier, UQ_4_12(2.0));
        break;
    }

    holdEffectAtk = GetBattlerHoldEffect(battlerAtk, TRUE);
    holdEffectParamAtk = GetBattlerHoldEffectParam(battlerAtk);
    if (holdEffectParamAtk > 100)
        holdEffectParamAtk = 100;

    holdEffectModifier = UQ_4_12(1.0) + sPercentToModifier[holdEffectParamAtk];

    // attacker's hold effect
    switch (holdEffectAtk)
    {
    case HOLD_EFFECT_MUSCLE_BAND:
        if (IS_MOVE_PHYSICAL(move))
            MulModifier(&modifier, holdEffectModifier);
        break;
    case HOLD_EFFECT_WISE_GLASSES:
        if (IS_MOVE_SPECIAL(move))
            MulModifier(&modifier, holdEffectModifier);
        break;
    // case HOLD_EFFECT_LUSTROUS_ORB:
        // if (gBattleMons[battlerAtk].species == SPECIES_PALKIA && (moveType == TYPE_WATER || moveType == TYPE_DRAGON))
            // MulModifier(&modifier, holdEffectModifier);
        // break;
    // case HOLD_EFFECT_ADAMANT_ORB:
        // if (gBattleMons[battlerAtk].species == SPECIES_DIALGA && (moveType == TYPE_STEEL || moveType == TYPE_DRAGON))
            // MulModifier(&modifier, holdEffectModifier);
        // break;
    // case HOLD_EFFECT_GRISEOUS_ORB:
        // if (gBattleMons[battlerAtk].species == SPECIES_GIRATINA && (moveType == TYPE_GHOST || moveType == TYPE_DRAGON))
            // MulModifier(&modifier, holdEffectModifier);
        // break;
    case HOLD_EFFECT_SOUL_DEW:
        if ((gBattleMons[battlerAtk].species == SPECIES_LATIAS || gBattleMons[battlerAtk].species == SPECIES_LATIOS) && !(gBattleTypeFlags & BATTLE_TYPE_FRONTIER))
            MulModifier(&modifier, holdEffectModifier);
        break;
    case HOLD_EFFECT_GEMS:
        if (gSpecialStatuses[battlerAtk].gemBoost && gBattleMons[battlerAtk].item)
            MulModifier(&modifier, UQ_4_12(1.0) + sPercentToModifier[gSpecialStatuses[battlerAtk].gemParam]);
        break;
    case HOLD_EFFECT_BUG_POWER:
    case HOLD_EFFECT_STEEL_POWER:
    case HOLD_EFFECT_GROUND_POWER:
    case HOLD_EFFECT_ROCK_POWER:
    case HOLD_EFFECT_GRASS_POWER:
    case HOLD_EFFECT_DARK_POWER:
    case HOLD_EFFECT_FIGHTING_POWER:
    case HOLD_EFFECT_ELECTRIC_POWER:
    case HOLD_EFFECT_WATER_POWER:
    case HOLD_EFFECT_FLYING_POWER:
    case HOLD_EFFECT_POISON_POWER:
    case HOLD_EFFECT_ICE_POWER:
    case HOLD_EFFECT_GHOST_POWER:
    case HOLD_EFFECT_PSYCHIC_POWER:
    case HOLD_EFFECT_FIRE_POWER:
    case HOLD_EFFECT_DRAGON_POWER:
    case HOLD_EFFECT_NORMAL_POWER:
    case HOLD_EFFECT_FAIRY_POWER:
        for (i = 0; i < ARRAY_COUNT(sHoldEffectToType); i++)
        {
            if (holdEffectAtk == sHoldEffectToType[i][0])
            {
                if (moveType == sHoldEffectToType[i][1])
                    MulModifier(&modifier, holdEffectModifier);
                break;
            }
        }
        break;
    }

    // move effect
    switch (gBattleMoves[move].effect)
    {
    case EFFECT_FACADE:
        if (gBattleMons[battlerAtk].status1 & (STATUS1_BURN | STATUS1_PSN_ANY | STATUS1_PARALYSIS))
            MulModifier(&modifier, UQ_4_12(2.0));
        break;
    case EFFECT_BRINE:
        if (gBattleMons[battlerDef].hp <= (gBattleMons[battlerDef].maxHP / 2))
            MulModifier(&modifier, UQ_4_12(2.0));
        break;
    case EFFECT_VENOSHOCK:
        if (gBattleMons[battlerAtk].status1 & STATUS1_PSN_ANY)
            MulModifier(&modifier, UQ_4_12(2.0));
        break;
    case EFFECT_RETALITATE:
        // todo
        break;
    case EFFECT_SOLARBEAM:
        if (WEATHER_HAS_EFFECT && gBattleWeather & (WEATHER_HAIL_ANY | WEATHER_SANDSTORM_ANY | WEATHER_RAIN_ANY))
            MulModifier(&modifier, UQ_4_12(0.5));
        break;
    case EFFECT_STOMPING_TANTRUM:
        if (gBattleStruct->lastMoveFailed & gBitTable[battlerAtk])
            MulModifier(&modifier, UQ_4_12(2.0));
        break;
    case EFFECT_BULLDOZE:
    case EFFECT_MAGNITUDE:
    case EFFECT_EARTHQUAKE:
        if (gFieldStatuses & STATUS_FIELD_GRASSY_TERRAIN && !(gStatuses3[battlerDef] & STATUS3_SEMI_INVULNERABLE))
            MulModifier(&modifier, UQ_4_12(0.5));
        break;
    case EFFECT_KNOCK_OFF:
        if (gBattleMons[battlerDef].item != ITEM_NONE && GetBattlerAbility(battlerDef) != ABILITY_STICKY_HOLD)
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
    }

    // various effecs
    if (gProtectStructs[battlerAtk].helpingHand)
        MulModifier(&modifier, UQ_4_12(1.5));
    if (gStatuses3[battlerAtk] & STATUS3_CHARGED_UP && moveType == TYPE_ELECTRIC)
        MulModifier(&modifier, UQ_4_12(2.0));
    if (gStatuses3[battlerAtk] & STATUS3_ME_FIRST)
        MulModifier(&modifier, UQ_4_12(1.5));
    if (gFieldStatuses & STATUS_FIELD_GRASSY_TERRAIN && moveType == TYPE_GRASS && IsBattlerGrounded(battlerAtk) && !(gStatuses3[battlerAtk] & STATUS3_SEMI_INVULNERABLE))
        MulModifier(&modifier, (B_TERRAIN_TYPE_BOOST >= GEN_8) ? UQ_4_12(1.3) : UQ_4_12(1.5));
    if (gFieldStatuses & STATUS_FIELD_MISTY_TERRAIN && moveType == TYPE_DRAGON && IsBattlerGrounded(battlerDef) && !(gStatuses3[battlerDef] & STATUS3_SEMI_INVULNERABLE))
        MulModifier(&modifier, UQ_4_12(0.5));
    if (gFieldStatuses & STATUS_FIELD_ELECTRIC_TERRAIN && moveType == TYPE_ELECTRIC && IsBattlerGrounded(battlerAtk) && !(gStatuses3[battlerAtk] & STATUS3_SEMI_INVULNERABLE))
        MulModifier(&modifier, (B_TERRAIN_TYPE_BOOST >= GEN_8) ? UQ_4_12(1.3) : UQ_4_12(1.5));
    if (gFieldStatuses & STATUS_FIELD_PSYCHIC_TERRAIN && moveType == TYPE_PSYCHIC && IsBattlerGrounded(battlerAtk) && !(gStatuses3[battlerAtk] & STATUS3_SEMI_INVULNERABLE))
        MulModifier(&modifier, (B_TERRAIN_TYPE_BOOST >= GEN_8) ? UQ_4_12(1.3) : UQ_4_12(1.5));

    return ApplyModifier(modifier, basePower);
}

static u32 CalcAttackStat(u16 move, u8 battlerAtk, u8 battlerDef, u8 moveType, bool32 isCrit, bool32 updateFlags)
{
    u8 atkStage;
    u32 atkStat;
    u16 modifier;

    if (gBattleMoves[move].effect == EFFECT_FOUL_PLAY)
    {
        if (IS_MOVE_PHYSICAL(move))
        {
            atkStat = gBattleMons[battlerDef].attack;
            atkStage = gBattleMons[battlerDef].statStages[STAT_ATK];
        }
        else
        {
            atkStat = gBattleMons[battlerDef].spAttack;
            atkStage = gBattleMons[battlerDef].statStages[STAT_SPATK];
        }
    }
    else
    {
        if (IS_MOVE_PHYSICAL(move))
        {
            atkStat = gBattleMons[battlerAtk].attack;
            atkStage = gBattleMons[battlerAtk].statStages[STAT_ATK];
        }
        else
        {
            atkStat = gBattleMons[battlerAtk].spAttack;
            atkStage = gBattleMons[battlerAtk].statStages[STAT_SPATK];
        }
    }

    // critical hits ignore attack stat's stage drops
    if (isCrit && atkStage < 6)
        atkStage = 6;
    // pokemon with unaware ignore attack stat changes while taking damage
    if (GetBattlerAbility(battlerDef) == ABILITY_UNAWARE)
        atkStage = 6;

    atkStat *= gStatStageRatios[atkStage][0];
    atkStat /= gStatStageRatios[atkStage][1];

    // apply attack stat modifiers
    modifier = UQ_4_12(1.0);

    // attacker's abilities
    switch (GetBattlerAbility(battlerAtk))
    {
    case ABILITY_HUGE_POWER:
    case ABILITY_PURE_POWER:
        if (IS_MOVE_PHYSICAL(move))
            MulModifier(&modifier, UQ_4_12(2.0));
        break;
    case ABILITY_SLOW_START:
        if (gDisableStructs[battlerAtk].slowStartTimer != 0)
            MulModifier(&modifier, UQ_4_12(0.5));
        break;
    case ABILITY_SOLAR_POWER:
        if (IS_MOVE_SPECIAL(move) && WEATHER_HAS_EFFECT && gBattleWeather & WEATHER_SUN_ANY)
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case ABILITY_DEFEATIST:
        if (gBattleMons[battlerAtk].hp <= (gBattleMons[battlerDef].maxHP / 2))
            MulModifier(&modifier, UQ_4_12(0.5));
        break;
    case ABILITY_FLASH_FIRE:
        if (moveType == TYPE_FIRE && gBattleResources->flags->flags[battlerAtk] & RESOURCE_FLAG_FLASH_FIRE)
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case ABILITY_SWARM:
        if (moveType == TYPE_BUG && gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case ABILITY_TORRENT:
        if (moveType == TYPE_WATER && gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case ABILITY_BLAZE:
        if (moveType == TYPE_FIRE && gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case ABILITY_OVERGROW:
        if (moveType == TYPE_GRASS && gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case ABILITY_PLUS:
    case ABILITY_MINUS:
        if (IsBattlerAlive(BATTLE_PARTNER(battlerAtk)))
        {
            u32 partnerAbility = GetBattlerAbility(BATTLE_PARTNER(battlerAtk));
            if (partnerAbility == ABILITY_PLUS || partnerAbility == ABILITY_MINUS)
                MulModifier(&modifier, UQ_4_12(1.5));
        }
        break;
    case ABILITY_FLOWER_GIFT:
        //
		break;
    case ABILITY_HUSTLE:
        if (IS_MOVE_PHYSICAL(move))
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case ABILITY_STAKEOUT:
        if (gDisableStructs[battlerDef].isFirstTurn == 2) // just switched in
            MulModifier(&modifier, UQ_4_12(2.0));
        break;
    }

    // target's abilities
    switch (GetBattlerAbility(battlerDef))
    {
    case ABILITY_THICK_FAT:
        if (moveType == TYPE_FIRE || moveType == TYPE_ICE)
        {
            MulModifier(&modifier, UQ_4_12(0.5));
            if (updateFlags)
                RecordAbilityBattle(battlerDef, ABILITY_THICK_FAT);
        }
        break;
    }

    // ally's abilities
    if (IsBattlerAlive(BATTLE_PARTNER(battlerAtk)))
    {
        switch (GetBattlerAbility(BATTLE_PARTNER(battlerAtk)))
        {
        case ABILITY_FLOWER_GIFT:
            //if (gBattleMons[BATTLE_PARTNER(battlerAtk)].species == SPECIES_CHERRIM)
            //MulModifier(&modifier, UQ_4_12(1.5));
            break;
        }
    }

    // attacker's hold effect
    switch (GetBattlerHoldEffect(battlerAtk, TRUE))
    {
    case HOLD_EFFECT_THICK_CLUB:
        if ((gBattleMons[battlerAtk].species == SPECIES_CUBONE || gBattleMons[battlerAtk].species == SPECIES_MAROWAK) && IS_MOVE_PHYSICAL(move))
            MulModifier(&modifier, UQ_4_12(2.0));
        break;
    case HOLD_EFFECT_DEEP_SEA_TOOTH:
        if (gBattleMons[battlerAtk].species == SPECIES_CLAMPERL && IS_MOVE_SPECIAL(move))
            MulModifier(&modifier, UQ_4_12(2.0));
        break;
    case HOLD_EFFECT_LIGHT_BALL:
        if (gBattleMons[battlerAtk].species == SPECIES_PIKACHU)
            MulModifier(&modifier, UQ_4_12(2.0));
        break;
    case HOLD_EFFECT_CHOICE_BAND:
        if (IS_MOVE_PHYSICAL(move))
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case HOLD_EFFECT_CHOICE_SPECS:
        if (IS_MOVE_SPECIAL(move))
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
    }

    return ApplyModifier(modifier, atkStat);
}

static bool32 CanEvolve(u32 species)

{
    u32 i;

    for (i = 0; i < EVOS_PER_MON; i++)
    {
        if (gEvolutionTable[species][i].method && gEvolutionTable[species][i].method != EVO_MEGA_EVOLUTION)
            return TRUE;
    }
    return FALSE;
}

static u32 CalcDefenseStat(u16 move, u8 battlerAtk, u8 battlerDef, u8 moveType, bool32 isCrit, bool32 updateFlags)
{
    bool32 usesDefStat;
    u8 defStage;
    u32 defStat, def, spDef;
    u16 modifier;

    if (gFieldStatuses & STATUS_FIELD_WONDER_ROOM) // the defense stats are swapped
    {
        def = gBattleMons[battlerDef].spDefense;
        spDef = gBattleMons[battlerDef].defense;
    }
    else
    {
        def = gBattleMons[battlerDef].defense;
        spDef = gBattleMons[battlerDef].spDefense;
    }

    if (gBattleMoves[move].effect == EFFECT_PSYSHOCK || IS_MOVE_PHYSICAL(move)) // uses defense stat instead of sp.def
    {
        defStat = def;
        defStage = gBattleMons[battlerDef].statStages[STAT_DEF];
        usesDefStat = TRUE;
    }
    else // is special
    {
        defStat = spDef;
        defStage = gBattleMons[battlerDef].statStages[STAT_SPDEF];
        usesDefStat = FALSE;
    }

    // critical hits ignore positive stat changes
    if (isCrit && defStage > 6)
        defStage = 6;
    // pokemon with unaware ignore defense stat changes while dealing damage
    if (GetBattlerAbility(battlerAtk) == ABILITY_UNAWARE)
        defStage = 6;
    // certain moves also ignore stat changes
    if (gBattleMoves[move].flags & FLAG_STAT_STAGES_IGNORED)
        defStage = 6;

    defStat *= gStatStageRatios[defStage][0];
    defStat /= gStatStageRatios[defStage][1];

    // apply defense stat modifiers
    modifier = UQ_4_12(1.0);

    // target's abilities
    switch (GetBattlerAbility(battlerDef))
    {
    case ABILITY_MARVEL_SCALE:
        if (gBattleMons[battlerDef].status1 & STATUS1_ANY && usesDefStat)
        {
            MulModifier(&modifier, UQ_4_12(1.5));
            if (updateFlags)
                RecordAbilityBattle(battlerDef, ABILITY_MARVEL_SCALE);
        }
        break;
    case ABILITY_FUR_COAT:
        if (usesDefStat)
        {
            MulModifier(&modifier, UQ_4_12(2.0));
            if (updateFlags)
                RecordAbilityBattle(battlerDef, ABILITY_FUR_COAT);
        }
        break;
    case ABILITY_GRASS_PELT:
        if (gFieldStatuses & STATUS_FIELD_GRASSY_TERRAIN && usesDefStat)
        {
            MulModifier(&modifier, UQ_4_12(1.5));
            if (updateFlags)
                RecordAbilityBattle(battlerDef, ABILITY_GRASS_PELT);
        }
        break;
    // case ABILITY_FLOWER_GIFT:
        // if (gBattleMons[battlerDef].species == SPECIES_CHERRIM && WEATHER_HAS_EFFECT && gBattleWeather & WEATHER_SUN_ANY && !usesDefStat)
            // MulModifier(&modifier, UQ_4_12(1.5));
        // break;
    }

    // ally's abilities
    // if (IsBattlerAlive(BATTLE_PARTNER(battlerDef)))
    // {
        // switch (GetBattlerAbility(BATTLE_PARTNER(battlerDef)))
        // {
        // case ABILITY_FLOWER_GIFT:
            // if (gBattleMons[BATTLE_PARTNER(battlerDef)].species == SPECIES_CHERRIM && !usesDefStat)
                // MulModifier(&modifier, UQ_4_12(1.5));
            // break;
        // }
    // }

    // target's hold effects
    switch (GetBattlerHoldEffect(battlerDef, TRUE))
    {
    case HOLD_EFFECT_DEEP_SEA_SCALE:
        if (gBattleMons[battlerDef].species == SPECIES_CLAMPERL && !usesDefStat)
            MulModifier(&modifier, UQ_4_12(2.0));
        break;
    case HOLD_EFFECT_METAL_POWDER:
        if (gBattleMons[battlerDef].species == SPECIES_DITTO && usesDefStat && !(gBattleMons[battlerDef].status2 & STATUS2_TRANSFORMED))
            MulModifier(&modifier, UQ_4_12(2.0));
        break;
    case HOLD_EFFECT_EVIOLITE:
        if (CanEvolve(gBattleMons[battlerDef].species))
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case HOLD_EFFECT_ASSAULT_VEST:
        if (!usesDefStat)
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
    }

    // sandstorm sp.def boost for rock types
    if (IS_BATTLER_OF_TYPE(battlerDef, TYPE_ROCK) && WEATHER_HAS_EFFECT && gBattleWeather & WEATHER_SANDSTORM_ANY && !usesDefStat)
        MulModifier(&modifier, UQ_4_12(1.5));

    return ApplyModifier(modifier, defStat);
}

static u32 CalcFinalDmg(u32 dmg, u16 move, u8 battlerAtk, u8 battlerDef, u8 moveType, u16 typeEffectivenessModifier, bool32 isCrit, bool32 updateFlags)
// >

< //
void UndoMegaEvolution(u32 monId)
{
    if (gBattleStruct->mega.evolvedPartyIds[B_SIDE_PLAYER] & gBitTable[monId])
    {
        gBattleStruct->mega.evolvedPartyIds[B_SIDE_PLAYER] &= ~(gBitTable[monId]);
        SetMonData(&gPlayerParty[monId], MON_DATA_SPECIES, &gBattleStruct->mega.playerEvolvedSpecies);
        CalculateMonStats(&gPlayerParty[monId]);
    }
}

void UndoFormChange(u32 monId, u32 side)
{
    u32 i, currSpecies;
    // struct Pokemon *party = (side == B_SIDE_PLAYER) ? gPlayerParty : gEnemyParty;
    // static const u16 species[][2] = // changed form id, default form id
    // {
        // {SPECIES_AEGISLASH_BLADE, SPECIES_AEGISLASH},
        // {SPECIES_MIMIKYU_BUSTED, SPECIES_MIMIKYU},
        // {SPECIES_DARMANITAN_ZEN, SPECIES_DARMANITAN},
        // {SPECIES_MINIOR, SPECIES_MINIOR_CORE},
        // {SPECIES_WISHIWASHI_SCHOOL, SPECIES_WISHIWASHI},
    // };

    // currSpecies = GetMonData(&party[monId], MON_DATA_SPECIES, NULL);
    // for (i = 0; i < ARRAY_COUNT(species); i++)
    // {
        // if (currSpecies == species[i][0])
        // {
            // SetMonData(&party[monId], MON_DATA_SPECIES, &species[i][1]);
            // CalculateMonStats(&party[monId]);
            // break;
        // }
    // }
}

bool32 DoBattlersShareType(u32 battler1, u32 battler2)
{
    s32 i;
    u8 types1[3] = {gBattleMons[battler1].type1, gBattleMons[battler1].type2, gBattleMons[battler1].type3};
    u8 types2[3] = {gBattleMons[battler2].type1, gBattleMons[battler2].type2, gBattleMons[battler2].type3};

    if (types1[2] == TYPE_MYSTERY)
        types1[2] = types1[0];
    if (types2[2] == TYPE_MYSTERY)
        types2[2] = types2[0];

    for (i = 0; i < 3; i++)
    {
        if (types1[i] == types2[0] || types1[i] == types2[1] || types1[i] == types2[2])
            return TRUE;
    }

    return FALSE;
}

bool32 CanBattlerGetOrLoseItem(u8 battlerId, u16 itemId)
{
    u16 species = gBattleMons[battlerId].species;

    if (IS_ITEM_MAIL(itemId))
        return FALSE;
    else if (itemId == ITEM_ENIGMA_BERRY)
        return FALSE;
    else if (species == SPECIES_KYOGRE && itemId == ITEM_BLUE_ORB)
        return FALSE;
    else if (species == SPECIES_GROUDON && itemId == ITEM_RED_ORB)
        return FALSE;
    // Mega stone cannot be lost if pokemon can mega evolve with it or is already mega evolved.
    else if (ItemId_GetHoldEffect(itemId) == HOLD_EFFECT_MEGA_STONE
             && ((GetMegaEvolutionSpecies(species, itemId) != SPECIES_NONE) || gBattleStruct->mega.evolvedPartyIds[GetBattlerSide(battlerId)] & gBitTable[gBattlerPartyIndexes[battlerId]]))
        return FALSE;
    // else if (species == SPECIES_GIRATINA && itemId == ITEM_GRISEOUS_ORB)
        // return FALSE;
    // else if (species == SPECIES_GENESECT && GetBattlerHoldEffect(battlerId, FALSE) == HOLD_EFFECT_DRIVE)
        // return FALSE;
    // else if (species == SPECIES_SILVALLY && GetBattlerHoldEffect(battlerId, FALSE) == HOLD_EFFECT_MEMORY)
        // return FALSE;
    else
        return TRUE;
}

struct Pokemon *GetIllusionMonPtr(u32 battlerId)
// >

< //
            case ABILITY_POWER_CONSTRUCT:
                // if ((gBattleMons[battler].species == SPECIES_ZYGARDE || gBattleMons[battler].species == SPECIES_ZYGARDE_10)
                    // && gBattleMons[battler].hp <= gBattleMons[battler].maxHP / 2)
                // {
                    // gBattleStruct->changedSpecies[gBattlerPartyIndexes[battler]] = gBattleMons[battler].species;
                    // gBattleMons[battler].species = SPECIES_ZYGARDE_COMPLETE;
                    // BattleScriptPushCursorAndCallback(BattleScript_AttackerFormChangeEnd3);
                    // effect++;
                // }
                // break;
            }
        }
        break;
    case ABILITYEFFECT_MOVES_BLOCK: // 2
// >