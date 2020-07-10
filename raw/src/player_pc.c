< //
static void ItemStorage_MoveCursor(s32 id, bool8 b, struct ListMenu * thisMenu);
static void fish4_goto_x5_or_x6(u8 windowId, s32 id, u8 yOffset, u8 listPos);

// EWRAM
static EWRAM_DATA const u8 *gPcItemMenuOptionOrder = NULL;
// >

< //
static void ItemStorage_MoveCursor(s32 id, bool8 b, struct ListMenu *thisMenu)
{
    if (b != TRUE)
        PlaySE(SE_SELECT);
    if (gUnknown_0203BCC4->unk666 == 0xFF)
    {
        sub_816C0C8();
        if (id != -2)
            sub_816C060(gSaveBlock1Ptr->pcItems[id].itemId);
        else
            sub_816C060(ITEMPC_GO_BACK_TO_PREV);
        sub_816BEF0(id);
    }
}

static void fish4_goto_x5_or_x6(u8 windowId, s32 id, u8 yOffset, u8 listPos)
{
    if (id != -2)
    {
        if (gUnknown_0203BCC4->unk666 != 0xFF)
        {
            if (gUnknown_0203BCC4->unk666 == (u8)id)
                sub_816BFE0(yOffset, 0, 0xFF);
            else
                sub_816BFE0(yOffset, 0xFF, 0xFF);
        }
        ConvertIntToDecimalStringN(gStringVar1, gSaveBlock1Ptr->pcItems[id].quantity, STR_CONV_MODE_RIGHT_ALIGN, 3);
        StringExpandPlaceholders(gStringVar4, gText_xVar1);
        AddTextPrinterParameterized(windowId, 7, gStringVar4, GetStringRightAlignXOffset(7, gStringVar4, 104), yOffset, 0xFF, NULL);
    }
}

static void sub_816BEF0(s32 id)
// >