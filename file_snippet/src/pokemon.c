< //
#include "constants/weather.h"
#include "constants/battle_anim.h"

struct SpeciesItem
// >

< //
        case TRAINER_CLASS_SALON_MAIDEN:
        case TRAINER_CLASS_DOME_ACE:
        case TRAINER_CLASS_PALACE_MAVEN:
        case TRAINER_CLASS_ARENA_TYCOON:
        case TRAINER_CLASS_FACTORY_HEAD:
        case TRAINER_CLASS_PIKE_QUEEN:
        case TRAINER_CLASS_PYRAMID_KING:
            return MUS_VS_FRONTIER_BRAIN;
		case TRAINER_CLASS_MEWTWO:
			return MUS_RG_VS_CHAMPION;
        default:
            return MUS_VS_TRAINER;
// >

< //
u16 MonTryLearningNewMove(struct Pokemon *mon, bool8 firstMove)
#Ru16 MonTryLearningNewMove(struct Pokemon *mon, bool8 firstMove, bool8 isEvolving)
{
    u32 retVal = 0;
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    u8 level = GetMonData(mon, MON_DATA_LEVEL, NULL);

    // since you can learn more than one move per level
    // the game needs to know whether you decided to
    // learn it or keep the old set to avoid asking
    // you to learn the same move over and over again
    if (firstMove)
    {
        sLearningMoveTableID = 0;
    }
    // Added evolution moves; Pokemon will learn moves listed at level zero upon evolution
    if(isEvolving && (gLevelUpLearnsets[species][sLearningMoveTableID].level == 0))
    {
        gMoveToLearn = gLevelUpLearnsets[species][sLearningMoveTableID].move;
        retVal = GiveMoveToMon(mon, gMoveToLearn);
        sLearningMoveTableID++;
        return retVal;        
    }
    if(isEvolving && (gLevelUpLearnsets[species][sLearningMoveTableID].level > 0))
    {
        while (gLevelUpLearnsets[species][sLearningMoveTableID].level != level)
         {
            sLearningMoveTableID++;
            if (gLevelUpLearnsets[species][sLearningMoveTableID].move == LEVEL_UP_END)
                return 0;
         }
    }

    if (firstMove)
    {
        while (gLevelUpLearnsets[species][sLearningMoveTableID].level != level)
        {
            sLearningMoveTableID++;
            if (gLevelUpLearnsets[species][sLearningMoveTableID].move == LEVEL_UP_END)
                return 0;
        }
    }
    if (gLevelUpLearnsets[species][sLearningMoveTableID].level == level)
    {
        gMoveToLearn = gLevelUpLearnsets[species][sLearningMoveTableID].move;
        sLearningMoveTableID++;
        retVal = GiveMoveToMon(mon, gMoveToLearn);
    }
    return retVal;
}

void DeleteFirstMoveAndGiveMoveToMon(struct Pokemon *mon, u16 move)
// >

< //
            case EVO_FRIENDSHIP_DAY:
                RtcCalcLocalTime();
                if (gLocalTime.hours >= DAY_START && gLocalTime.hours < NIGHT_START && friendship >= 220)
                    targetSpecies = gEvolutionTable[species][i].targetSpecies;
                break;
            case EVO_LEVEL_DAY:
                RtcCalcLocalTime();
                if (gLocalTime.hours >= DAY_START && gLocalTime.hours < NIGHT_START && gEvolutionTable[species][i].param <= level)
                    targetSpecies = gEvolutionTable[species][i].targetSpecies;
                break;
            case EVO_FRIENDSHIP_NIGHT:
                RtcCalcLocalTime();
                if ((gLocalTime.hours >= NIGHT_START || gLocalTime.hours < DAY_START) && friendship >= 220)
                    targetSpecies = gEvolutionTable[species][i].targetSpecies;
                break;
            case EVO_LEVEL_NIGHT:
                RtcCalcLocalTime();
                if ((gLocalTime.hours >= NIGHT_START || gLocalTime.hours < DAY_START) && gEvolutionTable[species][i].param <= level)
                    targetSpecies = gEvolutionTable[species][i].targetSpecies;
                break;
            case EVO_ITEM_HOLD_NIGHT:
                RtcCalcLocalTime();
                if ((gLocalTime.hours >= NIGHT_START || gLocalTime.hours < DAY_START) && heldItem == gEvolutionTable[species][i].param)
                {
                    heldItem = 0;
                    SetMonData(mon, MON_DATA_HELD_ITEM, &heldItem);
                    targetSpecies = gEvolutionTable[species][i].targetSpecies;
                }
                break;
            case EVO_ITEM_HOLD_DAY:
                RtcCalcLocalTime();
                if (gLocalTime.hours >= DAY_START && gLocalTime.hours < NIGHT_START && heldItem == gEvolutionTable[species][i].param)
                {
                    heldItem = 0;
                    SetMonData(mon, MON_DATA_HELD_ITEM, &heldItem);
                    targetSpecies = gEvolutionTable[species][i].targetSpecies;
                }
                break;
            case EVO_LEVEL_DUSK:
                RtcCalcLocalTime();
                if (gLocalTime.hours >= 17 && gLocalTime.hours < 18 && gEvolutionTable[species][i].param <= level)
                    targetSpecies = gEvolutionTable[species][i].targetSpecies;
                break;
            case EVO_LEVEL:
// >

< //
void CreateBoxMon(struct BoxPokemon *boxMon, u16 species, u8 level, u8 fixedIV, u8 hasFixedPersonality, u32 fixedPersonality, u8 otIdType, u32 fixedOtId)
{
    u8 speciesName[POKEMON_NAME_LENGTH + 1];
    u32 personality;
    u32 value;
    u16 checksum;

    ZeroBoxMonData(boxMon);

    if (hasFixedPersonality)
        personality = fixedPersonality;
    else
        personality = Random32();

    //Determine original trainer ID
    if (otIdType == OT_ID_RANDOM_NO_SHINY) //Pokemon cannot be shiny
    {
        u32 shinyValue;
        do
        {
            value = Random32();
            shinyValue = HIHALF(value) ^ LOHALF(value) ^ HIHALF(personality) ^ LOHALF(personality);
        } while (shinyValue < SHINY_ODDS);
    }
	// custom addition: fixed shiny
	else if (otIdType == OT_ID_RANDOM_SHINY) //Pokemon cannot be shiny
    {
        u32 shinyValue;
        do
        {
            value = Random32();
            shinyValue = HIHALF(value) ^ LOHALF(value) ^ HIHALF(personality) ^ LOHALF(personality);
        } while (shinyValue >= SHINY_ODDS);
    }
    else if (otIdType == OT_ID_PRESET) //Pokemon has a preset OT ID
    {
        value = fixedOtId;
    }
    else //Player is the OT
    {
        value = gSaveBlock2Ptr->playerTrainerId[0]
              | (gSaveBlock2Ptr->playerTrainerId[1] << 8)
              | (gSaveBlock2Ptr->playerTrainerId[2] << 16)
              | (gSaveBlock2Ptr->playerTrainerId[3] << 24);
        
        if (CheckBagHasItem(ITEM_SHINY_CHARM, 1))
        {
            u32 shinyValue;
            u32 rolls = 0;
            do
            {
                if (hasFixedPersonality)
                {
                    u8 wantedNature = GetNatureFromPersonality(fixedPersonality);
                    s32 natureTries = 0;

                    do
                    {
                        personality = (Random2() << 16) | (Random());
                        if (wantedNature == GetNatureFromPersonality(personality) && personality != 0)
                            break; // found a personality with the same nature

                        natureTries++;
                    } while (natureTries <= 2400);

                }
                else {
                    personality = Random32();
                }

                shinyValue = HIHALF(value) ^ LOHALF(value) ^ HIHALF(personality) ^ LOHALF(personality);
                rolls++;
            } while (shinyValue >= SHINY_ODDS && rolls < SHINY_CHARM_REROLLS);
        }
    }

    SetBoxMonData(boxMon, MON_DATA_PERSONALITY, &personality);
    SetBoxMonData(boxMon, MON_DATA_OT_ID, &value);

    checksum = CalculateBoxMonChecksum(boxMon);
    SetBoxMonData(boxMon, MON_DATA_CHECKSUM, &checksum);
    EncryptBoxMon(boxMon);
    GetSpeciesName(speciesName, species);
    SetBoxMonData(boxMon, MON_DATA_NICKNAME, speciesName);
    SetBoxMonData(boxMon, MON_DATA_LANGUAGE, &gGameLanguage);
    SetBoxMonData(boxMon, MON_DATA_OT_NAME, gSaveBlock2Ptr->playerName);
    SetBoxMonData(boxMon, MON_DATA_SPECIES, &species);
    SetBoxMonData(boxMon, MON_DATA_EXP, &gExperienceTables[gBaseStats[species].growthRate][level]);
    SetBoxMonData(boxMon, MON_DATA_FRIENDSHIP, &gBaseStats[species].friendship);
    value = GetCurrentRegionMapSectionId();
    SetBoxMonData(boxMon, MON_DATA_MET_LOCATION, &value);
    SetBoxMonData(boxMon, MON_DATA_MET_LEVEL, &level);
    SetBoxMonData(boxMon, MON_DATA_MET_GAME, &gGameVersion);
    value = ITEM_POKE_BALL;
    SetBoxMonData(boxMon, MON_DATA_POKEBALL, &value);
    SetBoxMonData(boxMon, MON_DATA_OT_GENDER, &gSaveBlock2Ptr->playerGender);

    if (fixedIV < 32)
    {
        SetBoxMonData(boxMon, MON_DATA_HP_IV, &fixedIV);
        SetBoxMonData(boxMon, MON_DATA_ATK_IV, &fixedIV);
        SetBoxMonData(boxMon, MON_DATA_DEF_IV, &fixedIV);
        SetBoxMonData(boxMon, MON_DATA_SPEED_IV, &fixedIV);
        SetBoxMonData(boxMon, MON_DATA_SPATK_IV, &fixedIV);
        SetBoxMonData(boxMon, MON_DATA_SPDEF_IV, &fixedIV);
    }
    else
    {
        u32 iv;
        value = Random();

        iv = value & 0x1F;
        SetBoxMonData(boxMon, MON_DATA_HP_IV, &iv);
        iv = (value & 0x3E0) >> 5;
        SetBoxMonData(boxMon, MON_DATA_ATK_IV, &iv);
        iv = (value & 0x7C00) >> 10;
        SetBoxMonData(boxMon, MON_DATA_DEF_IV, &iv);

        value = Random();

        iv = value & 0x1F;
        SetBoxMonData(boxMon, MON_DATA_SPEED_IV, &iv);
        iv = (value & 0x3E0) >> 5;
        SetBoxMonData(boxMon, MON_DATA_SPATK_IV, &iv);
        iv = (value & 0x7C00) >> 10;
        SetBoxMonData(boxMon, MON_DATA_SPDEF_IV, &iv);
    }

    if (gBaseStats[species].abilities[1])
    {
        value = personality & 1;
        SetBoxMonData(boxMon, MON_DATA_ABILITY_NUM, &value);
    }

    GiveBoxMonInitialMoveset(boxMon);
}

void CreateMonWithNature(struct Pokemon *mon, u16 species, u8 level, u8 fixedIV, u8 nature)
// >

< //
const u16 gSpeciesToNationalPokedexNum[NUM_SPECIES] = // Assigns all species to the National Dex Index (Summary No. for National Dex)
{
    SPECIES_TO_NATIONAL(BULBASAUR),
    SPECIES_TO_NATIONAL(IVYSAUR),
    SPECIES_TO_NATIONAL(VENUSAUR),
    SPECIES_TO_NATIONAL(CHARMANDER),
    SPECIES_TO_NATIONAL(CHARMELEON),
    SPECIES_TO_NATIONAL(CHARIZARD),
    SPECIES_TO_NATIONAL(SQUIRTLE),
    SPECIES_TO_NATIONAL(WARTORTLE),
    SPECIES_TO_NATIONAL(BLASTOISE),
    SPECIES_TO_NATIONAL(CATERPIE),
    SPECIES_TO_NATIONAL(METAPOD),
    SPECIES_TO_NATIONAL(BUTTERFREE),
    SPECIES_TO_NATIONAL(WEEDLE),
    SPECIES_TO_NATIONAL(KAKUNA),
    SPECIES_TO_NATIONAL(BEEDRILL),
    SPECIES_TO_NATIONAL(PIDGEY),
    SPECIES_TO_NATIONAL(PIDGEOTTO),
    SPECIES_TO_NATIONAL(PIDGEOT),
    SPECIES_TO_NATIONAL(RATTATA),
    SPECIES_TO_NATIONAL(RATICATE),
    SPECIES_TO_NATIONAL(ALOLAN_RATTATA),
    SPECIES_TO_NATIONAL(ALOLAN_RATICATE),
    SPECIES_TO_NATIONAL(SPEAROW),
    SPECIES_TO_NATIONAL(FEAROW),
    SPECIES_TO_NATIONAL(EKANS),
    SPECIES_TO_NATIONAL(ARBOK),
    SPECIES_TO_NATIONAL(PICHU),
    SPECIES_TO_NATIONAL(PIKACHU),
    SPECIES_TO_NATIONAL(RAICHU),
    SPECIES_TO_NATIONAL(ALOLAN_RAICHU),
    SPECIES_TO_NATIONAL(SANDSHREW),
    SPECIES_TO_NATIONAL(SANDSLASH),
    SPECIES_TO_NATIONAL(ALOLAN_SANDSHREW),
    SPECIES_TO_NATIONAL(ALOLAN_SANDSLASH),
    SPECIES_TO_NATIONAL(NIDORAN_F),
    SPECIES_TO_NATIONAL(NIDORINA),
    SPECIES_TO_NATIONAL(NIDOQUEEN),
    SPECIES_TO_NATIONAL(NIDORAN_M),
    SPECIES_TO_NATIONAL(NIDORINO),
    SPECIES_TO_NATIONAL(NIDOKING),
    SPECIES_TO_NATIONAL(CLEFFA),
    SPECIES_TO_NATIONAL(CLEFAIRY),
    SPECIES_TO_NATIONAL(CLEFABLE),
    SPECIES_TO_NATIONAL(TRIFOX),
    SPECIES_TO_NATIONAL(VULPIX),
    SPECIES_TO_NATIONAL(NINETALES),
    SPECIES_TO_NATIONAL(ALOLAN_TRIFOX),
    SPECIES_TO_NATIONAL(ALOLAN_VULPIX),
    SPECIES_TO_NATIONAL(ALOLAN_NINETALES),
    SPECIES_TO_NATIONAL(IGGLYBUFF),
    SPECIES_TO_NATIONAL(JIGGLYPUFF),
    SPECIES_TO_NATIONAL(WIGGLYTUFF),
    SPECIES_TO_NATIONAL(ZUBAT),
    SPECIES_TO_NATIONAL(GOLBAT),
    SPECIES_TO_NATIONAL(CROBAT),
    SPECIES_TO_NATIONAL(ODDISH),
    SPECIES_TO_NATIONAL(GLOOM),
    SPECIES_TO_NATIONAL(VILEPLUME),
    SPECIES_TO_NATIONAL(BELLOSSOM),
    SPECIES_TO_NATIONAL(PARA),
    SPECIES_TO_NATIONAL(PARAS),
    SPECIES_TO_NATIONAL(PARASECT),
    SPECIES_TO_NATIONAL(VENONAT),
    SPECIES_TO_NATIONAL(VENOMOTH),
    SPECIES_TO_NATIONAL(DIGLETT),
    SPECIES_TO_NATIONAL(DUGTRIO),
    SPECIES_TO_NATIONAL(ALOLAN_DIGLETT),
    SPECIES_TO_NATIONAL(ALOLAN_DUGTRIO),
    SPECIES_TO_NATIONAL(MEOWSY),
    SPECIES_TO_NATIONAL(MEOWTH),
    SPECIES_TO_NATIONAL(PERSIAN),
    SPECIES_TO_NATIONAL(ALOLAN_MEOWSY),
    SPECIES_TO_NATIONAL(ALOLAN_MEOWTH),
    SPECIES_TO_NATIONAL(ALOLAN_PERSIAN),
    SPECIES_TO_NATIONAL(PSYDUCK),
    SPECIES_TO_NATIONAL(GOLDUCK),
    SPECIES_TO_NATIONAL(MANKEY),
    SPECIES_TO_NATIONAL(PRIMEAPE),
    SPECIES_TO_NATIONAL(PUDDI),
    SPECIES_TO_NATIONAL(GROWLITHE),
    SPECIES_TO_NATIONAL(ARCANINE),
    SPECIES_TO_NATIONAL(POLIWAG),
    SPECIES_TO_NATIONAL(POLIWHIRL),
    SPECIES_TO_NATIONAL(POLIWRATH),
    SPECIES_TO_NATIONAL(POLITOED),
    SPECIES_TO_NATIONAL(ABRA),
    SPECIES_TO_NATIONAL(KADABRA),
    SPECIES_TO_NATIONAL(ALAKAZAM),
    SPECIES_TO_NATIONAL(MACHOP),
    SPECIES_TO_NATIONAL(MACHOKE),
    SPECIES_TO_NATIONAL(MACHAMP),
    SPECIES_TO_NATIONAL(BELLSPROUT),
    SPECIES_TO_NATIONAL(WEEPINBELL),
    SPECIES_TO_NATIONAL(VICTREEBEL),
    SPECIES_TO_NATIONAL(TENTACOOL),
    SPECIES_TO_NATIONAL(TENTACRUEL),
    SPECIES_TO_NATIONAL(GEODUDE),
    SPECIES_TO_NATIONAL(GRAVELER),
    SPECIES_TO_NATIONAL(GOLEM),
    SPECIES_TO_NATIONAL(ALOLAN_GEODUDE),
    SPECIES_TO_NATIONAL(ALOLAN_GRAVELER),
    SPECIES_TO_NATIONAL(ALOLAN_GOLEM),
    SPECIES_TO_NATIONAL(MINICORN),
    SPECIES_TO_NATIONAL(PONYTA),
    SPECIES_TO_NATIONAL(RAPIDASH),
    SPECIES_TO_NATIONAL(GALARIAN_MINICORN),
    SPECIES_TO_NATIONAL(GALARIAN_PONYTA),
    SPECIES_TO_NATIONAL(GALARIAN_RAPIDASH),
    SPECIES_TO_NATIONAL(SLOWPOKE),
    SPECIES_TO_NATIONAL(SLOWBRO),
    SPECIES_TO_NATIONAL(SLOWKING),
    SPECIES_TO_NATIONAL(MAGNEMITE),
    SPECIES_TO_NATIONAL(MAGNETON),
    SPECIES_TO_NATIONAL(MAGNEZONE),
    SPECIES_TO_NATIONAL(FARFETCHD),
    SPECIES_TO_NATIONAL(SIRFETCHD),
    SPECIES_TO_NATIONAL(MADAME),
    SPECIES_TO_NATIONAL(CHICKS),
    SPECIES_TO_NATIONAL(DODUO),
    SPECIES_TO_NATIONAL(DODRIO),
    SPECIES_TO_NATIONAL(SEEL),
    SPECIES_TO_NATIONAL(DEWGONG),
    SPECIES_TO_NATIONAL(GRIMEY),
    SPECIES_TO_NATIONAL(GRIMER),
    SPECIES_TO_NATIONAL(MUK),
    SPECIES_TO_NATIONAL(ALOLAN_GRIMEY),
    SPECIES_TO_NATIONAL(ALOLAN_GRIMER),
    SPECIES_TO_NATIONAL(ALOLAN_MUK),
    SPECIES_TO_NATIONAL(SHELLDER),
    SPECIES_TO_NATIONAL(CLOYSTER),
    SPECIES_TO_NATIONAL(TURBAN),
    SPECIES_TO_NATIONAL(GASTLY),
    SPECIES_TO_NATIONAL(HAUNTER),
    SPECIES_TO_NATIONAL(GENGAR),
    SPECIES_TO_NATIONAL(ONIX),
    SPECIES_TO_NATIONAL(STEELIX),
    SPECIES_TO_NATIONAL(DROWZEE),
    SPECIES_TO_NATIONAL(HYPNO),
    SPECIES_TO_NATIONAL(KRABBY),
    SPECIES_TO_NATIONAL(KINGLER),
    SPECIES_TO_NATIONAL(VOLTORB),
    SPECIES_TO_NATIONAL(ELECTRODE),
    SPECIES_TO_NATIONAL(EXEGGCUTE),
    SPECIES_TO_NATIONAL(EXEGGUTOR),
    SPECIES_TO_NATIONAL(ALOLAN_EXEGGUTOR),
    SPECIES_TO_NATIONAL(CUBONE),
    SPECIES_TO_NATIONAL(MAROWAK),
    SPECIES_TO_NATIONAL(ALOLAN_MAROWAK),
    SPECIES_TO_NATIONAL(TYROGUE),
    SPECIES_TO_NATIONAL(HITMONLEE),
    SPECIES_TO_NATIONAL(HITMONCHAN),
    SPECIES_TO_NATIONAL(HITMONTOP),
    SPECIES_TO_NATIONAL(LICKITUNG),
    SPECIES_TO_NATIONAL(LICKILICKY),
    SPECIES_TO_NATIONAL(KOFFING),
    SPECIES_TO_NATIONAL(WEEZING),
    SPECIES_TO_NATIONAL(RHYHORN),
    SPECIES_TO_NATIONAL(RHYDON),
    SPECIES_TO_NATIONAL(RHYPERIOR),
    SPECIES_TO_NATIONAL(HAPPINY),
    SPECIES_TO_NATIONAL(CHANSEY),
    SPECIES_TO_NATIONAL(BLISSEY),
    SPECIES_TO_NATIONAL(TANGEL),
    SPECIES_TO_NATIONAL(TANGELA),
    SPECIES_TO_NATIONAL(TANGROWTH),
    SPECIES_TO_NATIONAL(KANGASKHAN),
    SPECIES_TO_NATIONAL(HORSEA),
    SPECIES_TO_NATIONAL(SEADRA),
    SPECIES_TO_NATIONAL(KINGDRA),
    SPECIES_TO_NATIONAL(GOLPPY),
    SPECIES_TO_NATIONAL(GOLDEEN),
    SPECIES_TO_NATIONAL(SEAKING),
    SPECIES_TO_NATIONAL(STARYU),
    SPECIES_TO_NATIONAL(STARMIE),
    SPECIES_TO_NATIONAL(MIMEJR),
    SPECIES_TO_NATIONAL(MR_MIME),
    SPECIES_TO_NATIONAL(SCYTHER),
    SPECIES_TO_NATIONAL(SCIZOR),
    SPECIES_TO_NATIONAL(SMOOCHUM),
    SPECIES_TO_NATIONAL(JYNX),
    SPECIES_TO_NATIONAL(ELEKID),
    SPECIES_TO_NATIONAL(ELECTABUZZ),
    SPECIES_TO_NATIONAL(ELECTIVIRE),
    SPECIES_TO_NATIONAL(MAGBY),
    SPECIES_TO_NATIONAL(MAGMAR),
    SPECIES_TO_NATIONAL(MAGMORTAR),
    SPECIES_TO_NATIONAL(PINSIR),
    SPECIES_TO_NATIONAL(TAUROS),
    SPECIES_TO_NATIONAL(MAGIKARP),
    SPECIES_TO_NATIONAL(GYARADOS),
    SPECIES_TO_NATIONAL(LAPRAS),
    SPECIES_TO_NATIONAL(DITTO),
    SPECIES_TO_NATIONAL(EEVEE),
    SPECIES_TO_NATIONAL(VAPOREON),
    SPECIES_TO_NATIONAL(JOLTEON),
    SPECIES_TO_NATIONAL(FLAREON),
    SPECIES_TO_NATIONAL(ESPEON),
    SPECIES_TO_NATIONAL(UMBREON),
    SPECIES_TO_NATIONAL(LEAFEON),
    SPECIES_TO_NATIONAL(GLACEON),
    SPECIES_TO_NATIONAL(SYLVEON),
    SPECIES_TO_NATIONAL(PORYGON),
    SPECIES_TO_NATIONAL(PORYGON2),
    SPECIES_TO_NATIONAL(PORYGON_Z),
    SPECIES_TO_NATIONAL(OMANYTE),
    SPECIES_TO_NATIONAL(OMASTAR),
    SPECIES_TO_NATIONAL(KABUTO),
    SPECIES_TO_NATIONAL(KABUTOPS),
    SPECIES_TO_NATIONAL(AERODACTYL),
    SPECIES_TO_NATIONAL(MUNCHLAX),
    SPECIES_TO_NATIONAL(SNORLAX),
    SPECIES_TO_NATIONAL(ARTICUNO),
    SPECIES_TO_NATIONAL(ZAPDOS),
    SPECIES_TO_NATIONAL(MOLTRES),
    SPECIES_TO_NATIONAL(DRATINI),
    SPECIES_TO_NATIONAL(DRAGONAIR),
    SPECIES_TO_NATIONAL(DRAGONITE),
    SPECIES_TO_NATIONAL(MEWTWO),
    SPECIES_TO_NATIONAL(MEW),
    SPECIES_TO_NATIONAL(CHIKORITA),
    SPECIES_TO_NATIONAL(BAYLEEF),
    SPECIES_TO_NATIONAL(MEGANIUM),
    SPECIES_TO_NATIONAL(CYNDAQUIL),
    SPECIES_TO_NATIONAL(QUILAVA),
    SPECIES_TO_NATIONAL(TYPHLOSION),
    SPECIES_TO_NATIONAL(TOTODILE),
    SPECIES_TO_NATIONAL(CROCONAW),
    SPECIES_TO_NATIONAL(FERALIGATR),
    SPECIES_TO_NATIONAL(SENTRET),
    SPECIES_TO_NATIONAL(FURRET),
    SPECIES_TO_NATIONAL(HOOTHOOT),
    SPECIES_TO_NATIONAL(NOCTOWL),
    SPECIES_TO_NATIONAL(LEDYBA),
    SPECIES_TO_NATIONAL(LEDIAN),
    SPECIES_TO_NATIONAL(SPINARAK),
    SPECIES_TO_NATIONAL(ARIADOS),
    SPECIES_TO_NATIONAL(CHINCHOU),
    SPECIES_TO_NATIONAL(LANTURN),
    SPECIES_TO_NATIONAL(TOGEPI),
    SPECIES_TO_NATIONAL(TOGETIC),
    SPECIES_TO_NATIONAL(TOGEKISS),
    SPECIES_TO_NATIONAL(NATU),
    SPECIES_TO_NATIONAL(XATU),
    SPECIES_TO_NATIONAL(MAREEP),
    SPECIES_TO_NATIONAL(FLAAFFY),
    SPECIES_TO_NATIONAL(AMPHAROS),
    SPECIES_TO_NATIONAL(AZURILL),
    SPECIES_TO_NATIONAL(MARILL),
    SPECIES_TO_NATIONAL(AZUMARILL),
    SPECIES_TO_NATIONAL(BONSLY),
    SPECIES_TO_NATIONAL(SUDOWOODO),
    SPECIES_TO_NATIONAL(HOPPIP),
    SPECIES_TO_NATIONAL(SKIPLOOM),
    SPECIES_TO_NATIONAL(JUMPLUFF),
    SPECIES_TO_NATIONAL(AIPOM),
    SPECIES_TO_NATIONAL(AMBIPOM),
    SPECIES_TO_NATIONAL(SUNKERN),
    SPECIES_TO_NATIONAL(SUNFLORA),
    SPECIES_TO_NATIONAL(YANMA),
    SPECIES_TO_NATIONAL(YANMEGA),
    SPECIES_TO_NATIONAL(WOOPER),
    SPECIES_TO_NATIONAL(QUAGSIRE),
    SPECIES_TO_NATIONAL(MURKROW),
    SPECIES_TO_NATIONAL(HONCHKROW),
    SPECIES_TO_NATIONAL(MISDREAVUS),
    SPECIES_TO_NATIONAL(MISMAGIUS),
    SPECIES_TO_NATIONAL(UNOWN),
    SPECIES_TO_NATIONAL(WYNAUT),
    SPECIES_TO_NATIONAL(WOBBUFFET),
    SPECIES_TO_NATIONAL(GIRAFARIG),
    SPECIES_TO_NATIONAL(PINECO),
    SPECIES_TO_NATIONAL(FORRETRESS),
    SPECIES_TO_NATIONAL(DUNSPARCE),
    SPECIES_TO_NATIONAL(GLIGAR),
    SPECIES_TO_NATIONAL(GLISCOR),
    SPECIES_TO_NATIONAL(SNUBBULL),
    SPECIES_TO_NATIONAL(GRANBULL),
    SPECIES_TO_NATIONAL(QWILFISH),
    SPECIES_TO_NATIONAL(NUMPUFF),
    SPECIES_TO_NATIONAL(SHUCKLE),
    SPECIES_TO_NATIONAL(HERACROSS),
    SPECIES_TO_NATIONAL(SNEASEL),
    SPECIES_TO_NATIONAL(WEAVILE),
    SPECIES_TO_NATIONAL(TEDDIURSA),
    SPECIES_TO_NATIONAL(URSARING),
    SPECIES_TO_NATIONAL(SLUGMA),
    SPECIES_TO_NATIONAL(MAGCARGO),
    SPECIES_TO_NATIONAL(SWINUB),
    SPECIES_TO_NATIONAL(PILOSWINE),
    SPECIES_TO_NATIONAL(MAMOSWINE),
    SPECIES_TO_NATIONAL(CORSOLA),
    SPECIES_TO_NATIONAL(REMORAID),
    SPECIES_TO_NATIONAL(OCTILLERY),
    SPECIES_TO_NATIONAL(DELIBIRD),
    SPECIES_TO_NATIONAL(MANTYKE),
    SPECIES_TO_NATIONAL(MANTINE),
    SPECIES_TO_NATIONAL(SKARMORY),
    SPECIES_TO_NATIONAL(HOUNDOUR),
    SPECIES_TO_NATIONAL(HOUNDOOM),
    SPECIES_TO_NATIONAL(PHANPY),
    SPECIES_TO_NATIONAL(DONPHAN),
    SPECIES_TO_NATIONAL(STANTLER),
    SPECIES_TO_NATIONAL(SMEARGLE),
    SPECIES_TO_NATIONAL(MILTANK),
    SPECIES_TO_NATIONAL(RAIKOU),
    SPECIES_TO_NATIONAL(ENTEI),
    SPECIES_TO_NATIONAL(SUICUNE),
    SPECIES_TO_NATIONAL(LARVITAR),
    SPECIES_TO_NATIONAL(PUPITAR),
    SPECIES_TO_NATIONAL(TYRANITAR),
    SPECIES_TO_NATIONAL(LUGIA),
    SPECIES_TO_NATIONAL(HO_OH),
    SPECIES_TO_NATIONAL(CELEBI),
    SPECIES_TO_NATIONAL(TREECKO),
    SPECIES_TO_NATIONAL(GROVYLE),
    SPECIES_TO_NATIONAL(SCEPTILE),
    SPECIES_TO_NATIONAL(TORCHIC),
    SPECIES_TO_NATIONAL(COMBUSKEN),
    SPECIES_TO_NATIONAL(BLAZIKEN),
    SPECIES_TO_NATIONAL(MUDKIP),
    SPECIES_TO_NATIONAL(MARSHTOMP),
    SPECIES_TO_NATIONAL(SWAMPERT),
    SPECIES_TO_NATIONAL(POOCHYENA),
    SPECIES_TO_NATIONAL(MIGHTYENA),
    SPECIES_TO_NATIONAL(ZIGZAGOON),
    SPECIES_TO_NATIONAL(LINOONE),
    SPECIES_TO_NATIONAL(OBSTAGOON),
    SPECIES_TO_NATIONAL(GALARIAN_ZIGZAGOON),
    SPECIES_TO_NATIONAL(GALARIAN_LINOONE),
    SPECIES_TO_NATIONAL(GALARIAN_OBSTAGOON),
    SPECIES_TO_NATIONAL(WURMPLE),
    SPECIES_TO_NATIONAL(SILCOON),
    SPECIES_TO_NATIONAL(BEAUTIFLY),
    SPECIES_TO_NATIONAL(CASCOON),
    SPECIES_TO_NATIONAL(DUSTOX),
    SPECIES_TO_NATIONAL(LOTAD),
    SPECIES_TO_NATIONAL(LOMBRE),
    SPECIES_TO_NATIONAL(LUDICOLO),
    SPECIES_TO_NATIONAL(SEEDOT),
    SPECIES_TO_NATIONAL(NUZLEAF),
    SPECIES_TO_NATIONAL(SHIFTRY),
    SPECIES_TO_NATIONAL(TAILLOW),
    SPECIES_TO_NATIONAL(SWELLOW),
    SPECIES_TO_NATIONAL(WINGULL),
    SPECIES_TO_NATIONAL(PELIPPER),
    SPECIES_TO_NATIONAL(RALTS),
    SPECIES_TO_NATIONAL(KIRLIA),
    SPECIES_TO_NATIONAL(GARDEVOIR),
    SPECIES_TO_NATIONAL(GALLADE),
    SPECIES_TO_NATIONAL(SURSKIT),
    SPECIES_TO_NATIONAL(MASQUERAIN),
    SPECIES_TO_NATIONAL(SHROOMISH),
    SPECIES_TO_NATIONAL(BRELOOM),
    SPECIES_TO_NATIONAL(SLAKOTH),
    SPECIES_TO_NATIONAL(VIGOROTH),
    SPECIES_TO_NATIONAL(SLAKING),
    SPECIES_TO_NATIONAL(NINCADA),
    SPECIES_TO_NATIONAL(NINJASK),
    SPECIES_TO_NATIONAL(SHEDINJA),
    SPECIES_TO_NATIONAL(WHISMUR),
    SPECIES_TO_NATIONAL(LOUDRED),
    SPECIES_TO_NATIONAL(EXPLOUD),
    SPECIES_TO_NATIONAL(MAKUHITA),
    SPECIES_TO_NATIONAL(HARIYAMA),
    SPECIES_TO_NATIONAL(NOSEPASS),
    SPECIES_TO_NATIONAL(PROBOPASS),
    SPECIES_TO_NATIONAL(SKITTY),
    SPECIES_TO_NATIONAL(DELCATTY),
    SPECIES_TO_NATIONAL(SABLEYE),
    SPECIES_TO_NATIONAL(MAWILE),
    SPECIES_TO_NATIONAL(ARON),
    SPECIES_TO_NATIONAL(LAIRON),
    SPECIES_TO_NATIONAL(AGGRON),
    SPECIES_TO_NATIONAL(MEDITITE),
    SPECIES_TO_NATIONAL(MEDICHAM),
    SPECIES_TO_NATIONAL(ELECTRIKE),
    SPECIES_TO_NATIONAL(MANECTRIC),
    SPECIES_TO_NATIONAL(PLUSLE),
    SPECIES_TO_NATIONAL(MINUN),
    SPECIES_TO_NATIONAL(VOLBEAT),
    SPECIES_TO_NATIONAL(ILLUMISE),
    SPECIES_TO_NATIONAL(BUDEW),
    SPECIES_TO_NATIONAL(ROSELIA),
    SPECIES_TO_NATIONAL(ROSERADE),
    SPECIES_TO_NATIONAL(GULPIN),
    SPECIES_TO_NATIONAL(SWALOT),
    SPECIES_TO_NATIONAL(CARVANHA),
    SPECIES_TO_NATIONAL(SHARPEDO),
    SPECIES_TO_NATIONAL(WAILMER),
    SPECIES_TO_NATIONAL(WAILORD),
    SPECIES_TO_NATIONAL(NUMEL),
    SPECIES_TO_NATIONAL(CAMERUPT),
    SPECIES_TO_NATIONAL(TORKOAL),
    SPECIES_TO_NATIONAL(SPOINK),
    SPECIES_TO_NATIONAL(GRUMPIG),
    SPECIES_TO_NATIONAL(SPINDA),
    SPECIES_TO_NATIONAL(TRAPINCH),
    SPECIES_TO_NATIONAL(VIBRAVA),
    SPECIES_TO_NATIONAL(FLYGON),
    SPECIES_TO_NATIONAL(CACNEA),
    SPECIES_TO_NATIONAL(CACTURNE),
    SPECIES_TO_NATIONAL(SWABLU),
    SPECIES_TO_NATIONAL(ALTARIA),
    SPECIES_TO_NATIONAL(ZANGOOSE),
    SPECIES_TO_NATIONAL(SEVIPER),
    SPECIES_TO_NATIONAL(LUNATONE),
    SPECIES_TO_NATIONAL(SOLROCK),
    SPECIES_TO_NATIONAL(BARBOACH),
    SPECIES_TO_NATIONAL(WHISCASH),
    SPECIES_TO_NATIONAL(CORPHISH),
    SPECIES_TO_NATIONAL(CRAWDAUNT),
    SPECIES_TO_NATIONAL(BALTOY),
    SPECIES_TO_NATIONAL(CLAYDOL),
    SPECIES_TO_NATIONAL(LILEEP),
    SPECIES_TO_NATIONAL(CRADILY),
    SPECIES_TO_NATIONAL(ANORITH),
    SPECIES_TO_NATIONAL(ARMALDO),
    SPECIES_TO_NATIONAL(FEEBAS),
    SPECIES_TO_NATIONAL(MILOTIC),
    SPECIES_TO_NATIONAL(CASTFORM),
    SPECIES_TO_NATIONAL(KECLEON),
    SPECIES_TO_NATIONAL(SHUPPET),
    SPECIES_TO_NATIONAL(BANETTE),
    SPECIES_TO_NATIONAL(DUSKULL),
    SPECIES_TO_NATIONAL(DUSCLOPS),
    SPECIES_TO_NATIONAL(DUSKNOIR),
    SPECIES_TO_NATIONAL(TROPIUS),
    SPECIES_TO_NATIONAL(CHINGLING),
    SPECIES_TO_NATIONAL(CHIMECHO),
    SPECIES_TO_NATIONAL(ABSOL),
    SPECIES_TO_NATIONAL(SNORUNT),
    SPECIES_TO_NATIONAL(GLALIE),
    SPECIES_TO_NATIONAL(FROSLASS),
    SPECIES_TO_NATIONAL(SPHEAL),
    SPECIES_TO_NATIONAL(SEALEO),
    SPECIES_TO_NATIONAL(WALREIN),
    SPECIES_TO_NATIONAL(CLAMPERL),
    SPECIES_TO_NATIONAL(HUNTAIL),
    SPECIES_TO_NATIONAL(GOREBYSS),
    SPECIES_TO_NATIONAL(RELICANTH),
    SPECIES_TO_NATIONAL(LUVDISC),
    SPECIES_TO_NATIONAL(BAGON),
    SPECIES_TO_NATIONAL(SHELGON),
    SPECIES_TO_NATIONAL(SALAMENCE),
    SPECIES_TO_NATIONAL(BELDUM),
    SPECIES_TO_NATIONAL(METANG),
    SPECIES_TO_NATIONAL(METAGROSS),
    SPECIES_TO_NATIONAL(REGIROCK),
    SPECIES_TO_NATIONAL(REGICE),
    SPECIES_TO_NATIONAL(REGISTEEL),
    SPECIES_TO_NATIONAL(LATIAS),
    SPECIES_TO_NATIONAL(LATIOS),
    SPECIES_TO_NATIONAL(KYOGRE),
    SPECIES_TO_NATIONAL(GROUDON),
    SPECIES_TO_NATIONAL(RAYQUAZA),
    SPECIES_TO_NATIONAL(JIRACHI),
    SPECIES_TO_NATIONAL(DEOXYS),
    SPECIES_TO_NATIONAL(CLONE_BULBASAUR),
    SPECIES_TO_NATIONAL(CLONE_IVYSAUR),
    SPECIES_TO_NATIONAL(CLONE_VENUSAUR),
    SPECIES_TO_NATIONAL(CLONE_CHARMANDER),
    SPECIES_TO_NATIONAL(CLONE_CHARMELEON),
    SPECIES_TO_NATIONAL(CLONE_CHARIZARD),
    SPECIES_TO_NATIONAL(CLONE_SQUIRTLE),
    SPECIES_TO_NATIONAL(CLONE_WARTORTLE),
    SPECIES_TO_NATIONAL(CLONE_BLASTOISE),
};
// >

< //
bool8 HasTwoFramesAnimation(u16 species)
{
    return (species != SPECIES_CASTFORM
            && species != SPECIES_DEOXYS
            && species != SPECIES_SPINDA
            && species != SPECIES_UNOWN);
}

static bool8 ShouldSkipFriendshipChange(void)
// >

< //
static const u8 sMonFrontAnimIdsTable[NUM_SPECIES - 1] =
{
    [SPECIES_BULBASAUR - 1] = 0x06,
    [SPECIES_IVYSAUR - 1] = 0x17,
    [SPECIES_VENUSAUR - 1] = 0x2f,
    [SPECIES_CHARMANDER - 1] = 0x52,
    [SPECIES_CHARMELEON - 1] = 0x25,
    [SPECIES_CHARIZARD - 1] = 0x10,
    [SPECIES_SQUIRTLE - 1] = 0x0b,
    [SPECIES_WARTORTLE - 1] = 0x13,
    [SPECIES_BLASTOISE - 1] = 0x19,
    [SPECIES_CATERPIE - 1] = 0x0b,
    [SPECIES_METAPOD - 1] = 0x0b,
    [SPECIES_BUTTERFREE - 1] = 0x1d,
    [SPECIES_WEEDLE - 1] = 0x46,
    [SPECIES_KAKUNA - 1] = 0x20,
    [SPECIES_BEEDRILL - 1] = 0x02,
    [SPECIES_PIDGEY - 1] = 0x47,
    [SPECIES_PIDGEOTTO - 1] = 0x17,
    [SPECIES_PIDGEOT - 1] = 0x29,
    [SPECIES_RATTATA - 1] = 0x43,
    [SPECIES_RATICATE - 1] = 0x2b,
    [SPECIES_SPEAROW - 1] = 0x18,
    [SPECIES_FEAROW - 1] = 0x2b,
    [SPECIES_EKANS - 1] = 0x16,
    [SPECIES_ARBOK - 1] = 0x17,
    [SPECIES_PIKACHU - 1] = 0x2c,
    [SPECIES_RAICHU - 1] = 0x17,
    [SPECIES_SANDSHREW - 1] = 0x2d,
    [SPECIES_SANDSLASH - 1] = 0x17,
    [SPECIES_NIDORAN_F - 1] = 0x00,
    [SPECIES_NIDORINA - 1] = 0x17,
    [SPECIES_NIDOQUEEN - 1] = 0x0f,
    [SPECIES_NIDORAN_M - 1] = 0x09,
    [SPECIES_NIDORINO - 1] = 0x13,
    [SPECIES_NIDOKING - 1] = 0x0f,
    [SPECIES_CLEFAIRY - 1] = 0x00,
    [SPECIES_CLEFABLE - 1] = 0x4a,
    [SPECIES_VULPIX - 1] = 0x17,
    [SPECIES_NINETALES - 1] = 0x10,
    [SPECIES_JIGGLYPUFF - 1] = 0x48,
    [SPECIES_WIGGLYTUFF - 1] = 0x31,
    [SPECIES_ZUBAT - 1] = 0x00,
    [SPECIES_GOLBAT - 1] = 0x1d,
    [SPECIES_ODDISH - 1] = 0x00,
    [SPECIES_GLOOM - 1] = 0x45,
    [SPECIES_VILEPLUME - 1] = 0x49,
    [SPECIES_PARAS - 1] = 0x46,
    [SPECIES_PARASECT - 1] = 0x0f,
    [SPECIES_VENONAT - 1] = 0x06,
    [SPECIES_VENOMOTH - 1] = 0x4b,
    [SPECIES_DIGLETT - 1] = 0x10,
    [SPECIES_DUGTRIO - 1] = 0x4c,
    [SPECIES_MEOWSY - 1] = 0x17,
    [SPECIES_MEOWTH - 1] = 0x52,
    [SPECIES_PERSIAN - 1] = 0x17,
    [SPECIES_PSYDUCK - 1] = 0x06,
    [SPECIES_GOLDUCK - 1] = 0x4c,
    [SPECIES_MANKEY - 1] = 0x32,
    [SPECIES_PRIMEAPE - 1] = 0x48,
    [SPECIES_GROWLITHE - 1] = 0x25,
    [SPECIES_ARCANINE - 1] = 0x02,
    [SPECIES_POLIWAG - 1] = 0x00,
    [SPECIES_POLIWHIRL - 1] = 0x32,
    [SPECIES_POLIWRATH - 1] = 0x19,
    [SPECIES_ABRA - 1] = 0x31,
    [SPECIES_KADABRA - 1] = 0x09,
    [SPECIES_ALAKAZAM - 1] = 0x17,
    [SPECIES_MACHOP - 1] = 0x00,
    [SPECIES_MACHOKE - 1] = 0x10,
    [SPECIES_MACHAMP - 1] = 0x31,
    [SPECIES_BELLSPROUT - 1] = 0x17,
    [SPECIES_WEEPINBELL - 1] = 0x0d,
    [SPECIES_VICTREEBEL - 1] = 0x32,
    [SPECIES_TENTACOOL - 1] = 0x00,
    [SPECIES_TENTACRUEL - 1] = 0x00,
    [SPECIES_GEODUDE - 1] = 0x48,
    [SPECIES_GRAVELER - 1] = 0x48,
    [SPECIES_GOLEM - 1] = 0x2f,
    [SPECIES_PONYTA - 1] = 0x20,
    [SPECIES_RAPIDASH - 1] = 0x11,
    [SPECIES_SLOWPOKE - 1] = 0x45,
    [SPECIES_SLOWBRO - 1] = 0x0b,
    [SPECIES_MAGNEMITE - 1] = 0x54,
    [SPECIES_MAGNETON - 1] = 0x2c,
    [SPECIES_FARFETCHD - 1] = 0x48,
    [SPECIES_CHICKS - 1] = 0x43,
    [SPECIES_DODUO - 1] = 0x4c,
    [SPECIES_DODRIO - 1] = 0x41,
    [SPECIES_SEEL - 1] = 0x0b,
    [SPECIES_DEWGONG - 1] = 0x45,
    [SPECIES_GRIMER - 1] = 0x46,
    [SPECIES_MUK - 1] = 0x30,
    [SPECIES_SHELLDER - 1] = 0x12,
    [SPECIES_CLOYSTER - 1] = 0x1d,
    [SPECIES_GASTLY - 1] = 0x15,
    [SPECIES_HAUNTER - 1] = 0x35,
    [SPECIES_GENGAR - 1] = 0x3a,
    [SPECIES_ONIX - 1] = 0x43,
    [SPECIES_DROWZEE - 1] = 0x4f,
    [SPECIES_HYPNO - 1] = 0x09,
    [SPECIES_KRABBY - 1] = 0x03,
    [SPECIES_KINGLER - 1] = 0x4b,
    [SPECIES_VOLTORB - 1] = 0x00,
    [SPECIES_ELECTRODE - 1] = 0x00,
    [SPECIES_EXEGGCUTE - 1] = 0x46,
    [SPECIES_EXEGGUTOR - 1] = 0x32,
    [SPECIES_CUBONE - 1] = 0x48,
    [SPECIES_MAROWAK - 1] = 0x05,
    [SPECIES_HITMONLEE - 1] = 0x16,
    [SPECIES_HITMONCHAN - 1] = 0x09,
    [SPECIES_LICKITUNG - 1] = 0x45,
    [SPECIES_KOFFING - 1] = 0x13,
    [SPECIES_WEEZING - 1] = 0x04,
    [SPECIES_RHYHORN - 1] = 0x10,
    [SPECIES_RHYDON - 1] = 0x13,
    [SPECIES_CHANSEY - 1] = 0x45,
    [SPECIES_TANGELA - 1] = 0x48,
    [SPECIES_KANGASKHAN - 1] = 0x17,
    [SPECIES_HORSEA - 1] = 0x12,
    [SPECIES_SEADRA - 1] = 0x04,
    [SPECIES_GOLDEEN - 1] = 0x0d,
    [SPECIES_SEAKING - 1] = 0x1c,
    [SPECIES_STARYU - 1] = 0x4e,
    [SPECIES_STARMIE - 1] = 0x12,
    [SPECIES_MR_MIME - 1] = 0x46,
    [SPECIES_SCYTHER - 1] = 0x02,
    [SPECIES_JYNX - 1] = 0x17,
    [SPECIES_ELECTABUZZ - 1] = 0x2c,
    [SPECIES_MAGMAR - 1] = 0x0f,
    [SPECIES_PINSIR - 1] = 0x09,
    [SPECIES_TAUROS - 1] = 0x19,
    [SPECIES_MAGIKARP - 1] = 0x05,
    [SPECIES_GYARADOS - 1] = 0x48,
    [SPECIES_LAPRAS - 1] = 0x17,
    [SPECIES_DITTO - 1] = 0x01,
    [SPECIES_EEVEE - 1] = 0x17,
    [SPECIES_VAPOREON - 1] = 0x17,
    [SPECIES_JOLTEON - 1] = 0x00,
    [SPECIES_FLAREON - 1] = 0x17,
    [SPECIES_PORYGON - 1] = 0x52,
    [SPECIES_OMANYTE - 1] = 0x51,
    [SPECIES_OMASTAR - 1] = 0x09,
    [SPECIES_KABUTO - 1] = 0x1d,
    [SPECIES_KABUTOPS - 1] = 0x0f,
    [SPECIES_AERODACTYL - 1] = 0x47,
    [SPECIES_SNORLAX - 1] = 0x0b,
    [SPECIES_ARTICUNO - 1] = 0x09,
    [SPECIES_ZAPDOS - 1] = 0x2c,
    [SPECIES_MOLTRES - 1] = 0x45,
    [SPECIES_DRATINI - 1] = 0x00,
    [SPECIES_DRAGONAIR - 1] = 0x10,
    [SPECIES_DRAGONITE - 1] = 0x47,
    [SPECIES_MEWTWO - 1] = 0x09,
    [SPECIES_MEW - 1] = 0x0d,
    [SPECIES_CHIKORITA - 1] = 0x00,
    [SPECIES_BAYLEEF - 1] = 0x00,
    [SPECIES_MEGANIUM - 1] = 0x17,
    [SPECIES_CYNDAQUIL - 1] = 0x52,
    [SPECIES_QUILAVA - 1] = 0x17,
    [SPECIES_TYPHLOSION - 1] = 0x10,
    [SPECIES_TOTODILE - 1] = 0x31,
    [SPECIES_CROCONAW - 1] = 0x0f,
    [SPECIES_FERALIGATR - 1] = 0x0f,
    [SPECIES_SENTRET - 1] = 0x00,
    [SPECIES_FURRET - 1] = 0x32,
    [SPECIES_HOOTHOOT - 1] = 0x47,
    [SPECIES_NOCTOWL - 1] = 0x17,
    [SPECIES_LEDYBA - 1] = 0x52,
    [SPECIES_LEDIAN - 1] = 0x47,
    [SPECIES_SPINARAK - 1] = 0x4f,
    [SPECIES_ARIADOS - 1] = 0x0f,
    [SPECIES_CROBAT - 1] = 0x00,
    [SPECIES_CHINCHOU - 1] = 0x45,
    [SPECIES_LANTURN - 1] = 0x51,
    [SPECIES_PICHU - 1] = 0x1e,
    [SPECIES_CLEFFA - 1] = 0x52,
    [SPECIES_IGGLYBUFF - 1] = 0x0c,
    [SPECIES_TOGEPI - 1] = 0x0b,
    [SPECIES_TOGETIC - 1] = 0x00,
    [SPECIES_NATU - 1] = 0x31,
    [SPECIES_XATU - 1] = 0x09,
    [SPECIES_MAREEP - 1] = 0x00,
    [SPECIES_FLAAFFY - 1] = 0x1e,
    [SPECIES_AMPHAROS - 1] = 0x2c,
    [SPECIES_BELLOSSOM - 1] = 0x0b,
    [SPECIES_MARILL - 1] = 0x00,
    [SPECIES_AZUMARILL - 1] = 0x4a,
    [SPECIES_SUDOWOODO - 1] = 0x46,
    [SPECIES_POLITOED - 1] = 0x32,
    [SPECIES_HOPPIP - 1] = 0x1c,
    [SPECIES_SKIPLOOM - 1] = 0x18,
    [SPECIES_JUMPLUFF - 1] = 0x51,
    [SPECIES_AIPOM - 1] = 0x32,
    [SPECIES_SUNKERN - 1] = 0x52,
    [SPECIES_SUNFLORA - 1] = 0x00,
    [SPECIES_YANMA - 1] = 0x2b,
    [SPECIES_WOOPER - 1] = 0x00,
    [SPECIES_QUAGSIRE - 1] = 0x16,
    [SPECIES_ESPEON - 1] = 0x09,
    [SPECIES_UMBREON - 1] = 0x10,
    [SPECIES_MURKROW - 1] = 0x00,
    [SPECIES_SLOWKING - 1] = 0x13,
    [SPECIES_MISDREAVUS - 1] = 0x1c,
    [SPECIES_UNOWN - 1] = 0x0a,
    [SPECIES_WOBBUFFET - 1] = 0x30,
    [SPECIES_GIRAFARIG - 1] = 0x1e,
    [SPECIES_PINECO - 1] = 0x0b,
    [SPECIES_FORRETRESS - 1] = 0x10,
    [SPECIES_DUNSPARCE - 1] = 0x00,
    [SPECIES_GLIGAR - 1] = 0x13,
    [SPECIES_STEELIX - 1] = 0x0f,
    [SPECIES_SNUBBULL - 1] = 0x17,
    [SPECIES_GRANBULL - 1] = 0x10,
    [SPECIES_QWILFISH - 1] = 0x3a,
    [SPECIES_SCIZOR - 1] = 0x02,
    [SPECIES_SHUCKLE - 1] = 0x0b,
    [SPECIES_HERACROSS - 1] = 0x41,
    [SPECIES_SNEASEL - 1] = 0x16,
    [SPECIES_TEDDIURSA - 1] = 0x17,
    [SPECIES_URSARING - 1] = 0x10,
    [SPECIES_SLUGMA - 1] = 0x17,
    [SPECIES_MAGCARGO - 1] = 0x17,
    [SPECIES_SWINUB - 1] = 0x00,
    [SPECIES_PILOSWINE - 1] = 0x0f,
    [SPECIES_CORSOLA - 1] = 0x03,
    [SPECIES_REMORAID - 1] = 0x52,
    [SPECIES_OCTILLERY - 1] = 0x17,
    [SPECIES_DELIBIRD - 1] = 0x52,
    [SPECIES_MANTINE - 1] = 0x0d,
    [SPECIES_SKARMORY - 1] = 0x17,
    [SPECIES_HOUNDOUR - 1] = 0x17,
    [SPECIES_HOUNDOOM - 1] = 0x10,
    [SPECIES_KINGDRA - 1] = 0x42,
    [SPECIES_PHANPY - 1] = 0x32,
    [SPECIES_DONPHAN - 1] = 0x19,
    [SPECIES_PORYGON2 - 1] = 0x00,
    [SPECIES_STANTLER - 1] = 0x00,
    [SPECIES_SMEARGLE - 1] = 0x31,
    [SPECIES_TYROGUE - 1] = 0x16,
    [SPECIES_HITMONTOP - 1] = 0x02,
    [SPECIES_SMOOCHUM - 1] = 0x09,
    [SPECIES_ELEKID - 1] = 0x2c,
    [SPECIES_MAGBY - 1] = 0x00,
    [SPECIES_MILTANK - 1] = 0x45,
    [SPECIES_BLISSEY - 1] = 0x00,
    [SPECIES_RAIKOU - 1] = 0x2c,
    [SPECIES_ENTEI - 1] = 0x09,
    [SPECIES_SUICUNE - 1] = 0x10,
    [SPECIES_LARVITAR - 1] = 0x52,
    [SPECIES_PUPITAR - 1] = 0x10,
    [SPECIES_TYRANITAR - 1] = 0x0f,
    [SPECIES_LUGIA - 1] = 0x3a,
    [SPECIES_HO_OH - 1] = 0x09,
    [SPECIES_CELEBI - 1] = 0x18,
    [SPECIES_TREECKO - 1] = 0x00,
    [SPECIES_GROVYLE - 1] = 0x17,
    [SPECIES_SCEPTILE - 1] = 0x10,
    [SPECIES_TORCHIC - 1] = 0x16,
    [SPECIES_COMBUSKEN - 1] = 0x06,
    [SPECIES_BLAZIKEN - 1] = 0x0f,
    [SPECIES_MUDKIP - 1] = 0x01,
    [SPECIES_MARSHTOMP - 1] = 0x04,
    [SPECIES_SWAMPERT - 1] = 0x1e,
    [SPECIES_POOCHYENA - 1] = 0x10,
    [SPECIES_MIGHTYENA - 1] = 0x10,
    [SPECIES_ZIGZAGOON - 1] = 0x03,
    [SPECIES_LINOONE - 1] = 0x09,
    [SPECIES_OBSTAGOON - 1] = 0x50,
    [SPECIES_GALARIAN_ZIGZAGOON - 1] = 0x31,
    [SPECIES_GALARIAN_LINOONE - 1] = 0x25,
    [SPECIES_GALARIAN_OBSTAGOON - 1] = 0x50,
    [SPECIES_WURMPLE - 1] = 0x00,
    [SPECIES_SILCOON - 1] = 0x00,
    [SPECIES_BEAUTIFLY - 1] = 0x04,
    [SPECIES_CASCOON - 1] = 0x04,
    [SPECIES_DUSTOX - 1] = 0x06,
    [SPECIES_LOTAD - 1] = 0x00,
    [SPECIES_LOMBRE - 1] = 0x00,
    [SPECIES_LUDICOLO - 1] = 0x49,
    [SPECIES_SEEDOT - 1] = 0x05,
    [SPECIES_NUZLEAF - 1] = 0x00,
    [SPECIES_SHIFTRY - 1] = 0x02,
    [SPECIES_NINCADA - 1] = 0x00,
    [SPECIES_NINJASK - 1] = 0x46,
    [SPECIES_SHEDINJA - 1] = 0x1c,
    [SPECIES_TAILLOW - 1] = 0x1e,
    [SPECIES_SWELLOW - 1] = 0x01,
    [SPECIES_SHROOMISH - 1] = 0x00,
    [SPECIES_BRELOOM - 1] = 0x00,
    [SPECIES_SPINDA - 1] = 0x31,
    [SPECIES_WINGULL - 1] = 0x1b,
    [SPECIES_PELIPPER - 1] = 0x1c,
    [SPECIES_SURSKIT - 1] = 0x00,
    [SPECIES_MASQUERAIN - 1] = 0x00,
    [SPECIES_WAILMER - 1] = 0x01,
    [SPECIES_WAILORD - 1] = 0x1c,
    [SPECIES_SKITTY - 1] = 0x00,
    [SPECIES_DELCATTY - 1] = 0x17,
    [SPECIES_KECLEON - 1] = 0x35,
    [SPECIES_BALTOY - 1] = 0x1d,
    [SPECIES_CLAYDOL - 1] = 0x51,
    [SPECIES_NOSEPASS - 1] = 0x49,
    [SPECIES_TORKOAL - 1] = 0x17,
    [SPECIES_SABLEYE - 1] = 0x15,
    [SPECIES_BARBOACH - 1] = 0x49,
    [SPECIES_WHISCASH - 1] = 0x49,
    [SPECIES_LUVDISC - 1] = 0x1d,
    [SPECIES_CORPHISH - 1] = 0x10,
    [SPECIES_CRAWDAUNT - 1] = 0x09,
    [SPECIES_FEEBAS - 1] = 0x49,
    [SPECIES_MILOTIC - 1] = 0x22,
    [SPECIES_CARVANHA - 1] = 0x49,
    [SPECIES_SHARPEDO - 1] = 0x56,
    [SPECIES_TRAPINCH - 1] = 0x10,
    [SPECIES_VIBRAVA - 1] = 0x0f,
    [SPECIES_FLYGON - 1] = 0x4b,
    [SPECIES_MAKUHITA - 1] = 0x0b,
    [SPECIES_HARIYAMA - 1] = 0x34,
    [SPECIES_ELECTRIKE - 1] = 0x00,
    [SPECIES_MANECTRIC - 1] = 0x00,
    [SPECIES_NUMEL - 1] = 0x04,
    [SPECIES_CAMERUPT - 1] = 0x10,
    [SPECIES_SPHEAL - 1] = 0x53,
    [SPECIES_SEALEO - 1] = 0x17,
    [SPECIES_WALREIN - 1] = 0x0f,
    [SPECIES_CACNEA - 1] = 0x49,
    [SPECIES_CACTURNE - 1] = 0x04,
    [SPECIES_SNORUNT - 1] = 0x45,
    [SPECIES_GLALIE - 1] = 0x0a,
    [SPECIES_LUNATONE - 1] = 0x0e,
    [SPECIES_SOLROCK - 1] = 0x08,
    [SPECIES_AZURILL - 1] = 0x00,
    [SPECIES_SPOINK - 1] = 0x56,
    [SPECIES_GRUMPIG - 1] = 0x32,
    [SPECIES_PLUSLE - 1] = 0x00,
    [SPECIES_MINUN - 1] = 0x01,
    [SPECIES_MAWILE - 1] = 0x00,
    [SPECIES_MEDITITE - 1] = 0x05,
    [SPECIES_MEDICHAM - 1] = 0x45,
    [SPECIES_SWABLU - 1] = 0x04,
    [SPECIES_ALTARIA - 1] = 0x16,
    [SPECIES_WYNAUT - 1] = 0x32,
    [SPECIES_DUSKULL - 1] = 0x0a,
    [SPECIES_DUSCLOPS - 1] = 0x02,
    [SPECIES_ROSELIA - 1] = 0x45,
    [SPECIES_SLAKOTH - 1] = 0x45,
    [SPECIES_VIGOROTH - 1] = 0x31,
    [SPECIES_SLAKING - 1] = 0x45,
    [SPECIES_GULPIN - 1] = 0x00,
    [SPECIES_SWALOT - 1] = 0x45,
    [SPECIES_TROPIUS - 1] = 0x10,
    [SPECIES_WHISMUR - 1] = 0x03,
    [SPECIES_LOUDRED - 1] = 0x49,
    [SPECIES_EXPLOUD - 1] = 0x19,
    [SPECIES_CLAMPERL - 1] = 0x12,
    [SPECIES_HUNTAIL - 1] = 0x09,
    [SPECIES_GOREBYSS - 1] = 0x1c,
    [SPECIES_ABSOL - 1] = 0x11,
    [SPECIES_SHUPPET - 1] = 0x1c,
    [SPECIES_BANETTE - 1] = 0x0d,
    [SPECIES_SEVIPER - 1] = 0x17,
    [SPECIES_ZANGOOSE - 1] = 0x09,
    [SPECIES_RELICANTH - 1] = 0x1a,
    [SPECIES_ARON - 1] = 0x45,
    [SPECIES_LAIRON - 1] = 0x00,
    [SPECIES_AGGRON - 1] = 0x19,
    [SPECIES_CASTFORM - 1] = 0x1d,
    [SPECIES_VOLBEAT - 1] = 0x00,
    [SPECIES_ILLUMISE - 1] = 0x05,
    [SPECIES_LILEEP - 1] = 0x17,
    [SPECIES_CRADILY - 1] = 0x19,
    [SPECIES_ANORITH - 1] = 0x12,
    [SPECIES_ARMALDO - 1] = 0x10,
    [SPECIES_RALTS - 1] = 0x45,
    [SPECIES_KIRLIA - 1] = 0x00,
    [SPECIES_GARDEVOIR - 1] = 0x00,
    [SPECIES_BAGON - 1] = 0x19,
    [SPECIES_SHELGON - 1] = 0x04,
    [SPECIES_SALAMENCE - 1] = 0x0f,
    [SPECIES_BELDUM - 1] = 0x0f,
    [SPECIES_METANG - 1] = 0x04,
    [SPECIES_METAGROSS - 1] = 0x10,
    [SPECIES_REGIROCK - 1] = 0x01,
    [SPECIES_REGICE - 1] = 0x44,
    [SPECIES_REGISTEEL - 1] = 0x09,
    [SPECIES_KYOGRE - 1] = 0x2d,
    [SPECIES_GROUDON - 1] = 0x10,
    [SPECIES_RAYQUAZA - 1] = 0x0f,
    [SPECIES_LATIAS - 1] = 0x2d,
    [SPECIES_LATIOS - 1] = 0x10,
    [SPECIES_JIRACHI - 1] = 0x0d,
    [SPECIES_DEOXYS - 1] = 0x1b,
    [SPECIES_CHIMECHO - 1] = 0x1d,
    [SPECIES_AMBIPOM - 1] = 0x25,
    [SPECIES_MISMAGIUS - 1] = 0x0E,
    [SPECIES_HONCHKROW - 1] = 0x15,
    [SPECIES_CHINGLING - 1] = 0x1D,
    [SPECIES_BONSLY - 1] = 0x52,
    [SPECIES_MIMEJR - 1] = 0x40,
    [SPECIES_HAPPINY - 1] = 0x45,
    [SPECIES_MUNCHLAX - 1] = 0x13,
    [SPECIES_MANTYKE - 1] = 0x4E,
    [SPECIES_WEAVILE - 1] = 0xF,
    [SPECIES_MAGNEZONE - 1] = 0x23,
    [SPECIES_LICKILICKY - 1] = 0x2F,
    [SPECIES_RHYPERIOR - 1] = 0x41,
    [SPECIES_TANGROWTH - 1] = 0x3A,
    [SPECIES_ELECTIVIRE - 1] = 0x23,
    [SPECIES_MAGMORTAR - 1] = 0x21,
    [SPECIES_TOGEKISS - 1] = 0x1A,
    [SPECIES_YANMEGA - 1] = 0xA,
    [SPECIES_LEAFEON - 1] = 0x52,
    [SPECIES_GLACEON - 1] = 0x17,
    [SPECIES_GLISCOR - 1] = 0x12,
    [SPECIES_MAMOSWINE - 1] = 0x1E,
    [SPECIES_PORYGON_Z - 1] = 0x1C,
    [SPECIES_GALLADE - 1] = 0x13,
    [SPECIES_PROBOPASS - 1] = 0xE,
    [SPECIES_DUSKNOIR - 1] = 0x15,
    [SPECIES_FROSLASS - 1] = 0x1C,
    [SPECIES_SYLVEON - 1] = 0x16,
};

