#include "Harl.hpp"

int main()
{
	Harl man;

	std::cout << '\n';

	man.complain("DEBUG");
	man.complain("INFO");
	man.complain("WARNING");
	man.complain("ERROR");
	man.complain("WRONG");
	std::cout << '\n';

	return 0;
}