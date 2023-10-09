#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() 
{
    // Criando uma instância de ClapTrap
    ClapTrap bellatrix("Bellatrix Lestrange");

    // Exibindo os atributos iniciais
    std::cout << CYAN << "Atributos iniciais de Bellatrix:\n" << RESET << bellatrix << std::endl;

    std::cout << MAGENTA << "Batle ClapTrap\n" << RESET;

    bellatrix.attack("Ronald Weasley");
    std::cout << CYAN << "Estado atual de Bellatrix Lestrange:\n "<< CYAN << bellatrix << std::endl;

    bellatrix.takeDamage(4);
    std::cout << CYAN << "Estado atual de Bellatrix Lestrange:\n "<< CYAN << bellatrix << std::endl;
   
    bellatrix.beRepaired(2);
    std::cout << CYAN << "Estado final de Bellatrix Lestrange:\n "<< CYAN << bellatrix << std::endl;

    std::cout << RED << "\n final TESTE Clap!\n\n\n" << RESET;

    //métodos de ScavTrap

     // Criando uma instância de ScavTrap
    ScavTrap harry("Harry Potter");

    std::cout << CYAN << "Atributos iniciais de Harry Potter:\n" << RESET << harry << std::endl;

    std::cout << MAGENTA << "Batle ScavTrap\n" << RESET;

    harry.attack("Voldemort");
    std::cout << CYAN << "Estado de Harry Potter:\n" << RESET << harry << std::endl;

    harry.guardGate();

    std::cout << CYAN << "Estado de Harry Potter:\n" << RESET << harry << std::endl;

    std::cout << RED << "\n final TESTE Scav!\n\n\n" << RESET;

    return 0;
}



