#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie* newHorde = new (std::nothrow) Zombie[N];
	if (!newHorde)
		return NULL;
	for (int i = 0; i < N; i++)
		newHorde[i].setName(name);
	return newHorde;
}