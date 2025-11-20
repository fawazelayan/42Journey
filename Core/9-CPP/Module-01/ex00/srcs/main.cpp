#include "Zombie.hpp"

int	main(void)
{
	Zombie*	heapZombie = newZombie("HEAP");
	if (!heapZombie)
	{
		std::cout << "Allocation failure.\n";
		return 1;
	}
	randomChump("STACK");
	heapZombie -> announce();
	delete heapZombie;
	return 0;
}

// new operator works like this. in the case of int *x = new int;
// void *tmp = operator new(sizeof(int));  <--  this is the num of bytes to allocate
// int *x = static_cast<int *>(tmp);
// delete works like   opereator delete(x);
// for the case of classes  sizeof(class) depends on variables, padding, and virtual ptr if exists and other stuff
