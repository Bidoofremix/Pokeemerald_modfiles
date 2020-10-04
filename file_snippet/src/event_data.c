< //
#include "event_data.h"
#include "constants/species.h"
#include "pokedex.h"
// >

< //
void DisableNationalPokedex(void)
{
    u16 *nationalDexVar = GetVarPointer(VAR_NATIONAL_DEX);
    gSaveBlock2Ptr->pokedex.nationalMagic = 0;
    *nationalDexVar = 0;
    FlagClear(FLAG_SYS_NATIONAL_DEX);
}

void SetAllSpeciesSeen(void)
{
    u16 i;

    for (i = 0; i < NATIONAL_DEX_COUNT; i++)
    {
		GetSetPokedexFlag(i+1, FLAG_SET_SEEN);
    }
}

void EnableNationalPokedex(void)
// >