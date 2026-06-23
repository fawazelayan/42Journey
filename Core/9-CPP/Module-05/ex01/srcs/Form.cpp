#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <ostream>

Form::Form()
	: name("Default Form"),
		isSigned(false),
		signGrade(150),
		execGrade(150) {}

Form::Form(const std::string& name, int signGrade, int execGrade)
	: name(name),
		isSigned(false),
		signGrade(signGrade),
		execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& other)
	: name(other.name),
		isSigned(other.isSigned),
		signGrade(other.signGrade),
		execGrade(other.execGrade) {}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		this -> isSigned = other.isSigned;
	return *this;
}

Form::~Form() {}

const std::string Form::getName() const
{
	return this -> name;
}

bool Form::getIsSigned() const
{
	return this -> isSigned;
}

int Form::getSignGrade() const
{
	return this -> signGrade;
}

int Form::getExecGrade() const
{
	return this -> execGrade;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form: " << form.getName()
		<< ", signed: " << (form.getIsSigned() ? "yes" : "no")
		<< ", sign grade required: " << form.getSignGrade()
		<< ", execute grade required: " << form.getExecGrade();
	return os;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this -> signGrade)
		throw Form::GradeTooLowException();
	this -> isSigned = true;
}