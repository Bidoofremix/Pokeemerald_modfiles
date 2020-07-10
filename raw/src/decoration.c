< //
static void DecorationItemsMenu_OnCursorMove(s32 itemIndex, bool8 flag, struct ListMenu *menu);
static void DecorationItemsMenu_PrintDecorationInUse(u8 windowId, s32 itemIndex, u8 y, u8 listPos);
static void ShowDecorationItemsWindow(u8 taskId);
// >

< //
static void DecorationItemsMenu_OnCursorMove(s32 itemIndex, bool8 flag, struct ListMenu *menu)
{
    if (flag != TRUE)
        PlaySE(SE_SELECT);

    PrintDecorationItemDescription(itemIndex);
}

static void DecorationItemsMenu_PrintDecorationInUse(u8 windowId, s32 itemIndex, u8 y, u8 listPos)
{
    if (itemIndex != -2)
    {
        if (IsDecorationIndexInSecretBase(itemIndex + 1) == TRUE)
            blit_move_info_icon(windowId, 0x18, 0x5c, y + 2);
        else if (IsDecorationIndexInPlayersRoom(itemIndex + 1) == TRUE)
            blit_move_info_icon(windowId, 0x19, 0x5c, y + 2);
    }
}

static void AddDecorationItemsScrollIndicators(void)
// >