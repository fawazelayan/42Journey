#!/usr/bin/env python3
def add_one(num) :
    num["mod"] += 1
#################################################
# def add_one(num) :
#   num += 1
#num = int(input("Enter a num: "))
#print(num)
#add_one(num)                        ORIGINAL CODE IN SUBJECT
#print(num)                                  
################################################
# What do i observe? is that the number is passed by value.
# Taking a copy of the parameter instead of the actual address.
# So how do we make the function change the value in the main?
# We either use a list or the dictionary or return the value and reassign it.

num = {"mod": input("\nEnter a number: ")}
try :
    num["mod"] = int(num["mod"])
    print(f"\nNumber before calling the method = {num["mod"]}")
    add_one(num)
    print(f"Number after calling the method = {num["mod"]}\n")
except :
    print("\nValue is not an integer, try again. ⚠️\n")