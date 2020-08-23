< // START
.set LOCALID_GYARADOS, 1
.set LOCALID_SHELLY, 2
.set LOCALID_BRAWLY, 3
.set LOCALID_GRUNT1, 4
.set LOCALID_GRUNT2, 5
.set LOCALID_GRUNT3, 6

// Brine Beach states:
// 0: Shelly not defeated, Gyarados not defeated
// 1: Shelly confronted and lost, Gyarados not defeated
// 2: Shelly defeated, Gyarados not defeated
// 3: Shelly defeated, Gyarados defeated

BrineBeach_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BrineBeach_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BrineBeach_OnTransition
	.byte 0
	
BrineBeach_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, SilentForest_Mapscript_CtrlObj
	end

SilentForest_Mapscript_CtrlObj::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject LOCALID_GYARADOS
	return
	
BrineBeach_OnTransition::
	call BrineBeach_EventScript_ControlWeather
	call_if_unset FLAG_DEFEATED_GYARADOS, BrineBeach_ShowGyarados
	compare VAR_BRINE_BEACH_STATE, 1
	call_if_eq BrineBeach_EventScript_SetShellyCoordinates
	end

BrineBeach_EventScript_SetShellyCoordinates::
	setobjectxyperm LOCALID_SHELLY, 49, 12
	turnobject LOCALID_SHELLY, DIR_EAST
	end
	
BrineBeach_tmp::
	// DewfordTown_PokemonCenter_1F_EventScript_Man
	warp MAP_DEWFORD_TOWN, 255, 2, 12
	end
	
BrineBeach_ShowGyarados::
	clearflag FLAG_HIDE_GYARADOS
	end
	
BrineBeach_EventScript_ControlWeather::
	goto_if_unset FLAG_DEFEATED_GYARADOS BrineBeach_EventScript_HeavyRain
	return
	
BrineBeach_EventScript_HeavyRain::
	setweather WEATHER_RAIN_THUNDERSTORM
	return
	
BrineBeach_EventScript_Gyarados::
	lockall
	
	// walk to place
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_1, 11
	call_if_eq BrineBeach_EventScript_Movement_y11
	compare VAR_TEMP_1, 12
	call_if_eq BrineBeach_EventScript_Movement_y12
	compare VAR_TEMP_1, 13
	call_if_eq BrineBeach_EventScript_Movement_y13
	
	delay 40	
	applymovement LOCALID_BRAWLY, BrineBeach_Movement_Brawly3
	
	// gyarados arrives
	applymovement LOCALID_GYARADOS, BrineBeach_Movement_Gyarados
	waitmovement 0
	delay 40
	
	// sounds, shake
	playse SE_W070
	special DoSealedChamberShakingEffect2
	waitstate
	delay 20
	playse SE_W070
	special DoSealedChamberShakingEffect2
	waitstate
	special DoSealedChamberShakingEffect2
	waitstate
	delay 30
	playse SE_W291
	waitse
	
	// set battle
	playmoncry SPECIES_GYARADOS, 0
	msgbox BrineBeach_Text_Gyarados, MSGBOX_DEFAULT
	closemessage
	delay 40
	setwildbattle SPECIES_GYARADOS, 25, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	
	//dowildbattle
	special BattleSetup_StartLegendaryBattle
	waitstate
	delay 40
	
	// check outcome
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq BrineBeach_EventScript_DefeatedGyarados
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq BrineBeach_EventScript_DefeatedGyarados
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq BrineBeach_EventScript_DefeatedGyarados
	releaseall
	end
	
BrineBeach_EventScript_DefeatedGyarados::

	// remove gyarados sprite
	setvar VAR_BRINE_BEACH_STATE, 3
	fadescreenswapbuffers 1
	//fadescreen 1
	removeobject LOCALID_GYARADOS
	turnobject LOCALID_BRAWLY, 3
	//fadescreen 0
	fadescreenswapbuffers 0
	
	// stop rain
	setweather WEATHER_SUNNY
	doweather

	// brawly to player
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, BrineBeach_Movement_PlayerToBrawly
	waitmovement 0
	delay 20
	msgbox BrineBeach_Text_Brawly_ThatWasQuiteAShow, MSGBOX_DEFAULT
	closemessage
	
	// remove brawly
	setflag FLAG_DEFEATED_GYARADOS
	fadescreenswapbuffers 1
	removeobject LOCALID_BRAWLY
	fadescreenswapbuffers 0
	
	releaseall
	end

