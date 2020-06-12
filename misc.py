#!/usr/bin/python3

from config import pokeemerald_dir

def normalize_path(file_path):
	if "/" in pokeemerald_dir:
		file_path = file_path.replace("\\","/")
	elif "\\" in pokeemerald_dir:
		file_path = file_path.replace("/","\\")
	else:
		print("\nerror: could not determine path separator")
		exit(0)
		
	return file_path