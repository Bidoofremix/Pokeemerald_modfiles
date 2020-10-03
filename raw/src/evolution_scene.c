< //
    case 15: // check if it wants to learn a new move
        if (!IsTextPrinterActive(0))
        {
            var = MonTryLearningNewMove(mon, gTasks[taskID].tLearnsFirstMove, 1);
            if (var != 0 && !gTasks[taskID].tEvoWasStopped)
// >

< //
    case 13:
        if (!IsTextPrinterActive(0) && IsFanfareTaskInactive() == TRUE)
        {
            var = MonTryLearningNewMove(mon, gTasks[taskID].tLearnsFirstMove, 1);
            if (var != 0 && !gTasks[taskID].tEvoWasStopped)
// >