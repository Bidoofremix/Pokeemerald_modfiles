< // START

// Rhyolite Canyon states
// 0: have not engaged Tabitha
// 1: have engaged Tabitha, not defeated yet
// 2: Tabitha defeated

.set LOCALID_GRUNT1, 1
.set LOCALID_GRUNT2, 2
.set LOCALID_GRUNT3, 3
.set LOCALID_GRUNT4, 4
.set LOCALID_TABITHA, 5

NavelRock_Fork_MapScripts:: @ 826910E
	map_script MAP_SCRIPT_ON_RESUME, RhyoliteCanyon_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, RhyoliteCanyon_OnTransition
	.byte 0

RhyoliteCanyon_OnResume: @ 81F215E
	setstepcallback STEP_CB_ASH
	end
	
RhyoliteCanyon_OnTransition::
	compare VAR_RHYOLITE_CANYON_STATE, 1
	call_if_eq RhyoliteCanyon_EventScript_TabithaFaceDown
	end

RhyoliteCanyon_EventScript_TabithaFaceDown::
	setobjectmovementtype LOCALID_TABITHA, MOVEMENT_TYPE_FACE_DOWN
	return
	
RhyoliteCanyon_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_RHYOLITE_CANYON_1, RhyoliteCanyon_Text_Grunt1Intro, RhyoliteCanyon_Text_Grunt1Defeated
	msgbox RhyoliteCanyon_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end
	
RhyoliteCanyon_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_RHYOLITE_CANYON_2, RhyoliteCanyon_Text_Grunt2Intro, RhyoliteCanyon_Text_Grunt2Defeated
	msgbox RhyoliteCanyon_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end
	
RhyoliteCanyon_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_RHYOLITE_CANYON_3, RhyoliteCanyon_Text_Grunt3Intro, RhyoliteCanyon_Text_Grunt3Defeated
	msgbox RhyoliteCanyon_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end
	
RhyoliteCanyon_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_RHYOLITE_CANYON_4, RhyoliteCanyon_Text_Grunt4Intro, RhyoliteCanyon_Text_Grunt4Defeated
	msgbox RhyoliteCanyon_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

RhyoliteCanyon_EventScript_Tabitha::
	lock
	setvar VAR_RHYOLITE_CANYON_STATE, 1
	applymovement LOCALID_TABITHA, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	delay 20
	msgbox RhyoliteCanyon_Text_TabithaCall_TheMeteoriteIsntHere, MSGBOX_DEFAULT
	waitmessage
	playse SE_POKENAV_HANG_UP
	delay 20
	closemessage
	delay 60
	applymovement LOCALID_TABITHA, Common_Movement_FaceDown
	applymovement LOCALID_TABITHA, Common_Movement_WalkInPlaceDown
	playbgm MUS_ENCOUNTER_MAGMA, 0
	delay 20
	msgbox RhyoliteCanyon_Text_YouThinkYouCanMarchInHere, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_TABITHA, RhyoliteCanyon_Movement_WalkDown3
	waitmovement 0
	trainerbattle_no_intro TRAINER_TABITHA_RHYOLITE_CANYON, RhyoliteCanyon_Text_TabithaLose
	goto RhyoliteCanyon_EventScript_WonTabitha
	end
	
BrineBeach_EventScript_TabithaRematch::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, 0
	faceplayer
	msgbox RhyoliteCanyon_Text_YouWantToGetThroughHere, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_TABITHA, RhyoliteCanyon_Movement_WalkDown2
	waitmovement 0
	trainerbattle_no_intro TRAINER_TABITHA_RHYOLITE_CANYON, RhyoliteCanyon_Text_TabithaLose
	goto RhyoliteCanyon_EventScript_WonTabitha
	end

RhyoliteCanyon_EventScript_WonTabitha::
	delay 40
	msgbox RhyoliteCanyon_Text_ItSeemsIUnderestimatedYou, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_RHYOLITE_CANYON_TEAM_MAGMA
	
	// screen to black and back
	fadescreen 1
	removeobject LOCALID_TABITHA
	removeobject LOCALID_GRUNT1
	removeobject LOCALID_GRUNT2
	removeobject LOCALID_GRUNT3
	removeobject LOCALID_GRUNT4
	setvar VAR_RHYOLITE_CANYON_STATE, 2
	delay 20
	fadescreen 0
	delay 40

	release
	end
	
