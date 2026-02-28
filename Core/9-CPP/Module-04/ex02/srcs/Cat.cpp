#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat default called\n";
	this -> type = "Cat";
	this -> brain = new Brain();
}
Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy called\n";
	this -> brain = new Brain(*other.brain);
}
Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called\n";
}
Cat &Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		if (this -> brain)
			delete this -> brain;
		this -> brain = new Brain(*other.brain);
	}
	std::cout << "Assignment operator called\n";
	return *this;
}

void Cat::makeSound() const
{
	std::cout << type << " is meowing\n";
}