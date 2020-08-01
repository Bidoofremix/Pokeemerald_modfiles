< //
Route117_EventScript_Aisha:: @ 81F3C65
	trainerbattle_single TRAINER_AISHA, Route117_Text_29D1D1, Route117_Text_29D206
	msgbox Route117_Text_29D24C, MSGBOX_AUTOCLOSE
	end

Route117_EventScript_AquaGrunt1::
	msgbox Route117_Text_AquaGrunt1, MSGBOX_NPC
	end

Route117_EventScript_AquaGrunts23::
	lock
	applymovement 26, Common_Movement_WalkInPlaceDown
	msgbox Route117_Text_AquaGrunt2, MSGBOX_DEFAULT
	applymovement 27, Common_Movement_WalkInPlaceUp
	msgbox Route117_Text_AquaGrunt3, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_AquaGrunt4::
	msgbox Route117_Text_AquaGrunt4, MSGBOX_NPC
	end
	
Route117_EventScript_AquaGrunt5::
	msgbox Route117_Text_AquaGrunt5, MSGBOX_NPC
	end	
	
Route117_Text_AquaGrunt1:
	.string "You want to visit MAUVILLE?\p"
	.string "I'm sorry, but you can't come through.\n"
	.string "But I've heard that VERDANTURF is\l"
	.string "a bustling place.$"

Route117_Text_AquaGrunt2:
	.string "I heard that there is some kind\n"
	.string "of delay at the OCEANIC MUSEUM.\l"
	.string "When do we get to start the operation?$"
	
Route117_Text_AquaGrunt3:
	.string "Shush, you idiot! Someone might\n"
	.string "hear you.$"
	
Route117_Text_AquaGrunt4:
	.string "I'm so bored I could battle you, but\n"
	.string "BOSS told us not to make a commotion.$"

Route117_Text_AquaGrunt5:
	.string "Zzz…$"
	
Route117_Text_DayCarePokemonHadNewMove: @ 81F3C7C
// >