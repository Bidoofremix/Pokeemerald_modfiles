#!/usr/bin/python3

import re

from config import pokeemerald_dir
from misc import normalize_path

snippet_folder = "file_snippet"

########## resources

# moves
move_file = normalize_path("{0}/include/constants/moves.h".format(\
	pokeemerald_dir))

defined_moves = []	
with open(move_file, "r") as f:
	for line in f:
		if line.startswith("#define MOVE_"):
			defined_moves.append(line.split(" ")[1])

# move types
battle_move_file = normalize_path("{0}/src/data/battle_moves.h".format(\
	pokeemerald_dir))
	
move_types = {}
with open(battle_move_file, "r") as f:
	for line in f:
		if line.startswith("    ["):
			current_move = line.split("[")[1].split("]")[0]
		elif ".type" in line:
			tmp_type = line.split("=")[1].strip(" ").replace(",","").replace("\n","")
			move_types[current_move] = tmp_type

#TM moves			
item_file = normalize_path("{0}/include/constants/items.h".format(\
	pokeemerald_dir))

tm_pattern = r'#define ITEM_([T|H]M\d{2}_(.+)) '	
attack2tm = {}
with open(item_file, "r") as f:
	for line in f:
		re_match = re.match(tm_pattern,line)
		if re_match:
			tm_move = re_match.group(1)
			move = re_match.group(2)
			# adjust spacing of solarbeam
			if move == "SOLARBEAM":
				move = "SOLAR_BEAM"
			attack2tm[move] = tm_move
			
# tutor moves
# src/data/pokemon/tutor_learnsets.h
tutor_file = normalize_path("{0}/src/data/pokemon/tutor_learnsets.h".format(\
	snippet_folder))

tutor = 0
tutor_moves = set([])
with open(tutor_file, "r", encoding="utf-8") as f:
	for line in f:
		if not tutor:
			if line.startswith("const u16 gTutorMoves"):
				tutor = 1
		else:
			if line.startswith("{"):
				pass
			elif line.startswith(" "):
				tmp_move = line.rstrip("\n").rstrip("\n").split("=")[1].strip().replace(",","")
				tutor_moves.add(tmp_move)
			elif line.startswith("}"):
				tutor = 0			
			
# abilities
ability_file = normalize_path("{0}/include/constants/abilities.h".format(\
	pokeemerald_dir))
defined_abilities = set([])
with open(ability_file, "r") as f:
	for line in f:
		if line.startswith("#define ABILITY"):
			ability = line.split(" ")[1]
			defined_abilities.add(ability)
			
# species
species_file = normalize_path("{0}/include/constants/species.h".format(\
	pokeemerald_dir))
defined_species = set([])
with open(species_file, "r") as f:
	for line in f:
		if line.startswith("#define SPECIES") and line.count("SPECIES") < 2:
			species = line.split(" ")[1]
			defined_species.add(species)

unowns = [chr(i+64) for i in range(1,27)]
unowns += ["EMARK","QMARK"]
			
########## functions

def underscore_upper(text):
	return text.strip().replace(" ","_").replace("-","_").upper()

def check_level(level):
	error = False
	if not str(level).isdigit():
		error = True
	level = int(level)
	if not 0 <= level <= 100:
		error = True
	if error:
		print("\nerror: invalid level '%s'" % level)
		exit(0)
	return level
	
def check_move(move):
	tmp_move = "MOVE_{0}".format(underscore_upper(move))
	if tmp_move not in defined_moves:
		print("\nerror: did not recognize move '%s'" % move)
		exit(0)
	return tmp_move

def move_type(move):
	return move_types[move]
	
def check_tmmove(move):
	if move.lower() == "solarbeam":
		move = "Solar Beam"
	tmp_move = underscore_upper(move)
	if tmp_move not in attack2tm:
		print("\nerror: did not recognize TM/HM move '%s'" % move)
		exit(0)
	return attack2tm[tmp_move]
	
def check_ability(ability):
	ability = "ABILITY_" + ability.upper().replace(" ","_")
	if ability not in defined_abilities:
		print("\nerror: did not recognize ability '%s'" % ability)
		exit(0)
	return ability
	
def check_species(species):
	tmp_species = underscore_upper(species)
	if not tmp_species.startswith("SPECIES_"):
		tmp_species = "SPECIES_%s" % tmp_species
	if not tmp_species in defined_species:
		print("\nerror: did not recognize species '%s'" % species)
		exit(0)
	return tmp_species
	
def generate_capsjoined(mons):
	mons = [i.replace("SPECIES_","") for i in mons]
	caps2joined = {mon:"".join([i.capitalize() for i in mon.split("_")]) \
		for mon in mons}
		
	for u in unowns:
		if u == "EMARK":
			letter = "ExclamationMark"
		elif u == "QMARK":
			letter = "QuestionMark"
		else:
			letter = u
		caps2joined["UNOWN_{0}".format(u)] = "Unown{0}".format(letter)
		
	caps2joined["NONE"] = "CircledQuestionMark"	
		
	caps2joined["MR_MIME"] = "Mrmime"
	caps2joined["MIMEJR"] = "Mimejr"
	caps2joined["HO_OH"] = "HoOh"

	joined2caps = {caps2joined[i]:i for i in caps2joined}
	
	return caps2joined,joined2caps