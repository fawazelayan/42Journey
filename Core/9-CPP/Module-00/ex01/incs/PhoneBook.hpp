#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		count;
		int		next;
	public:
		// Constructor
		PhoneBook();
		
		// Command functions
		int searchContact(void) const;
		int addContact(void);

		// Getters
		int	getCount(void) const;
		int getNext(void) const;
};

#endif