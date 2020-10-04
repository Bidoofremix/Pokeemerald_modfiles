< //
static const union AnimCmd *const sSpriteAnimTable_859F508[] =
{
    sSpriteAnim_859F4F0,
    sSpriteAnim_859F4F8,
    sSpriteAnim_859F500
};

static const struct CompressedSpriteSheet gUnknown_0859F514 =
/*static const struct CompressedSpriteSheet gBagSwapSpriteSheet =*/
{
    gBagSwapLineGfx, 0x100, 109
};

static const struct CompressedSpritePalette gUnknown_0859F51C =
/*static const struct CompressedSpritePalette gBagSwapSpritePalette =*/
{
    gBagSwapLinePal, 109
};

static const struct SpriteTemplate gUnknown_0859F524 =
// >

< //
static const struct SpriteTemplate gUnknown_0859F524 =
{
    .tileTag = 109,
    .paletteTag = 109,
    .oam = &sOamData_859F4E8,
    .anims = sSpriteAnimTable_859F508,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

void ResetAllBgsCoordinatesAndBgCntRegs(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG3CNT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    ChangeBgX(2, 0, 0);
    ChangeBgY(2, 0, 0);
    ChangeBgX(3, 0, 0);
    ChangeBgY(3, 0, 0);
}

// code
void ResetVramOamAndBgCntRegs(void)
// >

< //
void LoadListMenuArrowsGfx(void)
{
    LoadCompressedSpriteSheet(&gUnknown_0859F514);
    LoadCompressedSpritePalette(&gUnknown_0859F51C);
	/*LoadCompressedSpriteSheet(&gBagSwapSpriteSheet);
    LoadCompressedSpritePalette(&gBagSwapSpritePalette);*/
}

void sub_8122344(u8 *spriteIds, u8 count)
// >