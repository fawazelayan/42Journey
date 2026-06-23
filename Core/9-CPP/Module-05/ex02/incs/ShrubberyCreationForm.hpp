#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string target;

		// Private constructor
		ShrubberyCreationForm();

	public:
		// Constructors & Destructor
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		// Getters
		const std::string getTarget() const;

		// Action
		void execute(const Bureaucrat& executor) const;
};

#endif