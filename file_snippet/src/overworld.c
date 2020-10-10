< //
#include "constants/weather.h"
// custom
#include "constants/rgb.h"

#define PLAYER_TRADING_STATE_IDLE 0x80
// >

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
	// put here something that tints the palette
	// how???
}

void SetDefaultFlashLevel(void)
// >