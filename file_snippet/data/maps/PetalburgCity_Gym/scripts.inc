< //
PetalburgCity_Gym_OnLoad: @ 820489E
	compare VAR_PETALBURG_GYM_STATE, 6
	goto_if_ge PetalburgCity_Gym_EventScript_OpenUnlockedDoors
	end

@ NOTE: Strength and OHKO rooms are misleading. Both are more accurately Critical-Hit
PetalburgCity_Gym_EventScript_OpenUnlockedDoors:: @ 82048B5
	setmetatile 4, 104, METATILE_PetalburgGym_SlidingDoor_Frame4, 1
	setmetatile 4, 105, METATILE_BattleFrontier_Door_Corridor, 1
	setvar VAR_0x8000, 1
	end
	
PetalburgCity_Gym_EventScript_UnlockAllDoors:: @ 82048FF
	end

PetalburgCity_Gym_OnTransition: @ 820492D
	compare VAR_PETALBURG_GYM_STATE, 1
	call_if_eq PetalburgCity_Gym_EventScript_MoveWallyToEntrance
	compare VAR_PETALBURG_GYM_STATE, 7
	call_if_lt PetalburgCity_Gym_EventScript_MoveNormanToEntrance
	call_if_set FLAG_NORMAN_INTRODUCED_GYM, PetalburgCity_Gym_EventScript_NormanAtBattleField
	call_if_set FLAG_SYS_GAME_CLEAR, PetalburgCity_Gym_EventScript_CheckNormanForRematch
	end
	
PetalburgCity_Gym_EventScript_NormanAtBattleField::
	clearflag FLAG_HIDE_PETALBURG_GYM_NORMAN
	showobjectat 1, MAP_PETALBURG_CITY_GYM
	setobjectxyperm 1, 4, 2
	setvar VAR_0x8000, 1
	return
	end

PetalburgCity_Gym_EventScript_EnterGymRoom::
	lockall
	setvar VAR_0x8008, 4
	setvar VAR_0x8009, 8
	msgbox PetalburgCity_Gym_Text_EnterGym, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
	releaseall
	end
	
PetalburgCity_Gym_Text_EnterGym:
	.string "Enter gym?$"
	
PetalburgCity_Gym_EventScript_MoveWallyToEntrance:: @ 820494D
// >

< //
PetalburgCity_Gym_Text_DadYoureHereWithYourPokemon: @ 82057A2
	.string "DAD: Hm?\p"
	.string "Well, if it isn't {PLAYER}!\n"
	.string "So you're all finished moving in?\p"
	.string "I'm not surprised that you managed\n"
	.string "to get here by yourself. I knew\l"
	.string "PROFESSOR BIRCH would give you\l"
	.string "your very own POKéMON!\p"
	.string "Then I guess you're going to\n"
	.string "become a TRAINER like me, {PLAYER}.\p"
	.string "That's great news!\n"
	.string "I'll be looking forward to it!$"

PetalburgCity_Gym_Text_WallyIdLikeAPokemon: @ 82058B1
// >

< //
PetalburgCity_Gym_EventScript_NormanBattle:: @ 8204E3B
	goto_if_unset FLAG_NORMAN_INTRODUCED_GYM, PetalburgCity_Gym_EventScript_NormanIntroducesGym
	// VAR_TEMP_1: how many trainers have been battled
	setvar VAR_TEMP_1, 0
	checktrainerflag TRAINER_BERKE
	call_if_eq PetalburgCity_Gym_EventScript_CountTrainers
	checktrainerflag TRAINER_JODY
	call_if_eq PetalburgCity_Gym_EventScript_CountTrainers
	compare VAR_TEMP_1, 2
	goto_if_eq PetalburgCity_Gym_EventScript_InitiateBattle
	msgbox PetalburgCity_Gym_Text_NotDefeatedTrainers, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_InitiateBattle::
	msgbox PetalburgCity_Gym_Text_YouDefeatedGymTrainers, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_NORMAN_1, PetalburgCity_Gym_Text_NormanDefeat
	message PetalburgCity_Gym_Text_ReceivedBalanceBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox PetalburgCity_Gym_Text_ExplainBalanceBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_PETALBURG_GYM
	setvar VAR_PETALBURG_GYM_STATE, 7
	setflag FLAG_BADGE05_GET
	clearflag FLAG_HIDE_DEWFORD_HALL_SLUDGE_BOMB_MAN
	call PetalburgCity_Gym_EventScript_UnlockAllDoors
	special DrawWholeMapView
	call PetalburgCity_Gym_EventScript_GiveFacade
	delay 30
	msgbox PetalburgCity_Gym_Text_DadHappyAndSad, MSGBOX_DEFAULT
	delay 30
	msgbox PetalburgCity_Gym_Text_TheNextGymIsAtRustboro, MSGBOX_DEFAULT
	release
	end
	
PetalburgCity_Gym_EventScript_CountTrainers::
	addvar VAR_TEMP_1, 1
	return	

