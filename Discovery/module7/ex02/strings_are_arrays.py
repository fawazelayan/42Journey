#!/usr/bin/env python3
import sys

counter = 0
if len(sys.argv) == 2 :
	print("\nOccurences: ", end = "")
	for char in sys.argv[1] :
		if char == 'z' :
			counter += 1
			print('z', end = "")
	if counter == 0 :
		print("Zero occurences of \'z\'.", end = "")
	print("\n")
else :
	print("\nNumber of parameters is not 1, try again. ⚠️\n")