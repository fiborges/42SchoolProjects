#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() 
{
    // Criando uma instância de ClapTrap
    ClapTrap bellatrix("Bellatrix Lestrange");

    // Exibindo os atributos iniciais
    std::cout << CYAN << "Atributos iniciais de Bellatrix:\n" << RESET << bellatrix << std::endl;

    // Chamando métodos de ClapTrap
    std::cout << MAGENTA << "Batle ClapTrap\n" << RESET;

    bellatrix.attack("Ronald Weasley");
    std::cout << CYAN << "Estado atual de Bellatrix Lestrange:\n "<< CYAN << bellatrix << std::endl;

    bellatrix.takeDamage(4);
    std::cout << CYAN << "Estado atual de Bellatrix Lestrange:\n "<< CYAN << bellatrix << std::endl;
  
    bellatrix.beRepaired(2);
    std::cout << CYAN << "Estado final de Bellatrix Lestrange:\n "<< CYAN << bellatrix << std::endl;

    std::cout << RED << "\n final TESTE Clap!\n\n\n" << RESET;

    //métodos de ScavTrap

     //ScavTrap
    ScavTrap harry("Harry Potter");

    std::cout << CYAN << "Atributos iniciais de Harry Potter:\n" << RESET << harry << std::endl;
  
    std::cout << MAGENTA << "Batle ScavTrap\n" << RESET;

    harry.attack("Voldemort");
    std::cout << CYAN << "Estado de Harry Potter:\n" << RESET << harry << std::endl;

    harry.guardGate();

    std::cout << RED << "\n final TESTE Scav!\n\n\n" << RESET;

      //FragTrap
    FragTrap herminione("Herminione Granger");
  

    //atributos iniciais
    std::cout << CYAN << "Atributos iniciais de Herminione:\n" << RESET << herminione << std::endl;

    std::cout << MAGENTA << "Batle FragTrap\n" << RESET;

    herminione.attack("Draco");
    std::cout << CYAN << "Estado de Herminione:\n" << RESET << herminione << std::endl;

    herminione.highFiveGuys();

    std::cout << RED << "\n final TESTE Frag!\n\n\n" << RESET;

    //DiamondTrap
    DiamondTrap dobby("Dobby");

    // atributos iniciais
    std::cout << CYAN << "Atributos iniciais de Dobby:\n" << RESET << dobby << std::endl;

    // Chamando métodos de DiamondTrap
    std::cout << MAGENTA << "Batalha DiamondTrap\n" << RESET;

    dobby.attack("Lucius Malfoy");
    std::cout << CYAN << "Estado atual de Diamantina:\n" << RESET << dobby << std::endl;

    dobby.takeDamage(4);
    std::cout << CYAN << "Estado atual de Diamantina:\n" << RESET << dobby << std::endl;

    dobby.beRepaired(5);
    std::cout << CYAN << "Estado atual de Diamantina:\n" << RESET << dobby << std::endl;

    dobby.guardGate();
    std::cout << YELLOW << "\n" << RESET;

    dobby.whoAmI();
    std::cout << YELLOW << "\n" << RESET;

    std::cout << CYAN << "Estado de Dobby:\n" << RESET << dobby << std::endl;

    std::cout << RED << "Teste Final DiamondTrap!\n\n" << RESET;

    return 0;
}



