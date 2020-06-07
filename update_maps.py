#!/usr/bin/python

import os,shutil,argparse
from pathlib import Path
from config import pokeemerald_dir,vanilla_dir

parser = argparse.ArgumentParser()
parser.add_argument("--mode", choices=["insert","backup"],\
	help="select mode")

args = vars(parser.parse_args())	

map_dir = "{0}\data\maps".format(pokeemerald_dir)
layout_dir = "{0}\data\layouts".format(pokeemerald_dir)

backup_dir = os.getcwd() + "\\raw_maps"

########## functions

def mod_to_backup(mod_path):
	return mod_path.replace(pokeemerald_dir,backup_dir)

########## insert files before porymap

file_meta = {}

for folder in [map_dir,layout_dir]:
	for dir, subdirs, files in os.walk(folder):
			for fname in files:
				
				relative_path = "{0}\{1}".format(dir,fname).replace(pokeemerald_dir,"")
				file_meta[relative_path] = {}
				
				mod_path = "{0}{1}".format(pokeemerald_dir,relative_path)
				vanilla_path = "{0}{1}".format(vanilla_dir,relative_path)
				backup_path = "{0}{1}".format(backup_dir,relative_path)
				
				file_meta[relative_path]["mod"] = {}
				file_meta[relative_path]["mod"]["size"] = Path(mod_path).stat().st_size
				file_meta[relative_path]["mod"]["path"] = mod_path
				file_meta[relative_path]["mod"]["mod_time"] = os.path.getmtime(mod_path)
				
				file_meta[relative_path]["vanilla"] = {}
				file_meta[relative_path]["vanilla"]["size"] = Path(vanilla_path).stat().st_size
				file_meta[relative_path]["vanilla"]["path"] = vanilla_path
				file_meta[relative_path]["vanilla"]["mod_time"] = os.path.getmtime(vanilla_path)
				
				file_meta[relative_path]["backup"] = {}
				file_meta[relative_path]["backup"]["path"] = ""
				
				if os.path.exists(backup_path):
					file_meta[relative_path]["backup"] = {}
					file_meta[relative_path]["backup"]["path"] = backup_path
				
			
########## insert files before porymap

if args["mode"] == "insert":

	print("\ncopy files for porymap")

	for file in file_meta:
		if file_meta[file]["backup"]["path"] != "":
			print(file)
			shutil.copyfile(file_meta[file]["backup"]["path"],\
				file_meta[file]["mod"]["path"])
				
	print("done")
	
########## back up files after porymap

if args["mode"] == "backup":

	print("\nback up files")
	
	for file in file_meta:
		if (file_meta[file]["mod"]["size"] != file_meta[file]["vanilla"]["size"]) \
			or (file_meta[file]["mod"]["mod_time"] != file_meta[file]["vanilla"]["mod_time"]):
			print(file)
			if file_meta[file]["backup"]["path"] == "":
				file_meta[file]["backup"]["path"] = mod_to_backup(file_meta[file]["mod"]["path"])
			backup_path = file_meta[file]["backup"]["path"]
			os.makedirs(os.path.dirname(backup_path), exist_ok=True)
			shutil.copy(file_meta[file]["mod"]["path"],backup_path)
	print("done")