< //
PetalburgCity_Gym_OnLoad: @ 820489E
	compare VAR_PETALBURG_GYM_STATE, 6
	goto_if_eq PetalburgCity_Gym_EventScript_OpenUnlockedDoors
	compare VAR_PETALBURG_GYM_STATE, 7
	call_if_ge PetalburgCity_Gym_EventScript_UnlockAllDoors
	end

PetalburgCity_Gym_OnTransition: @ 820489E
	call_if_set FLAG_RECEIVED_VERDANTURF_EGG, PetalburgCity_Gym_MapScript_GymAccessible
	call_if_set FLAG_NORMAN_INTRODUCED_GYM, PetalburgCity_Gym_EventScript_NormanAtBattleField
	end
	
PetalburgCity_Gym_EventScript_NormanAtBattleField::
	clearflag FLAG_HIDE_PETALBURG_GYM_NORMAN
	showobjectat 1, MAP_PETALBURG_CITY_GYM
	setobjectxyperm 1, 4, 2
	setvar VAR_0x8000, 1
	return
	end
	
PetalburgCity_Gym_MapScript_GymAccessible::
	setmetatile 5, 16, 540, 1
	setmetatile 5, 17, 548, 1
	setvar VAR_0x8000, 1
	end	
	
@ NOTE: Strength and OHKO rooms are misleading. Both are more accurately Critical-Hit
PetalburgCity_Gym_EventScript_OpenUnlockedDoors:: @ 82048B5
// >

@ NOTE: Strength and OHKO rooms are misleading. Both are more accurately Critical-Hit
PetalburgCity_Gym_EventScript_OpenUnlockedDoors:: @ 82048B5
	setvar VAR_0x8005, 1
	call PetalburgCity_Gym_EventScript_OpenGymEntranceDoors
	call_if_defeated TRAINER_RANDALL, PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors
	call_if_defeated TRAINER_MARY, PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors
	call_if_defeated TRAINER_PARKER, PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors
	call_if_defeated TRAINER_ALEXIA, PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors
	call_if_defeated TRAINER_GEORGE, PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors
	call_if_defeated TRAINER_JODY, PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors
	call_if_defeated TRAINER_BERKE, PetalburgCity_Gym_EventScript_OpenOHKORoomDoors
	end

PetalburgCity_Gym_EventScript_UnlockAllDoors:: @ 82048FF
	setvar VAR_0x8005, 1
	call PetalburgCity_Gym_EventScript_OpenGymEntranceDoors
	call PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors
	call PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors
	call PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors
	call PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors
	call PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors
	call PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors
	call PetalburgCity_Gym_EventScript_OpenOHKORoomDoors
	return

PetalburgCity_Gym_OnTransition: @ 820492D
	compare VAR_PETALBURG_GYM_STATE, 1
	call_if_eq PetalburgCity_Gym_EventScript_MoveWallyToEntrance
	compare VAR_PETALBURG_GYM_STATE, 6
	call_if_lt PetalburgCity_Gym_EventScript_MoveNormanToEntrance
	call_if_set FLAG_SYS_GAME_CLEAR, PetalburgCity_Gym_EventScript_CheckNormanForRematch
	end

PetalburgCity_Gym_EventScript_MoveWallyToEntrance:: @ 820494D
	setobjectxyperm 10, 5, 108
	return

PetalburgCity_Gym_EventScript_MoveNormanToEntrance:: @ 8204955
	setobjectxyperm 1, 4, 107
	return

PetalburgCity_Gym_EventScript_CheckNormanForRematch:: @ 820495D
	setorcopyvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_NORMAN_1
	specialvar VAR_RESULT, IsTrainerReadyForRematch
	compare VAR_RESULT, TRUE
	goto_if_eq PetalburgCity_Gym_EventScript_DontMoveNormanToFront
	compare VAR_PETALBURG_GYM_STATE, 8
	goto_if_eq PetalburgCity_Gym_EventScript_DontMoveNormanToFront
	setobjectxyperm 1, 4, 107
	return

