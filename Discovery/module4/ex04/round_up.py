#!/usr/bin/env python3

num = float(input("Give me a number: "))
if num == int(num) :
	print(int(num))
else :
	num = int(num)
	num += 1
	print(num)