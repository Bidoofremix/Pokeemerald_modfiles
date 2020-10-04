< //
MauvilleCity_GameCorner_MapScripts:: @ 820FBB8
	.byte 0

    @ Game Corner prices
	.set TM32_COINS,  1500
	.set TM29_COINS,  3500
	.set TM35_COINS,  4000
	.set TM24_COINS,  4000
	.set TM13_COINS,  4000
	.set DOLL_COINS,  1000
	.set STONE_COINS, 2000

	.set COINS_PRICE_50,  1000
	.set COINS_PRICE_500, 10000

MauvilleCity_GameCorner_EventScript_CoinsClerk:: @ 820FBB9
// >

< //
MauvilleCity_GameCorner_EventScript_PrizeCornerDolls:: @ 820FCF1
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_GameCorner_EventScript_ChooseDollPrizeMessage
	release
	end

MauvilleCity_GameCorner_EventScript_ChooseDollPrizeMessage:: @ 820FEBB
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	showcoinsbox 1, 1
	goto MauvilleCity_GameCorner_EventScript_ChooseDollPrize

MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize:: @ 820FECE
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	goto MauvilleCity_GameCorner_EventScript_ChooseDollPrize

MauvilleCity_GameCorner_EventScript_ChooseDollPrize:: @ 820FED9
	multichoice 12, 0, MULTI_GAME_CORNER_STONES_2, 0
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_SunStone
	case 1, MauvilleCity_GameCorner_EventScript_MoonStone
	case 2, MauvilleCity_GameCorner_EventScript_ShinyStone
	case 3, MauvilleCity_GameCorner_EventScript_DuskStone
	case 4, MauvilleCity_GameCorner_EventScript_DawnStone
	goto MauvilleCity_GameCorner_EventScript_CancelDollSelect
	end
	
MauvilleCity_GameCorner_EventScript_SunStone:: @ 820FF2B
	setvar VAR_TEMP_1, 0
	bufferitemname 0, ITEM_SUN_STONE
	setvar VAR_0x8004, ITEM_SUN_STONE
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize

MauvilleCity_GameCorner_EventScript_MoonStone:: @ 820FF2B
	setvar VAR_TEMP_1, 1
	bufferitemname 0, ITEM_MOON_STONE
	setvar VAR_0x8004, ITEM_MOON_STONE
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize	
	
MauvilleCity_GameCorner_EventScript_ShinyStone:: @ 820FF2B
	setvar VAR_TEMP_1, 2
	bufferitemname 0, ITEM_SHINY_STONE
	setvar VAR_0x8004, ITEM_SHINY_STONE
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize

MauvilleCity_GameCorner_EventScript_DuskStone:: @ 820FF2B
	setvar VAR_TEMP_1, 3
	bufferitemname 0, ITEM_DUSK_STONE
	setvar VAR_0x8004, ITEM_DUSK_STONE
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize

MauvilleCity_GameCorner_EventScript_DawnStone:: @ 820FF2B
	setvar VAR_TEMP_1, 4
	bufferitemname 0, ITEM_DAWN_STONE
	setvar VAR_0x8004, ITEM_DAWN_STONE
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize

MauvilleCity_GameCorner_EventScript_TreeckoDoll:: @ 820FD67
// >

< //
MauvilleCity_GameCorner_EventScript_ChooseTMPrize:: @ 820FED9
	multichoice 12, 0, MULTI_GAME_CORNER_STONES_1, 0
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_FireStone
	case 1, MauvilleCity_GameCorner_EventScript_WaterStone
	case 2, MauvilleCity_GameCorner_EventScript_ThunderStone
	case 3, MauvilleCity_GameCorner_EventScript_LeafStone
	case 4, MauvilleCity_GameCorner_EventScript_IceStone
	case 5, MauvilleCity_GameCorner_EventScript_CancelTMSelect
	goto MauvilleCity_GameCorner_EventScript_CancelTMSelect
	end
	
MauvilleCity_GameCorner_EventScript_FireStone:: @ 820FF2B
	setvar VAR_TEMP_1, 1
	bufferitemname 0, ITEM_FIRE_STONE
	setvar VAR_0x8004, ITEM_FIRE_STONE
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize

MauvilleCity_GameCorner_EventScript_WaterStone:: @ 820FF2B
	setvar VAR_TEMP_1, 2
	bufferitemname 0, ITEM_WATER_STONE
	setvar VAR_0x8004, ITEM_WATER_STONE
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize

MauvilleCity_GameCorner_EventScript_ThunderStone:: @ 820FF2B
	setvar VAR_TEMP_1, 3
	bufferitemname 0, ITEM_THUNDER_STONE
	setvar VAR_0x8004, ITEM_THUNDER_STONE
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize

MauvilleCity_GameCorner_EventScript_LeafStone:: @ 820FF2B
	setvar VAR_TEMP_1, 4
	bufferitemname 0, ITEM_LEAF_STONE
	setvar VAR_0x8004, ITEM_LEAF_STONE
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize

MauvilleCity_GameCorner_EventScript_IceStone:: @ 820FF2B
	setvar VAR_TEMP_1, 5
	bufferitemname 0, ITEM_ICE_STONE
	setvar VAR_0x8004, ITEM_ICE_STONE
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize

MauvilleCity_GameCorner_EventScript_TM32:: @ 820FF2B
// >

< //
MauvilleCity_GameCorner_EventScript_ConfirmDollPrize:: @ 820FD91
	bufferitemname 0, VAR_0x8004
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIs, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_GameCorner_EventScript_CancelTMSelect
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, STONE_COINS
	goto_if_lt MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitemspace VAR_0x8004, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoRoomForTM
	removecoins STONE_COINS
	additem VAR_0x8004
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

MauvilleCity_GameCorner_EventScript_BuyTreeckoDoll:: @ 820FDCB
// >

< //
MauvilleCity_GameCorner_EventScript_ConfirmTMPrize:: @ 820FF8A
	bufferitemname 0, VAR_0x8004
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIs, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_GameCorner_EventScript_CancelTMSelect
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, STONE_COINS
	goto_if_lt MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitemspace VAR_0x8004, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoRoomForTM
	removecoins STONE_COINS
	additem VAR_0x8004
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end
	
MauvilleCity_GameCorner_EventScript_BuyTM32:: @ 820FFDD
// >

< //
MauvilleCity_GameCorner_Text_SoYourChoiceIsTheTMX: @ 8210629
	.string "So your choice is\n"
	.string "the {STR_VAR_1} {STR_VAR_2}?$"

MauvilleCity_GameCorner_Text_SoYourChoiceIs: @ 8210629
	.string "So your choice is\n"
	.string "{STR_VAR_1}?$"	
	
MauvilleCity_GameCorner_Text_SendToYourHomePC: @ 8210646
// >