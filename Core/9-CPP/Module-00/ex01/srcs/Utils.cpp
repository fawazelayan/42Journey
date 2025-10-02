#include "Utils.hpp"

static bool	is_empty_string(const std::string& str)
{
	for(unsigned int i = 0; str[i]; i++)
	{
		if (!std::isspace(str[i]))
			return 0;
	}
	return 1;
}

std::string	addValidInfo(const std::string prompt, int& status)
{
	std::string	info;

	while (42)
	{
		std::cout << PRP << prompt << RST;
	
		if (!std::getline(std::cin, info))
		{
			status = 1;
			break ;
		}
		if (info == "EXIT")
			break;
		else if (!is_empty_string(info) && info != "SEARCH" && info != "ADD")
			break;	
		else if (is_empty_string(info) || info == "SEARCH" || info == "ADD")
		{
			std::cout << RED
				<< "\nField can't be empty or use reserved commands"
				<< " (ADD or SEARCH), "
				<< "please re-enter "
				<< prompt.substr(6, prompt.length() - 8) << ".\n\n" << RST;
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
		std::cout << CYN << "|" << std::setw(10) << "Index" << "|"
			<< std::setw(10) << "First Name" << "|"
			<< std::setw(10) << "Last Name" << "|"
			<< std::setw(10) << "Nickname" << "|\n" << RST;
	}

	std::cout << CYN << "|" << std::setw(10) << index << "|"
		<< std::setw(10) << truncate(first) << "|"
		<< std::setw(10) << truncate(last) << "|"
		<< std::setw(10) << truncate(nick) << "|\n" << RST;
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

	while (42)
	{
		std::cout << PRP <<"\nPlease enter an index in the range 0-"
			<< count - 1 << ": " << RST;
		if (!std::getline(std::cin, input))
			return 1;
		if ((input.length() == 1 && std::isdigit(input[0])))
		{
			index = input[0] - '0';
			if (index >= 0 && index < count)
				break;
			std::cout << RED << "\nInvalid range.\n" << RST;
		}
		else if (input == "EXIT")
			return -1;
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