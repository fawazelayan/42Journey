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
	int levelIndex = -1;
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
			levelIndex = i;
			break;
		}
	}
	switch (levelIndex)
	{
	case 0:
		std::cout << "[ DEBUG ]\n";
		(this ->*funcs[0])();
		std::cout << '\n';
		/* FALLTHROUGH */
	case 1:
		std::cout << "[ INFO ]\n";
		(this ->*funcs[1])();
		std::cout << '\n';
		/* FALLTHROUGH */
	case 2:
		std::cout << "[ WARNING ]\n";
		(this ->*funcs[2])();
		std::cout << '\n';
		/* FALLTHROUGH */
	case 3:
		std::cout << "[ ERROR ]\n";
		(this ->*funcs[3])();
		std::cout << '\n';
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]\n";
		break;
	}
}