#!/usr/bin/env python3
import sys

num = len(sys.argv)
if num >= 2 :
	print("\nModified words:\n")
	for i in range(1, num) :
		match sys.argv[i] :
			case _ if sys.argv[i].endswith("ism"): continue
			case _: sys.argv[i] += "ism"
		print(sys.argv[i])
	print()
else :
	print("\nNumber of parameters is 0, try again. ⚠️\n")