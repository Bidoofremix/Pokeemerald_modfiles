< //
RustboroCity_DevonCorp_2F_EventScript_PokemonDreamsScientist:: @ 82118DA
	lock
	faceplayer
	compare VAR_FOSSIL_RESURRECTION_STATE, 1
	call_if_eq RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	msgbox RustboroCity_DevonCorp_2F_Text_DeviceToVisualizePokemonDreams, MSGBOX_DEFAULT
	goto_if_unset FLAG_UNIVERSITY_RECEIVED_DREAM_BALL, RustboroCity_DevonCorp_2F_EventScript_GiveDreamBall
	release
	end

RustboroCity_DevonCorp_2F_EventScript_GiveDreamBall::
	giveitem ITEM_DREAM_BALL
	compare VAR_RESULT, FALSE
	goto_if_eq OldaleTown_EventScript_BagIsFull
	setflag FLAG_UNIVERSITY_RECEIVED_DREAM_BALL
	release
	end
	
RustboroCity_DevonCorp_2F_EventScript_NoRoomForDreamBall::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	release
	end
	
RustboroCity_DevonCorp_2F_EventScript_WeUsedToHaveADevice::
	lock
	faceplayer
	msgbox RustboroCity_DevonCorp_2F_Text_DeviceToReviveFossils, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_Text_DeviceToReviveFossils:
	.string "We used to have a device to revive\n"
	.string "ancient POKéMON from fossils.\p"
	.string "But then, the ecology and evolution\n"
	.string "research group here at the UNIVERSITY\l"
	.string "discovered that the ancient POKéMON\l"
	.string "are not extinct after all!\p"
	.string "It just goes to show you how important\n"
	.string "it is to understand the environment\n"
	.string "around us.$"
	
RustboroCity_DevonCorp_2F_EventScript_FossilScientist:: @ 82118F1
// >

< //
RustboroCity_DevonCorp_2F_Text_WeFinallyMadeNewBalls: @ 8211C99
	.string "We finally made new kinds of\n"
	.string "POKé BALLS!\p"
	.string "The REPEAT BALL makes it easier to\n"
	.string "catch POKéMON you've caught before.\p"
	.string "The TIMER BALL gets better at catching\n"
	.string "POKéMON the longer a battle runs.\p"
	.string "Both are proudly developed by\n"
	.string "the RUSTBORO UNIVERSITY.\p"
	.string "Please give them a try!$"

RustboroCity_DevonCorp_2F_Text_IMadePokenav: @ 8211D9F
	.string "I made the POKéNAV!\p"
	.string "As an engineer, I feel blessed to have\n"
	.string "made something so great!$"

RustboroCity_DevonCorp_2F_Text_WowThatsAPokenav: @ 8211DF3
	.string "Oh, wow!\n"
	.string "That's a POKéNAV!\p"
	.string "It came about as a result of our\n"
	.string "desire to learn about the feelings\l"
	.string "and welfare of POKéMON.\p"
	.string "Would you like me to describe its\n"
	.string "features in detail?\p"
	.string "No, no. I think you'll find out just by\n"
	.string "trying the POKéNAV out.$"

RustboroCity_DevonCorp_2F_Text_DeviceToVisualizePokemonDreams: @ 8211EE0
	.string "I'm trying to develop a device that\n"
	.string "visually reproduces the dreams of\l"
	.string "POKéMON.$"

RustboroCity_DevonCorp_2F_Text_IMadeThisAsASideInvention:
	.string "As a side discovery, I came up with\n"
	.string "a new type of POKé BALL.\p"
	.string "Here, you can have one!$"

RustboroCity_DevonCorp_2F_Text_DevelopDeviceToResurrectFossils: @ 8211F48
// >

< //
RustboroCity_DevonCorp_2F_Text_OhIsThatSo: @ 8212046
	.string "Oh, is that so?\p"
	.string "The UNIVERSITY's technological\n"
	.string "expertise is outstanding,\l"
	.string "I tell you.$"

RustboroCity_DevonCorp_2F_Text_TwoFossilsPickOne: @ 8212092
// >

< //
RustboroCity_DevonCorp_2F_Text_WhatToWorkOnNext: @ 8212386
	.string "Well, now what shall I work on\n"
	.string "developing next?\p"
	.string "Our academic freedom allows us to\n"
	.string "make our inspirations into reality.\p"
	.string "One couldn't ask for a better\n"
	.string "environment as a researcher.$"
// > END
