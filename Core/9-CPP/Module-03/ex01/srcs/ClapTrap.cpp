#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Robot"), HP(10), EP(10), AD(0)
{
	std::cout << "Default constructor called\n";
}

ClapTrap::ClapTrap(const std::string nm) : name(nm), HP(10), EP(10), AD(0)
{
	std::cout << "Parameter constructor called\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy constructor called\n";
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		this -> HP = other.HP;
		this -> AD = other.AD;
		this -> EP = other.EP;
		this -> name = other.name;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (EP > 0 && HP > 0)
	{
		EP--;
		std::cout << "ClapTrap " << name << " attacks " << target
			<< ", causing " << AD << " points of damage!\n"
			<< "HP = " << HP << "\nEP = " << EP << '\n';
	}
	else
		std::cout << "ClapTrap " << name << " can't attack!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (HP > 0)
	{
		if (amount >= (unsigned int)HP)
			HP = 0;
		else
			HP -= amount;
		std::cout << "ClapTrap " << name << " takes " << amount << " damage!\n"
			<< "HP = " << HP << "\nEP = " << EP << '\n';
	}
	else
		std::cout << "ClapTrap " << name << " is already dead!\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (EP > 0 && HP > 0)
	{
		HP += amount;
		EP--;
		std::cout << "ClapTrap " << name << " repairs " << amount << "HP!\n"
			<< "HP = " << HP << "\nEP = " << EP << '\n';
	}
	else
		std::cout << "ClapTrap " << name << " can't repair!\n";
}