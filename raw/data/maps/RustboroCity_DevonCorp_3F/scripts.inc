< //
RustboroCity_DevonCorp_3F_EventScript_MeetPresident:: @ 821246E
	lockall
	msgbox RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen
	waitmovement 0
	delay 80
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_TSURETEK, 0
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_PleaseGoAhead, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor, MSGBOX_DEFAULT
	giveitem ITEM_LETTER
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis, MSGBOX_DEFAULT
	playfanfare MUS_FANFA4
	//message RustboroCity_DevonCorp_3F_Text_ReceivedPokenav
	bufferitemname 0, ITEM_AMULET_COIN
	giveitem ITEM_AMULET_COIN
	compare VAR_RESULT, FALSE
	call_if_eq RustboroCity_DevonCorp_3F_EventScript_NoRoomForAmuletCoin
	call_if_ne RustboroCity_DevonCorp_3F_EventScript_ReceivedAmuletCoin
	//setflag FLAG_SYS_POKENAV_GET
	//setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT
	//msgbox RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp, MSGBOX_DEFAULT
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare, MSGBOX_DEFAULT
	setflag FLAG_HIDE_ROUTE_116_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDA
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_BRINEY_LOCATION, 1
	clearflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setvar VAR_DEVON_CORP_3F_STATE, 1
	setvar VAR_RUSTBORO_CITY_STATE, 6
	releaseall
	end

RustboroCity_DevonCorp_3F_EventScript_NoRoomForAmuletCoin::
	msgbox RustboroCity_DevonCorp_3F_Text_NoRoomForAmuletCoin, MSGBOX_DEFAULT
	end
	
RustboroCity_DevonCorp_3F_Text_NoRoomForAmuletCoin:
	.string "Oh?\p"
	.string "Your BAG is full.$"
	
RustboroCity_DevonCorp_3F_EventScript_ReceivedAmuletCoin::
	playfanfare MUS_FANFA4
	waitfanfare
	setflag FLAG_UNIVERSITY_RECEIVED_AMULET_COIN
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneExplainAmuletCoin, MSGBOX_DEFAULT
	end
	
RustboroCity_DevonCorp_3F_Text_MrStoneExplainAmuletCoin:
	.string "PROF. STONE: That {STR_VAR_1}…\p"
	.string "It is a fairly rare object that\n"
	.string "doubles the amount of money won\l"
	.string "from battles.\p"
	.string "I trust that you can put it to\n"
	.string "good use.$"	
	
RustboroCity_DevonCorp_3F_Text_MrStoneRestUp:
	.string "By the way, I've heard that sinister\n"
	.string "criminals--MAGMA and AQUA, I believe--\l"
	.string "have been making trouble far and wide.\p"
	.string "I think it would be best if you rested\n"
	.string "up before you go on your way.$"
	
RustboroCity_DevonCorp_3F_Movement_Unused: @ 821252F
// >


< //
RustboroCity_DevonCorp_3F_EventScript_MrStone:: @ 821256C
	lock
	faceplayer
	goto_if_unset FLAG_UNIVERSITY_RECEIVED_AMULET_COIN, RustboroCity_DevonCorp_3F_EventScript_TryGiveAmuletCoin
	goto_if_set FLAG_RECEIVED_EXP_SHARE, RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, RustboroCity_DevonCorp_3F_EventScript_GiveExpShare
	msgbox RustboroCity_DevonCorp_3F_Text_CountingOnYou, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_TryGiveAmuletCoin::
	lock
	faceplayer
	msgbox RustboroCity_DevonCorp_3F_Text_OhDearTheReward, MSGBOX_DEFAULT
	giveitem ITEM_AMULET_COIN
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_DevonCorp_3F_EventScript_NoRoomForAmuletCoin
	setflag FLAG_UNIVERSITY_RECEIVED_AMULET_COIN
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneExplainAmuletCoin, MSGBOX_DEFAULT
	release
	end
	
RustboroCity_DevonCorp_3F_Text_OhDearTheReward:
	.string "Oh dear!\p"
	.string "You still haven't received your\n"
	.string "reward for agreeing to take the\l"
	.string "LETTER to STEVEN.\p"
	.string "Here, please take this!$"
	
