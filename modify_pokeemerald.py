#!/usr/bin/python3

import os,re,xlrd,argparse,copy,json
from config import pokeemerald_dir,slash,vanilla_dir
from misc import normalize_path,excel_files,clean_num
from pokemon_tools import *

wrk_dir = os.getcwd()

parser = argparse.ArgumentParser()

parser.add_argument("--reset", action="store_true",\
	help="only reset changes")

args = vars(parser.parse_args())


########## reset all changes before working

print("\nreset to base battle_engine_v2")
os.chdir(pokeemerald_dir)
os_cmd = "git reset --hard".format(pokeemerald_dir)
os.system(os_cmd)			
			
print("done")

if args["reset"]:
	exit(0)

os.chdir(wrk_dir)

########## walk through other mods

print("\nread files in raw folder")

raw_folder = "raw"

encoding = "ISO-8859-15"

for dir, subdirs, files in os.walk(raw_folder):
	for fname in files:
	
		mod_path = normalize_path("{0}\{1}".format(dir,fname))

		pokeemerald_path = normalize_path(pokeemerald_dir + mod_path[len(raw_folder):])
		
		print(pokeemerald_path)
		
		# fix japanese characters in strings.c
		if fname in ["strings.c"]:
			encoding = "utf-8"
		else:
			encoding = "ISO-8859-15"
			
		with open(pokeemerald_path, "r", encoding=encoding) as f:
			original_lines = f.read().splitlines()
		
		with open(mod_path, "r", encoding=encoding) as f:
			mod_lines = f.read().splitlines()
		
		start_codes = []
		end_codes = []
		
		# split to chunks based on trailing // >
		mod_chunks = []
		tmp = []
		for line in mod_lines:
			if line.startswith("// >"):
				# remove first empty line only
				# keep later empty lines
				if "// > END" in line:
					end_codes.append(1)
				else:
					end_codes.append(0)

				if tmp[0] == "":
					tmp.pop(0)
				mod_chunks.append(tmp)
				tmp = []
			else:
				tmp.append(line)
				
		# remove leading empty lines and comment line < //
		tmp_chunks = []
		for m in mod_chunks:
			while m[0].replace(" ","") == "":
				m = m[1:]
			if m[0].startswith("< //"):
				if m[0].startswith("< // START"):
					start_codes.append(1)
				else:
					start_codes.append(0)
				m = m[1:]
				tmp_chunks.append(m)
			else:
				print("\nerror: found chunk not starting with < //")
				[print(c) for c in m]
				exit(0)
		mod_chunks = copy.deepcopy(tmp_chunks)
		
		for i,chunk in enumerate(mod_chunks):
		
			define = 0
			first_match = chunk[0]
			func_name = ""
			
			# check for #define lines
			# identical lines will not be found
			# so find lines that start similarly
			if first_match.startswith("#define"):
				define = 1
				
			if define:
				first_match = first_match.rsplit(" ",1)[0]
			last_match = chunk[-1]
			if define:
				last_match = last_match.rsplit(" ",1)[0]

			first_index = ""
			last_index = ""
		
			for n,line in enumerate(original_lines):
				tmp_line = line
				
				if define:
					tmp_line = tmp_line.rsplit(" ",1)[0]

				if tmp_line == first_match:
					first_index = n
					
				# get first and only first matching last line
				if tmp_line == last_match and first_index != "":
					if n > first_index:
						last_index = n
						break
			
			if (first_index == "" and not start_codes[i] == 1) \
				or (last_index == "" and not end_codes[i] == 1):
				print("\nerror: did not find matching lines for:")
				[print(c) for c in chunk]
				
				print("\nmismatch:")
				if first_index == "":
					print("first line")
				if last_index == "":
					print("last line")
				exit(0)
		
			if start_codes[i] == 1:
				first_index = 0	
	
			if end_codes[i] == 1:
				last_index = len(original_lines)
					
			# replacement lines
			new_chunk = []
			need_new_chunk = 0
			for n,line in enumerate(chunk):
				if line.startswith("#R"):
					need_new_chunk = 1
					replaced_line = chunk[n-1]
					replacing_line = line
					pad_spaces = len(replaced_line)-len(replaced_line.lstrip(" "))
					if pad_spaces > 2:
						replacing_line = "  " + replacing_line[2:]
					else:
						replacing_line = replacing_line[2:]
					line = replacing_line
					new_chunk.pop(-1)
				new_chunk.append(line)

			if need_new_chunk:
				chunk = new_chunk

			original_lines[first_index:last_index+1] = chunk
		
		with open(pokeemerald_path, "w", encoding=encoding) as f:
			for line in original_lines:
				f.write(line + "\n")
			
