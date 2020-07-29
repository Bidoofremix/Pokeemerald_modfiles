#!/usr/bin/python3
#-*- encoding: utf-8 -*-

import os,xlrd,shutil,math
from config import vanilla_dir,slash,pokeemerald_dir
from misc import *
from pokemon_tools import *
from PIL import Image

raw_folder = normalize_path(os.getcwd() + "\\raw")

########## read mandatory base stats from base_stats.txt

required_stats_file = "base_stats.txt"

required_stats = []
with open(required_stats_file, "r") as f:
	for line in f:
		required_stats.append(line.rstrip("\n").rstrip("\r"))
		
pokedex_parameters_file = "pokedex_parameters.txt"

pokedex_parameters = []
with open(pokedex_parameters_file, "r") as f:
	for line in f:
		pokedex_parameters.append(line.rstrip("\n").rstrip("\r"))
		
########## read new family-based order

family_order = []
order_file = "family_dex_order.txt"
with open(order_file, "r") as f:
	for line in f:
		line = line.rstrip("\n").rstrip("\r")
		if line != "":
			family_order.append(line)

							
########## read excel with new mon data

new_species = {}
insert_info = {}

new_species_excel = "pokemon/new_species.xlsx"
xl_workbook = xlrd.open_workbook(new_species_excel, encoding_override="utf8")
sheet_names = xl_workbook.sheet_names()

# each mon
for name in sheet_names:
	xl_sheet = xl_workbook.sheet_by_name(name)
	
	for i in range(0,xl_sheet.nrows):
		row = [c.value for c in xl_sheet.row(i)]
		tmp_row = []
		
		# convert digits to ints and trim strings
		for c in row:
			if isinstance(c,float):
				if c % 1 == 0.0:
					tmp_row.append(int(c))
				else:
					tmp_row.append(c)
			else:
				if isinstance(c,int):
					tmp_row.append(c)
				else:
					tmp_row.append(c.strip())
		row = tmp_row
		
		if row[0] == "name":
			mon = underscore_upper(row[1])
			print(mon)
			new_species[mon] = {"base_stats":{}, "pokedex_entry":{},\
								"level_up_moves":[], "egg_moves":[],\
								"tutor_moves":[], "tmhm_moves":[],\
								"pokedex_description":[[] for _ in range(4)],\
								"pokedex_entry":{}}

		if row[0] == "display_name":
			new_species[mon]["display_name"] = '_("{0}")'.format(row[1])
								
		if row[0].startswith("."):
			if row[0] not in required_stats:
				print("\nerror: unrecognized stat '%s'" % row[0])
				exit(0)
			new_species[mon]["base_stats"][row[0]] = row[1]

		else:
			# level-up moves
			if row[0] == "LEVEL_UP_MOVE":
				check_level(row[1])
				move = check_move(row[2])
				new_species[mon]["level_up_moves"].append([row[1],move])
			
			# egg moves
			if row[0] == "EGG_MOVE":
				move = check_move(row[2])
				new_species[mon]["egg_moves"].append(move)
			
			# tutor moves
			if row[0] == "TUTOR_MOVE":
				move = check_move(row[2])
				new_species[mon]["tutor_moves"].append(move)

			# TM/HM moves
			if row[0] == "TM_MOVE":
				move = check_tmmove(row[2])
				new_species[mon]["tmhm_moves"].append(move)
		
			# where to insert
			if row[0] == "where":
				if row[1] not in ["before","after"]:
					print("\nerror: unknown order preposition '%s'% " % row[1])
					exit(0)
				who = underscore_upper(row[2])
				if who not in family_order:
					print("\nerror: unknown index species '%s'" % who)
					exit(0)
				insert_info[mon] = {"where":row[1], "who":who}

			# pokedex description
			if row[0].startswith("pokedex_entry_line"):
				which_line = int(row[0][-1])-1
				new_species[mon]["pokedex_description"][which_line] = clean_text(row[1])
			
			# category
			if row[0] == "category":
				new_species[mon]["pokedex_entry"][".categoryName"] = '_("{0}")'.format(row[1].upper())
		
			# height, weight
			if row[0] in ["height (cm)", "weight (kg)"]:
				if row[0] == "height (cm)":
					if not row[1] % 10 == 0:
						print("\nerror: height must be divisible by 10")
						exit(0)
					else:
						mon_height = row[1]//10
						new_species[mon]["pokedex_entry"][".height"] = mon_height
				if row[0] == "weight (kg)":
						mon_weight = int(float(row[1])*10)
						new_species[mon]["pokedex_entry"][".weight"] = mon_weight
			
			# scales and offsets
			if row[0] in ["pokemonScale","pokemonOffset","trainerScale","trainerOffset"]:
				new_species[mon]["pokedex_entry"][".{0}".format(row[0])] = row[1]
						
			# evolution
			if row[0] == "evolves":
				new_species[mon]["evolution"] = {"target":"SPECIES_%s" % row[1], \
					"method": row[2], "parameter":row[3]}
						
	# check mandatory stats
	if not all([s in new_species[mon]["base_stats"] for s in required_stats]):
		print("\nerror: {0} missing the following stats:".format(mon))
		for s in required_stats:
			if s not in new_species[mon]["base_stats"]:
				print(" %s" % s)
		exit(0)
	
	new_species[mon]["pokedex_entry"][".description"] = "g{0}PokedexText".format(\
		"".join(i.capitalize() for i in mon.split("_")))
	
	who_index = family_order.index(insert_info[mon]["who"])
	if insert_info[mon]["where"] == "after":
		family_order.insert(who_index+1,mon)
	elif insert_info[mon]["where"] == "before":
		family_order.insert(who_index,mon)
	
print("\nimplementing {0} new mons".format(len(new_species)))	

########## stats and data of existing mons

base_stats = {mon:{} for mon in family_order}
move_data = {mon:{"level_up":[], "egg_move":[], "tutor_move":[],\
	"tm_move":[]} for mon in family_order}

for file in pokemon_excels:

	workbook = xlrd.open_workbook(file)    
    # get the first worksheet
	for i in range(0,workbook.nsheets):
		worksheet = workbook.sheet_by_index(i)
		for n in range(0,worksheet.nrows):
			row = worksheet.row_values(n)
			row = [int(i) if isinstance(i,float) else i \
				for i in row]
			if row[0] == "NAME":
				mon = row[1]
			elif row[0] == "LEVEL_UP":
				move_data[mon]["level_up"].append([check_move(row[1]),check_level(row[2])])
			elif row[0] in ["EGG_MOVE","TUTOR_MOVE"]:
				move_data[mon][row[0].lower()].append(check_move(row[1]))
			elif row[0] == "TM_MOVE":
				move_data[mon][row[0].lower()].append(check_tmmove(row[1]))
			else:
				if row[0] == ".noFlip":
					base_stats[mon][".noFlip"] = 0
				else:
					base_stats[mon][row[0]] = row[1]
	
