< //
GraniteCave_FieryRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GraniteCave_FieryRoom_OnTransition
	.byte 0

GraniteCave_FieryRoom_EventScript_ItemFlameOrb::
	finditem ITEM_FLAME_ORB
	end	
	
GraniteCave_FieryRoom_EventScript_ItemIgnisBall::
	finditem ITEM_IGNIS_BALL
	end	
	
GraniteCave_FieryRoom_OnTransition:
// >