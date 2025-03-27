#!/usr/bin/env python3

num1 = input("\nEnter the first number: ")
num2 = input("Enter the second number: ")
try :
	num1 = int(num1)
	num2 = int(num2)
	res = num1 * num2
	print(f"\n{num1} x {num2} = {res}\n")
	if res > 0 :
		print("The result is positive.\n")
	elif res < 0 :
		print("The result is negative.\n")
	else :
		print("The result is positive and negative.\n")
except :
	print("\nOne or both values are not integers, try again. ⚠️\n")