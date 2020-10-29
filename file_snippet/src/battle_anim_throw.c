< //
#define TAG_PARTICLES_BEASTBALL   65056
#define TAG_PARTICLES_IGNISBALL   65057

static const u32 sNewParticlesGfx[] = INCBIN_U32("graphics/interface/ball/particles2.4bpp.lz");
// >

< //
    [BALL_BEAST]    = {gBattleAnimSpriteGfx_Particles,      0x100, TAG_PARTICLES_BEASTBALL},
    [BALL_IGNIS]    = {gBattleAnimSpriteGfx_Particles,      0x100, TAG_PARTICLES_BEASTBALL},
};

static const struct CompressedSpritePalette sBallParticlePalettes[] =
// >

< //
    [BALL_BEAST]    = {gBattleAnimSpritePal_CircleImpact,   TAG_PARTICLES_BEASTBALL},
    [BALL_IGNIS]    = {gBattleAnimSpritePal_CircleImpact,   TAG_PARTICLES_BEASTBALL},
};

static const union AnimCmd sAnim_RegularBall[] =
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
    case ITEM_PARK_BALL:
        return BALL_PARK;
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