#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Test program for dynamic_cast identification.
// Generates random subclass instances, then identifies their actual
// class type using both pointer-based and reference-based overloads.
int main()
{
	std::srand(std::time(NULL));

	std::cout << "Generating 5 random objects and identifying them:\n\n";
	for (int i = 0; i < 5; ++i)
	{
		std::cout << "--- Test " << (i + 1) << " ---\n";
		Base* ptr = generate();
		if (ptr)
		{
			std::cout << "Identify via pointer: ";
			identify(ptr);

			std::cout << "Identify via reference: ";
			identify(*ptr);

			delete ptr;
		}
		std::cout << "\n";
	}
	return 0;
}