< //
            case MOVE_EFFECT_PAYDAY:
                if (GET_BATTLER_SIDE(gBattlerAttacker) == B_SIDE_PLAYER)
                {
                    u16 PayDay = gPaydayMoney;
					
					// more payday money with ability bonanza
					if (gBattleMons[gBattlerAttacker].ability != ABILITY_BONANZA)
					{
						gPaydayMoney += (gBattleMons[gBattlerAttacker].level * 5);
                    }
					else
					{
						gPaydayMoney += (gBattleMons[gBattlerAttacker].level * 10);
					}
                    
					if (PayDay > gPaydayMoney)
                        gPaydayMoney = 0xFFFF;
                }
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = sMoveEffectBS_Ptrs[gBattleScripting.moveEffect];
                break;
            case MOVE_EFFECT_HAPPY_HOUR:
// >

< //
static const u8 sPickupProbabilities[] =
{
    30, 40, 50, 60, 70, 80, 90, 94, 98
};

static const u16 sBonanzaItems[] =
{
    ITEM_SUPER_POTION,
    ITEM_FULL_HEAL,
    ITEM_HYPER_POTION,
    ITEM_GREAT_BALL,
    ITEM_SUPER_REPEL,
    ITEM_ESCAPE_ROPE,
    ITEM_MAX_REPEL,
    ITEM_REVIVE,
    ITEM_ULTRA_BALL,
    ITEM_MAX_POTION,
    ITEM_RARE_CANDY,
    ITEM_PROTEIN,
    ITEM_MAX_REVIVE,
    ITEM_HP_UP,
    ITEM_FULL_RESTORE,
    ITEM_MAX_REVIVE,
    ITEM_PP_MAX,
    ITEM_MAX_ELIXIR,
};

static const u16 sRareBonanzaItems[] =
{
    ITEM_MAX_POTION,
    ITEM_NUGGET,
    ITEM_KINGS_ROCK,
    ITEM_FULL_RESTORE,
    ITEM_DUSK_STONE,
    ITEM_RAZOR_CLAW,
    ITEM_DAWN_STONE,
    ITEM_ICE_STONE,
    ITEM_SHINY_STONE,
    ITEM_LEFTOVERS,
    ITEM_MASTER_BALL,
};
static const u8 sTerrainToType[] =
// >

