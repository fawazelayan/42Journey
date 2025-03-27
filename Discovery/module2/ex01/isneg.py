#!/usr/bin/env python3

num = input("\nEnter a number: ")
try :
	num = int(num)
	if num < 0 :
		print("\nThis number is negative.\n")
	elif num > 0 :
		print("\nThis number is positive.\n")
	else :
		print("\nThis number is both positive and negative.\n")
except :
	print("\nValue is not an integer, try again. ⚠️\n")