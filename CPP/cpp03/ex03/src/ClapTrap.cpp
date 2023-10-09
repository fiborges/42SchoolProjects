#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	LOG(GREEN "ClapTrap default constructor called." RESET);
	this->name = "";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& trap)
{
	LOG(GREEN "ClapTrap copy constructor called." RESET);
	*this = trap;
}

ClapTrap::ClapTrap(const std::string& name)
{
	LOG(GREEN "ClapTrap parameter constructor called." RESET);
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::~ClapTrap()
{
	LOG(RED "ClapTrap destroyed." RESET);
}

ClapTrap& ClapTrap::operator=(const ClapTrap& otherCopy)
{
	if (this == &otherCopy)
		return (*this);
	this->hitPoints = otherCopy.getCurrentHealth();
	this->energyPoints = otherCopy.getCurrentEnergy();
	this->attackDamage = otherCopy.getCurrentAttackPower();
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (!this->energyPoints || !this->hitPoints)
	{
		std::cout << RED "\n\t ClapTrap has no energy or health remaining. \n" RESET << std::endl; 
		return ;
	}
	std::cout << CYAN "\n\tClapTrap " << this->name << " attacks " << target;
	std::cout << ", causing " << this->attackDamage << " points of damage !" RESET << std::endl;
	this->energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->hitPoints = this->hitPoints - amount;
	if (this->hitPoints < 0)
		this->hitPoints = 0;
	std::cout << RED "\n\tClapTrap " << this->name << " takes " << amount;
	std::cout << " damage, reducing its health to " << this->hitPoints << "!" RESET << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->energyPoints || !this->hitPoints)
	{
		std::cout << RED "\n\t ClapTrap has no energy or health remaining. \n" RESET << std::endl; 
		return ;
	}
	this->hitPoints = this->hitPoints + amount;	
	std::cout << GREEN "\n\tClapTrap " << this->name << " repairs itself for " << amount;
	std::cout << " HP, increasing its health to " << this->hitPoints << "!" RESET << std::endl;
	this->energyPoints--;
}

int ClapTrap::getCurrentHealth(void) const
{
	return (this->hitPoints);
}

int ClapTrap::getCurrentEnergy(void) const
{
	return (this->energyPoints);
}

int ClapTrap::getCurrentAttackPower(void) const
{
	return (this->attackDamage);
}

std::ostream& operator<<(std::ostream& output, const ClapTrap& fixedNumber)
{
	output << YELLOW " - Health: " << fixedNumber.getCurrentHealth() << RESET << std::endl;
	output << YELLOW " - Energy: " << fixedNumber.getCurrentEnergy() << RESET << std::endl;
	output << YELLOW " - Damage: " << fixedNumber.getCurrentAttackPower() << RESET << std::endl;
	return (output);
}

