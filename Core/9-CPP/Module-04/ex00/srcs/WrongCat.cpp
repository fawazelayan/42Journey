#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this -> type = "WrongCat";
	std::cout << "WrongCat default called\n";
}
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy called\n";
}
WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called\n";
}
WrongCat &WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
		WrongAnimal::operator=(other);
	std::cout << "Assignment operator called\n";
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << type << " is meowing\n";
}