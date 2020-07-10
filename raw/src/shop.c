< //
static void Task_ReturnToItemListAfterItemPurchase(u8 taskId);
static void Task_ReturnToItemListAfterTMShopPurchase(u8 taskId);
static void Task_ReturnToItemListAfterDecorationPurchase(u8 taskId);
static void Task_HandleShopMenuBuy(u8 taskId);
static void Task_HandleShopMenuSell(u8 taskId);
static void BuyMenuPrintItemDescriptionAndShowItemIcon(s32 item, bool8 onInit, struct ListMenu *list);
static void BuyMenuPrintPriceInList(u8 windowId, s32 item, u8 y, u8 itemPos);

static const struct YesNoFuncTable sShopPurchaseYesNoFuncs =
// >

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
			}	
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

< //
static u8 CreateShopMenu(u8 martType)
{
    int numMenuItems;

    ScriptContext2_Enable();
    gMartInfo.martType = martType;

    if (martType == MART_TYPE_NORMAL || martType == MART_TYPE_TM)
    {
        struct WindowTemplate winTemplate;
        winTemplate = sShopMenuWindowTemplates[0];
        winTemplate.width = GetMaxWidthInMenuTable(sShopMenuActions_BuySellQuit, ARRAY_COUNT(sShopMenuActions_BuySellQuit));
        gMartInfo.windowId = AddWindow(&winTemplate);
        gMartInfo.menuActions = sShopMenuActions_BuySellQuit;
        numMenuItems = ARRAY_COUNT(sShopMenuActions_BuySellQuit);
    }
    else
    {
        struct WindowTemplate winTemplate;
        winTemplate = sShopMenuWindowTemplates[1];
        winTemplate.width = GetMaxWidthInMenuTable(sShopMenuActions_BuyQuit, ARRAY_COUNT(sShopMenuActions_BuyQuit));
        gMartInfo.windowId = AddWindow(&winTemplate);
        gMartInfo.menuActions = sShopMenuActions_BuyQuit;
        numMenuItems = ARRAY_COUNT(sShopMenuActions_BuyQuit);
    }

    SetStandardWindowBorderStyle(gMartInfo.windowId, 0);
    PrintMenuTable(gMartInfo.windowId, numMenuItems, gMartInfo.menuActions);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(gMartInfo.windowId, numMenuItems, 0);
    PutWindowTilemap(gMartInfo.windowId);
    CopyWindowToVram(gMartInfo.windowId, 1);

    return CreateTask(Task_ShopMenu, 8);
}

static void SetTMShopItemsForSale(const u16 *items)
{
    u16 i = 0;

    gMartInfo.itemList = items;
    gMartInfo.itemCount = 0;

    while (i < TMSHOP_ITEMS_COUNT && gMartInfo.itemList[i])
    {
        gMartInfo.itemCount++;
        i++;
    }
}

static void SetShopId(u8 shopId)
{
    gMartInfo.shopId = shopId;
}

static void SetShopMenuCallback(void (* callback)(void))
// >

< //

static void BuyMenuSetListEntry(struct ListMenuItem *menuItem, u16 item, u8 *name)
{
    if (gMartInfo.martType == MART_TYPE_NORMAL || gMartInfo.martType == MART_TYPE_TM)
        CopyItemName(item, name);
    else
        StringCopy(name, gDecorations[item].name);

    menuItem->name = name;
    menuItem->id = item;
}

static void BuyMenuPrintItemDescriptionAndShowItemIcon(s32 item, bool8 onInit, struct ListMenu *list)
{
    const u8 *description;
    if (onInit != TRUE)
        PlaySE(SE_SELECT);

    if (item != -2)
        BuyMenuAddItemIcon(item, gShopDataPtr->iconSlot);
    else
        BuyMenuAddItemIcon(-1, gShopDataPtr->iconSlot);

    BuyMenuRemoveItemIcon(item, gShopDataPtr->iconSlot ^ 1);
    gShopDataPtr->iconSlot ^= 1;
    if (item != -2)
    {
        if (gMartInfo.martType == MART_TYPE_NORMAL || gMartInfo.martType == MART_TYPE_TM)
            description = ItemId_GetDescription(item);
        else
            description = gDecorations[item].description;
    }
    else
    {
        description = gText_QuitShopping;
    }

    FillWindowPixelBuffer(2, PIXEL_FILL(0));
    BuyMenuPrint(2, description, 3, 1, 0, 0);
}

