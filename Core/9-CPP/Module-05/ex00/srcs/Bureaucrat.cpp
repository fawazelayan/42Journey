#include "Bureaucrat.hpp"
#include <ostream>

Bureaucrat::Bureaucrat()
	: name("Default"),
		grade(150) {}
Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: name(name),
		grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: name(other.name),
		grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		this -> grade = other.grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string Bureaucrat::getName() const
{
	return this -> name;
}

int Bureaucrat::getGrade() const
{
	return this -> grade;
}

void Bureaucrat::incrementGrade()
{
	if (this -> grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this -> grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this -> grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this -> grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bur)
{
	os << bur.getName() << ", bureaucrat grade " << bur.getGrade();
	return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat: Grade too high (must be >= 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat: Grade too low (must be <= 150)";
}