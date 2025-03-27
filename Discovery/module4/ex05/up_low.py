#!/usr/bin/env python3

word = input("\nEnter a word: ")
uplow = ""
i = 0
print(f"\nOriginal word: {word}")
while i < len(word) :
	if word[i] >= 'A' and word[i] <= 'Z' :
		uplow += chr(ord(word[i]) + 32)
	elif word[i] >= 'a' and word[i] <= 'z' :
		uplow += chr(ord(word[i]) - 32)
	else :
		uplow += word[i]
	i += 1
print(f"Modified word: {uplow}\n")