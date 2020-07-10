< //
	@ Opens the Pokemart system, offering the specified products for sale.
	.macro pokemart products:req, tmshopid = 0
	.byte 0x86
	.4byte \products
	.2byte \tmpshopid
	.endm

	@ Opens the Pokemart system and treats the list of items as decorations.
	.macro pokemartdecoration products:req
// >