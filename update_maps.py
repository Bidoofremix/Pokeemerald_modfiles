#!/usr/bin/python3

import sys,os,shutil,argparse,time,filecmp,json,fileinput
from pathlib import Path
from config import pokeemerald_dir,vanilla_dir,slash
from misc import normalize_path
from deepdiff import DeepDiff

parser = argparse.ArgumentParser()
parser.add_argument("--mode", choices=["insert","backup"],\
	help="select mode")

args = vars(parser.parse_args())	

map_dir = normalize_path("{0}\data\maps".format(pokeemerald_dir))
layout_dir = normalize_path("{0}\data\layouts".format(pokeemerald_dir))
constants_dir = normalize_path("{0}\include\constants".format(pokeemerald_dir))

modfile_dir = normalize_path(os.getcwd() + "\\raw")
backup_dir = normalize_path(os.getcwd() + "\\raw_maps")
graphics_dir = normalize_path("{0}/graphics".format(backup_dir))
sound_dir = normalize_path("{0}/sound".format(backup_dir))

########## functions

def mod_to_backup(mod_path):
	return mod_path.replace(pokeemerald_dir,backup_dir)

def backup_to_mod(backup_path):
	return backup_path.replace(backup_dir,pokeemerald_dir)

def countdown():
	print("")
	for remaining in range(5, 0, -1):
		sys.stdout.write("\r")
		sys.stdout.write("close script in {:2d} ...".format(remaining))
		sys.stdout.flush()
		time.sleep(1)
	sys.stdout.write("\r")
	sys.stdout.flush()
	print("")

########## insert files before porymap

# vanilla: base DizzyEgg's battle_engine_v2
# mod: modifiable copy directory of battle_engine_v2
# backup: whole files in raw_maps/ for porymap
# mod_pieces: snippets of code in raw/

file_meta = {}

print(map_dir)

# insert to pokeemerald_mod
# all files that have been previously
# modified by Porymap

for folder in [map_dir,layout_dir,constants_dir]:

	for dir, subdirs, files in os.walk(folder):
	
			for fname in files:
			
				if fname in ["map_groups.json","map.json","layouts.json","map.bin","border.bin","connections.inc"]:
				
					relative_path = normalize_path("{0}\{1}".format(dir,fname).replace(pokeemerald_dir,""))
					
					mod_path = normalize_path("{0}{1}".format(pokeemerald_dir,relative_path))
					vanilla_path = normalize_path("{0}{1}".format(vanilla_dir,relative_path))
					backup_path = normalize_path("{0}{1}".format(backup_dir,relative_path))
					mod_pieces_path = normalize_path("{0}{1}".format(modfile_dir, relative_path))
					
					file_meta[relative_path] = {}
					file_meta[relative_path]["mod"] = {}
					file_meta[relative_path]["mod"]["size"] = Path(mod_path).stat().st_size
					file_meta[relative_path]["mod"]["path"] = mod_path
					file_meta[relative_path]["mod"]["mod_time"] = os.path.getmtime(mod_path)
					
					file_meta[relative_path]["vanilla"] = {}
					if not os.path.isfile(vanilla_path):
						file_meta[relative_path]["vanilla"]["path"] = ""
					else:
						file_meta[relative_path]["vanilla"]["path"] = vanilla_path
						file_meta[relative_path]["vanilla"]["size"] = Path(vanilla_path).stat().st_size
						file_meta[relative_path]["vanilla"]["path"] = vanilla_path
						file_meta[relative_path]["vanilla"]["mod_time"] = os.path.getmtime(vanilla_path)
						
					file_meta[relative_path]["backup"] = {}
					file_meta[relative_path]["mod_pieces"] = {}
					
					if os.path.isfile(backup_path):
						file_meta[relative_path]["backup"]["path"] = backup_path
					else:
						file_meta[relative_path]["backup"]["path"] = ""

					if os.path.isfile(mod_pieces_path):
						file_meta[relative_path]["mod_pieces"]["path"] = mod_pieces_path
					else:
						file_meta[relative_path]["mod_pieces"]["path"] = ""

