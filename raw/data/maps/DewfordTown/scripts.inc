< //
.equ LOCALID_BRINEY_R104, 8

.set LOCALID_COOLTRAINER, 6

DewfordTown_MapScripts:: @ 81E9507
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_OnTransition
	.byte 0
// >

< //
DewfordTown_OnTransition: @ 81E950D
	setflag FLAG_VISITED_DEWFORD_TOWN
	call BrineBeach_EventScript_ControlWeather
	call_if_unset FLAG_DEFEATED_GYARADOS, DewfordTown_EventScript_SetCooltrainer
	end

DewfordTown_EventScript_SetCooltrainer::
	setobjectxyperm LOCALID_COOLTRAINER, 8, 18
	setobjectmovementtype LOCALID_COOLTRAINER, MOVEMENT_TYPE_FACE_DOWN
	
DewfordTown_EventScript_CoolTrainer::
	lock
	faceplayer
	goto_if_unset FLAG_DEFEATED_GYARADOS, DewfordTown_EventScript_NotDefeatedGyarados
	msgbox DewfordTown_Text_IHeardYouBattledGyarados, MSGBOX_DEFAULT
	release
	end
	
DewfordTown_EventScript_NotDefeatedGyarados::
	msgbox DewfordTown_Text_BrineyIsNotHere, MSGBOX_DEFAULT
	release
	end
	
DewfordTown_Text_BrineyIsNotHere::
	.string "If you're here for a GYM battle,\n"
	.string "you're out of luck. The LEADER\l"
	.string "isn't here.\p"
	.string "There's a commotion down at\n"
	.string "BRINE BEACH.\p"
	.string "It's related to this awful\n"
	.string "storm, apparently.$"
	
DewfordTown_Text_IHeardYouBattledGyarados::
	.string "I heard that you battled the enraged\n"
	.string "Gyarados at BRINE BEACH!\p"
	.string "Thanks to your brave actions,\n"
	.string "DEWFORD TOWN was saved!\l"
	.string "You're a hero!$"
	
DewfordTown_EventScript_Briney:: @ 81E9511
// >