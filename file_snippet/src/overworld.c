< //    
	ChooseAmbientCrySpecies();
    SetTimeBasedHue();
    SetDefaultFlashLevel();
// >

< //
static void OverworldBasic(void)
{
    ScriptContext2_RunScript();
    RunTasks();
    SetTimeBasedHue();
    AnimateSprites();
// >

< //
bool32 Overworld_IsBikingAllowed(void)
{
    if (!(gMapHeader.flags & MAP_ALLOW_CYCLING))
        return FALSE;
    else
        return TRUE;
}

void SetTimeBasedHue(void)
{
}

void SetDefaultFlashLevel(void)
// >