static const u8 sMonAnimationDelayTable[NUM_SPECIES - 1] =
{
    [SPECIES_BLASTOISE - 1] = 0x32,
    [SPECIES_WEEDLE - 1] = 0x0a,
    [SPECIES_KAKUNA - 1] = 0x14,
    [SPECIES_BEEDRILL - 1] = 0x23,
    [SPECIES_PIDGEOTTO - 1] = 0x19,
    [SPECIES_FEAROW - 1] = 0x02,
    [SPECIES_EKANS - 1] = 0x1e,
    [SPECIES_NIDORAN_F - 1] = 0x1c,
    [SPECIES_NIDOKING - 1] = 0x19,
    [SPECIES_PARAS - 1] = 0x0a,
    [SPECIES_PARASECT - 1] = 0x2d,
    [SPECIES_VENONAT - 1] = 0x14,
    [SPECIES_DIGLETT - 1] = 0x19,
    [SPECIES_DUGTRIO - 1] = 0x23,
    [SPECIES_MEOWTH - 1] = 0x28,
    [SPECIES_PERSIAN - 1] = 0x14,
    [SPECIES_MANKEY - 1] = 0x14,
    [SPECIES_GROWLITHE - 1] = 0x1e,
    [SPECIES_ARCANINE - 1] = 0x28,
    [SPECIES_POLIWHIRL - 1] = 0x05,
    [SPECIES_WEEPINBELL - 1] = 0x03,
    [SPECIES_MUK - 1] = 0x2d,
    [SPECIES_SHELLDER - 1] = 0x14,
    [SPECIES_HAUNTER - 1] = 0x17,
    [SPECIES_DROWZEE - 1] = 0x30,
    [SPECIES_HYPNO - 1] = 0x28,
    [SPECIES_HITMONCHAN - 1] = 0x19,
    [SPECIES_SCYTHER - 1] = 0x0a,
    [SPECIES_TAUROS - 1] = 0x0a,
    [SPECIES_TYPHLOSION - 1] = 0x14,
    [SPECIES_FERALIGATR - 1] = 0x05,
    [SPECIES_NATU - 1] = 0x1e,
    [SPECIES_MAREEP - 1] = 0x32,
    [SPECIES_AMPHAROS - 1] = 0x0a,
    [SPECIES_POLITOED - 1] = 0x28,
    [SPECIES_DUNSPARCE - 1] = 0x0a,
    [SPECIES_STEELIX - 1] = 0x2d,
    [SPECIES_QWILFISH - 1] = 0x27,
    [SPECIES_SCIZOR - 1] = 0x13,
    [SPECIES_OCTILLERY - 1] = 0x14,
    [SPECIES_SMOOCHUM - 1] = 0x28,
    [SPECIES_TYRANITAR - 1] = 0x0a,
    [SPECIES_LUGIA - 1] = 0x14,
    [SPECIES_WAILORD - 1] = 0x0a,
    [SPECIES_KECLEON - 1] = 0x1e,
    [SPECIES_MILOTIC - 1] = 0x2d,
    [SPECIES_SPHEAL - 1] = 0x0f,
    [SPECIES_SNORUNT - 1] = 0x14,
    [SPECIES_GRUMPIG - 1] = 0x0f,
    [SPECIES_WYNAUT - 1] = 0x0f,
    [SPECIES_DUSCLOPS - 1] = 0x1e,
    [SPECIES_ABSOL - 1] = 0x2d,
    [SPECIES_SALAMENCE - 1] = 0x46,
    [SPECIES_KYOGRE - 1] = 0x3c,
    [SPECIES_RAYQUAZA - 1] = 0x3c,
};

const u8 gPPUpGetMask[] = {0x03, 0x0c, 0x30, 0xc0}; // Masks for getting PP Up count, also PP Max values
// >