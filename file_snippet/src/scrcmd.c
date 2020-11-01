< //
#include "window.h"
#include "quests.h"
#include "constants/event_objects.h"
// >

< //
bool8 ScrCmd_bufferitemnameplural(struct ScriptContext *ctx)
{
    u8 stringVarIndex = ScriptReadByte(ctx);
    u16 itemId = VarGet(ScriptReadHalfword(ctx));
    u16 quantity = VarGet(ScriptReadHalfword(ctx));

    CopyItemNameHandlePlural(itemId, sScriptStringVars[stringVarIndex], quantity);
    return FALSE;
}

bool8 ScrCmd_setmonball(struct ScriptContext *ctx)
{
    u16 partyIndex = VarGet(ScriptReadHalfword(ctx));
    u16 ball = VarGet(ScriptReadHalfword(ctx));

    SetMonData(&gPlayerParty[partyIndex], MON_DATA_POKEBALL, &ball);
    return FALSE;
}

bool8 ScrCmd_setmonmetbreedersclub(struct ScriptContext *ctx)
{
    u16 partyIndex = VarGet(ScriptReadHalfword(ctx));
	u8 metLocation;

    metLocation = 0xFC;
    SetMonData(&gPlayerParty[partyIndex], MON_DATA_MET_LOCATION, &metLocation);	
    return FALSE;
}

bool8 ScrCmd_questmenu(struct ScriptContext *ctx)
{
    u8 caseId = ScriptReadByte(ctx);
    u8 questId = VarGet(ScriptReadByte(ctx));

    switch (caseId)
    {
    case QUEST_MENU_OPEN:
    default:
        SetQuestMenuActive();
        BeginNormalPaletteFade(0xFFFFFFFF, 2, 16, 0, 0);
        QuestMenu_Init(0, CB2_ReturnToFieldContinueScriptPlayMapMusic);
        ScriptContext1_Stop();
        break;
    case QUEST_MENU_UNLOCK_QUEST:
        GetSetQuestFlag(questId, FLAG_SET_UNLOCKED);
        break;
    case QUEST_MENU_COMPLETE_QUEST:
        GetSetQuestFlag(questId, FLAG_SET_COMPLETED);
		gSpecialVar_0x800A = GetQuestDifficulty(u8 questId);
		CopyQuestName(gStringVar1, questId)
        break;
    case QUEST_MENU_SET_ACTIVE:
        SetActiveQuest(questId);
        break;
    case QUEST_MENU_RESET_ACTIVE:
        ResetActiveQuest();
        break;
    case QUEST_MENU_BUFFER_QUEST_NAME:
            CopyQuestName(gStringVar1, questId);
        break;
    case QUEST_MENU_GET_ACTIVE_QUEST:
        gSpecialVar_Result = GetActiveQuestIndex();
        break;
    case QUEST_MENU_CHECK_UNLOCKED:
        if (GetSetQuestFlag(questId, FLAG_GET_UNLOCKED))
            gSpecialVar_Result = TRUE;
        else
            gSpecialVar_Result = FALSE;
        break;
    case QUEST_MENU_CHECK_COMPLETE:
        if (GetSetQuestFlag(questId, FLAG_GET_COMPLETED))
            gSpecialVar_Result = TRUE;
        else
            gSpecialVar_Result = FALSE;
        break;
    }

    return TRUE;
}

bool8 ScrCmd_bufferdecorationname(struct ScriptContext *ctx)
// >