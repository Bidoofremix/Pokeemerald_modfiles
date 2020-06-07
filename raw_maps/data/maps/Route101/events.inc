Route101_ObjectEvents:
	object_event 1, OBJ_EVENT_GFX_YOUNGSTER, 0, 16, 8, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, Route101_EventScript_Youngster, 0
	object_event 2, OBJ_EVENT_GFX_PROF_BIRCH, 0, 9, 13, 0, MOVEMENT_TYPE_JOG_IN_PLACE_RIGHT, 0, 0, 0, 0, 0x0, FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	object_event 3, OBJ_EVENT_GFX_BIRCHS_BAG, 0, 7, 14, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, Route101_EventScript_BirchsBag, FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	object_event 4, OBJ_EVENT_GFX_ZIGZAGOON_1, 0, 10, 13, 0, MOVEMENT_TYPE_JOG_IN_PLACE_LEFT, 0, 0, 0, 0, 0x0, FLAG_HIDE_ROUTE_101_ZIGZAGOON
	object_event 5, OBJ_EVENT_GFX_PROF_BIRCH, 0, 5, 11, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, ProfBirch_EventScript_RatePokedexOrRegister, FLAG_HIDE_ROUTE_101_BIRCH
	object_event 6, OBJ_EVENT_GFX_BOY_2, 0, 2, 13, 3, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT, 1, 1, 0, 0, Route101_EventScript_Boy, FLAG_HIDE_ROUTE_101_BOY

Route101_MapCoordEvents:
	coord_event 10, 19, 3, VAR_ROUTE101_STATE, 1, Route101_EventScript_StartBirchRescue
	coord_event 11, 19, 3, VAR_ROUTE101_STATE, 1, Route101_EventScript_StartBirchRescue
	coord_event 10, 18, 3, VAR_ROUTE101_STATE, 2, Route101_EventScript_PreventExitSouth
	coord_event 11, 18, 3, VAR_ROUTE101_STATE, 2, Route101_EventScript_PreventExitSouth
	coord_event 6, 16, 3, VAR_ROUTE101_STATE, 2, Route101_EventScript_PreventExitWest
	coord_event 6, 15, 3, VAR_ROUTE101_STATE, 2, Route101_EventScript_PreventExitWest
	coord_event 6, 17, 3, VAR_ROUTE101_STATE, 2, Route101_EventScript_PreventExitWest
	coord_event 6, 18, 3, VAR_ROUTE101_STATE, 2, Route101_EventScript_PreventExitWest
	coord_event 7, 13, 3, VAR_ROUTE101_STATE, 2, Route101_EventScript_PreventExitNorth

Route101_MapBGEvents:
	bg_event 5, 9, 0, BG_EVENT_PLAYER_FACING_ANY, Route101_EventScript_RouteSign

Route101_MapEvents::
	map_events Route101_ObjectEvents, 0x0, Route101_MapCoordEvents, Route101_MapBGEvents

