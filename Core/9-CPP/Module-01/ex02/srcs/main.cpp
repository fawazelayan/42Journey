#include <iostream>
#include <string>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string	&strRef = str;
	std::string	*strPtr;

	strPtr = &str;

	std::cout << '\n' << &str << '\n' << strPtr << '\n' << &strRef << "\n\n";
	std::cout << str << '\n' << *strPtr << '\n' << strRef << "\n\n";

	return 0;
}