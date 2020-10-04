< //
static void Task_UseRepel(u8 taskId)
{
    if (!IsSEPlaying())
    {
        VarSet(VAR_REPEL_STEP_COUNT, ItemId_GetHoldEffectParam(gSpecialVar_ItemId));
		VarSet(VAR_REPEL_LAST_USED, gSpecialVar_ItemId);
        RemoveUsedItem();
        if (!InBattlePyramid())
            DisplayItemMessage(taskId, 1, gStringVar4, BagMenu_InitListsMenu);
        else
            DisplayItemMessageInBattlePyramid(taskId, gStringVar4, Task_CloseBattlePyramidBagMessage);
    }
}

static void Task_UsedBlackWhiteFlute(u8 taskId)
// >