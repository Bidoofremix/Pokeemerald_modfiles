< //
#define TAG_PARTICLES_CHERISHBALL 65053
#define TAG_PARTICLES_CLONEBALL   65054
#define TAG_PARTICLES_DREAMBALL   65055
#define TAG_PARTICLES_BEASTBALL   65056
#define TAG_PARTICLES_IGNISBALL   65057

static const u32 sNewParticlesGfx[] = INCBIN_U32("graphics/interface/ball/particles2.4bpp.lz");
// >

< //
    [BALL_CHERISH]  = {sNewParticlesGfx,                    0x100, TAG_PARTICLES_CHERISHBALL},
    [BALL_CLONE]    = {sNewParticlesGfx,                    0x100, TAG_PARTICLES_CLONEBALL},
    [BALL_DREAM]    = {gBattleAnimSpriteGfx_Particles,      0x100, TAG_PARTICLES_DREAMBALL},
    [BALL_BEAST]    = {gBattleAnimSpriteGfx_Particles,      0x100, TAG_PARTICLES_BEASTBALL},
    [BALL_IGNIS]    = {sNewParticlesGfx,                    0x100, TAG_PARTICLES_IGNISBALL},
};

static const struct CompressedSpritePalette sBallParticlePalettes[] =
// >

< //
    [BALL_CHERISH]  = {sNewParticlesPal,                    TAG_PARTICLES_CHERISHBALL},
    [BALL_CLONE]    = {sNewParticlesPal,                    TAG_PARTICLES_CLONEBALL},
    [BALL_DREAM]    = {gBattleAnimSpritePal_CircleImpact,   TAG_PARTICLES_DREAMBALL},
    [BALL_BEAST]    = {gBattleAnimSpritePal_CircleImpact,   TAG_PARTICLES_BEASTBALL},
    [BALL_IGNIS]    = {sNewParticlesPal,                    TAG_PARTICLES_IGNISBALL},
};

static const union AnimCmd sAnim_RegularBall[] =
// >

< //
static const u8 sBallParticleAnimNums[POKEBALL_COUNT] =
{
    [BALL_POKE]    = 0,
    [BALL_GREAT]   = 0,
    [BALL_SAFARI]  = 0,
    [BALL_ULTRA]   = 5,
    [BALL_MASTER]  = 1,
    [BALL_NET]     = 2,
    [BALL_DIVE]    = 2,
    [BALL_NEST]    = 3,
    [BALL_REPEAT]  = 5,
    [BALL_TIMER]   = 5,
    [BALL_LUXURY]  = 4,
    [BALL_PREMIER] = 4,

    [BALL_LEVEL] = 5,
    [BALL_LURE] = 2,
    [BALL_MOON] = 4,
    [BALL_FRIEND] = 3,
    [BALL_LOVE] = 3,
    [BALL_HEAVY] = 0,
    [BALL_FAST] = 4,
    [BALL_SPORT] = 0,
    [BALL_DUSK] = 2,
    [BALL_QUICK] = 4,
    [BALL_HEAL] = 0,
    [BALL_CHERISH] = 0,
    [BALL_CLONE] = 2,
    [BALL_DREAM] = 5,
    [BALL_BEAST] = 5,
    [BALL_IGNIS] = 3,
};

static const TaskFunc sBallParticleAnimationFuncs[] =
{
    [BALL_POKE] = PokeBallOpenParticleAnimation,
    [BALL_GREAT] = GreatBallOpenParticleAnimation,
    [BALL_SAFARI] = SafariBallOpenParticleAnimation,
    [BALL_ULTRA] = UltraBallOpenParticleAnimation,
    [BALL_MASTER] = MasterBallOpenParticleAnimation,
    [BALL_NET] = SafariBallOpenParticleAnimation,
    [BALL_DIVE] = DiveBallOpenParticleAnimation,
    [BALL_NEST] = UltraBallOpenParticleAnimation,
    [BALL_REPEAT] = RepeatBallOpenParticleAnimation,
    [BALL_TIMER] = TimerBallOpenParticleAnimation,
    [BALL_LUXURY] = GreatBallOpenParticleAnimation,
    [BALL_PREMIER] = PremierBallOpenParticleAnimation,

    // Todo: assign and possibly create different particles
    [BALL_LEVEL] = SafariBallOpenParticleAnimation,
    [BALL_LURE] = GreatBallOpenParticleAnimation,
    [BALL_MOON] = UltraBallOpenParticleAnimation,
    [BALL_FRIEND] = UltraBallOpenParticleAnimation,
    [BALL_LOVE] = GreatBallOpenParticleAnimation,
    [BALL_HEAVY] = GreatBallOpenParticleAnimation,
    [BALL_FAST] = GreatBallOpenParticleAnimation,
    [BALL_SPORT] = UltraBallOpenParticleAnimation,
    [BALL_DUSK] = UltraBallOpenParticleAnimation,
    [BALL_QUICK] = UltraBallOpenParticleAnimation,
    [BALL_HEAL] = PokeBallOpenParticleAnimation,
    [BALL_CHERISH] = MasterBallOpenParticleAnimation,
    [BALL_CLONE] = RepeatBallOpenParticleAnimation,
    [BALL_DREAM] = UltraBallOpenParticleAnimation,
    [BALL_BEAST] = UltraBallOpenParticleAnimation,
    [BALL_IGNIS] = GreatBallOpenParticleAnimation
};

