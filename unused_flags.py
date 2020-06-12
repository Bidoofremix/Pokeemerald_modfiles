#!/usr/bin/python

import os
from config import pokeemerald_dir

flag_file = os.path.normpath("{0}\include\constants\\flags.h".format(pokeemerald_dir))

with open(flag_file, "r") as f:
	lines = f.read().splitlines()
	
special_flags_started = 0
unused_flags = []
used_flags = []

for line in lines:
	if line.startswith("#define SPECIAL_FLAGS_START"):
		special_flags_started = 1
	else:
		if line.startswith("#define FLAG_UNUSED"):
			if not special_flags_started:
				unused_flags.append(line)
		elif line.startswith("#define FLAG") and not line.startswith("#define FLAG_UNUSED"):
			used_flags.append(line)
			
print("found {0} flags, of which:".format(len(unused_flags)+len(used_flags)))
print(" %s used" % len(used_flags))
print(" %s unused" % len(unused_flags))

new_lines = [line for line in lines if line not in unused_flags]

########## rearrange file

# 134 to add total number of trainers to 1000
new_trainer_flags = 134

print("\nof unused flags, allocate:")
print(" %s for trainers" % new_trainer_flags)
print(" %s for other things" % (len(unused_flags)-new_trainer_flags))

non_trainer_flags = unused_flags[:-134]
trainer_flags = unused_flags[-134:]

print(len(non_trainer_flags)+len(trainer_flags))

for n,line in enumerate(new_lines):
	if line.startswith("#define TRAINER_FLAGS_START"):
		trainer_flags_started = n
		break
		
new_lines[n:n]
		
