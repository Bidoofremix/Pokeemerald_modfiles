< //
static void InheritIVs(struct Pokemon *egg, struct DayCare *daycare)
{
    u8 i;
    u8 iv;
    u8 randomStat;
    u32 motherItem = GetBoxMonData(&daycare->mons[0].mon, MON_DATA_HELD_ITEM);
    u32 fatherItem = GetBoxMonData(&daycare->mons[1].mon, MON_DATA_HELD_ITEM);
        u8 ivCount = (motherItem == ITEM_POTION || fatherItem == ITEM_POTION) ? FATEFUL_KNOT_INHERITED_IV_COUNT
    : (motherItem == ITEM_DESTINY_KNOT || fatherItem == ITEM_DESTINY_KNOT) ? DESTINY_KNOT_INHERITED_IV_COUNT
    : INHERITED_IV_COUNT;
    u32 powerItems[6] = { ITEM_POWER_WEIGHT, ITEM_POWER_BRACER, ITEM_POWER_BELT, ITEM_POWER_LENS, ITEM_POWER_BAND, ITEM_POWER_ANKLET };
    u32 motherPowerItem = -1;
    u32 fatherPowerItem = -1;
    u8 selectedIvs[ivCount];
    u8 whichParents[ivCount];
    u8 availableIVs[NUM_STATS];
    
    // check for power items
    for (i = 0; i < 6; i++)
    {
        if (motherItem == powerItems[i])
        {
            motherPowerItem = i;
        }    

        if (fatherItem == powerItems[i])
        {
            fatherPowerItem = i;
        }
    }

    // Initialize a list of IV indices.
    for (i = 0; i < NUM_STATS; i++)
    {
        availableIVs[i] = i;
    }

    // check if both parents have power items
    if (motherPowerItem != -1 && fatherPowerItem != -1)
    {
        // inherit mother's IV
        selectedIvs[0] = availableIVs[motherPowerItem];
        RemoveIVIndexFromList(availableIVs, motherPowerItem);

        // if mother < father, father has to be decremented to inherit correct IV
        if (motherPowerItem < fatherPowerItem)
        {
            selectedIvs[1] = availableIVs[fatherPowerItem - 1];
            RemoveIVIndexFromList(availableIVs, fatherPowerItem - 1);
        }
        else
        {
            selectedIvs[1] = availableIVs[fatherPowerItem];
            RemoveIVIndexFromList(availableIVs, fatherPowerItem);
        }

        // make sure the IV gets inherited from the correct parents
        whichParents[motherPowerItem] = 0;
        whichParents[fatherPowerItem] = 1;

        // if both parents have power item, no need for a loop
        randomStat = Random() % (NUM_STATS - 2);
        selectedIvs[2] = availableIVs[randomStat];
        RemoveIVIndexFromList(availableIVs, randomStat);

        // Determine which parent each of the selected IVs should inherit from.
        for (i = 0; i < ivCount; i++)
        {
            if (i != motherPowerItem && i != fatherPowerItem)
            {
                whichParents[i] = Random() % DAYCARE_MON_COUNT;
            }
        }
    }

    // if just the mother has a power item
    else if (motherPowerItem != -1)
    {
        selectedIvs[0] = availableIVs[motherPowerItem];
        RemoveIVIndexFromList(availableIVs, motherPowerItem);

        // loop for other inherited IVs
        for (i = 1; i < ivCount; i++)
        {
            randomStat = Random() % (NUM_STATS - i);
            selectedIvs[i] = availableIVs[randomStat];
            RemoveIVIndexFromList(availableIVs, randomStat);
        }

        whichParents[motherPowerItem] = 0;

        for (i = 0; i < ivCount; i++)
        {
            if (i != motherPowerItem)
            {
                whichParents[i] = Random() % DAYCARE_MON_COUNT;
            }
        }
    }

    // if just the father has a power item
    else if (fatherPowerItem != -1)
    {
        selectedIvs[0] = availableIVs[fatherPowerItem];
        RemoveIVIndexFromList(availableIVs, fatherPowerItem);

        for (i = 1; i < ivCount; i++)
        {
            randomStat = Random() % (NUM_STATS - i);
            selectedIvs[i] = availableIVs[randomStat];
            RemoveIVIndexFromList(availableIVs, randomStat);
        }

        whichParents[fatherPowerItem] = 1;

        for (i = 0; i < ivCount; i++)
        {
            if (i != fatherPowerItem)
            {
                whichParents[i] = Random() % DAYCARE_MON_COUNT;
            }
        }
    }
    // otherwise, if no parents have a power item
    else {
        for (i = 0; i < ivCount; i++)
        {
            // Randomly pick an IV from the available list and stop from being chosen again.
            randomStat = Random() % (NUM_STATS - i);
            selectedIvs[i] = availableIVs[randomStat];
            RemoveIVIndexFromList(availableIVs, randomStat);
        }

        // Determine which parent each of the selected IVs should inherit from.
        for (i = 0; i < ivCount; i++)
        {
            whichParents[i] = Random() % DAYCARE_MON_COUNT;
        }
    }

    // Set each of inherited IVs on the egg mon.
    for (i = 0; i < ivCount; i++)
    {
        switch (selectedIvs[i])
        {
            case 0:
                iv = GetBoxMonData(&daycare->mons[whichParents[i]].mon, MON_DATA_HP_IV);
                SetMonData(egg, MON_DATA_HP_IV, &iv);
                break;
            case 1:
                iv = GetBoxMonData(&daycare->mons[whichParents[i]].mon, MON_DATA_ATK_IV);
                SetMonData(egg, MON_DATA_ATK_IV, &iv);
                break;
            case 2:
                iv = GetBoxMonData(&daycare->mons[whichParents[i]].mon, MON_DATA_DEF_IV);
                SetMonData(egg, MON_DATA_DEF_IV, &iv);
                break;
            case 3:
                iv = GetBoxMonData(&daycare->mons[whichParents[i]].mon, MON_DATA_SPEED_IV);
                SetMonData(egg, MON_DATA_SPEED_IV, &iv);
                break;
            case 4:
                iv = GetBoxMonData(&daycare->mons[whichParents[i]].mon, MON_DATA_SPATK_IV);
                SetMonData(egg, MON_DATA_SPATK_IV, &iv);
                break;
            case 5:
                iv = GetBoxMonData(&daycare->mons[whichParents[i]].mon, MON_DATA_SPDEF_IV);
                SetMonData(egg, MON_DATA_SPDEF_IV, &iv);
                break;
        }
    }
}

