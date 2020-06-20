#!/usr/bin/python

import os,re,argparse
from config import pokeemerald_dir,vanilla_dir,raw_dir
from misc import normalize_path,dec2hex,hex2dec

########## argparse

parser = argparse.ArgumentParser()

parser.add_argument("--force", action="store_true",\
	help="force rearrangement of custom flag file")
parser.add_argument("--trainers", type=int, required=True,\
	help="how many new trainer flags")
parser.add_argument("--daily", type=int, default=0,\
	help="how many new daily flags")
	
args = vars(parser.parse_args())	
	
########## get vanilla number of trainers

opponents_file = normalize_path("{0}/include/constants/opponents.h".format(vanilla_dir))
with open(opponents_file, "r") as f:
	for line in f:
		if "MAX_TRAINERS_COUNT" in line:
			num_trainers = int(line.rstrip("\n").rstrip("\r").split()[2])
	
########## open flag file

modified_flag_file = normalize_path("{0}/include/constants/flags.h".format(raw_dir))

if os.path.isfile(modified_flag_file):
	if not args["force"]:
		print("\nERROR: modified flag file detected at:")
		print(modified_flag_file)
		print("\nif you really want to rearrange the flags again, use option --force")
		print("exit run")
		exit(0)
	else:
		flag_file = modified_flag_file
		using_modded_file = 1
else:
	flag_file = normalize_path("{0}\include\constants\\flags.h".format(pokeemerald_dir))
	using_modded_file = 0
	
output_flag_file = modified_flag_file
	
print("reads flags from: %s" % flag_file)

with open(flag_file, "r") as f:
	lines = f.read().splitlines()
	
special_flags_started = 0
unused_flags = []
used_flags = []

for line in lines:
	if line.startswith("#define DAILY_FLAGS_START"):
		special_flags_started = 1
	else:
		if line.startswith("#define FLAG_UNUSED") and not "MYSTERY_GIFT" in line:
			if not special_flags_started:
				unused_flags.append(line)
		elif line.startswith("#define FLAG") and not line.startswith("#define FLAG_UNUSED"):
			used_flags.append(line)
			
print("\nfound {0} flags, of which:".format(len(unused_flags)+len(used_flags)))
print(" %s used" % len(used_flags))
print(" %s unused" % len(unused_flags))

new_lines = [line for line in lines if line not in unused_flags]

########## print summary to screen

# 134 to add total number of trainers to 1000
new_trainer_flags = args["trainers"]
new_num_trainers = num_trainers + new_trainer_flags

if args["trainers"] <= len(unused_flags):
	pass
else:
	print("\nerror: cannot allocate {0} flags for trainers ({1} available)".format(\
		args["trainers"],len(unused_flags)))
	print("exited run")
	exit(0)
	
print("\nof unused flags, allocate:")
print(" {0} for trainers ({1} -> {2})".format(new_trainer_flags,num_trainers,\
	new_num_trainers))
print(" %s for other things" % (len(unused_flags)-new_trainer_flags))

non_trainer_flags = unused_flags[:-new_trainer_flags]
trainer_flags = unused_flags[-new_trainer_flags:]

########## insert non-trainer flags after temp flags

for n,line in enumerate(new_lines):
	if "#define TEMP_FLAGS_END" in line:
		insert_index = n+1
		break

non_trainer_flags.insert(0,"")
new_lines[insert_index:insert_index] = non_trainer_flags

########## renumber flag offsets
		
flag_pattern = r'#define ([^\s]+) +(0[xX][0-9a-fA-F]+)'
flag_start_sum_pattern = r'#define ([^\s]+) +\((.+) \+ ((0x)?[0-9a-fA-F]+)'		
		
flag_offsets = {}
		
running_flag_no = 0
temp_flags_ended = 0
flags_inserted = 0
for n,line in enumerate(new_lines):

	relative_definition = False

	if line.startswith("#define"):

		# all other lines than trainer flag end and badge number
		if not line.startswith(("#define TRAINER_FLAGS_END","#define NUM_BADGES")):
			re_match = re.match(flag_start_sum_pattern,line)

			# relative definitions
			if re_match:
				flag = re_match.group(1)
				relative_to_flag = re_match.group(2)
				flag_offset = re_match.group(3)
				relative_definition = True
				
			# absolute definitions
			else:
				re_match = re.match(flag_pattern,line)
				if re_match:
					flag = re_match.group(1)
					flag_offset = re_match.group(2)
			
			if re_match:

				if relative_definition:
					if flag_offset.startswith("0x"):
						increment = hex2dec(flag_offset)
					else:
						increment = int(flag_offset)
					calculated_flag_no = hex2dec(flag_offsets[relative_to_flag]) + \
						increment
				
				else:
					calculated_flag_no = hex2dec(flag_offset)

				if calculated_flag_no != running_flag_no:
					line = line.replace(" %s" % flag_offset,\
						" %s" % dec2hex(running_flag_no))
					new_lines[n] = line
				
				flag_offsets[flag] = dec2hex(running_flag_no)
				# exceptions to flag start definitions
				# to comply with original logic
				if flag not in ["FLAG_HIDDEN_ITEMS_START"]:
					running_flag_no += 1

		elif line.startswith("#define TRAINER_FLAGS_END"):
		
			running_flag_no = hex2dec(flag_offsets["TRAINER_FLAGS_START"]) + \
				new_num_trainers - 1
			flag_offsets["TRAINER_FLAGS_END"] = dec2hex(running_flag_no)
			
		# definition of badge number
		# no offset here so no need to modify this
		elif line.startswith("#define NUM_BADGES"):
			pass

########## raw snippet for trainer count

opponents_file = normalize_path("{0}/include/constants/opponents.h".format(raw_dir))

if os.path.isfile(opponents_file):
	print("\ndetected opponents.h, modify existing")
	opponents_file_lines = []
	with open(opponents_file, "r") as f:
		for line in f:
			opponents_file_lines.append(line)
			
	for n,line in enumerate(opponents_file_lines):
		if line.startswith("#R#define MAX_TRAINERS_COUNT"):
			tmp_count = line.split()[-1]
			line = line.replace(tmp_count,str(new_num_trainers))
			opponents_file_lines[n] = line

else:
	print("did not detect opponents.h, create new")
	opponents_file_lines = []
	opponents_file_lines.append("< //\n")
	opponents_file_lines.append("#define MAX_TRAINERS_COUNT                  864\n")
	opponents_file_lines.append("#R#define MAX_TRAINERS_COUNT                  {0}\n".format(\
		new_num_trainers))
	opponents_file_lines.append("\n")	
	opponents_file_lines.append("#endif  // GUARD_CONSTANTS_OPPONENTS_H\n")
	opponents_file_lines.append("// >\n")

with open(opponents_file, "w") as f:
	for line in opponents_file_lines:
		f.write(line)
			
########## write to file

with open(output_flag_file, "w") as f:
	if not using_modded_file:
		f.write("< //\n")
	for line in new_lines:
		f.write(line + "\n")
	if not using_modded_file:
		f.write("// >\n")
		
print("\nwrote rearranged flags to: %s" % output_flag_file)

