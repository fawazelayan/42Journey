#include "ScavTrap.hpp"

int main()
{
	ScavTrap scavy("Scavy");
	ScavTrap robot;
	ScavTrap copy(scavy);

	ScavTrap ass = robot;

	std::cout << '\n';
	scavy.attack("dummy");
	scavy.takeDamage(5);
	scavy.beRepaired(3);
	ass.takeDamage(5);

	for (int i = 0; i < 9; i++)
	{
		scavy.beRepaired(1);
	}
	scavy.attack("anything");
	robot.attack("bad dummy");
	robot.takeDamage(9);
	robot.beRepaired(1);
	robot.takeDamage(10000);
	robot.attack("anything");
	scavy.guardGate();
	std::cout << '\n';
}