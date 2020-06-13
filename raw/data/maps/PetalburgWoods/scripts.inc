< //
PetalburgWoods_EventScript_DevonResearcherRight:: @ 822E079
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement 4, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_MGM0, 0
	applymovement 3, PetalburgWoods_Movement_AquaEntrance
// >

< //
PetalburgWoods_Text_HandOverThosePapers: @ 822E428
	.string "You! UNIVERSITY RESEARCHER!\p"
	.string "Hand over that flashdrive!$"

PetalburgWoods_Text_YouHaveToHelpMe: @ 822E457
	.string "Aiyeeeh!\p"
	.string "You're a POKéMON TRAINER, aren't you?\n"
	.string "You've got to help me, please!$"

PetalburgWoods_Text_NoOneCrossesTeamAqua: @ 822E4A5
	.string "Hunh? What do you think you're doing?\n"
	.string "What, you're going to protect him?\p"
	.string "No one who crosses TEAM MAGMA\n"
	.string "gets any mercy, not even a kid!\p"
	.string "Come on and battle me!$"

PetalburgWoods_Text_YoureKiddingMe: @ 822E542
	.string "You're kidding me! You're tough!$"

PetalburgWoods_Text_YouveGotSomeNerve: @ 822E563
	.string "Grrr… You've got some nerve\n"
	.string "meddling with TEAM MAGMA!\l"
	.string "Come on and battle me again!\p"
	.string "I wish I could say that, but I'm out of\n"
	.string "POKéMON…\p"
	.string "And, hey, we of TEAM MAGMA are also\n"
	.string "after something in RUSTBORO.\p"
	.string "I'll let you go today!$"

PetalburgWoods_Text_ThatWasAwfullyClose: @ 822E63D
	.string "Whew…\n"
	.string "That was awfully close!\p"
	.string "Thanks to you, he didn't rob me of\n"
	.string "this confidential data.\p"
	.string "I know, I'll give you a GREAT BALL as\n"
	.string "my thanks!$"

PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro: @ 822E6C7
	.string "Didn't that TEAM MAGMA thug say\n"
	.string "they were after something in\l"
	.string "RUSTBORO, too?$"
// >