#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	LOG("FragTrap default constructor called.");
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& trap) : ClapTrap(trap)
{
	LOG("FragTrap copy constructor called.");
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	LOG("FragTrap parameter constructor called.");
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap& FragTrap::operator=(const FragTrap& otherCopy)
{
	if (this == &otherCopy)
		return (*this);
	this->hitPoints = otherCopy.getCurrentHealth();
	this->energyPoints = otherCopy.getCurrentEnergy();
	this->attackDamage = otherCopy.getCurrentAttackPower();
	return (*this);
}

FragTrap::~FragTrap(void)
{
	LOG(RED "FragTrap destroyed." RESET);
}

void FragTrap::attack(const std::string &target)
{
	if (!this->energyPoints || !this->hitPoints)
	{
		std::cout << "\n\tFragTrap is depleted.\n" << std::endl; 
		return ;
	}
	std::cout << CYAN "\n\tFragTrap " << this->name << " attacks " << target;
	std::cout << ", causing " << this->getCurrentAttackPower() << " points of damage!\n" << RESET << std::endl;
	this->energyPoints--;
}		

void FragTrap::highFiveGuys(void)
{
	std::cout << GREEN << "\n\tFragTrap " << this->name << " high fives everyone!\n" << RESET << std::endl;
}	