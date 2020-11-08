< // START

.set LOCALID_DRYSTAN, 1

NavelRock_Up1_MapScripts:: @ 826910F
	map_script MAP_SCRIPT_ON_TRANSITION, NavelRock_Up1_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NavelRock_Up1_OnFrame
	.byte 0

NavelRock_Up1_OnTransition::
	compare VAR_MEWTWO_QUESTLINE_STATE, 1
	call_if_eq FallarborTown_DrystansHouse_EventScript_PutDrystanToChair
	end
	
FallarborTown_DrystansHouse_EventScript_PutDrystanToChair::
	setobjectxyperm LOCALID_DRYSTAN, 4, 4
	setobjectmovementtype LOCALID_DRYSTAN, MOVEMENT_TYPE_FACE_DOWN
	return
	
NavelRock_Up1_OnFrame: @ 820499A
	map_script_2 VAR_MEWTWO_QUESTLINE_STATE, 1, FallarborTown_DrystansHouse_EventScript_StartQuest
	.2byte 0		
	
FallarborTown_DrystansHouse_EventScript_StartQuest::
	lockall
	setvar VAR_MEWTWO_QUESTLINE_STATE, 2
	delay 10
	msgbox FallarborTown_DrystansHouse_Text_PleaseHaveASeat, MSGBOX_DEFAULT
	closemessage
	delay 10
	applymovement OBJ_EVENT_ID_PLAYER, FallarborTown_DrystansHouse_Movement_Up3
	waitmovement 0
	delay 20
	msgbox FallarborTown_DrystansHouse_Text_FirstandForemost, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DRYSTAN, FallarborTown_DrystansHouse_Movement_LookLeft
	waitmovement 0
	bufferspeciesname 0, SPECIES_MEW
	bufferspeciesname 1, SPECIES_MEWTWO
	msgbox FallarborTown_DrystansHouse_Text_OurTeamWasOnTheBrinkOf, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DRYSTAN, FallarborTown_DrystansHouse_Movement_LookLeft
	waitmovement 0
	msgbox FallarborTown_DrystansHouse_Text_ImSorryThisIsDifficultForMe, MSGBOX_DEFAULT
	closemessage
	delay 40
	//questmenu QUEST_MENU_UNLOCK_QUEST SIDE_QUEST_27
	call NoteNewQuestSingle
	releaseall
	end
	
FallarborTown_DrystansHouse_Text_PleaseHaveASeat:
	.string "Please, have a seat.$"
	
FallarborTown_DrystansHouse_Text_FirstandForemost:
	.string "First and foremost, I want to say\n"
	.string "that what I'm about to tell you,\l"
	.string "I regret immensely.\l"
	.string "It should never have happened.\p"
	.string "Now, my name is DRYSTAN.\n"
	.string "And you are...?\p"
	.string "Ah, {PLAYER}.\n"
	.string "I am lucky to have met you.\p"
	.string "DRYSTAN: Now, I am a scientist.\n"
	.string "I was working with DR. FUJI on a\l"
	.string "top secret project gone wrong.\p"
	.string "I don't know whether you have\n"
	.string "heard of DR. FUJI before, but\l"
	.string "it doesn't matter, as he and\l"
	.string "likely all my other colleagues\l"
	.string "as well may have perished.$"

FallarborTown_DrystansHouse_Text_OurTeamWasOnTheBrinkOf:
	.string "DRYSTAN: You see, our research teams\n"
	.string "was on the brink of bankruptcy.\l"
	.string "We had no money to continue our\l"
	.string "work.\p"
	.string "Suddenly, a businessman came to us\n"
	.string "like a lifesaver, saying that he\l"
	.string "could fund whatever we need, for as\l"
	.string "long as we need, if we make his one\l"
	.string "wish come true.\p"
	.string "We should have known better than to\n"
	.string "accept his offer, but it was our last\l"
	.string "chance. So we did what he wanted.\p"
	.string "What he asked for, however, turned\n"
	.string "out to be the single greatest mistake\l"
	.string "in all our lives.\p"
	.string "He wanted us to create the most\n"
	.string "powerful POKéMON that ever existed.\l"
	.string "To do this, he shared with us his\l"
	.string "knowledge of an ancestral POKéMON,\l"
	.string "{STR_VAR_1}.\p"
	.string "He said that by enhancing\n"
	.string "{STR_VAR_1}'s powers, he could\l"
	.string "follow his goal of uniting all\l"
	.string "people and POKéMON under his\l"
	.string "command, ending wars and suffering.\p"
	.string "We trusted his word and did manage to\n"
	.string "clone {STR_VAR_1}'s DNA and create a\l"
	.string "a new POKéMON, {STR_VAR_2}.\p"
	.string "However, {STR_VAR_2} was so vicious\n"
	.string "and powerful that it could not be\l"
	.string "be controlled.\p"
	.string "It first destroyed our laboratory\n"
	.string "and later the businessman's\l"
	.string "premises, escaping its cruel fate\l"
	.string "as his slave.$"
	
FallarborTown_DrystansHouse_Text_ImSorryThisIsDifficultForMe:
	.string "DRYSTAN: I'm sorry. This is really\n"
	.string "difficult to me.\p"
	.string "The reason why I'm talking to you\n"
	.string "now is that recently, very ominous\l"
	.string "things have happened at the past\l"
	.string "location of our laboratory,\l"
	.string "NEW ISLAND.\p"
	.string "I fear that {STR_VAR_2} may have\n"
	.string "returned there for some reason.\p"
	.string "Its hatred is so strong that the\n"
	.string "entire humanity may be in danger.\p"
	.string "So, I need to ask you, {PLAYER}:\n"
	.string "please come with me to NEW ISLAND\l"
	.string "to inspect the situation.\p"
	.string "I am trying to right my wrongs,\n"
	.string "but my skills as a TRAINER are\l"
	.string "nothing to write home about.\p"
	.string "I know this is a lot to ask,\n"
	.string "but please at least consider\l"
	.string "doing this.\p"
	.string "If not for me, then for all the\n"
	.string "innocent lives in danger of\l"
	.string "{STR_VAR_2}'s revenge.\p"
	.string "If you are ready to leave for\n"
	.string "NEW ISLAND, just come talk to me.$"
	
FallarborTown_DrystansHouse_Movement_Up3::
	walk_up
	walk_up
	walk_up
	step_end
	
FallarborTown_DrystansHouse_Movement_LookLeft::
	face_left
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	step_end
	
// > END