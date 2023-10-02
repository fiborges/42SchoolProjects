#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    std::cout << CYAN << this->name << RESET << RED <<" is beeing killed :( " << RESET << std::endl;
}

void    Zombie::announce( void )
{
    std::cout << CYAN << this->name << RESET << YELLOW << ": BraiiiiiiinnnzzZ..." << RESET << std::endl;
}