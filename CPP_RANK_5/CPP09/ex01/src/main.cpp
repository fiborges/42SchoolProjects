#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
{
    std::cout << "Error: Usage: ./program <expression>" << std::endl;
    return 1;
}
	processRPNExpression(argv[1]);
	return (0);
}