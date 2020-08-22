< //
struct TrainerMonItemCustomMoves
{
    u16 iv;
    u8 lvl;
    u16 species;
    u16 heldItem;
    u16 moves[MAX_MON_MOVES];
};

// new trainer type for fixed ability and shiny mons
struct TrainerMonItemCustomMovesAbilityShiny
{
	u16 iv;
    u8 lvl;
    u16 species;
    u16 heldItem;
    u16 moves[MAX_MON_MOVES];
	u32 abilityNum;
	u8 shiny;
};

union TrainerMonPtr
{
    const struct TrainerMonNoItemDefaultMoves *NoItemDefaultMoves;
    const struct TrainerMonNoItemCustomMoves *NoItemCustomMoves;
    const struct TrainerMonItemDefaultMoves *ItemDefaultMoves;
    const struct TrainerMonItemCustomMoves *ItemCustomMoves;
    const struct TrainerMonItemCustomMovesAbility *ItemCustomMovesAbilityShiny;
};

struct Trainer
// >