#include "Harl.hpp"

void erro_msg(void)
{
	std::cout << RED << "Number of arguments Invalid. [./program] [level]" << RESET << std::endl;
	exit(1);
}

void harlFilter(Harl &harl, const std::string& level)
{	
	int index = -1;
	std::string levels[4] = 
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	
	for (int i = 0; i < 4; i++)
		if (levels[i] == level)
			index = i;
			
	switch(index)
	{
		default:
			break;
		case 0:
			std::cout << GREEN << "[ DEBUG ]" << RESET << std::endl;
			harl.complain("DEBUG");
		case 1:
			std::cout << GREEN << "[ INFO ]" << RESET << std::endl;
			harl.complain("INFO");
		case 2:
			std::cout << GREEN << "[ WARNING ]"<< RESET << std::endl;
			harl.complain("WARNING");
		case 3:
			std::cout << GREEN << "[ ERROR ]" << RESET << std::endl;
			harl.complain("ERROR");
	}
}

int main(int argc, char **argv)
{
	Harl harl;
	
	if (argc < 2)
		erro_msg();
	harlFilter(harl, argv[1]);
	return (0);
}