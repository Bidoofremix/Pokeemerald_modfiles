< // START
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
	
SilentForest_ShowSnorlax::
	clearflag FLAG_HIDE_SNORLAX
	return

SilentForest_EventScript_Snorlax::
	lock
	bufferspeciesname 0, SPECIES_SNORLAX
	checkitem ITEM_POKE_FLUTE, 1
	compare VAR_RESULT, TRUE
	goto_if_eq SilentForest_EventScript_BattleSnorlax
	msgbox SilentForest_Text_SnorlaxIsSleeping, MSGBOX_DEFAULT	
	release
	end
	
SilentForest_EventScript_BattleSnorlax::

	bufferitemname 1, ITEM_POKE_FLUTE
	msgbox SilentForest_Text_SnorlaxIsSleepingUseThePokeFlute, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SilentForest_EventScript_CancelBattle
	
	message SilentForest_Text_PlayedThePokeFlute
	playfanfare MUS_RG_POKEFUE
	waitfanfare
	waitmessage	
	delay 40
	
	// set battle
	msgbox SilentForest_Text_SnorlaxAttackedInAGrumpyRage, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_SNORLAX, 2
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
	
SilentForest_EventScript_CancelBattle::
	release
	end
	
SilentForest_EventScript_DefeatedSnorlax::
	// remove snorlax sprite
	fadescreenswapbuffers 1
	removeobject LOCALID_SNORLAX
	fadescreenswapbuffers 0
	setflag FLAG_DEFEATED_SNORLAX
	
	release
	end		
	
SilentForest_Text_SnorlaxIsSleeping:
	.string "A {STR_VAR_1} is sleeping…$"

SilentForest_Text_SnorlaxIsSleepingUseThePokeFlute:
	.string "A {STR_VAR_1} is sleeping…\n"
	.string "Use the {STR_VAR_2}?$"
	
SilentForest_Text_PlayedThePokeFlute:
	.string "{PLAYER} played the {STR_VAR_2}.$"
	
SilentForest_Text_SnorlaxAttackedInAGrumpyRage:
	.string "{STR_VAR_1} attacked in a\n"
	.string "grumpy rage!$"
	
SilentForest_EventScript_ItemLeafStone::
	finditem ITEM_LEAF_STONE
	end
// > END