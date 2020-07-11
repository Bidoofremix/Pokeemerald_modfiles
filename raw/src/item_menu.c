< //
void BagMenu_MoveCursorCallback(s32 a, bool8 b, struct ListMenu*);
void PrintItemQuantityPlusGFX(u8 rboxId, s32 item_index_in_pocket, u8 a, u8 listPos);
void ItemMenu_UseOutOfBattle(u8 taskId);
// >

< //
void BagMenu_MoveCursorCallback(s32 a, bool8 b, struct ListMenu *unused)
{
    if (b != 1)
    {
        PlaySE(SE_SELECT);
        ShakeBagVisual();
    }
    if (gBagMenu->unk81A == 0xFF)
    {
        RemoveBagItemIconSprite(1 ^ gBagMenu->unk81B_1);
        if (a != -2)
           AddBagItemIconSprite(BagGetItemIdByPocketPosition(gBagPositionStruct.pocket + 1, a), gBagMenu->unk81B_1);
        else
           AddBagItemIconSprite(-1, gBagMenu->unk81B_1);
        gBagMenu->unk81B_1 ^= 1;
        if (!gBagMenu->unk81B_3)
            BagMenu_PrintDescription(a);
    }
}

void PrintItemQuantityPlusGFX(u8 rboxId, s32 item_index_in_pocket, u8 a, u8 listPos)
{
    u16 itemId;
    u16 itemQuantity;
    bool8 unique;
    int offset;
    if (item_index_in_pocket != -2)
    {
        if (gBagMenu->unk81A != 0xFF)
        {
            if (gBagMenu->unk81A == (u8)item_index_in_pocket)
                BagMenu_PrintCursor(a, 2);
            else
                BagMenu_PrintCursor(a, -1);
        }
        itemId = BagGetItemIdByPocketPosition(gBagPositionStruct.pocket + 1, item_index_in_pocket);
        itemQuantity = BagGetQuantityByPocketPosition(gBagPositionStruct.pocket + 1, item_index_in_pocket);
        if (itemId >= ITEM_HM01 && itemId <= ITEM_HM08)
            BlitBitmapToWindow(rboxId, gBagMenuHMIcon_Gfx, 8, a - 1, 16, 16);
        if (gBagPositionStruct.pocket == BERRIES_POCKET)
        {
            ConvertIntToDecimalStringN(gStringVar1, itemQuantity, STR_CONV_MODE_RIGHT_ALIGN, 3);
            StringExpandPlaceholders(gStringVar4, gText_xVar1);
            offset = GetStringRightAlignXOffset(7, gStringVar4, 0x77);
            BagMenu_Print(rboxId, 7, gStringVar4, offset, a, 0, 0, -1, 0);
        }
        else if (gBagPositionStruct.pocket != KEYITEMS_POCKET && (unique = ItemId_GetImportance(itemId)) == FALSE)
        {
            ConvertIntToDecimalStringN(gStringVar1, itemQuantity, STR_CONV_MODE_RIGHT_ALIGN, 2);
            StringExpandPlaceholders(gStringVar4, gText_xVar1);
            offset = GetStringRightAlignXOffset(7, gStringVar4, 0x77);
            BagMenu_Print(rboxId, 7, gStringVar4, offset, a, unique, unique, -1, unique);
        }
        else
        {
            if (gSaveBlock1Ptr->registeredItem && gSaveBlock1Ptr->registeredItem == itemId)
                BlitBitmapToWindow(rboxId, gRegisteredSelect_Gfx, 0x60, a - 1, 0x18, 16);
        }
    }
}

void BagMenu_PrintDescription(int a)
// >

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