########## add data of new species to base stats dict

for mon in new_species:
	for stat in required_stats:
		base_stats[mon][stat] = new_species[mon]["base_stats"][stat]
	for move in new_species[mon]["level_up_moves"]:
		move_data[mon]["level_up"].append([move[1],move[0]])
	move_data[mon]["egg_move"] = new_species[mon]["egg_moves"]
	move_data[mon]["tutor_move"] = new_species[mon]["tutor_moves"]
	move_data[mon]["tm_move"] = new_species[mon]["tmhm_moves"]

	
caps2joined, joined2caps = generate_capsjoined(family_order)	
	
########## define species

national_dex_start = "#define NATIONAL_DEX_NONE"
national_dex_end = "#define NATIONAL_DEX_COUNT"

species_file = normalize_path("{0}/include/constants/species.h".format(raw_folder))
print("\ncreate %s" % species_file)
with open(species_file, "w") as f:
		f.write("< //\n")
		f.write("#ifndef GUARD_CONSTANTS_SPECIES_H\n")
		f.write("#define GUARD_CONSTANTS_SPECIES_H\n")
		f.write("\n")
		f.write("#define SPECIES_NONE 0\n")
		iter_round = 1
		for mon in family_order:
			f.write("#define SPECIES_{0} {1}\n".format(mon,iter_round))
			iter_round += 1
		f.write("#define SPECIES_EGG {0}\n".format(iter_round))
		f.write("#define NUM_SPECIES SPECIES_EGG\n")
		f.write("\n")
		
		# unown forms
		f.write("// Unown forms, not actual species\n")
		iter_round = 1

		for u in unowns:
			f.write("#define SPECIES_UNOWN_{0} NUM_SPECIES + {1}\n".format(u,iter_round))
			iter_round += 1
			
		f.write("\n")
		f.write("// National Dex Index Defines\n")
		f.write("\n")
			
		# national dex defines
		f.write("#define SPECIES_NONE 0\n")
		iter_round = 1
		for mon in family_order:
			f.write("#define NATIONAL_DEX_{0} {1}\n".format(mon,iter_round))
			iter_round += 1
			if mon == "MEW":
				f.write("\n#define KANTO_DEX_COUNT NATIONAL_DEX_MEW\n\n")
			elif mon == "CELEBI":
				f.write("\n#define JOHTO_DEX_COUNT NATIONAL_DEX_CELEBI\n\n")
		f.write("\n#define NATIONAL_DEX_COUNT NATIONAL_DEX_{0}\n".format(\
					family_order[-1]))
		
		# hoenn dex defines
		f.write("\n")
		f.write("// Hoenn Dex Index Defines\n")
		iter_round = 1
		for mon in family_order:
			f.write("#define HOENN_DEX_{0} {1}\n".format(mon,iter_round))
			iter_round += 1
		f.write("\n#define HOENN_DEX_COUNT {0}\n".format(iter_round - 1))

		f.write("\n")
		f.write("#endif  // GUARD_CONSTANTS_SPECIES_H\n")
		f.write("\n")
		f.write("// > END")

########## species name

species_name_file = normalize_path("{0}/src/data/text/species_names.h".format(\
	raw_folder))
print("create %s" % species_name_file)
	
species_name_dict = {}
for mon in family_order:
	if mon not in ["MR_MIME","PORYGON_Z","NIDORAN_F","NIDORAN_M",\
		"HO_OH","MIMEJR"] and not "ALOLAN_" in mon and not "CLONE_" in mon \
		and not "GALARIAN_" in mon:
		species_name_dict[mon] = mon.capitalize()
	else:
		if "ALOLAN_" in mon:
			species_name_dict[mon] = mon.replace("ALOLAN_","").capitalize()
		elif "GALARIAN_" in mon:
			species_name_dict[mon] = mon.replace("GALARIAN_","").capitalize()
		elif "CLONE_" in mon:
			species_name_dict[mon] = mon.replace("CLONE_","").capitalize()
		else:
			if mon == "MR_MIME":
				species_name_dict[mon] = "Mr. Mime"
			elif mon == "MIMEJR":
				species_name_dict[mon] = "Mime jr."
			elif mon == "NIDORAN_F":
				species_name_dict[mon] = "Nidoran♀"
			elif mon == "NIDORAN_M":
				species_name_dict[mon] = "Nidoran♂"
			elif mon == "HO_OH":
				species_name_dict[mon] = "Ho-Oh"
			elif mon == "PORYGON_Z":
				species_name_dict[mon] = "Porygon-Z"
	
with open(species_name_file, "w", encoding="utf-8") as f:
	f.write("< //\n")
	f.write("const u8 gSpeciesNames[][POKEMON_NAME_LENGTH + 1] = {\n")
	f.write('    [SPECIES_NONE] = _("??????????"),\n')
	for mon in family_order:	
		f.write('    [SPECIES_{0}] = _("{1}"),\n'.format(mon,species_name_dict[mon]))
	f.write("};\n")
	f.write("// > END")
		
########## pokedex_entries.h		
		
pokemon_scales = {}
pokemon_scales[1] = 800
pokemon_scales[2] = 650
pokemon_scales[3] = 550
pokemon_scales[4] = 490		
pokemon_scales[5] = 440
pokemon_scales[6] = 390
pokemon_scales[7] = 340
pokemon_scales[8] = 320
pokemon_scales[9] = 300
pokemon_scales[10] = 290
pokemon_scales[11] = 280
pokemon_scales[12] = 270
pokemon_scales[13] = 260
		
pokedex_entries_file = normalize_path("{0}/src/data/pokemon/pokedex_entries.h".format(\
	raw_folder))

print("create %s" % pokedex_entries_file)
	
pokedex_entry_data = {}	
pokedex_entry_parameters = []	
	
# copy existing species from vanilla
with open(normalize_path("{0}/src/data/pokemon/pokedex_entries.h".format(\
		vanilla_dir)), "r") as f:
		species_on = 0
		for line in f:
			if "[NATIONAL_DEX" in line:
				species_name = line.lstrip().split("]")[0][1:].replace("NATIONAL_DEX_","")
				if species_name in family_order:
					species_on = 1
					pokedex_entry_data[species_name] = {}
			if "}," in line:
					species_on = 0

			if species_on:
				if not "{" in line and not "[" in line:
					line = line.rstrip("\n").lstrip().rstrip(",").split(" = ")
					if not line[0] in pokedex_entry_parameters:
						pokedex_entry_parameters.append(line[0])
					pokedex_entry_data[species_name][line[0]] = line[1].strip()

