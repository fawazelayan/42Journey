#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "DEBUGGING HARL\n";
}

void Harl::info(void)
{
	std::cout << "INFO OF HARL\n";
}

void Harl::warning(void)
{
	std::cout << "WARNING HARL\n";
}

void Harl::error(void)
{
	std::cout << "ERROR FROM HARL\n";
}

void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*funcs[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*funcs[i])();
			return ;
		}
	}
	std::cout << "NO LEVEL FOUND\n";
}