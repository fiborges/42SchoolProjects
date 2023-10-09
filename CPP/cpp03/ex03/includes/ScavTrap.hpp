#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:

		ScavTrap(void);
		ScavTrap(const ScavTrap& copy);
		ScavTrap(const std::string name);
		virtual ~ScavTrap(void);

	
		ScavTrap& operator=(const ScavTrap& otherCopy);


		void attack(const std::string &target);		
		void guardGate(void);
};

#endif