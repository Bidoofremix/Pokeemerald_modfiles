< //
NavelRock_Fork_MapScripts:: @ 826910E
	map_script MAP_SCRIPT_ON_RESUME, RhyoliteCanyon_OnResume
	.byte 0

RhyoliteCanyon_OnResume: @ 81F215E
	setstepcallback STEP_CB_ASH
	end

// > END