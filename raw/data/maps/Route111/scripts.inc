< //
.set LOCALID_ROCK_SMASH_MAN, 46
.set LOCALID_WALLY, 51

Route111_MapScripts:: @ 81F0CA7
	map_script MAP_SCRIPT_ON_LOAD, Route111_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route111_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route111_OnFrame
	.byte 0

Route111_EventScript_SetRouteState1::
	setvar VAR_ROUTE111_STATE, 1
	end
	
Route111_EventScript_WallyGivesPokeflute::
	lock
	addobject LOCALID_WALLY
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 21
	call_if_eq Route111_EventScript_SetWallyToX21
	compare VAR_TEMP_0, 23
	call_if_eq Route111_EventScript_SetWallyToX23
	applymovement LOCALID_WALLY, Route111_Movement_WallyToPlayer
	waitmovement 0
	delay 16
	msgbox Route111_Text_WallyHelloPlayer, MSGBOX_DEFAULT
	waitmessage
	delay 16
	playse SE_PIN
	applymovement LOCALID_WALLY, Common_Movement_QuestionMark
	waitmovement 0
	delay 20
	msgbox Route111_Text_WallyWhatThereAreMagmaGrunts, MSGBOX_DEFAULT
	giveitem ITEM_POKE_FLUTE
	bufferitemname 0, ITEM_POKE_FLUTE
	delay 16
	msgbox Route111_Text_WallyThisIsThePokeFlute, MSGBOX_DEFAULT
	closemessage
	delay 20
	delay 20
	applymovement LOCALID_WALLY, Route111_Movement_WallyLeave
	waitmovement 0
	removeobject LOCALID_WALLY
	setvar VAR_ROUTE111_STATE, 2
	release
	end
	
Route111_EventScript_SetWallyToX21::
	setobjectxy LOCALID_WALLY, 21, 135
	return
	
Route111_EventScript_SetWallyToX23::
	setobjectxy LOCALID_WALLY, 23, 135
	return	
	
Route111_Text_WallyHelloPlayer:
	.string "WALLY: Hello, {PLAYER}!\n"
	.string "Nice to meet you again so soon.\l"
	.string "How are you doing?$"
	
Route111_Text_WallyWhatThereAreMagmaGrunts:
	.string "… What? TEAM MAGMA is blocking\n"
	.string "the way to LAVARIDGE TOWN?\l"
	.string "Oh no…\p"
	.string "… Listen, I know that you can get\n"
	.string "through another way.\p"
	.string "At ROUTE 116, in SILENT FOREST,\n"
	.string "there's a sleeping POKéMON that\l"
	.string "blocks the way north…\p"
	.string "But I read from a book that you can\n"
	.string "awaken it with a flute.\p"
	.string "… I'm too scared to go there, so\n"
	.string "{PLAYER}, maybe you can use this.$"
	
Route111_Text_WallyThisIsThePokeFlute:
	.string "WALLY: This is a {STR_VAR_1}.\n"
	.string "I found it with Kirlia when we\l"
	.string "were training in the grass.\p"
	.string "… {PLAYER}, please be careful.\n"
	.string "I heard that the POKéMON gets really\l"
	.string "grumpy when it wakes…\p"
	.string "… Well, we'd better get back home\n"
	.string "with Kirlia. I hope that we can\l"
	.string "meet again soon.\p"
	.string "… Please take care, {PLAYER}!$"
	
Route111_Movement_WallyToPlayer::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
	
Route111_Movement_WallyLeave::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end	
	
Route111_EventScript_MagmaGrunt1::
	lock
	faceplayer
	msgbox Route111_Text_MagmaGrunt1, MSGBOX_DEFAULT
	release
	end
	
Route111_EventScript_MagmaGrunt2::
	lock
	faceplayer
	msgbox Route111_Text_MagmaGrunt2, MSGBOX_DEFAULT
	release
	end
	
Route111_EventScript_MagmaGrunt3::
	lock
	faceplayer
	msgbox Route111_Text_MagmaGrunt3, MSGBOX_DEFAULT
	release
	end
	
Route111_EventScript_MagmaGrunt4::
	lock
	faceplayer
	msgbox Route111_Text_MagmaGrunt4, MSGBOX_DEFAULT
	release
	end
	
Route111_Text_MagmaGrunt1::
	.string "Official TEAM MAGMA business here.\n"
	.string "Nothing interesting for you to see.$"
	
Route111_Text_MagmaGrunt2::
	.string "Hey, kiddo! No entry beyond this\n"
	.string "point. Go on, scram!$"
	
Route111_Text_MagmaGrunt3::
	.string "I accidentally ate the BOSS's lunch\n"
	.string "sandwhich, and now I'm on field duty…\p"
	.string "Grumble…$"
	
Route111_Text_MagmaGrunt4::
	.string "Surely you must be thinking,\n"
	.string "“Why are there evil teams everywhere\l"
	.string "blocking my passage?”\p"
	.string "That's just your imagination. Now go\n"
	.string "bother someone else!$"
	
Route111_OnLoad: @ 81F0CBC
// >

< //
Route111_OnTransition: @ 81F0D87
	// custom
	setflag FLAG_HIDE_ROUTE_111_WALLY
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	special SetMirageTowerVisibility
	call_if_unset FLAG_MIRAGE_TOWER_VISIBLE, Route111_EventScript_SetLayoutNoMirageTower
	compare VAR_MIRAGE_TOWER_STATE, 1
	call_if_eq Route111_EventScript_SetFallingPlayerGfx
	compare VAR_MIRAGE_TOWER_STATE, 2
	call_if_eq Route111_EventScript_SetMirageTowerGone
	call Route111_EventScript_CheckSetSandstorm
	call GabbyAndTy_EventScript_UpdateLocation
	goto_if_not_defeated TRAINER_VICKY, Route111_EventScript_SetWinstratesNotDefeated
	end

Route111_EventScript_SetFallingPlayerGfx:: @ 81F0DC2
// >