< //
            lvlDivBy10 = (GetMonData(&gPlayerParty[i], MON_DATA_LEVEL)-1) / 10; //Moving this here makes it easier to add in abilities like Honey Gather
            if (lvlDivBy10 > 9)
                lvlDivBy10 = 9;

			// with the addition of hidden abilities, nums 0, 1 and 2 exist
            if (GetMonData(&gPlayerParty[i], MON_DATA_ABILITY_NUM) == 2)
			{
                ability = gBaseStats[species].abilityHidden;
			}
            else if (GetMonData(&gPlayerParty[i], MON_DATA_ABILITY_NUM) == 1)
			{
                ability = gBaseStats[species].abilities[1];
			}
			else
			{
				ability = gBaseStats[species].abilities[0];
			}

            if (ability == ABILITY_PICKUP
                && species != 0
                && species != SPECIES_EGG
                && heldItem == ITEM_NONE
                && (Random() % 10) == 0)
            {
                s32 j;
                s32 rand = Random() % 100;

                for (j = 0; j < (int)ARRAY_COUNT(sPickupProbabilities); j++)
                {
                    if (sPickupProbabilities[j] > rand)
                    {
                        SetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM, &sPickupItems[lvlDivBy10 + j]);
                        break;
                    }
                    else if (rand == 99 || rand == 98)
                    {
                        SetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM, &sRarePickupItems[lvlDivBy10 + (99 - rand)]);
                        break;
                    }
                }
            }
			else if (ability == ABILITY_BONANZA
                && species != 0
                && species != SPECIES_EGG
                && heldItem == ITEM_NONE
                && (Random() % 10) == 0)
            {
                s32 j;
                s32 rand = Random() % 100;

                for (j = 0; j < (int)ARRAY_COUNT(sPickupProbabilities); j++)
                {
                    if (sPickupProbabilities[j] > rand)
                    {
                        SetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM, &sBonanzaItems[lvlDivBy10 + j]);
                        break;
                    }
                    else if (rand == 99 || rand == 98)
                    {
                        SetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM, &sRareBonanzaItems[lvlDivBy10 + (99 - rand)]);
                        break;
                    }
                }
            }
            #if (defined ITEM_HONEY)
            else if (ability == ABILITY_HONEY_GATHER
// >

< //
            case ITEM_QUICK_BALL:
                if (gBattleResults.battleTurnCounter == 0)
                    ballMultiplier = 40;
                break;
		    case ITEM_IGNIS_BALL:
                if (IS_BATTLER_OF_TYPE(gBattlerTarget, TYPE_FIRE) || IS_BATTLER_OF_TYPE(gBattlerTarget, TYPE_DRAGON))
                    ballMultiplier = 30;
                else
                    ballMultiplier = 10;
                break;
			case ITEM_CLONE_BALL:
                ballMultiplier = 10;
                break;
			case ITEM_DREAM_BALL:
				if (gBattleMons[gBattlerTarget].status1 & (STATUS1_SLEEP))
                    ballMultiplier = 40;
				else
					ballMultiplier = 10;
                break;
            case ITEM_DUSK_BALL:
// >

< //
#define MON_ICON_LVLUP_BOX_TAG      0xD75A
#define EXP_A 184
#define EXP_C 16249
	
static const struct OamData sOamData_MonIconOnLvlUpBox =
// >

< //
static void Cmd_jumpbasedontype(void);
static float cubed(float y);
static void Cmd_getexp(void);
// >

< //
static void Cmd_getexp(void)
#Rfloat cubed(float y)
{
  return y*y*y;
}

static void Cmd_getexp(void)
{
    u16 item;
    s32 i; // also used as stringId
    u8 holdEffect;
    s32 sentIn;
    s32 viaExpShare = 0;
    u16 *exp = &gBattleStruct->expValue;

    gBattlerFainted = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);
    sentIn = gSentPokesToOpponent[(gBattlerFainted & 2) >> 1];

    switch (gBattleScripting.getexpState)
    {
    case 0: // check if should receive exp at all
        if (GetBattlerSide(gBattlerFainted) != B_SIDE_OPPONENT || (gBattleTypeFlags &
             (BATTLE_TYPE_LINK
              | BATTLE_TYPE_x2000000
              | BATTLE_TYPE_TRAINER_HILL
              | BATTLE_TYPE_FRONTIER
              | BATTLE_TYPE_SAFARI
              | BATTLE_TYPE_BATTLE_TOWER
              | BATTLE_TYPE_EREADER_TRAINER)))
        {
            gBattleScripting.getexpState = 6; // goto last case
        }
        else
        {
            gBattleScripting.getexpState++;
            gBattleStruct->givenExpMons |= gBitTable[gBattlerPartyIndexes[gBattlerFainted]];
        }
        break;
    case 1: // calculate experience points to redistribute
        {
            u16 calculatedExp;
            s32 viaSentIn;

            for (viaSentIn = 0, i = 0; i < PARTY_SIZE; i++)
            {
                if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) == SPECIES_NONE || GetMonData(&gPlayerParty[i], MON_DATA_HP) == 0)
                    continue;
                if (gBitTable[i] & sentIn)
                    viaSentIn++;

                item = GetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM);

                if (item == ITEM_ENIGMA_BERRY)
                    holdEffect = gSaveBlock1Ptr->enigmaBerry.holdEffect;
                else
                    holdEffect = ItemId_GetHoldEffect(item);

                if (holdEffect == HOLD_EFFECT_EXP_SHARE)
                    viaExpShare++;
            }

            calculatedExp = gBaseStats[gBattleMons[gBattlerFainted].species].expYield * gBattleMons[gBattlerFainted].level / 7;

			// scaled exp part 1
            //calculatedExp = gBaseStats[gBattleMons[gBattlerFainted].species].expYield * gBattleMons[gBattlerFainted].level / 5;

            if (viaExpShare) // at least one mon is getting exp via exp share
            {
                *exp = calculatedExp / 2 / viaSentIn;
                if (*exp == 0)
                    *exp = 1;

                gExpShareExp = calculatedExp / 2 / viaExpShare;
                if (gExpShareExp == 0)
                    gExpShareExp = 1;
            }
            else
            {
                *exp = calculatedExp / viaSentIn;
                if (*exp == 0)
                    *exp = 1;
                gExpShareExp = 0;
            }

            gBattleScripting.getexpState++;
            gBattleStruct->expGetterMonId = 0;
            gBattleStruct->sentInPokes = sentIn;
        }
        // fall through
    case 2: // set exp value to the poke in expgetter_id and print message
        if (gBattleControllerExecFlags == 0)
        {
            item = GetMonData(&gPlayerParty[gBattleStruct->expGetterMonId], MON_DATA_HELD_ITEM);
			
            if (item == ITEM_ENIGMA_BERRY)
                holdEffect = gSaveBlock1Ptr->enigmaBerry.holdEffect;
            else
                holdEffect = ItemId_GetHoldEffect(item);

            if (holdEffect != HOLD_EFFECT_EXP_SHARE && !(gBattleStruct->sentInPokes & 1))
            {
                *(&gBattleStruct->sentInPokes) >>= 1;
                gBattleScripting.getexpState = 5;
                gBattleMoveDamage = 0; // used for exp
            }
            else if (GetMonData(&gPlayerParty[gBattleStruct->expGetterMonId], MON_DATA_LEVEL) == MAX_LEVEL)
            {
                *(&gBattleStruct->sentInPokes) >>= 1;
                gBattleScripting.getexpState = 5;
                gBattleMoveDamage = 0; // used for exp
            }
            else
            {
                // Music change in a wild battle after fainting opposing pokemon.
                if (!(gBattleTypeFlags & BATTLE_TYPE_TRAINER)
                    && (gBattleMons[0].hp || (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && gBattleMons[2].hp))
                    && !IsBattlerAlive(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT))
                    && !IsBattlerAlive(GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT))
                    && !gBattleStruct->wildVictorySong)
                {
                    BattleStopLowHpSound();
                    PlayBGM(MUS_VICTORY_WILD);
                    gBattleStruct->wildVictorySong++;
                }

                if (GetMonData(&gPlayerParty[gBattleStruct->expGetterMonId], MON_DATA_HP))
                {
					
                    if (gBattleStruct->sentInPokes & 1)
                        gBattleMoveDamage = *exp;
                    else
                        gBattleMoveDamage = 0;

                    if (holdEffect == HOLD_EFFECT_EXP_SHARE)
                        gBattleMoveDamage += gExpShareExp;
					
					// scaled exp part 2
					//gBattleMoveDamage = gBattleMoveDamage * (cubed(2*gBattleMons[gBattlerFainted].level + 10) / \
					//    cubed(gBattleMons[gBattlerFainted].level + GetMonData(&gPlayerParty[gBattleStruct->expGetterMonId], MON_DATA_LEVEL) + 10) ) + 1;
						
					// unevolved pokemon boost
					if (gEvolutionTable[GetMonData(&gPlayerParty[gBattleStruct->expGetterMonId], MON_DATA_SPECIES)][0].method == EVO_LEVEL \
						&& (GetMonData(&gPlayerParty[gBattleStruct->expGetterMonId], MON_DATA_LEVEL) >= \
						gEvolutionTable[GetMonData(&gPlayerParty[gBattleStruct->expGetterMonId], MON_DATA_SPECIES)][0].param))
						gBattleMoveDamage = (gBattleMoveDamage * 120) / 100;

                    if (holdEffect == HOLD_EFFECT_LUCKY_EGG)
                        gBattleMoveDamage = (gBattleMoveDamage * 150) / 100;
                    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER && B_TRAINER_EXP_MULTIPLIER <= GEN_7)
                        gBattleMoveDamage = (gBattleMoveDamage * 150) / 100;

                    if (IsTradedMon(&gPlayerParty[gBattleStruct->expGetterMonId]))
                    {
                        // check if the pokemon doesn't belong to the player
                        if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && gBattleStruct->expGetterMonId >= 3)
                        {
                            i = STRINGID_EMPTYSTRING4;
                        }
                        else
                        {
                            gBattleMoveDamage = (gBattleMoveDamage * 150) / 100;
                            i = STRINGID_ABOOSTED;
                        }
                    }
                    else
                    {
                        i = STRINGID_EMPTYSTRING4;
                    }

                    // get exp getter battlerId
                    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
