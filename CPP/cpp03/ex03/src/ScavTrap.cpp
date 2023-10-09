#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	LOG( YELLOW "ScavTrap default constructor called." RESET);
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& trap) : ClapTrap(trap)
{
	LOG( YELLOW "ScavTrap copy constructor called." RESET);
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	LOG( YELLOW "ScavTrap parameter constructor called." RESET);
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& otherCopy)
{
	if (this == &otherCopy)
		return (*this);
	this->hitPoints = otherCopy.getCurrentHealth();
	this->energyPoints = otherCopy.getCurrentEnergy();
	this->attackDamage = otherCopy.getCurrentAttackPower();
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	LOG( RED "ScavTrap destroyed." RESET);
}

void ScavTrap::attack(const std::string &target)
{
	if (!this->getCurrentEnergy() || !this->getCurrentHealth())
	{
		std::cout << CYAN << "\n\tScavTrap is depleted.\n"<< RESET << std::endl; 
		return ;
	}
	std::cout << CYAN << "\n\tScavTrap " << this->name << " attacks " << target;
	std::cout << ", causing " << this->attackDamage << " points of damage!\n" << RESET << std::endl;
	this->energyPoints--;
}

void ScavTrap::guardGate(void)
{
	std::cout << YELLOW << "\n\tScavTrap " << this->name << " is in Gate Keeper mode.\n" << RESET << std::endl;
}