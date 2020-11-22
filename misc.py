#!/usr/bin/python3

from config import pokeemerald_dir


def yesno():
	answer = input(">> ")
	while not answer.lower() in ["y","yes","n","no"]:
		answer = input(">> ")
	if answer.lower() in ["n","no"]:
		exit(0)

##########

def write_lines(file,line_list):
	with open(file, "w", encoding="utf-8") as f:
		for line in line_list:
			f.write(line)
	print("wrote to: %s" % file)

def lines_to_chunks(lines):
	chunks = []
	for n,line in enumerate(lines):
		if line.startswith("< //"):
			start_index = n
		elif line.startswith("// >"):
			chunks.append(lines[start_index:n+1])
	return chunks	

def normalize_path(file_path):
	if "/" in pokeemerald_dir:
		file_path = file_path.replace("\\","/")
	elif "\\" in pokeemerald_dir:
		file_path = file_path.replace("/","\\")
	else:
		print("\nerror: could not determine path separator")
		exit(0)
		
	return file_path
	
def dec2hex(num):
	return "0x" + hex(num)[2:].upper()
	
def hex2dec(hex_num):
	return int(hex_num,16)
	
def clean_text(text):
	text = text.replace("\\xe2\\x80\\x99","")
	text = text.replace("\\xc3\\xa9","é")
	text = text.encode("utf-8").decode("utf-8")
	return text
	
def clean_move(move):
	return " ".join([i.capitalize() for i in \
		move.replace("MOVE_","").split("_")])
	
def clean_num(num):
	if isinstance(num,int):
		return int(num)
	if isinstance(num,float):
		try:
			return int(num)
		except ValueError:
			return float(num)
	else:
		return str(num)
	
########## 

def excel_files(mons):
	pokemon_excels = []
	mon_per_file = 100
	how_many_excels = (len(mons) // mon_per_file) + 1
	for i in range(1,how_many_excels+1):

		if i == 0:
			suffix = "1-{0}".format(i*mon_per_file)
		else:
			suffix = "{0}-{1}".format(((i-1)*mon_per_file)+1,i*mon_per_file)

		pokemon_excels.append(normalize_path("pokemon/pokemon_{0}.xlsx".format(suffix)))

	return pokemon_excels