#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:

		FragTrap(void);
		FragTrap(const FragTrap& copy);
		FragTrap(const std::string name);
		virtual ~FragTrap(void);
		
	
		FragTrap& operator=(const FragTrap& otherCopy);

	
		void attack(const std::string &target);		
		void highFiveGuys(void);
};

#endif