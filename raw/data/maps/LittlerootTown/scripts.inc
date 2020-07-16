< //
LittlerootTown_EventScript_BirchsHouseSignMale:: @ 81E81A9
	msgbox LittlerootTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
	return

NewIsland_EventScript_Mewtwo::
	lock
	faceplayer
	msgbox NewIsland_Text_Test, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MEWTWO, NewIsland_Text_Lost
	msgbox NewIsland_Text_Test2
	release
	end
	
NewIsland_Text_Test:
	.string "Hello!$"
	
NewIsland_Text_Lost:
	.string "What!?$"
	
NewIsland_Text_Test2:
	.string "After battle.$"
	
LittlerootTown_EventScript_PlayersHouseSignFemale:: @ 81E81B2
// >