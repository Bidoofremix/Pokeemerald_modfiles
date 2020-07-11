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