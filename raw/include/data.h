< //
struct TrainerMonItemCustomMoves
{
    u16 iv;
    u8 lvl;
    u16 species;
    u16 heldItem;
    u16 moves[MAX_MON_MOVES];
};

// new trainer types for fixed ability and shiny mons
struct TrainerMonItemDefaultMovesAbilityShiny
{
	u16 iv;
    u8 lvl;
    u16 species;
    u16 heldItem;
	u32 abilityNum;
	u8 shiny;
};

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
	const struct TrainerMonItemDefaultMovesAbilityShiny *ItemDefaultMovesAbilityShiny;
    const struct TrainerMonItemCustomMovesAbilityShiny *ItemCustomMovesAbilityShiny;
};

struct Trainer
// >