PetalburgCity_Gym_EventScript_NormanIntroducesGym::
	msgbox PetalburgCity_Gym_Text_HowWasVerdanturf, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Movement_Norman_ToDoor
	waitmovement 0
	opendoor 4, 105
	waitdooranim
	applymovement 1, Movement_Norman_ToDoor
	waitmovement 0
	removeobject 1
	setflag FLAG_HIDE_PETALBURG_GYM_NORMAN
	closedoor 4, 105
	waitdooranim
	setflag FLAG_NORMAN_INTRODUCED_GYM
	release
	end

Movement_Norman_ToDoor:
	walk_up
	step_end
	
PetalburgCity_Gym_EventScript_GiveFacade:: @ 8204ED2
// >

< //
PetalburgCity_Gym_EventScript_ReturnFromWallyTutorial:: @ 82049A4
	lockall
	msgbox PetalburgCity_Gym_Text_DadSoDidItWorkOut, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_WallyThankYouBye, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyExitGym
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_WALLY
	setflag FLAG_HIDE_PETALBURG_CITY_WALLY
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	//msgbox PetalburgCity_Gym_Text_DadGoCollectBadges, MSGBOX_DEFAULT
	setflag FLAG_ROUTE_103_EAST_ACCESSIBLE
	msgbox PetalburgCity_Gym_Text_DadGoHelpBreeder, MSGBOX_DEFAULT
	giveitem ITEM_QUEST_LOG
	msgbox PetalburgCity_Gym_Text_DadThisIsTheQuestLog, MSGBOX_DEFAULT
	delay 40
	bufferitemname 0, ITEM_QUEST_LOG
	setflag FLAG_QUEST_MENU_ACTIVE
	questmenu QUEST_MENU_UNLOCK_QUEST SIDE_QUEST_1
	call NoteNewQuestSingle
	msgbox PetalBurgCity_Gym_Text_DadOffYouGoThen, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_GYM_STATE, 2
	releaseall
	end

NoteNewQuestSingle::
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox Text_NewQuestWasUnlocked MSGBOX_DEFAULT
	closemessage
	delay 20
	return
	
NoteNewQuestSeveral::
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox Text_NewQuestsWereUnlocked, MSGBOX_DEFAULT
	closemessage
	delay 20
	return
	
Text_NewQuestWasUnlocked:
	.string "A new quest was unlocked!$"

Text_NewQuestsWereUnlocked:
	.string "New quests were unlocked!$"	
	
CompleteQuestFanfare::
	delay 20
	compare VAR_0x800A, 0
	call_if_eq QuestFanfareEasy
	compare VAR_0x800A, 1
	call_if_eq QuestFanfareMedium
	compare VAR_0x800A, 2
	call_if_eq QuestFanfareHard
	compare VAR_0x800A, 3
	call_if_eq QuestFanfareExtreme
	msgbox Text_QuestWasComplete, MSGBOX_DEFAULT
	return
	
QuestFanfareEasy::
	playfanfare MUS_OBTAIN_ITEM
	return
	
QuestFanfareMedium::
	playfanfare MUS_SLOTS_WIN
	return
	
QuestFanfareHard::
	playfanfare MUS_SLOTS_JACKPOT
	return
	
QuestFanfareExtreme::
	playfanfare MUS_OBTAIN_SYMBOL
	return
	
Text_QuestWasComplete::
	.string "The quest “{STR_VAR_1}”\n"
	.string "was complete!$"
	
PetalburgCity_Gym_Movement_WallyExitGym: @ 82049EC
// >

< //
PetalburgCity_Gym_EventScript_NormanNoBadges:: @ 8204D4A
	//msgbox PetalburgCity_Gym_Text_NormanGoToRustboro, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_NormanGoToVerdanturf, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_NormanOneBadge:: @ 8204D54
// >

< //	
PetalburgCity_Gym_Text_NormanGoToRustboro: @ 8205DB4
	.string "DAD: Hm? Aren't you going to the\n"
	.string "POKéMON GYM in RUSTBORO CITY?\p"
	.string "There's no challenge for me to\n"
	.string "battle a greenhorn TRAINER.\p"
	.string "{PLAYER}, I want you to challenge me\n"
	.string "when you become a lot stronger.\p"
	.string "I'll battle you, {PLAYER}, when you\n"
	.string "can show me four GYM BADGES, okay?$"

PetalburgCity_Gym_Text_DadGoHelpBreeder: @ 8205C40
	.string "DAD: Now…\p"
	.string "{PLAYER}, if you want to become a\n"
	.string "strong TRAINER, here's my advice.\p"
	.string "Head for VERDANTURF TOWN, through\n"
	.string "ALTERING CAVE.\p"
	.string "There's a POKéMON BREEDER at the\n"
	.string "BREEDER's CLUB that needs help.\p"
	.string "After that, we can have an official\n"
	.string "battle here at the GYM.\p"
	.string "To help you keep track of your\n"
	.string "adventures, here's something\l"
	.string "for you.$"
	
