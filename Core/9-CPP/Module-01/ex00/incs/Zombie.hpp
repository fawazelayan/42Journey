#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string name;
	public:
	// Constructors and Destructor
		Zombie(std::string name);
		Zombie();
		~Zombie();

	// Setters and Getters
		std::string getName(void) const;
		void setName(std::string name);

	// Other member functions
		void announce(void) const;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif