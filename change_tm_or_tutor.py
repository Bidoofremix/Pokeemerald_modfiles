#!/usr/bin/python3

import sys,os,shutil,argparse,textwrap,xlrd,xlsxwriter,copy
from config import pokeemerald_dir
from misc import *
from pokemon_tools import *

snippet_folder = normalize_path(os.getcwd() + "\\file_snippet")
full_folder = normalize_path(os.getcwd() + "\\file_full")

########## argparse

parser = argparse.ArgumentParser()

parser.add_argument("--mode", choices=["tm","tutor"], required=True)
parser.add_argument("--number", type=int,\
	help="which TM to change")
parser.add_argument("--tutor", \
	help="which tutor move to replace")
parser.add_argument("--move", required=True,\
	help="which move to use instead")
parser.add_argument("--species", required=True,\
	help="list of species to learn the new move")
	
args = vars(parser.parse_args())

if args["mode"] == "TM":
	if not args["number"]:
		print("\nerror: use option --number with --mode tm")
		exit(0)
	if args["tutor"]:
		print("\nerror: cannot use option --tutor with --mode tm")
		exit(0)
	
if args["mode"] == "tutor":
	if not args["tutor"]:
		print("\nerror: use option --tutor with --mode tutor")
		exit(0)
	elif args["number"]:
		print("\nerror: cannot use option --tm with --mode tutor")
		exit(0)

########## mode tm

if args["mode"] == "tm":

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
			
	### validate args

	if not (0 < args["number"] <= 50):
		print("\nerror: invalid TM number '%s'" % args["number"])
		exit(0)

	move = check_move(args["move"])
	deleted_move = tm_moves_list[args["number"]-1]
	print("\nreplacing {0} with move {1}".format(deleted_move,move))

	print("ok? (y/n)")
	yesno()

	
	### move description

	modified_tm = "TM{0}".format(str(args["number"]).zfill(2))
	simple_move = move.replace("MOVE_","")
	long_new_tm = "ITEM_TM{0}_{1}".format(str(args["number"]).zfill(2),simple_move)
	long_old_tm = "ITEM_TM{0}_{1}".format(str(args["number"]).zfill(2),deleted_move.replace("MOVE_",""))
	simple_type = move_type(move).replace("TYPE_","").capitalize()

	move_descr_file = normalize_path("{0}/src/data/text/move_descriptions.h".format(\
				pokeemerald_dir))

	move_descr = []
	text = 0
	with open(move_descr_file, "r", encoding="utf-8") as f:
		for line in f:
			if clean_move(move).replace(" ","") in line and move_descr == []:
				text = 1
			elif text:
				line_copy = copy.deepcopy(line)
				line = line.rstrip("\n").rstrip("\r").strip().replace("\\n","").replace('");','').strip('"')
				if not ";" in line_copy:
					move_descr.append(line)
				else:
					move_descr.append(line)
					text = 0
					
	move_descr = " ".join(move_descr)
	move_descr = textwrap.wrap(move_descr,18)

	if not len(move_descr) == 3:
		print("\nerror: cannot use default description for %s" % replace_move)
		exit(0)

if args["mode"] == "tutor":
	
	# src/data/pokemon/tutor_learnsets.h
	tutor_file = normalize_path("{0}/src/data/pokemon/tutor_learnsets.h".format(\
		pokeemerald_dir))

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
	
	### validate args

	move = check_move(args["move"])
	deleted_move = check_move(args["tutor"])
	
	if not deleted_move in tutor_moves:
		print("\nerror: invalid tutor move '%s'" % args["tutor"])
		exit(0)
	
	print("\nreplacing {0} with move {1}".format(deleted_move,move))

	print("ok? (y/n)")
	yesno()
	
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

print("\nmodifying learnsets")

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
		
		write = True	
		tmp_species = "SPECIES_%s" % i
		bst = 0		
			
		for i in range(0,read_sheet.nrows):
			row = [clean_num(cell.value) for cell in read_sheet.row(i)]
			if row[0].startswith(".base"):
				bst += row[1]
			
			if args["mode"] == "tm":
				category = "TM_MOVE"
				func = check_tmmove
			elif args["mode"] == "tutor":
				category = "TUTOR_MOVE"
				func = check_move

			if row[0] == category:
				tmp_move = func(row[1])
				tmp_move = "MOVE_%s" % tmp_move.split("_",1)[1]
				if tmp_move == deleted_move:
					write = False
			
			if write:
				for j,cell in enumerate(row):
					write_sheet.write(i, j, cell)
					
		if tmp_species in learn_species:
			write_sheet.write(i+1,0,category)
			write_sheet.write(i+1,1,clean_move(move))
				
		write_sheet.write_formula("C2","=SUM(B2:B7)", value=bst)		
	
	write_workbook.close()
	
	os.replace("%s.tmp" % file, file)

