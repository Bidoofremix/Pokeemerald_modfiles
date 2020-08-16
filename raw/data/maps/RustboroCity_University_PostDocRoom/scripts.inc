< //
RustboroCity_University_PostDocRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_University_PostDocRoom_OnTransition
	.byte 0

RustboroCity_University_EventScript_PostDoc::
	lockall
	faceplayer
	call_if_unset FLAG_INTRODUCED_MOVE_POSTDOC, RustboroCity_University_EventScript_PostDoc_Introduce
	call_if_set FLAG_INTRODUCED_MOVE_POSTDOC, RustboroCity_University_EventScript_PostDoc_HelloPlayer
	msgbox RustboroCity_University_PostDoc_WouldYouLikeMeToTeachAMove, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, RustboroCity_University_EventScript_PostDoc_ChooseMonAndMoveToTeach
	case NO, RustboroCity_University_EventScript_PostDoc_PleaseComeAgain
	releaseall
	end
	
RustboroCity_University_EventScript_PostDoc_Introduce::
	msgbox RustboroCity_University_PostDoc_HelloIAmAPostDoc, MSGBOX_DEFAULT
	setflag FLAG_INTRODUCED_MOVE_POSTDOC
	end
	
RustboroCity_University_PostDoc_HelloIAmAPostDoc:
	.string "Hello!\p"
	.string "I am a postdoctoral researcher\n"
	.string "here at the UNIVERSITY.\p"
	.string "I am studying POKéMON behaviour\n"
	.string "in relation to move learning.\p"
	.string "I have discovered that an\n"
	.string "individual POKéMON can under\l"
	.string "certain circumstances learn to use\l"
	.string "a new move after observing it.$"

RustboroCity_University_EventScript_PostDoc_HelloPlayer::
	msgbox RustboroCity_University_PostDoc_GoodToSeeyouAgain, MSGBOX_DEFAULT
	end
	
RustboroCity_University_PostDoc_GoodToSeeyouAgain:
	.string "Hello, {PLAYER}!\n"
	.string "It is good to see you again.$"
	
RustboroCity_University_PostDoc_WouldYouLikeMeToTeachAMove:
	.string "Would you like me to teach a new\n"
	.string "move to your POKéMON?$"
	
RustboroCity_University_EventScript_PostDoc_ChooseMonAndMoveToTeach::
	// which mon knows move
	msgbox RustboroCity_University_PostDoc_WhichMoveDoYouWantToTeach, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq RustboroCity_University_EventScript_PostDoc_ComeAgain
	special IsSelectedMonEgg
	compare VAR_RESULT, TRUE
	goto_if_eq Rustboro_University_EventScript_PostDoc_ThatIsAnEgg
	
	// which move
	fadescreen FADE_TO_BLACK
	// selected move will be stored in gSpecialVar_0x8005
	special MoveDeleterChooseMoveToForget
	fadescreen FADE_FROM_BLACK
	BufferMoveDeleterNicknameAndMove
	
	msgbox RustboroCity_University_PostDoc_WhichMonShouldLearnTheMove, MSGBOX_DEFAULT

	// which mon to teach the move
	setvar VAR_0x8005, TUTOR_MOVE_SWAGGER
	call MoveTutor_EventScript_OpenPartyMenu
	
	releaseall
	end
	
RustboroCity_University_PostDoc_WhichMonKnowsTheMove:
	.string "Which POKéMON is is that knows the\n"
	.string "move you want to teach?$"

RustboroCity_University_PostDoc_WhichMonKnowsTheMove:
	.string "And which POKéMON should try to\n"
	.string "learn the move?$"
	
RustboroCity_University_PostDoc_IsThisTheMove:
	.string "{STR_VAR_2!}\n"
	.string "Is this the move you want to teach?$"
	
Rustboro_University_EventScript_PostDoc_ThatIsAnEgg::
	msgbox RustboroCity_University_Text_ICantWorkWithEggs, MSGBOX_DEFAULT
	releaseall
	end
	
RustboroCity_University_PostDoc_WhichMoveDoYouWantToTeach:
	.string "Which move do you want me to teach?$"
	
RustboroCity_University_Text_ICantWorkWithEggs:
	.string "What?\n"
	.string "I can't work with EGGS.$"
	
RustboroCity_University_EventScript_PostDoc_ComeAgain:: @ 821EAE6
	msgbox RustboroCity_University_Text_PostDoc_ComeAgain, MSGBOX_DEFAULT
	releaseall
	end	
	
RustboroCity_University_Text_PostDoc_ComeAgain: @ 821EC3F
	.string "Come again if there are moves that\n"
	.string "you wish to teach.$"	
	
RustboroCity_University_PostDocRoom_OnTransition:
	end
// >