< // START
SurfersHut_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SurfersHut_OnTransition
	.byte 0

SurfersHut_EventScript_Surfer::
	lock
	faceplayer
	call_if_unset FLAG_INTRODUCED_SURFER_TUTOR, SurfersHut_EventScript_IntroduceSurfer
	call_if_set FLAG_INTRODUCED_SURFER_TUTOR, SurfersHut_EventScript_ICanTeachSurf
	switch VAR_RESULT
	case YES, RustboroCity_University_EventScript_PostDoc_ChooseMonAndMoveToTeach
	case NO, RustboroCity_University_EventScript_PostDoc_ComeAgain
	release
	end
	
SurfersHut_EventScript_IntroduceSurfer::	
	msgbox SurfersHut_Text_HowzitBrah, MSGBOX_YESNO
	end
	
SurfersHut_EventScript_TeachSurf::
	setvar VAR_0x800B, MODE_MOVE_TUTOR_SURFER
	setvar VAR_0x8005, TUTOR_MOVE_SURF
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq SurfersHut_EventScript_LearnedSurf
	goto MoveTutor_EventScript_SwaggerTaught
	end
	
SurfersHut_EventScript_Cancel::
	msgbox SurfersHut_Text_No, MSGBOX_DEFAULT
	release
	end
	
SurfersHut_EventScript_LearnedSurf::
	msgbox SurfersHut_Text_Akaw, MSGBOX_DEFAULT
	release
	end
	
SurfersHut_Text_HowzitBrah:
	.string "Howzit, brah!\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "You look like you haven't been doing\n"
	.string "a lot of surfing.\p"
	.string "You're a total kook, but you seem\n"
	.string "quite a tough POKéMON TRAINER.\p"
	.string "You know what?\n"
	.string "If you have a Pichu, Pikachu or\l"
	.string "Raichu, I can teach them Surf.\l"
	.string "Seeing them on waves gets me amped!p"
	.string "So, do you want that?$"
	
SurfersHut_Text_ICanTeachSurf:
	.string "I can teach Surf to your Pichu,\n"
	.string "Pikachu or Raichu.\p"
	.string "Do you want that?$"

SurfersHut_Text_Akaw::
	.string "Akaw!\p"
	.string "Now you can go hunt some epic waves.\n"
	.string "Just remember not to go full aggro\l"
	.string "with your awesome POKéMON!$"
	
SurfersHut_Text_No::
	.string "Aw, clucked it did you?\p"
	.string "Well, if you change your mind, come\n"
	.string "visit me again.$"
	
SurfersHut_EventScript_Pikachu1::
	lock
	faceplayer
	playmoncry SPECIES_PIKACHU, 0
	msgbox SurfersHut_Text_Pikachu1, MSGBOX_AUTOCLOSE
	release
	end
	
SurfersHut_EventScript_Pikachu2::
	lock
	faceplayer
	playmoncry SPECIES_PIKACHU, 0
	msgbox SurfersHut_Text_Pikachu2, MSGBOX_AUTOCLOSE
	release
	end	
	
SurfersHut_Text_Pikachu1:
	.string "PIKACHU: Pipipi?"
	
SurfersHut_Text_Pikachu2:
	.string "PIKACHU: Pikaa-chu!$"
	
SurfersHut_OnTransition:
	end
// > END