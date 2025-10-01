#include <iostream>
#include <string>
#include <cctype>

namespace mine	// Demonstrates understanding of namespaces.
{
	std::string	toupper(std::string str);
}
// TRY std::toupper(static_cast<unsigned char>str[i]) at campus
std::string	mine::toupper(std::string str)	// My own toupper function.
{
	for(unsigned int i = 0; str[i]; i++)
		str[i] = std::toupper(str[i]); // STD version of toupper in <cctype> not in <ctype.h>
	return (str);
}

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 0;
	}
	for (unsigned int i = 1; av[i]; i++)
		std::cout << mine::toupper(av[i]);
	std::cout << '\n';
	return 0;
}

// Reason why sending char * to std::string works is because:
// std::string is an object that has a constructor that takes const char * to make it as a string.
// Implicit conversion.