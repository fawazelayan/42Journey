#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
		const std::string target;

		// Private constructor
		RobotomyRequestForm();

	public:
		// Constructors & Destructor
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		// Getters
		const std::string getTarget() const;

		// Action
		void execute(const Bureaucrat& executor) const;
};

#endif