BrineBeach_EventScript_Shelly::
	lockall
	playbgm MUS_AQA_0, 0
	
	// shelly to brawly
	msgbox BrineBeach_Text_Shelly_ThatllShowYouNotToMeddle, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_SHELLY, BrineBeach_Movement_Shelly1
	applymovement LOCALID_BRAWLY, BrineBeach_Movement_Brawly1
	waitmovement 0
	delay 20
	
	// shelly to player
	msgbox BrineBeach_Text_Shelly_YourReputationPrecedesYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SHELLY, BrineBeach_Movement_Shelly2
	waitmovement 0
	setvar VAR_BRINE_BEACH_STATE, 1
	
	// battle
	trainerbattle_no_intro TRAINER_SHELLY_BRINE_BEACH, BrineBeach_Text_Shelly_Lose
	
	goto BrineBeach_EventScript_WonShelly
	end

BrineBeach_EventScript_ShellyRematch::
	lockall
	playbmg MUS_AQA_0, 0
	faceplayer
	msgbox BrineBeach_Text_Shelly_YouWantToGetToThatGyarados, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SHELLY_BRINE_BEACH, BrineBeach_Text_Shelly_Lose
	goto BrineBeach_EventScript_WonShelly
	end
	
BrineBeach_EventScript_WonShelly::
	// shelly departs
	delay 40
	applymovement LOCALID_SHELLY, BrineBeach_Movement_Shelly3
	waitmovement 0
	delay 20
	msgbox BrineBeach_Text_Shelly_YoureNotWorthTheTrouble, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_BRINE_BEACH_TEAM_AQUA
	
	// screen to black and back
	fadescreen 1
	removeobject LOCALID_SHELLY
	removeobject LOCALID_GRUNT1
	removeobject LOCALID_GRUNT2
	removeobject LOCALID_GRUNT3
	setvar VAR_BRINE_BEACH_STATE, 2
	delay 20
	fadescreen 0
	delay 40
	
	// brawly to player
	applymovement LOCALID_BRAWLY, BrineBeach_Movement_Brawly1
	waitmovement 0
	msgbox BrineBeach_Text_Brawly_ThatWasImpressive, MSGBOX_DEFAULT
	closemessage
	
	// gyarados shouts
	playmoncry SPECIES_GYARADOS, 2
	delay 20
	applymovement LOCALID_BRAWLY, BrineBeach_Movement_Brawly2
	waitmoncry
	waitmovement 0
	
	// brawly to player
	msgbox BrineBeach_Text_Brawly_GyaradosIsStillMad, MSGBOX_DEFAULT
	closemessage
	
	// gyarados shouts again, shaking
	playse SE_W070
	special DoSealedChamberShakingEffect2
	waitstate
	delay 20
	playmoncry SPECIES_GYARADOS, 2
	waitmoncry
	delay 20
	
	// brawly to player
	msgbox BrineBeach_Text_Brawly_CouldYouTameTheGyarados, MSGBOX_DEFAULT
	
	releaseall
	end
	
BrineBeach_EventScript_Brawly::
	lock
	faceplayer
	msgbox BrineBeach_Text_Brawly_CouldYouTameTheGyarados, MSGBOX_DEFAULT
	release
	end

BrineBeach_EventScript_Movement_y11::
	applymovement OBJ_EVENT_ID_PLAYER, BrineBeach_Movement_y11
	waitmovement 0
	return	
	
BrineBeach_EventScript_Movement_y12::
	applymovement OBJ_EVENT_ID_PLAYER, BrineBeach_Movement_y12
	waitmovement 0
	return	
	
BrineBeach_EventScript_Movement_y13::
	applymovement OBJ_EVENT_ID_PLAYER, BrineBeach_Movement_y13
	waitmovement 0
	return
	
BrineBeach_EventScript_AquaGrunt_1::
	trainerbattle_single TRAINER_GRUNT_BRINE_BEACH_1, BrineBeach_Text_AquaGrunt1_Intro, BrineBeach_Text_AquaGrunt1_Lose
	msgbox BrineBeach_Text_AquaGrunt1, MSGBOX_AUTOCLOSE
	end

