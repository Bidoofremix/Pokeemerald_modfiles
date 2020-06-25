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
tm_pattern = r'#define ITEM_((T|H)M\d{2}_.+) '	
	
defined_tmmoves = []
with open(item_file, "r") as f:
	for line in f:
		re_match = re.match(tm_pattern,line)
		if re_match:
			defined_tmmoves.append(re_match.group(1))

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
	if tmp_move not in defined_tmmoves:
		print("\nerror: did not recognize TM/HM move '%s'" % move)
		exit(0)
	return tmp_move