// >

< //
static u32 GetTrainerMoneyToGive(u16 trainerId)
{
    u32 i = 0;
    u32 lastMonLevel = 0;
    u32 moneyReward = 0;

    if (trainerId == TRAINER_SECRET_BASE)
    {
        moneyReward = 20 * gBattleResources->secretBase->party.levels[0] * gBattleStruct->moneyMultiplier;
    }
    else
    {
        switch (gTrainers[trainerId].partyFlags)
        {
        case 0:
            {
                const struct TrainerMonNoItemDefaultMoves *party = gTrainers[trainerId].party.NoItemDefaultMoves;
                lastMonLevel = party[gTrainers[trainerId].partySize - 1].lvl;
            }
            break;
        case F_TRAINER_PARTY_CUSTOM_MOVESET:
            {
                const struct TrainerMonNoItemCustomMoves *party = gTrainers[trainerId].party.NoItemCustomMoves;
                lastMonLevel = party[gTrainers[trainerId].partySize - 1].lvl;
            }
            break;
        case F_TRAINER_PARTY_HELD_ITEM:
            {
                const struct TrainerMonItemDefaultMoves *party = gTrainers[trainerId].party.ItemDefaultMoves;
                lastMonLevel = party[gTrainers[trainerId].partySize - 1].lvl;
            }
            break;
        case F_TRAINER_PARTY_CUSTOM_MOVESET | F_TRAINER_PARTY_HELD_ITEM:
            {
                const struct TrainerMonItemCustomMoves *party = gTrainers[trainerId].party.ItemCustomMoves;
                lastMonLevel = party[gTrainers[trainerId].partySize - 1].lvl;
            }
            break;
		case F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_ABILITY:
			{
	            const struct TrainerMonItemDefaultMovesAbilityShiny *party = gTrainers[trainerId].party.ItemDefaultMovesAbilityShiny;
                lastMonLevel = party[gTrainers[trainerId].partySize - 1].lvl;
			}
			break;		
		case F_TRAINER_PARTY_CUSTOM_MOVESET | F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_ABILITY:
			{
	            const struct TrainerMonItemCustomMovesAbilityShiny *party = gTrainers[trainerId].party.ItemCustomMovesAbilityShiny;
                lastMonLevel = party[gTrainers[trainerId].partySize - 1].lvl;
			}
			break;
        }

        for (; gTrainerMoneyTable[i].classId != 0xFF; i++)
        {
            if (gTrainerMoneyTable[i].classId == gTrainers[trainerId].trainerClass)
                break;
        }

        if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
            moneyReward = 4 * lastMonLevel * gBattleStruct->moneyMultiplier * gTrainerMoneyTable[i].value;
        else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
            moneyReward = 4 * lastMonLevel * gBattleStruct->moneyMultiplier * 2 * gTrainerMoneyTable[i].value;
        else
            moneyReward = 4 * lastMonLevel * gBattleStruct->moneyMultiplier * gTrainerMoneyTable[i].value;
    }

    return moneyReward;
}