PetalburgCity_Gym_EventScript_DontMoveNormanToFront:: @ 8204985
	setvar VAR_PETALBURG_GYM_STATE, 8
	end

PetalburgCity_Gym_OnWarp: @ 820498B
	map_script_2 VAR_PETALBURG_GYM_STATE, 1, PetalburgCity_Gym_EventScript_TurnPlayerNorth
	.2byte 0

PetalburgCity_Gym_EventScript_TurnPlayerNorth:: @ 8204995
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

PetalburgCity_Gym_OnFrame: @ 820499A
	map_script_2 VAR_PETALBURG_GYM_STATE, 1, PetalburgCity_Gym_EventScript_ReturnFromWallyTutorial
	.2byte 0

PetalburgCity_Gym_EventScript_ReturnFromWallyTutorial:: @ 82049A4
	lockall
	msgbox PetalburgCity_Gym_Text_DadSoDidItWorkOut, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_WallyThankYouBye, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	applymovement 10, PetalburgCity_Gym_Movement_WallyExitGym
	waitmovement 0
	playse SE_KAIDAN
	removeobject 10
	setflag FLAG_HIDE_PETALBURG_CITY_WALLY
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox PetalburgCity_Gym_Text_DadGoHelpBreeder, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_GYM_STATE, 2
	releaseall
	end

PetalburgCity_Gym_Movement_WallyExitGym: @ 82049EC
	walk_down
	walk_down
	walk_down
	delay_16
	step_end

PetalburgCity_Gym_EventScript_Norman:: @ 82049F1
	lock
	faceplayer
	switch VAR_PETALBURG_GYM_STATE
	case 2, PetalburgCity_Gym_EventScript_NormanNoBadges
	case 3, PetalburgCity_Gym_EventScript_NormanOneBadge
	case 4, PetalburgCity_Gym_EventScript_NormanTwoBadges
	case 5, PetalburgCity_Gym_EventScript_NormanThreeBadges
	case 6, PetalburgCity_Gym_EventScript_NormanBattle
	case 7, PetalburgCity_Gym_EventScript_NormanPostBattle
	case 8, PetalburgCity_Gym_EventScript_NormanRematch
	msgbox PetalburgCity_Gym_Text_DadYoureHereWithYourPokemon, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case DIR_SOUTH, PetalburgCity_Gym_EventScript_BeginWallyTutorialSouth
	case DIR_NORTH, PetalburgCity_Gym_EventScript_BeginWallyTutorialNorth
	case DIR_WEST, PetalburgCity_Gym_EventScript_BeginWallyTutorialWest
	case DIR_EAST, PetalburgCity_Gym_EventScript_BeginWallyTutorialEast
	end

PetalburgCity_Gym_EventScript_BeginWallyTutorialSouth:: @ 8204A80
	setvar VAR_0x8008, 0
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorial
	end

PetalburgCity_Gym_EventScript_BeginWallyTutorialNorth:: @ 8204A8B
	setvar VAR_0x8008, 1
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorial
	end

PetalburgCity_Gym_EventScript_BeginWallyTutorialWest:: @ 8204A96
	setvar VAR_0x8008, 2
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorial
	end

PetalburgCity_Gym_EventScript_BeginWallyTutorialEast:: @ 8204AA1
	setvar VAR_0x8008, 3
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorial
	end

