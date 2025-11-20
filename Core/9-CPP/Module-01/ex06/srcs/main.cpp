#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "\nUsage: ./harl <level>\n\n";
		return 1;
	}
	Harl man;
	std::string com(av[1]);

	std::cout << '\n';
	man.complain(com);

	return 0;
}