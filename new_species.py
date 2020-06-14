#!/usr/bin/python3

import os,xlrd
from config import vanilla_dir
from misc import normalize_path

raw_folder = normalize_path(os.getcwd() + "\\raw")

########## read new family-based order

family_order = []
order_file = "family_dex_order.txt"
with open(order_file, "r") as f:
	for line in f:
		line = line.rstrip("\n").rstrip("\r")
		if line != "":
			family_order.append(line)
		
print(len(family_order))

########## read excel with new mon data

new_species = {}

new_species_excel = "pokemon/new_species.xls"
xl_workbook = xlrd.open_workbook(new_species_excel)
xl_sheet = xl_workbook.sheet_by_index(0)

species_name = xl_sheet.cell(0,0).value

for i in range(1,xl_sheet.nrows):
	row = [c.value for c in xl_sheet.row(i)]
	if not row[0].startswith("."):
		if row[0] == "after":
			new_species[species_name] = {"where":row[0], "who":row[1]}

print(new_species)

########## insert new species to list

for n in new_species:
	who_index = family_order.index(new_species[n]["who"])
	if new_species[n]["where"] == "after":
		family_order.insert(who_index+1,n)
	elif new_species[n]["where"] == "before":
		family_order.insert(who_index,n)

print(family_order)

########## open files and create copy in raw

#species_file = normalize_path("{0}/include/constants/species.h".format(raw_folder))
species_file = normalize_path("test.txt".format(raw_folder))
with open(species_file, "w") as f:
	f.write("#ifndef GUARD_CONSTANTS_SPECIES_H\n")
	f.write("#define GUARD_CONSTANTS_SPECIES_H\n")
	f.write("\n")
	f.write("#define SPECIES_NONE 0\n")
	iter_round = 1
	for p in family_order:
		f.write("#define SPECIES_{0} {1}\n".format(p,iter_round))
		