#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:

		FragTrap(void);
		FragTrap(const FragTrap& trap);
		FragTrap(const std::string name);
		virtual ~FragTrap(void);
		
	
		FragTrap& operator=(const FragTrap& trap);

	
		void attack(const std::string &target);		
		void highFiveGuys(void);
};

#endif