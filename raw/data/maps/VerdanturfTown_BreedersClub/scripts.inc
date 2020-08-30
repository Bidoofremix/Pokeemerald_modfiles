< //
VerdanturfTown_BreedersClub_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_BreedersClub_OnTransition
	.byte 0

VerdanturfTown_BreedersClub_EventScript_Lady::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_VERDANTURF_EGG, VerdanturfTown_BreedersHouse_EventScript_GotEgg
	call_if_unset FLAG_ASKED_VERDANTURF_EGG VerdanturfTown_BreedersClub_EventScript_HiYouMustBePlayer
	msgbox VerdanturfTown_BreedersClub_Text_WillYouTakeCareOfThisEgg, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq VerdanturfTown_BreedersHouse_EventScript_TryGiveMeowsyEgg
	compare VAR_RESULT, NO
	goto_if_eq VerdanturfTown_BreedersHouse_EventScript_RefusedEgg
	end
	
VerdanturfTown_BreedersClub_EventScript_HiYouMustBePlayer::
	msgbox VerdanturfTown_BreedersClub_Text_HiYouMustBePlayer, MSGBOX_DEFAULT
	setflag FLAG_ASKED_VERDANTURF_EGG
	return
	
// old
VerdanturfTown_BreedersHouse_EventScript_GiveEgg::
	getpartysize
	compare VAR_RESULT, 6
	goto_if_eq LavaridgeTown_EventScript_NoRoomForEgg
	playfanfare MUS_FANFA4
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	giveegg SPECIES_MEOWSY
	setflag FLAG_RECEIVED_VERDANTURF_EGG
	setvar VAR_PETALBURG_GYM_STATE, 6
	clearflag FLAG_HIDE_PETALBURG_GYM_GREETER
	release
	end
	
// current
VerdanturfTown_BreedersHouse_EventScript_TryGiveMeowsyEgg: @ 8674D4C
	specialvar VAR_EVENT_MEOWSY_SLOT, CalculatePlayerPartyCount
	compare VAR_EVENT_MEOWSY_SLOT, PARTY_SIZE
	goto_if_eq LavaridgeTown_EventScript_NoRoomForEgg
	call VerdanturfTown_BreedersHouse_EventScript_GiveMeowsyEgg
	playfanfare MUS_FANFA4
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	setflag FLAG_RECEIVED_VERDANTURF_EGG
	setvar VAR_PETALBURG_GYM_STATE, 6
	clearflag FLAG_HIDE_PETALBURG_GYM_GREETER
	VerdanturfTown_BreedersHouse_Text_PleaseGiveNormanMyGreetings
	release
	end
	
VerdanturfTown_BreedersHouse_EventScript_GiveMeowsyEgg: @ 8674D7E
	giveegg SPECIES_MEOWSY
	setmonobedient VAR_EVENT_MEOWSY_SLOT
	setmonmove VAR_EVENT_MEOWSY_SLOT, 3, MOVE_HAPPY_HOUR
	return

VerdanturfTown_BreedersHouse_EventScript_RefusedEgg::
	msgbox VerdanturfTown_BreedersHouse_Text_RefuseEgg, MSGBOX_DEFAULT
	release
	end
	
VerdanturfTown_BreedersHouse_EventScript_GotEgg::
	msgbox VerdanturfTown_BreedersHouse_Text_PleaseGiveNormanMyGreetings, MSGBOX_NPC
	end
		
VerdanturfTown_BreedersClub_Text_HiYouMustBePlayer:
	.string "Hi! You must be {PLAYER}.\p"
	.string "NORMAN told me that you should be able\n"
	.string "to help me with this EGG.\p"
	.string "You see, I found this lone EGG at a\n"
	.string "roadside and rescued it, but I am\l"
	.string "already taking care of so many POKéMON\l"
	.string "that I simply don't have more space.$"
	
VerdanturfTown_BreedersClub_Text_WillYouTakeCareOfThisEgg:
	.string "{PLAYER}, will you take care\n"
	.string "of this EGG?$"	
	
VerdanturfTown_BreedersHouse_Text_PleaseGiveNormanMyGreetings:
	.string "Please give NORMAN my greetings!$"
	
VerdanturfTown_BreedersHouse_Text_RefuseEgg:
	.string "No?\p"
	.string "But I don't know who else we could ask…$"	
	
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
	.string "Are you a TRAINER?\n"
	.string "At such a young age?\p"
	.string "Good, good. I like your spirit.\p"
	.string "Do you like raising your POKéMON\n"
	.string "from EGGS?$"

VerdanturfTown_BreedersClub_Text_OldLady_Good:
	.string "I knew it! I can see talent in\n"
	.string "TRAINERS.\p"
	.string "Take this!$"
	
VerdanturfTown_BreedersClub_Text_OldLady_Disappointing:
	.string "Oh? That's disappointing.\p"
	.string "What are kids even good for nowdays…!$"
	
VerdanturfTown_BreedersClub_Text_OldLady_BagIsFull:
	.string "Oh? Your BAG is full.$"
	
VerdanturfTown_BreedersClub_Text_OldLady_Charcoal:
	.string "It was recently discovered that\n"
	.string "CHARCOAL doesn't only boost the power\l"
	.string "of FIRE-type moves.\p"
	.string "It is also useful for hatching EGGS.\n"
	.string "Give CHARCOAL to a POKéMON that has\l"
	.string "FLAME BODY or MAGMA ARMOR.\p"
	.string "You'll be surprised how fast your\n"
	.string "EGGS hatch!$"
	
VerdanturfTown_BreedersClub_EventScript_OldMan::
	lock
	faceplayer
	msgbox VerdanturfTown_BreedersClub_Text_OldMan, MSGBOX_DEFAULT
	goto_if_defeated TRAINER_VICKY, VerdanturfTown_BreedersClub_EventScript_WhatYouDefeatedVicky
	release
	end
	
VerdanturfTown_BreedersClub_EventScript_WhatYouDefeatedVicky::
	msgbox VerdanturfTown_BreedersClub_Text_WhatYouDefeatedVicky, MSGBOX_DEFAULT
	release
	end
	
VerdanturfTown_BreedersClub_Text_OldMan:
	.string "Oh hoh ho!\p"
	.string "Back in the days, I was one of the\n"
	.string "mightiest TRAINERS around!\p"
	.string "The name WINSTRATE still carries\n"
	.string "so much respect, it makes people go\l"
	.string "silent in awe!$"
	
VerdanturfTown_BreedersClub_Text_WhatYouDefeatedVicky:
	.string "…What?\p"
	.string "You defeated my wife VICKY?\p"
	.string "Oh.\n"
	.string "I ought to go home sometimes…$"
	
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