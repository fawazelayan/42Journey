#!/usr/bin/env python3

getthat = input("\nWhat do you want to say? : ")
print()
while 1 :
	getthat = input("I got that! Anything else? : ")
	if getthat == "STOP" :
		print()
		break