########## pokemon data

required_stats_file = "base_stats.txt"

required_stats = []
with open(required_stats_file, "r") as f:
	for line in f:
		required_stats.append(line.rstrip("\n").rstrip("\r"))

new_mon_order = []
species_order_file = normalize_path("{0}/include/constants/species.h".format(pokeemerald_dir))
with open(species_order_file, "r") as f:
	for line in f:
		if line.startswith("#define SPECIES_"):
			if not "UNOWN_" in line:
				species = line.rstrip("\n").rstrip("\r").split(" ")[1]
				species = species.replace("SPECIES_","")
				new_mon_order.append(species)

pokemon_data = {}

new_base_stats = {}
new_move_data = {}

pokemon_excels = excel_files(new_mon_order)

for file in pokemon_excels:
	xl_workbook = xlrd.open_workbook(file)
	
	for n in range(0,len(xl_workbook.sheet_names())):
		xl_sheet = xl_workbook.sheet_by_index(n)

		new_data = ""
		for i in range(0,xl_sheet.nrows):
			row = [cell.value for cell in xl_sheet.row(i)]
			row[1] = clean_num(row[1])
			if len(row) > 2:
				row[2] = clean_num(row[2])

			if row[0] == "NAME":
				mon = row[1]
				new_base_stats[mon] = {}
				new_move_data[mon] = {"LEVEL_UP":[], "EGG_MOVE":[],
					"TUTOR_MOVE":[], "TM_MOVE":[]}
			elif row[0] == "LEVEL_UP":
				new_move_data[mon]["LEVEL_UP"].append([check_move(row[1]),check_level(row[2])])
			elif row[0] == "EGG_MOVE":
				new_move_data[mon]["EGG_MOVE"].append(check_move(row[1]))
			elif row[0] == "TUTOR_MOVE":
				new_move_data[mon]["TUTOR_MOVE"].append(check_move(row[1]))
			elif row[0] == "TM_MOVE":
				new_move_data[mon]["TM_MOVE"].append(check_tmmove(row[1]))
			else:
				if row[0].startswith("."):
					new_base_stats[mon][row[0]] = row[1]
			
########## write base stat and move data to files

caps2joined, joined2caps = generate_capsjoined(new_mon_order)

# base stats
base_stats_file = normalize_path("{0}/src/data/pokemon/base_stats.h".format(pokeemerald_dir))

with open(base_stats_file, "w") as f:
	
	f.write("// Maximum value for a female Pokémon is 254 (MON_FEMALE) which is 100% female.\n")
	f.write("// 255 (MON_GENDERLESS) is reserved for genderless Pokémon.\n")
	f.write("#define PERCENT_FEMALE(percent) min(254, ((percent * 255) / 100))\n")
	f.write("\n")
	f.write("const struct BaseStats gBaseStats[] =\n")
	f.write("{\n")
	f.write("    [SPECIES_NONE] = {0},\n")
	f.write("\n")
	
	for mon in new_mon_order:
	
		mon = mon.replace("SPECIES_","")
	
		if mon in ["NONE","EGG"]:
			continue
	
		f.write("    [SPECIES_{0}] = \n".format(mon))
		f.write("    {\n")
		for stat in required_stats:
			f.write("        {0} = {1},\n".format(stat,new_base_stats[mon][stat]))
		f.write("    },\n")
		f.write("\n")
	
	f.write("};\n")
	
# level up moves
levelup_file = normalize_path("{0}/src/data/pokemon/level_up_learnsets.h".format(pokeemerald_dir))

