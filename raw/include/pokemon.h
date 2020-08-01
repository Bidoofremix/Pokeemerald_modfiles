< //
#include "sprite.h"

#define DAY_START 4
#define NIGHT_START 18

struct PokemonSubstruct0
// >

< //
void GiveBoxMonInitialMoveset(struct BoxPokemon *boxMon);
u16 MonTryLearningNewMove(struct Pokemon *mon, bool8 firstMove, bool8isEvolving);
void DeleteFirstMoveAndGiveMoveToMon(struct Pokemon *mon, u16 move);
// >