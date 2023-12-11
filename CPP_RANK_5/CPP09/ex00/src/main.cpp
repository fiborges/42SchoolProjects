#include "BitcoinExchange.hpp"

int main(int ac, char **av) 
{

	BitcoinExchange bitcoin;
	
	if (ac != 2) 
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}

	bitcoin.loadConversionData();
	bitcoin.processInputFile(av[1]);

}
