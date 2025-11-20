#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
	private:
		std::string type;
	public:

	// Constructors and Destructor
		Weapon(std::string);
		~Weapon();

	// Setters and Getters
		std::string getType(void) const;
		void setType (std::string);
};

#endif