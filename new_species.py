#!/usr/bin/python3

import os,xlrd
from config import vanilla_dir
from misc import normalize_path
from pokemon_tools import *

raw_folder = normalize_path(os.getcwd() + "\\raw")

########## read mandatory base stats from base_stats.txt

required_stats_file = "base_stats.txt"

required_stats = []
with open(required_stats_file, "r") as f:
	for line in f:
		required_stats.append(line.rstrip("\n").rstrip("\r"))
		
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

new_species_excel = "pokemon/new_species.xls"
xl_workbook = xlrd.open_workbook(new_species_excel)
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
				new_species[mon]["pokedex_description"][which_line] = row[1]
			
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
						new_species[mon]["pokedex_entry"][".height"] = row[1]//10
				if row[0] == "weight (kg)":
						new_species[mon]["pokedex_entry"][".weight"] = int(float(row[1])*10)
			
			# scales and offsets
			if row[0] in ["pokemonScale","pokemonOffset","trainerScale","trainerOffset"]:
				new_species[mon]["pokedex_entry"][".{0}".format(row[0])] = row[1]
						
	# check mandatory stats
	if not all([s in new_species[mon]["base_stats"] for s in required_stats]):
		print("\nerror: {0} missing the following stats:".format(mon))
		for s in required_stats:
			if s not in new_species[mon]["base_stats"]:
				print(" %s" % s)
		exit(0)
	
	new_species[mon]["pokedex_entry"][".description"] = "g{0}PokedexText".format(\
		mon.capitalize())
	
########## insert new species to list

for mon in new_species:
	who_index = family_order.index(insert_info[mon]["who"])
	if insert_info[mon]["where"] == "after":
		family_order.insert(who_index+1,mon)
	elif insert_info[mon]["where"] == "before":
		family_order.insert(who_index,mon)

########## define species

national_dex_start = "#define NATIONAL_DEX_NONE"
national_dex_end = "#define NATIONAL_DEX_COUNT"

species_file = normalize_path("{0}/include/constants/species.h".format(raw_folder))
if not os.path.isfile(species_file):
	print("species.h not detected, create new")
	species_file_lines = []
	with open("{0}/include/constants/species.h".format(vanilla_dir), "r") as f:
		for line in f:
			species_file_lines.append(line)

	national_defines_on = 0
	wrote_lines = 0
	with open(species_file, "w") as f:
		f.write("< //\n")
		for line in species_file_lines:
			if line.startswith(national_dex_start):
				national_defines_on = 1
			elif line.startswith(national_dex_end):
				national_defines_on = 0
				# skip old national dex count definition
				continue
			
			if national_defines_on and not wrote_lines:
				f.write("#define NATIONAL_DEX_NONE 0\n")
				iter_round = 1
				for mon in family_order:
					f.write("#define NATIONAL_DEX_{0} {1}\n".format(\
						mon,iter_round))
					iter_round += 1
					if mon == "MEW":
						f.write("\n#define KANTO_DEX_COUNT NATIONAL_DEX_MEW\n\n")
					elif mon == "CELEBI":
						f.write("\n#define JOHTO_DEX_COUNT NATIONAL_DEX_CELEBI\n\n")
				f.write("\n#define NATIONAL_DEX_COUNT NATIONAL_DEX_{0}\n".format(\
					family_order[-1]))
				wrote_lines = 1
			
			elif not national_defines_on:
				f.write(line)
		f.write("// >\n")
else:
	defined_new_mons = set([])
	species_file_lines = []
	with open(species_file, "r") as f:
		for line in f:
			species_file_lines.append(line)
for line in species_file_lines:
	line = line.split(" ")
	if len(line) > 1:
		if any([mon in line[1] for mon in new_species]):
			for mon in new_species:
				if mon in line:
					defined_new_mons.append(mon)

print("\nof the {0} new mons:".format(len(new_species)))
print(" {0} have been defined".format(len(defined_new_mons)))
print(" {0} have not been defined".format(len(new_species)-len(defined_new_mons)))
			
###	define species

print("\nmodify species.h")

for n,line in enumerate(species_file_lines):
	if line.startswith("#define SPECIES_EGG"):
		egg_index = int(line.split(" ")[2])
		insert_index = n
		break

new_species_defines = []
for mon in sorted(new_species):
	new_species_defines.append("#define SPECIES_{0} {1}\n".format(\
		mon,egg_index))
	egg_index += 1
new_species_defines.append("#define SPECIES_EGG {0}\n".format(egg_index))

species_file_lines[insert_index-1:insert_index+1] = new_species_defines

### define national dex indexes
for n,line in enumerate(species_file_lines):
	if line.startswith(national_dex_start):
		start_index = n
	elif line.startswith(national_dex_end):
		stop_index = n

