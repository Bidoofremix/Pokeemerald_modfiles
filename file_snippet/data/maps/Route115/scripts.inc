< //
Route115_OnTransition: @ 81F2947
	compare VAR_SHOULD_END_ABNORMAL_WEATHER, 1
	call_if_eq AbnormalWeather_EventScript_HideMapNamePopup
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_WEST
	call_if_eq AbnormalWeather_StartGroudonWeather
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_EAST
	call_if_eq AbnormalWeather_StartGroudonWeather
	compare VAR_ROUTE115_STATE, 1
	call_if_eq Route115_EventScript_ShowSkitty
	call_if_ne Route115_EventScript_HideSkitty
	setflag FLAG_HIDE_ROUTE115_OLDLADY
	end

.set LOCALID_OLDLADY, 25	
	
Route115_EventScript_HideSkitty::
	setflag FLAG_HIDE_ROUTE115_SKITTY
	return
	
Route115_EventScript_ShowSkitty::
	clearflag FLAG_HIDE_ROUTE115_SKITTY
	return
	
Route115_EventScript_Skitty::
	lock
	faceplayer
	playmoncry SPECIES_SKITTY, 0
	msgbox Route115_Text_Skitty, MSGBOX_DEFAULT
	closemessage
	delay 20
	addobject LOCALID_OLDLADY
	applymovement LOCALID_OLDLADY, Common_Movement_WalkUp2
	waitmovement 0
	delay 20
	playse SE_PIN
	applymovement LOCALID_OLDLADY, Common_Movement_ExclamationMark
	waitmovement 0
	delay 20
	applymovement LOCALID_OLDLADY, Route115_Movement_Up3
	waitmovement 0
	bufferspeciesname 0, SPECIES_SKITTY
	msgbox Route115_Text_MyGoodnesIRememberYou, MSGBOX_DEFAULT
	applymovement LOCALID_OLDLADY, Common_Movement_FaceLeft
	msgbox Route115_Text_ThankYouForFinding, MSGBOX_DEFAULT
	setvar VAR_ROUTE115_STATE, 2
	warp MAP_RUSTBORO_CITY_FLAT2_1F, 255, 8, 3
	release
	end
	
Route115_Movement_Up3::
	walk_up
	walk_up
	walk_up
	step_end
	
Route115_Text_Skitty::
	.string "Nyan?$"

Route115_Text_MyGoodnesIRememberYou:
	.string "My goodness, now I remember!\p"
	.string "You were playing with my {STR_VAR_1}\n"
	.string "the other day!$"
	
Route115_Text_ThankYouForFinding:
	.string "Now I know why my {STR_VAR_1} is\n"
	.string "so sad.\p"
	.string "I didn't realize it was missing\n"
	.string "its friend.\p"
	.string "Let's bring {STR_VAR_1}'s friend\n"
	.string "back to it and see if it helps.$"

Route115_OnFrame: @ 81F2969
// >