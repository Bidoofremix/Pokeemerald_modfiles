#!/usr/bin/python3
#-*- encoding: utf-8 -*-

import os,xlrd,shutil,math
from config import vanilla_dir,slash
from misc import *
from pokemon_tools import *

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
				new_species[mon]["evolution"] = {"target":row[1], \
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
		for i in range(1,27):
			f.write("#define SPECIES_UNOWN_{0} {1}".format(chr(i+64),i))
		f.write("#define SPECIES_UNOWN_EMARK NUM_SPECIES + 27\n")
		f.write("#define SPECIES_UNOWN_QMARK NUM_SPECIES + 28\n")	
			
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
		"HO_OH","MIMEJR"] and not "ALOLAN_" in mon and not "CLONE_" in mon:
		species_name_dict[mon] = mon.capitalize()
	else:
		if "ALOLAN_" in mon:
			species_name_dict[mon] = mon.replace("ALOLAN_","").capitalize()
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

exit(0)

########## base_stats.h

base_stats_file = normalize_path("{0}/src/data/pokemon/base_stats.h".format(\
	raw_folder))
	
with open(base_stats_file, "r") as f:
	base_stats_file_lines = f.readlines()
		
new_base_stats_lines = []
for mon in new_species:
	if mon not in defined_new_mons:
		new_base_stats_lines.append("\n")
		new_base_stats_lines.append("    [SPECIES_{0}] =\n".format(mon))
		new_base_stats_lines.append("    {\n")
		for stat in required_stats:
			new_base_stats_lines.append("        {0} = {1},\n".format(\
				stat.ljust(15),new_species[mon]["base_stats"][stat]))
		new_base_stats_lines.append("    },\n")

base_stats_file_lines[-2:-2] = new_base_stats_lines
		
write_lines(base_stats_file, base_stats_file_lines)
	
########## level-up moves

levelup_file = normalize_path("{0}/src/data/pokemon/level_up_learnsets.h".format(\
	raw_folder))
	
with open(levelup_file, "r") as f:
	levelup_file_lines = f.readlines()

new_lines = []
for mon in new_species:
	if mon not in defined_new_mons:
		new_lines.append("\n")
		new_lines.append("static const struct LevelUpMove s{0}LevelUpLearnset[] = {{\n".\
			format(mon.capitalize()))
		moves = new_species[mon]["level_up_moves"]
		for move in sorted(moves, key = lambda x: x[0]):
			new_lines.append("        LEVEL_UP_MOVE({0}, {1}),\n".format(\
				str(str(move[0])).rjust(2),move[1]))
		new_lines.append("    LEVEL_UP_END\n")
		new_lines.append("};\n")
		
levelup_file_lines[-1:-1] = new_lines
	
write_lines(levelup_file, levelup_file_lines)

learnset_pointer_file = normalize_path("{0}/src/data/pokemon/level_up_learnset_pointers.h".\
	format(raw_folder))
	
with open(learnset_pointer_file, "r") as f:
	learnset_pointer_file_lines = f.readlines()
	
new_lines = []
for mon in new_species:
	if not mon in defined_new_mons:
		new_lines.append("    [SPECIES_{0}] = s{1}LevelUpLearnset,\n".format(\
			mon,mon.capitalize()))
		
learnset_pointer_file_lines[-2:-2] = new_lines

write_lines(learnset_pointer_file,learnset_pointer_file_lines)
	
########## TM/HM moves

tm_file = normalize_path("{0}/src/data/pokemon/tmhm_learnsets.h".format(raw_folder))

with open(tm_file, "r") as f:
	tm_file_lines = f.readlines()
	
new_lines = []
for mon in new_species:
	if not mon in defined_new_mons:
		moves = sorted(new_species[mon]["tmhm_moves"])
		new_lines.append("    [SPECIES_{0}] = TMHM_LEARNSET(TMHM({1})\n".format(\
			mon,moves[0]))
		for move in sorted(moves[1:]):
			new_lines.append("\t"*11 + "| TMHM({0})\n".format(move))
		new_lines[-1] = new_lines[-1].replace("\n","),\n")

tm_file_lines[-2:-2] = new_lines

write_lines(tm_file,tm_file_lines)

########## tutor moves

tutor_file = normalize_path("{0}/src/data/pokemon/tutor_learnsets.h".format(raw_folder))

with open(tutor_file, "r") as f:
	tutor_file_lines = f.readlines()

