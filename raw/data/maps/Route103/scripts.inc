// <
Route103_MapScripts:: @ 81EC38E
	map_script MAP_SCRIPT_ON_TRANSITION, Route103_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route103_OnLoad
	.byte 0

Route103_OnTransition: @ 81EC399
	call Common_EventScript_SetupRivalGfxId
	call ProfBirch_EventScript_UpdateLocation
	call_if_set FLAG_ADVENTURE_STARTED, Route103_EventScript_CanGoEast
	end

Route103_OnLoad: @ 81EC3A4
	end

Route103_EventScript_CanGoEast:
	setvar VAR_ROUTE103_STATE, 1
	setobjectxyperm 23, 10, 7
	setobjectxyperm 24, 9, 6
	end		

Route103_EventScript_Rival:: @ 81EC3C1
// >

// <
Route103_EventScript_Isabelle:: @ 81EC78F
	trainerbattle_single TRAINER_ISABELLE, Route103_Text_IsabelleIntro, Route103_Text_IsabelleDefeated
	msgbox Route103_Text_IsabellePostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_ZigzagoonBoy::
	lock
	faceplayer
	bufferspeciesname 0, SPECIES_ZIGZAGOON
	goto_if_set FLAG_ADVENTURE_STARTED, Route103_EventScript_ZigzagoonBoy_CanGoEast
	msgbox Route103_Text_ZigzagoonIsTraining, MSGBOX_DEFAULT
	release
	end
	
Route103_EventScript_CantGoEastTrigger::
	lock
	bufferspeciesname 0, SPECIES_ZIGZAGOON
	playse SE_PIN
	applymovement 23, Route103_Movement_ZigzagoonBoyExclamation
	waitmovement 0
	delay 20
	msgbox Route103_Text_ZigzagoonIsTraining, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_GetAwayFromStairs
	waitmovement 0
	release
	end
	
Route103_EventScript_Zigzagoon::
	lock
	faceplayer
	bufferspeciesname 0, SPECIES_ZIGZAGOON
	playmoncry SPECIES_ZIGZAGOON, 0
	msgbox Route103_Text_ZigzagoonPshoo, MSGBOX_AUTOCLOSE
	release
	end
	
Route103_EventScript_ZigzagoonBoy_CanGoEast::
	msgbox Route103_Text_ZigzagoonBoy_ZigzagoonLikesGrassBetter, MSGBOX_NPC
	end
	
Route103_Movement_GetAwayFromStairs:
	delay_16
	walk_up
	step_end	
	
Route103_Movement_ZigzagoonBoyExclamation:
	emote_exclamation_mark
	face_down
	step_end	
	
Route103_Text_ZigzagoonBoy_ZigzagoonLikesGrassBetter:
	.string "I figured that training here is better.\p"
	.string "{STR_VAR_1} likes running in the grass!$"
	
Route103_Text_ZigzagoonIsTraining:
	.string "Oh, I'm training obedience with my\n"
	.string "{STR_VAR_1}. It got loose on ROUTE 101.\p"
	.string "Can you please come back later?$"
	
Route103_Text_ZigzagoonPshoo:
	.string "{STR_VAR_1}: Pshoo!$"
	
Route103_Text_MayRoute103Pokemon: @ 81EC7A6
// >

< //
Route103_Text_ShortcutToOldale: @ 81ECBB5
	.string "The land has risen here and a shoal\n"
	.string "has formed. It's a shortcut to\n"
	.string "OLDALE TOWN.\p"
	.string "Fufufu, that's useful, isn't it?$"

Route103_Text_RouteSign: @ 81ECC1A
// >