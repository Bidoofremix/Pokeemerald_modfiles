< //
Route107_MapScripts:: @ 81EE594
	map_script MAP_SCRIPT_ON_TRANSITION, Route107_OnTransition
	.byte 0

Route107_OnTransition: @ 81E950D
	call BrineBeach_EventScript_ControlWeather
	.byte 0

Route107_EventScript_Darrin:: @ 81EE595
// >