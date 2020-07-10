< //
static void PyramidBagMoveCursorFunc(s32 itemIndex, bool8 onInit, struct ListMenu *list);
static void PrintItemQuantity(u8 windowId, s32 itemIndex, u8 y, u8 itemPos);
static void TossItem(u8 taskId);
// >

< //
static void PyramidBagMoveCursorFunc(s32 itemIndex, bool8 onInit, struct ListMenu *list)
{
    if (onInit != TRUE)
    {
        PlaySE(SE_SELECT);
        sub_81C6F20();
    }
    if (gPyramidBagResources->unk814 == 0xFF)
    {
        sub_81C6FF8(gPyramidBagResources->unk815 ^ 1);
        if (itemIndex != LIST_CANCEL)
            ShowItemImage(gSaveBlock2Ptr->frontier.pyramidBag.itemId[gSaveBlock2Ptr->frontier.lvlMode][itemIndex], gPyramidBagResources->unk815);
        else
            ShowItemImage(0xFFFF, gPyramidBagResources->unk815);
        gPyramidBagResources->unk815 ^= 1;
        PrintItemDescription(itemIndex);
    }
}

static void PrintItemQuantity(u8 windowId, s32 itemIndex, u8 y, u8 itemPos)
{
    s32 xAlign;
    if (itemIndex == LIST_CANCEL)
        return;

    if (gPyramidBagResources->unk814 != 0xFF)
    {
        if (gPyramidBagResources->unk814 == (u8)(itemIndex))
            sub_81C5AB8(y, 1);
        else
            sub_81C5AB8(y, 0xFF);
    }
    ConvertIntToDecimalStringN(gStringVar1,
                               gSaveBlock2Ptr->frontier.pyramidBag.quantity[gSaveBlock2Ptr->frontier.lvlMode][itemIndex],
                               STR_CONV_MODE_RIGHT_ALIGN,
                               2);
    StringExpandPlaceholders(gStringVar4, gText_xVar1);
    xAlign = GetStringRightAlignXOffset(7, gStringVar4, 0x77);
    PrintOnWindow_Font7(windowId, gStringVar4, xAlign, y, 0, 0, TEXT_SPEED_FF, 0);
}

static void PrintItemDescription(s32 listMenuId)
// >