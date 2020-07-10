< //
bool8 ScrCmd_pokemart(struct ScriptContext *ctx)
{
    const void *ptr = (void *)ScriptReadWord(ctx);
    u8 tmShopId = ScriptReadByte(ctx);
	
    if(!tmShopId)
        CreatePokemartMenu(ptr);
    else
        CreateTMShopMenu(ptr, tmShopId);	
    ScriptContext1_Stop();
    return TRUE;
}

bool8 ScrCmd_pokemartdecoration(struct ScriptContext *ctx)
// >