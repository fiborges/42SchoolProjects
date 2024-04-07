/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <firibeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 11:01:21 by firibeir          #+#    #+#             */
/*   Updated: 2024/04/06 11:01:22 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>
#include <string>

// Definições de cores para saída de texto
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

int main(void) {
    // Demonstração com inteiros
    int a = 2;
    int b = 3;
    std::cout << BLUE << "Demonstração com Inteiros:" << RESET << std::endl;
    std::cout << GREEN << "Antes: a = " << RESET << a << GREEN << ", b = " << RESET << b << std::endl;
    ::swap(a, b);
    std::cout << GREEN << "Depois de swap: a = " << RESET << a << GREEN << ", b = " << RESET << b << std::endl;
    std::cout << YELLOW << "min(a, b) = " << RESET << ::min(a, b) << " (o menor entre a e b)" << std::endl;
    std::cout << YELLOW << "max(a, b) = " << RESET << ::max(a, b) << " (o maior entre a e b)" << std::endl;
    std::cout << std::endl;

    // Demonstração com strings
    std::string c = "chaine1";
    std::string d = "chaine2";
    std::cout << BLUE << "Demonstração com Strings:" << RESET << std::endl;
    std::cout << GREEN << "Antes: c = " << RESET << c << GREEN << ", d = " << RESET << d << std::endl;
    ::swap(c, d);
    std::cout << GREEN << "Depois de swap: c = " << RESET << c << GREEN << ", d = " << RESET << d << std::endl;
    std::cout << YELLOW << "min(c, d) = " << RESET << ::min(c, d) << " (o que vem primeiro alfabeticamente)" << std::endl;
    std::cout << YELLOW << "max(c, d) = " << RESET << ::max(c, d) << " (o que vem depois alfabeticamente)" << std::endl;
    std::cout << std::endl;

    // Demonstração com pontos flutuantes
    double e = 2.718;
    double f = 3.1415;
    std::cout << BLUE << "Demonstração com Pontos Flutuantes:" << RESET << std::endl;
    std::cout << GREEN << "Antes: e = " << RESET << e << GREEN << ", f = " << RESET << f << std::endl;
    ::swap(e, f);
    std::cout << GREEN << "Depois de swap: e = " << RESET << e << GREEN << ", f = " << RESET << f << std::endl;
    std::cout << YELLOW << "min(e, f) = " << RESET << ::min(e, f) << " (o menor valor)" << std::endl;
    std::cout << YELLOW << "max(e, f) = " << RESET << ::max(e, f) << " (o maior valor)" << std::endl;

    return 0;
}

