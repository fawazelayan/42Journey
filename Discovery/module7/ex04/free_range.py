#!/usr/bin/env python3
import sys

if (len(sys.argv) == 3) :
    try :
        num1 = int(sys.argv[1])
        num2 = int(sys.argv[2])
        if num1 > num2 :
            print("\nFirst number is greater than the second, try again. ⚠️\n")
        else :
            arr = []
            for i in range(num1, num2 + 1) :
                arr.append(num1)
                num1 += 1
            print(f"\n Array = {arr}\n")
        
    except :
        print("\nOne or both values are not integers, try again. ⚠️\n")
else :
    print("\nNumber of parameters is not 2, try again. ⚠️\n")