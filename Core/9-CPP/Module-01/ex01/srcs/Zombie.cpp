#include "Zombie.hpp"

Zombie::Zombie() : name("emptyName")
{
	std::cout << "Default constructor called.\n";
}

Zombie::Zombie(std::string zombieName) : name(zombieName)
{
	std::cout << name << " has been created.\n";
}

Zombie::~Zombie()
{
	std::cout << name << " has been destroyed.\n";
}

void	Zombie::setName(std::string name)
{
	this -> name = name;
}

std::string	Zombie::getName() const
{
	return name;
}

void	Zombie::announce(void) const
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}