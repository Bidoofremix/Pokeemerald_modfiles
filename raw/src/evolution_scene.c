< //
static void Task_EvolutionScene(u8 taskID)
{
    u32 var;
    struct Pokemon* mon = &gPlayerParty[gTasks[taskID].tPartyID];

    // check if B Button was held, so the evolution gets stopped
    if (gMain.heldKeys == B_BUTTON
        && gTasks[taskID].tState == 8
        && gTasks[sEvoGraphicsTaskID].isActive
        && gTasks[taskID].tBits & TASK_BIT_CAN_STOP)
    {
        gTasks[taskID].tState = 17;
        gTasks[sEvoGraphicsTaskID].EvoGraphicsTaskEvoStop = TRUE;
        sub_8140134();
        return;
    }

    switch (gTasks[taskID].tState)
    {
    case 0:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
        gSprites[sEvoStructPtr->preEvoSpriteID].invisible = FALSE;
        gTasks[taskID].tState++;
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);
        break;
    case 1: // print 'whoa, poke is evolving!!!' msg
        if (!gPaletteFade.active)
        {
            StringExpandPlaceholders(gStringVar4, gText_PkmnIsEvolving);
            BattlePutTextOnWindow(gStringVar4, 0);
            gTasks[taskID].tState++;
        }
        break;
    case 2: // wait for string, animate mon(and play its cry)
        if (!IsTextPrinterActive(0))
        {
            EvoScene_DoMonAnimation(sEvoStructPtr->preEvoSpriteID, gTasks[taskID].tPreEvoSpecies);
            gTasks[taskID].tState++;
        }
        break;
    case 3:
        if (EvoScene_IsMonAnimFinished(sEvoStructPtr->preEvoSpriteID)) // wait for animation, play tu du SE
        {
            PlaySE(MUS_ME_SHINKA);
            gTasks[taskID].tState++;
        }
        break;
    case 4: // play evolution music and fade screen black
        if (!IsSEPlaying())
        {
            PlayNewMapMusic(MUS_SHINKA);
            gTasks[taskID].tState++;
            BeginNormalPaletteFade(0x1C, 4, 0, 0x10, RGB_BLACK);
        }
        break;
    case 5: // launch moving bg task, preapre evo sparkles
        if (!gPaletteFade.active)
        {
            InitMovingBackgroundTask(FALSE);
            sEvoGraphicsTaskID = LaunchTask_PreEvoSparklesSet1(17);
            gTasks[taskID].tState++;
        }
        break;
    case 6: // another set of evo sparkles
        if (!gTasks[sEvoGraphicsTaskID].isActive)
        {
            gTasks[taskID].tState++;
            sEvoStructPtr->field_3 = 1;
            sEvoGraphicsTaskID = LaunchTask_PreEvoSparklesSet2();
        }
        break;
    case 7: // launch task that flashes pre evo with post evo sprites
        if (!gTasks[sEvoGraphicsTaskID].isActive)
        {
            sEvoGraphicsTaskID = sub_817C3A0(sEvoStructPtr->preEvoSpriteID, sEvoStructPtr->postEvoSpriteID);
            gTasks[taskID].tState++;
        }
        break;
    case 8: // wait for the above task to finish
        if (--sEvoStructPtr->field_3 == 0)
        {
            sEvoStructPtr->field_3 = 3;
            if (!gTasks[sEvoGraphicsTaskID].isActive)
                gTasks[taskID].tState++;
        }
        break;
    case 9: // post evo sparkles
        sEvoGraphicsTaskID = LaunchTask_PostEvoSparklesSet1();
        gTasks[taskID].tState++;
        break;
    case 10:
        if (!gTasks[sEvoGraphicsTaskID].isActive)
        {
            sEvoGraphicsTaskID = LaunchTask_PostEvoSparklesSet2AndFlash(gTasks[taskID].tPostEvoSpecies);
            gTasks[taskID].tState++;
        }
        break;
    case 11: // play tu du sound after evolution
        if (!gTasks[sEvoGraphicsTaskID].isActive)
        {
            PlaySE(SE_EXP);
            gTasks[taskID].tState++;
        }
        break;
    case 12: // stop music, return screen to pre-fade state
        if (IsSEPlaying())
        {
            m4aMPlayAllStop();
            memcpy(&gPlttBufferUnfaded[0x20], sEvoStructPtr->savedPalette, 0x60);
            sub_8140174();
            BeginNormalPaletteFade(0x1C, 0, 0x10, 0, RGB_BLACK);
            gTasks[taskID].tState++;
        }
        break;
    case 13: // animate mon
        if (!gPaletteFade.active)
        {
            EvoScene_DoMonAnimation(sEvoStructPtr->postEvoSpriteID, gTasks[taskID].tPostEvoSpecies);
            gTasks[taskID].tState++;
        }
        break;
    case 14: // congratulations string and rename prompt
        if (IsCryFinished())
        {
            StringExpandPlaceholders(gStringVar4, gText_CongratsPkmnEvolved);
            BattlePutTextOnWindow(gStringVar4, 0);
            PlayBGM(MUS_FANFA5);
            gTasks[taskID].tState++;
            SetMonData(mon, MON_DATA_SPECIES, (void*)(&gTasks[taskID].tPostEvoSpecies));
            CalculateMonStats(mon);
            EvolutionRenameMon(mon, gTasks[taskID].tPreEvoSpecies, gTasks[taskID].tPostEvoSpecies);
            GetSetPokedexFlag(SpeciesToNationalPokedexNum(gTasks[taskID].tPostEvoSpecies), FLAG_SET_SEEN);
            GetSetPokedexFlag(SpeciesToNationalPokedexNum(gTasks[taskID].tPostEvoSpecies), FLAG_SET_CAUGHT);
            IncrementGameStat(GAME_STAT_EVOLVED_POKEMON);
        }
        break;
    case 15: // check if it wants to learn a new move
        if (!IsTextPrinterActive(0))
        {
            var = MonTryLearningNewMove(mon, gTasks[taskID].tLearnsFirstMove, 1);
            if (var != 0 && !gTasks[taskID].tEvoWasStopped)
            {
                u8 text[20];

                if (!(gTasks[taskID].tBits & TASK_BIT_LEARN_MOVE))
                {
                    StopMapMusic();
                    Overworld_PlaySpecialMapMusic();
                }

                gTasks[taskID].tBits |= TASK_BIT_LEARN_MOVE;
                gTasks[taskID].tLearnsFirstMove = FALSE;
                gTasks[taskID].tLearnMoveState = 0;
                GetMonData(mon, MON_DATA_NICKNAME, text);
                StringCopy10(gBattleTextBuff1, text);

                if (var == MON_HAS_MAX_MOVES)
                    gTasks[taskID].tState = 22;
                else if (var == MON_ALREADY_KNOWS_MOVE)
                    break;
                else
                    gTasks[taskID].tState = 20; // move has been learned
            }
            else // no move to learn
            {
                BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
                gTasks[taskID].tState++;
            }
        }
        break;
    case 16: // task has finished, return
        if (!gPaletteFade.active)
        {
            if (!(gTasks[taskID].tBits & TASK_BIT_LEARN_MOVE))
            {
                StopMapMusic();
                Overworld_PlaySpecialMapMusic();
            }
            if (!gTasks[taskID].tEvoWasStopped)
                CreateShedinja(gTasks[taskID].tPreEvoSpecies, mon);

            DestroyTask(taskID);
            FreeMonSpritesGfx();
            Free(sEvoStructPtr);
            sEvoStructPtr = NULL;
            FreeAllWindowBuffers();
            SetMainCallback2(gCB2_AfterEvolution);
        }
        break;
    case 17: // evolution has been canceled, stop music and re-fade palette
        if (!gTasks[sEvoGraphicsTaskID].isActive)
        {
            m4aMPlayAllStop();
            BeginNormalPaletteFade(0x6001C, 0, 0x10, 0, RGB_WHITE);
            gTasks[taskID].tState++;
        }
        break;
    case 18: // animate pokemon trying to evolve again, evolution has been stopped
        if (!gPaletteFade.active)
        {
            EvoScene_DoMonAnimation(sEvoStructPtr->preEvoSpriteID, gTasks[taskID].tPreEvoSpecies);
            gTasks[taskID].tState++;
        }
        break;
    case 19: // after the animation, print the string 'WHOA IT DID NOT EVOLVE!!!'
        if (EvoScene_IsMonAnimFinished(sEvoStructPtr->preEvoSpriteID))
        {
            if (gTasks[taskID].tEvoWasStopped)
                StringExpandPlaceholders(gStringVar4, gText_EllipsisQuestionMark);
            else // Fire Red leftover probably
                StringExpandPlaceholders(gStringVar4, gText_PkmnStoppedEvolving);

            BattlePutTextOnWindow(gStringVar4, 0);
            gTasks[taskID].tEvoWasStopped = TRUE;
            gTasks[taskID].tState = 15;
        }
        break;
    case 20: // pokemon learned a new move, print string and play a fanfare
        if (!IsTextPrinterActive(0) && !IsSEPlaying())
        {
            BufferMoveToLearnIntoBattleTextBuff2();
            PlayFanfare(MUS_FANFA1);
            BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_PKMNLEARNEDMOVE - BATTLESTRINGS_ID_ADDER]);
            BattlePutTextOnWindow(gDisplayedStringBattle, 0);
            gTasks[taskID].tLearnsFirstMove = 0x40; // re-used as a counter
            gTasks[taskID].tState++;
        }
        break;
    case 21: // wait a bit and check if can learn another move
        if (!IsTextPrinterActive(0) && !IsSEPlaying() && --gTasks[taskID].tLearnsFirstMove == 0)
            gTasks[taskID].tState = 15;
        break;
    case 22: // try to learn a new move
        switch (gTasks[taskID].tLearnMoveState)
        {
        case 0:
            if (!IsTextPrinterActive(0) && !IsSEPlaying())
            {
                BufferMoveToLearnIntoBattleTextBuff2();
                BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_TRYTOLEARNMOVE1 - BATTLESTRINGS_ID_ADDER]);
                BattlePutTextOnWindow(gDisplayedStringBattle, 0);
                gTasks[taskID].tLearnMoveState++;
            }
            break;
        case 1:
            if (!IsTextPrinterActive(0) && !IsSEPlaying())
            {
                BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_TRYTOLEARNMOVE2 - BATTLESTRINGS_ID_ADDER]);
                BattlePutTextOnWindow(gDisplayedStringBattle, 0);
                gTasks[taskID].tLearnMoveState++;
            }
            break;
        case 2:
            if (!IsTextPrinterActive(0) && !IsSEPlaying())
            {
                BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_TRYTOLEARNMOVE3 - BATTLESTRINGS_ID_ADDER]);
                BattlePutTextOnWindow(gDisplayedStringBattle, 0);
                gTasks[taskID].tData7 = 5;
                gTasks[taskID].tData8 = 10;
                gTasks[taskID].tLearnMoveState++;
            }
        case 3:
            if (!IsTextPrinterActive(0) && !IsSEPlaying())
            {
                HandleBattleWindow(0x18, 8, 0x1D, 0xD, 0);
                BattlePutTextOnWindow(gText_BattleYesNoChoice, 0xC);
                gTasks[taskID].tLearnMoveState++;
                sEvoCursorPos = 0;
                BattleCreateYesNoCursorAt(0);
            }
            break;
        case 4:
            if (gMain.newKeys & DPAD_UP && sEvoCursorPos != 0)
            {
                PlaySE(SE_SELECT);
                BattleDestroyYesNoCursorAt(sEvoCursorPos);
                sEvoCursorPos = 0;
                BattleCreateYesNoCursorAt(0);
            }
            if (gMain.newKeys & DPAD_DOWN && sEvoCursorPos == 0)
            {
                PlaySE(SE_SELECT);
                BattleDestroyYesNoCursorAt(sEvoCursorPos);
                sEvoCursorPos = 1;
                BattleCreateYesNoCursorAt(1);
            }
            if (gMain.newKeys & A_BUTTON)
            {
                HandleBattleWindow(0x18, 8, 0x1D, 0xD, WINDOW_CLEAR);
                PlaySE(SE_SELECT);

                if (sEvoCursorPos != 0)
                {
                    gTasks[taskID].tLearnMoveState = gTasks[taskID].tData8;
                }
                else
                {
                    gTasks[taskID].tLearnMoveState = gTasks[taskID].tData7;
                    if (gTasks[taskID].tLearnMoveState == 5)
                        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
                }
            }
            if (gMain.newKeys & B_BUTTON)
            {
                HandleBattleWindow(0x18, 8, 0x1D, 0xD, WINDOW_CLEAR);
                PlaySE(SE_SELECT);
                gTasks[taskID].tLearnMoveState = gTasks[taskID].tData8;
            }
            break;
        case 5:
            if (!gPaletteFade.active)
            {
                FreeAllWindowBuffers();
                ShowSelectMovePokemonSummaryScreen(gPlayerParty, gTasks[taskID].tPartyID,
                            gPlayerPartyCount - 1, CB2_EvolutionSceneLoadGraphics,
                            gMoveToLearn);
                gTasks[taskID].tLearnMoveState++;
            }
            break;
        case 6:
            if (!gPaletteFade.active && gMain.callback2 == CB2_EvolutionSceneUpdate)
            {
                var = GetMoveSlotToReplace();
                if (var == MAX_MON_MOVES)
                {
                    gTasks[taskID].tLearnMoveState = 10;
                }
                else
                {
                    u16 move = GetMonData(mon, var + MON_DATA_MOVE1);
                    if (IsHMMove2(move))
                    {
                        BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_HMMOVESCANTBEFORGOTTEN - BATTLESTRINGS_ID_ADDER]);
                        BattlePutTextOnWindow(gDisplayedStringBattle, 0);
                        gTasks[taskID].tLearnMoveState = 12;
                    }
                    else
                    {
                        PREPARE_MOVE_BUFFER(gBattleTextBuff2, move)

                        RemoveMonPPBonus(mon, var);
                        SetMonMoveSlot(mon, gMoveToLearn, var);
                        gTasks[taskID].tLearnMoveState++;
                    }
                }
            }
            break;
        case 7:
            BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_123POOF - BATTLESTRINGS_ID_ADDER]);
            BattlePutTextOnWindow(gDisplayedStringBattle, 0);
            gTasks[taskID].tLearnMoveState++;
            break;
        case 8:
            if (!IsTextPrinterActive(0) && !IsSEPlaying())
            {
                BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_PKMNFORGOTMOVE - BATTLESTRINGS_ID_ADDER]);
                BattlePutTextOnWindow(gDisplayedStringBattle, 0);
                gTasks[taskID].tLearnMoveState++;
            }
            break;
        case 9:
            if (!IsTextPrinterActive(0) && !IsSEPlaying())
            {
                BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_ANDELLIPSIS - BATTLESTRINGS_ID_ADDER]);
                BattlePutTextOnWindow(gDisplayedStringBattle, 0);
                gTasks[taskID].tState = 20;
            }
            break;
        case 10:
            BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_STOPLEARNINGMOVE - BATTLESTRINGS_ID_ADDER]);
            BattlePutTextOnWindow(gDisplayedStringBattle, 0);
            gTasks[taskID].tData7 = 11;
            gTasks[taskID].tData8 = 0;
            gTasks[taskID].tLearnMoveState = 3;
            break;
        case 11:
            BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_DIDNOTLEARNMOVE - BATTLESTRINGS_ID_ADDER]);
            BattlePutTextOnWindow(gDisplayedStringBattle, 0);
            gTasks[taskID].tState = 15;
            break;
        case 12:
            if (!IsTextPrinterActive(0) && !IsSEPlaying())
                gTasks[taskID].tLearnMoveState = 5;
            break;
        }
        break;
    }
}

