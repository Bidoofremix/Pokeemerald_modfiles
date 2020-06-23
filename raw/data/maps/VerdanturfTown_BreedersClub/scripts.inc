< //
VerdanturfTown_BreedersClub_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_BreedersClub_OnTransition
	.byte 0

VerdanturfTown_BreedersClub_EventScript_OldLady::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_CHARCOAL_BREEDERSCLUB, VerdanturfTown_BreedersClub_EventScript_OldLady_AskQuestion
	msgbox VerdanturfTown_BreedersClub_Text_OldLady_Charcoal, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_BreedersClub_EventScript_OldLady_AskQuestion::
	msgbox VerdanturfTown_BreedersClub_Text_OldLady_DoYouLikeBreeding, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq VerdanturfTown_BreedersClub_EventScript_OldLady_YesILikeBreeding
	compare VAR_RESULT, NO
	goto_if_eq VerdanturfTown_BreedersClub_EventScript_OldLady_NoIDontLikeBreeding
	release
	end
	
VerdanturfTown_BreedersClub_EventScript_OldLady_YesILikeBreeding::
	msgbox VerdanturfTown_BreedersClub_Text_OldLady_Good, MSGBOX_DEFAULT
	giveitem ITEM_CHARCOAL
	compare VAR_RESULT, 0
	goto_if_eq VerdanturfTown_BreedersClub_Text_OldLady_BagIsFull
	setflag FLAG_RECEIVED_CHARCOAL_BREEDERSCLUB
	msgbox VerdanturfTown_BreedersClub_Text_OldLady_Charcoal, MSGBOX_DEFAULT
	release
	end
	
VerdanturfTown_BreedersClub_EventScript_OldLady_BagIsFull::
	msgbox VerdanturfTown_BreedersClub_Text_OldLady_BagIsFull, MSGBOX_DEFAULT
	release
	end	
	
VerdanturfTown_BreedersClub_EventScript_OldLady_NoIDontLikeBreeding::
	msgbox VerdanturfTown_BreedersClub_Text_OldLady_Disappointing, MSGBOX_DEFAULT
	release
	end
	
VerdanturfTown_BreedersClub_Text_OldLady_DoYouLikeBreeding:
	.string "Do you like raising POKéMON, youngster?$"

VerdanturfTown_BreedersClub_Text_OldLady_Good:
	.string "Good, good! I had you figured for a\n"
	.string "talented young TRAINER.\p"
	.string "Here, take this.$"
	
VerdanturfTown_BreedersClub_Text_OldLady_Disappointing:
	.string "Oh? That's disappointing. What are kids\n"
	.string "even good for nowdays…!$"
	
VerdanturfTown_BreedersClub_Text_OldLady_BagIsFull:
	.string "Oh? Your BAG is full.$"
	
VerdanturfTown_BreedersClub_Text_OldLady_Charcoal:
	.string "Give CHARCOAL to a POKéMON whose ability\n"
	.string "is FLAME BODY or MAGMA ARMOR.\p"
	.string "You'll see that EGGS will start hatching\n"
	.string "quite rapidly!$"
	
VerdanturfTown_BreedersClub_EventScript_Display1::
	goto_if_unset FLAG_RECEIVED_FATEFUL_KNOT, VerdanturfTown_BreedersClub_EventScript_Display1_ForSomeReason
	msgbox VerdanturfTown_BreedersClub_Text_FatefulKnot, MSGBOX_SIGN
	end
	
VerdanturfTown_BreedersClub_EventScript_Display1_ForSomeReason:
	msgbox VerdanturfTown_BreedersClub_Text_GoldenYarn, MSGBOX_SIGN
	end

VerdanturfTown_BreedersClub_Text_FatefulKnot:
	.string "A lustrous, golden FATEFUL KNOT is\n"
	.string "placed on the pedestal.$"
	
