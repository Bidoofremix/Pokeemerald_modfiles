< //
MoveTutor_EventScript_RolloutTaught:: @ 82C7FDC
	msgbox MoveTutor_Text_RolloutTaught, MSGBOX_DEFAULT
	release
	end

//VerdanturfTown_PokemonCenter_1F_EventScript_FuryCutterTutor:: @ 82C7FE6
//	lock
//	faceplayer
//	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_FURY_CUTTER, MoveTutor_EventScript_FuryCutterTaught
//	msgbox MoveTutor_Text_FuryCutterTeach, MSGBOX_YESNO
//	compare VAR_RESULT, NO
//	goto_if_eq MoveTutor_EventScript_FuryCutterDeclined
//	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
//	compare VAR_RESULT, NO
//	goto_if_eq MoveTutor_EventScript_FuryCutterDeclined
//	msgbox MoveTutor_Text_FuryCutterWhichMon, MSGBOX_DEFAULT
//	setvar VAR_0x8005, TUTOR_MOVE_FURY_CUTTER
//	call MoveTutor_EventScript_OpenPartyMenu
//	compare VAR_RESULT, 0
//	goto_if_eq MoveTutor_EventScript_FuryCutterDeclined
//	setflag FLAG_MOVE_TUTOR_TAUGHT_FURY_CUTTER
//	goto MoveTutor_EventScript_FuryCutterTaught
//	end

//MoveTutor_EventScript_FuryCutterDeclined:: @ 82C803A
//	msgbox MoveTutor_Text_FuryCutterDeclined, MSGBOX_DEFAULT
//	release
//	end

//MoveTutor_EventScript_FuryCutterTaught:: @ 82C8044
//	msgbox MoveTutor_Text_FuryCutterTaught, MSGBOX_DEFAULT
//	release
//	end

LavaridgeTown_House_EventScript_MimicTutor:: @ 82C804E
// >