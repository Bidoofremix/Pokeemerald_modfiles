Route124_ObjectEvents:
	object_event 1, OBJ_EVENT_GFX_SWIMMER_M, 0, 34, 25, 1, MOVEMENT_TYPE_LOOK_AROUND, 5, 0, 1, 3, Route124_EventScript_Spencer, 0
	object_event 2, OBJ_EVENT_GFX_SWIMMER_M, 0, 61, 74, 1, MOVEMENT_TYPE_WALK_IN_PLACE_RIGHT, 5, 3, 1, 7, Route124_EventScript_Roland, 0
	object_event 3, OBJ_EVENT_GFX_SWIMMER_F, 0, 49, 45, 1, MOVEMENT_TYPE_ROTATE_CLOCKWISE, 0, 0, 1, 3, Route124_EventScript_Jenny, 0
	object_event 4, OBJ_EVENT_GFX_SWIMMER_F, 0, 7, 23, 1, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT, 6, 8, 1, 5, Route124_EventScript_Grace, 0
	object_event 5, OBJ_EVENT_GFX_SWIMMER_M, 0, 58, 58, 1, MOVEMENT_TYPE_WALK_RIGHT_AND_LEFT, 7, 0, 1, 2, Route124_EventScript_Chad, 0
	object_event 6, OBJ_EVENT_GFX_ITEM_BALL, 0, 28, 12, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, Route124_EventScript_ItemRedShard, FLAG_ITEM_ROUTE_124_RED_SHARD
	object_event 7, OBJ_EVENT_GFX_ITEM_BALL, 0, 31, 53, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, Route124_EventScript_ItemBlueShard, FLAG_ITEM_ROUTE_124_BLUE_SHARD
	object_event 8, OBJ_EVENT_GFX_ITEM_BALL, 0, 58, 11, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, Route124_EventScript_ItemYellowShard, FLAG_ITEM_ROUTE_124_YELLOW_SHARD
	object_event 9, OBJ_EVENT_GFX_SWIMMER_F, 0, 18, 44, 1, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 1, 1, Route124_EventScript_Lila, 0
	object_event 10, OBJ_EVENT_GFX_TUBER_M_SWIMMING, 0, 17, 44, 1, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 1, 1, Route124_EventScript_Roy, 0
	object_event 11, OBJ_EVENT_GFX_SWIMMER_M, 0, 7, 29, 1, MOVEMENT_TYPE_FACE_UP, 1, 1, 1, 5, Route124_EventScript_Declan, 0
	object_event 12, OBJ_EVENT_GFX_SWIMMER_F, 0, 69, 74, 1, MOVEMENT_TYPE_WALK_IN_PLACE_LEFT, 1, 1, 1, 7, Route124_EventScript_Isabella, 0

Route124_MapWarps:
	warp_def 70, 48, 3, 0, MAP_ROUTE124_DIVING_TREASURE_HUNTERS_HOUSE

Route124_MapBGEvents:
	bg_event 73, 48, 3, BG_EVENT_PLAYER_FACING_ANY, Route124_EventScript_HuntersHouseSign

Route124_MapEvents::
	map_events Route124_ObjectEvents, Route124_MapWarps, 0x0, Route124_MapBGEvents

