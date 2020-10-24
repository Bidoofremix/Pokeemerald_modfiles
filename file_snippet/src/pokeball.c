< //
#define GFX_TAG_BEASTBALL   55026
#define GFX_TAG_IGNISBALL   55027

const struct CompressedSpriteSheet gBallSpriteSheets[POKEBALL_COUNT] =
// >

< //
    {gInterfaceGfx_BeastBall,   384, GFX_TAG_BEASTBALL},
    {gInterfaceGfx_IgnisBall,   384, GFX_TAG_IGNISBALL},
};

const struct CompressedSpritePalette gBallSpritePalettes[POKEBALL_COUNT] =
// >

< //
    {gInterfacePal_BeastBall,   GFX_TAG_BEASTBALL},
    {gInterfacePal_IgnisBall,   GFX_TAG_IGNISBALL},
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
		.tileTag = GFX_TAG_IGNISBALL,
        .paletteTag = GFX_TAG_IGNISBALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sAffineAnim_BallRotate,
        .callback = SpriteCB_TestBallThrow,
    },
};

#define tFrames          data[0]
// >