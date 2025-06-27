#include "Utils.hpp"

std::string	addValidInfo(std::string prompt)
{
	std::string info;

	while (1)
	{
		std::cout << PRP << prompt << RST;
	
		std::getline(std::cin, info);
		if (info == "EXIT")
			break;
		else if (!info.empty() && info != "SEARCH" && info != "ADD")
			break;	
		else if (info.empty() || info == "SEARCH" || info == "ADD")
		{
			std::cout << RED
				<< "\nField can't be empty or use reserved commands"
				<< " (ADD or SEARCH), "
				<< "please re-enter "
				<< prompt.substr(6, prompt.length() - 8)
				<< ".\n\n" << RST;
		}
	}
	return info;
}

std::string	truncate(const std::string& str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void	drawTable(const int index,
				const std::string& first, const std::string& last,
				const std::string& nick)
{
	if (index == 0)
	{
		std::cout << CYN << std::endl;
		std::cout << "|" << std::setw(10) << "Index" << "|"
			<< std::setw(10) << "First Name" << "|"
			<< std::setw(10) << "Last Name" << "|"
			<< std::setw(10) << "Nickname" << "|"
			<< std::endl << RST;
	}

	std::cout << CYN << "|" << std::setw(10) << index << "|"
		<< std::setw(10) << truncate(first) << "|"
		<< std::setw(10) << truncate(last) << "|"
		<< std::setw(10) << truncate(nick) << "|"
		<< std::endl << RST;
}

void	displayInfo(const std::string& first, const std::string& last,
					const std::string& nick, const std::string& num,
					const std::string& secret)
{
	std::cout << BLU << "\nFirst name: " << first << std::endl
		<< "Last name: " << last << std::endl
		<< "Nickname: " << nick << std::endl
		<< "Phone Number: " << num << std::endl
		<< "Darkest Secret: " << secret << std::endl << RST;
}

int	searchValidIndex(int& index, const int count)
{
	std::string input;

	while (1)
	{
		std::cout << PRP <<"\nPlease enter an index in the range 0-"
			<< count - 1 << ": " << RST;
		std::getline(std::cin, input);
		if ((input.length() == 1 && isdigit(input[0])))
		{
			index = input[0] - '0';
			if (index >= 0 && index < count)
				break;
			else
				std::cout << RED << "\nInvalid range.\n" << RST;
		}
		else if (input == "EXIT")
			return 1;
		else if (input == "SEARCH" || input == "ADD")
		{
			std::cout << RED << "\nInput can't be a reserved command"
				<< " (ADD or SEARCH).\n"
				<< RST;
		}
		else
			std::cout << RED << "\nInput is not a single positive digit.\n" << RST;
	}
	return 0;
}