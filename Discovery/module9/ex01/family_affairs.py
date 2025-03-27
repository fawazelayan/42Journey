#!/usr/bin/env python3
def find_the_redheads(my_dict) :
    arr = []
    for key, value in my_dict.items() :
        if value == "red" :
            arr.append(key.capitalize())
    return arr

dupont_family = {
    "florian": "red",
    "marie": "blond",
    "virginie": "brunette",
    "david": "red",
    "franck": "red"
}

print(f"\nRed heads: {find_the_redheads(dupont_family)}\n")