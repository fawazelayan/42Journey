#include "HumanA.hpp"

HumanA::HumanA(std::string nm, Weapon &wp) : name(nm), weapon(wp) {}
HumanA::~HumanA() {}

std::string HumanA::getName(void) const
{
	return name;
}

void HumanA::setName(std::string name)
{
	 this -> name = name;
}

void HumanA::attack(void) const
{
	std::cout << name << " attacks with their " << weapon.getType() << ".\n";
}