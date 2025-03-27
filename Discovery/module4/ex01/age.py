#!/usr/bin/env python3

age = input("\nPlease tell me your age: ")
years = 10
try :
    age = int(age)
    print("\nYou are currently", age, "years old.\n")
    while years <= 30 :
        print(f"In {years} years, you'll be, {age + years} old.")
        years += 10
    print()
except :
    print("\nValue is not an integer, try again. ⚠️\n")