new_lines = []	
for mon in new_species:
	if mon not in defined_new_mons:
		moves = sorted(new_species[mon]["tutor_moves"])
		new_lines.append("    [SPECIES_{0}] = TUTOR_LEARNSET(TUTOR({1})\n".format(\
			mon,moves[0]))
		for move in moves[1:]:
			new_lines.append("\t"*11 + "| TUTOR({0})\n".format(move))
		new_lines[-1] = new_lines[-1].replace("\n","),\n")
		
tutor_file_lines[-2:-2] = new_lines

write_lines(tutor_file,tutor_file_lines)

########## egg moves

egg_move_file = normalize_path("{0}/src/data/pokemon/egg_moves.h".format(raw_folder))

with open(egg_move_file, "r") as f:
	egg_move_file_lines = f.readlines()
	
new_lines = []
for mon in new_species:
	if mon not in defined_new_mons:
		moves = sorted(new_species[mon]["egg_moves"])
		new_lines.append("egg_moves({0},\n".format(mon))
		for move in moves:
			new_lines.append("\t\t{0},\n".format(move))
		new_lines[-1] = new_lines[-1].replace(",\n","),\n\n")

egg_move_file_lines[-2:-2] = new_lines		
		
write_lines(egg_move_file,egg_move_file_lines)
		
########## evolution

evolution_file = normalize_path("{0}/src/data/pokemon/evolution.h".format(raw_folder))

with open(evolution_file, "r") as f:
	evolution_file_lines = f.readlines()
	
new_lines = []
for mon in new_species:
	if not mon in defined_new_mons:
		if "evolution" in new_species[mon]:
			tmp_text = "    [SPECIES_{0}] = {{{{".format(mon)
			tmp_text += "{0}, {1}, SPECIES_{2}".format(\
				new_species[mon]["evolution"]["method"],\
				new_species[mon]["evolution"]["parameter"],\
				new_species[mon]["evolution"]["target"])
			tmp_text += "}},\n"
			
			new_lines.append(tmp_text)
			
evolution_file_lines[-2:-2] = new_lines

write_lines(evolution_file,evolution_file_lines)

########## sprites

sprite_files = ["front.png","anim_front.png","back.png",\
	"footprint.png","normal.pal","shiny.pal","icon.png"]

for mon in new_species:

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

graphics_file_lines = []
with open(graphics_file, "r") as f:
	for line in f:
		graphics_file_lines.append(line)
		
new_graphics_lines = []
for mon in new_species:
	if not mon in defined_new_mons:
		for category in ["FrontPic","Palette","BackPic",\
			"ShinyPalette"]:
			new_graphics_lines.append("extern const u32 gMon{0}_{1}[];\n".format(\
				category,mon.capitalize()))
		for category in ["Icon","Footprint"]:
			new_graphics_lines.append("extern const u8 gMon{0}_{1}[];\n".format(\
				category,mon.capitalize()))
				
graphics_file_lines[-2:-2] = new_graphics_lines

write_lines(graphics_file, graphics_file_lines)	

########## graphics/pokemon.h

pokemon_graphics_file = normalize_path("{0}/src/data/graphics/pokemon.h".format(\
	raw_folder))
	
pokemon_graphics_file_lines = []
with open(pokemon_graphics_file, "r") as f:
	for line in f:
		pokemon_graphics_file_lines.append(line)
		
new_pokemon_graphics_lines = []
for mon in new_species:
	if mon not in defined_new_mons:
	
		tmp_text = "const u32 gMonFrontPic_{0}[] = ".format(mon.capitalize())
		tmp_text += 'INCBIN_U32("graphics/pokemon/{0}/anim_front.4bpp.lz");\n'.format(mon.lower())
		new_pokemon_graphics_lines.append(tmp_text)
	
		for category in ["BackPic"]:
			tmp_text = "const u32 gMon{0}_{1}[] = ".format(category,mon.capitalize())
			tmp_text += 'INCBIN_U32("graphics/pokemon/{0}/{1}.4bpp.lz");\n'.format(\
				mon.lower(),category.replace("Pic","").lower())
			new_pokemon_graphics_lines.append(tmp_text)
			
		for category in ["Palette","ShinyPalette"]:
			if category == "Palette":
				palette = "normal"
			elif category == "ShinyPalette":
				palette = "shiny"
			tmp_text = "const u32 gMon{0}_{1}[] = ".format(category,mon.capitalize())
			tmp_text += 'INCBIN_U32("graphics/pokemon/{0}/{1}.gbapal.lz");\n'.format(\
				mon.lower(),palette)
			new_pokemon_graphics_lines.append(tmp_text)
			
		for category in ["Icon","Footprint"]:
			if category == "Icon":
				format = "4bpp"
			elif category == "Footprint":
				format = "1bpp"
			tmp_text = "const u8 gMon{0}_{1}[] = ".format(category,mon.capitalize())
			tmp_text += 'INCBIN_U8("graphics/pokemon/{0}/{1}.{2}");\n'.format(\
				mon.lower(),category.lower(),format)
			new_pokemon_graphics_lines.append(tmp_text)
			
