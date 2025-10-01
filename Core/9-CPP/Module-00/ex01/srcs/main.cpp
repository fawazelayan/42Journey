#include "PhoneBook.hpp"
#include "Utils.hpp"

int	main(void)
{
	std::string	cmd;
	int			status;
	PhoneBook	phoneBook;

	while (42)
	{
		std::cout << YLW << "\nPlease enter one of these commands: ADD, SEARCH, EXIT\n" << RST;
		if (!std::getline(std::cin, cmd))
		{
			std::cout << RED << "\nEOF detected, exiting..\n\n" << RST;
			return 1;
		}
		if (cmd == "ADD")
		{
			if (phoneBook.getCount() < 8)
				std::cout << GRN << "\nAdding contact number: " << phoneBook.getCount() + 1 << "\n\n" << RST;
			else
				std::cout << GRN << "\nReplacing contact number: " << phoneBook.getNext() + 1 << "\n\n" << RST;
			status = phoneBook.addContact();
			if (status == 1)
			{
				std::cout << RED << "\n\nEOF detected, exiting..\n\n" << RST;
				return 1;
			}
			else if (status == -1)
				break;
		}
		else if (cmd == "SEARCH")
		{
			std::cout << GRN << "\nSearching phonebook..\n\n" << RST;
			status = phoneBook.searchContact();
			if (status == 1)
			{
				std::cout << RED << "\n\nEOF detected, exiting..\n\n" << RST;
				return 1;
			}
			else if (status == -1)
				break;
		}
		else if (cmd == "EXIT")
				break;
		else
		{
			if (cmd[0])
				std::cout << '\n';
			std::cout << RED << "Wrong command\n" << RST;
		}
	}
	std::cout << GRN << "\nThanks for using PhoneBook!\n\n" << RST;
	return 0;
}
