#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>

class AForm;

class Intern
{
	private:
		AForm* createShrubbery(const std::string& target) const;
		AForm* createRobotomy(const std::string& target) const;
		AForm* createPresidential(const std::string& target) const;

	public:
		// Constructors & Destructor
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		// Form Operations
		AForm* makeForm(const std::string& formName, const std::string& target);
};

#endif
