#!/usr/bin/python3

import sys,os,shutil,argparse,textwrap,xlrd,xlsxwriter
from config import pokeemerald_dir
from misc import *
from pokemon_tools import *

snippet_folder = normalize_path(os.getcwd() + "\\file_snippet")
full_folder = normalize_path(os.getcwd() + "\\file_full")

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

########## modify excel files

pokemon_excels = [i for i in os.listdir("pokemon") if i.startswith("pokemon_") and i.endswith(".xlsx")]

print("\nmodifying TM learnsets")

for file in pokemon_excels:

	print(file)

	file = "pokemon/{0}".format(file)
	read_workbook = xlrd.open_workbook(file)
	
	write_workbook = xlsxwriter.Workbook(file + ".tmp")
	cell_format = write_workbook.add_format({'align': "left"})	
	
	for n,i in enumerate(read_workbook.sheet_names()):
		read_sheet = read_workbook.sheet_by_index(n)
		write_sheet = write_workbook.add_worksheet(i)
		write_sheet.set_column(0,0,20,cell_format)
		write_sheet.set_column(1,1,35,cell_format)
		write_sheet.set_column(2,2,None,cell_format)
		
		tmp_species = "SPECIES_%s" % i
		if tmp_species in learn_species:
			species = i
			
		bst = 0		
			
		for i in range(0,read_sheet.nrows):
			row = [clean_num(cell.value) for cell in read_sheet.row(i)]
			if row[0].startswith(".base"):
				bst += row[1]
			for j,cell in enumerate(row):
				write_sheet.write(i, j, cell)
				
		write_sheet.write_formula("C2","=SUM(B2:B7)", value=bst)		
				
	write_workbook.close()