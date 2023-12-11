#include "Base.hpp"

#include "Base.hpp"
#include <sstream>
#include <cstdlib>
#include <ctime>

#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define RESET   "\033[0m"

void testBadIdentify(void)
{
    std::cout << RED << "\n\t 0.0.0.0.0.0.0.0.0.0.0.0. Testing Incorrect Identify 0.0.0.0.0.0.0.0.0.0\n\n" << RESET;

    Base* pointer = nullptr;
    Base reference;

    identify(pointer);
    identify(reference);
}

void testCoolIdentify(void)
{
    std::cout << GREEN << "\n\t *_*_*_*_*_*_*_* Testing Successful Identify *_*_*_*_*_*_*_*_*_*_*\n\n" << RESET;

    Base* random = generate();

    identify(random);
    identify(*random);

    delete random;
}

int main(int argc, char** argv)
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    if (argc < 2)
        return (std::cerr << RED << "Usage: " << argv[0] << " <test_number>" << RESET << std::endl, 1);

    int testno;
    std::stringstream stream(argv[1]);

    if (!(stream >> testno))
        return (std::cerr << RED << "Error: Test number must be an integer." << RESET << std::endl, 1);

    if (testno < 0 || testno > 1)
        return (std::cerr << RED << "Error: Test number must be 0 or 1." << RESET << std::endl, 1);

    if (testno == 0)
        testCoolIdentify();
    else
        testBadIdentify();

    return 0;
}
