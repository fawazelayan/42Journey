#include "Zombie.hpp"

int	main(void)
{
	int	N;

	std::cout << "\nPlease enter number of the zombies: ";
	std::cin >> N;

	if (N <= 0)
	{
		std::cout << "Number of zombies must be greater than 0.\n";
		return 2;
	}

	std::cout << '\n';

	Zombie* horde =  zombieHorde(N, "HEAP");
	if (!horde)
	{
		std::cout << "Allocation failure.\n";
		return 1;
	}

	std::cout << '\n';

	for (int i = 0; i < N; i++)
		horde[i].announce();

	std::cout << '\n';
	delete [] horde;
	std::cout << '\n';

	return 0;
}