#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this -> type = "Cat";
	std::cout << "Cat default called\n";
}
Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy called\n";
}
Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
}
Cat &Cat::operator=(const Cat& other)
{
	if (this != &other)
		Animal::operator=(other);
	std::cout << "Assignment operator called\n";
	return *this;
}

void Cat::makeSound() const
{
	std::cout << type << " is meowing\n";
}