< //
static void PrintEggMemo(void)
{
    const u8 *text;
    struct PokeSummary *sum = &sMonSummaryScreen->summary;

    if (sMonSummaryScreen->summary.sanity != 1)
    {
        if (sum->metLocation == METLOC_FATEFUL_ENCOUNTER)
            text = gText_PeculiarEggNicePlace;
		else if (sum->metLocation == METLOC_BREEDERSCLUB_EGG)
			text = gText_EggFromBreedersClub;
        else if (DidMonComeFromGBAGames() == FALSE || DoesMonOTMatchOwner() == FALSE)
            text = gText_PeculiarEggTrade;
        else if (sum->metLocation == METLOC_SPECIAL_EGG)
            text = (DidMonComeFromRSE() == TRUE) ? gText_EggFromHotSprings : gText_EggFromTraveler;
        else
            text = gText_OddEggFoundByCouple;
    }
    else
    {
        text = gText_OddEggFoundByCouple;
    }

    PrintTextOnWindow(AddWindowFromTemplateList(sPageInfoTemplate, PSS_DATA_WINDOW_INFO_MEMO), text, 0, 1, 0, 0);
}

static void PrintSkillsPageText(void)
// >

< //
static void KeepMoveSelectorVisible(u8 firstSpriteId);
static void BufferIvOrEvStats(u8 mode);

// const rom data
#include "data/text/move_descriptions.h"
// >

< //
static const u8 sStatsLeftColumnLayout[] = _("{DYNAMIC 0}/{DYNAMIC 1}\n{DYNAMIC 2}\n{DYNAMIC 3}");
static const u8 sStatsLeftColumnLayoutIVEV[] = _("{DYNAMIC 0}\n{DYNAMIC 1}\n{DYNAMIC 2}");
static const u8 sStatsRightColumnLayout[] = _("{DYNAMIC 0}\n{DYNAMIC 1}\n{DYNAMIC 2}");
// >

< //
static void Task_HandleInput(u8 taskId)
{
    if (MenuHelpers_CallLinkSomething() != TRUE && !gPaletteFade.active)
    {
        if (gMain.newKeys & DPAD_UP)
        {
            ChangeSummaryPokemon(taskId, -1);
        }
        else if (gMain.newKeys & DPAD_DOWN)
        {
            ChangeSummaryPokemon(taskId, 1);
        }
        else if ((gMain.newKeys & DPAD_LEFT) || GetLRKeysPressed() == MENU_L_PRESSED)
        {
            ChangePage(taskId, -1);
        }
        else if ((gMain.newKeys & DPAD_RIGHT) || GetLRKeysPressed() == MENU_R_PRESSED)
        {
            ChangePage(taskId, 1);
        }
        else if (gMain.newKeys & A_BUTTON)
        {
            if (sMonSummaryScreen->currPageIndex != PSS_PAGE_SKILLS)
            {
                if (sMonSummaryScreen->currPageIndex == PSS_PAGE_INFO)
                {
                    StopPokemonAnimations();
                    PlaySE(SE_SELECT);
                    BeginCloseSummaryScreen(taskId);
                }
                else // Contest or Battle Moves
                {
                    PlaySE(SE_SELECT);
                    SwitchToMoveSelection(taskId);
                }
            }
        }
        else if (gMain.newKeys & B_BUTTON)
        {
            StopPokemonAnimations();
            PlaySE(SE_SELECT);
            BeginCloseSummaryScreen(taskId);
        }
		
		// show IVs/EVs/stats on button presses
		else if (gMain.newKeys & R_BUTTON)
		{
			if (sMonSummaryScreen->currPageIndex == PSS_PAGE_SKILLS)
			{
				BufferIvOrEvStats(0);
			}
		}
		else if (gMain.newKeys & L_BUTTON)
		{
			if (sMonSummaryScreen->currPageIndex == PSS_PAGE_SKILLS)
			{
				BufferIvOrEvStats(1);
			}
		}
		else if (gMain.newKeys & START_BUTTON)
		{
			if (sMonSummaryScreen->currPageIndex == PSS_PAGE_SKILLS)
			{
				BufferIvOrEvStats(2);
			}
		}
	}
}

static void ChangeSummaryPokemon(u8 taskId, s8 delta)
// >