BrineBeach_EventScript_AquaGrunt_2::
	trainerbattle_single TRAINER_GRUNT_BRINE_BEACH_2, BrineBeach_Text_AquaGrunt2_Intro, BrineBeach_Text_AquaGrunt2_Lose
	msgbox BrineBeach_Text_AquaGrunt2, MSGBOX_AUTOCLOSE
	end
	
BrineBeach_EventScript_AquaGrunt_3::
	trainerbattle_single TRAINER_GRUNT_BRINE_BEACH_3, BrineBeach_Text_AquaGrunt3_Intro, BrineBeach_Text_AquaGrunt3_Lose
	msgbox BrineBeach_Text_AquaGrunt3, MSGBOX_AUTOCLOSE
	end	
	
BrineBeach_EventScript_PikachuTrainer::
	trainerbattle_single TRAINER_TYCHO, BrineBeach_Text_PikachuTrainerIntro, BrineBeach_Text_PikachuTrainerLose
	msgbox BrineBeach_Text_PikachuTrainer, MSGBOX_AUTOCLOSE
	end

BrineBeach_EventScript_Pikachu::
	lock
	faceplayer
	playmoncry SPECIES_PIKACHU, 0
	msgbox BrineBeach_Text_Pikachu, MSGBOX_AUTOCLOSE
	release
	end

BrineBeach_EventScript_KarateGirl::
	trainerbattle_single TRAINER_CADEN, BrineBeach_Text_KarateGirl_Intro, BrineBeach_Text_KarateGirl_Loss
	msgbox BrineBeach_Text_KarateGirl, MSGBOX_AUTOCLOSE
	end
	
BrineBeach_EventScript_Fisherman::
	trainerbattle_single TRAINER_CHEVIS, BrineBeach_Text_Fisherman_Intro, BrineBeach_Text_Fisherman_Loss
	msgbox BrineBeach_Text_Fisherman, MSGBOX_AUTOCLOSE
	end		
	
BrineBeach_EventScript_SurfersHut::
	msgbox BrineBeach_Text_SurfersHut_Sign, MSGBOX_SIGN
	end
	
BrineBeach_Movement_Brawly1:
	face_right
	step_end
	
BrineBeach_Movement_Brawly2:
	face_left
	delay_16
	delay_16
	delay_16
	delay_16
	face_right
	step_end
	
BrineBeach_Movement_Brawly3:
	face_left
	step_end
	
BrineBeach_Movement_PlayerToBrawly:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end
	
BrineBeach_Movement_Shelly1:
	walk_in_place_right
	delay_16
	walk_slow_right
	walk_slow_right
	delay_16
	delay_8
	step_end
	
BrineBeach_Movement_Shelly2:
	delay_8
	walk_right
	step_end
	
BrineBeach_Movement_Shelly3:
	lock_facing_direction
	walk_slow_left
	unlock_facing_direction	
	delay_16
	delay_16
	step_end
	
BrineBeach_Movement_y11:
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_in_place_left
	step_end
	
BrineBeach_Movement_y12:
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_in_place_left
	step_end
	
BrineBeach_Movement_y13:
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_in_place_left
	step_end

BrineBeach_Movement_Gyarados:
	walk_slow_right
	walk_right
	walk_fast_right
	walk_fast_right
	walk_fastest_right
	step_end

BrineBeach_Text_Gyarados:
	.string "Gyarados: Gyashaa!$"
	
BrineBeach_Text_Brawly_ThatWasImpressive:
	.string "That was impressive! What's your name\n"
	.string "again?\p"
	.string "{PLAYER}? Thanks for taking care of\n"
	.string "TEAM {AQUA}!\l"
	.string "It was a close call.$"

BrineBeach_Text_Brawly_GyaradosIsStillMad:
	.string "That Gyarados is still super mad,\n"
	.string "though.\p"
	.string "It needs to be calmed down\n"
	.string "before it busts the whole island.\p"
	.string "My POKéMON are totally knocked out…$"
	
BrineBeach_Text_Brawly_CouldYouTameTheGyarados:
	.string "{PLAYER}, could you tame the Gyarados?\n"
	.string "The safety of the people of DEWFORD\l"
	.string "depends on you!$"
	
