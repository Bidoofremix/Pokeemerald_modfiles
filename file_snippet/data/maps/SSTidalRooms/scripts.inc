< //
SSTidalRooms_EventScript_SnatchGiver:: @ 823C9F2
	lock
	faceplayer
	msgbox SSTidalRooms_Text_ImARegular, MSGBOX_NPC
	//goto_if_set FLAG_RECEIVED_TM49, SSTidalRooms_EventScript_ExplainSnatch
	//msgbox SSTidalRooms_Text_NotSuspiciousTakeThis, MSGBOX_DEFAULT
	//giveitem ITEM_TM49
	//compare VAR_RESULT, FALSE
	//goto_if_eq Common_EventScript_ShowBagIsFull
	//setflag FLAG_RECEIVED_TM49
	//msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_Text_ImARegular:
	.string "I'm a regular here on SS Tidal.\p"
	.string "I enjoy sailing on it so much,\n"
	.string "they gave me a sailor's cap as\l"
	.string "a souvenir.$"
	
SSTidalRooms_EventScript_ExplainSnatch:: @ 823CA29
// >