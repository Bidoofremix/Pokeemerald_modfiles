< //
static void Task_ReturnToItemListAfterItemPurchase(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        PlaySE(SE_SELECT);
        if ((ItemId_GetPocket(tItemId) == POCKET_POKE_BALLS) && tItemCount > 9 && AddBagItem(ITEM_PREMIER_BALL, tItemCount / 10) == TRUE)       {
		{
           if (tItemCount > 19)
           {
               BuyMenuDisplayMessage(taskId, gText_ThrowInPremierBalls, BuyMenuReturnToItemList);
           }
           else
           {
               BuyMenuDisplayMessage(taskId, gText_ThrowInPremierBall, BuyMenuReturnToItemList);
           }
        }
		}
        else
        {
            BuyMenuReturnToItemList(taskId);
        }
    }
}

static void Task_ReturnToItemListAfterDecorationPurchase(u8 taskId)
// >