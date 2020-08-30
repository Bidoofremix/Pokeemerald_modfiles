< //
    [MOVE_SWIFT] =
    {
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 1,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },
// >

< //
    [MOVE_VINE_WHIP] =
    {
        .effect = EFFECT_HIT,
        .power = 45,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },
// >