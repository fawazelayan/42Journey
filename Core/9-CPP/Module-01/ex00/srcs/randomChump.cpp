#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie zombie(name);

	std::cout << zombie.getName() << ": BraiiiiiiinnnzzzZ...\n";
}