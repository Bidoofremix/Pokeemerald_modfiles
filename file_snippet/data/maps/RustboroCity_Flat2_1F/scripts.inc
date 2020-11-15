< //
RustboroCity_Flat2_1F_MapScripts:: @ 8215F76
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_Flat2_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_Flat2_1F_OnFrame
	.byte 0

.set LOCALID_ORIGINALSKITTY, 1	
.set LOCALID_NEWSKITTY, 3	
	
RustboroCity_Flat2_1F_OnFrame: @ 820499A
	map_script_2 VAR_ROUTE115_STATE, 2, RustboroCity_Flat2_1F_EventScript_FinishQuest
	.2byte 0
	
RustboroCity_Flat2_1F_OnTransition: @ 81F2947
	compare VAR_ROUTE115_STATE, 2
	call_if_ne RustboroCity_Flat2_1F_EventScript_HideNewSkitty
	end
	
RustboroCity_Flat2_1F_EventScript_HideNewSkitty::
	setflag FLAG_HIDE_ROUTE115_SKITTY
	return

RustboroCity_Flat2_1F_EventScript_OldWoman:: @ 8215F77
	lock
	faceplayer
	questmenu QUEST_MENU_CHECK_UNLOCKED SIDE_QUEST_5
	compare VAR_RESULT, TRUE
	goto_if_eq RustboroCity_Flat2_1F_EventScript_StartQuest
	msgbox RustboroCity_Flat2_1F_Text_DevonWorkersLiveHere, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat2_1F_EventScript_StartQuest::
	setvar VAR_ROUTE115_STATE, 1
	bufferspeciesname 0, SPECIES_SKITTY
	msgbox RustboroCity_Flat2_1F_Text_MySkittyHasBeenSad, MSGBOX_DEFAULT
	release
	end
	
RustboroCity_Flat2_1F_EventScript_FinishQuest::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	delay 20
	bufferspeciesname 0, SPECIES_SKITTY
	msgbox RustboroCity_Flat2_1F_Text_LookWhoIBrought, MSGBOX_DEFAULT
	playse SE_LEDGE
	applymovement LOCALID_ORIGINALSKITTY, RustboroCity_Flat2_1F_Movement_JumpInPlaceUp
	playse SE_LEDGE
	applymovement LOCALID_ORIGINALSKITTY, RustboroCity_Flat2_1F_Movement_JumpInPlaceUp
	waitmovement 0
	msgbox RustboroCity_Flat2_1F_Text_Skitty, MSGBOX_DEFAULT
	closemessage
	delay 20
	playse SE_LEDGE
	applymovement LOCALID_NEWSKITTY, RustboroCity_Flat2_1F_Movement_JumpInPlaceDown
	msgbox RustboroCity_Flat2_1F_Text_NewSkitty, MSGBOX_DEFAULT
	closemessage
	delay 40
	questmenu QUEST_MENU_COMPLETE_QUEST SIDE_QUEST_5
	call CompleteQuestFanfare
	setvar VAR_ROUTE115_STATE, 3
	releaseall
	end
	
RustboroCity_Flat2_1F_EventScript_Skitty:: @ 8215F80
	lock
	faceplayer
	questmenu QUEST_MENU_CHECK_COMPLETE SIDE_QUEST_5
	compare VAR_RESULT, TRUE
	goto_if_ne RustboroCity_Flat2_1F_EventScript_SkittySad
	waitse
	playmoncry SPECIES_SKITTY, 0
	msgbox RustboroCity_Flat2_1F_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end
	
RustboroCity_Flat2_1F_EventScript_SkittySad::
	waitse
	playmoncry SPECIES_SKITTY, 5
	msgbox RustboroCity_Flat2_1F_Text_SkittySad, MSGBOX_DEFAULT
	waitmoncry
	release
	end

	
RustboroCity_Flat2_1F_Movement_JumpInPlaceDown::
	disable_jump_landing_ground_effect
	jump_in_place_down
	enable_jump_landing_ground_effect
	step_end	
	
RustboroCity_Flat2_1F_Movement_JumpInPlaceUp::
	face_up
	disable_jump_landing_ground_effect
	jump_in_place_up
	enable_jump_landing_ground_effect
	step_end
	
RustboroCity_Flat2_1F_Text_DevonWorkersLiveHere: @ 8215F93
	.string "RUSTBORO UNIVERISTY's visiting\n"
	.string "researchers live in this building.$"

RustboroCity_Flat2_1F_Text_MySkittyHasBeenSad:
	.string "My {STR_VAR_1} has been really\n"
	.string "sad lately.\p"
	.string "It doesn't want to play or\n"
	.string "eat its favourite treats.\p"
	.string "The last time we went on a walk,\n"
	.string "it kept looking at the route\l"
	.string "north of RUSTBORO CITY.\p"
	.string "I wonder what it is that {STR_VAR_1}\n"
	.string "is longing for…$"
	
RustboroCity_Flat2_1F_Text_LookWhoIBrought:
	.string "{STR_VAR_1}! Look who I brought!$"
	
RustboroCity_Flat2_1F_Text_SkittySad:
	.string "SKITTY: Meewwwl…$"
	
RustboroCity_Flat2_1F_Text_NewSkitty: @ 8215FC6
	.string "SKITTY: Nyan!$"	
	
RustboroCity_Flat2_1F_Text_Skitty: @ 8215FC6
	.string "SKITTY: Gyaaaah!$"
// > END