# use excel data for new species
for mon in new_species:
	pokedex_entry_data[mon] = new_species[mon]["pokedex_entry"]	
		
with open(pokedex_entries_file, "w") as f:
	f.write("< //\n")
	f.write("const struct PokedexEntry gPokedexEntries[] =\n")
	f.write("{\n")
	for mon in family_order:
		f.write("    [NATIONAL_DEX_{0}] = \n".format(mon))
		f.write("    {\n")
		if "ALOLAN_" in mon:
			lookup_mon = mon.replace("ALOLAN_","")
		else:
			lookup_mon = mon
		for p in pokedex_entry_parameters:

			# pokemon and trainer scale
			if p in [".pokemonScale",".trainerScale"] and \
				mon in new_species:
				mon_height = pokedex_entry_data[lookup_mon][".height"]
				if mon_height == 14:
					trainer_scale = 256
					pokemon_scale = 256
				elif mon_height > 14:
					pokemon_scale = 256
					trainer_scale = math.ceil(256 / (mon_height / 14))
				elif mon_height < 14:
					trainer_scale = 256
					pokemon_scale = pokemon_scales[mon_height]

				if p == ".pokemonScale":
					value = pokemon_scale
				elif p == ".trainerScale":
					value = trainer_scale
				f.write("        {0} = {1},\n".format(p,value))
			
			# everything else
			else:
				f.write("        {0} = {1},\n".format(p, \
					pokedex_entry_data[lookup_mon][p]))
				
		f.write("    },\n")
		f.write("\n")
	f.write("};\n")
	f.write("// > END")
		
########## pokedex_text.h

pokedex_text_file = normalize_path("{0}/src/data/pokemon/pokedex_text.h".format(raw_folder))

print("create %s" % pokedex_text_file)

textid_to_species = {}
for mon in pokedex_entry_data:
	textid_to_species[pokedex_entry_data[mon][".description"]] = mon

pokedex_text_data = {}
	
# copy existing species from vanilla
with open(normalize_path("{0}/src/data/pokemon/pokedex_text.h".format(\
		vanilla_dir)), "r", encoding="utf-8") as f:
		text_on = 0
		for line in f:
			if line.startswith("const u8"):
				text_id = line.split(" ")[2].replace("[]","")
				if text_id in textid_to_species:
					text_on = 1
					iter_round = 0
					pokedex_text_data[text_id] = [[],[],[],[]]
					
			if text_on and not "[]" in line:
					line = line.rstrip("\n").replace(");","").replace("\\n","")
					line = line.lstrip().strip('"')
					pokedex_text_data[text_id][iter_round] = line
					iter_round += 1
					if iter_round == 4:
						text_on = 0

# use excel data for new species
for mon in new_species:
	pokedex_text_data[pokedex_entry_data[mon][".description"]] = \
		new_species[mon]["pokedex_description"]
		
with open(pokedex_text_file, "w", encoding="utf-8") as f:
	f.write("< //\n")
	f.write("const u8 gDummyPokedexText[] = _(\n")
	f.write('    "This is a newly discovered POKéMON.\\n"\n')
	f.write('    "It is currently under investigation.\\n"\n')
	f.write('    "No detailed information is available\\n"\n')
	f.write('    "at this time.");\n')
	f.write("\n")
	for mon in family_order:
		if "ALOLAN_" in mon:
			continue
			
		text_id = pokedex_entry_data[mon][".description"]
		f.write("const u8 {0}[] = _(\n".format(text_id))		
		for line in pokedex_text_data[text_id][:-1]:
			f.write('    "{0}\\n"\n'.format(line))
		f.write('    "{0}");\n'.format(pokedex_text_data[text_id][-1]))
		f.write("\n")
		
	f.write("// > END")

########## pokedex orders

pokedex_orders_file = normalize_path("{0}/src/data/pokemon/pokedex_orders.h".format(\
	raw_folder))

print("create %s" % pokedex_orders_file)	

with open(pokedex_orders_file, "w") as f:
	f.write("< //\n")
	
	# alphabetical
	f.write("const u16 gPokedexOrder_Alphabetical[] =\n")
	f.write("{\n")
	tmp_dict = {}
	for mon in sorted(family_order, key=lambda x: species_name_dict[x]):
		f.write("    NATIONAL_DEX_{0},\n".format(mon))
	f.write("};\n")
	f.write("\n")
	
	# weight, height
	for p in ["weight", "height"]:
		tmp_dict = {}
		for mon in family_order:
			if "ALOLAN_" in mon:
				lookup_mon = mon.replace("ALOLAN_","")
			else:
				lookup_mon = mon
			tmp_dict[mon] = pokedex_entry_data[lookup_mon][".%s" % p]

		f.write("const u16 gPokedexOrder_{0}[] =\n".format(p.capitalize()))
		f.write("{\n")
		for mon in sorted(tmp_dict, key=lambda x:int(tmp_dict[x])):
			f.write("    NATIONAL_DEX_{0},\n".format(mon))
		f.write("};\n")
		f.write("\n")
	f.write("// > END")

########## pokemon.c

pokemon_file = normalize_path("{0}/src/pokemon.c".format(raw_folder))

print("modify %s" % pokemon_file)

with open(pokemon_file, "r") as f:
	pokemon_file_lines = f.readlines()
		
found_pokedex_array = 0
for line in pokemon_file_lines:
	if "const u16 gSpeciesToNationalPokedexNum" in line:
		found_pokedex_array = 1
		
if not found_pokedex_array:
	print("gSpeciesToNationalPokedexNum not present in raw pokemon.c, create it")

	new_lines = []
	new_lines.append("\n\n")
	new_lines.append("< //\n")
	new_lines.append("const u16 gSpeciesToNationalPokedexNum[NUM_SPECIES] = // Assigns all species to the National Dex Index (Summary No. for National Dex)\n")
	new_lines.append("{\n")
	for mon in family_order:
		new_lines.append("    SPECIES_TO_NATIONAL({0}),\n".format(mon))
	new_lines.append("};\n")
	new_lines.append("// >\n")
	
	pokemon_file_lines += new_lines
	with open(pokemon_file, "a") as f:
		for line in new_lines:
			f.write(line)
			
else:
	print("found gSpeciesToNationalPokedexNum in raw pokemon.c")
	
