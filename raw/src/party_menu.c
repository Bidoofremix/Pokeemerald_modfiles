< //
#include "data.h"
#include "daycare.h"
#include "decompress.h"
// >

< //
static u8 CanMonLearnTMTutor(struct Pokemon *, u16, u8);
static u8 CanMonLearnPostDocTutor(struct Pokemon *, u16);
static void DisplayPartyPokemonBarDetail(u8, const u8*, u8, const u8*);
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
static void DisplayPartyPokemonDataToTeachMove(u8 slot, u16 item, u8 tutor)
{
    switch (CanMonLearnTMTutor(&gPlayerParty[slot], item, tutor))
    {
    case CANNOT_LEARN_MOVE:
    case CANNOT_LEARN_MOVE_IS_EGG:
        DisplayPartyPokemonDescriptionData(slot, PARTYBOX_DESC_NOT_ABLE_2);
        break;
    case ALREADY_KNOWS_MOVE:
        DisplayPartyPokemonDescriptionData(slot, PARTYBOX_DESC_LEARNED);
        break;
    default:
        DisplayPartyPokemonDescriptionData(slot, PARTYBOX_DESC_ABLE_2);
        break;
    }
}

static u8 CanMonLearnPostDocTutor(struct Pokemon *mon, u16 move)
{
    if (GetMonData(mon, MON_DATA_IS_EGG))
        return CANNOT_LEARN_MOVE_IS_EGG;

    if (MonKnowsMove(mon, move) == TRUE)
        return ALREADY_KNOWS_MOVE;
    else
        return CAN_LEARN_MOVE;
}

static void DisplayPartyPokemonDataForMultiBattle(u8 slot)
// >

< //
void BufferMoveDeleterNicknameAndMove(void)
{
    struct Pokemon *mon = &gPlayerParty[gSpecialVar_0x8004];
    u16 move = GetMonData(mon, MON_DATA_MOVE1 + gSpecialVar_0x8005);

    GetMonNickname(mon, gStringVar1);
    StringCopy(gStringVar2, gMoveNames[move]);
}

void SetMoveForPostDocTutor(void)
{
	struct Pokemon *mon = &gPlayerParty[gSpecialVar_0x8004];
    u16 move = GetMonData(mon, MON_DATA_MOVE1 + gSpecialVar_0x8005);

    GetMonNickname(mon, gStringVar1);
    StringCopy(gStringVar2, gMoveNames[move]);
	gSpecialVar_0x8005 = move;
}
	
void MoveDeleterForgetMove(void)
// >

< //
static void TryTutorSelectedMon(u8 taskId)
{
    struct Pokemon *mon;
    s16 *move;

    if (!gPaletteFade.active)
    {
        mon = &gPlayerParty[gPartyMenu.slotId];
        move = &gPartyMenu.data1;
        GetMonNickname(mon, gStringVar1);
		// postdoc move tutor
		if (gSpecialVar_0x800B == 1)
		{
			gPartyMenu.data1 = gSpecialVar_0x8005;
			StringCopy(gStringVar2, gMoveNames[gPartyMenu.data1]);
			move[1] = 2;
			switch (CanMonLearnPostDocTutor(mon, gSpecialVar_0x8005))
			{
			case CANNOT_LEARN_MOVE:
				DisplayLearnMoveMessageAndClose(taskId, gText_PkmnCantLearnMove);
				return;
			case ALREADY_KNOWS_MOVE:
				DisplayLearnMoveMessageAndClose(taskId, gText_PkmnAlreadyKnows);
				return;
			default:
				if (GiveMoveToMon(mon, gPartyMenu.data1) != MON_HAS_MAX_MOVES)
				{
					Task_LearnedMove(taskId);
					return;
				}
				break;
			}
		}
		// vanilla
		else
		{
			gPartyMenu.data1 = GetTutorMove(gSpecialVar_0x8005);
			StringCopy(gStringVar2, gMoveNames[gPartyMenu.data1]);
			move[1] = 2;
			switch (CanMonLearnTMTutor(mon, 0, gSpecialVar_0x8005))
			{
			case CANNOT_LEARN_MOVE:
				DisplayLearnMoveMessageAndClose(taskId, gText_PkmnCantLearnMove);
				return;
			case ALREADY_KNOWS_MOVE:
				DisplayLearnMoveMessageAndClose(taskId, gText_PkmnAlreadyKnows);
				return;
			default:
				if (GiveMoveToMon(mon, gPartyMenu.data1) != MON_HAS_MAX_MOVES)
				{
					Task_LearnedMove(taskId);
					return;
				}
				break;
			}
		}
        DisplayLearnMoveMessage(gText_PkmnNeedsToReplaceMove);
        gTasks[taskId].func = Task_ReplaceMoveYesNo;
    }
}

void CB2_PartyMenuFromStartMenu(void)
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