with open(levelup_file, "w") as f:

	f.write("#define LEVEL_UP_MOVE(lvl, moveLearned) {.move = moveLearned, .level = lvl}\n")
	f.write("#define LEVEL_UP_END (0xffff)\n")
	f.write("\n")
	for mon in new_mon_order:
	
		mon = mon.replace("SPECIES_","")
		if mon in ["NONE","EGG"]:
			continue
	
		f.write("static const struct LevelUpMove s{0}LevelUpLearnset[] = {{\n".format(\
			caps2joined[mon]))
		for move in new_move_data[mon]["LEVEL_UP"]:
			f.write("    LEVEL_UP_MOVE({0}, {1}),\n".format(move[1],move[0]))
		f.write("    LEVEL_UP_END\n")
		f.write("};\n")

# egg moves
eggmove_file = normalize_path("{0}/src/data/pokemon/egg_moves.h".format(pokeemerald_dir))

with open(eggmove_file, "w") as f:
	f.write("#define EGG_MOVES_SPECIES_OFFSET 20000\n")
	f.write("#define EGG_MOVES_TERMINATOR 0xFFFF\n")
	f.write("#define egg_moves(species, moves...) (SPECIES_##species + EGG_MOVES_SPECIES_OFFSET), moves\n")
	f.write("\n")
	f.write("const u16 gEggMoves[] = {\n")
	
	for mon in new_mon_order:
		mon = mon.replace("SPECIES_","")
		if mon in ["NONE","EGG"]:
			continue
		if len(new_move_data[mon]["EGG_MOVE"]) == 0:
			continue
		
		f.write("    egg_moves({0},\n".format(mon))
		for move in new_move_data[mon]["EGG_MOVE"][:-1]:
			f.write("        {0},\n".format(move))
		f.write("        {0}),\n".format(new_move_data[mon]["EGG_MOVE"][-1]))
		f.write("\n")
		
	f.write("    EGG_MOVES_TERMINATOR\n")
	f.write("};\n")
	
# tutor moves
tutormove_file = normalize_path("{0}/src/data/pokemon/tutor_learnsets.h".format(pokeemerald_dir))

with open(tutormove_file, "w") as f:
	f.write("const u16 gTutorMoves[] =\n")
	f.write("{\n")
	for move in tutor_moves:
		f.write("    [TUTOR_{0}] = {0},\n".format(check_move(move)))
	f.write("};\n")
	f.write("\n")
	f.write("#define TUTOR_LEARNSET(moves) ((u32)(moves))\n")
	f.write("#define TUTOR(move) ((u64)1 << (TUTOR_##move))\n")
	f.write("\n")
	f.write("static const u32 sTutorLearnsets[] =\n")
	f.write("{\n")
	f.write("    [SPECIES_NONE]       = TUTOR_LEARNSET(0),\n")
	f.write("\n")
	
	for mon in new_mon_order:
		mon = mon.replace("SPECIES_","")
		if mon in ["EGG","NONE"]:
			continue
	
		f.write("    [SPECIES_{0}] = TUTOR_LEARNSET".format(mon))
		moves = new_move_data[mon]["TUTOR_MOVE"]
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

# tm moves
tm_file = normalize_path("{0}/src/data/pokemon/tmhm_learnsets.h".format(pokeemerald_dir))

with open(tm_file, "w") as f:
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
	for mon in new_mon_order:
		mon = mon.replace("SPECIES_","")
		if mon in ["NONE","EGG"]:
			continue
	
		f.write("    [SPECIES_{0}] = TMHM_LEARNSET".format(mon))
		moves = sorted(new_move_data[mon]["TM_MOVE"])
		if len(moves) > 0:
			f.write("(TMHM({0})\n".format(moves[0]))
			for move in moves[1:-1]:
				f.write("\t"*11 + "| TMHM({0})\n".format(move))
			f.write("\t"*11 + "| TMHM({0})),\n".format(moves[-1]))
		else:
			f.write("(0),\n")
		f.write("\n")
	f.write("};\n")

########## trainer data

print("\nvalidate and modify trainers")

trainer_data = {}
trainer_metadata = {}

