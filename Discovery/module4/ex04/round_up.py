#!/usr/bin/env python3
import math

num = input("\nGive me a number: ")
try :
	num = float(num)
	if num == int(num) :
		print(f"\nValue is already rounded up = {int(num)}\n")
	else :
		print(f"\nOriginal value = {num}")
		print(f"Rounded up value = {math.ceil(num)}\n")
except :
	print("\nValue is neither a float or integer, try again. ⚠️\n")

###########################################
	# if num == int(num) :
	#	print(int(num))
	#elif num > 0 :
	#	num = int(num)
	#	num += 1
	#	print(num)
	#else :
	#	num = int(num)						ORIGINAL CODE I WROTE BEFORE USING math.ceil()
	#	print(num)
##########################################