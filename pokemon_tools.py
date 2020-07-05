#!/usr/bin/python3

import re

from config import pokeemerald_dir
from misc import normalize_path

########## resources

# moves
move_file = normalize_path("{0}/include/constants/moves.h".format(\
	pokeemerald_dir))

defined_moves = []	
with open(move_file, "r") as f:
	for line in f:
		if line.startswith("#define MOVE_"):
			defined_moves.append(line.split(" ")[1])

item_file = normalize_path("{0}/include/constants/items.h".format(\
	pokeemerald_dir))

#TM moves
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
			
########## functions

def underscore_upper(text):
	return text.strip().replace(" ","_").replace("-","_").upper()

def check_level(level):
	if not 0 < level <= 100:
		print("\nerror: invalid level '%s'" % level)
		exit(0)
	return level
	
def check_move(move):
	tmp_move = "MOVE_{0}".format(underscore_upper(move))
	if tmp_move not in defined_moves:
		print("\nerror: did not recognize move '%s'" % move)
		exit(0)
	return tmp_move
	
def check_tmmove(move):
	tmp_move = underscore_upper(move)
	if tmp_move not in attack2tm:
		print("\nerror: did not recognize TM/HM move '%s'" % move)
		exit(0)
	return attack2tm[tmp_move]