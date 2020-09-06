< //
Route111_MapScripts:: @ 81F0CA7
	map_script MAP_SCRIPT_ON_LOAD, Route111_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route111_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route111_OnFrame
	.byte 0

Route111_EventScript_MagmaGrunt1::
	lock
	faceplayer
	msgbox Route111_Text_MagmaGrunt1, MSGBOX_DEFAULT
	release
	end
	
Route111_EventScript_MagmaGrunt2::
	lock
	faceplayer
	msgbox Route111_Text_MagmaGrunt2, MSGBOX_DEFAULT
	release
	end
	
Route111_EventScript_MagmaGrunt3::
	lock
	faceplayer
	msgbox Route111_Text_MagmaGrunt3, MSGBOX_DEFAULT
	release
	end
	
Route111_EventScript_MagmaGrunt4::
	lock
	faceplayer
	msgbox Route111_Text_MagmaGrunt4, MSGBOX_DEFAULT
	release
	end
	
	
Route111_Text_MagmaGrunt1::
	.string "Official TEAM MAGMA business here.\n"
	.string "Nothing interesting for you to see.$"
	
Route111_Text_MagmaGrunt2::
	.string "Hey, kiddo! No entry beyond this\n"
	.string "point. Go on, scram!$"
	
Route111_Text_MagmaGrunt3::
	.string "I accidentally ate the BOSS's lunch\"
	.string "sandwhich, and now I'm on road duty…\p"
	.string "Grumble…$"
	
Route111_Text_MagmaGrunt4::
	.string "Surely you must be thinking,\n"
	.string "“Why are there evil teams everywhere\l"
	.string "blocking my passage?”\p"
	.string "That's just your imagination. Now go\n"
	.string "bother someone else!$"
	
Route111_OnLoad: @ 81F0CBC
// >