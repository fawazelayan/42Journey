#!/usr/bin/env python3

arr = [2, 8, 9, 48, 8, 22, -12, 2]
myset = set()
i = 0
print (f"\nOriginal array: {arr}")
while i < len(arr) :
	if arr[i] > 5 :
		myset.add(arr[i] + 2)
	i += 1
print(f"Modified array in set: {myset}\n")