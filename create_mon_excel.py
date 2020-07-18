#!/usr/bin/python3

import os,re,xlrd,argparse,copy,xlsxwriter
from config import vanilla_dir,slash
from misc import normalize_path, clean_move

wrk_dir = os.getcwd()

raw_folder = normalize_path(wrk_dir + "/raw")

########## hard-coded stuff

from misc import pokemon_excels,excel_splits

family_order = []
order_file = "family_dex_order.txt"
with open(order_file, "r") as f:
	for line in f:
		line = line.rstrip("\n").rstrip("\r")
		if line != "":
			family_order.append(line)
			
required_stats_file = "base_stats.txt"

required_stats = []
with open(required_stats_file, "r") as f:
	for line in f:
		required_stats.append(line.rstrip("\n").rstrip("\r"))
			
########## base stats 

base_stats_file = normalize_path("{0}/src/data/pokemon/base_stats.h".format(vanilla_dir))

print("\nreading vanilla stats from: %s" % base_stats_file)

species_on = 0
species_pattern = r'\[(SPECIES_\w+)\]'
attribute_pattern = r'.(\w+)'
replace_pattern = r'(\s+= )(.+)(,$)'

base_stats = {}

# open file and modify lines
lines = []
with open(base_stats_file) as f:
	for line in f:
		if "SPECIES_" in line:
			species = line.lstrip().split("]")[0].lstrip("[")
			base_stats[species] = {}
		else:
			line = line.rstrip("\n").rstrip(",").lstrip()
			if line.startswith("."):
				line = line.split(" = ")
				base_stats[species][line[0].rstrip()] = line[1]

########## level-up moves

caps2joined = {mon:"".join([i.capitalize() for i in mon.split("_")]) \
	for mon in family_order}
	
caps2joined["MR_MIME"] = "Mrmime"
caps2joined["MIMEJR"] = "Mimejr"
caps2joined["HO_OH"] = "HoOh"

joined2caps = {caps2joined[i]:i for i in caps2joined}

move_data = {mon:{} for mon in family_order}

levelup_file = normalize_path("{0}/src/data/pokemon/level_up_learnsets.h".format(\
	vanilla_dir))
	
levelup_pattern = r'LevelUpMove s(.+)LevelUpLearnset'	
level_move_pattern = r'LEVEL_UP_MOVE\( ?(\d{1,3}), (.+)\)'	
	
with open(levelup_file, "r") as f:
	for line in f:
		if "LevelUpLearnset" in line:
			re_match = re.search(levelup_pattern,line)
			species_name = re_match.group(1)
			if species_name in joined2caps:
				mon = joined2caps[species_name]
				if mon in family_order:
					move_data[mon]["level_up"] = []
					species_on = 1
				
		if species_on and not "[]" in line \
			and not "LEVEL_UP_END" in line:
			re_match = re.search(level_move_pattern,line)
			level = re_match.group(1)
			move = clean_move(re_match.group(2))
			move_data[mon]["level_up"].append([level,move])
		elif "LEVEL_UP_END" in line:
			species_on = 0

########## egg moves

eggmove_file = normalize_path("{0}/src/data/pokemon/egg_moves.h".format(\
	vanilla_dir))

with open(eggmove_file, "r") as f:
	for line in f:
		if "egg_moves" in line:
			species_name = line.split("(")[1].rstrip("\n").rstrip(",r")
			if species_name in family_order:
				move_data[species_name]["egg_move"] = []
				species_on = 1
		if ")," in line:
			species_on = 0
		
		if species_on and not "(" in line:
			move = clean_move(line.lstrip().rstrip("\n").rstrip(","))
			move_data[species_name]["egg_move"].append(move)
			
########## tutor moves

tutormove_file = normalize_path("{0}/src/data/pokemon/tutor_learnsets.h".format(\
	vanilla_dir))
	
name_pattern = r'\[SPECIES_(.+)\]'
move_pattern = r'TUTOR\((MOVE_.+)\)'

with open(tutormove_file, "r") as f:
	for line in f:
		if "TUTOR_LEARNSET" in line and not line.startswith("#define"):
			re_match = re.search(name_pattern,line)
			species_name = re_match.group(1)
			if species_name in family_order:
				move_data[species_name]["tutor_move"] = []
				species_on = 1
		if ")," in line:
			species_on = 0
			
		if species_on:
			if "TUTOR(MOVE" in line:
				re_match = re.search(move_pattern,line)
				move = clean_move(re_match.group(1))
				move_data[species_name]["tutor_move"].append(move)
			
########## tm moves

tmhm_file = normalize_path("{0}/src/data/pokemon/tmhm_learnsets.h".format(\
	vanilla_dir))

tmhm_pattern = r'TMHM\(((T|H)M\d{2}_(.+))\)'			
			
with open(tmhm_file, "r") as f:
	for line in f:
		if "[SPECIES" in line:
			re_match = re.search(name_pattern,line)
			species_name = re_match.group(1)
			if species_name in family_order:
				move_data[species_name]["tm_move"] = []
				species_on = 1
		if ")," in line:
			species_on = 0
				
		if species_on:
			if "TMHM(" in line:
				re_match = re.search(tmhm_pattern,line)
				move = clean_move(re_match.group(3))
				move_data[species_name]["tm_move"].append(move)
			
########## excel files

move_categories = ["level_up","egg_move","tutor_move","tm_move"]

for i,file in zip(excel_splits,pokemon_excels):

	if os.path.isfile(file):
		print("\nerror: file already exists: {0}".format(file))
		exit(0)
		
	if True:
		workbook = xlsxwriter.Workbook(file)
		cell_format = workbook.add_format({'align': "left"})
		
		for mon in sorted(family_order):
			write = False
			if excel_splits.index(i) == 0:
				if mon[0] <= i:
					write = True
			else:
				if excel_splits[excel_splits.index(i)-1] < mon[0] <= \
					excel_splits[excel_splits.index(i)]:
					write = True
				
			if write:
				worksheet = workbook.add_worksheet(mon)
				
				worksheet.set_column(0,0,20,cell_format)
				worksheet.set_column(1,1,35,cell_format)
				worksheet.set_column(2,2,None,cell_format)
				
				worksheet.write(0,0,"NAME")
				worksheet.write(0,1,mon)
		
				# stats
				
				row = 1
				for n,stat in enumerate(required_stats):
					value = ""
					if not stat in base_stats["SPECIES_%s" % mon]:
						if stat.startswith(".evYield"):
							value = 0
						elif stat.startswith(".item"):
							value = "ITEM_NONE"
						elif stat == ".abilityHidden":
							value = "ABILITY_NONE"
					else:
						value = base_stats["SPECIES_%s" % mon][stat].lstrip()
					if str(value) == str(""):
						print("ERROR", mon, stat, value)
						exit(0)
					if str(value).isdigit():
						value = int(value)
					worksheet.write(n+row,0,stat)
					worksheet.write(n+row,1,value)

				row += n+1
				
				# level-up moves
				for category in move_categories:
					if category in move_data[mon]:
						for move in move_data[mon][category]:
							worksheet.write(row,0,category.upper())
							worksheet.write(row,0,category.upper())
							if category == "level_up":
								worksheet.write(row,1,move[1])
								worksheet.write(row,2,move[0])
							else:	
								worksheet.write(row,1,move)
							row += 1
				
				# BST
				bst = sum([int(base_stats["SPECIES_%s" % mon][".base%s" % stat]) for \
					stat in ["HP","Attack","Defense","SpAttack","SpDefense","Speed"]])
				worksheet.write_formula("C2","=SUM(B2:B7", value=bst)
		workbook.close()