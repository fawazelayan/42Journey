#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main(void)
{
	// Seed the random generator for Robotomy 50/50 chance
	srand(time(NULL));

	Bureaucrat boss("Boss", 1);
	Intern intern;

	std::cout << "\n=== Test 1: Create and Execute Shrubbery Creation Form ===" << std::endl;
	AForm* f1 = intern.makeForm("shrubbery creation", "garden");
	if (f1)
	{
		boss.signForm(*f1);
		boss.executeForm(*f1);
		delete f1;
	}

	std::cout << "\n=== Test 2: Create and Execute Robotomy Request Form ===" << std::endl;
	AForm* f2 = intern.makeForm("RoBoToMy ReQuEsT", "Bender");
	if (f2)
	{
		boss.signForm(*f2);
		boss.executeForm(*f2);
		delete f2;
	}

	std::cout << "\n=== Test 3: Create and Execute Presidential Pardon Form ===" << std::endl;
	AForm* f3 = intern.makeForm("PRESIDENTIAL PARDON", "Criminal");
	if (f3)
	{
		boss.signForm(*f3);
		boss.executeForm(*f3);
		delete f3;
	}

	std::cout << "\n=== Test 4: Create Invalid Form ===" << std::endl;
	AForm* f4 = intern.makeForm("unknown form", "Target");
	if (f4)
		delete f4;

	return 0;
}