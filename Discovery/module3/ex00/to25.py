#!/usr/bin/env python3

num = input("\nEnter a number less than 25: ")
try :
	num = int(num)
	if num > 25 :
		print("\nNumber is larger than 25, try again. ⚠️\n")
	else :
		print()
		while num <= 25 :
			print(f"Inside the loop, my variable is {num}.")
			num += 1
		print()
except :
	print("\nValue is not an integer, try again. ⚠️\n")