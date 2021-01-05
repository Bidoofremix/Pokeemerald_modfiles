< //
static const struct MenuAction MultichoiceList_GameCornerTMs[] =
{
    {gText_TM32AndPrice},
    {gText_TM29AndPrice},
    {gText_TM35AndPrice},
    {gText_TM24AndPrice},
    {gText_TM13AndPrice},
    {gText_Exit},
};

static const struct MenuAction MultichoiceList_GameCornerStones1[] =
{
    {gText_FireStoneAndPrice},
    {gText_WaterStoneAndPrice},
    {gText_ThunderStoneAndPrice},
    {gText_LeafStoneAndPrice},
    {gText_IceStoneAndPrice},
    {gText_Exit},
};

static const struct MenuAction MultichoiceList_GameCornerStones2[] =
{
    {gText_SunStoneAndPrice},
    {gText_MoonStoneAndPrice},
    {gText_ShinyStoneAndPrice},
    {gText_DuskStoneAndPrice},
    {gText_DawnStoneAndPrice},
    {gText_Exit},
};

static const struct MenuAction MultichoiceList_SingleDouble[] =
{
	{gText_Single},
	{gText_Double},
	{gText_Exit},
};

static const struct MenuAction MultichoiceList_SingleChallenges[] = 
{
	{gText_TheWorst},
	{gText_Spicy2},
	{gText_SpacePoints2},
	{gText_Exit},
};

static const struct MenuAction MultichoiceList_GameCornerCoins[] =
// >


< //
    [MULTI_GAME_CORNER_TMS]            = MULTICHOICE(MultichoiceList_GameCornerTMs),
    [MULTI_GAME_CORNER_STONES_1]       = MULTICHOICE(MultichoiceList_GameCornerStones1),
    [MULTI_GAME_CORNER_STONES_2]       = MULTICHOICE(MultichoiceList_GameCornerStones2),
	[MULTI_SINGLE_DOUBLE]              = MULTICHOICE(MultichoiceList_SingleDouble),
	[MULTI_SINGLE_CHALLENGES]          = MULTICHOICE(MultichoiceList_SingleChallenges),
    [MULTI_SSTIDAL_SLATEPORT_NO_BF]    = MULTICHOICE(MultichoiceList_SSTidalSlateportNoBF),
// >