VerdanturfTown_BreedersClub_Text_GoldenYarn:
	.string "For some reason, there is a golden ball\n"
	.string "of yarn on display.$"
	
VerdanturfTown_BreedersClub_EventScript_Display2::
	msgbox VerdanturfTown_BreedersClub_Text_Everstone, MSGBOX_SIGN
	end
	
VerdanturfTown_BreedersClub_Text_Everstone:
	.string "A perfectly round EVERSTONE is on\n"
	.string "display in the glass case.$"

VerdanturfTown_BreedersClub_EventScript_Rater::
	lock
	faceplayer
	msgbox VerdanturfTown_BreedersClub_Text_Hello, MSGBOX_DEFAULT
	goto VerdanturfTown_BreedersClub_EventScript_ChooseMonToShowBreeder
	end
	
VerdanturfTown_BreedersClub_Text_Hello:
	.string "Hi! Which POKéMON would you like me\n"
	.string "to evaluate?$"
	
VerdanturfTown_BreedersClub_EventScript_ChooseMonToShowBreeder::
	lock
	faceplayer
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_ne VerdanturfTown_BreedersClub_EventScript_ShowMonToBreeder
	compare VAR_0x8004, 255
	goto_if_eq VerdanturfTown_BreedersClub_EventScript_CancelMonSelect
	end	

VerdanturfTown_BreedersClub_EventScript_ShowMonToBreeder::
	lock
	faceplayer
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq VerdanturfTown_BreedersClub_EventScript_ShowEggToBreeder
	special BufferHPAtkDef
	msgbox VerdanturfTown_BreedersClub_Text_RateHPAtkDef, MSGBOX_DEFAULT
	special BufferSpASpDSpe
	msgbox VerdanturfTown_BreedersClub_Text_RateSpASpDSpe, MSGBOX_DEFAULT
	release
	end	

VerdanturfTown_BreedersClub_Text_RateHPAtkDef:
	.string "Its HP is {STR_VAR_1}, Attack is {STR_VAR_2}\n"
	.string "and Defense is {STR_VAR_3}.$"
	
VerdanturfTown_BreedersClub_Text_RateSpASpDSpe:
	.string "Also, its Special Attack is {STR_VAR_1}, Special\n"
	.string "Defense is {STR_VAR_2} and Speed is {STR_VAR_3}.\p"
	.string "That's how I see this POKéMON.$"
	
VerdanturfTown_BreedersClub_EventScript_CancelMonSelect::
	msgbox VerdanturfTown_BreedersClub_Text_MaybeNextTimeThen, MSGBOX_DEFAULT
	release
	end
	
VerdanturfTown_BreedersClub_Text_MaybeNextTimeThen:
	.string "Oh, you don't want to evaluate your\n"
	.string "POKéMON? Maybe next time, then.$"
	
VerdanturfTown_BreedersClub_EventScript_ShowEggToBreeder::
	msgbox VerdanturfTown_BreedersClub_Text_ThisIsAnEgg, MSGBOX_DEFAULT
	goto VerdanturfTown_BreedersClub_EventScript_ChooseMonToShowBreeder
	end
	
VerdanturfTown_BreedersClub_Text_ThisIsAnEgg:
	.string "This is an EGG. I can't evaluate it!$"

VerdanturfTown_BreedersClub_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart VerdanturfTown_BreedersClub_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end	
	
VerdanturfTown_BreedersClub_Pokemart:
	.2byte ITEM_DESTINY_KNOT
	.2byte ITEM_EVERSTONE
	.2byte ITEM_POWER_WEIGHT
	.2byte ITEM_POWER_BRACER
	.2byte ITEM_POWER_BELT
	.2byte ITEM_POWER_LENS
	.2byte ITEM_POWER_BAND
	.2byte ITEM_POWER_ANKLET
	.2byte ITEM_NONE
	release
	end
	
VerdanturfTown_BreedersClub_OnTransition:
// >