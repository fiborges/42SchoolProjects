#include "Zombie.hpp"

Zombie :: Zombie( void )
{
	
}

Zombie :: Zombie(std::string name)
{
	this->name = name;
}

Zombie :: ~Zombie()
{
	std::cout << CYAN << this->name << RESET << RED << " died." << RESET << std::endl;
}

void Zombie :: setName(std::string name)
{
	this->name = name;
}

void Zombie :: announce( void )
{
	std::cout << CYAN << this->name << RESET << YELLOW << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}