#include "Contact.hpp"

void Contact::setFirstName(const std::string& first)
{
	firstName = first;
}

void Contact::setLastName(const std::string& last)
{
	lastName  = last;
}

void Contact::setNickname(const std::string& nick)
{
	nickname = nick;
}

void Contact::setPhoneNumber(const std::string& num)
{
	phoneNumber = num;
}

void Contact::setDarkestSecret(const std::string& secret)
{
	darkestSecret = secret;
}

std::string Contact::getFirstName(void) const
{
	return firstName;
}

std::string Contact::getLastName(void) const
{
	return lastName;
}
std::string Contact::getNickname(void) const
{
	return nickname;
}

std::string Contact::getPhoneNumber(void) const
{
	return phoneNumber;
}

std::string Contact::getDarkestSecret(void) const
{
	return darkestSecret;
}
