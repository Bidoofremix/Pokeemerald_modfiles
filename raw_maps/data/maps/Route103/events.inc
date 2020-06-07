Route103_ObjectEvents:
	object_event 1, OBJ_EVENT_GFX_MAN_3, 0, 49, 12, 3, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 0, 0, Route103_EventScript_Man, 0
	object_event 2, OBJ_EVENT_GFX_VAR_0, 0, 10, 3, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, Route103_EventScript_Rival, FLAG_HIDE_ROUTE_103_RIVAL
	object_event 3, OBJ_EVENT_GFX_WOMAN_2, 0, 71, 11, 3, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT, 0, 0, 1, 3, Route103_EventScript_Daisy, 0
	object_event 4, OBJ_EVENT_GFX_TWIN, 0, 65, 12, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 1, 1, Route103_EventScript_Liv, 0
	object_event 5, OBJ_EVENT_GFX_TWIN, 0, 64, 12, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 1, 1, Route103_EventScript_Amy, 0
	object_event 6, OBJ_EVENT_GFX_FISHERMAN, 0, 39, 11, 3, MOVEMENT_TYPE_WALK_DOWN_AND_UP, 0, 1, 1, 3, Route103_EventScript_Andrew, 0
	object_event 7, OBJ_EVENT_GFX_BERRY_TREE, 0, 58, 5, 3, MOVEMENT_TYPE_BERRY_TREE_GROWTH, 0, 0, 0, 5, BerryTreeScript, 0
	object_event 8, OBJ_EVENT_GFX_BERRY_TREE, 0, 59, 5, 3, MOVEMENT_TYPE_BERRY_TREE_GROWTH, 0, 0, 0, 6, BerryTreeScript, 0
	object_event 9, OBJ_EVENT_GFX_BERRY_TREE, 0, 60, 5, 3, MOVEMENT_TYPE_BERRY_TREE_GROWTH, 0, 0, 0, 7, BerryTreeScript, 0
	object_event 10, OBJ_EVENT_GFX_BOY_1, 0, 20, 10, 3, MOVEMENT_TYPE_WANDER_AROUND, 1, 2, 0, 0, Route103_EventScript_Boy, 0
	object_event 11, OBJ_EVENT_GFX_PROF_BIRCH, 0, 7, 3, 3, MOVEMENT_TYPE_WANDER_AROUND, 1, 1, 0, 0, ProfBirch_EventScript_RatePokedexOrRegister, FLAG_HIDE_ROUTE_103_BIRCH
	object_event 12, OBJ_EVENT_GFX_POKEFAN_M, 0, 56, 13, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 1, 5, Route103_EventScript_Miguel, 0
	object_event 13, OBJ_EVENT_GFX_ITEM_BALL, 0, 50, 5, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, Route103_EventScript_ItemGuardSpec, FLAG_ITEM_ROUTE_103_GUARD_SPEC
	object_event 14, OBJ_EVENT_GFX_CUTTABLE_TREE, 0, 67, 7, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, EventScript_CutTree, FLAG_TEMP_12
	object_event 15, OBJ_EVENT_GFX_CUTTABLE_TREE, 0, 72, 8, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, EventScript_CutTree, FLAG_TEMP_13
	object_event 16, OBJ_EVENT_GFX_BLACK_BELT, 0, 67, 5, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 1, 2, Route103_EventScript_Rhett, 0
	object_event 17, OBJ_EVENT_GFX_MAN_5, 0, 67, 9, 3, MOVEMENT_TYPE_FACE_UP, 1, 1, 1, 2, Route103_EventScript_Marcos, 0
	object_event 18, OBJ_EVENT_GFX_TUBER_F, 0, 32, 9, 1, MOVEMENT_TYPE_FACE_DOWN, 1, 3, 1, 2, Route103_EventScript_Isabelle, 0
	object_event 19, OBJ_EVENT_GFX_RUNNING_TRIATHLETE_M, 0, 49, 7, 1, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT, 5, 0, 1, 5, Route103_EventScript_Pete, 0
	object_event 20, OBJ_EVENT_GFX_ITEM_BALL, 0, 64, 7, 0, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, Route103_EventScript_ItemPPUp, FLAG_ITEM_ROUTE_103_PP_UP
	object_event 21, OBJ_EVENT_GFX_BREAKABLE_ROCK, 0, 66, 12, 3, MOVEMENT_TYPE_NONE, 0, 0, 0, 0, EventScript_RockSmash, FLAG_TEMP_15
	object_event 22, OBJ_EVENT_GFX_BREAKABLE_ROCK, 0, 67, 13, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, EventScript_RockSmash, FLAG_TEMP_14

Route103_MapWarps:
	warp_def 45, 5, 0, 0, MAP_ALTERING_CAVE

Route103_MapBGEvents:
	bg_event 11, 9, 0, BG_EVENT_PLAYER_FACING_ANY, Route103_EventScript_RouteSign

Route103_MapEvents::
	map_events Route103_ObjectEvents, Route103_MapWarps, 0x0, Route103_MapBGEvents