with open(pokemon_file, "r") as f:
	pokemon_file_lines = f.readlines()

for n,line in enumerate(pokemon_file_lines):
	if "const u16 gSpeciesToNationalPokedexNum" in line:
		start_index = n+2
	elif "};" in line and n > start_index:
		stop_index = n-1
		break

new_pokemon_lines = []
for mon in family_order:
	new_pokemon_lines.append("    SPECIES_TO_NATIONAL({0}),\n".format(mon))

pokemon_file_lines[start_index:stop_index+1] = new_pokemon_lines

write_lines(pokemon_file, pokemon_file_lines)

########## base_stats.h

base_stats_file = normalize_path("{0}/src/data/pokemon/base_stats.h".format(\
	raw_folder))
	
print("create %s" % base_stats_file)	
	
with open(base_stats_file, "w") as f:
	f.write("< // START\n")
	f.write("// Maximum value for a female Pokémon is 254 (MON_FEMALE) which is 100% female.\n")
	f.write("// 255 (MON_GENDERLESS) is reserved for genderless Pokémon.\n")
	f.write("#define PERCENT_FEMALE(percent) min(254, ((percent * 255) / 100))\n")
	f.write("\n")
	f.write("const struct BaseStats gBaseStats[] =\n")
	f.write("{\n")
	f.write("    [SPECIES_NONE] = {0},\n")
	f.write("\n")
	for mon in family_order:
		f.write("    [SPECIES_{0}] = \n".format(mon))
		f.write("    {\n")
		for stat in required_stats:
			f.write("        {0} = {1},\n".format(stat,base_stats[mon][stat]))
		f.write("    },\n")
		f.write("\n")
	f.write("\n")
	f.write("};\n")
	f.write("// > END")
	
########## level-up moves

# learnsets
levelup_file = normalize_path("{0}/src/data/pokemon/level_up_learnsets.h".format(\
	raw_folder))

print("create %s" % levelup_file)
	
with open(levelup_file, "w") as f:
	f.write("< //\n")
	f.write("#define LEVEL_UP_MOVE(lvl, moveLearned) {.move = moveLearned, .level = lvl}\n")
	f.write("#define LEVEL_UP_END (0xffff)\n")
	f.write("\n")
	for mon in family_order:
		f.write("static const struct LevelUpMove s{0}LevelUpLearnset[] = {{\n".format(
			caps2joined[mon]))
		for move in move_data[mon]["level_up"]:
			f.write("    LEVEL_UP_MOVE({0}, {1}),\n".format(move[1],move[0]))
		f.write("    LEVEL_UP_END\n")
		f.write("};\n")
		f.write("\n")
	f.write("// > END")

# learnset pointers
learnset_pointer_file = normalize_path("{0}/src/data/pokemon/level_up_learnset_pointers.h".\
	format(raw_folder))
	
with open(learnset_pointer_file, "w") as f:
	f.write("< //\n")
	f.write("const struct LevelUpMove *const gLevelUpLearnsets[NUM_SPECIES] =\n")
	f.write("{\n")
	f.write("    [SPECIES_NONE] = sBulbasaurLevelUpLearnset,\n")
	for mon in family_order:
		f.write("    [SPECIES_{0}] = s{1}LevelUpLearnset,\n".format(\
			mon,caps2joined[mon]))
	f.write("};\n")
	f.write("// > END")

########## TM/HM moves

tm_file = normalize_path("{0}/src/data/pokemon/tmhm_learnsets.h".format(raw_folder))

with open(tm_file, "w") as f:
	f.write("< //\n")
	f.write("#define TMHM_LEARNSET(moves) {(u32)(moves), ((u64)(moves) >> 32)}\n")
	f.write("#define TMHM(tmhm) ((u64)1 << (ITEM_##tmhm - ITEM_TM01_FOCUS_PUNCH))\n")
	f.write("\n")
	f.write("// This table determines which TMs and HMs a species is capable of learning.\n")
	f.write("// Each entry is a 64-bit bit array spread across two 32-bit values, with\n")
	f.write("// each bit corresponding to a .\n")
	f.write("const u32 gTMHMLearnsets[][2] =\n")
	f.write("{\n")
	f.write("    [SPECIES_NONE]    = TMHM_LEARNSET(0),\n")
	f.write("\n")
	for mon in family_order:
		f.write("    [SPECIES_{0}] = TMHM_LEARNSET".format(mon))
		moves = sorted(move_data[mon]["tm_move"])
		if len(moves) > 0:
			f.write("(TMHM({0})\n".format(moves[0]))
			for move in moves[1:-1]:
				f.write("\t"*11 + "| TMHM({0})\n".format(move))
			f.write("\t"*11 + "| TMHM({0})),\n".format(moves[-1]))
		else:
			f.write("(0),\n")
		f.write("\n")
	f.write("};\n")
	f.write("// > END")

########## tutor moves

tutor_file = normalize_path("{0}/src/data/pokemon/tutor_learnsets.h".format(raw_folder))

tutor_moves = ["Mega Punch", "Swords Dance", "Mega Kick", "Body Slam",\
	"Double Edge", "Counter", "Seismic Toss", "Mimic", "Metronome",\
	"Soft Boiled", "Dream Eater", "Thunder Wave", "Explosion",\
	"Rock Slide", "Substitute", "Dynamic Punch", "Rollout", "Psych Up",\
	"Snore", "Icy Wind", "Endure", "Mud Slap","Ice Punch", "Swagger",\
	"Sleep Talk", "Swift", "Defense Curl", "Thunder Punch", "Fire Punch",\
	"Fury Cutter"]
	
tutor_moves = [check_move(m) for m in tutor_moves]

print("create %s" % tutor_file)

with open(tutor_file, "w") as f:
	f.write("< //\n")
	f.write("const u16 gTutorMoves[] =\n")
	f.write("{\n")
	for move in tutor_moves:
		f.write("    [TUTOR_{0}] = {0},\n".format(move))
	f.write("};\n")
	f.write("\n")
	f.write("#define TUTOR_LEARNSET(moves) ((u32)(moves))\n")
	f.write("#define TUTOR(move) ((u64)1 << (TUTOR_##move))\n")
	f.write("\n")
	f.write("static const u32 sTutorLearnsets[] =\n")
	f.write("{\n")
	f.write("    [SPECIES_NONE]       = TUTOR_LEARNSET(0),\n")
	f.write("\n")
	for mon in family_order:
		f.write("    [SPECIES_{0}] = TUTOR_LEARNSET".format(mon))
		moves = move_data[mon]["tutor_move"]
		if len(moves) == 0:
			f.write("(0),\n")
		elif len(moves) == 1:
			f.write("(TUTOR({0})),\n".format(moves[0]))
		else:
			f.write("(TUTOR({0})\n".format(moves[0]))
			for move in moves[1:-1]:
				f.write("\t"*11 + "|TUTOR({0})\n".format(move))
			f.write("\t"*11 + "|TUTOR({0})),\n".format(moves[-1]))
		f.write("\n")
	f.write("};\n")
	f.write("// > END")

