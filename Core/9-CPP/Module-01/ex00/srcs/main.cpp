#include "Zombie.hpp"

int	main(void)
{
	Zombie*	heapZombie = newZombie("Fawaz");
	if (!heapZombie)
	{
		std::cout << "Malloc failure.\n";
		return 1;
	}
	Zombie	stackZombie("STACK 1");
	heapZombie -> announce();
	stackZombie.announce();
	randomChump("STACK 2");
	heapZombie -> setName("HEAP");
	delete heapZombie;
	return 0;
}