RustboroCity_DevonCorp_3F_EventScript_GiveExpShare:: @ 8212595
// >

< //
RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor: @ 8212609
	.string "I'm PROF. STONE, the RECTOR of\n"
	.string "the RUSTBORO UNIVERSITY.\p"
	.string "I'd just got word about you!\p"
	.string "You saved our staff not just once,\n"
	.string "but twice!\p"
	.string "I have a favor to ask of an amazing\n"
	.string "person like you.\p"
	.string "I understand that you're delivering\n"
	.string "a package to SLATEPORT's SHIPYARD.\p"
	.string "Well, on the way, could you stop off in\n"
	.string "DEWFORD TOWN?\p"
	.string "I was hoping that you'd deliver a\n"
	.string "LETTER to STEVEN in DEWFORD.$"

RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis: @ 821277C
	.string "PROF. STONE: Now, you should know\n"
	.string "that I am a very considerate RECTOR.\p"
	.string "So, I'd never be so cheap as to ask\n"
	.string "a favor for nothing in return.\p"
	.string "That's why I want you to have this!$"

RustboroCity_DevonCorp_3F_Text_ReceivedPokenav: @ 8212820
	.string "{PLAYER} received a POKéNAV.$"

RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp: @ 8212837
	.string "PROF. STONE: That device…\p"
	.string "It's a POKéMON NAVIGATOR, or POKéNAV\n"
	.string "for short.\p"
	.string "It's an indispensable tool for any\n"
	.string "TRAINER on an adventure.\p"
	.string "It has a map of the HOENN region.\p"
	.string "You can check the locations of\n"
	.string "DEWFORD and SLATEPORT easily!\p"
	.string "By the way, I've heard that sinister\n"
	.string "criminals--MAGMA and AQUA, I believe--\l"
	.string "have been making trouble far and wide.\p"
	.string "I think it would be best if you rested\n"
	.string "up before you go on your way.$"

RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare: @ 82129D2
	.string "PROF. STONE: Well, then, {PLAYER}{KUN},\n"
	.string "go with caution and care!$"

RustboroCity_DevonCorp_3F_Text_CountingOnYou: @ 8212A09
	.string "PROF. STONE: I'm counting on you!$"

RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter: @ 8212A29
	.string "PROF. STONE: You delivered my LETTER?\n"
	.string "Thank you kindly!\p"
	.string "This is my way of thanking you.\n"
	.string "It should help you, a TRAINER.$"

RustboroCity_DevonCorp_3F_Text_ExplainExpShare: @ 8212A9E
// >

< //
RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends: @ 8212B78
	.string "PROF. STONE: Since my youth, I've immersed\n"
	.string "myself in work.\p"
	.string "Consequently, I'm not familiar with\n"
	.string "trends and that sort of thing.\p"
	.string "But do young people all want to be\n"
	.string "TRAINERS in the POKéMON LEAGUE?$"

RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere: @ 8212C37
	.string "This is the UNIVERSITY's rectorate.\p"
	.string "Our RECTOR's main office is here.\p"
	.string "Anyway, I can't tell you how much I'm\n"
	.string "grateful for what you've done.\p"
	.string "Um… By the way, that FLASHDRIVE\n"
	.string "you got back for us…\p"
	.string "Could I get you to deliver that to\n"
	.string "the SHIPYARD in SLATEPORT?\p"
	.string "It would be awful if those robbers\n"
	.string "tried to take it again.\p"
	.string "Uh… Hehehe, so, uh, could I count\n"
	.string "on you to do that for me?\p"
	.string "Oh, that's right.\n"
	.string "Could you wait here a second?$"

RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe: @ 8212DE8
	.string "Our RECTOR would like to have\n"
	.string "a word with you.\p"
	.string "Please come with me.$"

RustboroCity_DevonCorp_3F_Text_PleaseGoAhead: @ 8212E2F
// >

< //
RustboroCity_DevonCorp_3F_Text_RareRocksDisplay: @ 8212EE9
	.string "It's a collection of rare rocks and\n"
	.string "stones assembled by the RECTOR.$"
// > END
