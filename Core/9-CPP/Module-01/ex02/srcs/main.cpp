#include <iostream>
#include <string>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string	&strREF = str;
	std::string	*strPTR;

	strPTR = &str;

	std::cout << '\n' << &str << '\n'
					<< strPTR << '\n'
					<< &strREF << "\n";

	std::cout << '\n' << str << '\n'
					<< *strPTR << '\n'
					<< strREF << "\n\n";

	return 0;
}