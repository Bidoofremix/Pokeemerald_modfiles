#!/usr/bin/python3

from config import pokeemerald_dir

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