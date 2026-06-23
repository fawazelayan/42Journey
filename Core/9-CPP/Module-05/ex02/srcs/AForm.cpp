#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm()
	: name("Default Form"),
		isSigned(false),
		signGrade(150),
		execGrade(150) {}

AForm::AForm(const std::string& name, int signGrade, int execGrade)
	: name(name),
		isSigned(false),
		signGrade(signGrade),
		execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other)
	: name(other.name),
		isSigned(other.isSigned),
		signGrade(other.signGrade),
		execGrade(other.execGrade) {}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		this -> isSigned = other.isSigned;
	return *this;
}

AForm::~AForm() {}

const std::string AForm::getName() const
{
	return this -> name;
}

bool AForm::getIsSigned() const
{
	return this -> isSigned;
}

int AForm::getSignGrade() const
{
	return this -> signGrade;
}

int AForm::getExecGrade() const
{
	return this -> execGrade;
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << "Form: " << form.getName()
		<< ", signed: " << (form.getIsSigned() ? "yes" : "no")
		<< ", sign grade required: " << form.getSignGrade()
		<< ", execute grade required: " << form.getExecGrade();
	return os;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed!";
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this -> signGrade)
		throw AForm::GradeTooLowException();
	this -> isSigned = true;
}

void AForm::execute(const Bureaucrat& executor) const
{
	if (!this -> isSigned)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this -> execGrade)
		throw AForm::GradeTooLowException();
}