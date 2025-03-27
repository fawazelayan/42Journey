#!/usr/bin/env python3
def array_of_names(my_dict) :
    arr = []
    for key, value in my_dict.items() :
        key = key.capitalize()
        value = value.capitalize()
        arr.append(f"{key} {value}")
    return arr

persons = {
    "jean": "valjean",
    "grace": "hopper",
    "xavier": "niel",
    "fifi": "brondacier" 
}
print(f"\nArray of names: {array_of_names(persons)}\n")