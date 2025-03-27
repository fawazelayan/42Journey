#!/usr/bin/env python3
import sys

if len(sys.argv) == 2 :
	print(f"\nFirst parameter uppered: {sys.argv[1].upper()}\n")
else :
	print("\nNumber of parameters is 0 or more than 1, try again. ⚠️\n")