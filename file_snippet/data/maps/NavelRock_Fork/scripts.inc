< //
NavelRock_Fork_MapScripts:: @ 826910E
	map_script MAP_SCRIPT_ON_RESUME, RhyoliteCanyon_OnResume
	.byte 0

RhyoliteCanyon_OnResume: @ 81F215E
	setstepcallback STEP_CB_ASH
	end
	
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
	.string "You're not a regular kid, are you?$"
	
RhyoliteCanyon_Text_Grunt3PostBattle:
	.string "We're apparently looking for some\n"
	.string "dumb piece of rock. Like there's not\l"
	.string "enough of those around…$"
	
RhyoliteCanyon_Text_Grunt4Intro:
	.string "You!\p"
	.string "First you humiliated me in PETALBURG\n"
	.string "WOODS, then RUSTURF TUNNEL, and\l"
	.string "now here.\p"
	.string "Is there no limit to your meddling?\n"
	.string "I'm gonna make you pay!$"
	
RhyoliteCanyon_Text_Grunt4Defeated:
	.string "Completely wiped out, again…"
	
RhyoliteCanyon_Text_Grunt4PostBattle:
	.string "You know what?\n"
	.string	"Just stop bothering me. Do whatever\l"
	.string "you want, I don't care.\p"
	.string "The ADMIN will destroy you anyway.$"
	
// > END