RhyoliteCanyon_Text_TabithaCall_TheMeteoriteIsntHere:
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "… Yes, we have searched through\n"
	.string "the entire canyon. It isn't here.\p"
	.string "… METEOR FALLS? Roger.\n"
	.string "We will proceed immediately. Hehehe!\p"
	.string "TABITHA out.\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"
	
RhyoliteCanyon_Text_YouThinkYouCanMarchInHere:
	.string "Hehehe! So, you think you can just\n"
	.string "march in here and interrupt our\l"
	.string "mission?\p"
	.string "After all the trouble we went to\n"
	.string "get rid of eyewitnesses?\p"
	.string "Hehehe! You need to learn a\n"
	.string "lesson here.\p"
	.string "This'll teach you not to stick your\n"
	.string "nose into other people's business!$"
	
RhyoliteCanyon_Text_TabithaLose:
	.string "Hehe… He?$"

RhyoliteCanyon_Text_ItSeemsIUnderestimatedYou:
	.string "Hehehe! It seems that I\n"
	.string "underestimated you.\p"
	.string "That won't happen again. The next\n"
	.string "time we meet, I'm going to wipe\l"
	.string "that smile off your face! Hehehe!$"

RhyoliteCanyon_Text_YouWantToGetThroughHere:
	.string "Hehehe! You want to get through\n"
	.string "this canyon?\p"
	.string "Hehehe! Too bad! You'll have to go\n"
	.string "through me first!$"
	
RhyoliteCanyon_Movement_WalkDown3:
	walk_down
	walk_down
	walk_down
	step_end
	
RhyoliteCanyon_Movement_WalkDown2:
	walk_down
	walk_down
	step_end
	
RhyoliteCanyon_Text_Grunt1Intro:
	.string "What? Where'd you come from?$"
	
RhyoliteCanyon_Text_Grunt1Defeated:
	.string "Too much!$"
	
RhyoliteCanyon_Text_Grunt1PostBattle:
	.string "We have an important mission, and\n"
	.string "you're ruining it. Scram!$"
	
RhyoliteCanyon_Text_Grunt2Intro:
	.string "Ha! A kid! I'm gonna make you\n"
	.string "bite dust!$"
	
RhyoliteCanyon_Text_Grunt2Defeated:
	.string "Total and complete destruction!$"
	
RhyoliteCanyon_Text_Grunt2PostBattle:
	.string "The damn ash gets everywhere.\n"
	.string "This is going to be some\l"
	.string "tough landry.$"

RhyoliteCanyon_Text_Grunt3Intro:
	.string "We were promised that we could\n"
	.string "complete this mission undisturbed.\l"
	.string "So, get lost!$"
	
RhyoliteCanyon_Text_Grunt3Defeated:
	.string "You're supposed to be a kid?$"
	
RhyoliteCanyon_Text_Grunt3PostBattle:
	.string "We're apparently looking for some\n"
	.string "dumb piece of rock. Like there's not\l"
	.string "enough of those around…$"
	
RhyoliteCanyon_Text_Grunt4Intro:
	.string "You!\p"
	.string "First you humiliated me in PETALBURG\n"
	.string "WOODS, then RUSTURF TUNNEL, and now\l"
	.string "you're here?\p"
	.string "Is there no limit to your meddling?\n"
	.string "I'm gonna make you pay!$"
	
RhyoliteCanyon_Text_Grunt4Defeated:
	.string "Completely wiped out, again…$"
	
RhyoliteCanyon_Text_Grunt4PostBattle:
	.string "You know what?\p"
	.string	"Just stop bothering me. Do whatever\n"
	.string "you want, I don't care.\p"
	.string "The ADMIN will destroy you anyway.$"
	
RhyoliteCanyon_EventScript_HyperPotion::
	finditem ITEM_HYPER_POTION
	end	
	
// > END