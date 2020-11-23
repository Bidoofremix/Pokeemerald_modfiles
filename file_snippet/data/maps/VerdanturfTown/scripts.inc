< //
VerdanturfTown_Text_MakeBattleTentDebut: @ 81EB7E2
	.string "The POKéMON BREEDER CLUB is in that\n"
	.string "red house over there.\p"
	.string "You should visit it if you are\n"
	.string "interested in raising POKéMON.$"

VerdanturfTown_EventScript_BugTypeTrainer::
	faceplayer

	// check if battle has been complete
	goto_if_defeated TRAINER_MASTER_BUG, VerdanturfTown_EventScript_QuestComplete
	
	// check if quest unlocked
	msgbox VerdanturfTown_Text_IAmBugTypeMasterTrainer
	questmenu QUEST_MENU_CHECK_UNLOCKED SIDE_QUEST_10
	compare VAR_RESULT, TRUE
	goto_if_eq VerdanturfTown_EventScript_AskToBattle
	goto_if_ne VerdanturfTown_EventScript_QuestNotUnlocked
	end
	
VerdanturfTown_EventScript_AskToBattle::
	msgbox VerdanturfTown_Text_YouLookLikeAStrongTrainer, MSGBOX_YESNO
	compare VAR_RESULT, TRUE
	
	// don't battle
	goto_if_ne VerdanturfTown_EventScript_CancelBattle
	
	// check party type
	setvar VAR_0x800A, TYPE_BUG
	call_if_eq Common_EventScript_CheckPartyType
	compare VAR_RESULT, FALSE
	call_if_eq VerdanturfTown_EventScript_NotBugType
	
	// do battle
	trainerbattle_no_intro TRAINER_MASTER_BUG, VerdanturfTown_Text_BugTypeTrainer_Lose

	// defeated
	msgbox VerdanturfTown_Text_ThatWasAwesome, MSGBOX_DEFAULT
	// reward
	giveitem ITEM_TM49
	msgbox VerdanturfTown_Text_LookForOtherMasterTrainers, MSGBOX_DEFAULT	
	release	
	end
	
VerdanturfTown_EventScript_QuestNotUnlocked::
	msgbox VerdanturfTown_Text_YoureNotStrongEnough, MSGBOX_DEFAULT
	release
	end
	
VerdanturfTown_EventScript_NotBugType::
	msgbox VerdanturfTown_Text_NotAllBugType, MSGBOX_DEFAULT
	goto VerdanturfTown_EventScript_CancelBattle
	end
	
VerdanturfTown_EventScript_CancelBattle::
	msgbox VerdanturfTown_Text_IfYouWantToBattle, MSGBOX_DEFAULT
	release
	end
	
Common_EventScript_CheckPartyType::
	special CheckPartyType
	return

VerdanturfTown_EventScript_QuestComplete::
	msgbox VerdanturfTown_Text_YoureEvenBetterThanMe, MSGBOX_DEFAULT
	release
	end
	
VerdanturfTown_Text_YoureEvenBetterThanMe:
	.string "Our battle was epic! You're even\n"
	.string "better than me with BUG POKéMON!$" 
	
VerdanturfTown_Text_ThatWasAwesome:
	.string "That was awesome! You totally and\n"
	.string "completely smashed me!\p"
	.string "As a reward for an exciting\n"
	.string "battle, please take this!$"
	
VerdanturfTown_Text_LookForOtherMasterTrainers:
	.string "Be sure to look for other MASTER\n"
	.string "TRAINERS if you want more\l"
	.string "challenges on your journey!$"
	
VerdanturfTown_Text_YoureNotStrongEnough:
	.string "I can see that you're a\n"
	.string "rookie through and through.\p"
	.string "Toughen up a bit first, then\n"
	.string "I'll consider battling you.$"
	
VerdanturfTown_Text_IAmBugTypeMasterTrainer:
	.string "I am a MASTER TRAINER of\n"
	.string "BUG TYPE POKéMON.\p"
	.string "That means I only battle with\n"
	.string "strong TRAINERS that use\l"
	.string "BUG TYPE POKéMON as well.$"
	
VerdanturfTown_Text_YouLookLikeAStrongTrainer:
	.string "You look like a strong TRAINER.\n"
	.string "Do you accept my challenge to\l"
	.string "a battle with BUG POKéMON only?$"
	
VerdanturfTown_Text_NotAllBugType:
	.string "Hey! Not all of your POKéMON\n"
	.string "are BUG TYPE. No deal!$"
	
VerdanturfTown_Text_IfYouWantToBattle:
	.string "If you want to battle the strongest\n"
	.string "BUG TYPE TRAINER, you know where\l"
	.string "to find me.$"
	
VerdanturfTown_Text_BugTypeTrainer_Lose:
	.string "Woah, you've got some serious\n"
	.string "POKéMON!$"
	
VerdanturfTown_Text_GuyTryingToBustThroughCave: @ 81EB854
// >

< //
VerdanturfTown_Text_BattleTentSign: @ 81EBA1F
	.string "POKéMON BREEDER CLUB$"

VerdanturfTown_Text_RusturfTunnelSign: @ 81EBA59
// >