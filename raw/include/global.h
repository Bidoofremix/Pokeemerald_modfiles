< //
struct RankingHall2P
{
    u8 id1[TRAINER_ID_LENGTH];
    u8 id2[TRAINER_ID_LENGTH];
    u16 winStreak;
    u8 name1[PLAYER_NAME_LENGTH + 1];
    u8 name2[PLAYER_NAME_LENGTH + 1];
    u8 language;
};

// quest menu
#include "constants/quests.h"
#define SIDE_QUEST_FLAGS_COUNT     ((SIDE_QUEST_COUNT / 8) + ((SIDE_QUEST_COUNT % 8) ? 1 : 0))

struct SaveBlock2
// >

< //
    /*0x64C*/ struct BattleFrontier frontier;
    /*0x0F2C*/ u8 unlockedQuests[SIDE_QUEST_FLAGS_COUNT];
    /*0x????*/ u8 completedQuests[SIDE_QUEST_FLAGS_COUNT];
    /*0x????*/ u8 activeQuest;
};
extern struct SaveBlock2 *gSaveBlock2Ptr;
// >

< //
    /*0x3???*/ struct WaldaPhrase waldaPhrase;
    /* size = 0x3D88 */
};

extern struct SaveBlock1* gSaveBlock1Ptr;
// >