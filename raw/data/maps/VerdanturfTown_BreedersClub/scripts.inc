< //
VerdanturfTown_BreedersClub_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_BreedersClub_OnTransition
	.byte 0

VerdanturfTown_BreedersClub_OldLady::
	msgbox VerdanturfTown_BreedersClub_OldLady_DoYouLikeBreeding, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_BreedersClub_OldLady_DoYouLikeBreeding:
	.string "Do you like breeding, lass?$"

VerdanturfTown_BreedersClub_OnTransition:
// >