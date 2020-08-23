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
	
Test_EventScript_Castform::
	lock
	setwildbattle SPECIES_CASTFORM, 3, ITEM_NONE
	dowildbattle
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
	.string "A good choice, if I may say so.$"

Text_ComeBackToMeIfYouChangeYourMind:
	.string "Huh? You don't want to change the\n"
	.string "Ability?\p"
	.string "Come back to me if you change your\n"
	.string "mind.$"
	
LittlerootTown_EventScript_PlayersHouseSignFemale:: @ 81E81B2
// >

< //
LittlerootTown_EventScript_Mom:: @ 81E863D
	lock
	faceplayer
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LittlerootTown_EventScript_SetHomeDoorCoordsMale
	compare VAR_RESULT, FEMALE
	call_if_eq LittlerootTown_EventScript_SetHomeDoorCoordsFemale
	call LittlerootTown_EventScript_GiveRunningShoes
	applymovement 4, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
	waitmovement 0
	hideobjectat 4, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	goto LittlerootTown_EventScript_SetReceivedRunningShoes
	end

LittlerootTown_EventScript_SetReceivedRunningShoes:: @ 81E8686
	removeobject 4
	// setflag FLAG_SYS_B_DASH
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
	release
	end

LittlerootTown_EventScript_GiveRunningShoes:: @ 81E8693
	msgbox LittlerootTown_Text_GiveThisSootheBell, MSGBOX_DEFAULT
	giveitem ITEM_SOOTHE_BELL
	msgbox LittlerootTown_Text_HeresSomethingFromDad, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE
	//playfanfare MUS_FANFA4
	//message LittlerootTown_Text_SwitchShoesWithRunningShoes
	//waitfanfare
	//setflag FLAG_RECEIVED_RUNNING_SHOES
	//msgbox LittlerootTown_Text_ExplainRunningShoes, MSGBOX_DEFAULT
	msgbox LittlerootTown_Text_ComeHomeIfAnythingHappens, MSGBOX_DEFAULT
	closemessage
	delay 30
	return

LittlerootTown_Text_GiveThisSootheBell: @ 81E87F0
	.string "MOM: {PLAYER}! {PLAYER}! Did you\n"
	.string "introduce yourself to PROF. BIRCH?\p"
	.string "Oh! What an adorable POKéMON!\n"
	.string "You got it from PROF. BIRCH. How nice!\p"
	.string "You're your father's child, all right.\n"
	.string "You look good together with POKéMON!\p"
	.string "Here, honey! If you're going out on an\n"
	.string "adventure, give this SOOTHE BELL to\l"
	.string "your POKéMON. It'll look so cute!$"	
	
LittlerootTown_Text_HeresSomethingFromDad:
	.string "MOM: Oh, I almost forgot.\p"
	.string "Here's something from DAD, too!$"
	
LittlerootTown_Text_OurNewHomeLetsGoInside: @ 81E86BC
// >