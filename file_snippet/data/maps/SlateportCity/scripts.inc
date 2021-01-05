< //
SlateportCity_EventScript_EnterSlateport:: @ 81DCC8D
	setflag FLAG_VISITED_SLATEPORT_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER
	return

.set LOCALID_GENTLEMAN, 36	
	
SlateportCity_EventScript_Gentleman::
	lock
	faceplayer
	msgbox SlateportCity_Text_ThisIsTheBattleTent, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_BATTLE_TENT_STATE, 1
	release
	end
	
SlateportCity_EventScript_IntroduceBattleTent::
	lock
	
	playbgm MUS_FOLLOW_ME, 0
	applymovement LOCALID_GENTLEMAN, Common_Movement_FaceRight
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_GENTLEMAN, Common_Movement_ExclamationMark
	waitmovement 0
	delay 40
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	
	// how many steps right
	applymovement LOCALID_GENTLEMAN, SlateportCity_Movement_Right5
	waitmovement 0	
	compare VAR_TEMP_0, 18
	call_if_ge SlateportCity_EventScript_WalkRight
	compare VAR_TEMP_0, 19
	call_if_eq SlateportCity_EventScript_WalkRight

	// walk up
	applymovement LOCALID_GENTLEMAN, Common_Movement_WalkUp2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	
	// message
	msgbox SlateportCity_Text_YouMustBeATrainer, MSGBOX_DEFAULT
	closemessage

	// walk back to battle tent
	applymovement LOCALID_GENTLEMAN, SlateportCity_Movement_Down2
	waitmovement 0
	compare VAR_TEMP_0, 19
	call_if_eq SlateportCity_EventScript_WalkGentlemanLeft2
	compare VAR_TEMP_0, 18
	call_if_eq SlateportCity_EventScript_WalkGentlemanLeft
	applymovement LOCALID_GENTLEMAN, SlateportCity_Movement_Left5
	waitmovement 0
	applymovement LOCALID_GENTLEMAN, Common_Movement_FaceRight
	waitmovement 0
	
	// walk player down
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_Down3
	waitmovement 0
	
	// walk player left
	compare VAR_TEMP_0, 19
	call_if_eq SlateportCity_EventScript_WalkPlayerLeft2
	compare VAR_TEMP_0, 18
	call_if_eq SlateportCity_EventScript_WalkPlayerLeft
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_Left4
	waitmovement 0
	
	delay 10
	msgbox SlateportCity_Text_ThisIsTheBattleTent, MSGBOX_DEFAULT
	closemessage
	
	fadedefaultbgm
	setvar VAR_SLATEPORT_BATTLE_TENT_STATE, 1
	release
	end
	
SlateportCity_EventScript_WalkRight::
	applymovement LOCALID_GENTLEMAN, SlateportCity_Movement_Right1
	waitmovement 0
	return
	
SlateportCity_EventScript_WalkGentlemanLeft::
	applymovement LOCALID_GENTLEMAN, SlateportCity_Movement_Left1
	waitmovement 0
	return	
	
SlateportCity_EventScript_WalkGentlemanLeft2::
	applymovement LOCALID_GENTLEMAN, SlateportCity_Movement_Left1
	waitmovement 0
	applymovement LOCALID_GENTLEMAN, SlateportCity_Movement_Left1
	waitmovement 0
	return
	
SlateportCity_EventScript_WalkPlayerLeft::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_Left1
	waitmovement 0
	return		
	
SlateportCity_EventScript_WalkPlayerLeft2::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_Left1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_Left1
	waitmovement 0
	return	
	
SlateportCity_Movement_Right5:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end
	
SlateportCity_Movement_Right1:
	walk_right
	step_end
	
SlateportCity_Movement_Left5:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end
	
SlateportCity_Movement_Left4:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end
	
SlateportCity_Movement_Left1:
	walk_left
	step_end
	
SlateportCity_Movement_Down2:
	walk_down
	walk_down
	step_end
	
SlateportCity_Movement_Down3:
	walk_down
	walk_down
	walk_down
	step_end
	
SlateportCity_Text_YouMustBeATrainer:
	.string "Hello, youngling! You look\n"
	.string "like a TRAINER.\p"
	.string "I want to inform you of a very\n"
	.string "useful facility. Please follow me.$"
	
SlateportCity_Text_ThisIsTheBattleTent:
	.string "This is the renewed BATTLE TENT.\p"
	.string "You may have visited here before,\n"
	.string "but the BATTLE CHALLENGE has\l"
	.string "been completely redesigned.\p"
	.string "No one has conquered all of the\n"
	.string "challenges yet.\l"
	.string "Maybe you will be the first one!$"
	
SlateportCity_EventScript_MovePeopleForSternInterview:: @ 81DCC99
// >