#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		~ScavTrap();
		ScavTrap(const ScavTrap& other);
		ScavTrap(const std::string nm);
		ScavTrap& operator=(const ScavTrap& other);

		void attack(const std::string& target);
		void guardGate();

};

#endif