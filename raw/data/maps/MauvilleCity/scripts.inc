< //
MauvilleCity_Text_WallyWeCanBeatAnyone: @ 81DF963
	.string "WALLY: I'm not pushing it.\p"
	.string "If I combine forces with Kirlia,\n"
	.string "we can beat anyone!$"

MauvilleCity_Text_WallyWillYouBattleMe: @ 81DF9B2
// >

< //
MauvilleCity_EventScript_DefeatedWally:: @ 81DF593
	removeobject LOCALID_WALLY
	removeobject LOCALID_WALLYS_UNCLE
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE
	setflag FLAG_DEFEATED_WALLY_MAUVILLE
	@custom: don't enable wally call until route 111
	@setvar VAR_WALLY_CALL_STEP_COUNTER, 0
	@setflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	compare VAR_FACING, DIR_NORTH
	call_if_eq MauvilleCity_EventScript_ScottApproachPlayerNorth
	compare VAR_FACING, DIR_EAST
	call_if_eq MauvilleCity_EventScript_ScottApproachPlayerEast
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox MauvilleCity_Text_ScottYouDidntHoldBack, MSGBOX_DEFAULT
	closemessage
	addvar VAR_SCOTT_STATE, 1
	compare VAR_FACING, DIR_NORTH
	call_if_eq MauvilleCity_EventScript_ScottExitNorth
	compare VAR_FACING, DIR_EAST
	call_if_eq MauvilleCity_EventScript_ScottExitEast
	removeobject LOCALID_SCOTT
	releaseall
	end

MauvilleCity_EventScript_ScottApproachPlayerNorth:: @ 81DF5F3
// >