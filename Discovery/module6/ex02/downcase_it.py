#!/usr/bin/env python3
import sys

if len(sys.argv) == 2 :
	print(f"\nFirst parameter lowered: {sys.argv[1].lower()}\n")
else :
	print("\nNumber of parameters is 0 or more than 1, try again. ⚠️\n")