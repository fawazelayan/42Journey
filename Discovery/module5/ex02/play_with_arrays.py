#!/usr/bin/env python3

arr = [2, 8, 9, 48, 8, 22, -12, 2]
i = 0
print (arr)
while i < len(arr) :
	if arr[i] > 5 :
		arr[i] += 2
		i += 1
	else :
		arr.remove(arr[i])
print(arr)