########## egg moves

egg_move_file = normalize_path("{0}/src/data/pokemon/egg_moves.h".format(raw_folder))

print("create %s" % egg_move_file)

with open(egg_move_file, "w") as f:
	f.write("< //\n")
	f.write("#define EGG_MOVES_SPECIES_OFFSET 20000\n")
	f.write("#define EGG_MOVES_TERMINATOR 0xFFFF\n")
	f.write("#define egg_moves(species, moves...) (SPECIES_##species + EGG_MOVES_SPECIES_OFFSET), moves\n")
	f.write("\n")
	f.write("const u16 gEggMoves[] = {\n")
	for mon in family_order:
		moves = move_data[mon]["egg_move"]
		if len(moves) > 0:
			f.write("    egg_moves({0},\n".format(mon))
			for move in moves[:-1]:
				f.write("        {0},\n".format(move))
			f.write("        {0}),\n".format(moves[-1]))
			f.write("\n")
	f.write("    EGG_MOVES_TERMINATOR\n")
	f.write("};\n")
	f.write("// > END")

########## evolution

evolution_file = normalize_path("{0}/src/data/pokemon/evolution.h".format(raw_folder))

evo_pattern = r'(EVO_.+),[ \t]+(.+),[ \t]+(.+)}{1,2}'
evo_data = {}

with open(normalize_path("{0}/src/data/pokemon/evolution.h".format(\
	vanilla_dir)), "r") as f:
	for line in f:
		line = line.replace("\t"," ")
		if "[SPECIES" in line:
			species_name = line.split("]")[0].split("[")[1].replace("SPECIES_","")
		if species_name in family_order:
			re_match = re.search(evo_pattern, line)
			if re_match:
				evo_method = re_match.group(1).strip()
				evo_parameter = re_match.group(2).strip()
				evo_target = re_match.group(3).replace("}","").strip()
				if evo_method != "EVO_MEGA_EVOLUTION":
					if species_name not in evo_data:
						evo_data[species_name] = []
					evo_data[species_name].append([evo_method,evo_parameter,evo_target])
					
for mon in new_species:
	if "evolution" in new_species[mon]:
		tmp_data = new_species[mon]["evolution"]
		if mon not in evo_data:
			evo_data[mon] = []
		evo_data[mon].append([tmp_data["method"],\
			tmp_data["parameter"],tmp_data["target"]])
			
with open(evolution_file, "w") as f:
	f.write("< //\n")
	f.write("const struct Evolution gEvolutionTable[NUM_SPECIES][EVOS_PER_MON] =\n")
	f.write("{\n")
	for mon in family_order:
		if mon in evo_data:
			f.write("    [SPECIES_{0}] = ".format(mon))
			if len(evo_data[mon]) == 1:
				f.write("{{%s,%s,%s}},\n" % (evo_data[mon][0][0],\
					evo_data[mon][0][1],evo_data[mon][0][2]))
			else:
				f.write("{{%s,%s,%s},\n" % (evo_data[mon][0][0],\
					evo_data[mon][0][1],evo_data[mon][0][2]))
				for e in evo_data[mon][1:-1]:
					f.write(" "*28 + "{%s,%s,%s},\n" % (e[0],e[1],e[2]))
				f.write(" "*28 + "{%s,%s,%s}},\n" % (evo_data[mon][-1][0],\
					evo_data[mon][-1][1],evo_data[mon][-1][2]))
	f.write("};\n")
	f.write("// > END")

########## sprites

sprite_files = ["front.png","anim_front.png","back.png",\
	"footprint.png","normal.pal","shiny.pal","icon.png"]

# copy all new sprites (incl. alolan anim and footprint)

sprite_folders = normalize_path("sprites/")

sprite_mons = [i for i in os.listdir(sprite_folders) \
	if os.path.isdir("{0}/{1}".format(sprite_folders,i))]

for mon in sprite_mons:

	# check that sprites exist
	sprite_folder = normalize_path("sprites/{0}".format(mon.lower()))
	if not os.path.isdir(sprite_folder):
		print("\nerror: did not find sprite folder for %s" % mon)
		exit(0)
	for file in sprite_files:
		if not os.path.isfile(normalize_path("{0}/{1}".format(\
			sprite_folder,file))):
			print("\nerror: did not find {0} for {1}".format(file,mon))
			exit(0)

	dest_folder = normalize_path("raw_maps/graphics/pokemon/{0}".format(mon.lower()))
	if not os.path.isdir(dest_folder):
		os.makedirs(dest_folder)
		
	for file in sprite_files:
		dest_file = normalize_path("{0}/{1}".format(dest_folder,file))
		shutil.copy(normalize_path("{0}/{1}".format(sprite_folder,file)),\
			dest_file)
				
########## graphics.h

graphics_file = normalize_path("{0}/include/graphics.h".format(raw_folder))
print("modify %s" % graphics_file)

pokemon_graphics_file = normalize_path("{0}/src/data/graphics/pokemon.h".format(\
	raw_folder))
print("create %s" % pokemon_graphics_file)
	
with open(graphics_file, "r") as f:
	graphics_file_lines = f.readlines()
		
start_index = None
for n,line in enumerate(graphics_file_lines):
	if "extern const u32 gMonFrontPic_Bulbasaur[];" in line:
		start_index = n
		break
if not start_index:
	print("\nerror: did not find anchor for graphics list")
	exit(0)
		
new_graphics_lines = []
new_graphics_lines2 = []

unown_declarations_done = set([])