static void Cmd_getmoneyreward(void)
// >

< //
static void Cmd_handlelearnnewmove(void)
{
    const u8 *jumpPtr1 = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    const u8 *jumpPtr2 = T1_READ_PTR(gBattlescriptCurrInstr + 5);

    u16 learnMove = MonTryLearningNewMove(&gPlayerParty[gBattleStruct->expGetterMonId], gBattlescriptCurrInstr[9], 0);
    while (learnMove == MON_ALREADY_KNOWS_MOVE)
        learnMove = MonTryLearningNewMove(&gPlayerParty[gBattleStruct->expGetterMonId], FALSE, 0);

    if (learnMove == 0)
    {
        gBattlescriptCurrInstr = jumpPtr2;
    }
    else if (learnMove == MON_HAS_MAX_MOVES)
    {
        gBattlescriptCurrInstr += 10;
    }
    else
    {
        gActiveBattler = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);

        if (gBattlerPartyIndexes[gActiveBattler] == gBattleStruct->expGetterMonId
            && !(gBattleMons[gActiveBattler].status2 & STATUS2_TRANSFORMED))
        {
            GiveMoveToBattleMon(&gBattleMons[gActiveBattler], learnMove);
        }
        if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
        {
            gActiveBattler = GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT);
            if (gBattlerPartyIndexes[gActiveBattler] == gBattleStruct->expGetterMonId
                && !(gBattleMons[gActiveBattler].status2 & STATUS2_TRANSFORMED))
            {
                GiveMoveToBattleMon(&gBattleMons[gActiveBattler], learnMove);
            }
        }

        gBattlescriptCurrInstr = jumpPtr1;
    }
}

static void Cmd_yesnoboxlearnmove(void)
// >

