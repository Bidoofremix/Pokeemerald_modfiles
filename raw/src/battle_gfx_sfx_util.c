< //
static void BattleLoadMonSpriteGfx(struct Pokemon *mon, u32 battlerId, bool32 opponent)
{
    u32 monsPersonality, currentPersonality, otId, species, paletteOffset, position;
    const void *lzPaletteData;
    struct Pokemon *illusionMon = GetIllusionMonPtr(battlerId);
    if (illusionMon != NULL)
        mon = illusionMon;

    monsPersonality = GetMonData(mon, MON_DATA_PERSONALITY);
    if (gBattleSpritesDataPtr->battlerData[battlerId].transformSpecies == SPECIES_NONE)
    {
        species = GetMonData(mon, MON_DATA_SPECIES);
        currentPersonality = monsPersonality;
    }
    else
    {
        species = gBattleSpritesDataPtr->battlerData[battlerId].transformSpecies;
        currentPersonality = gTransformedPersonalities[battlerId];
    }

    otId = GetMonData(mon, MON_DATA_OT_ID);
    position = GetBattlerPosition(battlerId);
    if (opponent)
    {
        HandleLoadSpecialPokePic_DontHandleDeoxys(&gMonFrontPicTable[species],
                                              gMonSpritesGfxPtr->sprites[position],
                                              species, currentPersonality);
    }
    else
    {
        if (sub_80688F8(1, battlerId) == 1 || gBattleSpritesDataPtr->battlerData[battlerId].transformSpecies != SPECIES_NONE)
        {
            HandleLoadSpecialPokePic_DontHandleDeoxys(&gMonBackPicTable[species],
                                                      gMonSpritesGfxPtr->sprites[position],
                                                      species, currentPersonality);
        }
        else
        {
            HandleLoadSpecialPokePic(&gMonBackPicTable[species],
                                    gMonSpritesGfxPtr->sprites[position],
                                    species, currentPersonality);
        }
    }

    paletteOffset = 0x100 + battlerId * 16;

    if (gBattleSpritesDataPtr->battlerData[battlerId].transformSpecies == SPECIES_NONE)
        lzPaletteData = GetMonFrontSpritePal(mon);
    else
        lzPaletteData = GetMonSpritePalFromSpeciesAndPersonality(species, otId, monsPersonality);

    LZDecompressWram(lzPaletteData, gDecompressionBuffer);
    LoadPalette(gDecompressionBuffer, paletteOffset, 0x20);
    LoadPalette(gDecompressionBuffer, 0x80 + battlerId * 16, 0x20);

    // if (species == SPECIES_CASTFORM || species == SPECIES_CHERRIM)
    if (species == SPECIES_CASTFORM)
    {
        paletteOffset = 0x100 + battlerId * 16;
        LZDecompressWram(lzPaletteData, gBattleStruct->castformPalette[0]);
        LoadPalette(gBattleStruct->castformPalette[gBattleMonForms[battlerId]], paletteOffset, 0x20);
    }

    // transform's pink color
    if (gBattleSpritesDataPtr->battlerData[battlerId].transformSpecies != SPECIES_NONE)
    {
        BlendPalette(paletteOffset, 16, 6, RGB_WHITE);
        CpuCopy32(gPlttBufferFaded + paletteOffset, gPlttBufferUnfaded + paletteOffset, 32);
    }
}

void BattleLoadOpponentMonSpriteGfx(struct Pokemon *mon, u8 battlerId)
// >

< //
        if (targetSpecies == SPECIES_CASTFORM || targetSpecies == SPECIES_CHERRIM)
#R        if (targetSpecies == SPECIES_CASTFORM)
        {
            gSprites[gBattlerSpriteIds[battlerAtk]].anims = gMonFrontAnimsPtrTable[targetSpecies];
            LZDecompressWram(lzPaletteData, gBattleStruct->castformPalette[0]);
            LoadPalette(gBattleStruct->castformPalette[0] + gBattleMonForms[battlerDef] * 16, paletteOffset, 32);
        }

        if (!megaEvo)
// >