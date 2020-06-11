#!/usr/bin/python3
#!-*- encoding: utf-8 -*-

import os
from pathlib import Path

#base_dir = "C:\\Users\Miro\Documents\Pokeemerald\pokeemerald_june20"
base_dir = str(Path(__file__).parent.absolute()).rsplit("/",1)[0]
pokeemerald_dir = "{0}/pokeemerald_mod".format(base_dir)
vanilla_dir = "{0}/pokeemerald".format(base_dir)

for dir in [pokeemerald_dir,vanilla_dir]:
	if not os.path.isdir(dir):
		print("\nerror: did not find directory: %s" % dir)
		exit(0)

