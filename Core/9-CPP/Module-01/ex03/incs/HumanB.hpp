#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB
{
	private:
		std::string name;
		Weapon *weapon;
	public:

	// Constructors and Destructor
		HumanB(std::string nm);
		~HumanB();

	// Setters and Getters
		std::string getName(void) const;
		void setName(std::string name);
		void setWeapon(Weapon &weapon);
	// Other member functions
		void attack() const;
};

#endif