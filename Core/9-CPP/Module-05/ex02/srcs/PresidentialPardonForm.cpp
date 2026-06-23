#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PPFORM", 25, 5),
		target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PPFORM", 25, 5),
		target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm("PPFORM", 25, 5),
		target(other.target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

const std::string PresidentialPardonForm::getTarget() const
{
	return this -> target;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);
	std::cout << this -> target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}