pokemon_graphics_file_lines[-2:-2] = new_pokemon_graphics_lines			

write_lines(pokemon_graphics_file,pokemon_graphics_file_lines)

########## front_pic_anims.h

anims_file = normalize_path("{0}/src/data/pokemon_graphics/front_pic_anims.h".format(\
	raw_folder))
	
anims_file_lines = []
with open(anims_file, "r") as f:
	for line in f:
		anims_file_lines.append(line)
		
# split to chunks
anims_chunk_indexes = {"sAnim": "", "sAnims":"","ANIM_CMD":""}
chunks = lines_to_chunks(anims_file_lines)
for n,c in enumerate(chunks):
	for line in c:
		if "AnimCmd sAnim" in line:
			anims_chunk_indexes["sAnim"] = n
		if "*const sAnims" in line:
			anims_chunk_indexes["sAnims"] = n
		if "ANIM_CMD" in line:
			anims_chunk_indexes["ANIM_CMD"] = n

for mon in new_species:
	if mon not in defined_new_mons:

		sanim_lines = []
		sanim_lines.append("\n")
		sanim_lines.append("static const union AnimCmd sAnim_{0}_1[] =\n".format(mon))
		sanim_lines.append("{\n")
		sanim_lines.append("    ANIMCMD_FRAME(1, 30),\n")
		sanim_lines.append("    ANIMCMD_FRAME(0, 20),\n")
		sanim_lines.append("    ANIMCMD_END,\n")
		sanim_lines.append("};\n")
		chunks[anims_chunk_indexes["sAnim"]][-1:-1] = sanim_lines

		sanims_lines = []
		sanims_lines.append("\n")
		sanims_lines.append("static const union AnimCmd *const sAnims_{0}[] = {{\n".format(mon))
		sanims_lines.append("    sAnim_GeneralFrame0,\n")
		sanims_lines.append("    sAnim_{0}_1,\n".format(mon))
		sanims_lines.append("};\n")
		chunks[anims_chunk_indexes["sAnims"]][-1:-1] = sanims_lines

		chunks[anims_chunk_indexes["ANIM_CMD"]].insert(-2,"    ANIM_CMD({0}),\n".format(mon))

anims_file_lines = []	
for c in chunks:
	for line in c:
		anims_file_lines.append(line)
		
write_lines(anims_file,anims_file_lines)

########## pokemon_animation.c

pokemon_animation_file = normalize_path("{0}/src/pokemon_animation.c".format(\
	raw_folder))

pokemon_animation_file_lines = []
with open(pokemon_animation_file, "r") as f:
	for line in f:
		pokemon_animation_file_lines.append(line)

for mon in new_species:
	if mon not in defined_new_mons:
		tmp_text = "    [SPECIES_{0}] = ".format(mon)
		tmp_text += "BACK_ANIM_VERTICAL_SHAKE,\n"
		pokemon_animation_file_lines.insert(-2, tmp_text)
		
write_lines(pokemon_animation_file,pokemon_animation_file_lines)

########## graphics tables

table_files = ["front_pic_table.h", "back_pic_table.h",\
	"footprint_table.h","palette_table.h","shiny_palette_table.h"]
	
for t in table_files:

	print("modify {0}".format(t))

	file = normalize_path("{0}/src/data/pokemon_graphics/{1}".format(\
		raw_folder,t))
	
	with open(file, "r") as f:
		file_lines = f.readlines()
		
	category = file.split(slash)[-1].replace("_table.h","").replace("_"," ").title().replace(" ","")
		
	for mon in new_species:
		if mon not in defined_new_mons:
				
			if t in ["front_pic_table.h","back_pic_table.h"]:
				tmp_text = "    SPECIES_SPRITE({0}, gMon{1}_{2}),\n".format(mon,category,mon.capitalize())
			elif t in ["palette_table.h","shiny_palette_table.h"]:
				if t == "shiny_palette_table.h":
					suffix = "SHINY_"
				else:
					suffix = ""
				tmp_text = "    SPECIES_{0}PAL({1}, gMon{2}_{3}),\n".format(\
					suffix,mon,category,mon.capitalize())
			elif t == "footprint_table.h":
				tmp_text = "    [SPECIES_{0}] = gMon{1}_{2},\n".format(mon,category,mon.capitalize())
						
			file_lines.insert(-2, tmp_text)
			
	write_lines(file,file_lines)		
	
