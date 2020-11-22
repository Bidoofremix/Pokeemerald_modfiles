< //
static u16 GetBagItemQuantity(u16 *quantity)
{
    return gSaveBlock2Ptr->encryptionKey ^ *quantity;
}

void ItemID_GetHoldEffectParam_Script();

void ItemId_GetHoldEffectParam_Script()
{
    VarSet(VAR_RESULT, ItemId_GetHoldEffectParam(VarGet(VAR_0x8004)));
}

static void SetBagItemQuantity(u16 *quantity, u16 newValue)
// >

< //
void CopyItemNameHandlePlural(u16 itemId, u8 *dst, u32 quantity)
{
    StringCopy(dst, ItemId_GetName(itemId));
    if (quantity > 1)
    {
        if (ItemId_GetPocket(itemId) == POCKET_BERRIES)
            GetBerryCountString(dst, gBerries[itemId - ITEM_CHERI_BERRY].name, quantity);
        else
            StringAppend(dst, sText_s);
    }
}

static const u8 sText_s[] = _("s");

void GetBerryCountString(u8 *dst, const u8 *berryName, u32 quantity)
// >