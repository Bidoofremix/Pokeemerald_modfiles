< //
const struct MonCoords gTrainerFrontPicCoords[] =
{
    [TRAINER_PIC_HIKER] = {.size = 8, .y_offset = 1},
	[TRAINER_PIC_MEWTWO] = {.size = 8, .y_offset = 1},
    [TRAINER_PIC_AQUA_GRUNT_M] = {.size = 8, .y_offset = 1},
// >

< //
const struct CompressedSpriteSheet gTrainerFrontPicTable[] =
{
    TRAINER_SPRITE(HIKER, gTrainerFrontPic_Hiker, 0x800),
    TRAINER_SPRITE(MEWTWO, gTrainerFrontPic_Mewtwo, 0x800),
    TRAINER_SPRITE(AQUA_GRUNT_M, gTrainerFrontPic_AquaGruntM, 0x800),
// >	
	
const struct CompressedSpritePalette gTrainerFrontPicPaletteTable[] =
{
    TRAINER_PAL(HIKER, gTrainerPalette_Hiker),
    TRAINER_PAL(MEWTWO, gTrainerPalette_Mewtwo),
    TRAINER_PAL(AQUA_GRUNT_M, gTrainerPalette_AquaGruntM),
// >