# defined trainers and their party offsets
defined_trainers = {}
party = ""
trainer_file = normalize_path("{0}/src/data/trainers.h".format(pokeemerald_dir))
trainer_file_lines = []
with open(trainer_file, "r") as f:
	for line in f:
		trainer_file_lines.append(line)
		if line.startswith("    [TRAINER_"):
			if party != "":
				defined_trainers[current_trainer] = party
			current_trainer = line.lstrip(" ").split("]")[0].lstrip("[")
		else:
			if ".party = {" in line:
				party = line.lstrip(" ").split(" ")[4].split("}")[0]
				
# defined moves
defined_moves = set([])
move_file = normalize_path("{0}/include/constants/moves.h".format(pokeemerald_dir))
with open(move_file, "r") as f:
	for line in f:
		if line.startswith("#define MOVE_"):
			defined_moves.add(line.split(" ")[1])

# defined species
defined_species = set([])
species_file = normalize_path("{0}/include/constants/species.h".format(pokeemerald_dir))
with open(species_file, "r") as f:
	for line in f:
		if line.startswith("#define SPECIES_"):
			defined_species.add(line.split(" ")[1])

# defined items
defined_items = set([])
items_file = normalize_path( "{0}/include/constants/items.h".format(pokeemerald_dir))
with open(items_file, "r") as f:
	for line in f:
		if line.startswith("#define ITEM_"):
			defined_items.add(line.split(" ")[1])			
			
trainer_excel = normalize_path("trainers/trainers.xlsx")

xl_workbook = xlrd.open_workbook(trainer_excel)
xl_sheet = xl_workbook.sheet_by_index(0)

party = ""
for i in range(0,xl_sheet.nrows):
	row = [c.value for c in xl_sheet.row(i)]
	row = [int(c) if isinstance(c, float) else c for c in row]
	
	# new trainer or last line of file
	if row[0].startswith("TRAINER_") or i == xl_sheet.nrows-1:
		if party != "":
		
			# validate level and IV
			for i,mon in enumerate(mons):
			
				if not isinstance(mon["lvl"], int):
					print("\nerror: non-numeric level '{0}' ({1})".format(\
						mon["lvl"],trainer))
						
				if mon["iv"] == "":
					mon["iv"] = 0
				else:
					if not isinstance(mon["iv"],int):
						print("\nerror: non-numeric IV '{0}' ({1})".format(\
							mon["iv"],trainer))
				
				mons[i] = mon
		
			# validate items
			items = [mon["heldItem"] for mon in mons]
			if any(items):
				mon_items = True
				for i,mon in enumerate(mons):
				
					if mon["heldItem"] != "":
						tmp_item = "ITEM_%s" % mon["heldItem"].replace(" ","_").upper()
						if tmp_item not in defined_items:
							print("\nerror: item {0} not defined ({1})".format(tmp_item,trainer))
							exit(0)
					else:
						tmp_item = "ITEM_NONE"
					mon["heldItem"] = tmp_item
					mons[i] = mon
			else:
				mon_items = False
				
			# validate moves
			moves = [mon["moves"] for mon in mons]
			if any(moves):
				if not all(moves):
					print("\nerror: some, but not all mons of %s have moves" % trainer)
					exit(0)
				mon_moves = True
				for i,mon in enumerate(mons):
					tmp_moves = mon["moves"].split(",")
					tmp_moves = set(["MOVE_%s" % m.strip().replace(" ","_").upper() \
						for m in tmp_moves])
					if not tmp_moves.issubset(defined_moves):
						print("\nerror: not all moves of %s defined:" % trainer)
						[print(m) for m in sorted(tmp_moves)]
						exit(0)
					tmp_moves = list(tmp_moves)
					# fill missing slots with MOVE_NONE
					if len(tmp_moves) != 4:
						tmp_moves += ["MOVE_NONE"] * (4 - (len(tmp_moves)))
					mon["moves"] = tmp_moves
					mons[i] = mon
			else:
				mon_moves = False
			
			# validate species
			for i,mon in enumerate(mons):
				species_name = "SPECIES_%s" % mon["species"].upper()
				if not species_name in defined_species:
					print("\nerror: species {0} not defined ({1})".format(\
						species_name,trainer))
					exit(0)
				mon["species"] = species_name
				mons[i] = mon
				
			if mon_items and mon_moves:
				category = "ItemCustomMoves"
			elif mon_items:
				category = "ItemDefaultMoves"
			elif mon_moves:
				category = "NoItemCustomMoves"
			else:
				category = "NoItemDefaultMoves"
			
			trainer_data[trainer] = {"pokemon":mons, "category":category}

		mons = []
		trainer = row[0]
	elif row[0] != "" and row[0] != "END":
			if row[0] == "species":
				columns = row
			elif not row[0].startswith("."):
				mons.append({z[0]:z[1] for z in zip(columns,row)})
				party = 1
			else:
				if trainer not in trainer_metadata:
					trainer_metadata[trainer] = {}
				trainer_metadata[trainer][row[0]] = row[1]
				
	# empty rows
	else:
		pass

