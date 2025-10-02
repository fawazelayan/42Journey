#include "PhoneBook.hpp"
#include "Utils.hpp"

PhoneBook::PhoneBook() : count(0), next(0) {}

int	PhoneBook::getCount(void) const
{
	return count;
}

int	PhoneBook::getNext(void) const
{
	return next;
}

int	PhoneBook::addContact(void)
{
	std::string	info;
	int			status = 0;

	info = addValidInfo("Enter first name: ", status);
	if (info == "EXIT")
		return -1;
	if (status == 1)
		return 1;
	contacts[next].setFirstName(info);

	info = addValidInfo("Enter last name: ", status);
	if (info == "EXIT")
		return -1;
	if (status == 1)
		return 1;
	contacts[next].setLastName(info);

	info = addValidInfo("Enter nickname: ", status);
	if (info == "EXIT")
		return -1;
	if (status == 1)
		return 1;
	contacts[next].setNickname(info);

	info = addValidInfo("Enter phone number: ", status);
	if (info == "EXIT")
		return -1;
	if (status == 1)
		return 1;
	contacts[next].setPhoneNumber(info);

	info = addValidInfo("Enter darkest secret: ", status);
	if (info == "EXIT")
		return -1;
	if (status == 1)
		return 1;
	contacts[next].setDarkestSecret(info);

	std::cout << GRN << "\nContact number: "
		<< next + 1
		<<" has been filled.\n" << RST;

	next = (next + 1) % 8;
	if (count < 8)
		count++;
	return 0;
}

int	PhoneBook::searchContact(void) const
{
	int	index = -1;
	int	status = 0;

	if (!count)
	{
		std::cout << RED <<"Phone book is empty, nothing to display.\n" << RST;
		return 0;
	}

	for (int i = 0; i < count; i++)
	{
		drawTable(i, contacts[i].getFirstName(),
					contacts[i].getLastName(),
					contacts[i].getNickname());
	}

	status = searchValidIndex(index, count);
	if (status)
		return status;

	displayInfo(contacts[index].getFirstName(), contacts[index].getLastName(),
				contacts[index].getNickname(), contacts[index].getPhoneNumber(),
				contacts[index].getDarkestSecret());
	return 0;
}