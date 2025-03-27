#!/usr/bin/env python3
def average(my_dict) :
    avg = 0
    counter = 0
    for key, value in my_dict.items() :
        avg += int(value)
        counter += 1
    avg /= counter
    return avg

class_3B = {
    "marine": 18,
    "jean": 15,
    "coline": 8,
    "luc": 9
}
class_3C = {
    "quentin": 17,
    "julie": 15,
    "marc": 8,
    "stephanie": 13
}
print(f"\nAverage for class 3B: {average(class_3B)}.")
print(f"Average for class 3C: {average(class_3C)}.\n")