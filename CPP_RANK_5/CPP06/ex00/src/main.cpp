#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << argv[0] << " input\n";
	else
		ScalarConverter::convert(argv[1]);
}