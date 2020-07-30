#!/usr/bin/python3

import os,xlsxwriter,json
from config import vanilla_dir
from misc import normalize_path

wrk_dir = os.getcwd()

raw_folder = normalize_path(wrk_dir + "/raw")

print("script disabled, modify source to re-enable run")
exit(0)

########## vanilla encounter data

encounter_file = normalize_path("{0}/src/data/wild_encounters.json".format(vanilla_dir))

with open(encounter_file, "r") as f:
	wild_data = json.load(f)

for category in wild_data["wild_encounter_groups"]:
	if category["label"] == "gWildMonHeaders":
		route_data = category
		
encounter_slots = {}
for i in route_data["fields"]:
	encounter_slots[i["type"]] = i["encounter_rates"]
	if i["type"] == "fishing_mons":
		fishing_groups = i["groups"]
	
########## write to excel	
	
outfile = normalize_path("wild_data/wild_data.xlsx")
workbook = xlsxwriter.Workbook(outfile)

top = workbook.add_format({"top":1})
left_justify = workbook.add_format({'align': "left"})

duplicate_mapnames = {}
cols_per_biome = 5
max_rows_per_biome = len(encounter_slots["land_mons"])

for route in sorted(route_data["encounters"], key=lambda x: x["map"]):
	print(route["map"])
	sheet_name = route["base_label"][1:30]
	
	if sheet_name not in duplicate_mapnames:
		duplicate_mapnames[sheet_name] = 1
	else:
		duplicate_mapnames[sheet_name] += 1
		sheet_name += str(duplicate_mapnames[sheet_name])
	
	worksheet = workbook.add_worksheet(sheet_name)
	row = 0
	
	for i in range(0,4):
		worksheet.set_column(i*6,i*6,4,left_justify)
		worksheet.set_column((i*6)+1,(i*6)+1,13)
		worksheet.set_column((i*6)+2,(i*6)+3,4)
		
	worksheet.write(row,0,"map")
	worksheet.write(row,1,route["map"])
	row += 1
	
	worksheet.write(row,0,"base_label")
	worksheet.write(row,1,route["base_label"])
	row += 2
	
	mon_row = row
	
	# land, water and rock smash mons
	col = 0
	for biome in ["land_mons","water_mons", "rock_smash_mons"]:

		row = mon_row
		worksheet.write(row,col,biome)
		row += 1
		
		worksheet.write(row,col,"slot", top)
		worksheet.write(row,col+1,"species", top)
		worksheet.write(row,col+2,"min", top)
		worksheet.write(row,col+3,"max", top)
		worksheet.write(row,col+4,"encounter_rate", top)
		row += 1

		for slot in encounter_slots[biome]:
			worksheet.write(row,col,slot)
			row += 1
		
		if biome in route:
			row = mon_row+2
			worksheet.write(row,col+4,route[biome]["encounter_rate"])

			for mon in route[biome]["mons"]:
				worksheet.write(row,col+1,mon["species"].replace("SPECIES_",""))
				worksheet.write(row,col+2,mon["min_level"])
				worksheet.write(row,col+3,mon["max_level"])
				row += 1

		col += cols_per_biome+1

	row += max_rows_per_biome+1
	mon_row = row
	
	# fishing mons
	col = 0
	for rod in ["old_rod","good_rod","super_rod"]:
	
		row = mon_row
	
		worksheet.write(row,col,rod)
		row += 1
	
		worksheet.write(row,col,"slot",top)
		worksheet.write(row,col+1,"species",top)
		worksheet.write(row,col+2,"min",top)
		worksheet.write(row,col+3,"max",top)
		worksheet.write(row,col+4,"encounter_rate",top)
		row += 1
		
		for slot in [encounter_slots["fishing_mons"][i] for i in fishing_groups[rod]]:
				worksheet.write(row,col,slot)
				row += 1
		
		if "fishing_mons" in route:
				
			row = mon_row+2
			worksheet.write(row,col+4,route["fishing_mons"]["encounter_rate"])
	
			mons = [route["fishing_mons"]["mons"][i] for i in fishing_groups[rod]]
				
			row = mon_row+2	
			for mon in mons:
				worksheet.write(row,col+1,mon["species"].replace("SPECIES_",""))
				worksheet.write(row,col+2,mon["min_level"])
				worksheet.write(row,col+3,mon["max_level"])
				row += 1
		
		col += cols_per_biome+1
		
		
workbook.close()