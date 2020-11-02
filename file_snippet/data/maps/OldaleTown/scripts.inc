< //
OldaleTown_EventScript_NotBlockingPath:: @ 81E9066
	questmenu QUEST_MENU_CHECK_COMPLETE SIDE_QUEST_2
	compare VAR_RESULT, TRUE
	goto_if_eq OldaleTown_EventScript_FootprintsMan_QuestComplete
	questmenu QUEST_MENU_CHECK_COMPLETE SIDE_QUEST_2
	compare VAR_RESULT, TRUE
	goto_if_eq OldaleTown_EventScript_FootprintsMan_QuestUnlocked
	msgbox OldaleTown_Text_FinishedSketchingFootprints, MSGBOX_DEFAULT
	release
	end
	
OldaleTown_EventScript_FootprintsMan_QuestUnlocked::
	msgbox OldaleTown_Text_FoundMoreInterestingFootprints, MSGBOX_YESNO
	compare VAR_RESULT, TRUE
	goto_if_eq OldaleTown_EventScript_FootprintsMan_TryShowZigzagoon
	goto_if_ne OldaleTown_EventScript_FootprintsMan_Cancel
	release
	end

OldaleTown_EventScript_FootprintsMan_TryShowZigzagoon::
	special ChoosePartyMon
	waitstate
	// did not select anything
	compare VAR_RESULT, 255
	goto_if_eq OldaleTown_EventScript_FootprintsMan_Cancel
	// selected mon
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_ZIGZAGOON
	goto_if_eq OldaleTown_EventScript_FootprintsMan_ThatsThePokemon
	compare VAR_RESULT, SPECIES_GALARIAN_ZIGZAGOON
	goto_if_eq OldaleTown_EventScript_FootprintsMan_ThatsThePokemon
	goto OldaleTown_EventScript_FootprintsMan_ThatsNotThePokemon
	release
	end
	
OldaleTown_EventScript_FootprintsMan_ThatsThePokemon::
	msgbox OldaleTown_Text_ThatsThePokemon, MSGBOX_DEFAULT
	closemessage
	questmenu QUEST_MENU_COMPLETE_QUEST SIDE_QUEST_2
	call CompleteQuestFanfare
	giveitem ITEM_REVIVE
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_REVEIVED_FOOTPRINTS_MAN_REVIVE
	release
	end
	
OldaleTown_EventScript_FootprintsMan_ThatsNotThePokemon::
	msgbox OldaleTown_Text_ThatsThePokemon, MSGBOX_DEFAULT
	release
	end
	
OldaleTown_EventScript_FootprintsMan_Cancel::
	msgbox OldaleTown_Text_WellIfYouFindThatPokemon MSGBOX_DEFAULT
	release
	end
	
OldaleTown_EventScript_FootprintsMan_QuestComplete::
	goto_if_unset FLAG_REVEIVED_FOOTPRINTS_MAN_REVIVE, OldaleTown_EventScript_FootprintsMan_GiveRevive
	msgbox OldaleTown_Text_FootprintsMan_ThanksForShowingZigzagoon, MSGBOX_DEFAULT
	release
	end

OldaleTown_EventScript_FootprintsMan_GiveRevive::
	msgbox OldaleTown_Text_ThanksForShowingPleaseTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_REVIVE
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	release
	end
	
OldaleTown_Text_FoundMoreInterestingFootprints::
	.string "I found more intriguing footprints!\n"
	.string "I almost saw the POKéMON that\l"
	.string "left them.\p"
	.string "It was brown and beige in color, or\n"
	.string "it could have been black and white\l"
	.string "as well.\p"
	.string "Do you know that kind of POKéMON?\n"
	.string "Can you show it to me?$"
	
OldaleTown_Text_ThatsThePokemon:
	.string "Huh? That's the POKéMON!\n"
	.string "Zigzagoon!\p"
	.string "I'm so happy, I could hug you!\n"
	.string "Or, let me give you this instead!$"

OldaleTown_Text_ThatsThePokemon::
	.string "Hmm… That's not the POKéMON I'm\n"
	.string "looking for.$"
	
OldaleTown_Text_WellIfYouFindThatPokemon:
	.string "Oh? Well, if you find that POKéMON,\n"
	.string "come show me.$"
	
OldaleTown_Text_ThanksForShowingPleaseTakeThis:
	.string "Thank you for showing me a Zigzagoon!\n"
	.string "Please, take this for a thank you!$"
	
OldaleTown_Text_ThanksForShowingZigzagoon:
	.string "Thank you for showing me a Zigzagoon!\n"
	.string "Their zigzagging paths make very\l"
	.string "intricate networks.\p"
	.string "I wonder if I should walk in zigzags\n"
	.string "as well to understand their\l"
	.string "deepest essence…$"

OldaleTown_EventScript_Rival:: @ 81E9070
// >