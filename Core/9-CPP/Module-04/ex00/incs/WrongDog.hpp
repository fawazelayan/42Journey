#ifndef WRONG_DOG_HPP
# define WRONG_DOG_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongDog : public WrongAnimal
{
	public:
		WrongDog();
		~WrongDog();
		WrongDog(const WrongDog&);
		WrongDog &operator=(const WrongDog&);

		void makeSound() const;
};

#endif