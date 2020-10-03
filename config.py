#!/usr/bin/python3
#!-*- encoding: utf-8 -*-

import os,sys

dirname, filename = os.path.split(os.path.abspath(__file__))

#base_dir = "C:\\Users\Miro\Documents\Pokeemerald\pokeemerald_june20"

if "/" in dirname:
	slash = "/"
elif "\\" in dirname:
	slash = "\\"

base_dir = dirname.rsplit(slash,1)[0]
#pokeemerald_dir = "{0}{1}pokeemerald_mod".format(base_dir,slash)
#vanilla_dir = "{0}{1}pokeemerald".format(base_dir,slash)
#pokeemerald_dir = "{0}{1}pokeemerald_expanded_mod_030820".format(base_dir,slash)
#vanilla_dir = "{0}{1}pokeemerald_expanded_030820".format(base_dir,slash)

pokeemerald_dir = "{0}{1}pokeemerald_expanded_mod_031020".format(base_dir,slash)
vanilla_dir = "{0}{1}pokeemerald_expanded_031020".format(base_dir,slash)

raw_dir = "{0}{1}raw".format(os.getcwd(),slash)

for dir in [pokeemerald_dir,vanilla_dir]:
	if not os.path.isdir(dir):
		print("\nerror: did not find directory: %s" % dir)
		exit(0)

