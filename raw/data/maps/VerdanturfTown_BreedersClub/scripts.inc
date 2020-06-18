< //
VerdanturfTown_BreedersClub_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_BreedersClub_OnTransition
	.byte 0

VerdanturfTown_BreedersClub_OldLady::
	lock
	faceplayer
	msgbox VerdanturfTown_BreedersClub_OldLady_DoYouLikeBreeding, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq VerdanturfTown_BreedersClub_OldLady_YesILikeBreeding
	compare VAR_RESULT, NO
	goto_if_eq VerdanturfTown_BreedersClub_OldLady_NoIDontLikeBreeding
	release
	end

VerdanturfTown_BreedersClub_OldLady_YesILikeBreeding:
	msgbox VerdanturfTown_BreedersClub_OldLady_Good, MSGBOX_DEFAULT
	release
	end
	
VerdanturfTown_BreedersClub_OldLady_NoIDontLikeBreeding:
	msgbox VerdanturfTown_BreedersClub_OldLady_Disappointing, MSGBOX_DEFAULT
	release
	end
	
VerdanturfTown_BreedersClub_OldLady_DoYouLikeBreeding:
	.string "Do you like breeding, lass?$"

VerdanturfTown_BreedersClub_OldLady_Good:
	.string "Good, good! I had you figured\n"
	.string "for a talented young TRAINER.$"
	
VerdanturfTown_BreedersClub_OldLady_Disappointing:
	.string "Oh? That's disappointing. What are\n"
	.string "youngsters even good for nowdays…!$"
	
VerdanturfTown_BreedersClub_OnTransition:
// >