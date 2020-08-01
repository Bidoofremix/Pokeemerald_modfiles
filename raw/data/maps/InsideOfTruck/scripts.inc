< //
InsideOfTruck_EventScript_SetIntroFlags:: @ 823BF04
	lockall
	setflag FLAG_HIDE_MAP_NAME_POPUP
	setflag FLAG_SYS_B_DASH
	setflag FLAG_RECEIVED_RUNNING_SHOES
	clearflag FLAG_DOUBLE_BATTLE_ENABLED
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq InsideOfTruck_EventScript_SetIntroFlagsMale
	compare VAR_RESULT, FEMALE
	goto_if_eq InsideOfTruck_EventScript_SetIntroFlagsFemale
	end

InsideOfTruck_EventScript_SetIntroFlagsMale:: @ 823BF20
// >