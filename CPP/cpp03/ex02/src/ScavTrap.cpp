#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	LOG( GREEN "ScavTrap default constructor called." RESET);
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& trap) : ClapTrap(trap)
{
	LOG( GREEN "ScavTrap copy constructor called." RESET);
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	LOG( GREEN "ScavTrap parameter constructor called." RESET);
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& trap)
{
	if (this == &trap)
		return (*this);
	this->hitPoints = trap.getCurrentHealth();
	this->energyPoints = trap.getCurrentEnergy();
	this->attackDamage = trap.getCurrentAttackPower();
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