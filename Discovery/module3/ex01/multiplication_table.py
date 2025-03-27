#!/usr/bin/env python3

num = input("\nEnter a number: ")
try :
	num = int(num)
	table = 0
	print()
	while table <= 9 :
		print(f"{table} x {num} = {table * num}")
		table += 1
	print()
except :
	print("\nValue is not an integer, try again. ⚠️\n")