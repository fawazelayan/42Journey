#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal default called\n";
}
Animal::Animal(const Animal& other)
{
	std::cout << "Animal copy called\n";
	*this = other;
}
Animal::~Animal()
{
	std::cout << "Animal destructor called\n";
}
Animal &Animal::operator=(const Animal& other)
{
	if (this != &other)
		this -> type = other.type;
	std::cout << "Assignment operator called\n";
	return *this;
}

void Animal::makeSound() const
{
	std::cout << type << " is animaling\n";
}

std::string Animal::getType() const
{
	return type;
}

void Animal::setType(const std::string type)
{
	this -> type = type;
}