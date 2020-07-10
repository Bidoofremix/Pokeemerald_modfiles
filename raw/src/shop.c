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

< //
static void Task_BuyMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        s32 itemId = ListMenu_ProcessInput(tListTaskId);
        ListMenuGetScrollAndRow(tListTaskId, &gShopDataPtr->scrollOffset, &gShopDataPtr->selectedRow);

        switch (itemId)
        {
        case LIST_NOTHING_CHOSEN:
            break;
        case LIST_CANCEL:
            PlaySE(SE_SELECT);
            ExitBuyMenu(taskId);
            break;
        default:
            PlaySE(SE_SELECT);
            tItemId = itemId;
            ClearWindowTilemap(2);
            BuyMenuRemoveScrollIndicatorArrows();
            BuyMenuPrintCursor(tListTaskId, 2);

            if (gMartInfo.martType == MART_TYPE_NORMAL)
            {
                gShopDataPtr->totalCost = (ItemId_GetPrice(itemId) >> GetPriceReduction(POKENEWS_SLATEPORT));
            }
            else
            {
                gShopDataPtr->totalCost = gDecorations[itemId].price;
            }

            if (!IsEnoughMoney(&gSaveBlock1Ptr->money, gShopDataPtr->totalCost))
            {
                BuyMenuDisplayMessage(taskId, gText_YouDontHaveMoney, BuyMenuReturnToItemList);
            else if (ItemId_GetPocket(itemId) == POCKET_TM_HM && CheckBagHasItem(itemId, 1))
            {
                BuyMenuDisplayMessage(taskId, gText_YouAlreadyHaveThis, BuyMenuReturnToItemList);
            }
            else
            {
                if (gMartInfo.martType == MART_TYPE_NORMAL)
                {
                    CopyItemName(itemId, gStringVar1);
                    if (ItemId_GetPocket(itemId) == POCKET_TM_HM)
                    {
                        StringCopy(gStringVar2, gMoveNames[ItemIdToBattleMoveId(itemId)]);
                        BuyMenuDisplayMessage(taskId, gText_Var1CertainlyHowMany2, Task_BuyHowManyDialogueInit);
                    }
                    else
                    {
                        BuyMenuDisplayMessage(taskId, gText_Var1CertainlyHowMany, Task_BuyHowManyDialogueInit);
                    }
                }
                else
                {
                    StringCopy(gStringVar1, gDecorations[itemId].name);
                    ConvertIntToDecimalStringN(gStringVar2, gShopDataPtr->totalCost, STR_CONV_MODE_LEFT_ALIGN, 6);

                    if (gMartInfo.martType == MART_TYPE_DECOR)
                        StringExpandPlaceholders(gStringVar4, gText_Var1IsItThatllBeVar2);
                    else
                        StringExpandPlaceholders(gStringVar4, gText_YouWantedVar1ThatllBeVar2);
                    BuyMenuDisplayMessage(taskId, gStringVar4, BuyMenuConfirmPurchase);
                }
            }
            break;
        }
    }
}

static void Task_BuyHowManyDialogueInit(u8 taskId)
// >