########## custom maps

custom_files = []

for dir, subdirs, files in os.walk(backup_dir,sound_dir,graphics_dir):

		for fname in files:
		
			absolute_path = normalize_path("{0}/{1}".format(dir,fname))
			mod_path = backup_to_mod(absolute_path)
			if not fname.endswith((".aif",".png")) and not os.path.isfile(mod_path):
				custom_files.append(absolute_path)
			elif fname.endswith((".aif",".png")):
				custom_files.append(absolute_path)

########## insert files before porymap

if args["mode"] == "insert":

	print("\ncopy files for porymap")

	for file in file_meta:

		if file_meta[file]["backup"]["path"] != "":

			print(file)
		
			# disregard map-specific script files
			# otherwise porymap and modify_pokeemerald will both
			# modify them and updates will not be applied
			if file.endswith("/scripts.inc"):
				if file_meta[file]["mod_pieces"]["path"] != "":
					continue
			
			shutil.copyfile(file_meta[file]["backup"]["path"],\
				file_meta[file]["mod"]["path"])
			if file.endswith(("map.json","scripts.inc")):
				Path(file_meta[file]["mod"]["path"]).touch(exist_ok=True)
	
	# insert custom files
	for file in custom_files:
		mod_filename = backup_to_mod(file)
		folder = mod_filename.rsplit(slash,1)[0]
		print(mod_filename)
		if not os.path.isdir(folder):
			os.makedirs(folder)
		shutil.copy(file, mod_filename)
		Path(mod_filename).touch(exist_ok=True)
	
	print("done")
	
########## back up files after porymap

# clean up after porymap changes parameters
map_parameters = {}
map_parameters["allow_bike="] = "allow_cycling="
map_parameters["allow_escape_rope="] = "allow_escaping="
map_parameters["allow_run="] = "allow_running="

# compare all files against base battle_engine_v2
# and mod folder (pokeemerald_mod)
# to see what has been changed by Porymap
if args["mode"] == "backup":

	print("\nback up files")

	for file in file_meta:

		backup_this_file = 0
	
		# custom maps
		if file.rsplit(slash,1)[-1] in ["map.json","map.bin","border.bin","connections.inc"] and \
			file_meta[file]["vanilla"]["path"] == "":
				backup_this_file = 1
	
		# existing maps
		else:
			if (file_meta[file]["mod"]["size"] != file_meta[file]["vanilla"]["size"]):
				backup_this_file = 1
			
			if file.endswith((".inc",".bin")):
			
				# if file.endswith(".inc"):
					# with open(file_meta[file]["mod"]["path"], "r", encoding="utf-8") as f:
						# content = f.read()
				
					# if any([i in content for i in map_parameters]):
						# for p in map_parameters:
							# content = content.replace(p, map_parameters[p])
							
						# with open(file_meta[file]["mod"]["path"], "w", encoding="utf-8") as f:
							# f.write(content)
				
				if (filecmp.cmp(file_meta[file]["mod"]["path"],file_meta[file]["vanilla"]["path"], \
				shallow=False) == False):
					backup_this_file = 1
						
			if file.endswith(".json"):
				f1 = open(file_meta[file]["mod"]["path"], "r")
				f2 = open(file_meta[file]["mod"]["path"], "r")
				ddiff = DeepDiff(json.load(f1),json.load(f2),ignore_order=True)
				f1.close
				f2.close
				if ddiff != {}:
					backup_this_file = 1
		
		if backup_this_file:
			
			print(file)
			
			if file_meta[file]["backup"]["path"] == "":
				file_meta[file]["backup"]["path"] = mod_to_backup(file_meta[file]["mod"]["path"])
			backup_path = file_meta[file]["backup"]["path"]
			os.makedirs(os.path.dirname(backup_path), exist_ok=True)
			shutil.copy(file_meta[file]["mod"]["path"],backup_path)
			if file.endswith(("layouts.json","map.json","scripts.inc")):
				Path(file_meta[file]["mod"]["path"]).touch(exist_ok=True)
	print("done")

countdown()