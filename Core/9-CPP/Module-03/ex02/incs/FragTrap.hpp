#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		~FragTrap();
		FragTrap(const FragTrap& other);
		FragTrap(const std::string nm);
		FragTrap& operator=(const FragTrap& other);

		void attack(const std::string& target);
		void highFivesGuys(void);

};

#endif