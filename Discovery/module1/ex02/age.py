my_age = input("\nEnter your age: ")
try :
    my_age = int(my_age)
    print(f"\nAge after 42 years: {my_age + 42}\n")
except :
    print("\nValue is not an integer, try again. ⚠️\n")