static void BuyMenuPrintPriceInList(u8 windowId, s32 item, u8 y, u8 itemPos)
{
    u8 x;

    if (item != -2)
    {
        if (gMartInfo.martType == MART_TYPE_NORMAL)
        {
            ConvertIntToDecimalStringN(
                gStringVar1,
                ItemId_GetPrice(item) >> GetPriceReduction(POKENEWS_SLATEPORT),
                STR_CONV_MODE_LEFT_ALIGN,
                5);
            StringExpandPlaceholders(gStringVar4, gText_PokedollarVar1);
        }
        else if (gMartInfo.martType == MART_TYPE_TM)
        {
            if (GetSetItemBought(gMartInfo.shopId, itemPos, FLAG_GET_BOUGHT))
            {
                StringCopy(gStringVar1, gText_SoldOut);
                StringExpandPlaceholders(gStringVar4, gText_StrVar1);
            }
            else
            {
                ConvertIntToDecimalStringN(
                    gStringVar1,
                    ItemId_GetPrice(item) >> GetPriceReduction(POKENEWS_SLATEPORT),
                    STR_CONV_MODE_LEFT_ALIGN,
                    5);
                StringExpandPlaceholders(gStringVar4, gText_PokedollarVar1);
            }
        }
        else
        {
            ConvertIntToDecimalStringN(
                gStringVar1,
                gDecorations[item].price,
                STR_CONV_MODE_LEFT_ALIGN,
                5);
            StringExpandPlaceholders(gStringVar4, gText_PokedollarVar1);
        }

        x = GetStringRightAlignXOffset(7, gStringVar4, 0x78);
        AddTextPrinterParameterized4(windowId, 7, x, y, 0, 0, sShopBuyMenuTextColors[1], -1, gStringVar4);
    }
}

static void BuyMenuAddScrollIndicatorArrows(void)
{
    if (gShopDataPtr->scrollIndicatorsTaskId == 0xFF && gMartInfo.itemCount + 1 > 8)
    {
        gShopDataPtr->scrollIndicatorsTaskId = AddScrollIndicatorArrowPairParameterized(
            SCROLL_ARROW_UP,
            0xAC,
            0xC,
            0x94,
            gMartInfo.itemCount - 7,
            2100,
            2100,
            &gShopDataPtr->scrollOffset);
    }
}

static void BuyMenuRemoveScrollIndicatorArrows(void)
{
    if (gShopDataPtr->scrollIndicatorsTaskId != 0xFF)
    {
        RemoveScrollIndicatorArrowPair(gShopDataPtr->scrollIndicatorsTaskId);
        gShopDataPtr->scrollIndicatorsTaskId = 0xFF;
    }
}

static void BuyMenuPrintCursor(u8 scrollIndicatorsTaskId, u8 colorSet)
{
    u8 y = ListMenuGetYCoordForPrintingArrowCursor(scrollIndicatorsTaskId);
    BuyMenuPrint(1, gText_SelectorArrow2, 0, y, 0, colorSet);
}

static void BuyMenuAddItemIcon(u16 item, u8 iconSlot)
{
    u8 spriteId;
    u8 *spriteIdPtr = &gShopDataPtr->itemSpriteIds[iconSlot];
    if (*spriteIdPtr != 0xFF)
        return;

    if (gMartInfo.martType == MART_TYPE_NORMAL || gMartInfo.martType == MART_TYPE_TM || item == 0xFFFF)
    {
        spriteId = AddItemIconSprite(iconSlot + 2110, iconSlot + 2110, item);
        if (spriteId != MAX_SPRITES)
        {
            *spriteIdPtr = spriteId;
            gSprites[spriteId].pos2.x = 24;
            gSprites[spriteId].pos2.y = 88;
        }
    }
    else
    {
        spriteId = AddDecorationIconObject(item, 20, 84, 1, iconSlot + 2110, iconSlot + 2110);
        if (spriteId != MAX_SPRITES)
            *spriteIdPtr = spriteId;
    }
}

static void BuyMenuRemoveItemIcon(u16 item, u8 iconSlot)
// >