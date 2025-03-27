#!/usr/bin/env python3
def greetings(name = "noble stranger") :
    match name :
        case _  if isinstance(name, str): print(f"Hello, {name}.")
        case _ : print("Not a valid name, try again. ⚠️")

print("\nSending a name: ", end = "")
greetings("Fawaz")
print("Sending an empty string: ", end = "")
greetings("")
print("Sending an integer value: ", end = "")
greetings(1)
print("Sending a float value: ", end = "")
greetings(1.2)
print("Sending nothing: ", end = "")
greetings()
print()