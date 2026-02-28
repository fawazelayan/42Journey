#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal default called\n";
}
WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "WrongAnimal copy called\n";
	*this = other;
}
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called\n";
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
		this -> type = other.type;
	std::cout << "Assignment operator called\n";
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << type << " is animaling\n";
}

std::string WrongAnimal::getType() const
{
	return type;
}

void WrongAnimal::setType(const std::string type)
{
	this -> type = type;
}