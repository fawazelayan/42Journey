#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog default called\n";
	this -> type = "Dog";
	this -> brain = new Brain();
}
Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy called\n";
	this -> brain = new Brain(*other.brain);
}
Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called\n";
}
Dog &Dog::operator=(const Dog& other)
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

void Dog::makeSound() const
{
	std::cout << type << " is barking\n";
}