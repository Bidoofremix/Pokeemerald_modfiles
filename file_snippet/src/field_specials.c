< //
bool32 ShouldDoWallyCall(void)
{
    if (FlagGet(FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL))
    {
        switch (gMapHeader.mapType)
        {
            case MAP_TYPE_TOWN:
            case MAP_TYPE_CITY:
            case MAP_TYPE_ROUTE:
            case MAP_TYPE_OCEAN_ROUTE:
                if (++(*GetVarPointer(VAR_WALLY_CALL_STEP_COUNTER)) < 250)
                {
                    return FALSE;
                }
                break;
            default:
                return FALSE;
        }
    }
    else
    {
        return FALSE;
    }

    return TRUE;
}

bool32 ShouldDoProfStoneCall(void)
{
    if (FlagGet(FLAG_ENABLE_PROF_STONE_POKENAV_CALL) && !FlagGet(FLAG_RECEIVED_EXP_SHARE))
    {
        switch (gMapHeader.mapType)
        {
            case MAP_TYPE_TOWN:
            case MAP_TYPE_CITY:
            case MAP_TYPE_ROUTE:
            case MAP_TYPE_OCEAN_ROUTE:
                if (++(*GetVarPointer(VAR_PROF_STONE_CALL_STEP_COUNTER)) < 250)
                {
                    return FALSE;
                }
                break;
            default:
                return FALSE;
        }
    }
    else
    {
        return FALSE;
    }

    return TRUE;
}

bool32 ShouldDoScottFortreeCall(void)
// >

< //
void BufferVarsForIVRater(void)
{
    u8 i;
    u32 ivStorage[NUM_STATS];

    ivStorage[STAT_HP] = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_HP_IV);
    ivStorage[STAT_ATK] = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_ATK_IV);
    ivStorage[STAT_DEF] = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_DEF_IV);
    ivStorage[STAT_SPEED] = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPEED_IV);
    ivStorage[STAT_SPATK] = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPATK_IV);
    ivStorage[STAT_SPDEF] = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPDEF_IV);

    gSpecialVar_0x8005 = 0;

    for (i = 0; i < NUM_STATS; i++)
    {
        gSpecialVar_0x8005 += ivStorage[i];
    }

    gSpecialVar_0x8006 = 0;
    gSpecialVar_0x8007 = ivStorage[STAT_HP];

    for (i = 1; i < NUM_STATS; i++)
    {
        if (ivStorage[gSpecialVar_0x8006] < ivStorage[i])
        {
            gSpecialVar_0x8006 = i;
            gSpecialVar_0x8007 = ivStorage[i];
        }
        else if (ivStorage[gSpecialVar_0x8006] == ivStorage[i])
        {
            u16 randomNumber = Random();
            if (randomNumber & 1)
            {
                gSpecialVar_0x8006 = i;
                gSpecialVar_0x8007 = ivStorage[i];
            }
        }
    }
}

void BufferHPAtkDef(void)
{
    u8 i;
    u32 ivStorage[NUM_STATS];

    ivStorage[STAT_HP] = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_HP_IV);
    ivStorage[STAT_ATK] = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_ATK_IV);
    ivStorage[STAT_DEF] = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_DEF_IV);
    ivStorage[STAT_SPEED] = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPEED_IV);
    ivStorage[STAT_SPATK] = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPATK_IV);
    ivStorage[STAT_SPDEF] = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPDEF_IV);
	
	ConvertIntToDecimalStringN(gStringVar1, ivStorage[STAT_HP], STR_CONV_MODE_RIGHT_ALIGN, 2);
	ConvertIntToDecimalStringN(gStringVar2, ivStorage[STAT_ATK], STR_CONV_MODE_RIGHT_ALIGN, 2);
	ConvertIntToDecimalStringN(gStringVar3, ivStorage[STAT_DEF], STR_CONV_MODE_RIGHT_ALIGN, 2);
}

