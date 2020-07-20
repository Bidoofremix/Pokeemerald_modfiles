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
void HandleSpeciesGfxDataChange(u8 battlerAtk, u8 battlerDef, bool8 notTransform, bool32 megaEvo)
{
    u32 personalityValue, otId, position, paletteOffset, targetSpecies;
    const void *lzPaletteData, *src;
    void *dst;

    if (IsContest())
    {
        position = 0;
        targetSpecies = gContestResources->field_18->unk2;
        personalityValue = gContestResources->field_18->unk8;
        otId = gContestResources->field_18->unkC;

        HandleLoadSpecialPokePic_DontHandleDeoxys(&gMonBackPicTable[targetSpecies],
                                                  gMonSpritesGfxPtr->sprites[0],
                                                  targetSpecies,
                                                  gContestResources->field_18->unk10);
    }
    else
    {
        position = GetBattlerPosition(battlerAtk);

        if (GetBattlerSide(battlerDef) == B_SIDE_OPPONENT)
            targetSpecies = GetMonData(&gEnemyParty[gBattlerPartyIndexes[battlerDef]], MON_DATA_SPECIES);
        else
            targetSpecies = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerDef]], MON_DATA_SPECIES);

        if (GetBattlerSide(battlerAtk) == B_SIDE_PLAYER)
        {
            personalityValue = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerAtk]], MON_DATA_PERSONALITY);
            otId = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerAtk]], MON_DATA_OT_ID);

            HandleLoadSpecialPokePic_DontHandleDeoxys(&gMonBackPicTable[targetSpecies],
                                                      gMonSpritesGfxPtr->sprites[position],
                                                      targetSpecies,
                                                      gTransformedPersonalities[battlerAtk]);
        }
        else
        {
            personalityValue = GetMonData(&gEnemyParty[gBattlerPartyIndexes[battlerAtk]], MON_DATA_PERSONALITY);
            otId = GetMonData(&gEnemyParty[gBattlerPartyIndexes[battlerAtk]], MON_DATA_OT_ID);

            HandleLoadSpecialPokePic_DontHandleDeoxys(&gMonFrontPicTable[targetSpecies],
                                                      gMonSpritesGfxPtr->sprites[position],
                                                      targetSpecies,
                                                      gTransformedPersonalities[battlerAtk]);
        }
    }

    if (notTransform)
    {
        StartSpriteAnim(&gSprites[gBattlerSpriteIds[battlerAtk]], gBattleSpritesDataPtr->animationData->animArg);
        paletteOffset = 0x100 + battlerAtk * 16;
        LoadPalette(gBattleStruct->castformPalette[gBattleSpritesDataPtr->animationData->animArg], paletteOffset, 32);
        gBattleMonForms[battlerAtk] = gBattleSpritesDataPtr->animationData->animArg;
        if (gBattleSpritesDataPtr->battlerData[battlerAtk].transformSpecies != SPECIES_NONE)
        {
            BlendPalette(paletteOffset, 16, 6, RGB_WHITE);
            CpuCopy32(gPlttBufferFaded + paletteOffset, gPlttBufferUnfaded + paletteOffset, 32);
        }
        gSprites[gBattlerSpriteIds[battlerAtk]].pos1.y = GetBattlerSpriteDefault_Y(battlerAtk);
    }
    else
    {
        src = gMonSpritesGfxPtr->sprites[position];
        dst = (void *)(VRAM + 0x10000 + gSprites[gBattlerSpriteIds[battlerAtk]].oam.tileNum * 32);
        DmaCopy32(3, src, dst, 0x800);
        paletteOffset = 0x100 + battlerAtk * 16;
        lzPaletteData = GetMonSpritePalFromSpeciesAndPersonality(targetSpecies, otId, personalityValue);
        LZDecompressWram(lzPaletteData, gDecompressionBuffer);
        LoadPalette(gDecompressionBuffer, paletteOffset, 32);

        // if (targetSpecies == SPECIES_CASTFORM || targetSpecies == SPECIES_CHERRIM)
        if (targetSpecies == SPECIES_CASTFORM)
        {
            gSprites[gBattlerSpriteIds[battlerAtk]].anims = gMonFrontAnimsPtrTable[targetSpecies];
            LZDecompressWram(lzPaletteData, gBattleStruct->castformPalette[0]);
            LoadPalette(gBattleStruct->castformPalette[0] + gBattleMonForms[battlerDef] * 16, paletteOffset, 32);
        }

        if (!megaEvo)
        {
            BlendPalette(paletteOffset, 16, 6, RGB_WHITE);
            CpuCopy32(gPlttBufferFaded + paletteOffset, gPlttBufferUnfaded + paletteOffset, 32);
        }

        if (!IsContest() && !megaEvo)
        {
            gBattleSpritesDataPtr->battlerData[battlerAtk].transformSpecies = targetSpecies;
            gBattleMonForms[battlerAtk] = gBattleMonForms[battlerDef];
        }

        gSprites[gBattlerSpriteIds[battlerAtk]].pos1.y = GetBattlerSpriteDefault_Y(battlerAtk);
        StartSpriteAnim(&gSprites[gBattlerSpriteIds[battlerAtk]], gBattleMonForms[battlerAtk]);
    }
}

void BattleLoadSubstituteOrMonSpriteGfx(u8 battlerId, bool8 loadMonSprite)
// >