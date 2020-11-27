< //
GraniteCave_StevensRoom_MapScripts:: @ 822DC7A
	.byte 0

GraniteCave_EventScript_ProfStoneCall::
	lockall
	pokenavcall GraniteCave_Text_ProfStonePokenavCall
	waitmessage
	clearflag FLAG_ENABLE_PROF_STONE_POKENAV_CALL
	releaseall
	end

GraniteCave_Text_ProfStonePokenavCall:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "PROF. STONE: Hello, {PLAYER}!\p"
	.string "STEVEN informed me that you\n"
	.string "delivered the Letter to him.\l"
	.string "Thank you!\p"
	.string "Please come visit me at the\n"
	.string "UNIVERSITY so that I can give\l"
	.string "you a reward for your good work!\p"
	.string "See you soon, {PLAYER}!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"
	
GraniteCave_StevensRoom_EventScript_Steven:: @ 822DC7B
	lock
	faceplayer
	msgbox GraniteCave_StevensRoom_Text_ImStevenLetterForMe, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_LETTER
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_ENABLE_PROF_STONE_POKENAV_CALL
	setvar VAR_PROF_STONE_CALL_STEP_COUNTER, 0
	setflag FLAG_DELIVERED_STEVEN_LETTER
// >