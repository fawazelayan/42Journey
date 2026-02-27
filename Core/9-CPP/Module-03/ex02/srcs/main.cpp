#include "FragTrap.hpp"

int main()
{
	FragTrap fragy("Fragy");
	FragTrap robot;
	FragTrap copy(fragy);

	FragTrap ass = robot;

	std::cout << '\n';
	fragy.attack("dummy");
	fragy.takeDamage(5);
	fragy.beRepaired(3);
	ass.takeDamage(5);

	for (int i = 0; i < 9; i++)
	{
		fragy.beRepaired(1);
	}
	fragy.attack("anything");
	robot.attack("bad dummy");
	robot.takeDamage(9);
	robot.beRepaired(1);
	robot.takeDamage(10000);
	robot.attack("anything");
	fragy.highFivesGuys();
	std::cout << '\n';
}