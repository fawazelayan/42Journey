#!/usr/bin/env python3

num1 = input("\nGive me the first number: ")
num2 = input("Give me the second number: ")
try :
    num1 = int(num1)
    num2 = int(num2)
    print("\nThank you!\n")
    print(f"Addition:       {num1} + {num2} = {num1 + num2}")
    print(f"Subtraction:    {num1} - {num2} = {num1 - num2}")
    print(f"Multiplication: {num1} * {num2} = {num1 * num2}")
    if num2 == 0:
        print("Can not divide by zero, try again. ⚠️\n")
    else:
        print(f"Division:       {num1} / {num2} = {int(num1 / num2)}\n")
except :
    print("\nOne or both values are not an integer, try again. ⚠️\n")