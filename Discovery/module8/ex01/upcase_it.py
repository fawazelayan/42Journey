#!/usr/bin/env python3
def upcase_it(word) :
    return word.upper()

word = input("\nEnter a word to be upcased: ")
print(f"\nOriginal word: {word}")
print(f"Upcased word: {upcase_it(word)}\n")