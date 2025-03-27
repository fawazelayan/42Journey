#!/usr/bin/env python3

num = 0
table = 0
print()
while num <= 10 :
	print(f"Table of {num}: ", end = "")
	while table <= 10 :
		print (f"{num * table} ", end = "")
		table += 1
	table = 0;
	num += 1
	print()
print()