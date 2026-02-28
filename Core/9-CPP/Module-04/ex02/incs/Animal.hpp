#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal&);
		virtual ~Animal();
		Animal &operator=(const Animal&);

		virtual void makeSound() const = 0;
		std::string getType() const;
		void setType(const std::string);
};

#endif