static void Task_TradeEvolutionScene(u8 taskID)
{
    u32 var = 0;
    struct Pokemon* mon = &gPlayerParty[gTasks[taskID].tPartyID];

    switch (gTasks[taskID].tState)
    {
    case 0:
        StringExpandPlaceholders(gStringVar4, gText_PkmnIsEvolving);
        DrawTextOnTradeWindow(0, gStringVar4, 1);
        gTasks[taskID].tState++;
        break;
    case 1:
        if (!IsTextPrinterActive(0))
        {
            PlayCry1(gTasks[taskID].tPreEvoSpecies, 0);
            gTasks[taskID].tState++;
        }
        break;
    case 2:
        if (IsCryFinished())
        {
            m4aSongNumStop(MUS_SHINKA);
            PlaySE(MUS_ME_SHINKA);
            gTasks[taskID].tState++;
        }
        break;
    case 3:
        if (!IsSEPlaying())
        {
            PlayBGM(MUS_SHINKA);
            gTasks[taskID].tState++;
            BeginNormalPaletteFade(0x1C, 4, 0, 0x10, RGB_BLACK);
        }
        break;
    case 4:
        if (!gPaletteFade.active)
        {
            InitMovingBackgroundTask(TRUE);
            var = gSprites[sEvoStructPtr->preEvoSpriteID].oam.paletteNum + 16;
            sEvoGraphicsTaskID = LaunchTask_PreEvoSparklesSet1(var);
            gTasks[taskID].tState++;
            SetGpuReg(REG_OFFSET_BG3CNT, 0x603);
        }
        break;
    case 5:
        if (!gTasks[sEvoGraphicsTaskID].isActive)
        {
            gTasks[taskID].tState++;
            sEvoStructPtr->field_3 = 1;
            sEvoGraphicsTaskID = LaunchTask_PreEvoSparklesSet2();
        }
        break;
    case 6:
        if (!gTasks[sEvoGraphicsTaskID].isActive)
        {
            sEvoGraphicsTaskID = sub_817C3A0(sEvoStructPtr->preEvoSpriteID, sEvoStructPtr->postEvoSpriteID);
            gTasks[taskID].tState++;
        }
        break;
    case 7:
        if (--sEvoStructPtr->field_3 == 0)
        {
            sEvoStructPtr->field_3 = 3;
            if (!gTasks[sEvoGraphicsTaskID].isActive)
                gTasks[taskID].tState++;
        }
        break;
    case 8:
        sEvoGraphicsTaskID = LaunchTask_PostEvoSparklesSet1();
        gTasks[taskID].tState++;
        break;
    case 9:
        if (!gTasks[sEvoGraphicsTaskID].isActive)
        {
            sEvoGraphicsTaskID = LaunchTask_PostEvoSparklesSet2AndFlash_Trade(gTasks[taskID].tPostEvoSpecies);
            gTasks[taskID].tState++;
        }
        break;
    case 10:
        if (!gTasks[sEvoGraphicsTaskID].isActive)
        {
            PlaySE(SE_EXP);
            gTasks[taskID].tState++;
        }
        break;
    case 11:
        if (IsSEPlaying())
        {
            Free(sEvoMovingBgPtr);
            EvoScene_DoMonAnimation(sEvoStructPtr->postEvoSpriteID, gTasks[taskID].tPostEvoSpecies);
            memcpy(&gPlttBufferUnfaded[0x20], sEvoStructPtr->savedPalette, 0x60);
            gTasks[taskID].tState++;
        }
        break;
    case 12:
        if (IsCryFinished())
        {
            StringExpandPlaceholders(gStringVar4, gText_CongratsPkmnEvolved);
            DrawTextOnTradeWindow(0, gStringVar4, 1);
            PlayFanfare(MUS_FANFA5);
            gTasks[taskID].tState++;
            SetMonData(mon, MON_DATA_SPECIES, (&gTasks[taskID].tPostEvoSpecies));
            CalculateMonStats(mon);
            EvolutionRenameMon(mon, gTasks[taskID].tPreEvoSpecies, gTasks[taskID].tPostEvoSpecies);
            GetSetPokedexFlag(SpeciesToNationalPokedexNum(gTasks[taskID].tPostEvoSpecies), FLAG_SET_SEEN);
            GetSetPokedexFlag(SpeciesToNationalPokedexNum(gTasks[taskID].tPostEvoSpecies), FLAG_SET_CAUGHT);
            IncrementGameStat(GAME_STAT_EVOLVED_POKEMON);
        }
        break;
    case 13:
        if (!IsTextPrinterActive(0) && IsFanfareTaskInactive() == TRUE)
        {
            var = MonTryLearningNewMove(mon, gTasks[taskID].tLearnsFirstMove, 1);
            if (var != 0 && !gTasks[taskID].tEvoWasStopped)
            {
                u8 text[20];

                gTasks[taskID].tBits |= TASK_BIT_LEARN_MOVE;
                gTasks[taskID].tLearnsFirstMove = FALSE;
                gTasks[taskID].tLearnMoveState = 0;
                GetMonData(mon, MON_DATA_NICKNAME, text);
                StringCopy10(gBattleTextBuff1, text);

                if (var == MON_HAS_MAX_MOVES)
                    gTasks[taskID].tState = 20;
                else if (var == MON_ALREADY_KNOWS_MOVE)
                    break;
                else
                    gTasks[taskID].tState = 18;
            }
            else
            {
                PlayBGM(MUS_SHINKA);
                DrawTextOnTradeWindow(0, gText_CommunicationStandby5, 1);
                gTasks[taskID].tState++;
            }
        }
        break;
    case 14:
        if (!IsTextPrinterActive(0))
        {
            DestroyTask(taskID);
            Free(sEvoStructPtr);
            sEvoStructPtr = NULL;
            gTextFlags.useAlternateDownArrow = 0;
            SetMainCallback2(gCB2_AfterEvolution);
        }
        break;
    case 15:
        if (!gTasks[sEvoGraphicsTaskID].isActive)
        {
            m4aMPlayAllStop();
            BeginNormalPaletteFade((1 << (gSprites[sEvoStructPtr->preEvoSpriteID].oam.paletteNum + 16)) | (0x4001C), 0, 0x10, 0, RGB_WHITE);
            gTasks[taskID].tState++;
        }
        break;
    case 16:
        if (!gPaletteFade.active)
        {
            EvoScene_DoMonAnimation(sEvoStructPtr->preEvoSpriteID, gTasks[taskID].tPreEvoSpecies);
            gTasks[taskID].tState++;
        }
        break;
    case 17:
        if (EvoScene_IsMonAnimFinished(sEvoStructPtr->preEvoSpriteID))
        {
            StringExpandPlaceholders(gStringVar4, gText_EllipsisQuestionMark);
            DrawTextOnTradeWindow(0, gStringVar4, 1);
            gTasks[taskID].tEvoWasStopped = 1;
            gTasks[taskID].tState = 13;
        }
        break;
    case 18:
        if (!IsTextPrinterActive(0) && !IsSEPlaying())
        {
            BufferMoveToLearnIntoBattleTextBuff2();
            PlayFanfare(MUS_FANFA1);
            BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_PKMNLEARNEDMOVE - BATTLESTRINGS_ID_ADDER]);
            DrawTextOnTradeWindow(0, gDisplayedStringBattle, 1);
            gTasks[taskID].tLearnsFirstMove = 0x40; // re-used as a counter
            gTasks[taskID].tState++;
        }
        break;
    case 19:
        if (!IsTextPrinterActive(0) && IsFanfareTaskInactive() == TRUE && --gTasks[taskID].tLearnsFirstMove == 0)
            gTasks[taskID].tState = 13;
        break;
    case 20:
        switch (gTasks[taskID].tLearnMoveState)
        {
        case 0:
            if (!IsTextPrinterActive(0) && !IsSEPlaying())
            {
                BufferMoveToLearnIntoBattleTextBuff2();
                BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_TRYTOLEARNMOVE1 - BATTLESTRINGS_ID_ADDER]);
                DrawTextOnTradeWindow(0, gDisplayedStringBattle, 1);
                gTasks[taskID].tLearnMoveState++;
            }
            break;
        case 1:
            if (!IsTextPrinterActive(0) && !IsSEPlaying())
            {
                BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_TRYTOLEARNMOVE2 - BATTLESTRINGS_ID_ADDER]);
                DrawTextOnTradeWindow(0, gDisplayedStringBattle, 1);
                gTasks[taskID].tLearnMoveState++;
            }
            break;
        case 2:
            if (!IsTextPrinterActive(0) && !IsSEPlaying())
            {
                BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_TRYTOLEARNMOVE3 - BATTLESTRINGS_ID_ADDER]);
                DrawTextOnTradeWindow(0, gDisplayedStringBattle, 1);
                gTasks[taskID].tData7 = 5;
                gTasks[taskID].tData8 = 9;
                gTasks[taskID].tLearnMoveState++;
            }
        case 3:
            if (!IsTextPrinterActive(0) && !IsSEPlaying())
            {
                LoadUserWindowBorderGfx(0, 0xA8, 0xE0);
                CreateYesNoMenu(&gTradeEvolutionSceneYesNoWindowTemplate, 0xA8, 0xE, 0);
                sEvoCursorPos = 0;
                gTasks[taskID].tLearnMoveState++;
                sEvoCursorPos = 0;
            }
            break;
        case 4:
            switch (Menu_ProcessInputNoWrapClearOnChoose())
            {
            case 0:
                sEvoCursorPos = 0;
                BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_EMPTYSTRING3 - BATTLESTRINGS_ID_ADDER]);
                DrawTextOnTradeWindow(0, gDisplayedStringBattle, 1);
                gTasks[taskID].tLearnMoveState = gTasks[taskID].tData7;
                if (gTasks[taskID].tLearnMoveState == 5)
                    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
                break;
            case 1:
            case -1:
                sEvoCursorPos = 1;
                BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_EMPTYSTRING3 - BATTLESTRINGS_ID_ADDER]);
                DrawTextOnTradeWindow(0, gDisplayedStringBattle, 1);
                gTasks[taskID].tLearnMoveState = gTasks[taskID].tData8;
                break;
            }
            break;
        case 5:
            if (!gPaletteFade.active)
            {
                if (gWirelessCommType)
                    DestroyWirelessStatusIndicatorSprite();

                Free(GetBgTilemapBuffer(3));
                Free(GetBgTilemapBuffer(1));
                Free(GetBgTilemapBuffer(0));
                FreeAllWindowBuffers();

                ShowSelectMovePokemonSummaryScreen(gPlayerParty, gTasks[taskID].tPartyID,
                            gPlayerPartyCount - 1, CB2_TradeEvolutionSceneLoadGraphics,
                            gMoveToLearn);
                gTasks[taskID].tLearnMoveState++;
            }
            break;
        case 6:
            if (!gPaletteFade.active && gMain.callback2 == CB2_TradeEvolutionSceneUpdate)
            {
                var = GetMoveSlotToReplace();
                if (var == MAX_MON_MOVES)
                {
                    gTasks[taskID].tLearnMoveState = 9;
                }
                else
                {
                    u16 move = GetMonData(mon, var + MON_DATA_MOVE1);
                    if (IsHMMove2(move))
                    {
                        BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_HMMOVESCANTBEFORGOTTEN - BATTLESTRINGS_ID_ADDER]);
                        DrawTextOnTradeWindow(0, gDisplayedStringBattle, 1);
                        gTasks[taskID].tLearnMoveState = 11;
                    }
                    else
                    {
                        PREPARE_MOVE_BUFFER(gBattleTextBuff2, move)

                        RemoveMonPPBonus(mon, var);
                        SetMonMoveSlot(mon, gMoveToLearn, var);
                        BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_123POOF - BATTLESTRINGS_ID_ADDER]);
                        DrawTextOnTradeWindow(0, gDisplayedStringBattle, 1);
                        gTasks[taskID].tLearnMoveState++;
                    }
                }
            }
            break;
        case 7:
            if (!IsTextPrinterActive(0) && !IsSEPlaying())
            {
                BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_PKMNFORGOTMOVE - BATTLESTRINGS_ID_ADDER]);
                DrawTextOnTradeWindow(0, gDisplayedStringBattle, 1);
                gTasks[taskID].tLearnMoveState++;
            }
            break;
        case 8:
            if (!IsTextPrinterActive(0) && !IsSEPlaying())
            {
                BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_ANDELLIPSIS - BATTLESTRINGS_ID_ADDER]);
                DrawTextOnTradeWindow(0, gDisplayedStringBattle, 1);
                gTasks[taskID].tState = 18;
            }
            break;
        case 9:
            BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_STOPLEARNINGMOVE - BATTLESTRINGS_ID_ADDER]);
            DrawTextOnTradeWindow(0, gDisplayedStringBattle, 1);
            gTasks[taskID].tData7 = 10;
            gTasks[taskID].tData8 = 0;
            gTasks[taskID].tLearnMoveState = 3;
            break;
        case 10:
            BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_DIDNOTLEARNMOVE - BATTLESTRINGS_ID_ADDER]);
            DrawTextOnTradeWindow(0, gDisplayedStringBattle, 1);
            gTasks[taskID].tState = 13;
            break;
        case 11:
            if (!IsTextPrinterActive(0) && !IsSEPlaying())
                gTasks[taskID].tLearnMoveState = 5;
            break;
        }
        break;
    }
}

#undef tState
// >