#!/usr/bin/env python3

arr = [2, 8, 9, 48, 8, 22, -12, 2]
i = 0
print ("Original array:", arr)
while i < len(arr) :
	arr[i] += 2
	i += 1
print("New array:",arr)