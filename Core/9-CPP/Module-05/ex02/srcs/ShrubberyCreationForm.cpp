#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("SCF", 145, 137),
		target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("SCF", 145, 137),
		target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other),
		target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const std::string ShrubberyCreationForm::getTarget() const
{
	return this -> target;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);
	std::ofstream file;

	file.open((this -> target + "_shrubbery").c_str());
	if (!file.good())
	{
		std::cerr << "Could not open file" << std::endl;
		return;
	}

	file << "      @@@    " << std::endl;
    file << "     @@@@@   " << std::endl;
    file << "    @@@@@@@  " << std::endl;
    file << "   @@@@@@@@@ " << std::endl;
    file << "  @@@@@@@@@@@" << std::endl;
    file << " @@@@@@@@@@@@@" << std::endl;
    file << "@@@@@@@@@@@@@@@" << std::endl;
    file << "      |||     " << std::endl;

	file.close();
}