PetalburgCity_Gym_Text_DadThisIsTheQuestLog:
	.string "DAD: This is the {STR_VAR_1}.\n"
	.string "You will find people who need\l"
	.string "help, or others who want to\l"
	.string "challenge you in battle or\l"
	.string "otherwise.\p"
	.string "Use this gadget to record those\n"
	.string "and find new quests to complete!\p"
	.string "Here, I'll unlock the first\n"
	.string "quest for you.$"

PetalBurgCity_Gym_Text_DadOffYouGoThen:
	.string "DAD: With that, you're ready\n"
	.string "to set for VERDANTURF TOWN.\p"
	.string "So, off you go, then!$"

PetalburgCity_Gym_Text_NormanGoToVerdanturf: @ 8205DB4
	.string "DAD: Hm? Aren't you going to the\n"
	.string "BREEDER's CLUB in VERDANTURF?\l"
	.string "There's a lady who needs your help.\n"
	.string "I'll battle you, {PLAYER}, when you\n"
	.string "have visited VERDANTURF TOWN, okay?$"

PetalburgCity_Gym_Text_HowWasVerdanturf: @ 8205FE5
	.string "So, how was VERDANTURF TOWN?\p"
	.string "Oh, you got an EGG?\n"
	.string "You should carry it with you and it\l"
	.string "will hatch when it is mature.\p"
	.string "But now, we will battle. As per the\n"
	.string "official protocol, I will stand at the\l"
	.string "battlefield.\p"
	.string "At a POKéMON GYM, you will always\n"
	.string "face TRAINERS before the LEADER.\p"
	.string "To prove your strength, beat the other\n"
	.string "TRAINERS. Only then can you battle the\l"
	.string "GYM LEADER.\p"
	.string "{PLAYER}, good luck!$"	

PetalburgCity_Gym_Text_NotDefeatedTrainers:
	.string "DAD: Well, aren't you enthusiastic!\p"
	.string "Beat the two TRAINERS in this room\n"
	.string "first, and then we will battle.$"
	
PetalburgCity_Gym_Text_YouDefeatedGymTrainers:
	.string "DAD: Hm…\n"
	.string "So, you did defeat the GYM TRAINERS.\p"
	.string "Fine, as I promised, we will have\n"
	.string "a POKéMON battle.\p"
	.string "I will do everything in my power as\n"
	.string "a GYM LEADER to win.\p"
	.string "{PLAYER}, you'd better give it your\n"
	.string "best shot, too!$"	

PetalburgCity_Gym_Text_TheNextGymIsAtRustboro:
	.string "Now, you defeated me truly and\n"
	.string "completely.\p"
	.string "But I'm just one of the eight\n"
	.string "GYM LEADERS.\p"
	.string "If you want to keep getting\n"
	.string "stronger, the next GYM is in \l"
	.string "RUSTBORO CITY.\p"
	.string "Go west of PETALBURG and you\n"
	.string "should find it easily enough.\p"
	.string "Say hi to ROXANNE from me, {PLAYER}!$"
	
PetalburgCity_Gym_Text_NormanGoToDewford: @ 8205EAE
// >

< //
PetalburgCity_Gym_Text_GymGuideAdvice: @ 8206542
	.string "Hey, how's it going, novice TRAINER?\p"
	.string "Before facing the GYM LEADER, you\n"
	.string "have to defeat the GYM TRAINERS.\p"
	.string "They have tough POKéMON, so you\n"
	.string "need to be well prepared.\p"
	.string "Go for it, {PLAYER}!$"

PetalburgCity_Gym_Text_GymGuidePostVictory: @ 82066F3
// >

< //
PetalburgCity_Gym_EventScript_Berke:: @ 820546E
	trainerbattle_single TRAINER_BERKE, PetalburgCity_Gym_Text_BerkeIntro, PetalburgCity_Gym_Text_BerkeDefeat
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_BerkePostBadge
	msgbox PetalburgCity_Gym_Text_BerkePostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenOHKORoomDoors:: @ 8205492
// >

< //
PetalburgCity_Gym_EventScript_Jody:: @ 8205522
	trainerbattle_single TRAINER_JODY, PetalburgCity_Gym_Text_JodyIntro, PetalburgCity_Gym_Text_JodyDefeat
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_JodyPostBadge
	msgbox PetalburgCity_Gym_Text_JodyPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenStrengthRoomDoors:: @ 8205546
// >

< //
PetalburgCity_Gym_Text_BerkeIntro: @ 8206BF4
	.string "I'm not going to take it easy just\n"
	.string "because you're our LEADER's kid.\p"
	.string "Come on, show me what you've got!$"

PetalburgCity_Gym_Text_BerkeDefeat: @ 8206C7D
// >

< //
PetalburgCity_Gym_Text_JodyPostBattle: @ 82070FB
	.string "The way you use your POKéMON…\n"
	.string "It's like your father's style.\p"
	.string "Go on! The GYM LEADER, your father,\n"
	.string "is waiting!$"

PetalburgCity_Gym_Text_JodyPostBadge: @ 8207170
// >