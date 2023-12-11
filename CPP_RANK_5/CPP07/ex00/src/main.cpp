#include "whatever.hpp"
#include <iostream>
#include <string>

// ANSI escape codes for text color
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

int main(void) {
    int a = 2;
    int b = 3;

    std::cout << GREEN << "Before: a = " << RESET << a << GREEN << ", b = "<< RESET << b << std::endl;
    ::swap(a, b);
    std::cout << GREEN << "After: a = " << RESET << a << GREEN << ", b = " << RESET << b << std::endl;
    std::cout << YELLOW << "min( a, b ) = " << RESET << ::min(a, b) << std::endl;
    std::cout << YELLOW << "max( a, b ) = " << RESET << ::max(a, b) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    std::cout << GREEN << "Before: c = " << RESET << c << GREEN << ", d = " << RESET << d << std::endl;
    ::swap(c, d);
    std::cout << GREEN << "After: c = " RESET << c << GREEN << ", d = " << RESET << d << std::endl;
    std::cout << YELLOW << "min( c, d ) = " RESET << ::min(c, d) << std::endl;
    std::cout << YELLOW << "max( c, d ) = "<< RESET << ::max(c, d) << std::endl;

    return 0;
}
