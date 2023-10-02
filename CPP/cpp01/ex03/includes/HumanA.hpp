#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(const std::string& name, Weapon& weapon);
		void attack(void);
		void setWeapon(const Weapon& weapon);
		
	private:
		std::string name;
		Weapon& weapon;
};

#endif