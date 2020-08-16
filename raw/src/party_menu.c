< //
#include "data.h"
#include "daycare.h"
#include "decompress.h"
// >

< //
static void Task_LearnedMove(u8 taskId)
{
    struct Pokemon *mon = &gPlayerParty[gPartyMenu.slotId];
    s16 *move = &gPartyMenu.data1;
    u16 item = gSpecialVar_ItemId;

	// no more happiness from TM teaching
    //if (move[1] == 0)
    //{
    //    AdjustFriendship(mon, FRIENDSHIP_EVENT_LEARN_TMHM);
    //}
	
    GetMonNickname(mon, gStringVar1);
    StringCopy(gStringVar2, gMoveNames[move[0]]);
    StringExpandPlaceholders(gStringVar4, gText_PkmnLearnedMove3);
    DisplayPartyMenuMessage(gStringVar4, TRUE);
    ScheduleBgCopyTilemapToVram(2);
    gTasks[taskId].func = Task_DoLearnedMoveFanfareAfterText;
}

static void Task_DoLearnedMoveFanfareAfterText(u8 taskId)
// >

< //
static bool8 CanLearnTutorMove(u16 species, u8 tutor)
{
	
	// custom modification for postdoc tutor moves
	// in postdoc dialog, VAR_0x800B is set to 1
	// it should be 0 everywhere else in vanilla
	if (gSpecialVar_0x800B == 1)
	{
		// check level-up and egg moves here
		return TRUE;
	}
	else
	{
		if (sTutorLearnsets[species] & (1 << tutor))
			return TRUE;
		else
			return FALSE;
	}
	
	// if (sTutorLearnsets[species] & (1 << tutor))
        // return TRUE;
    // else
        // return FALSE;
}

static void InitPartyMenuWindows(u8 layout)
// >

< //
static void Task_TryLearnNewMoves(u8 taskId)
{
    u16 learnMove;

    if (WaitFanfare(0) && ((gMain.newKeys & A_BUTTON) || (gMain.newKeys & B_BUTTON)))
    {
        RemoveLevelUpStatsWindow();
        learnMove = MonTryLearningNewMove(&gPlayerParty[gPartyMenu.slotId], TRUE, 0);
        gPartyMenu.learnMoveState = 1;
        switch (learnMove)
        {
        case 0: // No moves to learn
            PartyMenuTryEvolution(taskId);
            break;
        case MON_HAS_MAX_MOVES:
            DisplayMonNeedsToReplaceMove(taskId);
            break;
        case MON_ALREADY_KNOWS_MOVE:
            gTasks[taskId].func = Task_TryLearningNextMove;
            break;
        default:
            DisplayMonLearnedMove(taskId, learnMove);
            break;
        }
    }
}

static void Task_TryLearningNextMove(u8 taskId)
{
    u16 result = MonTryLearningNewMove(&gPlayerParty[gPartyMenu.slotId], FALSE, 0);

    switch (result)
// >