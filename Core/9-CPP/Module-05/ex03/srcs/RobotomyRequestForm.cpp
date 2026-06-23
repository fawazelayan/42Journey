#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RRF", 72, 45),
		target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RRF", 72, 45),
		target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other),
		target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

const std::string RobotomyRequestForm::getTarget() const
{
	return this -> target;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);

	std::cout << "drrrrrr....." << std::endl;
	if (rand() % 2 == 0)
		std::cout << this -> target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this -> target << " has not been robotomized successfully" << std::endl;
}