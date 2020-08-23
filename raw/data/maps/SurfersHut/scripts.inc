< // START
SurfersHut_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SurfersHut_OnTransition
	.byte 0

SurfersHut_EventScript_Surfer::
	lock
	faceplayer
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
	.string "Seeing them surfing gets me amped!p"
	.string "So, do you want that?$"
	
SurfersHut_Text_ICanTeachSurf:
	.string "I can teach Surf to your Pichu,\n"
	.string "Pikachu or Raichu.\p"
	.string "Do you want that?$"
	
SurfersHut_OnTransition:
	end
// > END