< //
u32 GetTotalAccuracy(u32 battlerAtk, u32 battlerDef, u32 move)
{
    u32 calc, moveAcc, atkHoldEffect, atkParam, defHoldEffect, defParam, atkAbility, defAbility;
    s8 buff, accStage, evasionStage;

    atkAbility = GetBattlerAbility(battlerAtk);
    atkHoldEffect = GetBattlerHoldEffect(battlerAtk, TRUE);
    atkParam = GetBattlerHoldEffectParam(battlerAtk);

    defAbility = GetBattlerAbility(battlerDef);
    defHoldEffect = GetBattlerHoldEffect(battlerDef, TRUE);
    defParam = GetBattlerHoldEffectParam(battlerDef);
    gPotentialItemEffectBattler = battlerDef;

    accStage = gBattleMons[battlerAtk].statStages[STAT_ACC];
    evasionStage = gBattleMons[battlerDef].statStages[STAT_EVASION];
    if (atkAbility == ABILITY_UNAWARE)
        evasionStage = 6;
    if (gBattleMoves[move].flags & FLAG_STAT_STAGES_IGNORED)
        evasionStage = 6;
    if (defAbility == ABILITY_UNAWARE)
        accStage = 6;

    if (gBattleMons[battlerDef].status2 & STATUS2_FORESIGHT || gStatuses3[battlerDef] & STATUS3_MIRACLE_EYED)
        buff = accStage;
    else
        buff = accStage + 6 - evasionStage;

    if (buff < 0)
        buff = 0;
    if (buff > 0xC)
        buff = 0xC;

    moveAcc = gBattleMoves[move].accuracy;
    // Check Thunder and Hurricane on sunny weather.
    if (WEATHER_HAS_EFFECT && gBattleWeather & WEATHER_SUN_ANY
        && (gBattleMoves[move].effect == EFFECT_THUNDER || gBattleMoves[move].effect == EFFECT_HURRICANE))
        moveAcc = 50;
    // Check Wonder Skin.
    if (defAbility == ABILITY_WONDER_SKIN && gBattleMoves[move].power == 0)
        moveAcc = 50;

    calc = sAccuracyStageRatios[buff].dividend * moveAcc;
    calc /= sAccuracyStageRatios[buff].divisor;

    if (atkAbility == ABILITY_COMPOUND_EYES || atkAbility == ABILITY_KEEN_EYE)
        calc = (calc * 130) / 100; // 1.3 compound eyes boost
    else if (atkAbility == ABILITY_VICTORY_STAR)
        calc = (calc * 110) / 100; // 1.1 victory star boost
    if (IsBattlerAlive(BATTLE_PARTNER(battlerAtk)) && GetBattlerAbility(BATTLE_PARTNER(battlerAtk)) == ABILITY_VICTORY_STAR)
        calc = (calc * 110) / 100; // 1.1 ally's victory star boost

    if (defAbility == ABILITY_SAND_VEIL && WEATHER_HAS_EFFECT && gBattleWeather & WEATHER_SANDSTORM_ANY)
        calc = (calc * 80) / 100; // 1.2 sand veil loss
    else if (defAbility == ABILITY_SNOW_CLOAK && WEATHER_HAS_EFFECT && gBattleWeather & WEATHER_HAIL_ANY)
        calc = (calc * 80) / 100; // 1.2 snow cloak loss
    else if (defAbility == ABILITY_TANGLED_FEET && gBattleMons[battlerDef].status2 & STATUS2_CONFUSION)
        calc = (calc * 50) / 100; // 1.5 tangled feet loss

    if (atkAbility == ABILITY_HUSTLE && IS_MOVE_PHYSICAL(move))
        calc = (calc * 80) / 100; // 1.2 hustle loss

    if (defHoldEffect == HOLD_EFFECT_EVASION_UP)
        calc = (calc * (100 - defParam)) / 100;

    if (atkHoldEffect == HOLD_EFFECT_WIDE_LENS)
        calc = (calc * (100 + atkParam)) / 100;
    else if (atkHoldEffect == HOLD_EFFECT_ZOOM_LENS && GetBattlerTurnOrderNum(battlerAtk) > GetBattlerTurnOrderNum(battlerDef));
        calc = (calc * (100 + atkParam)) / 100;

    return calc;
}

static void Cmd_accuracycheck(void)
// >

< //
static bool32 TryAegiFormChange(void)
{
    // Only Aegislash with Stance Change can transform, transformed mons cannot.
    // if (GetBattlerAbility(gBattlerAttacker) != ABILITY_STANCE_CHANGE
        // || gBattleMons[gBattlerAttacker].status2 & STATUS2_TRANSFORMED)
        // return FALSE;

    // switch (gBattleMons[gBattlerAttacker].species)
    // {
    // default:
        // return FALSE;
    // case SPECIES_AEGISLASH: // Shield -> Blade
        // if (gBattleMoves[gCurrentMove].power == 0)
            // return FALSE;
        // gBattleMons[gBattlerAttacker].species = SPECIES_AEGISLASH_BLADE;
        // break;
    // case SPECIES_AEGISLASH_BLADE: // Blade -> Shield
        // if (gCurrentMove != MOVE_KINGS_SHIELD)
            // return FALSE;
        // gBattleMons[gBattlerAttacker].species = SPECIES_AEGISLASH;
        // break;
    // }

    // BattleScriptPushCursor();
    // gBattlescriptCurrInstr = BattleScript_AttackerFormChange;
    // return TRUE;
	return FALSE;
}

