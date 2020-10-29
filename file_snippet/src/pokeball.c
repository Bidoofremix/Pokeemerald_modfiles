< //
#define GFX_TAG_BEASTBALL   55026
#define GFX_TAG_IGNIS   55027

const struct CompressedSpriteSheet gBallSpriteSheets[POKEBALL_COUNT] =
// >

< //
    {gInterfaceGfx_BeastBall,   384, GFX_TAG_BEASTBALL},
    {gInterfaceGfx_IgnisBall,   384, GFX_TAG_DIVEBALL},
};

const struct CompressedSpritePalette gBallSpritePalettes[POKEBALL_COUNT] =
// >

< //
    {gInterfacePal_BeastBall,   GFX_TAG_BEASTBALL},
    {gInterfacePal_IgnisBall,   GFX_TAG_DIVEBALL},
};

static const struct OamData sBallOamData =
// >

< //
        .tileTag = GFX_TAG_BEASTBALL,
        .paletteTag = GFX_TAG_BEASTBALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_TestBallThrow,
    },
	{
        .tileTag = GFX_TAG_DIVEBALL,
        .paletteTag = GFX_TAG_DIVEBALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_TestBallThrow,
    },
};

#define tFrames          data[0]
// >