print("done")

# read trainer party file content
trainer_party_file_lines = []
trainer_party_file = normalize_path("{0}/src/data/trainer_parties.h".format(pokeemerald_dir))
with open(trainer_party_file, "r") as f:
	for line in f:
		trainer_party_file_lines.append(line)

# modify trainer and trainer party file lines
for trainer in trainer_data:
	trainer_lines = []
	
	trainer_lines.append("static const struct TrainerMon{0} {1}[] = {{\n".format(\
		trainer_data[trainer]["category"],defined_trainers[trainer]))

	trainer_mons = trainer_data[trainer]["pokemon"]
	for i,mon in enumerate(trainer_mons):
		trainer_lines.append("    {\n")
		trainer_lines.append("    .iv = {0},\n".format(mon["iv"]))
		trainer_lines.append("    .lvl = {0},\n".format(mon["lvl"]))
		if trainer_data[trainer]["category"] in ["ItemCustomMoves","ItemDefaultMoves"]:
			trainer_lines.append("    .heldItem = {0},\n".format(mon["heldItem"]))
		if trainer_data[trainer]["category"] in ["NoItemCustomMoves","ItemCustomMoves"]:
			trainer_lines.append("    .moves = {%s},\n" % \
				", ".join(mon["moves"]))
		trainer_lines.append("    .species = {0},\n".format(mon["species"]))
		last_line = "    }"
		if i != len(trainer_mons)-1:
			last_line += ","
		last_line += "\n"
		trainer_lines.append(last_line)
		
	trainer_lines.append("};\n")
	
	first_index = ""
	for i,line in enumerate(trainer_party_file_lines):
		if defined_trainers[trainer] in line:
			first_index = i
		elif first_index != "" and line.startswith("static const struct Trainer"):
			last_index = i-1
			break
			
	trainer_party_file_lines[first_index:last_index] = trainer_lines

	trainer_on = 0
	for i,line in enumerate(trainer_file_lines):
		if "[TRAINER_" in line:
			if trainer in line:
				trainer_on = 1
			else:
				trainer_on = 0
		if trainer_on:
			if ".partyFlags" in line:
				line = "        .partyFlags = "
				if trainer_data[trainer]["category"] == "ItemCustomMoves":
					line += "F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET"
				elif trainer_data[trainer]["category"] == "NoItemCustomMoves":
					line += "F_TRAINER_PARTY_CUSTOM_MOVESET"
				elif trainer_data[trainer]["category"] == "ItemDefaultMoves":
					line += "F_TRAINER_PARTY_HELD_ITEM"
				else:
					line += "0"
				line += ",\n"
				trainer_file_lines[i] = line
				
			if ".party = {" in line:
				line = "        .party = {{.{0} = {1}}},\n".format(\
					trainer_data[trainer]["category"],defined_trainers[trainer])
				trainer_file_lines[i] = line
				
			else:
				if trainer in trainer_metadata:
					for attrib in trainer_metadata[trainer]:
						if attrib in line:
							line = "        {0} = {1},\n".format(\
								attrib,trainer_metadata[trainer][attrib])
							trainer_file_lines[i] = line
	
# write to trainer party file
with open(trainer_party_file, "w") as f:
	for line in trainer_party_file_lines:
		f.write(line)