########## coordinate tables

for category in ["front","back"]:

	print("modify {0}_pic_coordinates.h".format(category))

	file = normalize_path("{0}/src/data/pokemon_graphics/{1}_pic_coordinates.h".format(\
		raw_folder,category))
		
	with open(file, "r") as f:
		file_lines = f.readlines()
		
	for mon in new_species:
		if mon not in defined_new_mons:
			new_lines = []
			new_lines.append("\n")
			new_lines.append("    [SPECIES_{0}] = \n".format(mon))
			new_lines.append("    {\n")
			new_lines.append("        .size = 0x40,\n")
			new_lines.append("        .y_offset = 0x0,\n")
			new_lines.append("    },\n")
			
			file_lines[-2:-2] = new_lines
	
	write_lines(file,file_lines)
	
########## pokemon_icon.c

pokemon_icon_file = normalize_path("{0}/src/pokemon_icon.c".format(raw_folder))

with open(pokemon_icon_file, "r") as f:
	pokemon_icon_file_lines = f.readlines()
	
# icons
for n,line in enumerate(pokemon_icon_file_lines):
	if line.startswith("const u8 *const gMonIconTable"):
		insert_index = n
		break

new_lines = []
for mon in new_species:
	if mon not in defined_new_mons:
		new_lines.append("    [SPECIES_{0}] = gMonIcon_{1},\n".format(mon,mon.capitalize()))
		
pokemon_icon_file_lines[n+2:n+2] = new_lines

# icon indexes
for n,line in enumerate(pokemon_icon_file_lines):
	if line.startswith("const u8 gMonIconPaletteIndices"):
		insert_index = n
		break
		
new_lines = []
for mon in new_species:
	if mon not in defined_new_mons:
		new_lines.append("    [SPECIES_{0}] = 0,\n".format(mon))

pokemon_icon_file_lines[n+2:n+2] = new_lines
	
write_lines(pokemon_icon_file,pokemon_icon_file_lines)

########## cry

if not os.path.isdir("{0}/sound".format(raw_folder)):
	os.makedir("{0}/sound".format(raw_folder))

# check that cries exist and copy them
for mon in new_species:
	cry_file = normalize_path("sound/cry_not_{0}.aif".format(mon.lower()))
	if not os.path.isfile(cry_file):
		print("\nerror: did not find cry for %s" % mon)
		exit(0)
		
	dest_file = normalize_path("raw_maps/sound/direct_sound_samples/cry_not_{0}.aif".\
		format(mon.lower()))
	
	shutil.copy(cry_file,dest_file)
	
# order is important!
cry_table_file = normalize_path("{0}/sound/cry_tables.inc".format(raw_folder))
with open(cry_table_file, "w") as f:
	f.write("< //\n")
	f.write("\tcry_not Cry_Lycanroc_Dusk\n")
	for mon in new_mon_national_order:
		f.write("\tcry_not Cry_{0}\n".format(mon.capitalize()))
	f.write("\n")
	f.write(".align 2\n")
	f.write("gCryTable2:: @ 869EF24\n")
	f.write("// >\n")
	f.write("\n")
	
	f.write("< //\n")
	f.write("\tcry2_not Cry_Lycanroc_Dusk\n")
	for mon in new_mon_national_order:
		f.write("\tcry2_not Cry_{0}\n".format(mon.capitalize()))
	f.write("// > END\n")
	
direct_sound_file = normalize_path("{0}/sound/direct_sound_data.inc".format(raw_folder))
with open(direct_sound_file, "w") as f:
	f.write("< //\n")
	f.write("Cry_Lycanroc_Dusk::\n")
	f.write('\t.incbin "sound/direct_sound_samples/cry_not_lycanroc_dusk.bin"\n')
	for mon in new_mon_national_order:
		f.write("\t.align 2\n")
		f.write("Cry_{0}::\n".format(mon.capitalize()))
		f.write('\t.incbin "sound/direct_sound_samples/cry_not_{0}.bin"\n\n'.format(\
			mon.lower()))
	f.write("DirectSoundWaveData_register_noise::\n")
	f.write("// >\n")

