< //
MauvilleCity_BikeShop_EventScript_Rydel:: @ 820EBBC
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, MauvilleCity_BikeShop_EventScript_RememberToAdvertiseYourBike
	goto_if_set FLAG_DECLINED_BIKE, MauvilleCity_BikeShop_EventScript_SkipGreeting
	msgbox MauvilleCity_BikeShop_Text_RydelGreeting, MSGBOX_DEFAULT
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MauvilleCity_BikeShop_EventScript_YesFar
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_SkipGreeting:: @ 820EBF7
// >

< //
MauvilleCity_BikeShop_EventScript_YesFar:: @ 820EC4A
	msgbox MauvilleCity_BikeShop_Text_TakeABike, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_BIKE
	giveitem ITEM_ACRO_BIKE
	//goto MauvilleCity_BikeShop_EventScript_ChooseBike
	msgbox MauvilleCity_BikeShop_Text_TwoBikesInOne, MSGBOX_DEFAULT
	special SwapRegisteredBike
	goto MauvilleCity_BikeShop_EventScript_RememberToAdvertiseYourBike
	end

MauvilleCity_BikeShop_EventScript_RememberToAdvertiseYourBike::
	msgbox MauvilleCity_BikeShop_Text_RememberToAdvertise, MSGBOX_DEFAULT
	release
	end
	
MauvilleCity_BikeShop_EventScript_GetMachBike:: @ 820EC53
// >

< //
MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes: @ 820F1BD
	.string "RYDEL: If you get the urge to switch\n"
	.string "BIKES, just come see me!$"

MauvilleCity_BikeShop_Text_TakeABike: @ 820EF32
	.string "RYDEL: Hm, hm… … … … …\p"
	.string "You're saying that you came all this\n"
	.string "way from LITTLEROOT?\p"
	.string "My goodness!\n"
	.string "That's ridiculously far!\p"
	.string "If you had one of my BIKES, you could\n"
	.string "go anywhere easily while feeling the\l"
	.string "gentle caress of the wind!\p"
	.string "I'll tell you what!\n"
	.string "I'll give you a BIKE!\p"
	.string "Here, take this!$"
	
MauvilleCity_BikeShop_Text_TwoBikesInOne:
	.string "RYDEL: My BIKES have cutting-edge\n"
	.string "technology imported from SINNOH!\p"
	.string "There are two gears in the BIKE!\n"
	.string "To switch gears, simply press\l"
	.string "the R button.$"
	
MauvilleCity_BikeShop_Text_RememberToAdvertise: @ 820F1BD
	.string "Remember to advertise your BIKE\n"
	.string "so that people learn about the best\l"
	.string "BIKE shop in HOENN.\p"
	.string "Have a safe ride!$"
	
MauvilleCity_BikeShop_Text_WantToSwitchBikes: @ 820F1FB
// >

< //
MauvilleCity_BikeShop_Text_MachHandbookWhichPage: @ 820F445
	.string "It's a handbook on the MACH GEAR.\p"
	.string "Which page do you want to read?$"

MauvilleCity_BikeShop_Text_HowToRideMachBike: @ 820F487
	.string "A BIKE moves in the direction that\n"
	.string "the + Control Pad is pressed.\p"
	.string "It will speed up once it gets rolling.\p"
	.string "To stop, release the + Control Pad.\n"
	.string "The BIKE will slow to a stop.\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_HowToTurnMachBike: @ 820F550
	.string "MACH GEAR is speedy, but it can't\n"
	.string "stop very quickly.\p"
	.string "It gets a little tricky to get around\n"
	.string "a corner.\p"
	.string "Release the + Control Pad a little\n"
	.string "before the corner and slow down.\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_SandySlopes: @ 820F61A
	.string "There are small sandy slopes\n"
	.string "throughout the HOENN region.\p"
	.string "The loose, crumbly sand makes it\n"
	.string "impossible to climb normally.\p"
	.string "But if you use MACH GEAR, you can\n"
	.string "zip up a sandy slope.\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_AcroHandbookWhichPage: @ 820F6ED
	.string "It's a handbook on the ACRO GEAR.\p"
	.string "Which page do you want to read?$"

MauvilleCity_BikeShop_Text_Wheelies: @ 820F72F
	.string "Press the B Button while riding,\n"
	.string "and the front wheel lifts up.\p"
	.string "You can zip around with the front\n"
	.string "wheel up using the + Control Pad.\p"
	.string "This technique is called a wheelie.\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_BunnyHops: @ 820F7F5
	.string "Keeping the B Button pressed,\n"
	.string "your BIKE can hop on the spot.\p"
	.string "This technique is called a bunny hop.\p"
	.string "You can ride while hopping, too.\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_Jumps: @ 820F898
	.string "Press the B Button and the + Control\n"
	.string "Pad at the same time to jump.\p"
	.string "Press the + Control Pad to the side\n"
	.string "to jump sideways.\p"
	.string "Press it backwards to make the BIKE\n"
	.string "change directions while jumping.\p"
	.string "Want to read a different page?$"
// > END