< //
static void SetMainMoveSelectorColor(u8 which)
{
    u8 i;
    u8 *spriteIds = &sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MOVE_SELECTOR1];

    which *= 3;
    for (i = 0; i < MOVE_SELECTOR_SPRITES_COUNT; i++)
    {
        if (i == 0)
            StartSpriteAnim(&gSprites[spriteIds[i]], which + 4);
        else if (i == 9)
            StartSpriteAnim(&gSprites[spriteIds[i]], which + 5);
        else
            StartSpriteAnim(&gSprites[spriteIds[i]], which + 6);
    }
}

static void BufferIvOrEvStats(u8 mode)
{
    u16 hp, hp2, atk, def, spA, spD, spe;
    u8 *currHPString = Alloc(20);
    const s8 *natureMod = gNatureStatTable[sMonSummaryScreen->summary.nature];

    switch (mode)
    {
    case 0: // IV mode
        hp = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_HP_IV);
        atk = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_ATK_IV);
        def = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_DEF_IV);

        spA = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPATK_IV);
        spD = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPDEF_IV);
        spe = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPEED_IV);
        break;
    case 1: // EV mode
        hp = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_HP_EV);
        atk = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_ATK_EV);
        def = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_DEF_EV);

        spA = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPATK_EV);
        spD = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPDEF_EV);
        spe = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPEED_EV);
        break;
    case 2: // stats mode
    default:
        hp = sMonSummaryScreen->summary.currentHP;
        hp2 = sMonSummaryScreen->summary.maxHP;
        atk = sMonSummaryScreen->summary.atk;
        def = sMonSummaryScreen->summary.def;

        spA = sMonSummaryScreen->summary.spatk;
        spD = sMonSummaryScreen->summary.spdef;
        spe = sMonSummaryScreen->summary.speed;
        break;
    }

    FillWindowPixelBuffer(sMonSummaryScreen->windowIds[PSS_DATA_WINDOW_SKILLS_STATS_LEFT], 0);
    FillWindowPixelBuffer(sMonSummaryScreen->windowIds[PSS_DATA_WINDOW_SKILLS_STATS_RIGHT], 0);

    switch (mode)
    {
    case 0:
    case 1:
        ConvertIntToDecimalStringN(gStringVar1, hp, STR_CONV_MODE_RIGHT_ALIGN, 7);
        ConvertIntToDecimalStringN(gStringVar2, atk, STR_CONV_MODE_RIGHT_ALIGN, 7);
        ConvertIntToDecimalStringN(gStringVar3, def, STR_CONV_MODE_RIGHT_ALIGN, 7);
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, gStringVar1);
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(1, gStringVar2);
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(2, gStringVar3);
        DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar4, sStatsLeftColumnLayoutIVEV);
        PrintLeftColumnStats();

        ConvertIntToDecimalStringN(gStringVar1, spA, STR_CONV_MODE_RIGHT_ALIGN, 3);
        ConvertIntToDecimalStringN(gStringVar2, spD, STR_CONV_MODE_RIGHT_ALIGN, 3);
        ConvertIntToDecimalStringN(gStringVar3, spe, STR_CONV_MODE_RIGHT_ALIGN, 3);
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, gStringVar1);
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(1, gStringVar2);
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(2, gStringVar3);
        DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar4, sStatsRightColumnLayout);
        PrintRightColumnStats();
        break;
    case 2:
    default:
        ConvertIntToDecimalStringN(currHPString, hp, STR_CONV_MODE_RIGHT_ALIGN, 3);
        ConvertIntToDecimalStringN(gStringVar1, hp2, STR_CONV_MODE_RIGHT_ALIGN, 3);
        ConvertIntToDecimalStringN(gStringVar2, atk, STR_CONV_MODE_RIGHT_ALIGN, 7);
        ConvertIntToDecimalStringN(gStringVar3, def, STR_CONV_MODE_RIGHT_ALIGN, 7);
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, currHPString);
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(1, gStringVar1);
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(2, gStringVar2);
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(3, gStringVar3);
        DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar4, sStatsLeftColumnLayout);
        PrintLeftColumnStats();

        ConvertIntToDecimalStringN(gStringVar1, spA, STR_CONV_MODE_RIGHT_ALIGN, 3);
        ConvertIntToDecimalStringN(gStringVar2, spD, STR_CONV_MODE_RIGHT_ALIGN, 3);
        ConvertIntToDecimalStringN(gStringVar3, spe, STR_CONV_MODE_RIGHT_ALIGN, 3);
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, gStringVar1);
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(1, gStringVar2);
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(2, gStringVar3);
        DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar4, sStatsRightColumnLayout);
        PrintRightColumnStats();
        break;
    }

    Free(currHPString);
}

static void KeepMoveSelectorVisible(u8 firstSpriteId)
// >