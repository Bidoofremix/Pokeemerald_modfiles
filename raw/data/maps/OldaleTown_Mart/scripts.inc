< //
OldaleTown_Mart_EventScript_Clerk:: @ 81FC240
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_ExpandedItems
	pokemart OldaleTown_Mart_Pokemart_Basic, 1
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

OldaleTown_Mart_Pokemart_Basic: @ 81FC260
// >