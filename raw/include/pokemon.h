< //
#include "sprite.h"

#define DAY_START 4
#define NIGHT_START 18

struct PokemonSubstruct0
// >

< //
#define OT_ID_PLAYER_ID       0
#define OT_ID_PRESET          1
#define OT_ID_RANDOM_NO_SHINY 2
#define OT_ID_RANDOM_SHINY    3

#define MON_GIVEN_TO_PARTY      0
// >

< //
void GiveBoxMonInitialMoveset(struct BoxPokemon *boxMon);
u16 MonTryLearningNewMove(struct Pokemon *mon, bool8 firstMove, bool8 isEvolving);
void DeleteFirstMoveAndGiveMoveToMon(struct Pokemon *mon, u16 move);
// >