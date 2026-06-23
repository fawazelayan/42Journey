#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private:
		const std::string target;

		// Private constructor
		PresidentialPardonForm();

	public:
		// Constructors & Destructor
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		// Getters
		const std::string getTarget() const;

		// Action
		void execute(const Bureaucrat& executor) const;
};

#endif