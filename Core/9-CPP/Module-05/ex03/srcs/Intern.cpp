#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cctype>

Intern::Intern() {}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

Intern::~Intern() {}

AForm* Intern::createShrubbery(const std::string& target) const
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target) const
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string& target) const
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	std::string lowerFormName = formName;
	for (size_t i = 0; i < lowerFormName.length(); i++)
		lowerFormName[i] = std::tolower(lowerFormName[i]);

	std::string names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (Intern::*funcs[3])(const std::string&) const = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential
	};

	for (int i = 0; i < 3; i++)
		if (names[i] == lowerFormName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*funcs[i])(target);
		}

	std::cout << "Error: Form name '" << formName << "' is not recognized!" << std::endl;
	return NULL;
}