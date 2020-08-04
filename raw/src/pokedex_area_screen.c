< //
static bool8 MapHasMon(const struct WildPokemonHeader *info, u16 species)
{
	// make altering cave behave like a regular map
    /* if (GetRegionMapSectionId(info->mapGroup, info->mapNum) == MAPSEC_ALTERING_CAVE)
    {
        sPokedexAreaScreen->unk6E2++;
        if (sPokedexAreaScreen->unk6E2 != sPokedexAreaScreen->unk6E4 + 1)
            return FALSE;
    }*/

    if (MonListHasMon(info->landMonsInfo, species, 12))
        return TRUE;
    if (MonListHasMon(info->waterMonsInfo, species, 5))
        return TRUE;
    if (MonListHasMon(info->fishingMonsInfo, species, 12))
        return TRUE;
    if (MonListHasMon(info->rockSmashMonsInfo, species, 5))
        return TRUE;
    return FALSE;
}

static bool8 MonListHasMon(const struct WildPokemonInfo *info, u16 species, u16 size)
// >