< //
.equ LOCALID_BRINEY_R104, 8

.set LOCALID_COOLTRAINER, 6

DewfordTown_MapScripts:: @ 81E9507
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_OnTransition
	.byte 0
// >

< //
DewfordTown_OnTransition: @ 81E950D
	setflag FLAG_VISITED_DEWFORD_TOWN
	call BrineBeach_EventScript_ControlWeather
	call_if_unset FLAG_DEFEATED_GYARADOS, DewfordTown_EventScript_SetCooltrainer
	end

DewfordTown_EventScript_SetCooltrainer::
	setobjectxyperm LOCALID_COOLTRAINER, 3, 13
	setobjectmovementtype LOCALID_COOLTRAINER, MOVEMENT_TYPE_FACE_DOWN
	end
	
DewfordTown_EventScript_CoolTrainer::
	lock
	faceplayer
	goto_if_unset FLAG_DEFEATED_GYARADOS, DewfordTown_EventScript_NotDefeatedGyarados
	msgbox DewfordTown_Text_IHeardYouBattledGyarados, MSGBOX_DEFAULT
	release
	end
	
DewfordTown_EventScript_NotDefeatedGyarados::
	msgbox DewfordTown_Text_BrawleyIsNotHere, MSGBOX_DEFAULT
	release
	end
	
DewfordTown_Text_BrawleyIsNotHere::
	.string "If you're here for a GYM battle,\n"
	.string "you're out of luck. The LEADER\l"
	.string "isn't here.\p"
	.string "There's a commotion down at\n"
	.string "BRINE BEACH.\p"
	.string "It's related to this awful\n"
	.string "storm, apparently.$"
	
DewfordTown_Text_IHeardYouBattledGyarados::
	.string "I heard that you battled the enraged\n"
	.string "Gyarados at BRINE BEACH!\p"
	.string "Thanks to your brave actions,\n"
	.string "DEWFORD TOWN was saved!\l"
	.string "You're a hero!$"
	
DewfordTown_EventScript_MarineShopSign::
	msgbox DewfordTown_Text_MarineShopSign, MSGBOX_SIGN
	end	

DewfordTown_Text_MarineShopSign::
	.string "MARINE SHOP\n"
	.string "“All things ocean!”$"

DewfordTown_EventScript_NormalTypeTrainer::
	lock
	faceplayer

	// check if battle has been complete
	goto_if_defeated TRAINER_MASTER_NORMAL, DewfordTown_EventScript_QuestComplete
	
	// check if quest unlocked
	msgbox DewfordTown_Text_IAmNormalTypeMasterTrainer
	questmenu QUEST_MENU_CHECK_UNLOCKED SIDE_QUEST_13
	compare VAR_RESULT, TRUE
	goto_if_eq DewfordTown_EventScript_AskToBattle
	goto_if_ne DewfordTown_EventScript_QuestNotUnlocked
	end
	
DewfordTown_EventScript_AskToBattle::
	msgbox DewfordTown_Text_YouLookLikeAStrongTrainer, MSGBOX_YESNO
	compare VAR_RESULT, TRUE
	
	// no battle
	goto_if_ne DewfordTown_EventScript_CancelBattle
	
	// check party type
	setvar VAR_0x800A, TYPE_NORMAL
	call_if_eq Common_EventScript_CheckPartyType
	compare VAR_RESULT, FALSE
	call_if_eq DewfordTown_EventScript_NotNormalType
	
	// do battle
	trainerbattle_no_intro TRAINER_MASTER_NORMAL, DewfordTown_Text_NormalTypeTrainer_Lose

	// defeated
	delay 40
	msgbox DewfordTown_Text_IWasntExpecting, MSGBOX_DEFAULT
	// reward
	giveitem ITEM_TM20
	msgbox DewfordTown_Text_LookForOtherMasterTrainers, MSGBOX_DEFAULT	
	release	
	end
	
DewfordTown_EventScript_QuestNotUnlocked::
	msgbox DewfordTown_Text_YoureNotStrongEnough, MSGBOX_DEFAULT
	release
	end
	
DewfordTown_EventScript_NotNormalType::
	msgbox DewfordTown_Text_NotAllNormalType, MSGBOX_DEFAULT
	goto DewfordTown_EventScript_CancelBattle
	end
	
DewfordTown_EventScript_CancelBattle::
	msgbox DewfordTown_Text_IfYouWantToBattle, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_QuestComplete::
	msgbox DewfordTown_Text_YouAreExceptionallyStrong, MSGBOX_DEFAULT
	release
	end
	
DewfordTown_Text_YouAreExceptionallyStrong:
	.string "I have to admit that you are\n"
	.string "exceptionally strong.\p"
	.string "Please enjoy your battles with\n"
	.string "other MASTER TRAINERS as well.$"
	
DewfordTown_Text_IWasntExpecting:
	.string "I wasn't expecting you to dominate\n"
	.string "my POKéMON so completely.\p"
	.string "As your rightful reward for\n"
	.string "defeating me, please take this.$"
	
DewfordTown_Text_LookForOtherMasterTrainers:
	.string "If you meet other MASTER TRAINERS,\n"
	.string "please give my regards to them.$"
	
