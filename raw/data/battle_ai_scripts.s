< //
	if_equal ABILITY_WONDER_GUARD, CheckIfWonderGuardCancelsMove
	if_equal ABILITY_FLUTTER, CheckIfLevitateCancelsGroundMove
	if_equal ABILITY_LEVITATE, CheckIfLevitateCancelsGroundMove
// >

< //
	if_equal ABILITY_LEVITATE, Score_Minus10
	if_equal ABILITY_FLUTTER, Score_Minus10

AI_CBM_HighRiskForDamage: @ 82DC4ED
// >

< //
	if_ability AI_USER_PARTNER, ABILITY_LEVITATE, Score_Plus2
	if_ability AI_USER_PARTNER, ABILITY_FLUTTER, Score_Plus2
	if_type AI_USER_PARTNER, TYPE_FLYING, Score_Plus2
// >

< //
	if_not_equal ABILITY_LEVITATE, AI_TrySkillSwapOnAlly2
	get_ability AI_TARGET
	if_not_equal ABILITY_FLUTTER, AI_TrySkillSwapOnAlly2
	get_ability AI_TARGET
	if_equal ABILITY_LEVITATE, Score_Minus30
	get_target_type1
	if_equal ABILITY_FLUTTER, Score_Minus30
	get_target_type1
// >

< //
	if_equal ABILITY_LEVITATE, AI_Roaming_Flee
	get_ability AI_TARGET
	if_equal ABILITY_FLUTTER, AI_Roaming_Flee
	get_ability AI_TARGET
// >