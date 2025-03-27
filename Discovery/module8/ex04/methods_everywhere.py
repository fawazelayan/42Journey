#!/usr/bin/env python3
import sys
def enlarge(word) :
        for i in range(len(word), 8) :
            word += 'Z'
        print(word)
def shrink(word) :
    print(word[:8])

if len(sys.argv) >= 2 :
    print("\nModified words: \n")
    for i in range(1, len(sys.argv)) :
        if len(sys.argv[i]) > 8 :
            shrink(sys.argv[i])
        elif len(sys.argv[i]) < 8 :
            enlarge(sys.argv[i])
        else :
            print(sys.argv[i])
    print()
else :
     print("\nNumber of parameters is 0, try again. ⚠️\n")