#!/usr/bin/python3

import os,xlrd,argparse,re,shutil
from config import vanilla_dir
from misc import normalize_path

raw_folder = normalize_path(os.getcwd() + "\\raw")
raw_map_folder = normalize_path(os.getcwd() + "\\raw_maps")

########## argparse

parser = argparse.ArgumentParser()

parser.add_argument("--mapgroup", required=True, type=int,\
	choices=range(0,34), help="which map group")
parser.add_argument("--name", required=True,\
	help="map name")
parser.add_argument("--mapsection", required=True,\
	help="which map section")
	
args = vars(parser.parse_args())

########## variable names

map_group = "gMapGroup{0}".format(args["mapgroup"])

upper_underscore_name = re.findall('[A-Z][^A-Z]*', args["name"])
upper_underscore_name = "_".join([i.upper().strip("_") for i in upper_underscore_name])

layout_name = "LAYOUT_{0}".format(upper_underscore_name)


########## layouts.h

layouts_file = normalize_path("{0}/include/constants/layouts.h".format(raw_map_folder))
if not os.path.isfile(layouts_file):
	print("did not find layouts.h in raw folder, copied from base battle_engine_v2")
	vanilla_layouts_file = normalize_path("{0}/include/constants/layouts.h".format(vanilla_dir))
	shutil.copy(vanilla_layouts_file, layouts_file)
else:
	print("layouts.h detected, modify existing")
	
layouts_file_lines = []
with open(layouts_file, "r") as f:
	for line in f:
		layouts_file_lines.append(line)
		if line.startswith("#define"):
			if layout_name in line:
				print("\nerror: layout '%s' already defined" % layout_name)
				exit(0)
			last_defined = line
			
last_index = int(last_defined.split(" ")[2])
layouts_file_lines.insert(len(layouts_file_lines)-1,"#define LAYOUT_{0} {1}\n".format(\
	upper_underscore_name,last_index+1))
	
with open(layouts_file, "w") as f:
	for line in layouts_file_lines:
		f.write(line)

		
########## map groups file

mapgroups_file = normalize_path("{0}/data/maps/map_groups.json".format(raw_map_folder))
if not os.path.isfile(mapgroups_file):
	shutil.copy(normalize_path("{0}/data/maps/map_groups.json".format(vanilla_dir)),\
		mapgroups_file)
	print("did not find map_groups.json in raw maps folder, copied it from base battle_engine_v2")
else:
	print("detected map_groups.json, modify existing")

mapgroups_file_lines = []
with open(mapgroups_file, "r") as f:
	for line in f:
		mapgroups_file_lines.append(line)

# add new map to correct map group
found_map_group = 0
for i,line in enumerate(mapgroups_file_lines):
	if not found_map_group:
		if '"{0}":'.format(map_group) in line:
			found_map_group = 1
	elif found_map_group:
		# next map group or finished map groups
		if ": [" in line or "layouts_table_label" in line:
			insert_index = i
			break

mapgroups_file_lines[insert_index-2] = mapgroups_file_lines[i-2].replace("\n",",\n")
mapgroups_file_lines.insert(insert_index-1,'        "{0}"\n'.format(args["name"]))

with open(mapgroups_file, "w") as f:
	for line in mapgroups_file_lines:
		f.write(line)
		
########## layouts.json

layouts_json_file = normalize_path("{0}/data/layouts/layouts.json".format(raw_map_folder))
if not os.path.isfile(layouts_json_file):
	shutil.copy(normalize_path("{0}/data/layouts/layouts.json".format(vanilla_dir)),\
		layouts_json_file)
	print("did not find layouts.json in raw maps folder, copied it from base battle_engine_v2")
else:
	print("detected layouts.json, modify existing")

layouts_json_file_lines = []
with open(layouts_json_file, "r") as f:
	for line in f:
		layouts_json_file_lines.append(line)
		
for i,line in enumerate(layouts_json_file_lines):
	if line.endswith("},\n"):
		insert_index = i+1
		break