for mon in ["NONE"] + [mon for mon in family_order if mon != "UNOWN"] + \
	["UNOWN_{0}".format(u) for u in unowns]:
	for category in ["FrontPic","BackPic","Palette",\
		"ShinyPalette","Icon","Footprint"]:
			
			if mon == "NONE" and category in ["FrontPic","Icon","Footprint"]:
				continue
			
			
			if category in ["Icon","Footprint"]:
				g_type = "u8"
			else:
				g_type = "u32"
				
			if category == "FrontPic":
				sprite = "anim_front.4bpp"
			elif category == "BackPic":
				sprite = "back.4bpp"
			elif category == "Palette":
				sprite = "normal.gbapal"
			elif category == "ShinyPalette":
				sprite = "shiny.gbapal"
			elif category == "Footprint":
				sprite = "footprint.1bpp"
			elif category == "Icon":
				sprite = "icon.4bpp"
				
			if category in ["Footprint","Icon"]:
				suffix = ""
			else:
				suffix = ".lz"
				
			if not "UNOWN" in mon and mon != "NONE":
				folder = mon.lower()
			elif mon == "NONE":
				folder = "question_mark/circled"
			else:
			
				if category not in ["FrontPic","BackPic","Icon"]:
					folder = "unown"
				else:
					letter = mon.replace("UNOWN_","")
					if letter == "EMARK":
						letter = "exclamation_mark"
					elif letter == "QMARK":
						letter = "question_mark"
					else:
						letter = letter.lower()
					folder = "unown/{0}".format(letter)
			
			if "UNOWN" in mon and category in ["Footprint","Palette","ShinyPalette"]:
				if not category in unown_declarations_done:
					definition = "\nextern const {0} gMon{1}_Unown[];\n".format(\
						g_type,category)
					declaration = '\nconst {0} gMon{1}_Unown[] = INCBIN_{2}("graphics/pokemon/unown/{3}{4}");\n'.format(\
						g_type,category,g_type.upper(),sprite,suffix)
					unown_declarations_done.add(category)
				else:
					definition = ""
					declaration = ""
			else:
				
				definition = "extern const {0} gMon{1}_{2}[];\n".format(\
					g_type,category,caps2joined[mon])
								
				declaration = '{0} = INCBIN_{1}("graphics/pokemon/{2}/{3}{4}");\n'.format(\
					definition.replace(";\n","").replace("extern ",""),g_type.upper(),\
						folder,sprite,suffix)
			
			new_graphics_lines.append(definition)
			new_graphics_lines2.append(declaration)
	new_graphics_lines.append("\n")
	new_graphics_lines2.append("\n")

graphics_file_lines[start_index:start_index+1] = new_graphics_lines

species_none = "const u32 gMonFrontPic_CircledQuestionMark[] = "
species_none += 'INCBIN_U32("graphics/pokemon/question_mark/circled/anim_front.4bpp.lz");\n'

new_graphics_lines2.insert(0,species_none)
new_graphics_lines2.insert(0,"< //\n")
new_graphics_lines2.append("// > END")

write_lines(graphics_file, graphics_file_lines)
write_lines(pokemon_graphics_file, new_graphics_lines2)

########## front_pic_anims.h

anims_file = normalize_path("{0}/src/data/pokemon_graphics/front_pic_anims.h".format(\
	raw_folder))
	
print("create %s" % anims_file)

species_pattern = r'(sAnim_(.+)_.+?)\['
species_pattern2 = r'sAnims_(.+)\['

anim_data = {}

# get existing animations
with open(normalize_path("{0}/src/data/pokemon_graphics/front_pic_anims.h".format(\
	vanilla_dir)), "r") as f:
	species_on = 0
	for line in f:
		if line.startswith("static const union AnimCmd sAnim_"):
			re_match = re.search(species_pattern,line)
			anim_name = re_match.group(1)
			species_name = re_match.group(2)
			if species_name in family_order or "UNOWN" in species_name:
				if species_name not in anim_data:
					anim_data[species_name]= {"AnimCmd":{}, "sAnims":[]}
				species_on = 1
				tmp = []
		
		if species_on and "ANIMCMD_END" in line:
			anim_data[species_name]["AnimCmd"][anim_name] = tmp
			tmp = []
			species_on = 0
		
		if species_on and not "[" in line and not "{" in line:
			tmp.append(line.rstrip("\n").rstrip(",").lstrip())
		
	f.seek(0)
	for line in f:
		if line.startswith("static const union AnimCmd *const sAnims_"):
			re_match = re.search(species_pattern2,line)
			species_name = re_match.group(1)
			if species_name in family_order or "UNOWN" in species_name:
				species_on = 1
				
		if "};" in line:
			species_on = 0
				
		if species_on and not "[" in line:
			# fix for Spinda
			if species_name not in anim_data:
				anim_data[species_name] = {"AnimCmd":{}, "sAnims":[]}				
			anim_data[species_name]["sAnims"].append(line.lstrip().rstrip("\n").rstrip(","))

for mon in new_species:

		anim_name = "sAnim_{0}_1".format(mon)

		tmp = []
		tmp.append("ANIMCMD_FRAME(0, 20)")
		tmp.append("ANIMCMD_FRAME(1, 20)")
		tmp.append("ANIMCMD_FRAME(0, 20)")
		tmp.append("ANIMCMD_FRAME(1, 20)")
		anim_data[mon] = {"AnimCmd": {}}
		anim_data[mon]["AnimCmd"][anim_name] = tmp

		anim_data[mon]["sAnims"] = ["sAnim_GeneralFrame0",anim_name]

		
with open(anims_file, "w") as f:
	f.write("< // START\n")
	f.write("static const union AnimCmd sAnim_NONE_1[] =\n")
	f.write("{\n")
	f.write("    ANIMCMD_FRAME(0, 30),\n")
	f.write("    ANIMCMD_FRAME(1, 30),\n")
	f.write("    ANIMCMD_FRAME(0, 1),\n")
	f.write("    ANIMCMD_FRAME(1, 30),\n")
	f.write("    ANIMCMD_END,\n")
	f.write("};\n")
	f.write("\n")
	f.write("static const union AnimCmd *const sAnims_NONE[] ={\n")
	f.write("    sAnim_GeneralFrame0,\n")
	f.write("    sAnim_NONE_1,\n")
	f.write("};\n")
	f.write("\n")
	
	for mon in family_order:
		for anim in sorted(anim_data[mon]["AnimCmd"]):
			f.write("static const union AnimCmd {0}[] =\n".format(anim))
			f.write("{\n")
			for line in anim_data[mon]["AnimCmd"][anim]:
				f.write("    {0},\n".format(line))
			f.write("    ANIMCMD_END,\n")
			f.write("};\n")

		f.write("static const union AnimCmd *const sAnims_{0}[] =\n".format(mon))
		f.write("{\n")
		for line in anim_data[mon]["sAnims"]:
			f.write("    {0},\n".format(line))
		f.write("};\n")
		f.write("\n")
	
	f.write("#define ANIM_CMD(name)             [SPECIES_##name] = sAnims_##name\n")
	f.write("#define ANIM_CMD_FULL(name, anims) [SPECIES_##name] = anims\n")
	f.write("\n")
	f.write("const union AnimCmd *const *const gMonFrontAnimsPtrTable[] =\n")
	f.write("{\n")
	f.write("    ANIM_CMD(NONE),\n")
	for mon in family_order:
		f.write("    ANIM_CMD({0}),\n".format(mon))
	f.write("};\n")
	
	f.write("\n")
	f.write("#undef ANIM_CMD\n")
	f.write("#undef ANIM_CMD_FULL\n")

	f.write("// > END")
	
