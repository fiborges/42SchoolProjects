#include "Harl.hpp"

void erro_msg(void)
{
	std::cout << RED << "Number of Arguments Invalid [./program] [level]" << RESET << std::endl;
	exit(1);
}

int main(int argc, char **argv)
{
	Harl harl;
	std::string level;
	
	if (argc < 2)
		erro_msg();
	level = argv[1];
	harl.complain(level);
	return (0);
}