PetalburgCity_Gym_EventScript_BeginWallyTutorial:: @ 8204AAC
	addobject 10  @ Wally
	playse SE_DOOR
	compare VAR_0x8008, 0
	call_if_eq PetalburgCity_Gym_EventScript_WallyArriveSouth
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_Gym_EventScript_WallyArriveNorth
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_Gym_EventScript_WallyArriveWestEast
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_Gym_EventScript_WallyArriveWestEast
	msgbox PetalburgCity_Gym_Text_WallyIdLikeAPokemon, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_DadOhYoureWallyRight, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_WallyIveNeverCaughtAPokemon, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_DadHmISee, MSGBOX_DEFAULT
	compare VAR_0x8008, 0
	call_if_eq PetalburgCity_Gym_EventScript_NormanAddressPlayerSouth
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_Gym_EventScript_NormanAddressPlayerNorth
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_Gym_EventScript_NormanAddressPlayerWest
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_Gym_EventScript_NormanAddressPlayerEast
	msgbox PetalburgCity_Gym_Text_DadPlayerGoWithWally, MSGBOX_DEFAULT
	compare VAR_0x8008, 0
	call_if_eq PetalburgCity_Gym_EventScript_NormanAddressWallySouth
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_Gym_EventScript_NormanAddressWallyNorth
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_Gym_EventScript_NormanAddressWallyWest
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_Gym_EventScript_NormanAddressWallyEast
	msgbox PetalburgCity_Gym_Text_IllLoanYouMyZigzagoon, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_WallyThankYouAndDadGivesPokeBall, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_WallyOhWowThankYou, MSGBOX_DEFAULT
	compare VAR_0x8008, 0
	call_if_eq PetalburgCity_Gym_EventScript_NormanFaceDoorSouth
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_Gym_EventScript_NormanFaceDoorNorth
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_Gym_EventScript_NormanFaceDoorWest
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_Gym_EventScript_NormanFaceDoorEast
	compare VAR_0x8008, 0
	call_if_eq PetalburgCity_Gym_EventScript_WallyFacePlayer
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_Gym_EventScript_WallyFaceDown
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_Gym_EventScript_WallyFacePlayer
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_Gym_EventScript_WallyFacePlayer
	msgbox PetalburgCity_Gym_Text_WouldYouReallyComeWithMe, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_DONT_TRANSITION_MUSIC
	playbgm MUS_TSURETEK, 0
	compare VAR_0x8008, 0
	call_if_eq PetalburgCity_Gym_EventScript_ExitGymWithWallySouth
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_Gym_EventScript_ExitGymWithWallyNorth
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_Gym_EventScript_ExitGymWithWallyWest
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_Gym_EventScript_ExitGymWithWallyEast
	removeobject 10
	setflag FLAG_HIDE_PETALBURG_CITY_WALLYS_AUNT
	setvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_PETALBURG_CITY_STATE, 2
	clearflag FLAG_HIDE_PETALBURG_CITY_WALLY
	clearflag FLAG_HIDE_PETALBURG_GYM_WALLY
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
	special InitBirchState
	warp MAP_PETALBURG_CITY, 255, 15, 8
	waitstate
	release
	end

PetalburgCity_Gym_EventScript_WallyArriveSouth:: @ 8204C31
	applymovement 1, Common_Movement_WalkInPlaceFastestDown
	applymovement 10, PetalburgCity_Gym_Movement_WallyArrive
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallyArriveNorth:: @ 8204C43
	applymovement 10, PetalburgCity_Gym_Movement_WallyArriveNorth
	waitmovement 0
	applymovement 1, Common_Movement_WalkInPlaceFastestRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallyArriveWestEast:: @ 8204C5F
	applymovement 1, Common_Movement_WalkInPlaceFastestDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	applymovement 10, PetalburgCity_Gym_Movement_WallyArrive
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallySouth:: @ 8204C78
	applymovement 1, Common_Movement_WalkInPlaceFastestDown
	applymovement 10, PetalburgCity_Gym_Movement_WallyExitSouthWest
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallySouth
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallyNorth:: @ 8204C91
	applymovement 10, PetalburgCity_Gym_Movement_WallyExitNorth
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyNorth
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallyWest:: @ 8204CA3
	applymovement 10, PetalburgCity_Gym_Movement_WallyExitSouthWest
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyWest
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallyEast:: @ 8204CB5
	applymovement 10, PetalburgCity_Gym_Movement_WallyExitEast
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyEast
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressPlayerSouth:: @ 8204CC7
	applymovement 1, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressPlayerNorth:: @ 8204CD2
	applymovement 1, Common_Movement_WalkInPlaceFastestDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressPlayerWest:: @ 8204CE4
	applymovement 1, Common_Movement_WalkInPlaceFastestRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressPlayerEast:: @ 8204CF6
	applymovement 1, Common_Movement_WalkInPlaceFastestLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressWallySouth:: @ 8204D08
	applymovement 1, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressWallyNorth:: @ 8204D13
	applymovement 1, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressWallyWest:: @ 8204D1E
	applymovement 1, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressWallyEast:: @ 8204D29
	applymovement 1, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallyFacePlayer:: @ 8204D34
	applymovement 10, Common_Movement_FacePlayer
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallyFaceDown:: @ 8204D3F
	applymovement 10, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

