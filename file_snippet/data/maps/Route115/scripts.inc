< //
Route115_OnTransition: @ 81F2947
	compare VAR_SHOULD_END_ABNORMAL_WEATHER, 1
	call_if_eq AbnormalWeather_EventScript_HideMapNamePopup
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_WEST
	call_if_eq AbnormalWeather_StartGroudonWeather
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_EAST
	call_if_eq AbnormalWeather_StartGroudonWeather
	compare VAR_ROUTE115_STATE, 1
	call_if_ne Route115_EventScript_HideSkitty
	end

Route115_EventScript_HideSkitty::
	setflag FLAG_HIDE_ROUTE115_SKITTY
	return

Route115_OnFrame: @ 81F2969
// >