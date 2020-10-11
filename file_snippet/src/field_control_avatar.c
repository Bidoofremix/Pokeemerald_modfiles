< //
static const u8 *GetInteractedWaterScript(struct MapPosition *unused1, u8 metatileBehavior, u8 direction)
{
    if (FlagGet(FLAG_CAN_USE_SURF) == TRUE && PartyHasMonWithSurf() == TRUE && IsPlayerFacingSurfableFishableWater() == TRUE)
        return EventScript_UseSurf;

    if (MetatileBehavior_IsWaterfall(metatileBehavior) == TRUE)
    {
        if (FlagGet(FLAG_BADGE08_GET) == TRUE && IsPlayerSurfingNorth() == TRUE)
            return EventScript_UseWaterfall;
        else
            return EventScript_CannotUseWaterfall;
    }
    return NULL;
}

static bool32 TrySetupDiveDownScript(void)
// >

< //
        if (ShouldDoWallyCall() == TRUE)
        {
            ScriptContext1_SetupScript(MauvilleCity_EventScript_RegisterWallyCall);
            return TRUE;
        }
        if (ShouldDoProfStoneCall() == TRUE)
        {
            ScriptContext1_SetupScript(MauvilleCity_EventScript_ProfStoneCall);
            return TRUE;
        }
        if (ShouldDoScottFortreeCall() == TRUE)
// >