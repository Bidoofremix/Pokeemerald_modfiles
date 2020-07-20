#!/usr/bin/python3

import os,re,xlrd,argparse,copy
from config import pokeemerald_dir,slash
from misc import normalize_path

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

pokemon_data = {}

pokemon_excel = normalize_path("pokemon/pokemon.xlsx")

xl_workbook = xlrd.open_workbook(pokemon_excel)
xl_sheet = xl_workbook.sheet_by_index(0)

new_data = ""
for i in range(0,xl_sheet.nrows):
	row = [c.value for c in xl_sheet.row(i)]
	
	# next species found, save previous
	if row[0].startswith("SPECIES_") or i == xl_sheet.nrows-1:
		if new_data != "":
			pokemon_data[species_name] = new_data
		species_name = row[0]
		new_data = {}
			
	# current species
	if not row[0].startswith("SPECIES_") and row[0] != "":
		new_data[row[0]] = row[1]

# save last species
#pokemon_data[species_name] = new_data


########## replace rows with new data

base_stats_file = normalize_path("{0}/src/data/pokemon/base_stats.h".format(pokeemerald_dir))

# follow which data was replaced
data_replaced = {}

species_on = 0
species_pattern = r'\[(SPECIES_\w+)\]'
attribute_pattern = r'.(\w+)'
replace_pattern = r'(\s+= )(.+)(,$)'

# open file and modify lines
lines = []
with open(base_stats_file) as f:
	for line in f:
		if "SPECIES_" in line:
			species_name = re.search(species_pattern,line).group(1)
			if species_name in pokemon_data:
				species_on = 1
			else:
				species_on = 0
				
		else:
			if species_on:
				re_match = re.search(attribute_pattern,line)
				if re_match:
					attrib = re_match.group(1)
					if attrib in pokemon_data[species_name]:
						if species_name not in data_replaced:
							data_replaced[species_name] = {}
						data_replaced[species_name][attrib] = pokemon_data[species_name][attrib]
						line = re.sub(replace_pattern, r'\1{0}\3'.format(\
							pokemon_data[species_name][attrib]),line)
		
		lines.append(line)

if data_replaced == pokemon_data:
	print("\nreplaced base stats data successfully")
else:		
	print("\nWARNING: not all modifications on base stats updated")
	
# write to file
with open(base_stats_file, "w") as f:
	for line in lines:
		f.write(line)
		
print("wrote changes to file")


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
