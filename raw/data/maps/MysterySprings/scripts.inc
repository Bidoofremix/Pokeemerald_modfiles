< // START
MysterySprings_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MysterySprings_OnTransition
	.byte 0

MysterySprings_EventScript_AbilityNum0::
	lock
	faceplayer
	setvar VAR_0x8005, 0
	call_if_unset FLAG_INTRODUCED_ABILITY_CHANGER, MysterySprings_EventScript_IntroduceAbilityChanger
	msgbox MysterySprings_Text_Ability0, MSGBOX_DEFAULT
	goto MysterySprings_EventScript_AbilityChanger
	end
	
MysterySprings_EventScript_AbilityNum1::
	lock
	faceplayer
	setvar VAR_0x8005, 1
	call_if_unset FLAG_INTRODUCED_ABILITY_CHANGER, MysterySprings_EventScript_IntroduceAbilityChanger
	msgbox MysterySprings_Text_Ability1, MSGBOX_DEFAULT	
	goto MysterySprings_EventScript_AbilityChanger
	end
	
MysterySprings_EventScript_AbilityNum2::
	lock
	faceplayer
	setvar VAR_0x8005, 2
	call_if_unset FLAG_INTRODUCED_ABILITY_CHANGER, MysterySprings_EventScript_IntroduceAbilityChanger
	msgbox MysterySprings_Text_Ability2, MSGBOX_DEFAULT
	goto MysterySprings_EventScript_AbilityChanger
	end
	
MysterySprings_EventScript_IntroduceAbilityChanger::
	msgbox MysterySprings_Text_GreetingsChild, MSGBOX_DEFAULT
	setflag FLAG_INTRODUCED_ABILITY_CHANGER
	return
	
MysterySprings_EventScript_AbilityChanger::
	bufferleadmonspeciesname 0
	// check that lead mon is not egg
	special GetLeadMonPotentialAbility
	msgbox MysterySprings_Text_MonsAbilityIs, MSGBOX_DEFAULT
	compare VAR_RESULT, 0
	goto_if_eq MysterySprings_EventScript_CannotChangeAbility
	compare VAR_RESULT, 1
	goto_if_eq MysterySprings_EventScript_WontChangeAbility
	goto MysterySprings_EventScript_ChangeAbilityYesNo
	release
	end
	
MysterySprings_Text_GreetingsChild:
	.string "Greetings, child!\p"
	.string "You have arrived at the MYSTERY\n"
	.string "SPRINGS.\p"
	.string "By using the powers conferred by\n"
	.string "this enigmatic fountain, we can\l"
	.string "change POKéMON's abilities.\p"
	.string "To do so, a strong bond must exist\n"
	.string "between the TRAINER and their\l"
	.string "POKéMON.\l"
	.string "Now…$"
	
MysterySprings_Text_Ability0::
	.string "I admire POKéMON's first abilities.$"
	
MysterySprings_Text_Ability1::
	.string "I find beauty in POKéMON's\n"
	.string "second abilities.$"
	
MysterySprings_Text_Ability2::
	.string "I have unlocked the secrets of\n"
	.string "POKéMON's hidden abilities.$"
	
MysterySprings_EventScript_CannotChangeAbility::
	msgbox MysterySprings_Text_ICannotChangeThisMonsAbility, MSGBOX_DEFAULT
	release
	end
	
MysterySprings_EventScript_WontChangeAbility::
	msgbox MysterySprings_Text_IWontChangeThisMonsAbility, MSGBOX_DEFAULT
	release
	end
	
MysterySprings_EventScript_ChangeAbilityYesNo::
	msgbox MysterySprings_Text_ICanChangeThisMonsAbilityTo, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MysterySprings_EventScript_ChangeAbility
	goto MysterySprings_EventScript_CancelChangeAbility
	release
	end

MysterySprings_EventScript_ChangeAbility::
	special SetLeadMonAbility
	msgbox MysterySprings_Text_DoneThisMonsAbilityIs, MSGBOX_DEFAULT
	release
	end

MysterySprings_EventScript_CancelChangeAbility::
	msgbox MysterySprings_Text_ComeBackToMeIfYouChangeYourMind
	release
	end
	
MysterySprings_Text_MonsAbilityIs::
	.string "{STR_VAR_1}'s current ability is\n"
	.string "{STR_VAR_3}.$"
	
MysterySprings_Text_IWontChangeThisMonsAbility:
	.string "That is a fabulous Ability. I won't\n"
	.string "change it!$"
	
MysterySprings_Text_ICannotChangeThisMonsAbility:
	.string "Huh?\p"
	.string "It seems that I cannot change the\n"
	.string "Ability of this POKéMON.$"
	
MysterySprings_Text_ICanChangeThisMonsAbilityTo:
	.string "I can change it to {STR_VAR_2}.\n"
	.string "Would that be desired?$"

MysterySprings_Text_DoneThisMonsAbilityIs:
	.string "Done! This POKéMON's Ability was\n"
	.string "changed to {STR_VAR_2}.\p"
	.string "A good choice, if I may say so.$"

MysterySprings_Text_ComeBackToMeIfYouChangeYourMind:
	.string "Huh? You don't want to change the\n"
	.string "Ability?\p"
	.string "Come back to me if you change your\n"
	.string "mind.$"
			
MysterySprings_OnTransition:
	end
// > END