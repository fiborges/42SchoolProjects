#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB
{
	public:
		HumanB();
		HumanB(std::string name);
		void attack(void);
		void setWeapon(Weapon& weapon);
		
	private:
		std::string name;
		Weapon *weapon;
};

#endif