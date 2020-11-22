< //
RustboroCity_Flat2_1F_MapScripts:: @ 8215F76
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_Flat2_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_Flat2_1F_OnFrame
	.byte 0

.set LOCALID_ORIGINALSKITTY, 1
.set LOCALID_OLDLADY, 2
.set LOCALID_NEWSKITTY, 3	
	
RustboroCity_Flat2_1F_OnFrame: @ 820499A
	map_script_2 VAR_ROUTE115_STATE, 2, RustboroCity_Flat2_1F_EventScript_FinishQuest
	.2byte 0
	
RustboroCity_Flat2_1F_OnTransition: @ 81F2947
	compare VAR_ROUTE115_STATE, 2
	call_if_lt RustboroCity_Flat2_1F_EventScript_HideNewSkitty
	compare VAR_ROUTE115_STATE, 2
	call_if_ge RustboroCity_Flat2_1F_EventScript_OriginalSkittyFaceUp
	end
	
RustboroCity_Flat2_1F_EventScript_HideNewSkitty::
	setflag FLAG_HIDE_ROUTE115_SKITTY
	return
	
RustboroCity_Flat2_1F_EventScript_OriginalSkittyFaceUp::
	setobjectmovementtype LOCALID_ORIGINALSKITTY, MOVEMENT_TYPE_FACE_UP
	return

RustboroCity_Flat2_1F_EventScript_OldWoman:: @ 8215F77
	lock
	faceplayer
	questmenu QUEST_MENU_CHECK_COMPLETE SIDE_QUEST_5
	compare VAR_RESULT, TRUE
	goto_if_eq RustboroCity_Flat2_1F_EventScript_QuestComplete
	questmenu QUEST_MENU_CHECK_UNLOCKED SIDE_QUEST_5
	compare VAR_RESULT, TRUE
	goto_if_eq RustboroCity_Flat2_1F_EventScript_StartQuest
	msgbox RustboroCity_Flat2_1F_Text_DevonWorkersLiveHere, MSGBOX_DEFAULT
	release
	end
	
RustboroCity_Flat2_1F_EventScript_QuestComplete::
	goto_if_unset FLAG_RECEIVED_OLD_LADY_MOON_BALLS, RustboroCity_Flat2_1F_EventScript_TryGiveMoonBalls
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
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_ORIGINALSKITTY, RustboroCity_Flat2_1F_Movement_JumpInPlaceUp
	waitmovement 0
	playmoncry SPECIES_SKITTY, 0
	msgbox RustboroCity_Flat2_1F_Text_Skitty, MSGBOX_DEFAULT
	closemessage
	delay 20
	playse SE_LEDGE
	applymovement LOCALID_NEWSKITTY, RustboroCity_Flat2_1F_Movement_JumpInPlaceDown
	playmoncry SPECIES_SKITTY, 0
	msgbox RustboroCity_Flat2_1F_Text_NewSkitty, MSGBOX_DEFAULT
	closemessage
	delay 40
	questmenu QUEST_MENU_COMPLETE_QUEST SIDE_QUEST_5
	call CompleteQuestFanfare
	setvar VAR_ROUTE115_STATE, 3
	bufferspeciesname 0, SPECIES_SKITTY
	applymovement LOCALID_OLDLADY, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	msgbox RustboroCity_Flat2_1F_Text_ImSoRelieved, MSGBOX_DEFAULT
	giveitem ITEM_MOON_BALL, 3
	compare VAR_RESULT, FALSE
	call_if_eq OldaleTown_EventScript_FootprintsMan_BagIsFull
	setflag FLAG_RECEIVED_OLD_LADY_MOON_BALLS
	releaseall
	end
	
RustboroCity_Flat2_1F_EventScript_TryGiveMoonBalls::
	lock
	faceplayer
	bufferspeciesname 0, SPECIES_SKITTY
	msgbox RustboroCity_Flat2_1F_Text_ThankYouForFindingSkittysFriend, MSGBOX_DEFAULT
	giveitem ITEM_MOON_BALL, 3
	compare VAR_RESULT, FALSE
	call_if_eq OldaleTown_EventScript_FootprintsMan_BagIsFull
	setflag FLAG_RECEIVED_OLD_LADY_MOON_BALLS
	release
	end
	
RustboroCity_Flat2_1F_EventScript_Skitty:: @ 8215F80
	lock
	faceplayer
	questmenu QUEST_MENU_CHECK_COMPLETE SIDE_QUEST_5
	compare VAR_RESULT, TRUE
	goto_if_ne RustboroCity_Flat2_1F_EventScript_SkittySad
	playmoncry SPECIES_SKITTY, 0
	msgbox RustboroCity_Flat2_1F_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end
	
RustboroCity_Flat2_1F_EventScript_SkittySad::
	playmoncry SPECIES_SKITTY, 5
	msgbox RustboroCity_Flat2_1F_Text_SkittySad, MSGBOX_DEFAULT
	waitmoncry
	release
	end
	
RustboroCity_Flat2_1F_EventScript_NewSkitty::
	lock
	faceplayer
	playmoncry SPECIES_SKITTY, 0
	msgbox RustboroCity_Flat2_1F_Text_NewSkitty, MSGBOX_DEFAULT
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
	.string "north of the city.\p"
	.string "I wonder what it is that {STR_VAR_1}\n"
	.string "is longing for…$"
	
RustboroCity_Flat2_1F_Text_LookWhoIBrought:
	.string "{STR_VAR_1}! Look who I brought!$"

RustboroCity_Flat2_1F_Text_ImSoRelieved:
	.string "I'm so relieved that my {STR_VAR_1}\n"
	.string "is happy again!\p"
	.string "Thank you so much for finding its\n"
	.string "friend. As a sign of my gratitude,\l"
	.string "I'd like you to have these.$"
	
RustboroCity_Flat2_1F_Text_ThankYouForFindingSkittysFriend:
	.string "Thank you for finding {STR_VAR_1}'s\n"
	.string "friend.\p"
	.string "As a reward, I'd like you to\n"
	.string "have these.$"
	
RustboroCity_Flat2_1F_Text_SkittySad:
	.string "SKITTY: Meewwwl…$"
	
RustboroCity_Flat2_1F_Text_NewSkitty: @ 8215FC6
	.string "SKITTY: Nyan!$"	
	
RustboroCity_Flat2_1F_Text_Skitty: @ 8215FC6
	.string "SKITTY: Gyaaaah!$"
// > END