DewfordTown_Text_YoureNotStrongEnough:
	.string "Aren't you a cute rookie TRAINER,\n"
	.string "honey.\p"
	.string "You may challenge me to a battle\n"
	.string "when you are more experienced.$"
	
DewfordTown_Text_IAmNormalTypeMasterTrainer:
	.string "I am a MASTER TRAINER of\n"
	.string "NORMAL TYPE POKéMON.\p"
	.string "Should you wish to battle me,\n"
	.string "you must agree to use only\l"
	.string "NORMAL TYPE POKéMON.$"
	
DewfordTown_Text_YouLookLikeAStrongTrainer:
	.string "You look like a strong TRAINER.\n"
	.string "Do you accept my challenge?$"
	
DewfordTown_Text_NotAllNormalType:
	.string "Please, you're not fooling anyone.\n"
	.string "Rid your party of other than NORMAL\l"
	.string "TYPES, and I may reconsider.$"
	
DewfordTown_Text_IfYouWantToBattle:
	.string "I'll be waiting for you, honey,\n"
	.string "if you change your mind.$"
	
DewfordTown_Text_NormalTypeTrainer_Lose:
	.string "What…?$"	
	
DewfordTown_EventScript_Briney:: @ 81E9511
// >

< //
DewfordTown_EventScript_HowsFishing:: @ 81E962A
	questmenu QUEST_MENU_CHECK_COMPLETE SIDE_QUEST_16
	compare VAR_RESULT, TRUE
	goto_if_eq DewfordTown_EventScript_CompletedQuest
	questmenu QUEST_MENU_CHECK_UNLOCKED SIDE_QUEST_16
	compare VAR_RESULT, TRUE
	goto_if_eq DewfordTown_EventScript_TryCompleteQuest
	message DewfordTown_Text_HowsYourFishing
	waitmessage
	multichoice 20, 8, MULTI_HOWS_FISHING, 1
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_EventScript_FishingExcellent
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_EventScript_FishingNotSoGood
	end

DewfordTown_EventScript_TryCompleteQuest::
	msgbox DewfordTown_Text_HowsYourFishing, MSGBOX_DEFAULT
	special CheckIfFished20Mons
	compare VAR_RESULT, TRUE
	goto_if_eq DewfordTown_EventScript_Fished20Mons
	goto_if_ne DewfordTown_EventScript_FishedLessThan20Mons
	release
	
DewfordTown_EventScript_FishedLessThan20Mons::
	msgbox DewfordTown_Text_YouNeedMoreExperience, MSGBOX_DEFAULT
	release
	end
	
DewfordTown_EventScript_Fished20Mons::
	msgbox DewfordTown_Text_WowYouHaveHauledInLoads, MSGBOX_DEFAULT
	questmenu QUEST_MENU_COMPLETE_QUEST SIDE_QUEST_16
	call CompleteQuestFanfare
	questmenu QUEST_MENU_UNLOCK_QUEST SIDE_QUEST_21
	call NoteNewQuestSingle
	msgbox DewfordTown_Text_ExperienceWithWaterPokemon, MSGBOX_DEFAULT
	giveitem ITEM_WATER_STONE
	compare VAR_RESULT, 0
	goto_if_eq VerdanturfTown_BreedersClub_EventScript_OldLady_BagIsFull
	setflag FLAG_RECEIVED_FISHERMAN_WATER_STONE
	release
	end
	
DewfordTown_EventScript_CompletedQuest::
	goto_if_unset FLAG_RECEIVED_FISHERMAN_WATER_STONE, DewfordTown_EventScript_TryGiveReward
	msgbox DewfordTown_Text_HelloFellowAngler, MSGBOX_NPC
	end
	
DewfordTown_EventScript_TryGiveReward::
	msgbox DewfordTown_Text_ExperienceWithWaterPokemon, MSGBOX_DEFAULT
	giveitem ITEM_WATER_STONE
	compare VAR_RESULT, 0
	goto_if_eq VerdanturfTown_BreedersClub_EventScript_OldLady_BagIsFull
	setflag FLAG_RECEIVED_FISHERMAN_WATER_STONE
	release
	end
	
DewfordTown_Text_YouNeedMoreExperience:
	.string "Hmm…\p"
	.string "You still need more experience\n"
	.string "in fishing.\p"
	.string "Haul in at least 20 POKéMON\n"
	.string "and I'll give you something to\l"
	.string "make it worth your time.$"
	
DewfordTown_Text_WowYouHaveHauledInLoads:
	.string "Wow! You have hauled in loads\n"
	.string "of POKéMON!$"
	
DewfordTown_Text_ExperienceWithWaterPokemon:
	.string "By now, you must have so much\n"
	.string "experience with WATER POKéMON\l"
	.string "that this is probably more useful\l"
	.string "to you than me.$"
	
DewfordTown_Text_HelloFellowAngler:
	.string "Hello, fellow angler!\n"
	.string "Tight lines and bent rods!$"	
	
DewfordTown_EventScript_FishingExcellent:: @ 81E964C
// >