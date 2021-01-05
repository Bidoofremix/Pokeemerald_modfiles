< //
SlateportCity_BattleTentLobby_EventScript_TurnPlayerNorth:: @ 8208745
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

SlateportCity_BattleTentLobby_EventScript_ScoreBoard::
	lock
	release
	end
	
SlateportCity_BattleTentLobby_EventScript_InitiateChallenge::
	lock
	faceplayer
	msgbox SlateportCity_BattleTentLobby_Text_ThisIsTheBattleTent, MSGBOX_DEFAULT
	waitmessage
	multichoice 0, 0, MULTI_SINGLE_DOUBLE, 0
	switch VAR_RESULT
	case 0, SlateportCity_BattleTentLobby_EventScript_SingleBattleChallenge
	case 1, SlateportCity_BattleTentLobby_EventScript_DoubleBattleChallenge
	case 2, SlateportCity_BattleTentLobby_EventScript_CancelBattleChallenge
	goto SlateportCity_BattleTentLobby_EventScript_CancelBattleChallenge
	release
	end
	
SlateportCity_BattleTentLobby_EventScript_SingleBattleChallenge::
	msgbox single_test, MSGBOX_DEFAULT
	waitmessage
	multichoice 0, 0, MULTI_SINGLE_CHALLENGES, 0
	switch VAR_RESULT
	release
	end
	
SlateportCity_BattleTentLobby_EventScript_DoubleBattleChallenge::
	msgbox double_test, MSGBOX_DEFAULT
	release
	end
	
SlateportCity_BattleTentLobby_EventScript_CancelBattleChallenge::	
	release
	end
	
single_test:
	.string "Single battle$"
	
double_test:
	.string "Double battle$"
	
SlateportCity_BattleTentLobby_Text_ThisIsTheBattleTent:
	.string "Hello! This is the BATTLE TENT.\n"
	.string "Here you can take on advanced\l"
	.string "challenges and try to overcome them\l"
	.string "with your best strategies.\p"
	.string "Now, what kind of challenge do you\n"
	.string "wish to undertake?$"
	
SlateportCity_BattleTentLobby_OnFrame: @ 820874F
// >

< //
SlateportCity_BattleTentLobby_Text_BattleEvenWithoutToughMons: @ 8208DA6
	.string "You can battle all you want here even\n"
	.string "if you don't have any tough POKéMON.\p"
	.string "Sometimes strategy is everything.$"

SlateportCity_BattleTentLobby_Text_NiceIfMoreSelection: @ 8208DF1
	.string "The BATTLE CHALLENGES are so hard...\p"
	.string "Wouldn't it be nice if they offered\n"
	.string "rental POKéMON for use?$"
// > END