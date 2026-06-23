#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	// Seeding the random generator for Robotomy 50/50 chance
	srand(time(NULL));

	std::cout << "\n=======================================" << std::endl;
	std::cout << "1. Form Execution (Direct vs executeForm)" << std::endl;
	std::cout << "=======================================" << std::endl;
	Bureaucrat boss("Boss", 1);
	Bureaucrat intern("Intern", 150);
	ShrubberyCreationForm shrub("backyard");

	// Direct execution of unsigned form (should throw directly)
	try
	{
		shrub.execute(boss);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Caught expected exception (Direct execute unsigned): " << e.what() << std::endl;
	}

	// Sign form
	boss.signForm(shrub);

	// Direct execution by too low bureaucrat (should throw directly)
	try
	{
		shrub.execute(intern);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Caught expected exception (Direct execute grade too low): " << e.what() << std::endl;
	}

	// Direct execution by valid bureaucrat (should succeed)
	try
	{
		shrub.execute(boss);
		std::cout << "Direct execution succeeded!" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error during direct execute: " << e.what() << std::endl;
	}

	std::cout << "\n=======================================" << std::endl;
	std::cout << "2. Polymorphic Forms execution Tests" << std::endl;
	std::cout << "=======================================" << std::endl;

	// Instantiate forms polymorphically using base pointers
	AForm* forms[3];
	forms[0] = new ShrubberyCreationForm("park");
	forms[1] = new RobotomyRequestForm("robot_target");
	forms[2] = new PresidentialPardonForm("criminal_target");

	for (int i = 0; i < 3; ++i)
	{
		std::cout << "\n--- Processing: " << forms[i]->getName() << " ---" << std::endl;
		boss.signForm(*forms[i]);
		boss.executeForm(*forms[i]);
	}

	// Cleanup polymorphic array (Requires virtual destructor in AForm to prevent memory leaks)
	std::cout << "\nCleaning up polymorphic forms..." << std::endl;
	for (int i = 0; i < 3; ++i)
		delete forms[i];

	std::cout << "=======================================" << std::endl;
	return 0;
}