########## pokemon_animation.c

pokemon_animation_file = normalize_path("{0}/src/pokemon_animation.c".format(\
	raw_folder))

print("create %s" % pokemon_animation_file)	
	
anim_pattern = r'\[SPECIES_(.+)\] = (.+),'	
anim_data = {}
	
with open(normalize_path("{0}/src/pokemon_animation.c".format(\
	vanilla_dir)),"r") as f:
	species_on = 0
	for line in f:
		if "static const u8 sSpeciesToBackAnimSet" in line:
			species_on = 1
			
		if "}" in line:
			species_on = 0
			
		if species_on and not "static" in line and not "{" in line:
			re_match = re.search(anim_pattern,line)
			species_name = re_match.group(1)
			anim = re_match.group(2)
			anim_data[species_name] = anim

for mon in new_species:
	anim_data[mon] = "BACK_ANIM_VERTICAL_SHAKE"

for mon in family_order:
	if mon not in anim_data:
		anim_data[mon] = "BACK_ANIM_VERTICAL_SHAKE"
			
with open(pokemon_animation_file, "w") as f:
	f.write("< //\n")
	f.write("static const u8 sSpeciesToBackAnimSet[NUM_SPECIES] =\n")
	f.write("{\n")
	for mon in family_order:
		f.write("    [SPECIES_{0}] = {1},\n".format(mon,anim_data[mon]))
	f.write("};\n")
	f.write("\n")
	f.write("static const u8 sUnknown_0860AA64[][2] =\n")
	f.write("// >")

########## graphics tables

for t in ["front_pic_table.h", "back_pic_table.h",\
		"palette_table.h","shiny_palette_table.h"]:

	file = normalize_path("{0}/src/data/pokemon_graphics/{1}".format(\
		raw_folder,t))

	print("create %s" % file)
		
	with open(file, "w") as f:
		
		if t == "front_pic_table.h":
			category = "FrontPic"
			sprite_type = "SPRITE"
			struct_type = "Sheet"
		elif t == "back_pic_table.h":
			category = "BackPic"
			sprite_type = "SPRITE"
			struct_type = "Sheet"
		elif t == "palette_table.h":
			category = "Palette"
			sprite_type = "PAL"
			struct_type = "Palette"
		elif t == "shiny_palette_table.h":
			category = "ShinyPalette"
			sprite_type = "PAL"
			struct_type = "Palette"

		f.write("< // START\n")
		f.write("const struct CompressedSprite{0} gMon{1}Table[] =\n".format(\
			struct_type,category))
		f.write("{\n")
		f.write("    SPECIES_{0}(NONE, gMon{1}_CircledQuestionMark),\n".format(\
			sprite_type,category))
		for mon in family_order:
			if not "UNOWN" in mon:
				f.write("    SPECIES_{0}({1}, gMon{2}_{3}),\n".format(\
					sprite_type,mon,category,caps2joined[mon]))
		f.write("\n")
		for u in unowns:
			if u == "EMARK":
				letter = "ExclamationMark"
			elif u == "QMARK":
				letter = "QuestionMark"
			else:
				letter = u
				
			if category in ["Palette","ShinyPalette"]:
				letter = ""
				
			f.write("    SPECIES_{0}(UNOWN_{1}, gMon{2}_Unown{3}),\n".\
				format(sprite_type,u,category,letter))
		f.write("};\n")
		f.write("\n")
		f.write("// > END")

footprint_table_file = normalize_path("{0}/src/data/pokemon_graphics/footprint_table.h".\
	format(raw_folder,t))

print("create %s" % footprint_table_file)

with open(footprint_table_file, "w") as f:
	f.write("< //\n")
	f.write("const u8 *const gMonFootprintTable[] =\n")
	f.write("{\n")
	f.write("    [SPECIES_NONE] = gMonFootprint_Bulbasaur,\n")
	for mon in family_order:
		f.write("    [SPECIES_{0}] = gMonFootprint_{1},\n".format(\
			mon,caps2joined[mon]))
	f.write("    [SPECIES_EGG] = gMonFootprint_Bulbasaur,\n")
	f.write("};\n")
	f.write("// > END")
	
########## coordinate tables

for category in ["front","back"]:

	file = normalize_path("{0}/src/data/pokemon_graphics/{1}_pic_coordinates.h".format(\
		raw_folder,category))	
		
	print("create %s" % file)	
		
	coordinate_data = {}	
		
	with open("{0}/src/data/pokemon_graphics/{1}_pic_coordinates.h".\
		format(vanilla_dir,category), "r") as f:
		species_on = 0
		for line in f:
			if "SPECIES" in line and not "NONE" in line:
				species_name = line.split("]")[0].split("[")[1].replace(\
					"SPECIES_","")
				if species_name in family_order or species_name == "EGG" \
					or "UNOWN" in species_name:
					coordinate_data[species_name] = {}
					species_on = 1
					
			if "}" in line:
				species_on = 0
			
			if species_on and not "[" in line and not "{" in line:
				line = line.split()
				coordinate_data[species_name][line[0]] = line[2].replace(",","")

	for mon in new_species:
		coordinate_data[mon] = {".size":"0x7", ".y_offset":"0x7"}
	
	with open(file, "w") as f:
		f.write("< // START\n")
		f.write("const struct MonCoords gMon{0}PicCoords[] =\n".format(\
			category.capitalize()))
		f.write("{\n")
		f.write("    [SPECIES_NONE] =\n")
		f.write("    {\n")
		f.write("        .size = 0x88,\n")
		f.write("        .y_offset = 0x0,\n")
		f.write("    },\n")
		
		for mon in family_order:
			if mon != "UNOWN":
				f.write("    [SPECIES_{0}] =\n".format(mon))
				f.write("    {\n")
				f.write("        .size = {0},\n".format(\
					coordinate_data[mon][".size"]))
				f.write("        .y_offset = {0},\n".format(\
					coordinate_data[mon][".y_offset"]))
				f.write("    },\n")
		
		f.write("    [SPECIES_EGG] = \n")
		f.write("    {\n")
		f.write("        .size = {0},\n".format(coordinate_data["EGG"][".size"]))
		f.write("        .y_offset = {0},\n".format(coordinate_data["EGG"][".y_offset"]))
		f.write("    },\n")
		
		for u in unowns:
			f.write("    [SPECIES_UNOWN_{0}] =\n".format(u))
			f.write("    {\n")
			f.write("        .size = {0},\n".format(\
				coordinate_data["UNOWN_{0}".format(u)][".size"]))
			f.write("        .y_offset = {0},\n".format(\
				coordinate_data["UNOWN_{0}".format(u)][".y_offset"]))
			f.write("    },\n")
			
		f.write("};\n")
		f.write("// > END")	
	
