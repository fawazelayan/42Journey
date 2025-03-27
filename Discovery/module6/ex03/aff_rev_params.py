#!/usr/bin/env python3
import sys

i = len(sys.argv)
if i > 2 :
	i -= 1
	print("\nReversed order:\n")
	while i >= 1 :
		print(sys.argv[i])
		i -= 1
	print()
else :
	print("\nNumber of parameters is less than 2, try again. ⚠️\n")