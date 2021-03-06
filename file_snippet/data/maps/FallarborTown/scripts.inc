< // START

.set LOCALID_DRYSTAN, 5

FallarborTown_MapScripts:: @ 81EB1FA
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_OnTransition
	.byte 0
	
FallarborTown_OnTransition: @ 81EB200
	setflag FLAG_HIDE_FALLARBOR_TOWN_DRYSTAN
	setflag FLAG_VISITED_FALLARBOR_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	clearflag FLAG_CONTEST_SKETCH_CREATED
	end

FallarborTown_EventScript_Drystan::
	lockall
	
	setvar VAR_MEWTWO_QUESTLINE_STATE, 1
	
	playse SE_DOOR
	opendoor 8, 6
	waitdooranim
	
	addobject LOCALID_DRYSTAN
	applymovement LOCALID_DRYSTAN, Route111_Movement_WinstrateExitHouse
	delay 40
	
	playse SE_PIN
	applymovement LOCALID_DRYSTAN, Common_Movement_ExclamationMark
	waitmovement 0
	delay 10
	msgbox FallarborTown_Text_HeyYouThere, MSGBOX_DEFAULT
	closemessage
	
	getplayerxy VAR_TEMP_0, VAR_TEMP_1

	// if Y = 8, Drystan does not walk down
	// also, player faces up
	compare VAR_TEMP_1, 8
	call_if_eq FallarborTown_EventScript_PlayerFaceUp	
	// else Drystan walks to player
	call_if_ne FallarborTown_EventScript_DrystanWalkToPlayer	
	
	msgbox FallarborTown_Text_IHeardThereIsAStrongTrainer, MSGBOX_DEFAULT
	closemessage
	
	delay 40
	
	// Drystan goes back to house
	compare VAR_TEMP_1, 8
	call_if_eq FallarborTown_EventScript_DrystanBackToHouseShort
	call_if_ne FallarborTown_EventScript_DrystanBackToHouseLong

	playse SE_DOOR
	closedoor 8, 6
	waitdooranim
	delay 20
	
	// player goes to house
	compare VAR_TEMP_1, 8
	call_if_eq FallarborTown_EventScript_PlayerToHouseShort
	call_if_ne FallarborTown_EventScript_PlayerToHouseLong
	
	warpdoor MAP_NAVEL_ROCK_UP1, 255, 4, 8

	releaseall
	end	
	
FallarborTown_EventScript_DrystanWalkToPlayer::
	// if Y > 8, Drystan walks down 2
	// also, player faces right
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	applymovement LOCALID_DRYSTAN, FallarborTown_Movement_Down2
	waitmovement 0

	// if Y = 11, Drystan walks down 2 more
	compare VAR_TEMP_1, 11
	call_if_eq FallarborTown_EventScript_DrystanWalkDown2

	// if Y = 10, Drystan walks down 1 more
	compare VAR_TEMP_1, 10
	call_if_eq FallarborTown_EventScript_DrystanWalkDown1
	
	// Drystan faces left
	applymovement LOCALID_DRYSTAN, FallarborTown_Movement_Left1
	waitmovement 0
	delay 20

	return
	
FallarborTown_EventScript_DrystanBackToHouseShort::	
	applymovement LOCALID_DRYSTAN, Route111_Movement_WinstrateEnterHouse
	waitmovement 0
	removeobject LOCALID_DRYSTAN 
	return

FallarborTown_EventScript_DrystanBackToHouseLong::
	applymovement LOCALID_DRYSTAN, FallarborTown_Movement_Right1
	waitmovement 0
	
	// walk up 2
	call FallarborTown_EventScript_DrystanWalkUp2
	
	// if Y = 11, Drystan walks up 2 more
	compare VAR_TEMP_1, 11
	call_if_eq FallarborTown_EventScript_DrystanWalkUp2

	// if Y = 10, Drystan walks up 1 more
	compare VAR_TEMP_1, 10
	call_if_eq FallarborTown_EventScript_DrystanWalkUp1
	
	removeobject LOCALID_DRYSTAN
	return
	
FallarborTown_EventScript_PlayerToHouseShort::
	applymovement OBJ_EVENT_ID_PLAYER, FallarborTown_Movement_Up1
	waitmovement 0
	return
	
FallarborTown_EventScript_PlayerToHouseLong::

	applymovement OBJ_EVENT_ID_PLAYER, FallarborTown_Movement_Right1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, FallarborTown_Movement_Right1
	waitmovement 0
	
	// if Y = 11, walk up 2 more
	compare VAR_TEMP_1, 11
	call_if_eq FallarborTown_EventScript_PlayerWalkUp2

	// if Y = 10, walk up 1 more
	compare VAR_TEMP_1, 10
	call_if_eq FallarborTown_EventScript_PlayerWalkUp1
		
	// walk up 1
	call FallarborTown_EventScript_PlayerWalkUp2
	
	return
	
FallarborTown_EventScript_PlayerFaceUp::	
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	return
	
FallarborTown_EventScript_DrystanWalkUp2::
	applymovement LOCALID_DRYSTAN, FallarborTown_Movement_Up2
	waitmovement 0
	return
	
FallarborTown_EventScript_DrystanWalkUp1::
	applymovement LOCALID_DRYSTAN, FallarborTown_Movement_Up1
	waitmovement 0
	return	
	
FallarborTown_EventScript_PlayerWalkUp2::
	applymovement OBJ_EVENT_ID_PLAYER, FallarborTown_Movement_Up2
	waitmovement 0
	return
	
FallarborTown_EventScript_PlayerWalkUp1::
	applymovement OBJ_EVENT_ID_PLAYER, FallarborTown_Movement_Up1
	waitmovement 0
	return
	
FallarborTown_EventScript_DrystanWalkDown1::
	applymovement LOCALID_DRYSTAN, FallarborTown_Movement_Down1
	waitmovement 0
	return	
	
FallarborTown_EventScript_DrystanWalkDown2::
	applymovement LOCALID_DRYSTAN, FallarborTown_Movement_Down2
	waitmovement 0
	return

FallarborTown_Movement_Up2::
	walk_up
	walk_up
	step_end
	
FallarborTown_Movement_Up1::
	walk_up
	step_end
	
FallarborTown_Movement_Down1::
	walk_down
	step_end
	
FallarborTown_Movement_Down2::
	walk_down
	walk_down
	step_end
	
FallarborTown_Movement_Left1::
	walk_left
	step_end
	
FallarborTown_Movement_Right1::
	walk_right
	step_end
	
FallarborTown_Text_HeyYouThere:
	.string "Hey! You there, wait!$"
	
FallarborTown_Text_IHeardThereIsAStrongTrainer:
	.string "I heard that there is a strong\n"
	.string "TRAINER traveling around here.\p"
	.string "You look like you fit the\n"
	.string "description.\p"
	.string "I'm in dire need of help. Please,\n"
	.string "follow me.$"

FallarborTown_EventScript_DrystansHouseSign:: @ 81EB250
	giveitem ITEM_QUEST_LOG
	questmenu QUEST_MENU_UNLOCK_QUEST SIDE_QUEST_2
	msgbox FallarborTown_Text_DrystansHouseSign, MSGBOX_SIGN
	end
	
tmp::
	playse SE_PIN
	end
	
FallarborTown_Text_DrystansHouseSign:
	.string "DRYSTAN'S HOUSE$"

FallarborTown_EventScript_ExpertM:: @ 81EB20C
// >