#!/usr/bin/env python3
import sys
import re

if len(sys.argv) == 3 :
	num = len(re.findall(sys.argv[1], sys.argv[2]))
	if num == 0 :
		print("\nDid not find any occurences.\n")
	else :
		print(f"\nNumber of occurences: {num}\n")
else :
	print("\nNumber of parameters is not 3, try again. ⚠️\n")