static const struct SpriteTemplate sBallParticleSpriteTemplates[POKEBALL_COUNT] =
// >

< //
        .tileTag = TAG_PARTICLES_CHERISHBALL,
        .paletteTag = TAG_PARTICLES_CHERISHBALL,
        .oam = &gOamData_AffineOff_ObjNormal_8x8,
        .anims = sAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    {
        .tileTag = TAG_PARTICLES_CLONEBALL,
        .paletteTag = TAG_PARTICLES_CLONEBALL,
        .oam = &gOamData_AffineOff_ObjNormal_8x8,
        .anims = sAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    {
        .tileTag = TAG_PARTICLES_DREAMBALL,
        .paletteTag = TAG_PARTICLES_DREAMBALL,
        .oam = &gOamData_AffineOff_ObjNormal_8x8,
        .anims = sAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
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
{
    [BALL_POKE] = RGB(31, 22, 30),
    [BALL_GREAT] = RGB(16, 23, 30),
    [BALL_SAFARI] = RGB(23, 30, 20),
    [BALL_ULTRA] = RGB(31, 31, 15),
    [BALL_MASTER] = RGB(23, 20, 28),
    [BALL_NET] = RGB(21, 31, 25),
    [BALL_DIVE] = RGB(12, 25, 30),
    [BALL_NEST] = RGB(30, 27, 10),
    [BALL_REPEAT] = RGB(31, 24, 16),
    [BALL_TIMER] = RGB(29, 30, 30),
    [BALL_LUXURY] = RGB(31, 17, 10),
    [BALL_PREMIER] = RGB(31, 9, 10),

    // Todo, assign different colors
    [BALL_LEVEL] = RGB(24, 4, 4),
    [BALL_LURE] = RGB(9, 22, 27),
    [BALL_MOON] = RGB(30, 25, 8),
    [BALL_FRIEND] = RGB(17, 24, 7),
    [BALL_LOVE] = RGB(31, 19, 26),
    [BALL_HEAVY] = RGB(7, 11, 20),
    [BALL_FAST] = RGB(29, 17, 8),
    [BALL_SPORT] = RGB(31, 31, 15),
    [BALL_DUSK] = RGB(7, 1, 13),
    [BALL_QUICK] = RGB(16, 25, 30),
    [BALL_HEAL] = RGB(31, 23, 27),
    [BALL_CHERISH] = RGB(25, 4, 3),
    [BALL_CLONE] = RGB(31, 31, 15),
    [BALL_DREAM] = RGB(31, 31, 15),
    [BALL_BEAST] = RGB(31, 31, 15),
    [BALL_IGNIS] = RGB(31, 13, 1),
};

const struct SpriteTemplate gPokeblockSpriteTemplate =
// >

< //
u8 ItemIdToBallId(u16 ballItem)
{
    switch (ballItem)
    {
    case ITEM_MASTER_BALL:
        return BALL_MASTER;
    case ITEM_ULTRA_BALL:
        return BALL_ULTRA;
    case ITEM_GREAT_BALL:
        return BALL_GREAT;
    case ITEM_SAFARI_BALL:
        return BALL_SAFARI;
    case ITEM_NET_BALL:
        return BALL_NET;
    case ITEM_DIVE_BALL:
        return BALL_DIVE;
    case ITEM_NEST_BALL:
        return BALL_NEST;
    case ITEM_REPEAT_BALL:
        return BALL_REPEAT;
    case ITEM_TIMER_BALL:
        return BALL_TIMER;
    case ITEM_LUXURY_BALL:
        return BALL_LUXURY;
    case ITEM_PREMIER_BALL:
        return BALL_PREMIER;
    case ITEM_POKE_BALL:
        return BALL_POKE;
    case ITEM_LEVEL_BALL:
        return BALL_LEVEL;
    case ITEM_LURE_BALL:
        return BALL_LURE;
    case ITEM_MOON_BALL:
        return BALL_MOON;
    case ITEM_FRIEND_BALL:
        return BALL_FRIEND;
    case ITEM_LOVE_BALL:
        return BALL_LOVE;
    case ITEM_HEAVY_BALL:
        return BALL_HEAVY;
    case ITEM_FAST_BALL:
        return BALL_FAST;
    case ITEM_SPORT_BALL:
        return BALL_SPORT;
    case ITEM_DUSK_BALL:
        return BALL_DUSK;
    case ITEM_QUICK_BALL:
        return BALL_QUICK;
    case ITEM_HEAL_BALL:
        return BALL_HEAL;
    case ITEM_CHERISH_BALL:
        return BALL_CHERISH;
    case ITEM_CLONE_BALL:
        return BALL_CLONE;
    case ITEM_DREAM_BALL:
        return BALL_DREAM;
    case ITEM_BEAST_BALL:
        return BALL_BEAST;
	case ITEM_IGNIS_BALL:
        return BALL_IGNIS;
    default:
        return BALL_POKE;
    }
}
// >