< //
PetalburgCity_Gym_EventScript_NormanNoBadges:: @ 8204D4A
	msgbox PetalburgCity_Gym_Text_NormanGoHelpBreeder, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_NormanOneBadge:: @ 8204D54
// >
	msgbox PetalburgCity_Gym_Text_NormanGoToDewford, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_NormanTwoBadges:: @ 8204D5E
	msgbox PetalburgCity_Gym_Text_YouHaveGottenStronger, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_NormanThreeBadges:: @ 8204D68
	msgbox PetalburgCity_Gym_Text_YouHaveGottenStronger, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_NormanFaceDoorSouth:: @ 8204D72
	return

@ For all other NormanFaceDoorX, Norman is already facing the door from NormanAddressWallyX
PetalburgCity_Gym_EventScript_NormanFaceDoorNorth:: @ 8204D73
	applymovement 1, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanFaceDoorWest:: @ 8204D7E
	return

PetalburgCity_Gym_EventScript_NormanFaceDoorEast:: @ 8204D7F
	return

PetalburgCity_Gym_EventScript_NormanPostBattle:: @ 8204D80
	call PetalburgCity_Gym_EventScript_ShouldGiveEnigmaBerry
	compare VAR_RESULT, TRUE
	goto_if_eq PetalburgCity_Gym_EventScript_GiveEnigmaBerry
	goto_if_unset FLAG_RECEIVED_TM42, PetalburgCity_Gym_EventScript_GiveFacade2
	goto_if_set FLAG_SYS_GAME_CLEAR, PetalburgCity_Gym_EventScript_NoAmountOfTrainingIsEnough
	msgbox PetalburgCity_Gym_Text_DadGoingToKeepTraining, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_GiveFacade2:: @ 8204DAC
	call PetalburgCity_Gym_EventScript_GiveFacade
	release
	end

PetalburgCity_Gym_EventScript_NormanRematch:: @ 8204DB3
	trainerbattle_rematch_double TRAINER_NORMAN_1, PetalburgCity_Gym_Text_NormanPreRematch, PetalburgCity_Gym_Text_NormanRematchDefeat, PetalburgCity_Gym_Text_NormanRematchNeedTwoMons
	msgbox PetalburgCity_Gym_Text_NormanPostRematch, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_ShouldGiveEnigmaBerry:: @ 8204DCE
	specialvar VAR_RESULT, IsEnigmaBerryValid
	compare VAR_RESULT, FALSE
	goto_if_eq PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
	checkitem ITEM_ENIGMA_BERRY, 1
	compare VAR_RESULT, TRUE
	goto_if_eq PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
	checkpcitem ITEM_ENIGMA_BERRY, 1
	compare VAR_RESULT, TRUE
	goto_if_eq PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
	compare VAR_ENIGMA_BERRY_AVAILABLE, 0
	goto_if_eq PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
	msgbox PetalburgCity_Gym_Text_GiveEnigmaBerry, MSGBOX_DEFAULT
	setvar VAR_RESULT, TRUE
	return

PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry:: @ 8204E17
	setvar VAR_RESULT, FALSE
	return

PetalburgCity_Gym_EventScript_GiveEnigmaBerry:: @ 8204E1D
	giveitem ITEM_ENIGMA_BERRY
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setvar VAR_ENIGMA_BERRY_AVAILABLE, 0
	release
	end

PetalburgCity_Gym_EventScript_NormanBattle:: @ 8204E3B
	goto_if_unset FLAG_NORMAN_INTRODUCED_GYM, PetalburgCity_Gym_EventScript_NormanIntroducesGym
	// VAR_TEMP_1: how many trainers have been battled
	setvar VAR_TEMP_1, 0
	checktrainerflag TRAINER_BERKE
	call_if_eq PetalburgCity_Gym_EventScript_CountTrainers
	checktrainerflag TRAINER_JODY
	call_if_eq PetalburgCity_Gym_EventScript_CountTrainers
	compare VAR_TEMP_1, 2
	goto_if_eq PetalburgCity_Gym_EventScript_InitiateBattle
	msgbox PetalburgCity_Gym_Text_NotDefeatedTrainers, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_InitiateBattle::
	msgbox PetalburgCity_Gym_Text_YouDefeatedGymTrainers, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_NORMAN_1, PetalburgCity_Gym_Text_NormanDefeat
	message PetalburgCity_Gym_Text_ReceivedBalanceBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox PetalburgCity_Gym_Text_ExplainBalanceBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_PETALBURG_GYM
	setvar VAR_PETALBURG_GYM_STATE, 7
	setflag FLAG_BADGE05_GET
	clearflag FLAG_HIDE_DEWFORD_HALL_SLUDGE_BOMB_MAN
	call PetalburgCity_Gym_EventScript_UnlockAllDoors
	special DrawWholeMapView
	call PetalburgCity_Gym_EventScript_GiveFacade
	delay 30
	msgbox PetalburgCity_Gym_Text_DadHappyAndSad, MSGBOX_DEFAULT
	delay 30
	msgbox PetalburgCity_Gym_Text_TheNextGymIsAtRustboro, MSGBOX_DEFAULT
	release
	end
	
PetalburgCity_Gym_EventScript_CountTrainers::
	addvar VAR_TEMP_1, 1
	return	

PetalburgCity_Gym_EventScript_NormanIntroducesGym::
	msgbox PetalburgCity_Gym_Text_HowWasVerdanturf, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Movement_Norman_ToDoor
	waitmovement 0
	opendoor 5, 17
	waitdooranim
	applymovement 1, Movement_Norman_ToDoor
	waitmovement 0
	removeobject 1
	setflag FLAG_HIDE_PETALBURG_GYM_NORMAN
	closedoor 5, 17
	waitdooranim
	setflag FLAG_NORMAN_INTRODUCED_GYM
	clearflag FLAG_HIDE_PETALBURG_GYM_GREETER
	release
	end

Movement_Norman_ToDoor:
	walk_up
	step_end
	
PetalburgCity_Gym_EventScript_GiveFacade:: @ 8204ED2
// >

< //
PetalburgCity_Gym_Text_NormanGoToRustboro: @ 8205DB4
	.string "DAD: Hm? Aren't you going to the\n"
	.string "POKéMON GYM in RUSTBORO CITY?\p"
	.string "There's no challenge for me to\n"
	.string "battle a greenhorn TRAINER.\p"
	.string "{PLAYER}, I want you to challenge me\n"
	.string "when you become a lot stronger.\p"
	.string "I'll battle you, {PLAYER}, when you\n"
	.string "can show me four GYM BADGES, okay?$"

PetalburgCity_Gym_Text_DadGoHelpBreeder: @ 8205C40
	.string "DAD: Now…\p"
	.string "{PLAYER}, if you want to become a\n"
	.string "strong TRAINER, here's my advice.\p"
	.string "Head for VERDANTURF TOWN, through\n"
	.string "ALTERING CAVE.\p"
	.string "There's a POKéMON BREEDER at the\n"
	.string "BREEDER's CLUB that needs help.\p"
	.string "After that, we can have an official\n"
	.string "battle here at the GYM.$"
	.string "So, off you go, then!$

