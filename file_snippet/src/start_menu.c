< //
#include "window.h"
#include "quests.h"
#include "constants/songs.h"
// >

< //
    MENU_ACTION_RETIRE_FRONTIER,
    MENU_ACTION_PYRAMID_BAG,
	MENU_ACTION_QUEST_MENU
};

// Save status
// >

< //
static bool8 StartMenuBattlePyramidBagCallback(void);
static bool8 QuestMenuCallback(void);

// Menu callbacks
static bool8 SaveStartCallback(void);
// >

< //
static const struct WindowTemplate sPyramidFloorWindowTemplate_1 = {0, 1, 1, 0xC, 4, 0xF, 8};

static const u8 sText_QuestMenu[] = _("QUESTS");

static const struct MenuAction sStartMenuItems[] =
{
    [MENU_ACTION_POKEDEX]           = {gText_MenuPokedex, {.u8_void = StartMenuPokedexCallback}},
    [MENU_ACTION_POKEMON]           = {gText_MenuPokemon, {.u8_void = StartMenuPokemonCallback}},
    [MENU_ACTION_BAG]               = {gText_MenuBag, {.u8_void = StartMenuBagCallback}},
    [MENU_ACTION_POKENAV]           = {gText_MenuPokenav, {.u8_void = StartMenuPokeNavCallback}},
    [MENU_ACTION_PLAYER]            = {gText_MenuPlayer, {.u8_void = StartMenuPlayerNameCallback}},
    [MENU_ACTION_SAVE]              = {gText_MenuSave, {.u8_void = StartMenuSaveCallback}},
    [MENU_ACTION_OPTION]            = {gText_MenuOption, {.u8_void = StartMenuOptionCallback}},
    [MENU_ACTION_EXIT]              = {gText_MenuExit, {.u8_void = StartMenuExitCallback}},
    [MENU_ACTION_RETIRE_SAFARI]     = {gText_MenuRetire, {.u8_void = StartMenuSafariZoneRetireCallback}},
    [MENU_ACTION_PLAYER_LINK]       = {gText_MenuPlayer, {.u8_void = StartMenuLinkModePlayerNameCallback}},
    [MENU_ACTION_REST_FRONTIER]     = {gText_MenuRest, {.u8_void = StartMenuSaveCallback}},	
    [MENU_ACTION_RETIRE_FRONTIER]   = {gText_MenuRetire, {.u8_void = StartMenuBattlePyramidRetireCallback}},
    [MENU_ACTION_PYRAMID_BAG]       = {gText_MenuBag, {.u8_void = StartMenuBattlePyramidBagCallback}},
    [MENU_ACTION_QUEST_MENU]        = {sText_QuestMenu, {.u8_void = QuestMenuCallback}},
};

static const struct BgTemplate sUnknown_085105A8[] =
// >

< //
    AddStartMenuAction(MENU_ACTION_PLAYER);
    if (FlagGet(FLAG_SYS_QUEST_MENU_GET))
        AddStartMenuAction(MENU_ACTION_QUEST_MENU);
    AddStartMenuAction(MENU_ACTION_SAVE);
// >

< //
void AppendToList(u8 *list, u8 *pos, u8 newEntry)
{
    list[*pos] = newEntry;
    (*pos)++;
}

static bool8 QuestMenuCallback(void)
{
    CreateTask(Task_OpenQuestMenuFromStartMenu, 0);
    return TRUE;
}

// > END