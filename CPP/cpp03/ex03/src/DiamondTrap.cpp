#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	LOG(MAGENTA "DiamondTrap default constructor called." RESET);
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 30;
	this->ClapTrap::name = name + "_clap_name";
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	LOG(MAGENTA "DiamondTrap parameter constructor called." RESET);
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 30;
	this->ClapTrap::name = name + "_clap_name";
}

DiamondTrap::DiamondTrap(const DiamondTrap& trap) : ClapTrap(trap), ScavTrap(trap), FragTrap(trap) 
{
	LOG(MAGENTA "DiamondTrap copy constructor called." RESET);
	this->name = trap.name;
}

DiamondTrap::~DiamondTrap(void)
{
	LOG(RED "DiamondTrap destroyed." RESET);
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& otherCopy)
{
	if (this == &otherCopy)
		return (*this);
	this->name = otherCopy.name;
	this->hitPoints = otherCopy.hitPoints;
	this->energyPoints = otherCopy.energyPoints;
	this->attackDamage = otherCopy.attackDamage;
	this->ClapTrap::name = otherCopy.ClapTrap::name;
	return (*this);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << CYAN << "\n\tDiamondTrap " << this->name;
	std::cout << " is also known as ClapTrap " << RESET << ClapTrap::name;
	std::cout << std::endl << std::endl;
}