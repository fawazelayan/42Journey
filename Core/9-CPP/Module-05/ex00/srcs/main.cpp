#include <iostream>
#include "Bureaucrat.hpp"

// Test normal creation and grade increment/decrement
void testNormalBureaucrat()
{
	std::cout << "\n=== Test 1: Normal Bureaucrat ===" << std::endl;
	try
	{
		// Create a valid bureaucrat and try incrementing/decrementing their grade
		Bureaucrat b1("John", 2);
		std::cout << "Created: " << b1 << std::endl;

		b1.incrementGrade();
		std::cout << "After Increment: " << b1 << std::endl;

		b1.decrementGrade();
		std::cout << "After Decrement: " << b1 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected Exception: " << e.what() << std::endl;
	}
}

// Test exception when grade is too high (< 1) on construction
void testTooHighOnConstruction()
{
	std::cout << "\n=== Test 2: Grade Too High on Construction ===" << std::endl;
	try
	{
		// Attempting to create a bureaucrat with grade 0
		Bureaucrat b("TooHigh", 0);
		std::cout << "This should not print: " << b << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "Caught expected GradeTooHighException: " << e.what() << std::endl;
	}
}

// Test exception when grade is too low (> 150) on construction
void testTooLowOnConstruction()
{
	std::cout << "\n=== Test 3: Grade Too Low on Construction ===" << std::endl;
	try
	{
		// Attempting to create a bureaucrat with grade 151
		Bureaucrat b("TooLow", 151);
		std::cout << "This should not print: " << b << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "Caught expected GradeTooLowException: " << e.what() << std::endl;
	}
}

// Test exception when incrementing grade 1
void testTooHighOnIncrement()
{
	std::cout << "\n=== Test 4: Grade Too High on Increment ===" << std::endl;
	try
	{
		// Attempting to increment past grade 1
		Bureaucrat b("Boss", 1);
		std::cout << "Created: " << b << std::endl;
		std::cout << "Attempting to increment grade 1..." << std::endl;
		b.incrementGrade();
		std::cout << "This should not print: " << b << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "Caught expected GradeTooHighException: " << e.what() << std::endl;
	}
}

// Test exception when decrementing grade 150
void testTooLowOnDecrement()
{
	std::cout << "\n=== Test 5: Grade Too Low on Decrement ===" << std::endl;
	try
	{
		// Attempting to decrement past grade 150
		Bureaucrat b("Intern", 150);
		std::cout << "Created: " << b << std::endl;
		std::cout << "Attempting to decrement grade 150..." << std::endl;
		b.decrementGrade();
		std::cout << "This should not print: " << b << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "Caught expected GradeTooLowException: " << e.what() << std::endl;
	}
}

// Test Orthodox Canonical Form (copy constructor and assignment operator)
void testOrthodoxCanonicalForm()
{
	std::cout << "\n=== Test 6: Orthodox Canonical Form Checks ===" << std::endl;
	
	std::cout << "--- Sub-test 6a: Copy Constructor ---" << std::endl;
	Bureaucrat original("Original", 42);
	std::cout << "Original: " << original << std::endl;

	Bureaucrat copy(original);
	std::cout << "Copy:     " << copy << " (Should have same name and grade)" << std::endl;

	std::cout << "\n--- Sub-test 6b: Copy Assignment Operator ---" << std::endl;
	Bureaucrat target("Target", 100);
	std::cout << "Before Assignment:" << std::endl;
	std::cout << "Target:   " << target << std::endl;
	std::cout << "Original: " << original << std::endl;

	// Assign original to target
	target = original;
	std::cout << "After Assignment (target = original):" << std::endl;
	std::cout << "Target:   " << target << " (Should keep its original name but have original's grade)" << std::endl;
	std::cout << "Original: " << original << std::endl;
}

int main(void)
{
	// Run all test cases
	testNormalBureaucrat();
	testTooHighOnConstruction();
	testTooLowOnConstruction();
	testTooHighOnIncrement();
	testTooLowOnDecrement();
	testOrthodoxCanonicalForm();

	return 0;
}