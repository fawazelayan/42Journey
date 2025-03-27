#!/usr/bin/env python3

num = input("\nEnter a number: ")
try :
	num = int(num)
	if num == 0 :
		print("\nThis number is equal to zero.\n")
	else :
		print("\nThis number is different from zero.\n")
except :
	print("\nValue is not an integer, try again. ⚠️\n")