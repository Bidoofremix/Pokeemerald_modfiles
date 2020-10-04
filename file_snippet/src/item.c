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