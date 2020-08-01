< //
const struct Evolution gEvolutionTable[NUM_SPECIES][EVOS_PER_MON] =
{
    [SPECIES_BULBASAUR] = {{EVO_LEVEL,16,SPECIES_IVYSAUR}},
    [SPECIES_IVYSAUR] = {{EVO_LEVEL,32,SPECIES_VENUSAUR}},
    [SPECIES_CHARMANDER] = {{EVO_LEVEL,16,SPECIES_CHARMELEON}},
    [SPECIES_CHARMELEON] = {{EVO_LEVEL,36,SPECIES_CHARIZARD}},
    [SPECIES_SQUIRTLE] = {{EVO_LEVEL,16,SPECIES_WARTORTLE}},
    [SPECIES_WARTORTLE] = {{EVO_LEVEL,36,SPECIES_BLASTOISE}},
    [SPECIES_CATERPIE] = {{EVO_LEVEL,7,SPECIES_METAPOD}},
    [SPECIES_METAPOD] = {{EVO_LEVEL,10,SPECIES_BUTTERFREE}},
    [SPECIES_WEEDLE] = {{EVO_LEVEL,7,SPECIES_KAKUNA}},
    [SPECIES_KAKUNA] = {{EVO_LEVEL,10,SPECIES_BEEDRILL}},
    [SPECIES_PIDGEY] = {{EVO_LEVEL,18,SPECIES_PIDGEOTTO}},
    [SPECIES_PIDGEOTTO] = {{EVO_LEVEL,36,SPECIES_PIDGEOT}},
    [SPECIES_RATTATA] = {{EVO_LEVEL,20,SPECIES_RATICATE}},
    [SPECIES_ALOLAN_RATTATA] = {{EVO_LEVEL_NIGHT,20,SPECIES_ALOLAN_RATICATE}},
    [SPECIES_SPEAROW] = {{EVO_LEVEL,20,SPECIES_FEAROW}},
    [SPECIES_EKANS] = {{EVO_LEVEL,22,SPECIES_ARBOK}},
    [SPECIES_PICHU] = {{EVO_FRIENDSHIP,0,SPECIES_PIKACHU}},
    [SPECIES_PIKACHU] = {{EVO_ITEM,ITEM_THUNDER_STONE,SPECIES_RAICHU},
                            {EVO_ITEM,ITEM_THUNDER_STONE,SPECIES_ALOLAN_RAICHU}},
    [SPECIES_SANDSHREW] = {{EVO_LEVEL,22,SPECIES_SANDSLASH}},
    [SPECIES_ALOLAN_SANDSHREW] = {{EVO_ITEM,ITEM_ICE_STONE,SPECIES_ALOLAN_SANDSLASH}},
    [SPECIES_NIDORAN_F] = {{EVO_LEVEL,16,SPECIES_NIDORINA}},
    [SPECIES_NIDORINA] = {{EVO_ITEM,ITEM_MOON_STONE,SPECIES_NIDOQUEEN}},
    [SPECIES_NIDORAN_M] = {{EVO_LEVEL,16,SPECIES_NIDORINO}},
    [SPECIES_NIDORINO] = {{EVO_ITEM,ITEM_MOON_STONE,SPECIES_NIDOKING}},
    [SPECIES_CLEFFA] = {{EVO_FRIENDSHIP,0,SPECIES_CLEFAIRY}},
    [SPECIES_CLEFAIRY] = {{EVO_ITEM,ITEM_MOON_STONE,SPECIES_CLEFABLE}},
    [SPECIES_TRIFOX] = {{EVO_FRIENDSHIP,0,SPECIES_VULPIX}},
    [SPECIES_VULPIX] = {{EVO_ITEM,ITEM_FIRE_STONE,SPECIES_NINETALES}},
    [SPECIES_ALOLAN_TRIFOX] = {{EVO_FRIENDSHIP,0,SPECIES_ALOLAN_VULPIX}},
    [SPECIES_ALOLAN_VULPIX] = {{EVO_ITEM,ITEM_ICE_STONE,SPECIES_ALOLAN_NINETALES}},
    [SPECIES_IGGLYBUFF] = {{EVO_FRIENDSHIP,0,SPECIES_JIGGLYPUFF}},
    [SPECIES_JIGGLYPUFF] = {{EVO_ITEM,ITEM_MOON_STONE,SPECIES_WIGGLYTUFF}},
    [SPECIES_ZUBAT] = {{EVO_LEVEL,22,SPECIES_GOLBAT}},
    [SPECIES_GOLBAT] = {{EVO_FRIENDSHIP,0,SPECIES_CROBAT}},
    [SPECIES_ODDISH] = {{EVO_LEVEL,21,SPECIES_GLOOM}},
    [SPECIES_GLOOM] = {{EVO_ITEM,ITEM_LEAF_STONE,SPECIES_VILEPLUME},
                            {EVO_ITEM,ITEM_SUN_STONE,SPECIES_BELLOSSOM}},
    [SPECIES_PARA] = {{EVO_FRIENDSHIP,0,SPECIES_PARAS}},
    [SPECIES_PARAS] = {{EVO_LEVEL,24,SPECIES_PARASECT}},
    [SPECIES_VENONAT] = {{EVO_LEVEL,31,SPECIES_VENOMOTH}},
    [SPECIES_DIGLETT] = {{EVO_LEVEL,26,SPECIES_DUGTRIO}},
    [SPECIES_ALOLAN_DIGLETT] = {{EVO_LEVEL,26,SPECIES_ALOLAN_DUGTRIO}},
    [SPECIES_MEOWSY] = {{EVO_FRIENDSHIP,0,SPECIES_MEOWTH}},
    [SPECIES_MEOWTH] = {{EVO_LEVEL,28,SPECIES_PERSIAN}},
    [SPECIES_ALOLAN_MEOWSY] = {{EVO_FRIENDSHIP,0,SPECIES_ALOLAN_MEOWTH}},
    [SPECIES_ALOLAN_MEOWTH] = {{EVO_FRIENDSHIP,28,SPECIES_ALOLAN_PERSIAN}},
    [SPECIES_PSYDUCK] = {{EVO_LEVEL,33,SPECIES_GOLDUCK}},
    [SPECIES_MANKEY] = {{EVO_LEVEL,28,SPECIES_PRIMEAPE}},
    [SPECIES_PUDDI] = {{EVO_FRIENDSHIP,0,SPECIES_GROWLITHE}},
    [SPECIES_GROWLITHE] = {{EVO_ITEM,ITEM_FIRE_STONE,SPECIES_ARCANINE}},
    [SPECIES_POLIWAG] = {{EVO_LEVEL,25,SPECIES_POLIWHIRL}},
    [SPECIES_POLIWHIRL] = {{EVO_ITEM,ITEM_WATER_STONE,SPECIES_POLIWRATH},
                            {EVO_TRADE_ITEM,ITEM_KINGS_ROCK,SPECIES_POLITOED}},
    [SPECIES_ABRA] = {{EVO_LEVEL,16,SPECIES_KADABRA}},
    [SPECIES_KADABRA] = {{EVO_TRADE,0,SPECIES_ALAKAZAM}},
    [SPECIES_MACHOP] = {{EVO_LEVEL,28,SPECIES_MACHOKE}},
    [SPECIES_MACHOKE] = {{EVO_TRADE,0,SPECIES_MACHAMP}},
    [SPECIES_BELLSPROUT] = {{EVO_LEVEL,21,SPECIES_WEEPINBELL}},
    [SPECIES_WEEPINBELL] = {{EVO_ITEM,ITEM_LEAF_STONE,SPECIES_VICTREEBEL}},
    [SPECIES_TENTACOOL] = {{EVO_LEVEL,30,SPECIES_TENTACRUEL}},
    [SPECIES_GEODUDE] = {{EVO_LEVEL,25,SPECIES_GRAVELER}},
    [SPECIES_GRAVELER] = {{EVO_TRADE,0,SPECIES_GOLEM}},
    [SPECIES_ALOLAN_GEODUDE] = {{EVO_LEVEL,25,SPECIES_ALOLAN_GRAVELER}},
    [SPECIES_ALOLAN_GRAVELER] = {{EVO_TRADE,0,SPECIES_ALOLAN_GOLEM}},
    [SPECIES_MINICORN] = {{EVO_FRIENDSHIP,0,SPECIES_PONYTA}},
    [SPECIES_PONYTA] = {{EVO_LEVEL,40,SPECIES_RAPIDASH}},
    [SPECIES_GALARIAN_MINICORN] = {{EVO_FRIENDSHIP,0,SPECIES_GALARIAN_PONYTA}},
    [SPECIES_GALARIAN_PONYTA] = {{EVO_LEVEL,40,SPECIES_RAPIDASH}},
    [SPECIES_SLOWPOKE] = {{EVO_LEVEL,37,SPECIES_SLOWBRO},
                            {EVO_TRADE_ITEM,ITEM_KINGS_ROCK,SPECIES_SLOWKING}},
    [SPECIES_MAGNEMITE] = {{EVO_LEVEL,30,SPECIES_MAGNETON}},
    [SPECIES_MAGNETON] = {{EVO_MAP,62,SPECIES_MAGNEZONE}},
    [SPECIES_CHICKS] = {{EVO_FRIENDSHIP,0,SPECIES_DODUO}},
    [SPECIES_DODUO] = {{EVO_LEVEL,31,SPECIES_DODRIO}},
    [SPECIES_SEEL] = {{EVO_LEVEL,34,SPECIES_DEWGONG}},
    [SPECIES_GRIMEY] = {{EVO_FRIENDSHIP,0,SPECIES_GRIMER}},
    [SPECIES_GRIMER] = {{EVO_LEVEL,38,SPECIES_MUK}},
    [SPECIES_ALOLAN_GRIMEY] = {{EVO_FRIENDSHIP,0,SPECIES_ALOLAN_GRIMER}},
    [SPECIES_ALOLAN_GRIMER] = {{EVO_LEVEL,38,SPECIES_ALOLAN_MUK}},
    [SPECIES_SHELLDER] = {{EVO_ITEM,ITEM_WATER_STONE,SPECIES_CLOYSTER}},
    [SPECIES_GASTLY] = {{EVO_LEVEL,25,SPECIES_HAUNTER}},
    [SPECIES_HAUNTER] = {{EVO_TRADE,0,SPECIES_GENGAR}},
    [SPECIES_ONIX] = {{EVO_TRADE_ITEM,ITEM_METAL_COAT,SPECIES_STEELIX}},
    [SPECIES_DROWZEE] = {{EVO_LEVEL,26,SPECIES_HYPNO}},
    [SPECIES_KRABBY] = {{EVO_LEVEL,28,SPECIES_KINGLER}},
    [SPECIES_VOLTORB] = {{EVO_LEVEL,30,SPECIES_ELECTRODE}},
    [SPECIES_EXEGGCUTE] = {{EVO_ITEM,ITEM_LEAF_STONE,SPECIES_EXEGGUTOR},
                            {EVO_ITEM,ITEM_LEAF_STONE,SPECIES_ALOLAN_EXEGGUTOR}},
    [SPECIES_CUBONE] = {{EVO_LEVEL,28,SPECIES_MAROWAK},
                            {EVO_LEVEL_NIGHT,28,SPECIES_ALOLAN_MAROWAK}},
    [SPECIES_TYROGUE] = {{EVO_LEVEL_ATK_LT_DEF,20,SPECIES_HITMONCHAN},
                            {EVO_LEVEL_ATK_GT_DEF,20,SPECIES_HITMONLEE},
                            {EVO_LEVEL_ATK_EQ_DEF,20,SPECIES_HITMONTOP}},
    [SPECIES_LICKITUNG] = {{EVO_MOVE,MOVE_ROLLOUT,SPECIES_LICKILICKY}},
    [SPECIES_KOFFING] = {{EVO_LEVEL,35,SPECIES_WEEZING}},
    [SPECIES_RHYHORN] = {{EVO_LEVEL,42,SPECIES_RHYDON}},
    [SPECIES_RHYDON] = {{EVO_TRADE_ITEM,ITEM_PROTECTOR,SPECIES_RHYPERIOR}},
    [SPECIES_HAPPINY] = {{EVO_ITEM_HOLD_DAY,ITEM_OVAL_STONE,SPECIES_CHANSEY}},
    [SPECIES_CHANSEY] = {{EVO_FRIENDSHIP,0,SPECIES_BLISSEY}},
    [SPECIES_TANGEL] = {{EVO_FRIENDSHIP,0,SPECIES_TANGELA}},
    [SPECIES_TANGELA] = {{EVO_MOVE,MOVE_ANCIENT_POWER,SPECIES_TANGROWTH}},
    [SPECIES_HORSEA] = {{EVO_LEVEL,32,SPECIES_SEADRA}},
    [SPECIES_SEADRA] = {{EVO_TRADE_ITEM,ITEM_DRAGON_SCALE,SPECIES_KINGDRA}},
    [SPECIES_GOLPPY] = {{EVO_FRIENDSHIP,0,SPECIES_GOLDEEN}},
    [SPECIES_GOLDEEN] = {{EVO_LEVEL,33,SPECIES_SEAKING}},
    [SPECIES_STARYU] = {{EVO_ITEM,ITEM_WATER_STONE,SPECIES_STARMIE}},
    [SPECIES_MIMEJR] = {{EVO_MOVE,MOVE_MIMIC,SPECIES_MR_MIME}},
    [SPECIES_SCYTHER] = {{EVO_TRADE_ITEM,ITEM_METAL_COAT,SPECIES_SCIZOR}},
    [SPECIES_SMOOCHUM] = {{EVO_LEVEL,30,SPECIES_JYNX}},
    [SPECIES_ELEKID] = {{EVO_LEVEL,30,SPECIES_ELECTABUZZ}},
    [SPECIES_ELECTABUZZ] = {{EVO_TRADE_ITEM,ITEM_ELECTIRIZER,SPECIES_ELECTIVIRE}},
    [SPECIES_MAGBY] = {{EVO_LEVEL,30,SPECIES_MAGMAR}},
    [SPECIES_MAGMAR] = {{EVO_TRADE_ITEM,ITEM_MAGMARIZER,SPECIES_MAGMORTAR}},
    [SPECIES_MAGIKARP] = {{EVO_LEVEL,20,SPECIES_GYARADOS}},
    [SPECIES_EEVEE] = {{EVO_ITEM,ITEM_THUNDER_STONE,SPECIES_JOLTEON},
                            {EVO_ITEM,ITEM_WATER_STONE,SPECIES_VAPOREON},
                            {EVO_ITEM,ITEM_FIRE_STONE,SPECIES_FLAREON},
                            {EVO_FRIENDSHIP_DAY,0,SPECIES_ESPEON},
                            {EVO_FRIENDSHIP_NIGHT,0,SPECIES_UMBREON},
                            {EVO_MAP,62,SPECIES_LEAFEON},
                            {EVO_MAP,62,SPECIES_GLACEON},
                            {EVO_MOVE_TYPE,TYPE_FAIRY,SPECIES_SYLVEON}},
    [SPECIES_PORYGON] = {{EVO_TRADE_ITEM,ITEM_UP_GRADE,SPECIES_PORYGON2}},
    [SPECIES_PORYGON2] = {{EVO_TRADE_ITEM,ITEM_DUBIOUS_DISC,SPECIES_PORYGON_Z}},
    [SPECIES_OMANYTE] = {{EVO_LEVEL,40,SPECIES_OMASTAR}},
    [SPECIES_KABUTO] = {{EVO_LEVEL,40,SPECIES_KABUTOPS}},
    [SPECIES_MUNCHLAX] = {{EVO_FRIENDSHIP,0,SPECIES_SNORLAX}},
    [SPECIES_DRATINI] = {{EVO_LEVEL,30,SPECIES_DRAGONAIR}},
    [SPECIES_DRAGONAIR] = {{EVO_LEVEL,55,SPECIES_DRAGONITE}},
    [SPECIES_CHIKORITA] = {{EVO_LEVEL,16,SPECIES_BAYLEEF}},
    [SPECIES_BAYLEEF] = {{EVO_LEVEL,32,SPECIES_MEGANIUM}},
    [SPECIES_CYNDAQUIL] = {{EVO_LEVEL,14,SPECIES_QUILAVA}},
    [SPECIES_QUILAVA] = {{EVO_LEVEL,36,SPECIES_TYPHLOSION}},
    [SPECIES_TOTODILE] = {{EVO_LEVEL,18,SPECIES_CROCONAW}},
    [SPECIES_CROCONAW] = {{EVO_LEVEL,30,SPECIES_FERALIGATR}},
    [SPECIES_SENTRET] = {{EVO_LEVEL,15,SPECIES_FURRET}},
    [SPECIES_HOOTHOOT] = {{EVO_LEVEL,20,SPECIES_NOCTOWL}},
    [SPECIES_LEDYBA] = {{EVO_LEVEL,18,SPECIES_LEDIAN}},
    [SPECIES_SPINARAK] = {{EVO_LEVEL,22,SPECIES_ARIADOS}},
    [SPECIES_CHINCHOU] = {{EVO_LEVEL,27,SPECIES_LANTURN}},
    [SPECIES_TOGEPI] = {{EVO_FRIENDSHIP,0,SPECIES_TOGETIC}},
    [SPECIES_TOGETIC] = {{EVO_ITEM,ITEM_SHINY_STONE,SPECIES_TOGEKISS}},
    [SPECIES_NATU] = {{EVO_LEVEL,25,SPECIES_XATU}},
    [SPECIES_MAREEP] = {{EVO_LEVEL,15,SPECIES_FLAAFFY}},
    [SPECIES_FLAAFFY] = {{EVO_LEVEL,30,SPECIES_AMPHAROS}},
    [SPECIES_AZURILL] = {{EVO_FRIENDSHIP,0,SPECIES_MARILL}},
    [SPECIES_MARILL] = {{EVO_LEVEL,18,SPECIES_AZUMARILL}},
    [SPECIES_BONSLY] = {{EVO_MOVE,MOVE_MIMIC,SPECIES_SUDOWOODO}},
    [SPECIES_HOPPIP] = {{EVO_LEVEL,18,SPECIES_SKIPLOOM}},
    [SPECIES_SKIPLOOM] = {{EVO_LEVEL,27,SPECIES_JUMPLUFF}},
    [SPECIES_AIPOM] = {{EVO_MOVE,MOVE_DOUBLE_HIT,SPECIES_AMBIPOM}},
    [SPECIES_SUNKERN] = {{EVO_ITEM,ITEM_SUN_STONE,SPECIES_SUNFLORA}},
    [SPECIES_YANMA] = {{EVO_MOVE,MOVE_ANCIENT_POWER,SPECIES_YANMEGA}},
    [SPECIES_WOOPER] = {{EVO_LEVEL,20,SPECIES_QUAGSIRE}},
    [SPECIES_MURKROW] = {{EVO_ITEM,ITEM_DUSK_STONE,SPECIES_HONCHKROW}},
    [SPECIES_MISDREAVUS] = {{EVO_ITEM,ITEM_DUSK_STONE,SPECIES_MISMAGIUS}},
    [SPECIES_WYNAUT] = {{EVO_LEVEL,15,SPECIES_WOBBUFFET}},
    [SPECIES_PINECO] = {{EVO_LEVEL,31,SPECIES_FORRETRESS}},
    [SPECIES_GLIGAR] = {{EVO_ITEM_HOLD_NIGHT,ITEM_RAZOR_FANG,SPECIES_GLISCOR}},
    [SPECIES_SNUBBULL] = {{EVO_LEVEL,23,SPECIES_GRANBULL}},
    [SPECIES_SNEASEL] = {{EVO_ITEM_HOLD_NIGHT,ITEM_RAZOR_CLAW,SPECIES_WEAVILE}},
    [SPECIES_TEDDIURSA] = {{EVO_LEVEL,30,SPECIES_URSARING}},
    [SPECIES_SLUGMA] = {{EVO_LEVEL,38,SPECIES_MAGCARGO}},
    [SPECIES_SWINUB] = {{EVO_LEVEL,33,SPECIES_PILOSWINE}},
    [SPECIES_PILOSWINE] = {{EVO_MOVE,MOVE_ANCIENT_POWER,SPECIES_MAMOSWINE}},
    [SPECIES_REMORAID] = {{EVO_LEVEL,25,SPECIES_OCTILLERY}},
    [SPECIES_MANTYKE] = {{EVO_SPECIFIC_MON_IN_PARTY,SPECIES_REMORAID,SPECIES_MANTINE}},
    [SPECIES_HOUNDOUR] = {{EVO_LEVEL,24,SPECIES_HOUNDOOM}},
    [SPECIES_PHANPY] = {{EVO_LEVEL,25,SPECIES_DONPHAN}},
    [SPECIES_LARVITAR] = {{EVO_LEVEL,30,SPECIES_PUPITAR}},
    [SPECIES_PUPITAR] = {{EVO_LEVEL,55,SPECIES_TYRANITAR}},
    [SPECIES_TREECKO] = {{EVO_LEVEL,16,SPECIES_GROVYLE}},
    [SPECIES_GROVYLE] = {{EVO_LEVEL,36,SPECIES_SCEPTILE}},
    [SPECIES_TORCHIC] = {{EVO_LEVEL,16,SPECIES_COMBUSKEN}},
    [SPECIES_COMBUSKEN] = {{EVO_LEVEL,36,SPECIES_BLAZIKEN}},
    [SPECIES_MUDKIP] = {{EVO_LEVEL,16,SPECIES_MARSHTOMP}},
    [SPECIES_MARSHTOMP] = {{EVO_LEVEL,36,SPECIES_SWAMPERT}},
    [SPECIES_POOCHYENA] = {{EVO_LEVEL,18,SPECIES_MIGHTYENA}},
    [SPECIES_ZIGZAGOON] = {{EVO_LEVEL,20,SPECIES_LINOONE}},
    [SPECIES_GALARIAN_ZIGZAGOON] = {{EVO_LEVEL,20,SPECIES_LINOONE}},
    [SPECIES_GALARIAN_LINOONE] = {{EVO_LEVEL_NIGHT,35,SPECIES_GALARIAN_OBSTAGOON}},
    [SPECIES_WURMPLE] = {{EVO_LEVEL_SILCOON,7,SPECIES_SILCOON},
                            {EVO_LEVEL_CASCOON,7,SPECIES_CASCOON}},
    [SPECIES_SILCOON] = {{EVO_LEVEL,10,SPECIES_BEAUTIFLY}},
    [SPECIES_CASCOON] = {{EVO_LEVEL,10,SPECIES_DUSTOX}},
    [SPECIES_LOTAD] = {{EVO_LEVEL,14,SPECIES_LOMBRE}},
    [SPECIES_LOMBRE] = {{EVO_ITEM,ITEM_WATER_STONE,SPECIES_LUDICOLO}},
    [SPECIES_SEEDOT] = {{EVO_LEVEL,14,SPECIES_NUZLEAF}},
    [SPECIES_NUZLEAF] = {{EVO_ITEM,ITEM_LEAF_STONE,SPECIES_SHIFTRY}},
    [SPECIES_TAILLOW] = {{EVO_LEVEL,22,SPECIES_SWELLOW}},
    [SPECIES_WINGULL] = {{EVO_LEVEL,25,SPECIES_PELIPPER}},
    [SPECIES_RALTS] = {{EVO_LEVEL,20,SPECIES_KIRLIA}},
    [SPECIES_KIRLIA] = {{EVO_LEVEL,30,SPECIES_GARDEVOIR},
                            {EVO_ITEM_MALE,ITEM_DAWN_STONE,SPECIES_GALLADE}},
    [SPECIES_SURSKIT] = {{EVO_LEVEL,22,SPECIES_MASQUERAIN}},
    [SPECIES_SHROOMISH] = {{EVO_LEVEL,23,SPECIES_BRELOOM}},
    [SPECIES_SLAKOTH] = {{EVO_LEVEL,18,SPECIES_VIGOROTH}},
    [SPECIES_VIGOROTH] = {{EVO_LEVEL,36,SPECIES_SLAKING}},
    [SPECIES_NINCADA] = {{EVO_LEVEL_NINJASK,20,SPECIES_NINJASK},
                            {EVO_LEVEL_SHEDINJA,20,SPECIES_SHEDINJA}},
    [SPECIES_WHISMUR] = {{EVO_LEVEL,20,SPECIES_LOUDRED}},
    [SPECIES_LOUDRED] = {{EVO_LEVEL,40,SPECIES_EXPLOUD}},
    [SPECIES_MAKUHITA] = {{EVO_LEVEL,24,SPECIES_HARIYAMA}},
    [SPECIES_NOSEPASS] = {{EVO_MAP,62,SPECIES_PROBOPASS}},
    [SPECIES_SKITTY] = {{EVO_ITEM,ITEM_MOON_STONE,SPECIES_DELCATTY}},
    [SPECIES_ARON] = {{EVO_LEVEL,32,SPECIES_LAIRON}},
    [SPECIES_LAIRON] = {{EVO_LEVEL,42,SPECIES_AGGRON}},
    [SPECIES_MEDITITE] = {{EVO_LEVEL,37,SPECIES_MEDICHAM}},
    [SPECIES_ELECTRIKE] = {{EVO_LEVEL,26,SPECIES_MANECTRIC}},
    [SPECIES_BUDEW] = {{EVO_FRIENDSHIP,0,SPECIES_ROSELIA}},
    [SPECIES_ROSELIA] = {{EVO_ITEM,ITEM_SHINY_STONE,SPECIES_ROSERADE}},
    [SPECIES_GULPIN] = {{EVO_LEVEL,26,SPECIES_SWALOT}},
    [SPECIES_CARVANHA] = {{EVO_LEVEL,30,SPECIES_SHARPEDO}},
    [SPECIES_WAILMER] = {{EVO_LEVEL,40,SPECIES_WAILORD}},
    [SPECIES_NUMEL] = {{EVO_LEVEL,33,SPECIES_CAMERUPT}},
    [SPECIES_SPOINK] = {{EVO_LEVEL,32,SPECIES_GRUMPIG}},
    [SPECIES_TRAPINCH] = {{EVO_LEVEL,35,SPECIES_VIBRAVA}},
    [SPECIES_VIBRAVA] = {{EVO_LEVEL,45,SPECIES_FLYGON}},
    [SPECIES_CACNEA] = {{EVO_LEVEL,32,SPECIES_CACTURNE}},
    [SPECIES_SWABLU] = {{EVO_LEVEL,35,SPECIES_ALTARIA}},
    [SPECIES_BARBOACH] = {{EVO_LEVEL,30,SPECIES_WHISCASH}},
    [SPECIES_CORPHISH] = {{EVO_LEVEL,30,SPECIES_CRAWDAUNT}},
    [SPECIES_BALTOY] = {{EVO_LEVEL,36,SPECIES_CLAYDOL}},
    [SPECIES_LILEEP] = {{EVO_LEVEL,40,SPECIES_CRADILY}},
    [SPECIES_ANORITH] = {{EVO_LEVEL,40,SPECIES_ARMALDO}},
    [SPECIES_FEEBAS] = {{EVO_BEAUTY,170,SPECIES_MILOTIC},
                            {EVO_TRADE_ITEM,ITEM_PRISM_SCALE,SPECIES_MILOTIC}},
    [SPECIES_SHUPPET] = {{EVO_LEVEL,37,SPECIES_BANETTE}},
    [SPECIES_DUSKULL] = {{EVO_LEVEL,37,SPECIES_DUSCLOPS}},
    [SPECIES_DUSCLOPS] = {{EVO_TRADE_ITEM,ITEM_REAPER_CLOTH,SPECIES_DUSKNOIR}},
    [SPECIES_CHINGLING] = {{EVO_FRIENDSHIP_NIGHT,0,SPECIES_CHIMECHO}},
    [SPECIES_SNORUNT] = {{EVO_LEVEL,42,SPECIES_GLALIE},
                            {EVO_ITEM_FEMALE,ITEM_DAWN_STONE,SPECIES_FROSLASS}},
    [SPECIES_SPHEAL] = {{EVO_LEVEL,32,SPECIES_SEALEO}},
    [SPECIES_SEALEO] = {{EVO_LEVEL,44,SPECIES_WALREIN}},
    [SPECIES_CLAMPERL] = {{EVO_TRADE_ITEM,ITEM_DEEP_SEA_TOOTH,SPECIES_HUNTAIL},
                            {EVO_TRADE_ITEM,ITEM_DEEP_SEA_SCALE,SPECIES_GOREBYSS}},
    [SPECIES_BAGON] = {{EVO_LEVEL,30,SPECIES_SHELGON}},
    [SPECIES_SHELGON] = {{EVO_LEVEL,50,SPECIES_SALAMENCE}},
    [SPECIES_BELDUM] = {{EVO_LEVEL,20,SPECIES_METANG}},
    [SPECIES_METANG] = {{EVO_LEVEL,45,SPECIES_METAGROSS}},
    [SPECIES_LINOONE] = {{EVO_LEVEL_DAY,35,SPECIES_OBSTAGOON}},
    [SPECIES_GALARIAN_LINOONE] = {{EVO_LEVEL_NIGHT,35,SPECIES_GALARIAN_OBSTAGOON}},
    [SPECIES_CLONE_BULBASAUR] = {{EVO_LEVEL,16,SPECIES_CLONE_IVYSAUR}},
    [SPECIES_CLONE_IVYSAUR] = {{EVO_LEVEL,36,SPECIES_VENUSAUR}},
    [SPECIES_CLONE_CHARMANDER] = {{EVO_LEVEL,16,SPECIES_CLONE_CHARMELEON}},
    [SPECIES_CLONE_CHARMELEON] = {{EVO_LEVEL,36,SPECIES_CLONE_CHARIZARD}},
    [SPECIES_CLONE_SQUIRTLE] = {{EVO_LEVEL,16,SPECIES_CLONE_WARTORTLE}},
    [SPECIES_CLONE_WARTORTLE] = {{EVO_LEVEL,36,SPECIES_CLONE_BLASTOISE}},
};
// > END