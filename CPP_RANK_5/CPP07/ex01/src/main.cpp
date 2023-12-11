#include "iter.hpp"

void testIntegerArrayPrinting(void)
{
	std::cout << GREEN << "\n\t :_:_:_:_:_:_:_:_:_: TEST INTEGERS :_:_:_:_:_:_:_:_:_:_:_:_:_:_\n\n" << RESET;
	
	int array[] = {1, 2, 3, 4, 5, 42, -42, 0, -200007, 59870};
	iter(array, sizeof(array)/sizeof(int), &print);	
}

void testStringArrayPrinting(void)
{
	std::cout << GREEN << "\n\t *_*_*_*_*_*_*_*_*_*_*_* TEST STRINGS *_*_*_*_*_*_*_*_*_*_*\n\n" << RESET;
	
	std::string array[] = 
	{
		"Filipa",
		"Manuela",
		"Ribeiro",
		"Vieira",
        "Borges",
	};
	iter(array, sizeof(array)/sizeof(std::string), &print);	
}

void testAlphabetPrinting(void)
{	
	std::cout << GREEN << "\n\t 0.0.0.0.0.0.0.0.0.0.0 TEST ALPHABET 0.0.0.0.0.0.0..0.0.0\n\n" << RESET;
	
	char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	iter(alphabet, sizeof(alphabet), &print);
}

int main(int argc, char **argv)
{
	int					selectedTest;
	std::stringstream	argumentStream;

    if (argc < 2) 
	{
        std::cerr << RED << "Erro: Número de argumentos incorreto." << std::endl << RESET;
        return 1;
    }

    argumentStream << argv[1];

    if (!(argumentStream >> selectedTest)) 
	{
        std::cerr << RED <<  "Erro: O argumento não é um número inteiro válido." << std::endl << RESET;
        return 2;
    }

    if (selectedTest < 0 || selectedTest > 2) 
	{
        std::cerr << RED << "Erro: Número de teste não está correto." << std::endl << RESET;
        return 3;
    }
	if (selectedTest == 0)
		testIntegerArrayPrinting();
	else if (selectedTest == 1)
		testStringArrayPrinting();
	else
		testAlphabetPrinting();
	return (0);
}