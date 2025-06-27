#include "PhoneBook.hpp"
#include "Utils.hpp"

int	main(void)
{
	std::string	cmd;
	PhoneBook	book;

	std::cout << YLW
			<< "\nPlease enter one of these commands: ADD, SEARCH, EXIT\n"
			<< RST;

	std::getline(std::cin, cmd);

	while (cmd != "EXIT")
	{
		if (cmd == "ADD")
		{
			if (book.addContact())
				break ;
		}
		else if (cmd == "SEARCH")
		{
			if (book.searchContact())
				break ;
		}
		std::cout << YLW
			<< "\nPlease enter one of these commands: ADD, SEARCH, EXIT\n"
			<< RST;
		std::getline(std::cin, cmd);
	}
	std::cout << GRN << "\nThanks for using PhoneBook!\n\n" << RST;
	return (0);
}
