#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("def")
{
	HP = 100;
	EP = 100;
	AD = 30;
	std::cout << "Frag default called\n";
}
FragTrap::~FragTrap()
{
	std::cout << "Frag destructor called\n";
}
FragTrap::FragTrap(const std::string nm) : ClapTrap(nm)
{
	HP = 100;
	EP = 100;
	AD = 30;
	std::cout << "Frag parameter called\n";
}
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "Frag copy called\n";
	*this = other;
}
FragTrap &FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return *this;
}
void FragTrap::attack(const std::string& target)
{
	if (EP > 0 && HP > 0)
	{
		EP--;
		std::cout << "FragTrap " << name << " attacks " << target
			<< ", dealing " << AD << " points of damage!\n"
			<< "HP = " << HP << "\nEP = " << EP << '\n';
	}
	else
		std::cout << "FragTrap " << name << " can't attack!\n";
}
void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name << " has high fived!\n";
}