########## pokemon_icon.c

pokemon_icon_file = normalize_path("{0}/src/pokemon_icon.c".format(raw_folder))

print("create %s" % pokemon_icon_file)
palette_indices = {}
	
# existing palettes
with open(normalize_path("{0}/src/pokemon_icon.c".format(\
	vanilla_dir)), "r") as f:
	species_on = 0
	for line in f:
		if "const u8 gMonIconPaletteIndices" in line:
			species_on = 1
			
		if "};" in line:
			species_on = 0
			
		if species_on and not "const" in line and not "{" in line:
			species_name = line.split("]")[0].split("[")[1].replace(\
				"SPECIES_","")
			if species_name in family_order:
				tmp_index = line.split()[2].replace("\n","").replace(",","")
				palette_indices[species_name] = tmp_index

# palettes				
palette_folder = normalize_path("{0}/graphics/pokemon/icon_palettes".format(\
	vanilla_dir))
palette_files = [i for i in os.listdir(palette_folder) \
	if i.endswith(".pal")]

palettes = {}
for file in palette_files:
	num = file.split(".")[0][-1]
	with open("{0}/{1}".format(palette_folder,file), "r") as f:
		f.readline()
		f.readline()
		f.readline()
		colors = set([])
		for line in f:
			line = line.rstrip("\n").rstrip("\r").replace(" ",", ")
			colors.add(line)
		palettes[num] = colors
		
# determine icon palette index automatically		
for mon in new_species:
	icon_file = "sprites/{0}/icon.png".format(mon.lower())
	im = Image.open(icon_file).convert("RGB")
	pix = im.load()
	width,height = im.size
	icon_colors = set([])
	for x in range(0,width):
		for y in range(0,height):
			rgb = str(pix[x,y]).replace("(","").replace(")","")
			icon_colors.add(rgb)
	
	for num in palettes:
		if icon_colors.issubset(palettes[num]):
			correct_palette = num
			break
	
	palette_indices[mon] = str(num)
	

with open(pokemon_icon_file, "w") as f:
	f.write("< //\n")
	f.write("const u8 *const gMonIconTable[] =\n")
	f.write("{\n")
	f.write("    [SPECIES_NONE] = gMonIcon_Bulbasaur,\n")
	for mon in family_order:
		if "UNOWN" not in mon:
			f.write("    [SPECIES_{0}] = gMonIcon_{1},\n".format(\
				mon,caps2joined[mon]))
	for u in unowns:
		if u == "EMARK":
			letter = "ExclamationMark"
		elif u == "QMARK":
			letter = "QuestionMark"
		else:
			letter = u
		f.write("    [SPECIES_UNOWN_{0}] = gMonIcon_Unown{1},\n".format(\
			u,letter))
	f.write("};\n")
	f.write("\n")
	
	f.write("const u8 gMonIconPaletteIndices[] =\n")
	f.write("{\n")
	for mon in family_order:
		f.write("    [SPECIES_{0}] = {1},\n".format(mon,palette_indices[mon]))
	f.write("    [SPECIES_UNOWN_A ... SPECIES_UNOWN_QMARK] = 0,\n")
	f.write("    [SPECIES_EGG] = 1,\n")
	f.write("};\n")
	f.write("\n")
	
	f.write("const struct SpritePalette gMonIconPaletteTable[] =\n")
	f.write("// >")
	
########## cry

if not os.path.isdir("{0}/sound".format(raw_folder)):
	os.makedir("{0}/sound".format(raw_folder))

# check that cries exist and copy them
# copy all cries, not just new ones
for file in os.listdir("sound"):

	dest_file = normalize_path("raw_maps/sound/direct_sound_samples/{0}".\
		format(file))
	file = normalize_path("sound/{0}".format(file))
	
		
	shutil.copy(file,dest_file)
	
cry_data = {}	
	
for mon in family_order:
		vanilla_cry = normalize_path("{0}/sound/direct_sound_samples/cry_{1}.aif".\
			format(vanilla_dir,mon.lower()))
		mod_cry = normalize_path("raw_maps/sound/direct_sound_samples/cry_{0}.aif".\
			format(mon.lower()))
		if os.path.isfile(vanilla_cry) or os.path.isfile(mod_cry):
			cry_data[mon] = "cry"
		else:
			cry_data[mon] = "cry_not"
	
# order is important!
cry_table_file = normalize_path("{0}/sound/cry_tables.inc".format(raw_folder))
with open(cry_table_file, "w") as f:
	f.write("< // START\n")
	f.write("\n")
	f.write("    .align 2\n")
	f.write("gCryTable:: @ 869DCF4\n")
	for mon in family_order:
		f.write("    {0} Cry_{1}\n".format(cry_data[mon],caps2joined[mon]))
	f.write("\n")

	f.write("    .align 2\n")
	f.write("gCryTable2:: @ 869EF24\n")
	for mon in family_order:
		f.write("    {0} Cry_{1}\n".format(cry_data[mon].replace("cry","cry2"),\
			caps2joined[mon]))
			
	f.write("// > END")
	
direct_sound_file = normalize_path("{0}/sound/direct_sound_data.inc".format(raw_folder))
with open(direct_sound_file, "w") as f:
	f.write("< //\n")
	f.write("DirectSoundWaveData_8745A7C::\n")
	f.write('	.incbin "sound/direct_sound_samples/8745A7C.bin"\n')
	f.write("\n")
	
	for mon in family_order:
		f.write("    .align 2\n")
		f.write("Cry_{0}::\n".format(caps2joined[mon]))
		if mon != "PORYGON_Z":
			mon_name = mon.lower()
		else:
			mon_name = "porygonZ"
		f.write('    .incbin "sound/direct_sound_samples/{0}_{1}.bin"\n'.format(\
			cry_data[mon],mon_name))
		f.write("\n")
	
	f.write("    .align 2\n")
	f.write("DirectSoundWaveData_register_noise::\n")
	f.write("// >\n")