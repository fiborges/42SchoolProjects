/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <firibeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:15:27 by firibeir          #+#    #+#             */
/*   Updated: 2024/04/04 11:23:07 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define RESET   "\033[0m"

# define PRINT_ERROR(x) 		std::cout << x << std::endl
# define ERROR_MESSAGE(e)	PRINT_ERROR("Usage: " << e << " test_number")
# define ERROR_NOT_INTEGER	PRINT_ERROR("Error: test number must be a number")
# define ERROR_OUT_OF_RANGE	PRINT_ERROR("Error: test number must be bounded between 0 and 2")

// Função para testar burocratas com notas extremas (1 e 150)
void extremos() 
{
    try 
	{
        Bureaucrat b(BLUE "FILIPA" RESET, 1);
        std::cout << b;
        b.incrementGrade();
        std::cout << b;
    } 
	catch (std::exception &e) 
	{
        std::cout << RED << e.what() << RESET << "\n";
    }

    try 
	{
        Bureaucrat b(YELLOW "MARIA" RESET, 150);
        std::cout << b;
        b.decrementGrade();
        std::cout << b;
    } 
	catch (std::exception &e) 
	{
        std::cout << RED << e.what() << RESET << "\n";
    }
}

// Função para testar burocratas com notas padrão (2 e 149)
void validos() 
{
    try 
	{
        Bureaucrat b(MAGENTA "JOAO" RESET, 2);
        std::cout << b;
        b.incrementGrade();
        std::cout << b;
    } 
	catch (std::exception &e) 
	{
        std::cout << RED << e.what() << RESET << "\n";
    }

    try 
	{
        Bureaucrat b(CYAN "BORGES" RESET, 149);
        std::cout << b;
        b.decrementGrade();
        std::cout << b;
    } 
	catch (std::exception &e) 
	{
        std::cout << RED << e.what() << RESET << "\n";
    }
}

// Função para testar construtores com notas fora dos limites (0 e 151)
void construtores() {
    try 
	{
        Bureaucrat b("0 Grade Someone", 0);
    } 
	catch (std::exception &e) 
	{
        std::cout << RED << e.what() << RESET << "\n";
    }

    try 
	{
        Bureaucrat b("151 Grade Someone", 151);
    } 
	catch (std::exception &e) 
	{
        std::cout << RED << e.what() << RESET << "\n";
    }
}

int main(int argc, char **argv) 
{
    int test_number;
    std::stringstream stream;

    if (argc < 2)
        return (ERROR_MESSAGE(argv[0]), 1);
    stream << argv[1];
    if (!(stream >> test_number))
        return (ERROR_NOT_INTEGER, 1);
    if (test_number == 0)
        extremos();
    else if (test_number == 1)
        validos();
    else if (test_number == 2)
        construtores();
    else
        return (ERROR_OUT_OF_RANGE, 1);
    return (0);
}





