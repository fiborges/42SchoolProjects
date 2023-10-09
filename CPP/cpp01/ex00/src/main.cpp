#include "Zombie.hpp"

void erro_msg(void)
{
    std::cerr << RED << "You need to pass two arguments!! [./zombie] [name_of_random_chump] [name_of_new_zombie] " << RESET << std::endl;
    exit(1);
}

int main(int argc, char **argv)
{
    std::string randomName;
    std::string newZombieName;

    if (argc < 3)
        erro_msg();

    randomName = argv[1];
    newZombieName = argv[2];

    // Spawn and announce the random zombie
    std::cout << "\n" << GREEN << "\t *_* Random Chump *_*" << RESET << std::endl;
    std::cout << std::endl;
    randomChump(randomName);

    // Create a new heap zombie to be used in main
    std::cout << "\n" << MAGENTA << "\t *_* New Zombie *_*" << RESET << std::endl;
    std::cout << std::endl;
    Zombie *zombie = newZombie(newZombieName);
    zombie->announce();
    delete zombie;
}
