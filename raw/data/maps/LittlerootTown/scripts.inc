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
	.string "(What!?)$"
	
NewIsland_Text_Test2:
	.string "After battle.$"
	
EventScript_AbilityChanger::
	lock
	faceplayer
	bufferleadmonspeciesname 0
	msgbox Text_IAmAbilityChanger, MSGBOX_DEFAULT
	setvar VAR_0x8005, 2
	special GetLeadMonPotentialAbility
	compare VAR_RESULT, 0
	goto_if_eq EventScript_CannotChangeAbility
	compare VAR_RESULT, 1
	goto_if_eq EventScript_WontChangeAbility
	goto EventScript_ChangeAbilityYesNo
	release
	end
	
EventScript_CannotChangeAbility::
	msgbox Text_ICannotChangeThisMonsAbility, MSGBOX_DEFAULT
	release
	end
	
EventScript_WontChangeAbility::
	msgbox Text_IWontChangeThisMonsAbility, MSGBOX_DEFAULT
	release
	end
	
EventScript_ChangeAbilityYesNo::
	msgbox Text_ICanChangeThisMonsAbilityTo, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EventScript_ChangeAbility
	goto EventScript_CancelChangeAbility
	release
	end

EventScript_ChangeAbility::
	special SetLeadMonAbility
	msgbox Text_DoneThisMonsAbilityIs, MSGBOX_DEFAULT
	release
	end

EventScript_CancelChangeAbility::
	msgbox Text_ComeBackToMeIfYouChangeYourMind
	release
	end
	
Text_IAmAbilityChanger::
	.string "Ah, {STR_VAR_1}!\n"
	.string "What a magnificent POKéMON.$"
	
Text_IWontChangeThisMonsAbility:
	.string "{STR_VAR_2}!\p"
	.string "That is a fabulous Ability. I won't\n"
	.string "change it!$"
	
Text_ICannotChangeThisMonsAbility:
	.string "Huh?\p"
	.string "It seems that I cannot change the\n"
	.string "Ability of this POKéMON.$"
	
Text_ICanChangeThisMonsAbilityTo:
	.string "This POKéMON's current Ability is\n"
	.string "{STR_VAR_3}.\p"
	.string "I can change it to {STR_VAR_2}.\n"
	.string "Would that be desired?$"

Text_DoneThisMonsAbilityIs:
	.string "Done! This POKéMON's Ability was\n"
	.string "changed to {STR_VAR_2}.\p"
	.string "A good choice, if I may say so!$"

Text_ComeBackToMeIfYouChangeYourMind:
	.string "Huh? You don't want to change the\n"
	.string "Ability?\p"
	.string "Come back to me if you change your\n"
	.string "mind.$"
	
LittlerootTown_EventScript_PlayersHouseSignFemale:: @ 81E81B2
// >