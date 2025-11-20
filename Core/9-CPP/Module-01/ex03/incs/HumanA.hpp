#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA
{
	private:
		std::string name;
		Weapon &weapon;
	public:

	// Constructors and Destructor
		HumanA(std::string nm, Weapon &wp);
		~HumanA();

	// Setters and Getters
		std::string getName(void) const;
		void setName(std::string name);
	// Other member functions
		void attack(void) const;
};

#endif