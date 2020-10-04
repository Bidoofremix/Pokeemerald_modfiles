< //
    ResetContestLinkResults();
    memset(&gSaveBlock2Ptr->unlockedQuests, 0, sizeof(gSaveBlock2Ptr->unlockedQuests));
    memset(&gSaveBlock2Ptr->completedQuests, 0, sizeof(gSaveBlock2Ptr->completedQuests));
    gSaveBlock2Ptr->activeQuest = 0;
	}
	
static void ResetMiniGamesResults(void)
// >