#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal
{
	public:
		Cat();
		~Cat();
		Cat(const Cat&);
		Cat &operator=(const Cat&);

		void makeSound() const;
};

#endif