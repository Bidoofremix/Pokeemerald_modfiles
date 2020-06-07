LittlerootTown_ObjectEvents:
	object_event 1, OBJ_EVENT_GFX_TWIN, 0, 16, 10, 3, MOVEMENT_TYPE_WANDER_AROUND, 1, 2, 0, 0, LittlerootTown_EventScript_Twin, 0
	object_event 2, OBJ_EVENT_GFX_FAT_MAN, 0, 12, 13, 3, MOVEMENT_TYPE_WANDER_AROUND, 2, 1, 0, 0, LittlerootTown_EventScript_FatMan, FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN
	object_event 3, OBJ_EVENT_GFX_BOY_2, 0, 14, 17, 3, MOVEMENT_TYPE_WANDER_AROUND, 2, 1, 0, 0, LittlerootTown_EventScript_Boy, 0
	object_event 4, OBJ_EVENT_GFX_MOM, 0, 5, 8, 3, MOVEMENT_TYPE_FACE_UP, 0, 0, 0, 0, LittlerootTown_EventScript_Mom, FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
	object_event 5, OBJ_EVENT_GFX_TRUCK, 0, 2, 10, 4, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, 0x0, FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
	object_event 6, OBJ_EVENT_GFX_TRUCK, 0, 11, 10, 4, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, 0x0, FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
	object_event 7, OBJ_EVENT_GFX_VAR_0, 0, 13, 10, 3, MOVEMENT_TYPE_FACE_UP, 1, 1, 0, 0, 0x0, FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
	object_event 8, OBJ_EVENT_GFX_PROF_BIRCH, 0, 14, 10, 3, MOVEMENT_TYPE_FACE_UP, 1, 1, 0, 0, 0x0, FLAG_HIDE_LITTLEROOT_TOWN_BIRCH

LittlerootTown_MapWarps:
	warp_def 14, 8, 0, 1, MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F
	warp_def 5, 8, 0, 1, MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F
	warp_def 7, 16, 0, 0, MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB

LittlerootTown_MapCoordEvents:
	coord_event 10, 1, 3, VAR_LITTLEROOT_TOWN_STATE, 0, LittlerootTown_EventScript_NeedPokemonTriggerLeft
	coord_event 11, 1, 3, VAR_LITTLEROOT_TOWN_STATE, 0, LittlerootTown_EventScript_NeedPokemonTriggerRight
	coord_event 11, 1, 3, VAR_LITTLEROOT_TOWN_STATE, 1, LittlerootTown_EventScript_GoSaveBirchTrigger
	coord_event 8, 9, 3, VAR_LITTLEROOT_TOWN_STATE, 3, LittlerootTown_EventScript_GiveRunningShoesTrigger4
	coord_event 9, 9, 3, VAR_LITTLEROOT_TOWN_STATE, 3, LittlerootTown_EventScript_GiveRunningShoesTrigger5
	coord_event 10, 9, 3, VAR_LITTLEROOT_TOWN_STATE, 3, LittlerootTown_EventScript_GiveRunningShoesTrigger2
	coord_event 11, 9, 3, VAR_LITTLEROOT_TOWN_STATE, 3, LittlerootTown_EventScript_GiveRunningShoesTrigger3
	coord_event 10, 2, 3, VAR_LITTLEROOT_TOWN_STATE, 3, LittlerootTown_EventScript_GiveRunningShoesTrigger0
	coord_event 11, 2, 3, VAR_LITTLEROOT_TOWN_STATE, 3, LittlerootTown_EventScript_GiveRunningShoesTrigger1

LittlerootTown_MapBGEvents:
	bg_event 15, 13, 0, BG_EVENT_PLAYER_FACING_ANY, LittlerootTown_EventScript_TownSign
	bg_event 6, 17, 0, BG_EVENT_PLAYER_FACING_ANY, LittlerootTown_EventScript_BirchsLabSign
	bg_event 7, 8, 3, BG_EVENT_PLAYER_FACING_ANY, LittlerootTown_EventScript_BrendansHouseSign
	bg_event 12, 8, 3, BG_EVENT_PLAYER_FACING_ANY, LittlerootTown_EventScript_MaysHouseSign

LittlerootTown_MapEvents::
	map_events LittlerootTown_ObjectEvents, LittlerootTown_MapWarps, LittlerootTown_MapCoordEvents, LittlerootTown_MapBGEvents