void BufferSpASpDSpe(void)
{
    u8 i;
    u32 ivStorage[NUM_STATS];

    ivStorage[STAT_HP] = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_HP_IV);
    ivStorage[STAT_ATK] = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_ATK_IV);
    ivStorage[STAT_DEF] = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_DEF_IV);
    ivStorage[STAT_SPEED] = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPEED_IV);
    ivStorage[STAT_SPATK] = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPATK_IV);
    ivStorage[STAT_SPDEF] = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPDEF_IV);
	
	ConvertIntToDecimalStringN(gStringVar1, ivStorage[STAT_SPATK], STR_CONV_MODE_RIGHT_ALIGN, 2);
	ConvertIntToDecimalStringN(gStringVar2, ivStorage[STAT_SPDEF], STR_CONV_MODE_RIGHT_ALIGN, 2);
	ConvertIntToDecimalStringN(gStringVar3, ivStorage[STAT_SPEED], STR_CONV_MODE_RIGHT_ALIGN, 2);
}

bool8 UsedPokemonCenterWarp(void)
// >

< //
u8 GetLeadMonFriendshipScore(void)
{
    struct Pokemon *pokemon = &gPlayerParty[GetLeadMonIndex()];
    if (GetMonData(pokemon, MON_DATA_FRIENDSHIP) == MAX_FRIENDSHIP)
    {
        return 6;
    }
    if (GetMonData(pokemon, MON_DATA_FRIENDSHIP) >= 200)
    {
        return 5;
    }
    if (GetMonData(pokemon, MON_DATA_FRIENDSHIP) >= 150)
    {
        return 4;
    }
    if (GetMonData(pokemon, MON_DATA_FRIENDSHIP) >= 100)
    {
        return 3;
    }
    if (GetMonData(pokemon, MON_DATA_FRIENDSHIP) >= 50)
    {
        return 2;
    }
    if (GetMonData(pokemon, MON_DATA_FRIENDSHIP) >= 1)
    {
        return 1;
    }
    return 0;
}

void GetLeadMonPotentialAbility(void)
{
	u32 species = GetMonData(&gPlayerParty[0], MON_DATA_SPECIES, NULL);
	u8 oldAbilityNum = GetMonData(&gPlayerParty[0], MON_DATA_ABILITY_NUM, NULL);
	u8 oldAbility = GetAbilityBySpecies(species, oldAbilityNum);
	u8 newAbility = GetAbilityBySpecies(species, gSpecialVar_0x8005);
	
	StringCopy(gStringVar2, gAbilityNames[newAbility]);
	StringCopy(gStringVar3, gAbilityNames[oldAbility]);
	
	// 0 = ability is ABILITY_NONE
	if (newAbility == 0)
	{
		gSpecialVar_Result = 0;
	}
	// 1 = current ability is the same as new potential ability
	else if (oldAbilityNum == gSpecialVar_0x8005)
	{
		gSpecialVar_Result = 1;
	}
	// 2 = new potential ability is new and not none
	else
	{
		gSpecialVar_Result = 2;
	}
}
	
void SetLeadMonAbility(void)
{
	SetMonData(&gPlayerParty[0], MON_DATA_ABILITY_NUM, &gSpecialVar_0x8005);
}

void CheckPartyType(void)
{ 
    u8 monType = gSpecialVar_0x800A;
    u8 i;
    u16 species;
	
	struct Pokemon *pokemon;
	
	for (i = 0; i < PARTY_SIZE; i++)
    {
        pokemon = &gPlayerParty[i];
        if (GetMonData(pokemon, MON_DATA_SANITY_HAS_SPECIES) && !GetMonData(pokemon, MON_DATA_IS_EGG))
        {
            species = GetMonData(pokemon, MON_DATA_SPECIES);
            //if (!gBaseStats[species].type1 == monType && !gBaseStats[species].type2 == monType)
            if (gBaseStats[species].type1 != monType && gBaseStats[species].type2 != monType)
            {
                gSpecialVar_Result = FALSE;
                return;
            }
        }
    }
	
    gSpecialVar_Result = TRUE;
	
}
	
static void CB2_FieldShowRegionMap(void)
// >