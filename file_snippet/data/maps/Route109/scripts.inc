< //
Route109_EventScript_OldMan:: @ 81EEA0F
	lock
	faceplayer
	bufferspeciesname 0, SPECIES_ZIGZAGOON
	questmenu QUEST_MENU_CHECK_COMPLETE SIDE_QUEST_21
	goto_if_eq Route109_EventScript_ShoreUpTutor
	questmenu QUEST_MENU_CHECK_UNLOCKED SIDE_QUEST_21
	goto_if_ne Route109_EventScript_OldMan_QuestNotUnlocked
	compare VAR_ROUTE109_STATE, 0
	goto_if_eq Route109_EventScript_OldMan_QuestStart
	compare VAR_ROUTE109_STATE, 1
	goto_if_eq Route109_EventScript_CheckFoundItems
	end
	
Route109_EventScript_OldMan_QuestStart::	
	msgbox Route109_Text_IAmTryingToCleanUpWithZigzagoon, MSGBOX_DEFAULT
	giveitem ITEM_ITEMFINDER
	setvar VAR_ROUTE109_STATE, 1
	end

Route109_EventScript_CheckFoundItems::
	setvar VAR_TEMP_0, 0
	call_if_set FLAG_HIDDEN_ITEM_ROUTE_109_REVIVE, Route109_EventScript_AddTempVar
	call_if_set FLAG_HIDDEN_ITEM_ROUTE_109_GREAT_BALL, Route109_EventScript_AddTempVar
	call_if_set FLAG_HIDDEN_ITEM_ROUTE_109_ETHER, Route109_EventScript_AddTempVar
	call_if_set FLAG_HIDDEN_ITEM_ROUTE_109_TWISTED_SPOON, Route109_EventScript_AddTempVar
	call_if_set FLAG_HIDDEN_ITEM_ROUTE_109_SUPER_REPEL, Route109_EventScript_AddTempVar
	call_if_set FLAG_HIDDEN_ITEM_ROUTE_109_LEMONADE, Route109_EventScript_AddTempVar
	call_if_set FLAG_HIDDEN_ITEM_ROUTE_109_BURN_HEAL, Route109_EventScript_AddTempVar
	call_if_set FLAG_HIDDEN_ITEM_ROUTE_109_WISE_GLASS, Route109_EventScript_AddTempVar
	compare VAR_TEMP_0, 8
	goto_if_eq Route109_EventScript_FoundAllItems
	goto_if_ne Route109_EventScript_NotAllItemsFound
	end
	
Route109_EventScript_AddTempVar::
	addvar VAR_TEMP_0, 1
	return
	
Route109_EventScript_FoundAllItems::
	msgbox Route109_Text_YouHavePickedUpSoManyItems, MSGBOX_DEFAULT
	questmenu QUEST_MENU_COMPLETE_QUEST SIDE_QUEST_21
	call CompleteQuestFanfare
	msgbox Route109_Text_InsteadOfAnItemReward, MSGBOX_DEFAULT
	goto Route109_EventScript_ShoreUpTutor
	end

Route109_EventScript_NotAllItemsFound::
	msgbox Route109_Text_IThinkThereAreMoreItems, MSGBOX_DEFAULT
	release
	end
	
Route109_EventScript_OldMan_QuestNotUnlocked::
	msgbox Route109_Text_ZigzagoonPicksUpLitter, MSGBOX_DEFAULT
	release
	end

Route109_EventScript_ShoreUpTutor::
	msgbox Route109_Text_ICanTeachYourMon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Route109_EventScript_ShoreUpDeclined
	msgbox Rute109_Text_ShoreUpWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_SHORE_UP
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq Route109_EventScript_ShoreUpDeclined
	goto Route109_EventScript_ShoreUpTaught
	end
	
Route109_EventScript_ShoreUpDeclined::
	msgbox Route109_Text_ComeBackIfYouWantToTeach, MSGBOX_DEFAULT
	release
	end
	
Route109_EventScript_ShoreUpTaught::
	msgbox Route109_Text_SomeWaterPokemonEnjoyRest, MSGBOX_DEFAULT
	release
	end
	
Route109_Text_IAmTryingToCleanUpWithZigzagoon:
	.string "Every day, I try to clean the beach\n"
	.string "with {STR_VAR_1}.\p"
	.string "People are carelessly throwing litter\n"
	.string "onto this shore and the sea.\p"
	.string "But we are both getting old and slow,\n"
	.string "and my knees aren't what they used\l"
	.string "to be.\p"
	.string "Could you maybe help us? I can give\n"
	.string "you this to help with finding\l"
	.string "the trash.$"
	
Route109_Text_YouHavePickedUpSoManyItems:
	.string "Ohoho! You have picked up so many\n"
	.string "items, the beach looks pristine.\p"
	.string "Thank you for your hard work.$"
	
Route109_Text_InsteadOfAnItemReward:
	.string "Instead of a material reward, I'd\n"
	.string "like to offer you something else.$"

Route109_Text_ICanTeachYourMon:
	.string "I can teach your POKéMON the move\n"
	.string "Shore Up. Would you like that?$"

Rute109_Text_ShoreUpWhichMon:
	.string "Which POKéMON should I teach?$"
	
Route109_Text_SomeWaterPokemonEnjoyRest:
	.string "Some WATER POKéMON enjoy resting\n"
	.string "at a shore between long sea journeys.\p"
	.string "That's why they can recover health\n"
	.string "using Shore Up.$"
	
Route109_Text_ComeBackIfYouWantToTeach:
	.string "Come back if you want me to teach\n"
	.string "a move to your POKéMON.$"
	
Route109_Text_IThinkThereAreMoreItems:	
	.string "Hmm… I think there are more items\n"
	.string "still on this beach.$"	
	
Route109_EventScript_Zigzagoon:: @ 81EEA18
// >

< //
Route109_Text_ZigzagoonPicksUpLitter: @ 81EF080
	.string "The water around these parts is clean.\p"
	.string "But, I get my {STR_VAR_1} to pick up\n"
	.string "litter from the shoreline at times.\p"
	.string "Dirty water becomes rain and joins our\n"
	.string "rivers, which we drink from…\p"
	.string "If we pollute the sea, it all comes\n"
	.string "back to haunt us eventually.$"

Route109_Text_ZigzagoonCry: @ 81EF173
// >

< //
DewfordTown_Text_BrineyLandedInSlateportDeliverGoods: @ 81EEC1D
	.string "MR. BRINEY: Ahoy!\n"
	.string "We've made land in SLATEPORT!\p"
	.string "I suppose you're going to visit CAPT.\n"
	.string "STERN and deliver the FLASHDRIVE?$"

Route109_Text_BrineySailToDewfordQuestion: @ 81EEC96
	.string "MR. BRINEY: I thought you're supposed\n"
	.string "to deliver the FLASHDRIVE.\p"
	.string "Would you like to sail back to\n"
	.string "DEWFORD, then?$"

Route109_Text_BrineyDewfordItIs: @ 81EED06
	.string "MR. BRINEY: DEWFORD it is, then!\p"
	.string "Anchors aweigh!\n"
	.string "PEEKO, we're setting sail, my darling!$"

Route109_Text_BrineyDeliverDevonGoods: @ 81EED5E
	.string "MR. BRINEY: Then you go on and deliver\n"
	.string "the FLASHDRIVE. I'll be waiting.$"

DewfordTown_Text_BrineyLandedInSlateport: @ 81EEDA7
// >