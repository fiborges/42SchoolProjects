#include "ClapTrap.hpp"
#include <iostream>
#include <string>

int main()
{
    ClapTrap harry("Harry Potter");
    ClapTrap bellatrix("Bellatrix Lestrange");

    std::cout << GREEN << "Welcome to the ClapTrap Battle of Hogwarts!" << RESET << std::endl;

    while (true)
    {
        std::cout << CYAN << "\nOptions:\n" << RESET;
        std::cout << "1. Attack\n";
        std::cout << "2. Take Damage\n";
        std::cout << "3. Be Repaired\n";
        std::cout << "4. Quit\n";
        std::cout << "Choose an option (1-4): ";

        int choice;
        std::cin >> choice;

        if (choice == 4)
        {
            // Usuário escolheu sair
            break;
        }

        std::cin.ignore(); // Limpa o buffer de entrada

        switch (choice)
        {
        case 1:
            {
                std::cout << MAGENTA << "Choose a target (1 - Harry or 2 - Bellatrix): " << RESET;
                std::string targetName;
                std::getline(std::cin, targetName);

                if (targetName == "Harry" || targetName == "1")
                {
                    harry.attack("Bellatrix");
                }
                else if (targetName == "Bellatrix" || targetName == "2")
                {
                    bellatrix.attack("Harry");
                }
                else
                {
                    std::cout << RED <<"Invalid target!" << RESET << std::endl;
                }
                break;
            }
        case 2:
            {
                std::cout << MAGENTA << "Choose a target (1 - Harry or 2 - Bellatrix): " << RESET;
                std::string targetName;
                std::getline(std::cin, targetName);

                int damage;
                std::cout << CYAN << "Enter damage amount: " << RESET;
                std::cin >> damage;

                if (targetName == "Harry" || targetName == "1")
                {
                    harry.takeDamage(damage);
                }
                else if (targetName == "Bellatrix" || targetName == "2")
                {
                    bellatrix.takeDamage(damage);
                }
                else
                {
                    std::cout << RED <<"Invalid target!" << RESET << std::endl;
                }
                break;
            }
        case 3:
            {
                std::cout << MAGENTA << "Choose a character to be repaired (1- Harry or 2 - Bellatrix): " << RESET;
                std::string characterName;
                std::getline(std::cin, characterName);

                int repairAmount;
                std::cout << CYAN << "Enter repair amount: " << RESET;
                std::cin >> repairAmount;

                if (characterName == "Harry" || characterName == "1")
                {
                    harry.beRepaired(repairAmount);
                }
                else if (characterName == "Bellatrix" || characterName == "2")
                {
                    bellatrix.beRepaired(repairAmount);
                }
                else
                {
                    std::cout << RED << "Invalid character!" << RESET << std::endl;
                }
                break;
            }
        default:
            std::cout << RED << "Invalid choice. Please choose a valid option (1-4)." << RESET << std::endl;
        }

        std::cout << CYAN << "Harry's Status:\n" << RESET << harry << std::endl;
        std::cout << CYAN << "Bellatrix's Status:\n" << RESET << bellatrix << std::endl;
    }

    std::cout << YELLOW << "Exiting the ClapTrap Battle. Goodbye!" << RESET << std::endl;

    return 0;
}

