< //
bool32 IsRunningDisallowed(u8 metatile)
{
    if (IsRunningDisallowedByMetatile(metatile) == TRUE)
        return TRUE;
    else
        return FALSE;
}
// > END