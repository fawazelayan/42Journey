#include "Weapon.hpp"

Weapon::Weapon(std::string tp) : type(tp) {}
Weapon::~Weapon() {}

std::string Weapon::getType(void) const
{
	return type;
}

void Weapon::setType(std::string type)
{
	this -> type = type;
}