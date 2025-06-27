#include "PhoneBook.hpp"
#include "Utils.hpp"

PhoneBook::PhoneBook() : count(0), next(0) {}

int	PhoneBook::addContact(void)
{
	std::string info;

	std::cout << std::endl;
	info = addValidInfo("Enter first name: ");
	if (info == "EXIT")
		return (1);
	contacts[next].setFirstName(info);

	info = addValidInfo("Enter last name: ");
	if (info == "EXIT")
		return (1);
	contacts[next].setLastName(info);

	info = addValidInfo("Enter nickname: ");
	if (info == "EXIT")
		return (1);
	contacts[next].setNickname(info);

	info = addValidInfo("Enter phone number: ");
	if (info == "EXIT")
		return (1);
	contacts[next].setPhoneNumber(info);

	info = addValidInfo("Enter darkest secret: ");
	if (info == "EXIT")
		return (1);
	contacts[next].setDarkestSecret(info);

	std::cout << GRN << "\nContact number: "
		<< next + 1
		<<" has been filled.\n" << RST;

	next = (next + 1) % 8;
	if (count < 8)
		count++;
	return (0);
}

int	PhoneBook::searchContact(void) const
{
	int index = -1;
	std::string input;

	if (count == 0)
	{
		std::cout << RED <<"\nPhone book is empty, nothing to display.\n" << RST;
		return (0);
	}

	for (int i = 0; i < count; i++)
	{
		drawTable(i, contacts[i].getFirstName(),
					contacts[i].getLastName(),
					contacts[i].getNickname());
	}

	if (searchValidIndex(index, count))
		return (1);

	displayInfo(contacts[index].getFirstName(), contacts[index].getLastName(),
				contacts[index].getNickname(), contacts[index].getPhoneNumber(),
				contacts[index].getDarkestSecret());
	return (0);
}