new_lines = []
new_lines.append("        {\n")
new_lines.append('            "blockdata_filepath": "data/layouts/{0}/map.bin",\n'.format(args["name"]))
new_lines.append('            "border_filepath": "data/layouts/{0}/border.bin",\n'.format(args["name"]))
new_lines.append('            "height": 9,\n')
new_lines.append('            "id": "LAYOUT_{0}",\n'.format(upper_underscore_name))
new_lines.append('            "name": "{0}_Layout",\n'.format(args["name"]))
new_lines.append('            "primary_tileset": "gTileset_Building",\n')
new_lines.append('            "secondary_tileset": "gTileset_GenericBuilding",\n')
new_lines.append('            "width": 10\n')
new_lines.append('        },\n')

layouts_json_file_lines[insert_index:insert_index] = new_lines

with open(layouts_json_file, "w") as f:
	for line in layouts_json_file_lines:
		f.write(line)
		
########## copy dummy bin files

new_layout_dir = "{0}/data/layouts/{1}".format(raw_map_folder,args["name"])
if not os.path.isdir(new_layout_dir):
	os.mkdir(new_layout_dir)
for file in ["map.bin","border.bin"]:
	shutil.copy(normalize_path("{0}/data/layouts/House1/{1}".format(\
		vanilla_dir,file)),"{0}/{1}".format(new_layout_dir,file))
		
new_map_dir = "{0}/data/maps/{1}".format(raw_map_folder,args["name"])
if not os.path.isdir(new_map_dir):
	os.mkdir(new_map_dir)
new_map_json_file = normalize_path("{0}/map.json".format(new_map_dir,args["name"]))
shutil.copy(normalize_path("default_map.json"), new_map_json_file)

########## make new map.json file
	
new_map_json_lines = []
with open(new_map_json_file, "r") as f:
	for line in f:
		new_map_json_lines.append(line)

for i,line in enumerate(new_map_json_lines):
	if '"id":' in line:
		new_map_json_lines[i] = '  "id": "MAP_{0}",\n'.format(upper_underscore_name)
	elif '"name":' in line:
		new_map_json_lines[i] = '  "name": "{0}",\n'.format(args["name"])
	elif '"layout":' in line:
		new_map_json_lines[i] = '  "layout": "LAYOUT_{0}",\n'.format(upper_underscore_name)
	elif '"region_map_section":' in line:
		new_map_json_lines[i] = '  "region_map_section": "{0}",\n'.format(args["mapsection"])

with open(new_map_json_file, "w") as f:
	for line in new_map_json_lines:
		f.write(line)

########## make new scripts.inc file

new_scripts_file = normalize_path("{0}/scripts.inc".format(new_map_dir))
with open(new_scripts_file, "w") as f:
	f.write("{0}_MapScripts::\n".format(args["name"]))
	f.write("\tmap_script MAP_SCRIPT_ON_TRANSITION, {0}_OnTransition\n".format(args["name"]))
	f.write("\t.byte 0\n")
	f.write("\n")
	f.write("{0}_OnTransition:\n".format(args["name"]))
	f.write("\nend")
	f.write("\n")
	
########## event_scripts.s	

event_scripts_file = normalize_path("{0}/data/event_scripts.s".format(raw_folder))
if not os.path.isfile(event_scripts_file):
	with open(event_scripts_file, "w") as f:
		f.write("< //\n")
		f.write('\t.include "data/maps/Route124_DivingTreasureHuntersHouse/scripts.inc"\n')
		f.write("\n\n")
		f.write('\t.include "data/scripts/std_msgbox.inc"\n')
		f.write("// >\n")
	print("did not find event_scripts.s in raw folder, created a new one")

event_scripts_file_lines = []
with open(event_scripts_file, "r") as f:
	for line in f:
		event_scripts_file_lines.append(line)

event_scripts_file_lines.insert(-3,'\t.include "data/maps/{0}/scripts.inc"\n'.format(\
	args["name"]))

with open(event_scripts_file, "w") as f:
	for line in event_scripts_file_lines:
		f.write(line)