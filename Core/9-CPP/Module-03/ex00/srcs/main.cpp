#include "ClapTrap.hpp"

int main()
{
	ClapTrap clippy("Clippy");
	ClapTrap robot;
	ClapTrap copy(clippy);

	ClapTrap ass = robot;

	std::cout << '\n';
	clippy.attack("dummy");
	clippy.takeDamage(5);
	clippy.beRepaired(3);

	for (int i = 0; i < 9; i++)
	{
		clippy.beRepaired(1);
	}
	clippy.attack("anything");
	robot.attack("bad dummy");
	robot.takeDamage(9);
	robot.beRepaired(1);
	robot.takeDamage(10000);
	robot.attack("anything");
	std::cout << '\n';
}