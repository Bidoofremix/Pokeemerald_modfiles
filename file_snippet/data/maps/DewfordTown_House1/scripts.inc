< //
DewfordTown_House1_MapScripts:: @ 81FC3CD
	.byte 0

	.align 2
DewfordTown_MarineShop_Pokemart: @ 821FE20
	.2byte ITEM_NET_BALL
	.2byte ITEM_LURE_BALL
	.2byte ITEM_DIVE_BALL
	.2byte ITEM_FRESH_WATER
	.2byte ITEM_MYSTIC_WATER
	.2byte ITEM_SEA_INCENSE
	.2byte ITEM_WAVE_INCENSE
	.2byte ITEM_NONE
	release
	end	
	
DewfordTown_MarineShop_Pokemart_Man:: @ 821FE2C
	lock
	faceplayer
	message DewfordTown_MarineShop_Text_WelcomeToTheMarineShop
	waitmessage
	pokemart DewfordTown_MarineShop_Pokemart
	msgbox DewfordTown_MarineShop_Text_ThankYouPleaseComeAgain, MSGBOX_DEFAULT
	release
	end	
	
DewfordTown_MarineShop_Text_WelcomeToTheMarineShop::
	.string "Welcome to the MARINE SHOP!\n"
	.string "How may I serve you?$"
	
DewfordTown_MarineShop_Text_ThankYouPleaseComeAgain::
	.string "Thank you for visiting us.\n"
	.string "Please come again!$"
	
DewfordTown_House1_EventScript_Man:: @ 81FC3CE
// >

< //
DewfordTown_House1_Text_LifeGoesSlowlyOnIsland: @ 81FC45B
	.string "I left the major port of SLATEPORT\n"
	.string "CITY when I married my husband here.\p"
	.string "He is very fond of the sea, so he\n"
	.string "set up a marine themed shop here.\p"
	.string "Life goes by slowly on this little\n"
	.string "island. But being surrounded by the\l"
	.string "beautiful sea--that's happiness, too.$"

DewfordTown_House1_Text_Zigzagoon: @ 81FC510
// >