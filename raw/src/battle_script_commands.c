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