first_name = input("\nHey, what's your first name? : ").strip()
last_name = input("And your last name? : ").strip()
if first_name.isalpha() and last_name.isalpha() :
    whole_name = first_name.capitalize() + " " + last_name.capitalize()
    print(f"\nWell, pleased to meet you, {whole_name}.\n")
else :
    print("\nOne or both names are not valid, try again. ⚠️\n")