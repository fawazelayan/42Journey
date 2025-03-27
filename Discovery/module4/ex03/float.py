#!/usr/bin/env python3

num = input("\nGive me a number: ")
try :
	num = float(num)
	if num == int(num) :
		print("\nThis number is an integer.\n")
	else :
		print("\nThis number is a decimal.\n")
except :
	print("\nValue is neither a float or integer, try again. ⚠️\n")