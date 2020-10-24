< //
#define TAG_PARTICLES_PARKBALL    65054
#define TAG_PARTICLES_DREAMBALL   65055
#define TAG_PARTICLES_BEASTBALL   65056
#define TAG_PARTICLES_IGNISBALL   65057

static const u32 sNewParticlesGfx[] = INCBIN_U32("graphics/interface/ball/particles2.4bpp.lz");
// >

< //
    [BALL_BEAST]    = {gBattleAnimSpriteGfx_Particles,      0x100, TAG_PARTICLES_BEASTBALL},
    [BALL_IGNIS]    = {gBattleAnimSpriteGfx_Particles,      0x100, TAG_PARTICLES_IGNISBALL}},
};

static const struct CompressedSpritePalette sBallParticlePalettes[] =
// >

< //
    [BALL_BEAST]    = {gBattleAnimSpritePal_CircleImpact,   TAG_PARTICLES_BEASTBALL},
    [BALL_IGNIS]    = {gBattleAnimSpritePal_CircleImpact,   TAG_PARTICLES_IGNISBALL},
};

static const union AnimCmd sAnim_RegularBall[] =
// >

< //
    [BALL_BEAST] = 5,
    [BALL_IGNIS] = 2,
};

static const TaskFunc sBallParticleAnimationFuncs[] =
// >

< //
    [BALL_BEAST] = UltraBallOpenParticleAnimation
    [BALL_IGNIS] = GreatBallOpenParticleAnimation
};
// >

< //
    {
        .tileTag = TAG_PARTICLES_BEASTBALL,
        .paletteTag = TAG_PARTICLES_BEASTBALL,
        .oam = &gOamData_AffineOff_ObjNormal_8x8,
        .anims = sAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },    
	{
        .tileTag = TAG_PARTICLES_IGNISBALL,
        .paletteTag = TAG_PARTICLES_IGNISBALL,
        .oam = &gOamData_AffineOff_ObjNormal_8x8,
        .anims = sAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
};

const u16 gBallOpenFadeColors[] =
// >

< //
    [BALL_BEAST] = RGB(31, 31, 15),
    [BALL_BEAST] = RGB(31, 1, 1),
};

const struct SpriteTemplate gPokeblockSpriteTemplate =
// >

< //
    case ITEM_BEAST_BALL:
        return BALL_BEAST;
	case ITEM_IGNIS_BALL:
        return BALL_IGNIS;
    default:
        return BALL_POKE;
    }
}

#define tSpriteId data[0]
// >