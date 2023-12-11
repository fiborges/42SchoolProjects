#include "Array.hpp"

#include <iostream>
#include <sstream>
#include "Array.hpp"

void testDefaultArrayCreation(void)
{
    std::cout << GREEN << "\n\t Testing Default Array Creation: Creating an Array with 10 Elements  \n\n" << RESET;

    Array<int> numbers(10);

    for (size_t i = 0; i < numbers.size(); i++)
        std::cout << "Element at index " << i << " is: " << numbers[i] << std::endl;
}

void testArrayCopy(void)
{
    std::cout << GREEN << "\n\t Testing Array Copy: Creating a Copy of an Array  \n\n" << RESET;

    Array<int> numbers(10);
    Array<int> copy(5);

    for (size_t i = 0; i < numbers.size(); i++)
        numbers[i] = 42;

    copy = numbers;
    numbers[0] = 21;
    for (size_t i = 0; i < copy.size(); i++)
        std::cout << CYAN << "Copied Element at index " << i << ": " << RESET << copy[i] << CYAN << " (Original Element at index " << i << ": " << RESET << numbers[i] << ")\n";
}

void testInvalidIndexHandling(void)
{
    std::cout << GREEN << "\n\t Testing Invalid Index Handling: Attempting to Set Values at Out-of-Bounds Indexes \n\n" << RESET;
    Array<int> numbers(10);

    try
    {
        numbers[-1] = 0;
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught Exception (Attempted to set value at index -1): " << e.what() << '\n';
    }

    try
    {
        numbers[10] = 0;
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught Exception (Attempted to set value at index 10): " << e.what() << '\n';
    }
}

int main(int argc, char **argv)
{
    int selectedTest;
    std::stringstream argumentStream;

    std::srand(time(NULL));

    if (argc < 2)
    {
        std::cerr << RED << "Usage: " << RESET <<  argv[0] << RED << " <test_number>" << RESET << std::endl;
        return 1;
    }

    argumentStream << argv[1];
    if (!(argumentStream >> selectedTest))
    {
        std::cerr << RED << "Error: Invalid test number." << RESET << std::endl;
        return 1;
    }

    if (selectedTest < 0 || selectedTest > 2)
    {
        std::cerr << RED << "Error: Invalid test number. Choose 0, 1, or 2." << RESET << std::endl;
        return 1;
    }

    if (selectedTest == 0)
        testDefaultArrayCreation();
    else if (selectedTest == 1)
        testArrayCopy();
    else
        testInvalidIndexHandling();

    return 0;
}