static void Cmd_attackcanceler(void)
// >

< //
bool32 IsShieldsDownProtected(u32 battler)
{
    // return (gBattleMons[battler].ability == ABILITY_SHIELDS_DOWN
            // && gBattleMons[battler].species == SPECIES_MINIOR);
	return FALSE;
}

u32 IsAbilityStatusProtected(u32 battler)
// >

< //
static void Cmd_datahpupdate(void)
{
    u32 moveType;

    if (gBattleControllerExecFlags)
        return;

    if (gBattleStruct->dynamicMoveType == 0)
        moveType = gBattleMoves[gCurrentMove].type;
    else if (!(gBattleStruct->dynamicMoveType & 0x40))
        moveType = gBattleStruct->dynamicMoveType & 0x3F;
    else
        moveType = gBattleMoves[gCurrentMove].type;

    if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
    {
        gActiveBattler = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);
        if (DoesSubstituteBlockMove(gBattlerAttacker, gActiveBattler, gCurrentMove) && gDisableStructs[gActiveBattler].substituteHP && !(gHitMarker & HITMARKER_IGNORE_SUBSTITUTE))
        {
            if (gDisableStructs[gActiveBattler].substituteHP >= gBattleMoveDamage)
            {
                if (gSpecialStatuses[gActiveBattler].dmg == 0)
                    gSpecialStatuses[gActiveBattler].dmg = gBattleMoveDamage;
                gDisableStructs[gActiveBattler].substituteHP -= gBattleMoveDamage;
                gHpDealt = gBattleMoveDamage;
            }
            else
            {
                if (gSpecialStatuses[gActiveBattler].dmg == 0)
                    gSpecialStatuses[gActiveBattler].dmg = gDisableStructs[gActiveBattler].substituteHP;
                gHpDealt = gDisableStructs[gActiveBattler].substituteHP;
                gDisableStructs[gActiveBattler].substituteHP = 0;
            }
            // check substitute fading
            if (gDisableStructs[gActiveBattler].substituteHP == 0)
            {
                gBattlescriptCurrInstr += 2;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_SubstituteFade;
                return;
            }
        }
        // else if (DoesDisguiseBlockMove(gBattlerAttacker, gActiveBattler, gCurrentMove))
        // {
            // gBattleMons[gActiveBattler].species = SPECIES_MIMIKYU_BUSTED;
            // BattleScriptPush(gBattlescriptCurrInstr + 2);
            // gBattlescriptCurrInstr = BattleScript_TargetFormChange;
        // }
        else
        {
            gHitMarker &= ~(HITMARKER_IGNORE_SUBSTITUTE);
            if (gBattleMoveDamage < 0) // hp goes up
// >

< //
    case VARIOUS_TRY_REFLECT_TYPE:
        // if (gBattleMons[gBattlerTarget].species == SPECIES_ARCEUS || gBattleMons[gBattlerTarget].species == SPECIES_SILVALLY)
        // {
            // gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);
        // }
        // else if (gBattleMons[gBattlerTarget].type1 == TYPE_MYSTERY && gBattleMons[gBattlerTarget].type2 != TYPE_MYSTERY)
        if (gBattleMons[gBattlerTarget].type1 == TYPE_MYSTERY && gBattleMons[gBattlerTarget].type2 != TYPE_MYSTERY)
			{
            gBattleMons[gBattlerAttacker].type1 = gBattleMons[gBattlerTarget].type2;
// >

< //
bool32 DoesDisguiseBlockMove(u8 battlerAtk, u8 battlerDef, u32 move)
{
    // if (GetBattlerAbility(battlerDef) != ABILITY_DISGUISE
        // || gBattleMons[battlerDef].species != SPECIES_MIMIKYU
        // || gBattleMons[battlerDef].status2 & STATUS2_TRANSFORMED
        // || gBattleMoves[move].power == 0)
        // return FALSE;
    // else
        // return TRUE;
	return FALSE;
}

static void Cmd_jumpifsubstituteblocks(void)
// >