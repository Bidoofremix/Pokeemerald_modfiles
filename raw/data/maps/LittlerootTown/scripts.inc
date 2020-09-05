< //
LittlerootTown_EventScript_BirchsHouseSignMale:: @ 81E81A9
	msgbox LittlerootTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
	return

Debug_EventScript_SetFlagsGivePartyWarp::
	// route 103
	settrainerflag TRAINER_ISABELLE
	settrainerflag TRAINER_ANDREW
	settrainerflag TRAINER_PETE
	settrainerflag TRAINER_MIGUEL_1
	// altering cave
	settrainerflag TRAINER_MARY
	settrainerflag TRAINER_EARL_AND_EVA
	// verdanturf
	setflag FLAG_VISITED_VERDANTURF_TOWN                
	setflag FLAG_RECEIVED_VERDANTURF_EGG
	// rusturf pre-rustboro
	settrainerflag TRAINER_MIKE_2
	// route 117
	settrainerflag TRAINER_LYDIA_1
	settrainerflag TRAINER_DEREK
	settrainerflag TRAINER_BRANDI
	settrainerflag TRAINER_MELINA
	settrainerflag TRAINER_AISHA
	settrainerflag TRAINER_MARIA_1
	settrainerflag TRAINER_ISAAC_1
	settrainerflag TRAINER_ANNA_AND_MEG_1
	settrainerflag TRAINER_DYLAN_1
	// route 102
	settrainerflag TRAINER_CALVIN_1
	settrainerflag TRAINER_RICK
	settrainerflag TRAINER_ALLEN
	settrainerflag TRAINER_TIANA
	// petalburg
	setflag FLAG_VISITED_PETALBURG_CITY
	setflag FLAG_HIDE_PETALBURG_CITY_WALLYS_UNCLE
	setvar VAR_SCOTT_STATE, 1
	setvar VAR_SCOTT_PETALBURG_ENCOUNTER, 1
	setflag FLAG_HIDE_PETALBURG_GYM_WALLY
	setflag FLAG_HIDE_PETALBURG_CITY_WALLY
	setflag FLAG_ROUTE_103_EAST_ACCESSIBLE
	setflag FLAG_HIDE_PETALBURG_CITY_WALLYS_AUNT
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
	setflag FLAG_DEFEATED_PETALBURG_GYM
	setflag FLAG_BADGE05_GET
	clearflag FLAG_HIDE_DEWFORD_HALL_SLUDGE_BOMB_MAN
	setflag FLAG_HIDE_PETALBURG_GYM_NORMAN
	setflag FLAG_NORMAN_INTRODUCED_GYM
	setvar VAR_PETALBURG_GYM_STATE, 7
	setflag FLAG_RECEIVED_TM42
	settrainerflag TRAINER_BERKE
	settrainerflag TRAINER_JODY
	// route 104
	settrainerflag TRAINER_BILLY
	settrainerflag TRAINER_CINDY_1
	// petalburg woods
	settrainerflag TRAINER_LYLE
	setvar VAR_PETALBURG_WOODS_STATE, 1
	settrainerflag TRAINER_JAMES_1
	// route 104 north
	settrainerflag TRAINER_WINSTON_1
	settrainerflag TRAINER_HALEY_1
	settrainerflag TRAINER_GINA_AND_MIA_1
	settrainerflag TRAINER_IVAN
	// rustboro
	setflag FLAG_VISITED_RUSTBORO_CITY
	settrainerflag TRAINER_JOSH
	settrainerflag TRAINER_TOMMY
	settrainerflag TRAINER_MARC
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_RUSTBORO_CITY_STATE, 1
	addvar VAR_PETALBURG_GYM_STATE, 1
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	// route 116
	settrainerflag TRAINER_JOEY
	settrainerflag TRAINER_JOSE
	settrainerflag TRAINER_KAREN_1
	settrainerflag TRAINER_CLARK
	settrainerflag TRAINER_JOHNSON
	settrainerflag TRAINER_DEVAN
	// rusturf tunnel part 2
	settrainerflag TRAINER_GRUNT_RUSTURF_TUNNEL
	clearflag FLAG_DEVON_GOODS_STOLEN
	setflag FLAG_RECOVERED_DEVON_GOODS
	setvar VAR_RUSTBORO_CITY_STATE, 4
	setvar VAR_BRINEY_HOUSE_STATE, 1
	setflag FLAG_HIDE_ROUTE_116_MR_BRINEY
	// devon corp / rustboro university
	setflag FLAG_INTERACTED_WITH_DEVON_EMPLOYEE_GOODS_STOLEN
	setflag FLAG_RETURNED_DEVON_GOODS
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
	setvar VAR_RUSTBORO_CITY_STATE, 5
	setflag FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT
	setflag FLAG_HIDE_ROUTE_116_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDA
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_BRINEY_LOCATION, 1
	clearflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setvar VAR_DEVON_CORP_3F_STATE, 1
	setvar VAR_RUSTBORO_CITY_STATE, 6
	giveitem ITEM_LETTER
	
	// warp player to mr brineys house
	warp MAP_ROUTE104_MR_BRINEYS_HOUSE, 255, 5, 8
	end
	
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