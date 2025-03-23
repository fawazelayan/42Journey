#!/usr/bin/env python3

word = input()
uplow = ""
i = 0

while i < len(word) :
	if word[i] >= 'A' and word[i] <= 'Z' :
		uplow += word[i].lower()
	elif word[i] >= 'a' and word[i] <= 'z' :
		uplow += word[i].upper()
	else :
		uplow += word[i]
	i += 1
print(uplow)