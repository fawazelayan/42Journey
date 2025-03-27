#!/usr/bin/env python3
def famous_births(my_dict) :
    my_dict_sorted = sorted(my_dict.values(), key=lambda x: int(x["date_of_birth"]))
    for scientist in my_dict_sorted :
        print(f"{scientist['name']} is a great scientist born in {scientist['date_of_birth']}.")

women_scientists = {
    "ada": { "name": "Ada Lovelace", "date_of_birth": "1815" },
    "cecilia": { "name": "Cecila Payne", "date_of_birth": "1900" },
    "lise": { "name": "Lise Meitner", "date_of_birth": "1878" },
    "grace": { "name": "Grace Hopper", "date_of_birth": "1906" }
}
print("\nScientists sorted based on birth year:\n")
famous_births(women_scientists)
print()