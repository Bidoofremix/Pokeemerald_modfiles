< //
bool8 sub_8017630(struct UnkStruct_Shared* arg0, const struct UnkStruct_Shared* arg1);
void sub_8013278(u8 windowId, s32 itemId, u8 y, u8 itemPos);
void sub_8013DF4(u8 windowId, s32 itemId, u8 y, u8 itemPos);
void sub_8017BE8(u8 windowId, s32 itemId, u8 y, u8 itemPos);
void nullsub_14(u8 windowId, s32 itemId, u8 y, u8 itemPos);

#include "data/union_room.h"
// >

< //
bool8 sub_801320C(struct UnkStruct_Leader *data, u32 arg1, u32 arg2)
{
    switch (sub_80132D4(data->field_0))
    {
    case 1:
        PlaySE(SE_PC_LOGIN);
        RedrawListMenu(data->listTaskId);
        sub_8018404(gStringVar2, &data->field_0->arr[data->field_13]);
        sub_8012FC4(gStringVar4, gUnknown_02022C2C);
        data->state = arg1;
        break;
    case 2:
        sub_8011A64(0, 0);
        RedrawListMenu(data->listTaskId);
        data->state = arg2;
        return TRUE;
    }

    return FALSE;
}

void sub_8013278(u8 arg0, s32 id, u8 arg2, u8 itemPos)
{
    struct UnkStruct_Leader *data = gUnknown_02022C30.leader;
    u8 var = 0;

    switch (data->field_0->arr[id].field_1A_0)
    {
    case 1:
        if (data->field_0->arr[id].field_1B != 0)
            var = 2;
        break;
    case 2:
        var = 1;
        break;
    }

    sub_80178A0(arg0, 0, arg2, &data->field_0->arr[id], var, id);
}

u8 sub_80132D4(struct UnkStruct_Main0 *arg0)
// >

< //
u8 sub_8013DBC(struct UnkStruct_Group *data, u32 id)
{
    if (data->field_0->arr[id].field_1A_0 == 1)
    {
        if (data->field_0->arr[id].unk.field_0.started)
            return 3;
        else if (data->field_0->arr[id].field_1A_1 != 0)
            return 1;
        else if (data->field_0->arr[id].field_1B != 0)
            return 2;
    }

    return 0;
}

void sub_8013DF4(u8 arg0, s32 id, u8 arg2), u8 itemPos
{
    struct UnkStruct_Group *data = gUnknown_02022C30.group;
    u8 var = sub_8013DBC(data, id);

    sub_80177B8(arg0, 8, arg2, &data->field_0->arr[id], var, id);
}

u8 sub_8013E44(void)
// >

< //
s32 sub_80179D4(struct UnkStruct_Main0 *arg0, u8 arg1, u8 arg2, u32 playerGender)
{
    bool32 r2;

    struct UnkStruct_x20 * r5 = &arg0->arr[arg2];

    if (!r5->unk.field_0.started && arg1 == 0)
    {
        sub_8018404(gStringVar1, r5);
        r2 = sub_800E540(ReadAsU16(r5->unk.field_0.unk_00.playerTrainerId), gStringVar1);
        if (r5->unk.field_0.activity == 0x45)
        {
            StringExpandPlaceholders(gStringVar4, sJoinChatTexts[r2][playerGender]);
            return 2;
        }
        else
        {
            sub_8017020(sCommunicatingWaitTexts[r2]);
            return 1;
        }
    }
    else
    {
        sub_8018404(gStringVar1, r5);
        if (arg1 != 0)
        {
            playerGender = (r5->unk.field_0.unk_00.playerTrainerId[arg1 + 1] >> 3) & 1;
        }
        switch (r5->unk.field_0.activity & 0x3F)
        {
        case 1:
            StringExpandPlaceholders(gStringVar4, sBattleReactionTexts[playerGender][Random() % 4]);
            break;
        case 4:
            StringExpandPlaceholders(gStringVar4, sTradeReactionTexts[playerGender][Random() % 2]);
            break;
        case 5:
            StringExpandPlaceholders(gStringVar4, sChatReactionTexts[playerGender][Random() % 4]);
            break;
        case 8:
            StringExpandPlaceholders(gStringVar4, sTrainerCardReactionTexts[playerGender][Random() % 2]);
            break;
        default:
            StringExpandPlaceholders(gStringVar4, sText_TrainerAppearsBusy);
            break;
        }
        return 0;
    }
}

void nullsub_14(u8 windowId, s32 itemId, u8 y, u8 itemPos)
{

}

void sub_8017B3C(u8 arg0, u8 arg1, struct GFtgtGname * arg2, const u8 * str, u8 arg4)
{
    u8 sp8[4];
    u16 r8 = arg2->species;
    u8 r7 = arg2->type;
    u8 r9 = arg2->level;

    sub_80173E0(arg0, 1, str, 8, arg1, arg4);
    if (r8 == SPECIES_EGG)
    {
        sub_80173E0(arg0, 1, sText_EggTrade, 0x44, arg1, arg4);
    }
    else
    {
        blit_move_info_icon(arg0, r7 + 1, 0x44, arg1);
        sub_80173E0(arg0, 1, gSpeciesNames[r8], 0x76, arg1, arg4);
        ConvertIntToDecimalStringN(sp8, r9, STR_CONV_MODE_RIGHT_ALIGN, 3);
        sub_80173E0(arg0, 1, sp8, 0xC6, arg1, arg4);
    }
}

void sub_8017BE8(u8 windowId, s32 itemId, u8 y, u8 itemPos)
{
    struct UnkStruct_Leader *leader = gUnknown_02022C30.leader;
    struct GFtgtGname *rfu;
    s32 i, j;
    u8 sp4[11];

    if (itemId == -3 && y == gUnknown_082F03A4.upText_Y)
    {
        rfu = sub_800F7DC();
        if (rfu->species != SPECIES_NONE)
        {
            sub_8017B3C(windowId, y, rfu, gSaveBlock2Ptr->playerName, 5);
        }
    }
    else
    {
        j = 0;
        for (i = 0; i < 8; i++)
        {
            if (leader->field_0->arr[i].field_1A_0 == 1 && leader->field_0->arr[i].unk.field_0.species != SPECIES_NONE)
            {
                j++;
            }
            if (j == itemId + 1)
            {
                sub_8018404(sp4, &leader->field_0->arr[i]);
                sub_8017B3C(windowId, y, &leader->field_0->arr[i].unk.field_0, sp4, 6);
                break;
            }
        }
    }
}

s32 sub_8017CB0(struct UnkStruct_x20 * arg, s32 arg1)
// >