// Counts the number of egg moves a pokemon learns and stores the moves in
// the given array.
static u8 GetEggMoves(struct Pokemon *pokemon, u16 *eggMoves)
// >

< //
static s32 GetParentToInheritNature(struct DayCare *daycare)
{
    u16 motherItem = GetBoxMonData(&daycare->mons[0].mon, MON_DATA_HELD_ITEM);
    u16 fatherItem = GetBoxMonData(&daycare->mons[1].mon, MON_DATA_HELD_ITEM);
    if(motherItem == ITEM_EVERSTONE && fatherItem == ITEM_EVERSTONE)
    {
        if (Random() >= USHRT_MAX / 2)
            return 0;
        else
            return 1;
    }else
    {
        if(motherItem == ITEM_EVERSTONE)
        {
            return 0;
        }
        if(fatherItem == ITEM_EVERSTONE)
        {
            return 1;
        }
    }
    return -1;
}

static void _TriggerPendingDaycareEgg(struct DayCare *daycare)
// >

< //
static void BuildEggMoveset(struct Pokemon *egg, struct BoxPokemon *father, struct BoxPokemon *mother)
{
    u16 numSharedParentMoves;
    u32 numLevelUpMoves;
    u16 numEggMoves;
    u16 i, j;

	// empty 4-slot arrays for mother's and father's moves
	// and final list of egg moves
    numSharedParentMoves = 0;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        sHatchedEggMotherMoves[i] = MOVE_NONE;
        sHatchedEggFatherMoves[i] = MOVE_NONE;
        sHatchedEggFinalMoves[i] = MOVE_NONE;
    }
	// empty 10-slot array
    for (i = 0; i < EGG_MOVES_ARRAY_COUNT; i++)
        sHatchedEggEggMoves[i] = MOVE_NONE;
	// empty 50-slot array
    for (i = 0; i < EGG_LVL_UP_MOVES_ARRAY_COUNT; i++)
        sHatchedEggLevelUpMoves[i] = MOVE_NONE;

	// list of species level-up moves
    numLevelUpMoves = GetLevelUpMovesBySpecies(GetMonData(egg, MON_DATA_SPECIES), sHatchedEggLevelUpMoves);
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
		// get father's egg moves
        sHatchedEggFatherMoves[i] = GetBoxMonData(father, MON_DATA_MOVE1 + i);
		// get mother's egg moves
        sHatchedEggMotherMoves[i] = GetBoxMonData(mother, MON_DATA_MOVE1 + i);
    }

	// numEggMoves = how many egg moves this species learns
	// sHatchedEggEggMoves = which egg moves this species learns
    numEggMoves = GetEggMoves(egg, sHatchedEggEggMoves);

	// for four times
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
		// if father's 1/2/3/4 move is not empty
        if (sHatchedEggFatherMoves[i] != MOVE_NONE)
        {
			// as many times as this species has egg moves
            for (j = 0; j < numEggMoves; j++)
            {
				// if father's 1/2/3/4 move corresponds to jth egg move
                if (sHatchedEggFatherMoves[i] == sHatchedEggEggMoves[j])
                {
					// give the move to the egg
                    if (GiveMoveToMon(egg, sHatchedEggFatherMoves[i]) == MON_HAS_MAX_MOVES)
                        DeleteFirstMoveAndGiveMoveToMon(egg, sHatchedEggFatherMoves[i]);
                    break;
                }
            }
        }
		// if the moves is empty, break
        else
        {
            break;
        }
    }
	
	// mother's egg moves
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (sHatchedEggMotherMoves[i] != MOVE_NONE)
        {
            for (j = 0; j < numEggMoves; j++)
            {
                if (sHatchedEggMotherMoves[i] == sHatchedEggEggMoves[j])
                {
                    if (GiveMoveToMon(egg, sHatchedEggMotherMoves[i]) == MON_HAS_MAX_MOVES)
                        DeleteFirstMoveAndGiveMoveToMon(egg, sHatchedEggMotherMoves[i]);
                    break;
                }
            }
        }
        else
        {
            break;
        }
    }
	
	// same as above blocks for father's TM moves
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (sHatchedEggFatherMoves[i] != MOVE_NONE)
        {
			// remove HM inheritance
            //for (j = 0; j < NUM_TECHNICAL_MACHINES + NUM_HIDDEN_MACHINES; j++)
            for (j = 0; j < NUM_TECHNICAL_MACHINES; j++)
            {
                if (sHatchedEggFatherMoves[i] == ItemIdToBattleMoveId(ITEM_TM01_FOCUS_PUNCH + j) && CanMonLearnTMHM(egg, j))
                {
                    if (GiveMoveToMon(egg, sHatchedEggFatherMoves[i]) == MON_HAS_MAX_MOVES)
                        DeleteFirstMoveAndGiveMoveToMon(egg, sHatchedEggFatherMoves[i]);
                }
            }
        }
    }
	
	// mother's TM moves
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (sHatchedEggMotherMoves[i] != MOVE_NONE)
        {
			// remove HM inheritance
            //for (j = 0; j < NUM_TECHNICAL_MACHINES + NUM_HIDDEN_MACHINES; j++)
            for (j = 0; j < NUM_TECHNICAL_MACHINES; j++)
            {
                if (sHatchedEggMotherMoves[i] == ItemIdToBattleMoveId(ITEM_TM01_FOCUS_PUNCH + j) && CanMonLearnTMHM(egg, j))
                {
                    if (GiveMoveToMon(egg, sHatchedEggMotherMoves[i]) == MON_HAS_MAX_MOVES)
                        DeleteFirstMoveAndGiveMoveToMon(egg, sHatchedEggMotherMoves[i]);
                }
            }
        }
    }
	
	// common level-up moves of mother and father
	// store them in array sHatchedEggFinalMoves
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (sHatchedEggFatherMoves[i] == MOVE_NONE)
            break;
        for (j = 0; j < MAX_MON_MOVES; j++)
        {
            if (sHatchedEggFatherMoves[i] == sHatchedEggMotherMoves[j] && sHatchedEggFatherMoves[i] != MOVE_NONE)
                sHatchedEggFinalMoves[numSharedParentMoves++] = sHatchedEggFatherMoves[i];
        }
    }

	// fill empty moveslots with parents' common level-up moves
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (sHatchedEggFinalMoves[i] == MOVE_NONE)
            break;
        for (j = 0; j < numLevelUpMoves; j++)
        {
            if (sHatchedEggLevelUpMoves[j] != MOVE_NONE && sHatchedEggFinalMoves[i] == sHatchedEggLevelUpMoves[j])
            {
                if (GiveMoveToMon(egg, sHatchedEggFinalMoves[i]) == MON_HAS_MAX_MOVES)
                    DeleteFirstMoveAndGiveMoveToMon(egg, sHatchedEggFinalMoves[i]);
                break;
            }
        }
    }
}

static void RemoveEggFromDayCare(struct DayCare *daycare)
// >