#include "Zombie.hpp"

int	main(void)
{
	int	N = 0;

	std::cout << "\nPlease enter number of the horde: \n";
	std::cin >> N;

	Zombie* horde =  zombieHorde(N, "HEAP");
	if (!horde)
	{
		std::cout << "\n\nAllocation failed.\n\n";
		return 1;
	}
	Zombie stack("STACK");
	
	std::cout << '\n';
	stack.announce();
	for (int i = 0; i < N; i++)
		horde[i].announce();
	std::cout << '\n';
	delete [] horde;
	return 0;
}