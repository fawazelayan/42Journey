#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <exception>
#include <iosfwd>

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool isSigned;
		const int signGrade;
		const int execGrade;

		// Private constructor
		Form();

	public:
		// Constructors & Destructor
		Form(const std::string& name, int signGrade, int execGrade);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		// Getters
		const std::string getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;

		// Form Actions
		void beSigned(const Bureaucrat& bureaucrat);

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

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif