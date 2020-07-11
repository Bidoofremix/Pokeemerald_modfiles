< //
            case MOVE_EFFECT_PAYDAY:
                if (GET_BATTLER_SIDE(gBattlerAttacker) == B_SIDE_PLAYER)
                {
                    u16 PayDay = gPaydayMoney;
					
					// more payday money with ability bonanza
					if (gBattleMons[gBattlerAttacker].ability != ABILITY_BONANZA)
					{
						gPaydayMoney += (gBattleMons[gBattlerAttacker].level * 10);
                    }
					else
					{
						gPaydayMoney += (gBattleMons[gBattlerAttacker].level * 5);
					}
					if (PayDay > gPaydayMoney)
                        gPaydayMoney = 0xFFFF;
                }
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = sMoveEffectBS_Ptrs[gBattleCommunication[MOVE_EFFECT_BYTE]];
                break;
            case MOVE_EFFECT_TRI_ATTACK:
// >