new_national_dex_defines = []
for n,mon in enumerate(family_order):
	new_national_dex_defines.append("#define NATIONAL_DEX_{0} {1}\n".format(\
		mon,n+1))
		
species_file_lines[start_index:stop_index] = new_national_dex_defines

### TODO: write species file lines to file

########## species name

print("modify species_names.h")

species_name_file = normalize_path("{0}/src/data/text/species_names.h".format(\
	raw_folder))
	
species_name_file_lines = []
with open(species_name_file, "r") as f:
	for line in f:
		species_name_file_lines.append(line)

for mon in new_species:
	if mon not in defined_new_mons:
		line = '    [SPECIES_{0}] = _("{1}"),\n'.format(mon,mon.capitalize())
		species_name_file_lines.insert(-2,line)

### TODO: write species name file lines to file
	
########## collect weights for weight-based national dex order

pokedex_entries_file = normalize_path("{0}/src/data/pokemon/pokedex_entries.h".format(\
	raw_folder))
if not os.path.isfile(pokedex_entries_file):
	print("pokedex_entries.h not detected, create new")
	pokedex_entry_dict = {}
	with open(normalize_path("{0}/src/data/pokemon/pokedex_entries.h".format(\
		vanilla_dir)), "r") as f:
		for line in f:
			if "[NATIONAL_DEX" in line:
				mon = line.lstrip().split("]")[0][1:]
				pokedex_entry_dict[mon] = {}
			elif line.startswith("        ."):
				line = line.strip().rstrip("\n").rstrip(",").split(" = ")
				pokedex_entry_dict[mon][line[0]] = line[1]
	
	with open(pokedex_entries_file, "w") as f:
		f.write("< //\n")
		f.write("const struct PokedexEntry gPokedexEntries[] =\n")
		f.write("{\n")
		for mon in family_order:
			mon = "NATIONAL_DEX_{0}".format(mon)
			f.write("    [{0}] = \n".format(mon))
			f.write("    {\n")
			for key in sorted(pokedex_entry_dict[mon]):
				f.write("        {0} = {1},\n".format(key,pokedex_entry_dict[mon][key]))
			f.write("    },\n\n")
		f.write("};\n")
		f.write("// >\n")
else:
	print("found pokedex_entries.h")
	
weight_dict = {}
height_dict = {}
with open(pokedex_entries_file, "r") as f:
	for line in f:
		if "[NATIONAL_DEX" in line:
			mon = line.strip().split("]")[0][1:]
		elif ".weight" in line or ".height" in line:
			line = line.strip().rstrip("\n").rstrip(",").split(" ")
			if ".weight" in line:
				which_dict = weight_dict
			elif ".height" in line:
				which_dict = height_dict
			which_dict[mon] = int(line[2])
			
########## pokedex orders

pokedex_orders_file = normalize_path("{0}/src/data/pokemon/pokedex_orders.h".format(\
	raw_folder))
if not os.path.isfile(pokedex_orders_file):
	print("pokedex_orders.h not detected, create new")
	with open(pokedex_orders_file, "w") as f:
		f.write("< //\n")
		
		# alphabetical
		f.write("const u16 gPokedexOrder_Alphabetical[] =\n")
		f.write("{\n")
		for mon in sorted(family_order):
			f.write("    NATIONAL_DEX_{0},\n".format(mon))
		f.write("};\n\n")

		# weight
		f.write("const u16 gPokedexOrder_Weight[] =\n")
		f.write("{\n")
		for mon in sorted(weight_dict, key= lambda x: weight_dict[x]):
			if mon.replace("NATIONAL_DEX_","") in family_order:
				f.write("    {0},\n".format(mon))
		f.write("};\n\n")
		
		# height
		f.write("const u16 gPokedexOrder_Height[] =\n")
		f.write("{\n")
		for mon in sorted(height_dict, key= lambda x: height_dict[x]):
			if mon.replace("NATIONAL_DEX_","") in family_order:
				f.write("    {0},\n".format(mon))
		f.write("};\n")
		f.write("// > END\n")
		
else:
	print("found pokedex_orders.h")

########## pokemon.c

pokemon_file = normalize_path("{0}/src/pokemon.c".format(raw_folder))

pokemon_file_lines = []
with open(pokemon_file, "r") as f:
	for line in f:
		pokemon_file_lines.append(line)
		
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
	

########## sprites

sprite_files = ["front.png","front_anim.png","back.png",\
	"footprint.png","normal.pal","shiny.pal"]

for mon in new_species:

	# check that sprites exist
	sprite_folder = normalize_path("sprites/{0}".format(mon.lower()))
	if not os.path.isdir(sprite_folder):
		print("\nerror: did not find sprite folder for %s" % mon)
		exit(0)
	for file in sprite_files:
		if not os.path.isfile("{0}/{1}".format(sprite_folder,file)):
			print("\nerror: did not find {0} for {1}".format(file,mon))
			exit(0)
