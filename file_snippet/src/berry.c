< //
static bool32 BerryTreeGrow(struct BerryTree *tree)
{
	
    if (tree->growthSparkle)
        return FALSE;
    switch (tree->stage)
    {
    case BERRY_STAGE_NO_BERRY:
        return FALSE;
    case BERRY_STAGE_FLOWERING:
        tree->berryYield = CalcBerryYield(tree);
    case BERRY_STAGE_PLANTED:
    case BERRY_STAGE_SPROUTED:
    case BERRY_STAGE_TALLER:
        tree->stage++;
        break;
		
	// berry trees won't disappear	
    /*case BERRY_STAGE_BERRIES:
        tree->watered1 = 0;
        tree->watered2 = 0;
        tree->watered3 = 0;
        tree->watered4 = 0;
        tree->berryYield = 0;
        tree->stage = BERRY_STAGE_SPROUTED;
        if (++tree->regrowthCount == 10)
            *tree = gBlankBerryTree;
        break;*/
    }
    return TRUE;
}

void BerryTreeTimeUpdate(s32 minutes)
{
    int i;
    struct BerryTree *tree;

    for (i = 0; i < BERRY_TREES_COUNT; i++)
    {
        tree = &gSaveBlock1Ptr->berryTrees[i];

        if (tree->berry && tree->stage && !tree->growthSparkle && (tree->stage != BERRY_STAGE_BERRIES))
        {
			
			// berry trees won't disappear
            /*if (minutes >= GetStageDurationByBerryType(tree->berry) * 71)
            {
                *tree = gBlankBerryTree;
            }
            else
            {*/
			s32 time = minutes;

			while (time != 0)
			{
				if (tree->minutesUntilNextStage > time)
				{
					tree->minutesUntilNextStage -= time;
					break;
				}
				time -= tree->minutesUntilNextStage;
				tree->minutesUntilNextStage = GetStageDurationByBerryType(tree->berry);
				if (!BerryTreeGrow(tree))
					break;
				if (tree->stage == BERRY_STAGE_BERRIES)
					tree->minutesUntilNextStage *= 4;
			}
            /* } */
        }
    }
}

void PlantBerryTree(u8 id, u8 berry, u8 stage, bool8 sparkle)
// >