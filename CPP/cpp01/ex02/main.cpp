#include <iostream>

// Cores ANSI
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define CYAN     "\033[36m"


int main(void)
{
	std::string stringVar = "HI THIS IS BRAIN";
	std::string *stringPTR = &stringVar;
	std::string &stringREF = stringVar;

	std::cout << CYAN << "Memory address of the string: "<< RESET << &stringVar << std::endl;
	std::cout << CYAN << "Memory address of the stringPTR:" << RESET << stringPTR << std::endl;
	std::cout <<  CYAN << "Memory address of the stringREF" << RESET << &stringREF << std::endl;

	std::cout << std::endl;
	
	std::cout << GREEN << "The value in str is: " << RESET << stringVar << std::endl;
	std::cout << GREEN << "The value in stringPTR is: " << RESET << *stringPTR << std::endl;
	std::cout << GREEN << "The value in stringREF is: " <<  RESET <<stringREF << std::endl;

	return (0);
}
