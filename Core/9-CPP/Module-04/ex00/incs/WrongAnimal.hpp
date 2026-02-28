#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal&);
		~WrongAnimal();
		WrongAnimal &operator=(const WrongAnimal&);

		void makeSound() const;
		std::string getType() const;
		void setType(const std::string);
};

#endif