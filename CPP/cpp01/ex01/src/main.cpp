#include "Zombie.hpp"

void	erro_msg(void)
{
	std::cout << RED << "Number of arguments ivalid. [./zombie] [number_of_zombies] [name]"<< RESET << std::endl;
	exit(1);
}

int main(int argc, char **argv)
{
	if (argc < 3)
		erro_msg();
		
	int	hordeSize;
	Zombie *horde;
	
	hordeSize = atoi(argv[1]);
	horde = zombieHorde(hordeSize, argv[2]);
	if (!horde)
		return (2);
	for (int i = 0; i < hordeSize; i++)
		horde[i].announce();
		std::cout << std::endl;
	delete[] horde;
}