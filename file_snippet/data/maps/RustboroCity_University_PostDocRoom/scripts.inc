< //
RustboroCity_University_PostDocRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_University_PostDocRoom_OnTransition
	.byte 0

RustboroCity_University_EventScript_Kirlia::
	lock
	faceplayer
	playmoncry SPECIES_KIRLIA, 0
	msgbox RustboroCity_University_Text_Kirlia, MSGBOX_DEFAULT
	release
	end
	
RustboroCity_University_Text_Kirlia:
	.string "Kiih!$"
	
RustboroCity_University_EventScript_PostDoc::
	lock
	faceplayer
	call_if_set FLAG_INTRODUCED_MOVE_POSTDOC, RustboroCity_University_EventScript_PostDoc_HelloPlayer
	call_if_unset FLAG_INTRODUCED_MOVE_POSTDOC, RustboroCity_University_EventScript_PostDoc_Introduce

	showmoneybox 0, 0, 0
	msgbox RustboroCity_University_PostDoc_WouldYouLikeMeToTeachAMove, MSGBOX_YESNO

	switch VAR_RESULT
	case YES, RustboroCity_University_EventScript_PostDoc_ChooseMonAndMoveToTeach
	case NO, RustboroCity_University_EventScript_PostDoc_ComeAgain
	release
	end
	
RustboroCity_University_EventScript_PostDoc_Introduce::
	msgbox RustboroCity_University_PostDoc_HelloIAmAPostDoc, MSGBOX_DEFAULT
	setflag FLAG_INTRODUCED_MOVE_POSTDOC
	return
	
RustboroCity_University_PostDoc_HelloIAmAPostDoc:
	.string "Hello!\p"
	.string "I am a postdoctoral researcher here\n"
	.string "at the UNIVERSITY.\p"
	.string "I am studying POKéMON behaviour\n"
	.string "in relation to move learning.\p"
	.string "I have discovered that an individual\n"
	.string "POKéMON can in certain situations\l"
	.string "learn a new move by observing it.$"

RustboroCity_University_EventScript_PostDoc_HelloPlayer::
	msgbox RustboroCity_University_PostDoc_GoodToSeeyouAgain, MSGBOX_DEFAULT
	return
	
RustboroCity_University_PostDoc_GoodToSeeyouAgain:
	.string "Hello, {PLAYER}!\n"
	.string "It is good to see you again.$"
	
RustboroCity_University_PostDoc_WouldYouLikeMeToTeachAMove:
	.string "For ¥500, I can teach your POKéMON a\n"
	.string "new move. Is that okay?$"
	
RustboroCity_University_EventScript_PostDoc_ChooseMonAndMoveToTeach::
	// money check
	checkmoney 500, 0
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_University_EventScript_PostDoc_NotEnoughMoney
	
	// which mon knows move
	msgbox RustboroCity_University_PostDoc_WhichMoveDoYouWantToTeach, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	faceplayer
	compare VAR_0x8004, 255
	goto_if_eq RustboroCity_University_EventScript_PostDoc_ComeAgain
	special IsSelectedMonEgg
	compare VAR_RESULT, TRUE
	goto_if_eq Rustboro_University_EventScript_PostDoc_ThatIsAnEgg
	
	// which move
	fadescreen FADE_TO_BLACK
	// selected move position be stored in VAR_0x8005 after this
	special MoveDeleterChooseMoveToForget
	fadescreen FADE_FROM_BLACK
	faceplayer
	compare VAR_0x8005, MAX_MON_MOVES
	goto_if_eq RustboroCity_University_EventScript_PostDoc_ChooseMonAndMoveToTeach
	
	// selected move position is converted to actual move
	special SetMoveForPostDocTutor
	
	// which mon to teach the move
	msgbox RustboroCity_University_PostDoc_WhichMonShouldLearnTheMove, MSGBOX_DEFAULT
	
	// teach the move
	// set VAR_0x800B to 1 for special mode in 
	// TryTutorSelectedMon and DisplayPartyPokemonDataToTeachMove
	//setvar VAR_0x800B, 1
	setvar VAR_0x800B, MODE_MOVE_TUTOR_POSTDOC
	call MoveTutor_EventScript_OpenPartyMenu
	
	// more dialogue here
	// check if tutoring happened -> "success, your pkmn learned this"
	// take money
	faceplayer
	compare VAR_RESULT, 0
	goto_if_eq RustboroCity_University_EventScript_PostDoc_ComeAgain
	msgbox RustboroCity_University_PostDoc_ThatWillBe500, MSGBOX_DEFAULT
	showmoneybox 0, 0, 0
	delay 40
	playse SE_SHOP
	removemoney 500, 0
	updatemoneybox 0, 0
	delay 40
	delay 40
	hidemoneybox
	msgbox RustboroCity_University_Text_PostDoc_ComeAgain, MSGBOX_DEFAULT
	release
	end
	
RustboroCity_University_EventScript_PostDoc_NotEnoughMoney::
	msgbox Route121_SafariZoneEntrance_Text_NotEnoughMoney, MSGBOX_DEFAULT
	release
	end
	
Rustboro_University_EventScript_PostDoc_ThatIsAnEgg::
	msgbox RustboroCity_University_Text_ICantWorkWithEggs, MSGBOX_DEFAULT
	release
	end
	
RustboroCity_University_PostDoc_WhichMoveDoYouWantToTeach:
	.string "Which move do you want me to teach?$"
	
RustboroCity_University_PostDoc_WhichMonShouldLearnTheMove:
	.string "And which POKéMON should try to\n"
	.string "learn that move?$"
	
RustboroCity_University_Text_ICantWorkWithEggs:
	.string "What?\n"
	.string "I can't work with EGGS.$"
	
RustboroCity_University_PostDoc_ThatWillBe500:
	.string "Success!\p"
	.string "Your {STR_VAR_1} learned {STR_VAR_2}.\p"
	.string "That will be ¥500, then.$"
	
RustboroCity_University_EventScript_PostDoc_ComeAgain:: @ 821EAE6
	faceplayer
	hidemoneybox
	msgbox RustboroCity_University_Text_PostDoc_ComeAgain, MSGBOX_DEFAULT
	release
	end
	
RustboroCity_University_Text_PostDoc_ComeAgain: @ 821EC3F
	.string "Come again if there are moves that\n"
	.string "you wish to teach.$"	
	
RustboroCity_University_PostDocRoom_OnTransition:
	end
// > END