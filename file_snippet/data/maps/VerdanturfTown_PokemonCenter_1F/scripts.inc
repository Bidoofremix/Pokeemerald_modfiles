< //
VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent: @ 820280B
	.string "The reason why anyone would visit\n"
	.string "VERDANTURF…\p"
	.string "It's the BREEDER'S CLUB. It goes\n"
	.string "wihtout saying.\p"
	.string "Or is there somebody here that you\n"
	.string "came to see?$"

VerdanturfTown_PokemonCenter_1F_EventScript_SmallBoy::
	lock
	faceplayer
	goto_if_defeated TRAINER_MASTER_BUG, VerdanturfTown_PokemonCenter_1F_EventScript_DefeatedBugMasterTrainer
	msgbox VerdanturfTown_PokemonCenter_1F_TheresAReallyStrongTrainer, MSGBOX_DEFAULT
	release
	end
	
VerdanturfTown_PokemonCenter_1F_EventScript_DefeatedBugMasterTrainer::
	msgbox VerdanturfTown_PokemonCenter_1F_WhatYouDefeatedTheStrongTrainer, MSGBOX_DEFAULT
	release
	end
	
VerdanturfTown_PokemonCenter_1F_TheresAReallyStrongTrainer:
	.string "There's a really strong trainer\n"
	.string "outside!\p"
	.string "I bet you can't beat him!$"
	
VerdanturfTown_PokemonCenter_1F_WhatYouDefeatedTheStrongTrainer:
	.string "You defeated the strong trainer\n"
	.string "outside?\p"
	.string "You're the best!$"
	
// > END