#!/usr/bin/env python3

arr = [2, 8, 9, 48, 8, 22, -12, 2]
newarr = []
i = 0
print (f"\nOriginal array: {arr}")
while i < len(arr) :
	if arr[i] > 5 :
		newarr.append(arr[i] + 2)
	i += 1
print(f"New array: {newarr}\n")