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
	setobjectxyperm LOCALID_COOLTRAINER, 8, 18
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