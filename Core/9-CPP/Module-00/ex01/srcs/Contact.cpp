#include "Contact.hpp"

void Contact::setFirstName(const std::string& first)
{
	this -> firstName = first;
}

void Contact::setLastName(const std::string& last)
{
	this -> lastName  = last;
}

void Contact::setNickname(const std::string& nick)
{
	this -> nickname = nick;
}

void Contact::setPhoneNumber(const std::string& num)
{
	this -> phoneNumber = num;
}

void Contact::setDarkestSecret(const std::string& secret)
{
	this -> darkestSecret = secret;
}

std::string Contact::getFirstName(void) const
{
	return this -> firstName;
}

std::string Contact::getLastName(void) const
{
	return this -> lastName;
}
std::string Contact::getNickname(void) const
{
	return this -> nickname;
}

std::string Contact::getPhoneNumber(void) const
{
	return this -> phoneNumber;
}

std::string Contact::getDarkestSecret(void) const
{
	return this -> darkestSecret;
}
