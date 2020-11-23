< //
RustboroCity_Gym_EventScript_GiveRockTomb:: @ 8212FA4
	giveitem ITEM_TM39
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM39
	msgbox RustboroCity_Gym_Text_ExplainRockTomb, MSGBOX_DEFAULT
	questmenu QUEST_MENU_UNLOCK_QUEST SIDE_QUEST_13
	questmenu QUEST_MENU_UNLOCK_QUEST SIDE_QUEST_16
	call NoteNewQuestSeveral
	release
	end

RustboroCity_Gym_EventScript_RoxanneRematch:: @ 8212FC8
// >

< //
RustboroCity_Gym_Text_GymGuideAdvice: @ 821309D
	.string "Yo, how's it going?\p"
	.string "Listen, my friend!\n"
	.string "The ROCK type is very durable, but\l"
	.string "it can't stand WATER-type and\l"
	.string "GRASS-type moves.\p"
	.string "Well, go for it!$"

RustboroCity_Gym_Text_GymGuidePostVictory: @ 82132E2
	.string "Whoa! What a breathtaking victory!\n"
	.string "My cheering must've worked!$"

RustboroCity_Gym_Text_JoshIntro: @ 82133E9
// >