< //
void DisplaySellItemAskString(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (ItemId_GetPrice(gSpecialVar_ItemId) == 0 || ItemId_GetPocket(gSpecialVar_ItemId) == POCKET_TM_HM)
    {
        CopyItemName(gSpecialVar_ItemId, gStringVar2);
        StringExpandPlaceholders(gStringVar4, gText_CantBuyKeyItem);
        DisplayItemMessage(taskId, 1, gStringVar4, BagMenu_InitListsMenu);
    }
    else
    {
        tItemCount = 1;
        if (data[2] == 1)
        {
            DisplayCurrentMoneyWindow();
            DisplaySellItemPriceAndConfirm(taskId);
        }
        else
        {
            CopyItemName(gSpecialVar_ItemId, gStringVar2);
            StringExpandPlaceholders(gStringVar4, gText_HowManyToSell);
            DisplayItemMessage(taskId, 1, gStringVar4, sub_81AD730);
        }
    }
}

void DisplaySellItemPriceAndConfirm(u8 taskId)
// >