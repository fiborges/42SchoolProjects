/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <firibeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 11:01:41 by firibeir          #+#    #+#             */
/*   Updated: 2024/04/06 11:42:29 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>
#include <sstream> // Para std::istringstream
#include <iomanip> // Para std::setprecision
#include <cctype>  // Para std::toupper

template <typename T>
void print(T& value)
{
	std::cout << value << std::endl;
}

// Função para incrementar valores (demonstração com inteiros)
template <typename T>
void increment(T &x) {
    ++x;
}

void toUpperCase(std::string &str) {
    for (size_t i = 0; i < str.size(); ++i) {
        str[i] = std::toupper(str[i]);
    }
}

// Função para imprimir valores de ponto flutuante com precisão fixa
void printWithPrecision(double &val) {
    std::cout << std::fixed << std::setprecision(2) << val << std::endl;
}

void testArrayModifications() {
    std::cout << GREEN << "\nTestando Modificação de Array de Inteiros:\n" << RESET;
    int nums[] = {1, 2, 3, 4, 5};
    std::cout << YELLOW << "Antes: " << RESET;
    iter(nums, 5, print); // Imprime valores originais
    iter(nums, 5, increment<int>); // Incrementa cada elemento
    std::cout << YELLOW << "Depois: " << RESET;
    iter(nums, 5, print); // Imprime valores modificados
}

void testStringUpperCase() {
    std::cout << GREEN << "\nTestando Conversão para Maiúsculas em Array de Strings:\n" << RESET;
    std::string strs[] = {"hello", "world", "iter", "template"};
    std::cout << YELLOW << "Antes: " << RESET;
    iter(strs, 4, print);
    iter(strs, 4, toUpperCase); // Converte cada string para maiúsculas
    std::cout << YELLOW << "Depois: " << RESET;
    iter(strs, 4, print); // Imprime strings modificadas
}

void testPrecisionPrinting() {
    std::cout << GREEN << "\nTestando Impressão de Números de Ponto Flutuante com Precisão:\n" << RESET;
    double floats[] = {3.14159, 2.71828, 1.61803};
    iter(floats, 3, printWithPrecision); // Imprime valores com duas casas decimais
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << RED << "Uso: " << argv[0] << " <opção de teste>\n" << RESET;
        return 1;
    }

    std::istringstream iss(argv[1]);
    int testOption;
    if (!(iss >> testOption)) {
        std::cerr << RED << "Erro: O argumento deve ser um número inteiro.\n" << RESET;
        return 2;
    }

    switch (testOption) {
        case 0: testArrayModifications(); break;
        case 1: testStringUpperCase(); break;
        case 2: testPrecisionPrinting(); break;
        default: std::cerr << RED << "Opção de teste inválida.\n" << RESET; return 3;
    }

    return 0;
}

