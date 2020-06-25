#!/usr/bin/python3

import os,xlrd
from config import vanilla_dir
from misc import normalize_path

raw_folder = normalize_path(os.getcwd() + "\\raw")

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

new_species_excel = "pokemon/new_species.xls"
xl_workbook = xlrd.open_workbook(new_species_excel)
xl_sheet = xl_workbook.sheet_by_index(0)

species_name = xl_sheet.cell(0,0).value

for i in range(1,xl_sheet.nrows):
	row = [c.value for c in xl_sheet.row(i)]
	if not row[0].startswith("."):
		if row[0] == "after":
			new_species[species_name] = {"where":row[0], "who":row[1]}

########## insert new species to list

# for n in new_species:
	# who_index = family_order.index(new_species[n]["who"])
	# if new_species[n]["where"] == "after":
		# family_order.insert(who_index+1,n)
	# elif new_species[n]["where"] == "before":
		# family_order.insert(who_index,n)

# print(family_order)

########## open files and create copy in raw

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
			if line.startswith("#define NATIONAL_DEX_NONE"):
				national_defines_on = 1
			elif line.startswith("#define NATIONAL_DEX_COUNT"):
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
	print("found species.h")
		
########## weight for weight-based national dex order

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
	print("found")