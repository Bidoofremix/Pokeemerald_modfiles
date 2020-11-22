< //
EventScript_ObtainedItem:: @ 8271B95
	compare VAR_0x8001, 1
	goto_if_eq EventScript_ObtainedItemMessage
	buffernumberstring 0, VAR_0x8001
	message gText_ObtainedTheItems
	goto EventScript_ContinueObtainedItem
EventScript_ObtainedItemMessage:
	message gText_ObtainedTheItem
EventScript_ContinueObtainedItem:
	waitfanfare
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	setvar VAR_RESULT, 1
	return
	
EventScript_NoRoomForItem:: @ 8271BA9
// >