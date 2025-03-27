#!/usr/bin/env python3
import sys
def downcase_it(word) :
    return word.lower()

length = len(sys.argv)
if length >= 2 :
    print("\nLowered paramters: \n")
    for i in range(1, length) :
        print(f"{i}. {downcase_it(sys.argv[i])}")
    print()
else :
    print("\nNumber of parameters is 0, try again. ⚠️\n")