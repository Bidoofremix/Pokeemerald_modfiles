#!/usr/bin/python3

import sys,os,shutil,argparse,textwrap
from pathlib import Path
from config import pokeemerald_dir,vanilla_dir,slash
from misc import normalize_path,yesno
from pokemon_tools import *	

map_dir = normalize_path("{0}\data\maps".format(pokeemerald_dir))
layout_dir = normalize_path("{0}\data\layouts".format(pokeemerald_dir))
constants_dir = normalize_path("{0}\include\constants".format(pokeemerald_dir))

snippet_folder = normalize_path(os.getcwd() + "\\file_snippet")
full_folder = normalize_path(os.getcwd() + "\\file_full")
graphics_dir = normalize_path("{0}/graphics".format(full_folder))
sound_dir = normalize_path("{0}/sound".format(full_folder))
include_dir = normalize_path("{0}/include".format(full_folder))
src_dir = normalize_path("{0}/src".format(full_folder))

########## argparse

parser = argparse.ArgumentParser()

parser.add_argument("--number", type=int, required=True,\
	help="which TM to change")
parser.add_argument("--move", required=True,\
	help="which move to use instead")
parser.add_argument("--species", required=True,\
	help="list of species to learn the new move")
	
args = vars(parser.parse_args())

########## open files

# include/constants/items.h
item_file = normalize_path("{0}/include/constants/items.h".format(\
	snippet_folder))
	
print(item_file)

tm_items = []
with open(item_file, "r", encoding="utf-8") as f:
	for line in f:
		if line.count("ITEM_TM") > 1:
			line = line.rstrip("\n").rstrip("\r").split(" ")
			tm_items.append(line[1])
	
tm_indexes = {tm_items[n].replace("ITEM_",""): n+1 for n in range(0,len(tm_items))}

# src/data/party_menu.h
move = 0
tm_moves_list = []
party_menu_file = normalize_path("{0}/src/data/party_menu.h".format(\
	snippet_folder))
with open(party_menu_file, "r", encoding="utf-8") as f:
	for line in f:
		if not move:
			if line.startswith("static const u16 sTMHMMoves"):
				move = 1
		else:
			if line.startswith("{"):
				pass
			elif line.startswith(" "):
				tm_moves_list.append(line.rstrip("\n").rstrip("\r").rstrip(",").lstrip(" "))
			elif line.startswith("}"):
				move = 0
			
########## validate args

if not (0 < args["number"] <= 50):
	print("\nerror: invalid TM number '%s'" % args["number"])
	exit(0)

move = check_move(args["move"])
print("\nreplacing {0} with move {1}".format(tm_moves_list[args["number"]-1],move))

print("ok? (y/n)")
#yesno()

########## read species

learn_species = set([])

print("\nread list of species from: %s" % args["species"])
with open(args["species"], "r") as f:
	for line in f:
		line = line.rstrip("\n")
		species = check_species(line)
		learn_species.add(species)
		
print("found %s species" % len(learn_species))