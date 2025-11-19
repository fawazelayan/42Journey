#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string name;
	public:
	// Constructor and destructor
		Zombie(std::string name);
		Zombie();
		~Zombie();

		std::string getName(void) const;
		void setName(std::string name);
		void announce(void) const;
};

Zombie*	zombieHorde(int N, std::string name);

#endif