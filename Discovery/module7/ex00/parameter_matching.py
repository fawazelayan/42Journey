#!/usr/bin/env python3
import sys

if len(sys.argv) == 2 :
	word = input("\nWhat was the parameter? ")
	if word == sys.argv[1] :
		print("\nGood job!\n")
	else :
		print("\nNope, sorry...\n")
else :		
	print("\nNumber of parameters is not 1, try again. ⚠️\n")