< //
static void ListMenuPrintEntries(struct ListMenu *list, u16 startIndex, u16 yOffset, u16 count)
{
    s32 i;
    u8 x, y;
    u8 yMultiplier = GetFontAttribute(list->template.fontId, FONTATTR_MAX_LETTER_HEIGHT) + list->template.itemVerticalPadding;

    for (i = 0; i < count; i++)
    {
        if (list->template.items[startIndex].id != LIST_HEADER)
            x = list->template.item_X;
        else
            x = list->template.header_X;

        y = (yOffset + i) * yMultiplier + list->template.upText_Y;
        if (list->template.itemPrintFunc != NULL)
            list->template.itemPrintFunc(list->template.windowId, list->template.items[startIndex].id, y, startIndex);

        ListMenuPrint(list, list->template.items[startIndex].name, x, y);
        startIndex++;
    }
}

static void ListMenuDrawCursor(struct ListMenu *list)
// >