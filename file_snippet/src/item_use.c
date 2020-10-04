< //
#include "constants/songs.h"
#include "quests.h"

static void ItemUseOnFieldCB_QuestLog(u8 taskId);
static void SetUpItemUseCallback(u8 taskId);
// >

< //
static void Task_UseRepel(u8 taskId)
{
    if (!IsSEPlaying())
    {
        VarSet(VAR_REPEL_STEP_COUNT, ItemId_GetHoldEffectParam(gSpecialVar_ItemId));
		VarSet(VAR_REPEL_LAST_USED, gSpecialVar_ItemId);
        RemoveUsedItem();
        if (!InBattlePyramid())
            DisplayItemMessage(taskId, 1, gStringVar4, BagMenu_InitListsMenu);
        else
            DisplayItemMessageInBattlePyramid(taskId, gStringVar4, Task_CloseBattlePyramidBagMessage);
    }
}

static void Task_UsedBlackWhiteFlute(u8 taskId)
// >

< //
void ItemUseOutOfBattle_Itemfinder(u8 var)
{
    IncrementGameStat(GAME_STAT_USED_ITEMFINDER);
    sItemUseOnFieldCB = ItemUseOnFieldCB_Itemfinder;
    SetUpItemUseOnFieldCallback(var);
}

void ItemUseOutOfBattle_QuestLog(u8 taskId)
{
	sItemUseOnFieldCB = ItemUseOnFieldCB_QuestLog;
    SetUpItemUseOnFieldCallback(taskId);
}

static void ItemUseOnFieldCB_QuestLog(u8 taskId)
{
	SetQuestMenuActive();
    BeginNormalPaletteFade(0xFFFFFFFF, 2, 16, 0, 0);
    QuestMenu_Init(0, CB2_ReturnToFieldContinueScriptPlayMapMusic);
    ScriptContext1_Stop();
	DestroyTask(taskId);
}

static void ItemUseOnFieldCB_Itemfinder(u8 taskId)
// >