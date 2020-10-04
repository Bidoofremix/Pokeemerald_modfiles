< //
static void Task_NewGameBirchSpeechSub_InitPokeBall(u8 taskId)
{
	
    u8 spriteId = gTasks[sBirchSpeechMainTaskId].tLotadSpriteId;

    gSprites[spriteId].pos1.x = 100;
    gSprites[spriteId].pos1.y = 75;
    gSprites[spriteId].invisible = FALSE;
    gSprites[spriteId].data[0] = 0;

	// change intro species to chicks
    CreatePokeballSpriteToReleaseMon(spriteId, gSprites[spriteId].oam.paletteNum, 112, 58, 0, 0, 32, 0x0000FFFF, SPECIES_CHICKS);
    gTasks[taskId].func = Task_NewGameBirchSpeechSub_WaitForLotad;
    gTasks[sBirchSpeechMainTaskId].tTimer = 0;
}

static void Task_NewGameBirchSpeechSub_WaitForLotad(u8 taskId)
// >

< //
static u8 NewGameBirchSpeech_CreateLotadSprite(u8 a, u8 b)
{
	// change intro species to chicks
    return CreatePicSprite2(SPECIES_CHICKS, SHINY_ODDS, 0, 1, a, b, 14, -1);
}

static void AddBirchSpeechObjects(u8 taskId)
// >