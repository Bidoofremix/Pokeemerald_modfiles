#!/usr/bin/python

import os,re,xlrd,argparse
from config import pokeemerald_dir

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
			
########## pokemon data

pokemon_data = {}

pokemon_excel = "pokemon/pokemon.xlsx"

xl_workbook = xlrd.open_workbook(pokemon_excel)
xl_sheet = xl_workbook.sheet_by_index(0)

new_data = ""
for i in range(0,xl_sheet.nrows):
	row = [c.value for c in xl_sheet.row(i)]
	
	# new species found, save previous
	if row[0].startswith("SPECIES_"):
		if new_data != "":
			pokemon_data[species_name] = new_data
		species_name = row[0]
		new_data = {}
			
	# current species
	if not row[0].startswith("SPECIES_") and row[0] != "":
		new_data[row[0]] = row[1]

# save last species
pokemon_data[species_name] = new_data

########## replace rows with new data

base_stats_file = "{0}/src/data/pokemon/base_stats.h".format(pokeemerald_dir)

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

########## walk through other mods

print("\nreading other files")

raw_folder = "raw"

for dir, subdirs, files in os.walk(raw_folder):
	for fname in files:

		mod_path = "{0}\{1}".format(dir,fname)
		pokeemerald_path = pokeemerald_dir + mod_path[len(raw_folder):]
		
		print(pokeemerald_path)
		
		with open(pokeemerald_path, "r", encoding="utf-8") as f:
			original_lines = f.read().splitlines()
			
		with open(mod_path, "r", encoding="utf-8") as f:
			mod_lines = f.read().splitlines()
		
		# split to chunks based on trailing // >
		mod_chunks = []
		tmp = []
		for line in mod_lines:
			if line.startswith("// >"):
				# remove first empty line only
				# keep later empty lines
				if tmp[0] == "":
					tmp.pop(0)
				mod_chunks.append(tmp)
				tmp = []
			else:
				tmp.append(line)
				
		# remove leading comment line // <
		mod_chunks = [m[1:] for m in mod_chunks]
		
		for chunk in mod_chunks:

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
			
			if first_index == "" or last_index == "":
				print("\nerror: did not find matching lines for:")
				print("\nmismatch:")
				if first_index == "":
					print("first line")
				if last_index == "":
					print("last line")
				exit(0)
			
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
		
		with open(pokeemerald_path, "w", encoding="utf-8") as f:
			for line in original_lines:
				f.write(line + "\n")
		
########## maps

os_cmd = "update_maps.py --mode insert"

os.system(os_cmd)
		
########## finish

print("")

os.chdir(pokeemerald_dir)
os_cmd = "git status"
os.system(os_cmd)