# write to trainer file
with open(trainer_file, "w") as f:
	for line in trainer_file_lines:
		f.write(line)

########### wild encounters		

print("\nmodifying wild encounters")

# read everything from vanilla
# only wild pokemon encounters are changed
# the rest need to be injected from vanilla	
vanilla_wild_data = normalize_path("{0}/src/data/wild_encounters.json".format(vanilla_dir))
with open(vanilla_wild_data, "r") as f:
	vanilla_encounters = json.load(f)

wild_data_excel = normalize_path("wild_data/wild_data.xlsx")		
print("read encounter data from: %s" % wild_data_excel)

new_encounter_data = []

xl_workbook = xlrd.open_workbook(wild_data_excel)
for n in range(0,len(xl_workbook.sheet_names())):
	xl_sheet = xl_workbook.sheet_by_index(n)

	route_data = {}
	
	new_data = ""
	
	# map name and base label
	row = [clean_num(cell.value) for cell in xl_sheet.row(0)]
	route_data["map"] = xl_sheet.cell(0,1).value
	route_data["base_label"] = xl_sheet.cell(1,1).value

	# land, water and rock smash encounters
	for index,biome in [(0,"land_mons"),(6,"water_mons"),(12,"rock_smash_mons")]:
		if xl_sheet.cell(5,index+1).value != "":
			route_data[biome] = {"mons":[]}
			for row in range(5,17):
				if xl_sheet.cell(row,index+1).value == "":
					break
				mon = {}
				mon["species"] = "SPECIES_%s" % xl_sheet.cell(row,index+1).value
				mon["min_level"] = int(xl_sheet.cell(row,index+2).value)
				mon["max_level"] = int(xl_sheet.cell(row,index+3).value)
				route_data[biome]["mons"].append(mon)
			route_data[biome]["encounter_rate"] = int(xl_sheet.cell(5,index+4).value)
			
	# fishing encounters
	if xl_sheet.cell(25,1).value != "":
		route_data["fishing_mons"] = {"mons":[]}
		
		# old rod
		for row in [25,26]:
			mon = {}
			mon["species"] = "SPECIES_%s" % xl_sheet.cell(row,1).value
			mon["min_level"] = int(xl_sheet.cell(row,2).value)
			mon["max_level"] = int(xl_sheet.cell(row,3).value)
			route_data["fishing_mons"]["mons"].append(mon)
			
		# good rod
		for row in range(25,28):
			mon = {}
			mon["species"] = "SPECIES_%s" % xl_sheet.cell(row,7).value
			mon["min_level"] = int(xl_sheet.cell(row,8).value)
			mon["max_level"] = int(xl_sheet.cell(row,9).value)	
			route_data["fishing_mons"]["mons"].append(mon)

		# super rod
		for row in range(25,30):
			mon = {}
			mon["species"] = "SPECIES_%s" % xl_sheet.cell(row,13).value
			mon["min_level"] = int(xl_sheet.cell(row,14).value)
			mon["max_level"] = int(xl_sheet.cell(row,15).value)	
			route_data["fishing_mons"]["mons"].append(mon)

		route_data["fishing_mons"]["encounter_rate"] = int(xl_sheet.cell(25,4).value)
		
	new_encounter_data.append(route_data)	
		
for n,category in enumerate(vanilla_encounters["wild_encounter_groups"]):
	if category["label"] == "gWildMonHeaders":
		vanilla_encounters["wild_encounter_groups"][n]["encounters"] = new_encounter_data
		
with open(normalize_path("{0}/src/data/wild_encounters.json".format(\
	pokeemerald_dir)), "w") as f:
		json.dump(vanilla_encounters,f,indent=3)
	
print("done")
	
########### maps

print("\nupdating maps")

#os_cmd = "./update_maps.py --mode insert"

if slash == "/":
	suffix = "./"
elif slash == "\\":
	suffix = ""
	
os_cmd = "{0}update_maps.py --mode insert".format(suffix)	
	
os.system(os_cmd)
		
print("done")		
		
########## finish

print("")

os.chdir(pokeemerald_dir)
os_cmd = "git status"
os.system(os_cmd)