PetalburgCity_Gym_Text_NormanGoToVerdanturf: @ 8205DB4
	.string "DAD: Hm? Aren't you going to the\n"
	.string "BREEDER's CLUB in VERDANTURF?\l"
	.string "There's a lady who needs your help.\n"
	.string "I'll battle you, {PLAYER}, when you\n"
	.string "have visited VERDANTURF TOWN, okay?$"

PetalburgCity_Gym_Text_HowWasVerdanturf: @ 8205FE5
	.string "So, how was VERDANTURF TOWN?\p"
	.string "Oh, you got an EGG? You should carry\n"
	.string "it with you and it will hatch when\l"
	.string "it is mature.\p"
	.string "But now, we will battle. As per the\n"
	.string "official protocol, I will stand at the\l"
	.string "battlefield.\p"
	.string "At a POKéMON GYM, you will always\n"
	.string "face TRAINERS before the LEADER.\p"
	.string "To prove your strength, beat the other\n"
	.string "TRAINERS. Only then can you battle the\l"
	.string "GYM LEADER.\p"
	.string "{PLAYER}, good luck!$"	

PetalburgCity_Gym_Text_NotDefeatedTrainers:
	.string "DAD: Well, aren't you enthusiastic!\p"
	.string "Beat the two TRAINERS in this room\n"
	.string "first, and then we will battle.$"
	
PetalburgCity_Gym_Text_YouDefeatedGymTrainers:
	.string "DAD: Hm…\n"
	.string "So, you did defeat the GYM TRAINERS.\p"
	.string "Fine, as I promised, we will have\n"
	.string "a POKéMON battle.\p"
	.string "I will do everything in my power as\n"
	.string "a GYM LEADER to win.\p"
	.string "{PLAYER}, you'd better give it your\n"
	.string "best shot, too!$"	

PetalburgCity_Gym_Text_TheNextGymIsAtRustboro:
	.string "Now, you defeated me truly and\n"
	.string "completely.\p"
	.string "But I'm just one of the eight\n"
	.string "GYM LEADERS.\p"
	.string "If you want to keep getting\n"
	.string "stronger, the next GYM is in \l"
	.string "RUSTBORO CITY.\p"
	.string "Go west of PETALBURG and you\n"
	.string "should find it easily enough.\p"
	.string "Give ROXANNE my greetings,\n"
	.string "{PLAYER}!$"
	
PetalburgCity_Gym_Text_NormanGoToDewford: @ 8205EAE
// >

< //
PetalburgCity_Gym_Text_GymGuideAdvice: @ 8206542
	.string "Hey, how's it going, novice TRAINER?\p"
	.string "Before facing the GYM LEADER, you\n"
	.string "have to defeat the GYM TRAINERS.\p"
	.string "They have tough POKéMON, so you\n"
	.string "need to be well prepared.\p"
	.string "Good luck, {PLAYER}!$"

PetalburgCity_Gym_Text_GymGuidePostVictory: @ 82066F3
// >

< //
PetalburgCity_Gym_Text_BerkeIntro: @ 8206BF4
	.string "I'm not going to take it easy just\n"
	.string "because you're our LEADER's kid.\p"
	.string "Come on, show me what you've got!$"

PetalburgCity_Gym_Text_BerkeDefeat: @ 8206C7D
// >

< //
PetalburgCity_Gym_Text_JodyPostBattle: @ 82070FB
	.string "The way you use your POKéMON…\n"
	.string "It's like your father's style.\p"
	.string "Go on! The GYM LEADER, your father,\n"
	.string "is waiting!$"

PetalburgCity_Gym_Text_JodyPostBadge: @ 8207170
// >