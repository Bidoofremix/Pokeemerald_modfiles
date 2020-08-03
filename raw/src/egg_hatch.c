< //
u8 GetEggCyclesToSubtract(void)
{
    u8 count, i;
	int n = 1;
	
	for (count = CalculatePlayerPartyCount(), i = 0; i < count; i++)
    {
        if (!GetMonData(&gPlayerParty[i], MON_DATA_SANITY_IS_EGG))
        {
            u8 ability = GetMonAbility(&gPlayerParty[i]);		
            if (ability == ABILITY_MAGMA_ARMOR || ability == ABILITY_FLAME_BODY)
			{
				if (GetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM) == ITEM_CHARCOAL)
                {
					if (n < 4)
						n = 4;
				}
				else
				{
					if (n < 2)
						n = 2;
				}
			}
        }
    }
	
	if (n == 1)
	{
		return 1;
	}
	else if (n == 2)
	{
		return 2;
	}
	else
	{
		return 4;
	}
}

u16 CountPartyAliveNonEggMons(void)
// >