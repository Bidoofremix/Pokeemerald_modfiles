< //
bool32 IsRunningDisallowed(u8 metatile)
{
    if (IsRunningDisallowedByMetatile(metatile) == TRUE)
        return TRUE;
    else
        return FALSE;
}
// > END

< //
void MovePlayerOnBike(u8 direction, u16 newKeys, u16 heldKeys)
{
    if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_MACH_BIKE)
        MovePlayerOnMachBike(direction, newKeys, heldKeys);
    else
        MovePlayerOnAcroBike(direction, newKeys, heldKeys);

    if (heldKeys & R_BUTTON)
    {
        if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_MACH_BIKE)
        {
            gPlayerAvatar.flags -= PLAYER_AVATAR_FLAG_MACH_BIKE;
            gPlayerAvatar.flags += PLAYER_AVATAR_FLAG_ACRO_BIKE;
			SetPlayerAvatarTransitionFlags(PLAYER_AVATAR_FLAG_ACRO_BIKE);
        }
        else
        {
            gPlayerAvatar.flags -= PLAYER_AVATAR_FLAG_ACRO_BIKE;
            gPlayerAvatar.flags += PLAYER_AVATAR_FLAG_MACH_BIKE;
			SetPlayerAvatarTransitionFlags(PLAYER_AVATAR_FLAG_MACH_BIKE);
        }
        PlaySE(SE_BIKE_BELL);
    }
}

static void MovePlayerOnMachBike(u8 direction, u16 newKeys, u16 heldKeys)
// >