BrineBeach_Text_Brawly_ThatWasQuiteAShow:
	.string "Wow! That was quite a show!\p"
	.string "Thank you for saving DEWFORD TOWN!\n"
	.string "I have a feeling I'll see you later at\l"
	.string "the GYM, right?\p"
	.string "Well, I gotta go to prepare for an epic\n"
	.string "battle! I'm looking forward to it!$"
	
BrineBeach_Text_Shelly_ThatllShowYouNotToMeddle:
	.string "SHELLY: There!\p"
	.string "That'll show you not to meddle with\n"
	.string "TEAM {AQUA}'s business.\l"
	.string "Now get out of my way.$"
	
BrineBeach_Text_Shelly_YourReputationPrecedesYou:
	.string "Your name is {PLAYER}, right?\p"
	.string "Your reputation precedes you.\p"
	.string "I heard that you thwarted TEAM \n"
	.string "{MAGMA}'s plans in PETALBURG WOODS.\p"
	.string "Unlike those spineless loons, I\n"
	.string "won't have you run wild and scare my\l"
	.string "subordinates.\p"
	.string "You will make up for it!$"

BrineBeach_Text_Shelly_YouWantToGetToThatGyarados:
	.string "What?\p"
	.string "You want to get to that Gyarados?\n"
	.string "I'm going to keelhaul you!$"
	
BrineBeach_Text_Shelly_Lose:	
	.string "You're not an ordinary kid, are you?$"
	
BrineBeach_Text_Shelly_YoureNotWorthTheTrouble:
	.string "You know what?\p"
	.string "You're not worth the trouble.\n"
	.string "We can cause mayhem without that big\l"
	.string	"stupid serpent anyway.\p"
	.string "Remember that the next time I see you,\n"
	.string "I'm not going to be this nice!$"
	
BrineBeach_Text_AquaGrunt1_Intro:
	.string "You tryna interfere with us?\n"
	.string "Get lost, kid!$"

BrineBeach_Text_AquaGrunt1_Lose:
	.string "Ow. That's harsh, man!$"
		
BrineBeach_Text_AquaGrunt1:
	.string "Our ADMIN will take care of you.\n"
	.string "Don't you dare doubt it!$"

BrineBeach_Text_AquaGrunt2_Intro:
	.string "Do you have any idea how long we've\n"
	.string "stood in the rain? I'm soaked!$"

BrineBeach_Text_AquaGrunt2_Lose:
	.string "What the…?$"
		
BrineBeach_Text_AquaGrunt2:
	.string "I'd sell my soul for a pair of\n"
	.string "dry socks…$"

BrineBeach_Text_AquaGrunt3_Intro:
	.string "I'm one good victory away from applying\n"
	.string "for an ADMIN status.\p"
	.string "Now do as I say and lose!$"

BrineBeach_Text_AquaGrunt3_Lose:
	.string "This is not possible! You cheated!$"
		
BrineBeach_Text_AquaGrunt3:
	.string "I refuse to acknowledge your victory.$"
	
BrineBeach_Text_PikachuTrainerIntro:
	.string "I have a really cool Pikachu!\n"
	.string "Wanna see it Surf?$"
	
BrineBeach_Text_PikachuTrainerLose:
	.string "That was rad!$"
	
BrineBeach_Text_PikachuTrainer:
	.string "There's a dude around here that can\n"
	.string "teach Surf to your Pikachu.$"

BrineBeach_Text_Pikachu:
	.string "Pikachu: Chu-pikaa!$"

BrineBeach_Text_KarateGirl_Intro:
	.string "Training at the sea heightens the\n"
	.string "senses of the body and soul!$"
	
BrineBeach_Text_KarateGirl_Loss:
	.string "Your skills are far beyond mine!$"
	
BrineBeach_Text_KarateGirl:
	.string "Respect your POKéMON and they will\n"
	.string "respect you.$"
	
BrineBeach_Text_Fisherman_Intro:
	.string "Shh! This is my secret fishing place!$"

BrineBeach_Text_Fisherman_Loss:
	.string "You tangled my lines…$"
	
BrineBeach_Text_Fisherman:
	.string "One day I'm going to haul in the\n"
	.string "mightiest Gyarados there is.$"

BrineBeach_Text_SurfersHut_Sign:
	.string "SURFER'S HUT$"

// > END