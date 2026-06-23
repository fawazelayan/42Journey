#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iosfwd>

class Form;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;

		// Private constructor
		Bureaucrat();

	public:
		// Constructors & Destructor
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		// Getters
		const std::string getName() const;
		int getGrade() const;

		// Grade Modifiers
		void incrementGrade();
		void decrementGrade();

		// Form Operations
		void signForm(Form& form);

		// Exception Classes
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bur);

#endif