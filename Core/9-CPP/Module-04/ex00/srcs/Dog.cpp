#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this -> type = "Dog";
	std::cout << "Dog default called\n";
}
Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy called\n";
}
Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
}
Dog &Dog::operator=(const Dog& other)
{
	if (this != &other)
		Animal::operator=(other);
	std::cout << "Assignment operator called\n";
	return *this;
}

void Dog::makeSound() const
{
	std::cout << type << " is barking\n";
}