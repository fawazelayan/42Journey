#include "HumanB.hpp"

HumanB::HumanB(std::string nm) : name(nm), weapon(NULL) {}
HumanB::~HumanB() {}

std::string HumanB::getName(void) const
{
	return name;
}

void HumanB::setName(std::string name)
{
	 this -> name = name;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this -> weapon = &weapon;
}

void HumanB::attack(void) const
{
	if (weapon)
		std::cout << name << " attacks with their "
				<< weapon -> getType() << ".\n";
	else
		std::cout << name << " has no weapon.\n";
}