########## modify other files

print("")

if args["mode"] == "tm":

	# include/constants/items.h
	lines = []
	with open(item_file, "r", encoding="utf-8") as f:
		for line in f:
			if line.count("ITEM_TM") > 1 and modified_tm in line:
				line = "#define ITEM_TM{0}_{1} ITEM_TM{0}\n".format(\
					args["number"],simple_move)
			lines.append(line)
			
	write_lines(item_file, lines)		
			
	# src/data/party_menu.h
	lines = []
	with open(party_menu_file, "r", encoding="utf-8") as f:
		for line in f:
			if not move:
				if line.startswith("static const u16 sTMHMMoves"):
					move = 1
			else:
				if deleted_move in line:
					line = "    %s,\n" % move	
				if line.startswith("}"):
					move = 0
			lines.append(line)
					
	write_lines(party_menu_file, lines)				
					
	# src/data/item_icon_table.h
	lines = []
	item_icon_file = normalize_path("{0}/src/data/item_icon_table.h".format(\
		snippet_folder))
	with open(item_icon_file, "r", encoding="utf-8") as f:
		for line in f:
			if "ITEM_{0}".format(modified_tm) in line:
				line = "    [ITEM_{0}] = {{gItemIcon_TM, gItemIconPalette_{1}TMHM}},\n".format(\
					modified_tm,simple_type)
			lines.append(line)

	write_lines(item_icon_file, lines)		
			
	# src/data/items.h
	lines = []
	src_item_file = normalize_path("{0}/src/data/items.h".format(\
		snippet_folder))
	with open(src_item_file, "r") as f:
		for line in f:
			if long_old_tm in line:
				line = line.replace(long_old_tm,long_new_tm)
			lines.append(line)

	write_lines(src_item_file,lines)		
			
	# src/data/text/item_descriptions.h
	lines = []
	descr_exists = False
	item_descr_file = normalize_path("{0}/src/data/text/item_descriptions.h".format(\
		snippet_folder))
	with open(item_descr_file, "r") as f:
		for line in f:
			lines.append(line)
			if modified_tm in line:
				descr_exists = True			
				
	if descr_exists:
		print("\nWARNING: item description exists in file:")
		print(item_descr_file)
		print("modify file manually")	
		
	else:
		if args["number"] != 1:
			tmp_lines = []
			tmp_lines.append("\n< //\n")
			tmp_lines.append("static const u8 s{0}Desc[] = _(\n".format(modified_tm))
			for line in move_descr[:-1]:
				tmp_lines.append('    "{0}\\n"\n'.format(line))
			tmp_lines.append('    "{0}");\n'.format(move_descr[-1]))
			tmp_lines.append("\n")
			tmp_lines.append("static const u8 sTM{0}Desc[] = _(\n".format(\
				str(args["number"]+1).zfill(2)))
			tmp_lines.append("// >\n")
			lines.extend(tmp_lines)
			
			write_lines(item_descr_file,lines,encoding="iso-8859-15")
		else:
			print("\nWARNING: cannot modify description for TM01")
			print("add description manually to this file:")
			print(item_descr_file)
			print("")
			[print(l) for l in move_descr]
			
if args["mode"] == "tutor":
	
	# src/data/pokemon/tutor_learnsets.h
	tutor_file = normalize_path("{0}/src/data/pokemon/tutor_learnsets.h".format(\
		snippet_folder))

	tutor = 0
	lines = []
	with open(tutor_file, "r", encoding="utf-8") as f:
		for line in f:
			if not tutor:
				lines.append(line)
				if line.startswith("const u16 gTutorMoves"):
					tutor = 1
			else:
				if deleted_move in line:
					line = "    [TUTOR_{0}] = {0},\n".format(move)
				lines.append(line)
				if line.startswith("}"):
					tutor = 0
					
	write_lines(tutor_file, lines)
	
	# include/constants/party_menu.h
	lines = []
	party_menu_file = normalize_path("{0}/include/constants/party_menu.h".format(\
		snippet_folder))
	with open(party_menu_file, "r", encoding="utf-8") as f:
		for line in f:
			if "TUTOR_%s" % deleted_move in line:
				line = line.replace(deleted_move, move)
			lines.append(line)
	
	write_lines(party_menu_file,lines)