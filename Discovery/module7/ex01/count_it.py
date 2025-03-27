#!/usr/bin/env python3
import sys

num = len(sys.argv)
if num >= 2 :
	print(f"\nNumber of Parameters: {num - 1}\n")
	for i in range(1, num) :
		print(f"Length of parameter \"{sys.argv[i]}\": {len(sys.argv[i])}")
	print()
else :
	print("\nNumber of parameters is 0, try again. ⚠️\n")