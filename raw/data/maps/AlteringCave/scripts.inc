< //
AlteringCave_MapScripts:: @ 823B177
	map_script MAP_SCRIPT_ON_TRANSITION, AlteringCave_OnTransition
	.byte 0

AlteringCave_EventScript_Mary::
	trainerbattle_single TRAINER_MARY, AlteringCave_Text_MaryIntro, AlteringCave_Text_MaryDefeat
	bufferitemname 0, ITEM_THICK_CLUB
	bufferspeciesname 1, SPECIES_CUBONE
	msgbox AlteringCave_Text_MaryPostBattle, MSGBOX_AUTOCLOSE
	end	
	
AlteringCave_Text_MaryIntro:
	.string "We're training in this cave to attain\n"
	.string "maximum strength! Get ready to lose!$"
	
AlteringCave_Text_MaryDefeat:
	.string "Too strong!$"
	
AlteringCave_Text_MaryPostBattle:
	.string "I'm looking for a {STR_VAR_1}.\p"
	.string "It boosts the power of {STR_VAR_2}.$"
	
AlteringCave_EventScript_Earl:: @ 828CDD6
	trainerbattle_double TRAINER_EARL_AND_EVA, AlteringCave_Text_EarlIntro, AlteringCave_Text_EarlDefeat, AlteringCave_Text_EarlNotEnoughMons
	msgbox AlteringCave_Text_EarlGotTooExcited, MSGBOX_DEFAULT
	release
	end
	
AlteringCave_EventScript_Eva:: @ 828CDD6
	trainerbattle_double TRAINER_EARL_AND_EVA, AlteringCave_Text_EvaIntro, AlteringCave_Text_EvaDefeat, AlteringCave_Text_EvaNotEnoughMons
	msgbox AlteringCave_Text_EvaMyHusbandGetsExcited, MSGBOX_DEFAULT
	release
	end
	
AlteringCave_Text_EarlIntro:
	.string "Hah! A youngster! Our POKéMON\n"
	.string "will leave you breathless!$"
	
AlteringCave_Text_EarlDefeat:
	.string "Ouch!$"
	
AlteringCave_Text_EarlGotTooExcited:
	.string "My apologies. I get so excited by\n"
	.string "battles that I act before I think.$"

AlteringCave_Text_EarlNotEnoughMons:
	.string "What? You don't have enough\n"
	.string "POKéMON for a double battle!$"
	
AlteringCave_Text_EvalIntro:
	.string "You look like such a nice kid.\n"
	.string "Let's have a battle!$"
	
AlteringCave_Text_EvaDefeat:
	.string "My goodness!$"
	
AlteringCave_Text_EvaMyHusbandGetsExcited:
	.string "My husband gets so excited by battles\n"
	.string "that he can't think straight.$"

AlteringCave_Text_EvaNotEnoughMons:
	.string "We would like to battle you, but it\n"
	.string "seems that you don't have enough\l"
	.string" POKéMON for a double battle.$"	

AlteringCave_EventScript_HeavyBall::
	finditem ITEM_HEAVY_BALL
	end	
	
AlteringCave_EventScript_Potion::
	finditem ITEM_POTION
	end		
	
AlteringCave_OnTransition: @ 823B17D
	end
// >