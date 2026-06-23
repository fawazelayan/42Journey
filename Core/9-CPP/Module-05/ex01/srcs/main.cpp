#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

// Test creating a valid Form and printing it
void testNormalForm()
{
	std::cout << "\n=== Test 1: Normal Form Construction & Printing ===" << std::endl;
	try
	{
		Form f1("Tax Form 1040", 50, 25);
		std::cout << f1 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected Exception: " << e.what() << std::endl;
	}
}

// Test constructor exceptions for invalid grade limits
void testFormExceptions()
{
	std::cout << "\n=== Test 2: Form Exceptions on Creation ===" << std::endl;
	try
	{
		std::cout << "Attempting to create Form with signGrade 0..." << std::endl;
		Form f1("InvalidSignForm", 0, 50);
	}
	catch (const Form::GradeTooHighException& e)
	{
		std::cout << "Caught expected GradeTooHighException: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "Attempting to create Form with execGrade 151..." << std::endl;
		Form f2("InvalidExecForm", 50, 151);
	}
	catch (const Form::GradeTooLowException& e)
	{
		std::cout << "Caught expected GradeTooLowException: " << e.what() << std::endl;
	}
}

// Test form signing with high and low grade bureaucrats
void testFormSigning()
{
	std::cout << "\n=== Test 3: Form Signing ===" << std::endl;
	
	Bureaucrat high("HighBureaucrat", 10);
	Bureaucrat low("LowBureaucrat", 120);
	Form f("Standard NDA", 50, 25);
	
	std::cout << high << std::endl;
	std::cout << low << std::endl;
	std::cout << f << std::endl;

	std::cout << "\n--- LowBureaucrat tries to sign (should fail) ---" << std::endl;
	low.signForm(f);
	std::cout << f << std::endl;

	std::cout << "\n--- HighBureaucrat tries to sign (should succeed) ---" << std::endl;
	high.signForm(f);
	std::cout << f << std::endl;
}

int main(void)
{
	// Run all test cases
	testNormalForm();
	testFormExceptions();
	testFormSigning();

	return 0;
}