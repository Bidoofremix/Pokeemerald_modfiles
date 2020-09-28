< //

.set LOCALID_SNORLAX, 1

SilentForest_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SilentForest_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, SilentForest_OnTransition
	.byte 0
	
SilentForest_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, SilentForest_Mapscript_CtrlObj
	end

SilentForest_Mapscript_CtrlObj::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject LOCALID_SNORLAX
	return
	
SilentForest_OnTransition::
	call_if_unset FLAG_DEFEATED_SNORLAX, SilentForest_ShowSnorlax
	end

SilentForest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SilentForest_OnTransition
	.byte 0

SilentForest_ShowSnorlax::
	clearflag FLAG_HIDE_SNORLAX
	return

SilentForest_EventScript_Snorlax::
	lock
	
	// set battle
	playmoncry SPECIES_SNORLAX, 2
	msgbox BrineBeach_Text_Gyarados, MSGBOX_DEFAULT
	closemessage
	delay 40
	setwildbattle SPECIES_SNORLAX, 30, ITEM_LEFTOVERS
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	
	//dowildbattle
	special BattleSetup_StartLegendaryBattle
	waitstate
	delay 40
	
	// check outcome
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq SilentForest_EventScript_DefeatedSnorlax
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq SilentForest_EventScript_DefeatedSnorlax
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq SilentForest_EventScript_DefeatedSnorlax
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq SilentForest_EventScript_DefeatedSnorlax
	
	release
	end
	
SilentForest_EventScript_DefeatedSnorlax::
	// remove gyarados sprite
	setvar VAR_SILENT_FOREST_STATE, 1
	fadescreenswapbuffers 1
	//fadescreen 1
	removeobject LOCALID_SNORLAX
	//fadescreen 0
	fadescreenswapbuffers 0
	setflag FLAG_DEFEATED_SNORLAX
	
	releaseall
	end	
	
	
SilentForest_EventScript_ItemLeafStone::
	finditem ITEM_LEAF_STONE
	end	
	
SilentForest_OnTransition:
	end
// >