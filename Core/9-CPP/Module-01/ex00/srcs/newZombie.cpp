#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie* new_Zombie =  new (std::nothrow) Zombie(name);
	return new_Zombie;
}