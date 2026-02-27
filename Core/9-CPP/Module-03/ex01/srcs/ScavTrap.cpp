#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("def")
{
	HP = 100;
	EP = 50;
	AD = 20;
	std::cout << "Scav default called\n";
}
ScavTrap::~ScavTrap()
{
	std::cout << "Scav destructor called\n";
}
ScavTrap::ScavTrap(const std::string nm) : ClapTrap(nm)
{
	HP = 100;
	EP = 50;
	AD = 20;
	std::cout << "Scav parameter called\n";
}
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "Scav copy called\n";
	*this = other;
}
ScavTrap &ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return *this;
}
void ScavTrap::attack(const std::string& target)
{
	if (EP > 0 && HP > 0)
	{
		EP--;
		std::cout << "ScavTrap " << name << " attacks " << target
			<< ", dealing " << AD << " points of damage!\n"
			<< "HP = " << HP << "\nEP = " << EP << '\n';
	}
	else
		std::cout << "ScavTrap " << name << " can't attack!\n";
}
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " has entered Gatekeeper mode!\n";
}