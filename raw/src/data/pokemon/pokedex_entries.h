< //
const struct PokedexEntry gPokedexEntries[] =
{
    [NATIONAL_DEX_BULBASAUR] = 
    {
        .categoryName = _("SEED"),
        .description = gBulbasaurPokedexText,
        .height = 7,
        .pokemonOffset = 17,
        .pokemonScale = 356,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 69,
    },

    [NATIONAL_DEX_IVYSAUR] = 
    {
        .categoryName = _("SEED"),
        .description = gIvysaurPokedexText,
        .height = 10,
        .pokemonOffset = 13,
        .pokemonScale = 335,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 130,
    },

    [NATIONAL_DEX_VENUSAUR] = 
    {
        .categoryName = _("SEED"),
        .description = gVenusaurPokedexText,
        .height = 20,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 6,
        .trainerScale = 388,
        .weight = 1000,
    },

    [NATIONAL_DEX_CHARMANDER] = 
    {
        .categoryName = _("LIZARD"),
        .description = gCharmanderPokedexText,
        .height = 6,
        .pokemonOffset = 18,
        .pokemonScale = 444,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 85,
    },

    [NATIONAL_DEX_CHARMELEON] = 
    {
        .categoryName = _("FLAME"),
        .description = gCharmeleonPokedexText,
        .height = 11,
        .pokemonOffset = 9,
        .pokemonScale = 302,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 190,
    },

    [NATIONAL_DEX_CHARIZARD] = 
    {
        .categoryName = _("FLAME"),
        .description = gCharizardPokedexText,
        .height = 17,
        .pokemonOffset = 1,
        .pokemonScale = 256,
        .trainerOffset = 3,
        .trainerScale = 302,
        .weight = 905,
    },

    [NATIONAL_DEX_SQUIRTLE] = 
    {
        .categoryName = _("TINY TURTLE"),
        .description = gSquirtlePokedexText,
        .height = 5,
        .pokemonOffset = 18,
        .pokemonScale = 412,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 90,
    },

    [NATIONAL_DEX_WARTORTLE] = 
    {
        .categoryName = _("TURTLE"),
        .description = gWartortlePokedexText,
        .height = 10,
        .pokemonOffset = 10,
        .pokemonScale = 332,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 225,
    },

    [NATIONAL_DEX_BLASTOISE] = 
    {
        .categoryName = _("SHELLFISH"),
        .description = gBlastoisePokedexText,
        .height = 16,
        .pokemonOffset = -1,
        .pokemonScale = 256,
        .trainerOffset = 2,
        .trainerScale = 293,
        .weight = 855,
    },

    [NATIONAL_DEX_CATERPIE] = 
    {
        .categoryName = _("WORM"),
        .description = gCaterpiePokedexText,
        .height = 3,
        .pokemonOffset = 22,
        .pokemonScale = 549,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 29,
    },

    [NATIONAL_DEX_METAPOD] = 
    {
        .categoryName = _("COCOON"),
        .description = gMetapodPokedexText,
        .height = 7,
        .pokemonOffset = 18,
        .pokemonScale = 350,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 99,
    },

    [NATIONAL_DEX_BUTTERFREE] = 
    {
        .categoryName = _("BUTTERFLY"),
        .description = gButterfreePokedexText,
        .height = 11,
        .pokemonOffset = 2,
        .pokemonScale = 312,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 320,
    },

    [NATIONAL_DEX_WEEDLE] = 
    {
        .categoryName = _("HAIRY BUG"),
        .description = gWeedlePokedexText,
        .height = 3,
        .pokemonOffset = 22,
        .pokemonScale = 455,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 32,
    },

    [NATIONAL_DEX_KAKUNA] = 
    {
        .categoryName = _("COCOON"),
        .description = gKakunaPokedexText,
        .height = 6,
        .pokemonOffset = 17,
        .pokemonScale = 424,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 100,
    },

    [NATIONAL_DEX_BEEDRILL] = 
    {
        .categoryName = _("POISON BEE"),
        .description = gBeedrillPokedexText,
        .height = 10,
        .pokemonOffset = 2,
        .pokemonScale = 366,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 295,
    },

    [NATIONAL_DEX_PIDGEY] = 
    {
        .categoryName = _("TINY BIRD"),
        .description = gPidgeyPokedexText,
        .height = 3,
        .pokemonOffset = -3,
        .pokemonScale = 508,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 18,
    },

    [NATIONAL_DEX_PIDGEOTTO] = 
    {
        .categoryName = _("BIRD"),
        .description = gPidgeottoPokedexText,
        .height = 11,
        .pokemonOffset = 10,
        .pokemonScale = 331,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 300,
    },

    [NATIONAL_DEX_PIDGEOT] = 
    {
        .categoryName = _("BIRD"),
        .description = gPidgeotPokedexText,
        .height = 15,
        .pokemonOffset = 0,
        .pokemonScale = 269,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 395,
    },

    [NATIONAL_DEX_RATTATA] = 
    {
        .categoryName = _("MOUSE"),
        .description = gRattataPokedexText,
        .height = 3,
        .pokemonOffset = 21,
        .pokemonScale = 481,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 35,
    },

    [NATIONAL_DEX_RATICATE] = 
    {
        .categoryName = _("MOUSE"),
        .description = gRaticatePokedexText,
        .height = 7,
        .pokemonOffset = 18,
        .pokemonScale = 459,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 185,
    },

    [NATIONAL_DEX_SPEAROW] = 
    {
        .categoryName = _("TINY BIRD"),
        .description = gSpearowPokedexText,
        .height = 3,
        .pokemonOffset = 22,
        .pokemonScale = 571,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 20,
    },

    [NATIONAL_DEX_FEAROW] = 
    {
        .categoryName = _("BEAK"),
        .description = gFearowPokedexText,
        .height = 12,
        .pokemonOffset = 1,
        .pokemonScale = 278,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 380,
    },

    [NATIONAL_DEX_EKANS] = 
    {
        .categoryName = _("SNAKE"),
        .description = gEkansPokedexText,
        .height = 20,
        .pokemonOffset = 12,
        .pokemonScale = 298,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 69,
    },

    [NATIONAL_DEX_ARBOK] = 
    {
        .categoryName = _("COBRA"),
        .description = gArbokPokedexText,
        .height = 35,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 2,
        .trainerScale = 296,
        .weight = 650,
    },

    [NATIONAL_DEX_PICHU] = 
    {
        .categoryName = _("TINY MOUSE"),
        .description = gPichuPokedexText,
        .height = 3,
        .pokemonOffset = 20,
        .pokemonScale = 508,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 20,
    },

    [NATIONAL_DEX_PIKACHU] = 
    {
        .categoryName = _("MOUSE"),
        .description = gPikachuPokedexText,
        .height = 4,
        .pokemonOffset = 19,
        .pokemonScale = 479,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 60,
    },

    [NATIONAL_DEX_RAICHU] = 
    {
        .categoryName = _("MOUSE"),
        .description = gRaichuPokedexText,
        .height = 8,
        .pokemonOffset = 13,
        .pokemonScale = 426,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 300,
    },

    [NATIONAL_DEX_SANDSHREW] = 
    {
        .categoryName = _("MOUSE"),
        .description = gSandshrewPokedexText,
        .height = 6,
        .pokemonOffset = 18,
        .pokemonScale = 365,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 120,
    },

    [NATIONAL_DEX_SANDSLASH] = 
    {
        .categoryName = _("MOUSE"),
        .description = gSandslashPokedexText,
        .height = 10,
        .pokemonOffset = 11,
        .pokemonScale = 341,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 295,
    },

    [NATIONAL_DEX_NIDORAN_F] = 
    {
        .categoryName = _("POISON PIN"),
        .description = gNidoranFPokedexText,
        .height = 4,
        .pokemonOffset = 21,
        .pokemonScale = 488,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 70,
    },

    [NATIONAL_DEX_NIDORINA] = 
    {
        .categoryName = _("POISON PIN"),
        .description = gNidorinaPokedexText,
        .height = 8,
        .pokemonOffset = 15,
        .pokemonScale = 381,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 200,
    },

    [NATIONAL_DEX_NIDOQUEEN] = 
    {
        .categoryName = _("DRILL"),
        .description = gNidoqueenPokedexText,
        .height = 13,
        .pokemonOffset = 4,
        .pokemonScale = 293,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 600,
    },

    [NATIONAL_DEX_NIDORAN_M] = 
    {
        .categoryName = _("POISON PIN"),
        .description = gNidoranMPokedexText,
        .height = 5,
        .pokemonOffset = 20,
        .pokemonScale = 511,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 90,
    },

    [NATIONAL_DEX_NIDORINO] = 
    {
        .categoryName = _("POISON PIN"),
        .description = gNidorinoPokedexText,
        .height = 9,
        .pokemonOffset = 15,
        .pokemonScale = 408,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 195,
    },

    [NATIONAL_DEX_NIDOKING] = 
    {
        .categoryName = _("DRILL"),
        .description = gNidokingPokedexText,
        .height = 14,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 620,
    },

    [NATIONAL_DEX_CLEFFA] = 
    {
        .categoryName = _("STAR SHAPE"),
        .description = gCleffaPokedexText,
        .height = 3,
        .pokemonOffset = 23,
        .pokemonScale = 462,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 30,
    },

    [NATIONAL_DEX_CLEFAIRY] = 
    {
        .categoryName = _("FAIRY"),
        .description = gClefairyPokedexText,
        .height = 6,
        .pokemonOffset = 20,
        .pokemonScale = 441,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 75,
    },

    [NATIONAL_DEX_CLEFABLE] = 
    {
        .categoryName = _("FAIRY"),
        .description = gClefablePokedexText,
        .height = 13,
        .pokemonOffset = 5,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 400,
    },

    [NATIONAL_DEX_VULPIX] = 
    {
        .categoryName = _("FOX"),
        .description = gVulpixPokedexText,
        .height = 6,
        .pokemonOffset = 19,
        .pokemonScale = 542,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 99,
    },

    [NATIONAL_DEX_NINETALES] = 
    {
        .categoryName = _("FOX"),
        .description = gNinetalesPokedexText,
        .height = 11,
        .pokemonOffset = 10,
        .pokemonScale = 339,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 199,
    },

    [NATIONAL_DEX_IGGLYBUFF] = 
    {
        .categoryName = _("BALLOON"),
        .description = gIgglybuffPokedexText,
        .height = 3,
        .pokemonOffset = -1,
        .pokemonScale = 457,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 10,
    },

    [NATIONAL_DEX_JIGGLYPUFF] = 
    {
        .categoryName = _("BALLOON"),
        .description = gJigglypuffPokedexText,
        .height = 5,
        .pokemonOffset = 2,
        .pokemonScale = 433,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 55,
    },

    [NATIONAL_DEX_WIGGLYTUFF] = 
    {
        .categoryName = _("BALLOON"),
        .description = gWigglytuffPokedexText,
        .height = 10,
        .pokemonOffset = 11,
        .pokemonScale = 328,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 120,
    },

    [NATIONAL_DEX_ZUBAT] = 
    {
        .categoryName = _("BAT"),
        .description = gZubatPokedexText,
        .height = 8,
        .pokemonOffset = -5,
        .pokemonScale = 362,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 75,
    },

    [NATIONAL_DEX_GOLBAT] = 
    {
        .categoryName = _("BAT"),
        .description = gGolbatPokedexText,
        .height = 16,
        .pokemonOffset = 1,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 550,
    },

    [NATIONAL_DEX_CROBAT] = 
    {
        .categoryName = _("BAT"),
        .description = gCrobatPokedexText,
        .height = 18,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 1,
        .trainerScale = 281,
        .weight = 750,
    },

    [NATIONAL_DEX_ODDISH] = 
    {
        .categoryName = _("WEED"),
        .description = gOddishPokedexText,
        .height = 5,
        .pokemonOffset = 19,
        .pokemonScale = 423,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 54,
    },

    [NATIONAL_DEX_GLOOM] = 
    {
        .categoryName = _("WEED"),
        .description = gGloomPokedexText,
        .height = 8,
        .pokemonOffset = 13,
        .pokemonScale = 329,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 86,
    },

    [NATIONAL_DEX_VILEPLUME] = 
    {
        .categoryName = _("FLOWER"),
        .description = gVileplumePokedexText,
        .height = 12,
        .pokemonOffset = 4,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 186,
    },

    [NATIONAL_DEX_BELLOSSOM] = 
    {
        .categoryName = _("FLOWER"),
        .description = gBellossomPokedexText,
        .height = 4,
        .pokemonOffset = 21,
        .pokemonScale = 472,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 58,
    },

    [NATIONAL_DEX_PARAS] = 
    {
        .categoryName = _("MUSHROOM"),
        .description = gParasPokedexText,
        .height = 3,
        .pokemonOffset = 22,
        .pokemonScale = 593,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 54,
    },

    [NATIONAL_DEX_PARASECT] = 
    {
        .categoryName = _("MUSHROOM"),
        .description = gParasectPokedexText,
        .height = 10,
        .pokemonOffset = 8,
        .pokemonScale = 307,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 295,
    },

    [NATIONAL_DEX_VENONAT] = 
    {
        .categoryName = _("INSECT"),
        .description = gVenonatPokedexText,
        .height = 10,
        .pokemonOffset = 0,
        .pokemonScale = 360,
        .trainerOffset = -1,
        .trainerScale = 256,
        .weight = 300,
    },

    [NATIONAL_DEX_VENOMOTH] = 
    {
        .categoryName = _("POISON MOTH"),
        .description = gVenomothPokedexText,
        .height = 15,
        .pokemonOffset = 2,
        .pokemonScale = 285,
        .trainerOffset = 1,
        .trainerScale = 256,
        .weight = 125,
    },

    [NATIONAL_DEX_DIGLETT] = 
    {
        .categoryName = _("MOLE"),
        .description = gDiglettPokedexText,
        .height = 2,
        .pokemonOffset = 25,
        .pokemonScale = 833,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 8,
    },

    [NATIONAL_DEX_DUGTRIO] = 
    {
        .categoryName = _("MOLE"),
        .description = gDugtrioPokedexText,
        .height = 7,
        .pokemonOffset = 18,
        .pokemonScale = 406,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 333,
    },

    [NATIONAL_DEX_MEOWTH] = 
    {
        .categoryName = _("SCRATCH CAT"),
        .description = gMeowthPokedexText,
        .height = 4,
        .pokemonOffset = 19,
        .pokemonScale = 480,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 42,
    },

    [NATIONAL_DEX_PERSIAN] = 
    {
        .categoryName = _("CLASSY CAT"),
        .description = gPersianPokedexText,
        .height = 10,
        .pokemonOffset = 10,
        .pokemonScale = 320,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 320,
    },

    [NATIONAL_DEX_PSYDUCK] = 
    {
        .categoryName = _("DUCK"),
        .description = gPsyduckPokedexText,
        .height = 8,
        .pokemonOffset = 15,
        .pokemonScale = 369,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 196,
    },

    [NATIONAL_DEX_GOLDUCK] = 
    {
        .categoryName = _("DUCK"),
        .description = gGolduckPokedexText,
        .height = 17,
        .pokemonOffset = 1,
        .pokemonScale = 256,
        .trainerOffset = 1,
        .trainerScale = 273,
        .weight = 766,
    },

    [NATIONAL_DEX_MANKEY] = 
    {
        .categoryName = _("PIG MONKEY"),
        .description = gMankeyPokedexText,
        .height = 5,
        .pokemonOffset = 19,
        .pokemonScale = 404,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 280,
    },

    [NATIONAL_DEX_PRIMEAPE] = 
    {
        .categoryName = _("PIG MONKEY"),
        .description = gPrimeapePokedexText,
        .height = 10,
        .pokemonOffset = 10,
        .pokemonScale = 326,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 320,
    },

    [NATIONAL_DEX_GROWLITHE] = 
    {
        .categoryName = _("PUPPY"),
        .description = gGrowlithePokedexText,
        .height = 7,
        .pokemonOffset = 14,
        .pokemonScale = 346,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 190,
    },

    [NATIONAL_DEX_ARCANINE] = 
    {
        .categoryName = _("LEGENDARY"),
        .description = gArcaninePokedexText,
        .height = 19,
        .pokemonOffset = 1,
        .pokemonScale = 256,
        .trainerOffset = 4,
        .trainerScale = 312,
        .weight = 1550,
    },

    [NATIONAL_DEX_POLIWAG] = 
    {
        .categoryName = _("TADPOLE"),
        .description = gPoliwagPokedexText,
        .height = 6,
        .pokemonOffset = 20,
        .pokemonScale = 369,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 124,
    },

    [NATIONAL_DEX_POLIWHIRL] = 
    {
        .categoryName = _("TADPOLE"),
        .description = gPoliwhirlPokedexText,
        .height = 10,
        .pokemonOffset = 11,
        .pokemonScale = 288,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 200,
    },

    [NATIONAL_DEX_POLIWRATH] = 
    {
        .categoryName = _("TADPOLE"),
        .description = gPoliwrathPokedexText,
        .height = 13,
        .pokemonOffset = 6,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 540,
    },

    [NATIONAL_DEX_POLITOED] = 
    {
        .categoryName = _("FROG"),
        .description = gPolitoedPokedexText,
        .height = 11,
        .pokemonOffset = 6,
        .pokemonScale = 289,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 339,
    },

    [NATIONAL_DEX_ABRA] = 
    {
        .categoryName = _("PSI"),
        .description = gAbraPokedexText,
        .height = 9,
        .pokemonOffset = 14,
        .pokemonScale = 363,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 195,
    },

    [NATIONAL_DEX_KADABRA] = 
    {
        .categoryName = _("PSI"),
        .description = gKadabraPokedexText,
        .height = 13,
        .pokemonOffset = 3,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 565,
    },

    [NATIONAL_DEX_ALAKAZAM] = 
    {
        .categoryName = _("PSI"),
        .description = gAlakazamPokedexText,
        .height = 15,
        .pokemonOffset = 3,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 480,
    },

    [NATIONAL_DEX_MACHOP] = 
    {
        .categoryName = _("SUPERPOWER"),
        .description = gMachopPokedexText,
        .height = 8,
        .pokemonOffset = 14,
        .pokemonScale = 342,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 195,
    },

    [NATIONAL_DEX_MACHOKE] = 
    {
        .categoryName = _("SUPERPOWER"),
        .description = gMachokePokedexText,
        .height = 15,
        .pokemonOffset = 9,
        .pokemonScale = 323,
        .trainerOffset = 0,
        .trainerScale = 257,
        .weight = 705,
    },

    [NATIONAL_DEX_MACHAMP] = 
    {
        .categoryName = _("SUPERPOWER"),
        .description = gMachampPokedexText,
        .height = 16,
        .pokemonOffset = 1,
        .pokemonScale = 280,
        .trainerOffset = -1,
        .trainerScale = 269,
        .weight = 1300,
    },

    [NATIONAL_DEX_BELLSPROUT] = 
    {
        .categoryName = _("FLOWER"),
        .description = gBellsproutPokedexText,
        .height = 7,
        .pokemonOffset = 16,
        .pokemonScale = 354,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 40,
    },

    [NATIONAL_DEX_WEEPINBELL] = 
    {
        .categoryName = _("FLYCATCHER"),
        .description = gWeepinbellPokedexText,
        .height = 10,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 64,
    },

    [NATIONAL_DEX_VICTREEBEL] = 
    {
        .categoryName = _("FLYCATCHER"),
        .description = gVictreebelPokedexText,
        .height = 17,
        .pokemonOffset = 1,
        .pokemonScale = 256,
        .trainerOffset = 3,
        .trainerScale = 312,
        .weight = 155,
    },

    [NATIONAL_DEX_TENTACOOL] = 
    {
        .categoryName = _("JELLYFISH"),
        .description = gTentacoolPokedexText,
        .height = 9,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 455,
    },

    [NATIONAL_DEX_TENTACRUEL] = 
    {
        .categoryName = _("JELLYFISH"),
        .description = gTentacruelPokedexText,
        .height = 16,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 1,
        .trainerScale = 312,
        .weight = 550,
    },

    [NATIONAL_DEX_GEODUDE] = 
    {
        .categoryName = _("ROCK"),
        .description = gGeodudePokedexText,
        .height = 4,
        .pokemonOffset = 18,
        .pokemonScale = 347,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 200,
    },

    [NATIONAL_DEX_GRAVELER] = 
    {
        .categoryName = _("ROCK"),
        .description = gGravelerPokedexText,
        .height = 10,
        .pokemonOffset = 2,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 1050,
    },

    [NATIONAL_DEX_GOLEM] = 
    {
        .categoryName = _("MEGATON"),
        .description = gGolemPokedexText,
        .height = 14,
        .pokemonOffset = 3,
        .pokemonScale = 256,
        .trainerOffset = 2,
        .trainerScale = 296,
        .weight = 3000,
    },

    [NATIONAL_DEX_PONYTA] = 
    {
        .categoryName = _("FIRE HORSE"),
        .description = gPonytaPokedexText,
        .height = 10,
        .pokemonOffset = 8,
        .pokemonScale = 283,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 300,
    },

    [NATIONAL_DEX_RAPIDASH] = 
    {
        .categoryName = _("FIRE HORSE"),
        .description = gRapidashPokedexText,
        .height = 17,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 1,
        .trainerScale = 289,
        .weight = 950,
    },

    [NATIONAL_DEX_SLOWPOKE] = 
    {
        .categoryName = _("DOPEY"),
        .description = gSlowpokePokedexText,
        .height = 12,
        .pokemonOffset = 10,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 360,
    },

    [NATIONAL_DEX_SLOWBRO] = 
    {
        .categoryName = _("HERMIT CRAB"),
        .description = gSlowbroPokedexText,
        .height = 16,
        .pokemonOffset = 6,
        .pokemonScale = 256,
        .trainerOffset = 2,
        .trainerScale = 296,
        .weight = 785,
    },

    [NATIONAL_DEX_SLOWKING] = 
    {
        .categoryName = _("ROYAL"),
        .description = gSlowkingPokedexText,
        .height = 20,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 5,
        .trainerScale = 309,
        .weight = 795,
    },

    [NATIONAL_DEX_MAGNEMITE] = 
    {
        .categoryName = _("MAGNET"),
        .description = gMagnemitePokedexText,
        .height = 3,
        .pokemonOffset = -9,
        .pokemonScale = 288,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 60,
    },

    [NATIONAL_DEX_MAGNETON] = 
    {
        .categoryName = _("MAGNET"),
        .description = gMagnetonPokedexText,
        .height = 10,
        .pokemonOffset = 1,
        .pokemonScale = 292,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 600,
    },

    [NATIONAL_DEX_MAGNEZONE] = 
    {
    },

    [NATIONAL_DEX_FARFETCHD] = 
    {
        .categoryName = _("WILD DUCK"),
        .description = gFarfetchdPokedexText,
        .height = 8,
        .pokemonOffset = 2,
        .pokemonScale = 330,
        .trainerOffset = 2,
        .trainerScale = 293,
        .weight = 150,
    },

    [NATIONAL_DEX_DODUO] = 
    {
        .categoryName = _("TWIN BIRD"),
        .description = gDoduoPokedexText,
        .height = 14,
        .pokemonOffset = 3,
        .pokemonScale = 256,
        .trainerOffset = -1,
        .trainerScale = 257,
        .weight = 392,
    },

    [NATIONAL_DEX_DODRIO] = 
    {
        .categoryName = _("TRIPLE BIRD"),
        .description = gDodrioPokedexText,
        .height = 18,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 268,
        .weight = 852,
    },

    [NATIONAL_DEX_SEEL] = 
    {
        .categoryName = _("SEA LION"),
        .description = gSeelPokedexText,
        .height = 11,
        .pokemonOffset = 8,
        .pokemonScale = 297,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 900,
    },

    [NATIONAL_DEX_DEWGONG] = 
    {
        .categoryName = _("SEA LION"),
        .description = gDewgongPokedexText,
        .height = 17,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 275,
        .weight = 1200,
    },

    [NATIONAL_DEX_GRIMER] = 
    {
        .categoryName = _("SLUDGE"),
        .description = gGrimerPokedexText,
        .height = 9,
        .pokemonOffset = 10,
        .pokemonScale = 258,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 300,
    },

    [NATIONAL_DEX_MUK] = 
    {
        .categoryName = _("SLUDGE"),
        .description = gMukPokedexText,
        .height = 12,
        .pokemonOffset = 2,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 300,
    },

    [NATIONAL_DEX_SHELLDER] = 
    {
        .categoryName = _("BIVALVE"),
        .description = gShellderPokedexText,
        .height = 3,
        .pokemonOffset = 24,
        .pokemonScale = 675,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 40,
    },

    [NATIONAL_DEX_CLOYSTER] = 
    {
        .categoryName = _("BIVALVE"),
        .description = gCloysterPokedexText,
        .height = 15,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 1,
        .trainerScale = 269,
        .weight = 1325,
    },

    [NATIONAL_DEX_GASTLY] = 
    {
        .categoryName = _("GAS"),
        .description = gGastlyPokedexText,
        .height = 13,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 1,
    },

    [NATIONAL_DEX_HAUNTER] = 
    {
        .categoryName = _("GAS"),
        .description = gHaunterPokedexText,
        .height = 16,
        .pokemonOffset = 2,
        .pokemonScale = 256,
        .trainerOffset = 2,
        .trainerScale = 293,
        .weight = 1,
    },

    [NATIONAL_DEX_GENGAR] = 
    {
        .categoryName = _("SHADOW"),
        .description = gGengarPokedexText,
        .height = 15,
        .pokemonOffset = 2,
        .pokemonScale = 256,
        .trainerOffset = 2,
        .trainerScale = 302,
        .weight = 405,
    },

    [NATIONAL_DEX_ONIX] = 
    {
        .categoryName = _("ROCK SNAKE"),
        .description = gOnixPokedexText,
        .height = 88,
        .pokemonOffset = 1,
        .pokemonScale = 256,
        .trainerOffset = 14,
        .trainerScale = 515,
        .weight = 2100,
    },

    [NATIONAL_DEX_STEELIX] = 
    {
        .categoryName = _("IRON SNAKE"),
        .description = gSteelixPokedexText,
        .height = 92,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 13,
        .trainerScale = 516,
        .weight = 4000,
    },

    [NATIONAL_DEX_DROWZEE] = 
    {
        .categoryName = _("HYPNOSIS"),
        .description = gDrowzeePokedexText,
        .height = 10,
        .pokemonOffset = 6,
        .pokemonScale = 274,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 324,
    },

    [NATIONAL_DEX_HYPNO] = 
    {
        .categoryName = _("HYPNOSIS"),
        .description = gHypnoPokedexText,
        .height = 16,
        .pokemonOffset = 3,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 257,
        .weight = 756,
    },

    [NATIONAL_DEX_KRABBY] = 
    {
        .categoryName = _("RIVER CRAB"),
        .description = gKrabbyPokedexText,
        .height = 4,
        .pokemonOffset = 20,
        .pokemonScale = 469,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 65,
    },

    [NATIONAL_DEX_KINGLER] = 
    {
        .categoryName = _("PINCER"),
        .description = gKinglerPokedexText,
        .height = 13,
        .pokemonOffset = 2,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 600,
    },

    [NATIONAL_DEX_VOLTORB] = 
    {
        .categoryName = _("BALL"),
        .description = gVoltorbPokedexText,
        .height = 5,
        .pokemonOffset = -8,
        .pokemonScale = 364,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 104,
    },

    [NATIONAL_DEX_ELECTRODE] = 
    {
        .categoryName = _("BALL"),
        .description = gElectrodePokedexText,
        .height = 12,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 666,
    },

    [NATIONAL_DEX_EXEGGCUTE] = 
    {
        .categoryName = _("EGG"),
        .description = gExeggcutePokedexText,
        .height = 4,
        .pokemonOffset = -4,
        .pokemonScale = 489,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 25,
    },

    [NATIONAL_DEX_EXEGGUTOR] = 
    {
        .categoryName = _("COCONUT"),
        .description = gExeggutorPokedexText,
        .height = 20,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 5,
        .trainerScale = 309,
        .weight = 1200,
    },

    [NATIONAL_DEX_CUBONE] = 
    {
        .categoryName = _("LONELY"),
        .description = gCubonePokedexText,
        .height = 4,
        .pokemonOffset = 21,
        .pokemonScale = 545,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 65,
    },

    [NATIONAL_DEX_MAROWAK] = 
    {
        .categoryName = _("BONE KEEPER"),
        .description = gMarowakPokedexText,
        .height = 10,
        .pokemonOffset = 12,
        .pokemonScale = 293,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 450,
    },

    [NATIONAL_DEX_TYROGUE] = 
    {
        .categoryName = _("SCUFFLE"),
        .description = gTyroguePokedexText,
        .height = 7,
        .pokemonOffset = 9,
        .pokemonScale = 292,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 210,
    },

    [NATIONAL_DEX_HITMONLEE] = 
    {
        .categoryName = _("KICKING"),
        .description = gHitmonleePokedexText,
        .height = 15,
        .pokemonOffset = 3,
        .pokemonScale = 256,
        .trainerOffset = 1,
        .trainerScale = 259,
        .weight = 498,
    },

    [NATIONAL_DEX_HITMONCHAN] = 
    {
        .categoryName = _("PUNCHING"),
        .description = gHitmonchanPokedexText,
        .height = 14,
        .pokemonOffset = 2,
        .pokemonScale = 256,
        .trainerOffset = 2,
        .trainerScale = 277,
        .weight = 502,
    },

    [NATIONAL_DEX_HITMONTOP] = 
    {
        .categoryName = _("HANDSTAND"),
        .description = gHitmontopPokedexText,
        .height = 14,
        .pokemonOffset = 2,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 257,
        .weight = 480,
    },

    [NATIONAL_DEX_LICKITUNG] = 
    {
        .categoryName = _("LICKING"),
        .description = gLickitungPokedexText,
        .height = 12,
        .pokemonOffset = 4,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 655,
    },

    [NATIONAL_DEX_LICKILICKY] = 
    {
    },

    [NATIONAL_DEX_KOFFING] = 
    {
        .categoryName = _("POISON GAS"),
        .description = gKoffingPokedexText,
        .height = 6,
        .pokemonOffset = -1,
        .pokemonScale = 369,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 10,
    },

    [NATIONAL_DEX_WEEZING] = 
    {
        .categoryName = _("POISON GAS"),
        .description = gWeezingPokedexText,
        .height = 12,
        .pokemonOffset = 3,
        .pokemonScale = 305,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 95,
    },

    [NATIONAL_DEX_RHYHORN] = 
    {
        .categoryName = _("SPIKES"),
        .description = gRhyhornPokedexText,
        .height = 10,
        .pokemonOffset = 6,
        .pokemonScale = 267,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 1150,
    },

    [NATIONAL_DEX_RHYDON] = 
    {
        .categoryName = _("DRILL"),
        .description = gRhydonPokedexText,
        .height = 19,
        .pokemonOffset = 1,
        .pokemonScale = 256,
        .trainerOffset = 2,
        .trainerScale = 299,
        .weight = 1200,
    },

    [NATIONAL_DEX_RHYPERIOR] = 
    {
    },

    [NATIONAL_DEX_HAPPINY] = 
    {
    },

    [NATIONAL_DEX_CHANSEY] = 
    {
        .categoryName = _("EGG"),
        .description = gChanseyPokedexText,
        .height = 11,
        .pokemonOffset = 7,
        .pokemonScale = 257,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 346,
    },

    [NATIONAL_DEX_BLISSEY] = 
    {
        .categoryName = _("HAPPINESS"),
        .description = gBlisseyPokedexText,
        .height = 15,
        .pokemonOffset = 4,
        .pokemonScale = 256,
        .trainerOffset = 3,
        .trainerScale = 310,
        .weight = 468,
    },

    [NATIONAL_DEX_TANGELA] = 
    {
        .categoryName = _("VINE"),
        .description = gTangelaPokedexText,
        .height = 10,
        .pokemonOffset = 1,
        .pokemonScale = 304,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 350,
    },

    [NATIONAL_DEX_TANGROWTH] = 
    {
    },

    [NATIONAL_DEX_KANGASKHAN] = 
    {
        .categoryName = _("PARENT"),
        .description = gKangaskhanPokedexText,
        .height = 22,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 8,
        .trainerScale = 387,
        .weight = 800,
    },

    [NATIONAL_DEX_HORSEA] = 
    {
        .categoryName = _("DRAGON"),
        .description = gHorseaPokedexText,
        .height = 4,
        .pokemonOffset = -1,
        .pokemonScale = 399,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 80,
    },

    [NATIONAL_DEX_SEADRA] = 
    {
        .categoryName = _("DRAGON"),
        .description = gSeadraPokedexText,
        .height = 12,
        .pokemonOffset = 3,
        .pokemonScale = 299,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 250,
    },

    [NATIONAL_DEX_KINGDRA] = 
    {
        .categoryName = _("DRAGON"),
        .description = gKingdraPokedexText,
        .height = 18,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 287,
        .weight = 1520,
    },

    [NATIONAL_DEX_GOLDEEN] = 
    {
        .categoryName = _("GOLDFISH"),
        .description = gGoldeenPokedexText,
        .height = 6,
        .pokemonOffset = 4,
        .pokemonScale = 379,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 150,
    },

    [NATIONAL_DEX_SEAKING] = 
    {
        .categoryName = _("GOLDFISH"),
        .description = gSeakingPokedexText,
        .height = 13,
        .pokemonOffset = 3,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 390,
    },

    [NATIONAL_DEX_STARYU] = 
    {
        .categoryName = _("STAR SHAPE"),
        .description = gStaryuPokedexText,
        .height = 8,
        .pokemonOffset = 1,
        .pokemonScale = 326,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 345,
    },

    [NATIONAL_DEX_STARMIE] = 
    {
        .categoryName = _("MYSTERIOUS"),
        .description = gStarmiePokedexText,
        .height = 11,
        .pokemonOffset = 3,
        .pokemonScale = 301,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 800,
    },

    [NATIONAL_DEX_MIMEJR] = 
    {
    },

    [NATIONAL_DEX_MR_MIME] = 
    {
        .categoryName = _("BARRIER"),
        .description = gMrmimePokedexText,
        .height = 13,
        .pokemonOffset = 6,
        .pokemonScale = 258,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 545,
    },

    [NATIONAL_DEX_SCYTHER] = 
    {
        .categoryName = _("MANTIS"),
        .description = gScytherPokedexText,
        .height = 15,
        .pokemonOffset = 1,
        .pokemonScale = 256,
        .trainerOffset = 2,
        .trainerScale = 293,
        .weight = 560,
    },

    [NATIONAL_DEX_SCIZOR] = 
    {
        .categoryName = _("PINCER"),
        .description = gScizorPokedexText,
        .height = 18,
        .pokemonOffset = 1,
        .pokemonScale = 278,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 1180,
    },

    [NATIONAL_DEX_SMOOCHUM] = 
    {
        .categoryName = _("KISS"),
        .description = gSmoochumPokedexText,
        .height = 4,
        .pokemonOffset = 20,
        .pokemonScale = 440,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 60,
    },

    [NATIONAL_DEX_JYNX] = 
    {
        .categoryName = _("HUMAN SHAPE"),
        .description = gJynxPokedexText,
        .height = 14,
        .pokemonOffset = 3,
        .pokemonScale = 256,
        .trainerOffset = 1,
        .trainerScale = 300,
        .weight = 406,
    },

    [NATIONAL_DEX_ELEKID] = 
    {
        .categoryName = _("ELECTRIC"),
        .description = gElekidPokedexText,
        .height = 6,
        .pokemonOffset = 14,
        .pokemonScale = 363,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 235,
    },

    [NATIONAL_DEX_ELECTABUZZ] = 
    {
        .categoryName = _("ELECTRIC"),
        .description = gElectabuzzPokedexText,
        .height = 11,
        .pokemonOffset = 8,
        .pokemonScale = 351,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 300,
    },

    [NATIONAL_DEX_ELECTIVIRE] = 
    {
    },

    [NATIONAL_DEX_MAGBY] = 
    {
        .categoryName = _("LIVE COAL"),
        .description = gMagbyPokedexText,
        .height = 7,
        .pokemonOffset = 13,
        .pokemonScale = 284,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 214,
    },

    [NATIONAL_DEX_MAGMAR] = 
    {
        .categoryName = _("SPITFIRE"),
        .description = gMagmarPokedexText,
        .height = 13,
        .pokemonOffset = 5,
        .pokemonScale = 277,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 445,
    },

    [NATIONAL_DEX_MAGMORTAR] = 
    {
    },

    [NATIONAL_DEX_PINSIR] = 
    {
        .categoryName = _("STAG BEETLE"),
        .description = gPinsirPokedexText,
        .height = 15,
        .pokemonOffset = 2,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 257,
        .weight = 550,
    },

    [NATIONAL_DEX_TAUROS] = 
    {
        .categoryName = _("WILD BULL"),
        .description = gTaurosPokedexText,
        .height = 14,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 884,
    },

    [NATIONAL_DEX_MAGIKARP] = 
    {
        .categoryName = _("FISH"),
        .description = gMagikarpPokedexText,
        .height = 9,
        .pokemonOffset = 4,
        .pokemonScale = 310,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 100,
    },

    [NATIONAL_DEX_GYARADOS] = 
    {
        .categoryName = _("ATROCIOUS"),
        .description = gGyaradosPokedexText,
        .height = 65,
        .pokemonOffset = 6,
        .pokemonScale = 256,
        .trainerOffset = 13,
        .trainerScale = 481,
        .weight = 2350,
    },

    [NATIONAL_DEX_LAPRAS] = 
    {
        .categoryName = _("TRANSPORT"),
        .description = gLaprasPokedexText,
        .height = 25,
        .pokemonOffset = 10,
        .pokemonScale = 257,
        .trainerOffset = 8,
        .trainerScale = 423,
        .weight = 2200,
    },

    [NATIONAL_DEX_DITTO] = 
    {
        .categoryName = _("TRANSFORM"),
        .description = gDittoPokedexText,
        .height = 3,
        .pokemonOffset = 23,
        .pokemonScale = 633,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 40,
    },

    [NATIONAL_DEX_EEVEE] = 
    {
        .categoryName = _("EVOLUTION"),
        .description = gEeveePokedexText,
        .height = 3,
        .pokemonOffset = 18,
        .pokemonScale = 476,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 65,
    },

    [NATIONAL_DEX_VAPOREON] = 
    {
        .categoryName = _("BUBBLE JET"),
        .description = gVaporeonPokedexText,
        .height = 10,
        .pokemonOffset = 8,
        .pokemonScale = 316,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 290,
    },

    [NATIONAL_DEX_JOLTEON] = 
    {
        .categoryName = _("LIGHTNING"),
        .description = gJolteonPokedexText,
        .height = 8,
        .pokemonOffset = 8,
        .pokemonScale = 283,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 245,
    },

    [NATIONAL_DEX_FLAREON] = 
    {
        .categoryName = _("FLAME"),
        .description = gFlareonPokedexText,
        .height = 9,
        .pokemonOffset = 12,
        .pokemonScale = 306,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 250,
    },

    [NATIONAL_DEX_ESPEON] = 
    {
        .categoryName = _("SUN"),
        .description = gEspeonPokedexText,
        .height = 9,
        .pokemonOffset = 14,
        .pokemonScale = 363,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 265,
    },

    [NATIONAL_DEX_UMBREON] = 
    {
        .categoryName = _("MOONLIGHT"),
        .description = gUmbreonPokedexText,
        .height = 10,
        .pokemonOffset = 11,
        .pokemonScale = 317,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 270,
    },

    [NATIONAL_DEX_LEAFEON] = 
    {
    },

    [NATIONAL_DEX_GLACEON] = 
    {
    },

    [NATIONAL_DEX_SYLVEON] = 
    {
    },

    [NATIONAL_DEX_PORYGON] = 
    {
        .categoryName = _("VIRTUAL"),
        .description = gPorygonPokedexText,
        .height = 8,
        .pokemonOffset = 15,
        .pokemonScale = 328,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 365,
    },

    [NATIONAL_DEX_PORYGON2] = 
    {
        .categoryName = _("VIRTUAL"),
        .description = gPorygon2PokedexText,
        .height = 6,
        .pokemonOffset = 17,
        .pokemonScale = 320,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 325,
    },

    [NATIONAL_DEX_PORYGON_Z] = 
    {
    },

    [NATIONAL_DEX_OMANYTE] = 
    {
        .categoryName = _("SPIRAL"),
        .description = gOmanytePokedexText,
        .height = 4,
        .pokemonOffset = 22,
        .pokemonScale = 521,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 75,
    },

    [NATIONAL_DEX_OMASTAR] = 
    {
        .categoryName = _("SPIRAL"),
        .description = gOmastarPokedexText,
        .height = 10,
        .pokemonOffset = 7,
        .pokemonScale = 307,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 350,
    },

    [NATIONAL_DEX_KABUTO] = 
    {
        .categoryName = _("SHELLFISH"),
        .description = gKabutoPokedexText,
        .height = 5,
        .pokemonOffset = 21,
        .pokemonScale = 454,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 115,
    },

    [NATIONAL_DEX_KABUTOPS] = 
    {
        .categoryName = _("SHELLFISH"),
        .description = gKabutopsPokedexText,
        .height = 13,
        .pokemonOffset = 3,
        .pokemonScale = 271,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 405,
    },

    [NATIONAL_DEX_AERODACTYL] = 
    {
        .categoryName = _("FOSSIL"),
        .description = gAerodactylPokedexText,
        .height = 18,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 4,
        .trainerScale = 302,
        .weight = 590,
    },

    [NATIONAL_DEX_MUNCHLAX] = 
    {
    },

    [NATIONAL_DEX_SNORLAX] = 
    {
        .categoryName = _("SLEEPING"),
        .description = gSnorlaxPokedexText,
        .height = 21,
        .pokemonOffset = 4,
        .pokemonScale = 256,
        .trainerOffset = 11,
        .trainerScale = 423,
        .weight = 4600,
    },

    [NATIONAL_DEX_ARTICUNO] = 
    {
        .categoryName = _("FREEZE"),
        .description = gArticunoPokedexText,
        .height = 17,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 2,
        .trainerScale = 309,
        .weight = 554,
    },

    [NATIONAL_DEX_ZAPDOS] = 
    {
        .categoryName = _("ELECTRIC"),
        .description = gZapdosPokedexText,
        .height = 16,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 3,
        .trainerScale = 318,
        .weight = 526,
    },

    [NATIONAL_DEX_MOLTRES] = 
    {
        .categoryName = _("FLAME"),
        .description = gMoltresPokedexText,
        .height = 20,
        .pokemonOffset = 0,
        .pokemonScale = 270,
        .trainerOffset = 8,
        .trainerScale = 387,
        .weight = 600,
    },

    [NATIONAL_DEX_DRATINI] = 
    {
        .categoryName = _("DRAGON"),
        .description = gDratiniPokedexText,
        .height = 18,
        .pokemonOffset = 8,
        .pokemonScale = 256,
        .trainerOffset = 6,
        .trainerScale = 386,
        .weight = 33,
    },

    [NATIONAL_DEX_DRAGONAIR] = 
    {
        .categoryName = _("DRAGON"),
        .description = gDragonairPokedexText,
        .height = 40,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 5,
        .trainerScale = 411,
        .weight = 165,
    },

    [NATIONAL_DEX_DRAGONITE] = 
    {
        .categoryName = _("DRAGON"),
        .description = gDragonitePokedexText,
        .height = 22,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 4,
        .trainerScale = 309,
        .weight = 2100,
    },

    [NATIONAL_DEX_MEWTWO] = 
    {
        .categoryName = _("GENETIC"),
        .description = gMewtwoPokedexText,
        .height = 20,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 4,
        .trainerScale = 309,
        .weight = 1220,
    },

    [NATIONAL_DEX_MEW] = 
    {
        .categoryName = _("NEW SPECIES"),
        .description = gMewPokedexText,
        .height = 4,
        .pokemonOffset = -2,
        .pokemonScale = 457,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 40,
    },

    [NATIONAL_DEX_CHIKORITA] = 
    {
        .categoryName = _("LEAF"),
        .description = gChikoritaPokedexText,
        .height = 9,
        .pokemonOffset = 20,
        .pokemonScale = 512,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 64,
    },

    [NATIONAL_DEX_BAYLEEF] = 
    {
        .categoryName = _("LEAF"),
        .description = gBayleefPokedexText,
        .height = 12,
        .pokemonOffset = 4,
        .pokemonScale = 296,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 158,
    },

    [NATIONAL_DEX_MEGANIUM] = 
    {
        .categoryName = _("HERB"),
        .description = gMeganiumPokedexText,
        .height = 18,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 1,
        .trainerScale = 277,
        .weight = 1005,
    },

    [NATIONAL_DEX_CYNDAQUIL] = 
    {
        .categoryName = _("FIRE MOUSE"),
        .description = gCyndaquilPokedexText,
        .height = 5,
        .pokemonOffset = 21,
        .pokemonScale = 539,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 79,
    },

    [NATIONAL_DEX_QUILAVA] = 
    {
        .categoryName = _("VOLCANO"),
        .description = gQuilavaPokedexText,
        .height = 9,
        .pokemonOffset = 11,
        .pokemonScale = 329,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 190,
    },

    [NATIONAL_DEX_TYPHLOSION] = 
    {
        .categoryName = _("VOLCANO"),
        .description = gTyphlosionPokedexText,
        .height = 17,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 1,
        .trainerScale = 268,
        .weight = 795,
    },

    [NATIONAL_DEX_TOTODILE] = 
    {
        .categoryName = _("BIG JAW"),
        .description = gTotodilePokedexText,
        .height = 6,
        .pokemonOffset = 20,
        .pokemonScale = 487,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 95,
    },

    [NATIONAL_DEX_CROCONAW] = 
    {
        .categoryName = _("BIG JAW"),
        .description = gCroconawPokedexText,
        .height = 11,
        .pokemonOffset = 13,
        .pokemonScale = 378,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 250,
    },

    [NATIONAL_DEX_FERALIGATR] = 
    {
        .categoryName = _("BIG JAW"),
        .description = gFeraligatrPokedexText,
        .height = 23,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 7,
        .trainerScale = 342,
        .weight = 888,
    },

    [NATIONAL_DEX_SENTRET] = 
    {
        .categoryName = _("SCOUT"),
        .description = gSentretPokedexText,
        .height = 8,
        .pokemonOffset = 12,
        .pokemonScale = 439,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 60,
    },

    [NATIONAL_DEX_FURRET] = 
    {
        .categoryName = _("LONG BODY"),
        .description = gFurretPokedexText,
        .height = 18,
        .pokemonOffset = 11,
        .pokemonScale = 346,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 325,
    },

    [NATIONAL_DEX_HOOTHOOT] = 
    {
        .categoryName = _("OWL"),
        .description = gHoothootPokedexText,
        .height = 7,
        .pokemonOffset = -2,
        .pokemonScale = 380,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 212,
    },

    [NATIONAL_DEX_NOCTOWL] = 
    {
        .categoryName = _("OWL"),
        .description = gNoctowlPokedexText,
        .height = 16,
        .pokemonOffset = 3,
        .pokemonScale = 278,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 408,
    },

    [NATIONAL_DEX_LEDYBA] = 
    {
        .categoryName = _("FIVE STAR"),
        .description = gLedybaPokedexText,
        .height = 10,
        .pokemonOffset = 4,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 108,
    },

    [NATIONAL_DEX_LEDIAN] = 
    {
        .categoryName = _("FIVE STAR"),
        .description = gLedianPokedexText,
        .height = 14,
        .pokemonOffset = 2,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 356,
    },

    [NATIONAL_DEX_SPINARAK] = 
    {
        .categoryName = _("STRING SPIT"),
        .description = gSpinarakPokedexText,
        .height = 5,
        .pokemonOffset = 21,
        .pokemonScale = 414,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 85,
    },

    [NATIONAL_DEX_ARIADOS] = 
    {
        .categoryName = _("LONG LEG"),
        .description = gAriadosPokedexText,
        .height = 11,
        .pokemonOffset = 8,
        .pokemonScale = 316,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 335,
    },

    [NATIONAL_DEX_CHINCHOU] = 
    {
        .categoryName = _("ANGLER"),
        .description = gChinchouPokedexText,
        .height = 5,
        .pokemonOffset = -2,
        .pokemonScale = 424,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 120,
    },

    [NATIONAL_DEX_LANTURN] = 
    {
        .categoryName = _("LIGHT"),
        .description = gLanturnPokedexText,
        .height = 12,
        .pokemonOffset = 6,
        .pokemonScale = 269,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 225,
    },

    [NATIONAL_DEX_TOGEPI] = 
    {
        .categoryName = _("SPIKE BALL"),
        .description = gTogepiPokedexText,
        .height = 3,
        .pokemonOffset = 23,
        .pokemonScale = 507,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 15,
    },

    [NATIONAL_DEX_TOGETIC] = 
    {
        .categoryName = _("HAPPINESS"),
        .description = gTogeticPokedexText,
        .height = 6,
        .pokemonOffset = 17,
        .pokemonScale = 424,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 32,
    },

    [NATIONAL_DEX_TOGEKISS] = 
    {
    },

    [NATIONAL_DEX_NATU] = 
    {
        .categoryName = _("TINY BIRD"),
        .description = gNatuPokedexText,
        .height = 2,
        .pokemonOffset = 25,
        .pokemonScale = 610,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 20,
    },

    [NATIONAL_DEX_XATU] = 
    {
        .categoryName = _("MYSTIC"),
        .description = gXatuPokedexText,
        .height = 15,
        .pokemonOffset = 6,
        .pokemonScale = 256,
        .trainerOffset = 4,
        .trainerScale = 318,
        .weight = 150,
    },

    [NATIONAL_DEX_MAREEP] = 
    {
        .categoryName = _("WOOL"),
        .description = gMareepPokedexText,
        .height = 6,
        .pokemonOffset = 18,
        .pokemonScale = 379,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 78,
    },

    [NATIONAL_DEX_FLAAFFY] = 
    {
        .categoryName = _("WOOL"),
        .description = gFlaaffyPokedexText,
        .height = 8,
        .pokemonOffset = 15,
        .pokemonScale = 372,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 133,
    },

    [NATIONAL_DEX_AMPHAROS] = 
    {
        .categoryName = _("LIGHT"),
        .description = gAmpharosPokedexText,
        .height = 14,
        .pokemonOffset = 4,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 615,
    },

    [NATIONAL_DEX_AZURILL] = 
    {
        .categoryName = _("POLKA DOT"),
        .description = gAzurillPokedexText,
        .height = 2,
        .pokemonOffset = 23,
        .pokemonScale = 603,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 20,
    },

    [NATIONAL_DEX_MARILL] = 
    {
        .categoryName = _("AQUA MOUSE"),
        .description = gMarillPokedexText,
        .height = 4,
        .pokemonOffset = 20,
        .pokemonScale = 476,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 85,
    },

    [NATIONAL_DEX_AZUMARILL] = 
    {
        .categoryName = _("AQUA RABBIT"),
        .description = gAzumarillPokedexText,
        .height = 8,
        .pokemonOffset = 16,
        .pokemonScale = 448,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 285,
    },

    [NATIONAL_DEX_BONSLY] = 
    {
    },

    [NATIONAL_DEX_SUDOWOODO] = 
    {
        .categoryName = _("IMITATION"),
        .description = gSudowoodoPokedexText,
        .height = 12,
        .pokemonOffset = 8,
        .pokemonScale = 305,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 380,
    },

    [NATIONAL_DEX_HOPPIP] = 
    {
        .categoryName = _("COTTONWEED"),
        .description = gHoppipPokedexText,
        .height = 4,
        .pokemonOffset = -7,
        .pokemonScale = 562,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 5,
    },

    [NATIONAL_DEX_SKIPLOOM] = 
    {
        .categoryName = _("COTTONWEED"),
        .description = gSkiploomPokedexText,
        .height = 6,
        .pokemonOffset = 0,
        .pokemonScale = 387,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 10,
    },

    [NATIONAL_DEX_JUMPLUFF] = 
    {
        .categoryName = _("COTTONWEED"),
        .description = gJumpluffPokedexText,
        .height = 8,
        .pokemonOffset = -4,
        .pokemonScale = 418,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 30,
    },

    [NATIONAL_DEX_AIPOM] = 
    {
        .categoryName = _("LONG TAIL"),
        .description = gAipomPokedexText,
        .height = 8,
        .pokemonOffset = 6,
        .pokemonScale = 363,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 115,
    },

    [NATIONAL_DEX_AMBIPOM] = 
    {
    },

    [NATIONAL_DEX_SUNKERN] = 
    {
        .categoryName = _("SEED"),
        .description = gSunkernPokedexText,
        .height = 3,
        .pokemonOffset = 0,
        .pokemonScale = 541,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 18,
    },

    [NATIONAL_DEX_SUNFLORA] = 
    {
        .categoryName = _("SUN"),
        .description = gSunfloraPokedexText,
        .height = 8,
        .pokemonOffset = 15,
        .pokemonScale = 444,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 85,
    },

    [NATIONAL_DEX_YANMA] = 
    {
        .categoryName = _("CLEAR WING"),
        .description = gYanmaPokedexText,
        .height = 12,
        .pokemonOffset = -1,
        .pokemonScale = 274,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 380,
    },

    [NATIONAL_DEX_YANMEGA] = 
    {
    },

    [NATIONAL_DEX_WOOPER] = 
    {
        .categoryName = _("WATER FISH"),
        .description = gWooperPokedexText,
        .height = 4,
        .pokemonOffset = 21,
        .pokemonScale = 479,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 85,
    },

    [NATIONAL_DEX_QUAGSIRE] = 
    {
        .categoryName = _("WATER FISH"),
        .description = gQuagsirePokedexText,
        .height = 14,
        .pokemonOffset = 4,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 750,
    },

    [NATIONAL_DEX_MURKROW] = 
    {
        .categoryName = _("DARKNESS"),
        .description = gMurkrowPokedexText,
        .height = 5,
        .pokemonOffset = -8,
        .pokemonScale = 401,
        .trainerOffset = 1,
        .trainerScale = 256,
        .weight = 21,
    },

    [NATIONAL_DEX_HONCHKROW] = 
    {
    },

    [NATIONAL_DEX_MISDREAVUS] = 
    {
        .categoryName = _("SCREECH"),
        .description = gMisdreavusPokedexText,
        .height = 7,
        .pokemonOffset = -8,
        .pokemonScale = 407,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 10,
    },

    [NATIONAL_DEX_MISMAGIUS] = 
    {
    },

    [NATIONAL_DEX_UNOWN] = 
    {
        .categoryName = _("SYMBOL"),
        .description = gUnownPokedexText,
        .height = 5,
        .pokemonOffset = 2,
        .pokemonScale = 411,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 50,
    },

    [NATIONAL_DEX_WYNAUT] = 
    {
        .categoryName = _("BRIGHT"),
        .description = gWynautPokedexText,
        .height = 6,
        .pokemonOffset = 19,
        .pokemonScale = 484,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 140,
    },

    [NATIONAL_DEX_WOBBUFFET] = 
    {
        .categoryName = _("PATIENT"),
        .description = gWobbuffetPokedexText,
        .height = 13,
        .pokemonOffset = 4,
        .pokemonScale = 274,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 285,
    },

    [NATIONAL_DEX_GIRAFARIG] = 
    {
        .categoryName = _("LONG NECK"),
        .description = gGirafarigPokedexText,
        .height = 15,
        .pokemonOffset = 1,
        .pokemonScale = 281,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 415,
    },

    [NATIONAL_DEX_PINECO] = 
    {
        .categoryName = _("BAGWORM"),
        .description = gPinecoPokedexText,
        .height = 6,
        .pokemonOffset = 2,
        .pokemonScale = 445,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 72,
    },

    [NATIONAL_DEX_FORRETRESS] = 
    {
        .categoryName = _("BAGWORM"),
        .description = gForretressPokedexText,
        .height = 12,
        .pokemonOffset = 5,
        .pokemonScale = 293,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 1258,
    },

    [NATIONAL_DEX_DUNSPARCE] = 
    {
        .categoryName = _("LAND SNAKE"),
        .description = gDunsparcePokedexText,
        .height = 15,
        .pokemonOffset = 17,
        .pokemonScale = 316,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 140,
    },

    [NATIONAL_DEX_GLIGAR] = 
    {
        .categoryName = _("FLYSCORPION"),
        .description = gGligarPokedexText,
        .height = 11,
        .pokemonOffset = -1,
        .pokemonScale = 350,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 648,
    },

    [NATIONAL_DEX_GLISCOR] = 
    {
    },

    [NATIONAL_DEX_SNUBBULL] = 
    {
        .categoryName = _("FAIRY"),
        .description = gSnubbullPokedexText,
        .height = 6,
        .pokemonOffset = 19,
        .pokemonScale = 465,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 78,
    },

    [NATIONAL_DEX_GRANBULL] = 
    {
        .categoryName = _("FAIRY"),
        .description = gGranbullPokedexText,
        .height = 14,
        .pokemonOffset = 4,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 487,
    },

    [NATIONAL_DEX_QWILFISH] = 
    {
        .categoryName = _("BALLOON"),
        .description = gQwilfishPokedexText,
        .height = 5,
        .pokemonOffset = 0,
        .pokemonScale = 430,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 39,
    },

    [NATIONAL_DEX_SHUCKLE] = 
    {
        .categoryName = _("MOLD"),
        .description = gShucklePokedexText,
        .height = 6,
        .pokemonOffset = 18,
        .pokemonScale = 485,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 205,
    },

    [NATIONAL_DEX_HERACROSS] = 
    {
        .categoryName = _("SINGLE HORN"),
        .description = gHeracrossPokedexText,
        .height = 15,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 540,
    },

    [NATIONAL_DEX_SNEASEL] = 
    {
        .categoryName = _("SHARP CLAW"),
        .description = gSneaselPokedexText,
        .height = 9,
        .pokemonOffset = -3,
        .pokemonScale = 413,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 280,
    },

    [NATIONAL_DEX_WEAVILE] = 
    {
    },

    [NATIONAL_DEX_TEDDIURSA] = 
    {
        .categoryName = _("LITTLE BEAR"),
        .description = gTeddiursaPokedexText,
        .height = 6,
        .pokemonOffset = 19,
        .pokemonScale = 455,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 88,
    },

    [NATIONAL_DEX_URSARING] = 
    {
        .categoryName = _("HIBERNATOR"),
        .description = gUrsaringPokedexText,
        .height = 18,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 1258,
    },

    [NATIONAL_DEX_SLUGMA] = 
    {
        .categoryName = _("LAVA"),
        .description = gSlugmaPokedexText,
        .height = 7,
        .pokemonOffset = 15,
        .pokemonScale = 329,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 350,
    },

    [NATIONAL_DEX_MAGCARGO] = 
    {
        .categoryName = _("LAVA"),
        .description = gMagcargoPokedexText,
        .height = 8,
        .pokemonOffset = 15,
        .pokemonScale = 332,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 550,
    },

    [NATIONAL_DEX_SWINUB] = 
    {
        .categoryName = _("PIG"),
        .description = gSwinubPokedexText,
        .height = 4,
        .pokemonOffset = 20,
        .pokemonScale = 324,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 65,
    },

    [NATIONAL_DEX_PILOSWINE] = 
    {
        .categoryName = _("SWINE"),
        .description = gPiloswinePokedexText,
        .height = 11,
        .pokemonOffset = 10,
        .pokemonScale = 306,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 558,
    },

    [NATIONAL_DEX_MAMOSWINE] = 
    {
    },

    [NATIONAL_DEX_CORSOLA] = 
    {
        .categoryName = _("CORAL"),
        .description = gCorsolaPokedexText,
        .height = 6,
        .pokemonOffset = 15,
        .pokemonScale = 410,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 50,
    },

    [NATIONAL_DEX_REMORAID] = 
    {
        .categoryName = _("JET"),
        .description = gRemoraidPokedexText,
        .height = 6,
        .pokemonOffset = 4,
        .pokemonScale = 316,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 120,
    },

    [NATIONAL_DEX_OCTILLERY] = 
    {
        .categoryName = _("JET"),
        .description = gOctilleryPokedexText,
        .height = 9,
        .pokemonOffset = 3,
        .pokemonScale = 296,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 285,
    },

    [NATIONAL_DEX_DELIBIRD] = 
    {
        .categoryName = _("DELIVERY"),
        .description = gDelibirdPokedexText,
        .height = 9,
        .pokemonOffset = 11,
        .pokemonScale = 293,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 160,
    },

    [NATIONAL_DEX_MANTYKE] = 
    {
    },

    [NATIONAL_DEX_MANTINE] = 
    {
        .categoryName = _("KITE"),
        .description = gMantinePokedexText,
        .height = 21,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 7,
        .trainerScale = 342,
        .weight = 2200,
    },

    [NATIONAL_DEX_SKARMORY] = 
    {
        .categoryName = _("ARMOR BIRD"),
        .description = gSkarmoryPokedexText,
        .height = 17,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 1,
        .trainerScale = 271,
        .weight = 505,
    },

    [NATIONAL_DEX_HOUNDOUR] = 
    {
        .categoryName = _("DARK"),
        .description = gHoundourPokedexText,
        .height = 6,
        .pokemonOffset = 16,
        .pokemonScale = 393,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 108,
    },

    [NATIONAL_DEX_HOUNDOOM] = 
    {
        .categoryName = _("DARK"),
        .description = gHoundoomPokedexText,
        .height = 14,
        .pokemonOffset = 4,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 350,
    },

    [NATIONAL_DEX_PHANPY] = 
    {
        .categoryName = _("LONG NOSE"),
        .description = gPhanpyPokedexText,
        .height = 5,
        .pokemonOffset = 21,
        .pokemonScale = 465,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 335,
    },

    [NATIONAL_DEX_DONPHAN] = 
    {
        .categoryName = _("ARMOR"),
        .description = gDonphanPokedexText,
        .height = 11,
        .pokemonOffset = 9,
        .pokemonScale = 313,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 1200,
    },

    [NATIONAL_DEX_STANTLER] = 
    {
        .categoryName = _("BIG HORN"),
        .description = gStantlerPokedexText,
        .height = 14,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 712,
    },

    [NATIONAL_DEX_SMEARGLE] = 
    {
        .categoryName = _("PAINTER"),
        .description = gSmearglePokedexText,
        .height = 12,
        .pokemonOffset = 5,
        .pokemonScale = 287,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 580,
    },

    [NATIONAL_DEX_MILTANK] = 
    {
        .categoryName = _("MILK COW"),
        .description = gMiltankPokedexText,
        .height = 12,
        .pokemonOffset = 5,
        .pokemonScale = 280,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 755,
    },

    [NATIONAL_DEX_RAIKOU] = 
    {
        .categoryName = _("THUNDER"),
        .description = gRaikouPokedexText,
        .height = 19,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 7,
        .trainerScale = 345,
        .weight = 1780,
    },

    [NATIONAL_DEX_ENTEI] = 
    {
        .categoryName = _("VOLCANO"),
        .description = gEnteiPokedexText,
        .height = 21,
        .pokemonOffset = 0,
        .pokemonScale = 259,
        .trainerOffset = 7,
        .trainerScale = 345,
        .weight = 1980,
    },

    [NATIONAL_DEX_SUICUNE] = 
    {
        .categoryName = _("AURORA"),
        .description = gSuicunePokedexText,
        .height = 20,
        .pokemonOffset = 0,
        .pokemonScale = 269,
        .trainerOffset = 7,
        .trainerScale = 345,
        .weight = 1870,
    },

    [NATIONAL_DEX_LARVITAR] = 
    {
        .categoryName = _("ROCK SKIN"),
        .description = gLarvitarPokedexText,
        .height = 6,
        .pokemonOffset = 18,
        .pokemonScale = 472,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 720,
    },

    [NATIONAL_DEX_PUPITAR] = 
    {
        .categoryName = _("HARD SHELL"),
        .description = gPupitarPokedexText,
        .height = 12,
        .pokemonOffset = 8,
        .pokemonScale = 292,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 1520,
    },

    [NATIONAL_DEX_TYRANITAR] = 
    {
        .categoryName = _("ARMOR"),
        .description = gTyranitarPokedexText,
        .height = 20,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 7,
        .trainerScale = 345,
        .weight = 2020,
    },

    [NATIONAL_DEX_LUGIA] = 
    {
        .categoryName = _("DIVING"),
        .description = gLugiaPokedexText,
        .height = 52,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 19,
        .trainerScale = 721,
        .weight = 2160,
    },

    [NATIONAL_DEX_HO_OH] = 
    {
        .categoryName = _("RAINBOW"),
        .description = gHoOhPokedexText,
        .height = 38,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 17,
        .trainerScale = 610,
        .weight = 1990,
    },

    [NATIONAL_DEX_CELEBI] = 
    {
        .categoryName = _("TIME TRAVEL"),
        .description = gCelebiPokedexText,
        .height = 6,
        .pokemonOffset = -10,
        .pokemonScale = 393,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 50,
    },

    [NATIONAL_DEX_TREECKO] = 
    {
        .categoryName = _("WOOD GECKO"),
        .description = gTreeckoPokedexText,
        .height = 5,
        .pokemonOffset = 19,
        .pokemonScale = 541,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 50,
    },

    [NATIONAL_DEX_GROVYLE] = 
    {
        .categoryName = _("WOOD GECKO"),
        .description = gGrovylePokedexText,
        .height = 9,
        .pokemonOffset = 5,
        .pokemonScale = 360,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 216,
    },

    [NATIONAL_DEX_SCEPTILE] = 
    {
        .categoryName = _("FOREST"),
        .description = gSceptilePokedexText,
        .height = 17,
        .pokemonOffset = -1,
        .pokemonScale = 256,
        .trainerOffset = 2,
        .trainerScale = 275,
        .weight = 522,
    },

    [NATIONAL_DEX_TORCHIC] = 
    {
        .categoryName = _("CHICK"),
        .description = gTorchicPokedexText,
        .height = 4,
        .pokemonOffset = 19,
        .pokemonScale = 566,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 25,
    },

    [NATIONAL_DEX_COMBUSKEN] = 
    {
        .categoryName = _("YOUNG FOWL"),
        .description = gCombuskenPokedexText,
        .height = 9,
        .pokemonOffset = 5,
        .pokemonScale = 343,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 195,
    },

    [NATIONAL_DEX_BLAZIKEN] = 
    {
        .categoryName = _("BLAZE"),
        .description = gBlazikenPokedexText,
        .height = 19,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 4,
        .trainerScale = 301,
        .weight = 520,
    },

    [NATIONAL_DEX_MUDKIP] = 
    {
        .categoryName = _("MUD FISH"),
        .description = gMudkipPokedexText,
        .height = 4,
        .pokemonOffset = 20,
        .pokemonScale = 535,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 76,
    },

    [NATIONAL_DEX_MARSHTOMP] = 
    {
        .categoryName = _("MUD FISH"),
        .description = gMarshtompPokedexText,
        .height = 7,
        .pokemonOffset = 7,
        .pokemonScale = 340,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 280,
    },

    [NATIONAL_DEX_SWAMPERT] = 
    {
        .categoryName = _("MUD FISH"),
        .description = gSwampertPokedexText,
        .height = 15,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 819,
    },

    [NATIONAL_DEX_POOCHYENA] = 
    {
        .categoryName = _("BITE"),
        .description = gPoochyenaPokedexText,
        .height = 5,
        .pokemonOffset = 19,
        .pokemonScale = 481,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 136,
    },

    [NATIONAL_DEX_MIGHTYENA] = 
    {
        .categoryName = _("BITE"),
        .description = gMightyenaPokedexText,
        .height = 10,
        .pokemonOffset = 9,
        .pokemonScale = 362,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 370,
    },

    [NATIONAL_DEX_ZIGZAGOON] = 
    {
        .categoryName = _("TINYRACCOON"),
        .description = gZigzagoonPokedexText,
        .height = 4,
        .pokemonOffset = 22,
        .pokemonScale = 560,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 175,
    },

    [NATIONAL_DEX_LINOONE] = 
    {
        .categoryName = _("RUSHING"),
        .description = gLinoonePokedexText,
        .height = 5,
        .pokemonOffset = 7,
        .pokemonScale = 321,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 325,
    },

    [NATIONAL_DEX_WURMPLE] = 
    {
        .categoryName = _("WORM"),
        .description = gWurmplePokedexText,
        .height = 3,
        .pokemonOffset = 24,
        .pokemonScale = 711,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 36,
    },

    [NATIONAL_DEX_SILCOON] = 
    {
        .categoryName = _("COCOON"),
        .description = gSilcoonPokedexText,
        .height = 6,
        .pokemonOffset = 19,
        .pokemonScale = 431,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 100,
    },

    [NATIONAL_DEX_BEAUTIFLY] = 
    {
        .categoryName = _("BUTTERFLY"),
        .description = gBeautiflyPokedexText,
        .height = 10,
        .pokemonOffset = -1,
        .pokemonScale = 298,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 284,
    },

    [NATIONAL_DEX_CASCOON] = 
    {
        .categoryName = _("COCOON"),
        .description = gCascoonPokedexText,
        .height = 7,
        .pokemonOffset = 20,
        .pokemonScale = 391,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 115,
    },

    [NATIONAL_DEX_DUSTOX] = 
    {
        .categoryName = _("POISON MOTH"),
        .description = gDustoxPokedexText,
        .height = 12,
        .pokemonOffset = 1,
        .pokemonScale = 269,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 316,
    },

    [NATIONAL_DEX_LOTAD] = 
    {
        .categoryName = _("WATER WEED"),
        .description = gLotadPokedexText,
        .height = 5,
        .pokemonOffset = 19,
        .pokemonScale = 406,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 26,
    },

    [NATIONAL_DEX_LOMBRE] = 
    {
        .categoryName = _("JOLLY"),
        .description = gLombrePokedexText,
        .height = 12,
        .pokemonOffset = 9,
        .pokemonScale = 277,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 325,
    },

    [NATIONAL_DEX_LUDICOLO] = 
    {
        .categoryName = _("CAREFREE"),
        .description = gLudicoloPokedexText,
        .height = 15,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = -1,
        .trainerScale = 268,
        .weight = 550,
    },

    [NATIONAL_DEX_SEEDOT] = 
    {
        .categoryName = _("ACORN"),
        .description = gSeedotPokedexText,
        .height = 5,
        .pokemonOffset = 20,
        .pokemonScale = 472,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 40,
    },

    [NATIONAL_DEX_NUZLEAF] = 
    {
        .categoryName = _("WILY"),
        .description = gNuzleafPokedexText,
        .height = 10,
        .pokemonOffset = 10,
        .pokemonScale = 299,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 280,
    },

    [NATIONAL_DEX_SHIFTRY] = 
    {
        .categoryName = _("WICKED"),
        .description = gShiftryPokedexText,
        .height = 13,
        .pokemonOffset = 4,
        .pokemonScale = 290,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 596,
    },

    [NATIONAL_DEX_TAILLOW] = 
    {
        .categoryName = _("TINYSWALLOW"),
        .description = gTaillowPokedexText,
        .height = 3,
        .pokemonOffset = 21,
        .pokemonScale = 465,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 23,
    },

    [NATIONAL_DEX_SWELLOW] = 
    {
        .categoryName = _("SWALLOW"),
        .description = gSwellowPokedexText,
        .height = 7,
        .pokemonOffset = 15,
        .pokemonScale = 428,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 198,
    },

    [NATIONAL_DEX_WINGULL] = 
    {
        .categoryName = _("SEAGULL"),
        .description = gWingullPokedexText,
        .height = 6,
        .pokemonOffset = -2,
        .pokemonScale = 295,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 95,
    },

    [NATIONAL_DEX_PELIPPER] = 
    {
        .categoryName = _("WATER BIRD"),
        .description = gPelipperPokedexText,
        .height = 12,
        .pokemonOffset = 1,
        .pokemonScale = 288,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 280,
    },

    [NATIONAL_DEX_RALTS] = 
    {
        .categoryName = _("FEELING"),
        .description = gRaltsPokedexText,
        .height = 4,
        .pokemonOffset = -3,
        .pokemonScale = 457,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 66,
    },

    [NATIONAL_DEX_KIRLIA] = 
    {
        .categoryName = _("EMOTION"),
        .description = gKirliaPokedexText,
        .height = 8,
        .pokemonOffset = 0,
        .pokemonScale = 354,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 202,
    },

    [NATIONAL_DEX_GARDEVOIR] = 
    {
        .categoryName = _("EMBRACE"),
        .description = gGardevoirPokedexText,
        .height = 16,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 484,
    },

    [NATIONAL_DEX_GALLADE] = 
    {
    },

    [NATIONAL_DEX_SURSKIT] = 
    {
        .categoryName = _("POND SKATER"),
        .description = gSurskitPokedexText,
        .height = 5,
        .pokemonOffset = 17,
        .pokemonScale = 375,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 17,
    },

    [NATIONAL_DEX_MASQUERAIN] = 
    {
        .categoryName = _("EYEBALL"),
        .description = gMasquerainPokedexText,
        .height = 8,
        .pokemonOffset = 8,
        .pokemonScale = 378,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 36,
    },

    [NATIONAL_DEX_SHROOMISH] = 
    {
        .categoryName = _("MUSHROOM"),
        .description = gShroomishPokedexText,
        .height = 4,
        .pokemonOffset = 22,
        .pokemonScale = 513,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 45,
    },

    [NATIONAL_DEX_BRELOOM] = 
    {
        .categoryName = _("MUSHROOM"),
        .description = gBreloomPokedexText,
        .height = 12,
        .pokemonOffset = 6,
        .pokemonScale = 324,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 392,
    },

    [NATIONAL_DEX_SLAKOTH] = 
    {
        .categoryName = _("SLACKER"),
        .description = gSlakothPokedexText,
        .height = 8,
        .pokemonOffset = 16,
        .pokemonScale = 291,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 240,
    },

    [NATIONAL_DEX_VIGOROTH] = 
    {
        .categoryName = _("WILD MONKEY"),
        .description = gVigorothPokedexText,
        .height = 14,
        .pokemonOffset = 2,
        .pokemonScale = 301,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 465,
    },

    [NATIONAL_DEX_SLAKING] = 
    {
        .categoryName = _("LAZY"),
        .description = gSlakingPokedexText,
        .height = 20,
        .pokemonOffset = 2,
        .pokemonScale = 256,
        .trainerOffset = 1,
        .trainerScale = 300,
        .weight = 1305,
    },

    [NATIONAL_DEX_NINCADA] = 
    {
        .categoryName = _("TRAINEE"),
        .description = gNincadaPokedexText,
        .height = 5,
        .pokemonOffset = 21,
        .pokemonScale = 405,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 55,
    },

    [NATIONAL_DEX_NINJASK] = 
    {
        .categoryName = _("NINJA"),
        .description = gNinjaskPokedexText,
        .height = 8,
        .pokemonOffset = -9,
        .pokemonScale = 383,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 120,
    },

    [NATIONAL_DEX_SHEDINJA] = 
    {
        .categoryName = _("SHED"),
        .description = gShedinjaPokedexText,
        .height = 8,
        .pokemonOffset = -8,
        .pokemonScale = 372,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 12,
    },

    [NATIONAL_DEX_WHISMUR] = 
    {
        .categoryName = _("WHISPER"),
        .description = gWhismurPokedexText,
        .height = 6,
        .pokemonOffset = 17,
        .pokemonScale = 373,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 163,
    },

    [NATIONAL_DEX_LOUDRED] = 
    {
        .categoryName = _("BIG VOICE"),
        .description = gLoudredPokedexText,
        .height = 10,
        .pokemonOffset = 10,
        .pokemonScale = 356,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 405,
    },

    [NATIONAL_DEX_EXPLOUD] = 
    {
        .categoryName = _("LOUD NOISE"),
        .description = gExploudPokedexText,
        .height = 15,
        .pokemonOffset = 1,
        .pokemonScale = 284,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 840,
    },

    [NATIONAL_DEX_MAKUHITA] = 
    {
        .categoryName = _("GUTS"),
        .description = gMakuhitaPokedexText,
        .height = 10,
        .pokemonOffset = 10,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 864,
    },

    [NATIONAL_DEX_HARIYAMA] = 
    {
        .categoryName = _("ARM THRUST"),
        .description = gHariyamaPokedexText,
        .height = 23,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 7,
        .trainerScale = 343,
        .weight = 2538,
    },

    [NATIONAL_DEX_NOSEPASS] = 
    {
        .categoryName = _("COMPASS"),
        .description = gNosepassPokedexText,
        .height = 10,
        .pokemonOffset = 9,
        .pokemonScale = 256,
        .trainerOffset = 3,
        .trainerScale = 289,
        .weight = 970,
    },

    [NATIONAL_DEX_PROBOPASS] = 
    {
    },

    [NATIONAL_DEX_SKITTY] = 
    {
        .categoryName = _("KITTEN"),
        .description = gSkittyPokedexText,
        .height = 6,
        .pokemonOffset = 19,
        .pokemonScale = 492,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 110,
    },

    [NATIONAL_DEX_DELCATTY] = 
    {
        .categoryName = _("PRIM"),
        .description = gDelcattyPokedexText,
        .height = 11,
        .pokemonOffset = 10,
        .pokemonScale = 322,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 326,
    },

    [NATIONAL_DEX_SABLEYE] = 
    {
        .categoryName = _("DARKNESS"),
        .description = gSableyePokedexText,
        .height = 5,
        .pokemonOffset = 17,
        .pokemonScale = 451,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 110,
    },

    [NATIONAL_DEX_MAWILE] = 
    {
        .categoryName = _("DECEIVER"),
        .description = gMawilePokedexText,
        .height = 6,
        .pokemonOffset = 17,
        .pokemonScale = 466,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 115,
    },

    [NATIONAL_DEX_ARON] = 
    {
        .categoryName = _("IRON ARMOR"),
        .description = gAronPokedexText,
        .height = 4,
        .pokemonOffset = 23,
        .pokemonScale = 419,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 600,
    },

    [NATIONAL_DEX_LAIRON] = 
    {
        .categoryName = _("IRON ARMOR"),
        .description = gLaironPokedexText,
        .height = 9,
        .pokemonOffset = 12,
        .pokemonScale = 275,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 1200,
    },

    [NATIONAL_DEX_AGGRON] = 
    {
        .categoryName = _("IRON ARMOR"),
        .description = gAggronPokedexText,
        .height = 21,
        .pokemonOffset = -1,
        .pokemonScale = 256,
        .trainerOffset = 6,
        .trainerScale = 350,
        .weight = 3600,
    },

    [NATIONAL_DEX_MEDITITE] = 
    {
        .categoryName = _("MEDITATE"),
        .description = gMedititePokedexText,
        .height = 6,
        .pokemonOffset = 17,
        .pokemonScale = 465,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 112,
    },

    [NATIONAL_DEX_MEDICHAM] = 
    {
        .categoryName = _("MEDITATE"),
        .description = gMedichamPokedexText,
        .height = 13,
        .pokemonOffset = 5,
        .pokemonScale = 298,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 315,
    },

    [NATIONAL_DEX_ELECTRIKE] = 
    {
        .categoryName = _("LIGHTNING"),
        .description = gElectrikePokedexText,
        .height = 6,
        .pokemonOffset = 15,
        .pokemonScale = 290,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 152,
    },

    [NATIONAL_DEX_MANECTRIC] = 
    {
        .categoryName = _("DISCHARGE"),
        .description = gManectricPokedexText,
        .height = 15,
        .pokemonOffset = 3,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 257,
        .weight = 402,
    },

    [NATIONAL_DEX_PLUSLE] = 
    {
        .categoryName = _("CHEERING"),
        .description = gPluslePokedexText,
        .height = 4,
        .pokemonOffset = -9,
        .pokemonScale = 515,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 42,
    },

    [NATIONAL_DEX_MINUN] = 
    {
        .categoryName = _("CHEERING"),
        .description = gMinunPokedexText,
        .height = 4,
        .pokemonOffset = -7,
        .pokemonScale = 512,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 42,
    },

    [NATIONAL_DEX_VOLBEAT] = 
    {
        .categoryName = _("FIREFLY"),
        .description = gVolbeatPokedexText,
        .height = 7,
        .pokemonOffset = 16,
        .pokemonScale = 442,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 177,
    },

    [NATIONAL_DEX_ILLUMISE] = 
    {
        .categoryName = _("FIREFLY"),
        .description = gIllumisePokedexText,
        .height = 6,
        .pokemonOffset = 19,
        .pokemonScale = 572,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 177,
    },

    [NATIONAL_DEX_BUDEW] = 
    {
    },

    [NATIONAL_DEX_ROSELIA] = 
    {
        .categoryName = _("THORN"),
        .description = gRoseliaPokedexText,
        .height = 3,
        .pokemonOffset = 20,
        .pokemonScale = 677,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 20,
    },

    [NATIONAL_DEX_ROSERADE] = 
    {
    },

    [NATIONAL_DEX_GULPIN] = 
    {
        .categoryName = _("STOMACH"),
        .description = gGulpinPokedexText,
        .height = 4,
        .pokemonOffset = 23,
        .pokemonScale = 593,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 103,
    },

    [NATIONAL_DEX_SWALOT] = 
    {
        .categoryName = _("POISON BAG"),
        .description = gSwalotPokedexText,
        .height = 17,
        .pokemonOffset = 6,
        .pokemonScale = 256,
        .trainerOffset = 3,
        .trainerScale = 345,
        .weight = 800,
    },

    [NATIONAL_DEX_CARVANHA] = 
    {
        .categoryName = _("SAVAGE"),
        .description = gCarvanhaPokedexText,
        .height = 8,
        .pokemonOffset = 0,
        .pokemonScale = 362,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 208,
    },

    [NATIONAL_DEX_SHARPEDO] = 
    {
        .categoryName = _("BRUTAL"),
        .description = gSharpedoPokedexText,
        .height = 18,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 3,
        .trainerScale = 317,
        .weight = 888,
    },

    [NATIONAL_DEX_WAILMER] = 
    {
        .categoryName = _("BALL WHALE"),
        .description = gWailmerPokedexText,
        .height = 20,
        .pokemonOffset = 2,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 493,
        .weight = 1300,
    },

    [NATIONAL_DEX_WAILORD] = 
    {
        .categoryName = _("FLOAT WHALE"),
        .description = gWailordPokedexText,
        .height = 145,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 18,
        .trainerScale = 1352,
        .weight = 3980,
    },

    [NATIONAL_DEX_NUMEL] = 
    {
        .categoryName = _("NUMB"),
        .description = gNumelPokedexText,
        .height = 7,
        .pokemonOffset = 17,
        .pokemonScale = 342,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 240,
    },

    [NATIONAL_DEX_CAMERUPT] = 
    {
        .categoryName = _("ERUPTION"),
        .description = gCameruptPokedexText,
        .height = 19,
        .pokemonOffset = 7,
        .pokemonScale = 256,
        .trainerOffset = 6,
        .trainerScale = 345,
        .weight = 2200,
    },

    [NATIONAL_DEX_TORKOAL] = 
    {
        .categoryName = _("COAL"),
        .description = gTorkoalPokedexText,
        .height = 5,
        .pokemonOffset = 9,
        .pokemonScale = 390,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 804,
    },

    [NATIONAL_DEX_SPOINK] = 
    {
        .categoryName = _("BOUNCE"),
        .description = gSpoinkPokedexText,
        .height = 7,
        .pokemonOffset = 17,
        .pokemonScale = 423,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 306,
    },

    [NATIONAL_DEX_GRUMPIG] = 
    {
        .categoryName = _("MANIPULATE"),
        .description = gGrumpigPokedexText,
        .height = 9,
        .pokemonOffset = 10,
        .pokemonScale = 358,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 715,
    },

    [NATIONAL_DEX_SPINDA] = 
    {
        .categoryName = _("SPOT PANDA"),
        .description = gSpindaPokedexText,
        .height = 11,
        .pokemonOffset = 4,
        .pokemonScale = 321,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 50,
    },

    [NATIONAL_DEX_TRAPINCH] = 
    {
        .categoryName = _("ANT PIT"),
        .description = gTrapinchPokedexText,
        .height = 7,
        .pokemonOffset = 17,
        .pokemonScale = 298,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 150,
    },

    [NATIONAL_DEX_VIBRAVA] = 
    {
        .categoryName = _("VIBRATION"),
        .description = gVibravaPokedexText,
        .height = 11,
        .pokemonOffset = 11,
        .pokemonScale = 370,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 153,
    },

    [NATIONAL_DEX_FLYGON] = 
    {
        .categoryName = _("MYSTIC"),
        .description = gFlygonPokedexText,
        .height = 20,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 1,
        .trainerScale = 268,
        .weight = 820,
    },

    [NATIONAL_DEX_CACNEA] = 
    {
        .categoryName = _("CACTUS"),
        .description = gCacneaPokedexText,
        .height = 4,
        .pokemonOffset = 20,
        .pokemonScale = 455,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 513,
    },

    [NATIONAL_DEX_CACTURNE] = 
    {
        .categoryName = _("SCARECROW"),
        .description = gCacturnePokedexText,
        .height = 13,
        .pokemonOffset = 5,
        .pokemonScale = 327,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 774,
    },

    [NATIONAL_DEX_SWABLU] = 
    {
        .categoryName = _("COTTON BIRD"),
        .description = gSwabluPokedexText,
        .height = 4,
        .pokemonOffset = -8,
        .pokemonScale = 422,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 12,
    },

    [NATIONAL_DEX_ALTARIA] = 
    {
        .categoryName = _("HUMMING"),
        .description = gAltariaPokedexText,
        .height = 11,
        .pokemonOffset = 0,
        .pokemonScale = 327,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 206,
    },

    [NATIONAL_DEX_ZANGOOSE] = 
    {
        .categoryName = _("CAT FERRET"),
        .description = gZangoosePokedexText,
        .height = 13,
        .pokemonOffset = 3,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 403,
    },

    [NATIONAL_DEX_SEVIPER] = 
    {
        .categoryName = _("FANG SNAKE"),
        .description = gSeviperPokedexText,
        .height = 27,
        .pokemonOffset = 7,
        .pokemonScale = 275,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 525,
    },

    [NATIONAL_DEX_LUNATONE] = 
    {
        .categoryName = _("METEORITE"),
        .description = gLunatonePokedexText,
        .height = 10,
        .pokemonOffset = 3,
        .pokemonScale = 300,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 1680,
    },

    [NATIONAL_DEX_SOLROCK] = 
    {
        .categoryName = _("METEORITE"),
        .description = gSolrockPokedexText,
        .height = 12,
        .pokemonOffset = 0,
        .pokemonScale = 328,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 1540,
    },

    [NATIONAL_DEX_BARBOACH] = 
    {
        .categoryName = _("WHISKERS"),
        .description = gBarboachPokedexText,
        .height = 4,
        .pokemonOffset = -3,
        .pokemonScale = 581,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 19,
    },

    [NATIONAL_DEX_WHISCASH] = 
    {
        .categoryName = _("WHISKERS"),
        .description = gWhiscashPokedexText,
        .height = 9,
        .pokemonOffset = 1,
        .pokemonScale = 317,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 236,
    },

    [NATIONAL_DEX_CORPHISH] = 
    {
        .categoryName = _("RUFFIAN"),
        .description = gCorphishPokedexText,
        .height = 6,
        .pokemonOffset = 19,
        .pokemonScale = 484,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 115,
    },

    [NATIONAL_DEX_CRAWDAUNT] = 
    {
        .categoryName = _("ROGUE"),
        .description = gCrawdauntPokedexText,
        .height = 11,
        .pokemonOffset = 9,
        .pokemonScale = 365,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 328,
    },

    [NATIONAL_DEX_BALTOY] = 
    {
        .categoryName = _("CLAY DOLL"),
        .description = gBaltoyPokedexText,
        .height = 5,
        .pokemonOffset = 21,
        .pokemonScale = 457,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 215,
    },

    [NATIONAL_DEX_CLAYDOL] = 
    {
        .categoryName = _("CLAY DOLL"),
        .description = gClaydolPokedexText,
        .height = 15,
        .pokemonOffset = 3,
        .pokemonScale = 256,
        .trainerOffset = 1,
        .trainerScale = 280,
        .weight = 1080,
    },

    [NATIONAL_DEX_LILEEP] = 
    {
        .categoryName = _("SEA LILY"),
        .description = gLileepPokedexText,
        .height = 10,
        .pokemonOffset = 8,
        .pokemonScale = 305,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 238,
    },

    [NATIONAL_DEX_CRADILY] = 
    {
        .categoryName = _("BARNACLE"),
        .description = gCradilyPokedexText,
        .height = 15,
        .pokemonOffset = 0,
        .pokemonScale = 267,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 604,
    },

    [NATIONAL_DEX_ANORITH] = 
    {
        .categoryName = _("OLD SHRIMP"),
        .description = gAnorithPokedexText,
        .height = 7,
        .pokemonOffset = 4,
        .pokemonScale = 296,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 125,
    },

    [NATIONAL_DEX_ARMALDO] = 
    {
        .categoryName = _("PLATE"),
        .description = gArmaldoPokedexText,
        .height = 15,
        .pokemonOffset = 3,
        .pokemonScale = 312,
        .trainerOffset = 0,
        .trainerScale = 271,
        .weight = 682,
    },

    [NATIONAL_DEX_FEEBAS] = 
    {
        .categoryName = _("FISH"),
        .description = gFeebasPokedexText,
        .height = 6,
        .pokemonOffset = -4,
        .pokemonScale = 423,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 74,
    },

    [NATIONAL_DEX_MILOTIC] = 
    {
        .categoryName = _("TENDER"),
        .description = gMiloticPokedexText,
        .height = 62,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 7,
        .trainerScale = 360,
        .weight = 1620,
    },

    [NATIONAL_DEX_CASTFORM] = 
    {
        .categoryName = _("WEATHER"),
        .description = gCastformPokedexText,
        .height = 3,
        .pokemonOffset = -5,
        .pokemonScale = 435,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 8,
    },

    [NATIONAL_DEX_KECLEON] = 
    {
        .categoryName = _("COLOR SWAP"),
        .description = gKecleonPokedexText,
        .height = 10,
        .pokemonOffset = 10,
        .pokemonScale = 316,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 220,
    },

    [NATIONAL_DEX_SHUPPET] = 
    {
        .categoryName = _("PUPPET"),
        .description = gShuppetPokedexText,
        .height = 6,
        .pokemonOffset = 20,
        .pokemonScale = 440,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 23,
    },

    [NATIONAL_DEX_BANETTE] = 
    {
        .categoryName = _("MARIONETTE"),
        .description = gBanettePokedexText,
        .height = 11,
        .pokemonOffset = 9,
        .pokemonScale = 262,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 125,
    },

    [NATIONAL_DEX_DUSKULL] = 
    {
        .categoryName = _("REQUIEM"),
        .description = gDuskullPokedexText,
        .height = 8,
        .pokemonOffset = -4,
        .pokemonScale = 406,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 150,
    },

    [NATIONAL_DEX_DUSCLOPS] = 
    {
        .categoryName = _("BECKON"),
        .description = gDusclopsPokedexText,
        .height = 16,
        .pokemonOffset = 3,
        .pokemonScale = 256,
        .trainerOffset = 1,
        .trainerScale = 299,
        .weight = 306,
    },

    [NATIONAL_DEX_DUSKNOIR] = 
    {
    },

    [NATIONAL_DEX_TROPIUS] = 
    {
        .categoryName = _("FRUIT"),
        .description = gTropiusPokedexText,
        .height = 20,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 7,
        .trainerScale = 344,
        .weight = 1000,
    },

    [NATIONAL_DEX_CHINGLING] = 
    {
    },

    [NATIONAL_DEX_CHIMECHO] = 
    {
        .categoryName = _("WIND CHIME"),
        .description = gChimechoPokedexText,
        .height = 6,
        .pokemonOffset = 0,
        .pokemonScale = 505,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 10,
    },

    [NATIONAL_DEX_ABSOL] = 
    {
        .categoryName = _("DISASTER"),
        .description = gAbsolPokedexText,
        .height = 12,
        .pokemonOffset = 3,
        .pokemonScale = 301,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 470,
    },

    [NATIONAL_DEX_SNORUNT] = 
    {
        .categoryName = _("SNOW HAT"),
        .description = gSnoruntPokedexText,
        .height = 7,
        .pokemonOffset = 15,
        .pokemonScale = 380,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 168,
    },

    [NATIONAL_DEX_GLALIE] = 
    {
        .categoryName = _("FACE"),
        .description = gGlaliePokedexText,
        .height = 15,
        .pokemonOffset = 3,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 344,
        .weight = 2565,
    },

    [NATIONAL_DEX_FROSLASS] = 
    {
    },

    [NATIONAL_DEX_SPHEAL] = 
    {
        .categoryName = _("CLAP"),
        .description = gSphealPokedexText,
        .height = 8,
        .pokemonOffset = 16,
        .pokemonScale = 315,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 395,
    },

    [NATIONAL_DEX_SEALEO] = 
    {
        .categoryName = _("BALL ROLL"),
        .description = gSealeoPokedexText,
        .height = 11,
        .pokemonOffset = 13,
        .pokemonScale = 338,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 876,
    },

    [NATIONAL_DEX_WALREIN] = 
    {
        .categoryName = _("ICE BREAK"),
        .description = gWalreinPokedexText,
        .height = 14,
        .pokemonOffset = 4,
        .pokemonScale = 316,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 1506,
    },

    [NATIONAL_DEX_CLAMPERL] = 
    {
        .categoryName = _("BIVALVE"),
        .description = gClamperlPokedexText,
        .height = 4,
        .pokemonOffset = 22,
        .pokemonScale = 691,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 525,
    },

    [NATIONAL_DEX_HUNTAIL] = 
    {
        .categoryName = _("DEEP SEA"),
        .description = gHuntailPokedexText,
        .height = 17,
        .pokemonOffset = 1,
        .pokemonScale = 307,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 270,
    },

    [NATIONAL_DEX_GOREBYSS] = 
    {
        .categoryName = _("SOUTH SEA"),
        .description = gGorebyssPokedexText,
        .height = 18,
        .pokemonOffset = 5,
        .pokemonScale = 278,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 226,
    },

    [NATIONAL_DEX_RELICANTH] = 
    {
        .categoryName = _("LONGEVITY"),
        .description = gRelicanthPokedexText,
        .height = 10,
        .pokemonOffset = 7,
        .pokemonScale = 316,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 234,
    },

    [NATIONAL_DEX_LUVDISC] = 
    {
        .categoryName = _("RENDEZVOUS"),
        .description = gLuvdiscPokedexText,
        .height = 6,
        .pokemonOffset = 2,
        .pokemonScale = 371,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 87,
    },

    [NATIONAL_DEX_BAGON] = 
    {
        .categoryName = _("ROCK HEAD"),
        .description = gBagonPokedexText,
        .height = 6,
        .pokemonOffset = 18,
        .pokemonScale = 448,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 421,
    },

    [NATIONAL_DEX_SHELGON] = 
    {
        .categoryName = _("ENDURANCE"),
        .description = gShelgonPokedexText,
        .height = 11,
        .pokemonOffset = 12,
        .pokemonScale = 311,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 1105,
    },

    [NATIONAL_DEX_SALAMENCE] = 
    {
        .categoryName = _("DRAGON"),
        .description = gSalamencePokedexText,
        .height = 15,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 1026,
    },

    [NATIONAL_DEX_BELDUM] = 
    {
        .categoryName = _("IRON BALL"),
        .description = gBeldumPokedexText,
        .height = 6,
        .pokemonOffset = -1,
        .pokemonScale = 414,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 952,
    },

    [NATIONAL_DEX_METANG] = 
    {
        .categoryName = _("IRON CLAW"),
        .description = gMetangPokedexText,
        .height = 12,
        .pokemonOffset = 6,
        .pokemonScale = 256,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 2025,
    },

    [NATIONAL_DEX_METAGROSS] = 
    {
        .categoryName = _("IRON LEG"),
        .description = gMetagrossPokedexText,
        .height = 16,
        .pokemonOffset = 4,
        .pokemonScale = 256,
        .trainerOffset = 9,
        .trainerScale = 447,
        .weight = 5500,
    },

    [NATIONAL_DEX_REGIROCK] = 
    {
        .categoryName = _("ROCK PEAK"),
        .description = gRegirockPokedexText,
        .height = 17,
        .pokemonOffset = 2,
        .pokemonScale = 256,
        .trainerOffset = 1,
        .trainerScale = 309,
        .weight = 2300,
    },

    [NATIONAL_DEX_REGICE] = 
    {
        .categoryName = _("ICEBERG"),
        .description = gRegicePokedexText,
        .height = 18,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 2,
        .trainerScale = 301,
        .weight = 1750,
    },

    [NATIONAL_DEX_REGISTEEL] = 
    {
        .categoryName = _("IRON"),
        .description = gRegisteelPokedexText,
        .height = 19,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 6,
        .trainerScale = 359,
        .weight = 2050,
    },

    [NATIONAL_DEX_LATIAS] = 
    {
        .categoryName = _("EON"),
        .description = gLatiasPokedexText,
        .height = 14,
        .pokemonOffset = 3,
        .pokemonScale = 304,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 400,
    },

    [NATIONAL_DEX_LATIOS] = 
    {
        .categoryName = _("EON"),
        .description = gLatiosPokedexText,
        .height = 20,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 3,
        .trainerScale = 294,
        .weight = 600,
    },

    [NATIONAL_DEX_KYOGRE] = 
    {
        .categoryName = _("SEA BASIN"),
        .description = gKyogrePokedexText,
        .height = 45,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 13,
        .trainerScale = 614,
        .weight = 3520,
    },

    [NATIONAL_DEX_GROUDON] = 
    {
        .categoryName = _("CONTINENT"),
        .description = gGroudonPokedexText,
        .height = 35,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 14,
        .trainerScale = 515,
        .weight = 9500,
    },

    [NATIONAL_DEX_RAYQUAZA] = 
    {
        .categoryName = _("SKY HIGH"),
        .description = gRayquazaPokedexText,
        .height = 70,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 12,
        .trainerScale = 448,
        .weight = 2065,
    },

    [NATIONAL_DEX_JIRACHI] = 
    {
        .categoryName = _("WISH"),
        .description = gJirachiPokedexText,
        .height = 3,
        .pokemonOffset = -8,
        .pokemonScale = 608,
        .trainerOffset = 0,
        .trainerScale = 256,
        .weight = 11,
    },

    [NATIONAL_DEX_DEOXYS] = 
    {
        .categoryName = _("DNA"),
        .description = gDeoxysPokedexText,
        .height = 17,
        .pokemonOffset = 0,
        .pokemonScale = 256,
        .trainerOffset = 2,
        .trainerScale = 290,
        .weight = 608,
    },

};
// >
