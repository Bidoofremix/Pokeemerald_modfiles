// < event scripts for pokedex and pokenav
LittlerootTown_ProfessorBirchsLab_EventScript_ReceivePokedex:: @ 81FA3AC
	playfanfare MUS_FANFA4
	message LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokedex
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	special SetAllSpeciesSeen
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	return
	
LittlerootTown_ProfessorBirchsLab_EventScript_ReceivePokenav::
	playfanfare MUS_FANFA4
	message LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokenav
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
	setflag FLAG_HAS_MATCH_CALL
	return
// >

// < main function to give pokedex and pokenav
LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedex:: @ 81FA2F8
	msgbox LittlerootTown_ProfessorBirchsLab_Text_HeardYouBeatRivalTakePokedex, MSGBOX_DEFAULT
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivePokedex
	msgbox LittlerootTown_ProfessorBirchsLab_Text_ExplainPokedex, MSGBOX_DEFAULT
	closemessage
	msgbox LittlerootTown_ProfessorBirchsLab_Text_TakePokenav, MSGBOX_DEFAULT
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivePokenav
	msgbox LittlerootTown_ProfessorBirchsLab_Text_ExplainPokenav, MSGBOX_DEFAULT
	closemessage
// >

// < text for pokedex and pokenav
LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokedex: @ 81FAC32
	.string "{PLAYER} received the POKéDEX!$"

LittlerootTown_ProfessorBirchsLab_Text_ExplainPokedex: @ 81FAC4B
	.string "PROF. BIRCH: The POKéDEX is a high-tech\n"
	.string "tool that automatically makes a record\l"
	.string "of any POKéMON you meet or catch.\p"
	.string "But you knew that already, didn't you?\n"
	.string "That's why we have made it a proper\l"
	.string "encyclopedia.\p"
	.string "We have pre-loaded data on all species\n"
	.string "on it, so you can find the habitats of\l"
	.string "your favourite POKéMON easier.$"	
	
LittlerootTown_ProfessorBirchsLab_Text_TakePokenav:
	.string "Oh, I almost forgot. To get the most\n"
	.string "of your adventure, I will also give you\l"
	.string "this.$"
	
LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokenav:
	.string "{PLAYER} received the POKéNAV!$"
	
LittlerootTown_ProfessorBirchsLab_Text_ExplainPokenav:
	.string "PROF. BIRCH: This is the POKéNAV.\n"
	.string "You can use it for communication\l"
	.string "with your family and friends.\p"
	.string "It also includes a map of the HOENN\n"
	.string "region. That should come in handy!$"

LittlerootTown_ProfessorBirchsLab_Text_CountlessPokemonAwait: @ 81FAD6F
// >