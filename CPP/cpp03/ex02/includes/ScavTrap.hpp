#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:

		ScavTrap(void);
		ScavTrap(const ScavTrap& trap);
		ScavTrap(const std::string name);
		virtual ~ScavTrap(void);

	
		ScavTrap& operator=(const ScavTrap& trap);


		void attack(const std::string &target);		
		void guardGate(void);
};

#endif