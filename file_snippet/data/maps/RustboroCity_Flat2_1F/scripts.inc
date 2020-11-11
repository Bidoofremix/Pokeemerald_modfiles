< //
RustboroCity_Flat2_1F_EventScript_OldWoman:: @ 8215F77
	questmenu QUEST_MENU_CHECK_UNLOCKED SIDE_QUEST_5
	compare VAR_RESULT, TRUE
	goto_if_eq RustboroCity_Flat2_1F_EventScript_StartQuest
	msgbox RustboroCity_Flat2_1F_Text_DevonWorkersLiveHere, MSGBOX_NPC
	end

RustboroCity_Flat2_1F_EventScript_StartQuest::
	bufferspeciesname 0, SPECIES_SKITTY
	msgbox RustboroCity_Flat2_1F_Text_MySkittyHasBeenSad, MSGBOX_DEFAULT
	release
	end
	
RustboroCity_Flat2_1F_EventScript_Skitty:: @ 8215F80
	lock
	faceplayer
	questmenu QUEST_MENU_CHECK_COMPLETE SIDE_QUEST_5
	compare VAR_RESULT, TRUE
	goto_if_ne RustboroCity_Flat2_1F_EventScript_SkittySad
	waitse
	playmoncry SPECIES_SKITTY, 0
	msgbox RustboroCity_Flat2_1F_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end
	
RustboroCity_Flat2_1F_EventScript_SkittySad::
	waitse
	playmoncry SPECIES_SKITTY, 1
	msgbox RustboroCity_Flat2_1F_Text_SkittySad, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_Flat2_1F_Text_DevonWorkersLiveHere: @ 8215F93
	.string "RUSTBORO UNIVERISTY's visiting\n"
	.string "researchers live in this building.$"

RustboroCity_Flat2_1F_Text_MySkittyHasBeenSad:
	.string "My {STR_VAR_1} has been really\n"
	.string "sad lately.\p"
	.string "It doesn't want to play or\n"
	.string "eat its favourite treats.\p"
	.string "The last time we went on a walk,\n"
	.string "it kept looking at the route\l"
	.string "north of RUSTBORO CITY.\p"
	.string "I wonder what it is that {STR_VAR_1}\n"
	.string "is longing for…$"
	
RustboroCity_Flat2_1F_Text_SkittySad:
	.string "SKITTY: Meewwwl…$"
	
RustboroCity_Flat2_1F_Text_Skitty: @ 8215FC6
	.string "SKITTY: Gyaaaah!$"
// > END