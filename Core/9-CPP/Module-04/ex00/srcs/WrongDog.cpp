#include "WrongDog.hpp"

WrongDog::WrongDog() : WrongAnimal()
{
	this -> type = "WrongDog";
	std::cout << "WrongDog default called\n";
}
WrongDog::WrongDog(const WrongDog& other) : WrongAnimal(other)
{
	std::cout << "WrongDog copy called\n";
}
WrongDog::~WrongDog()
{
	std::cout << "WrongDog destructor called\n";
}
WrongDog &WrongDog::operator=(const WrongDog& other)
{
	if (this != &other)
		WrongAnimal::operator=(other);
	std::cout << "Assignment operator called\n";
	return *this;
}

void WrongDog::makeSound() const
{
	std::cout << type << " is barking\n";
}