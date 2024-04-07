/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <firibeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 11:41:10 by firibeir          #+#    #+#             */
/*   Updated: 2024/04/06 11:41:11 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

void testDefaultArrayCreation() {
    std::cout << GREEN << "\nTestando a Criação Padrão do Array:" << RESET << std::endl;
    std::cout << "Criando um Array<int> com 10 elementos inicializados com 0." << std::endl;

    Array<int> numbers(10);

    for (size_t i = 0; i < numbers.size(); i++) {
        std::cout << "Elemento no índice " << i << " é: " << numbers[i] << std::endl;
    }
}

void testArrayCopy() {
    std::cout << GREEN << "\nTestando a Cópia de Arrays:" << RESET << std::endl;
    std::cout << "Criando um Array<int> original e copiando seu conteúdo para um novo Array." << std::endl;

    Array<int> original(10);

    // Preencher o array original com o valor 42
    for (size_t i = 0; i < original.size(); i++) {
        original[i] = 42;
    }

    Array<int> copy = original; //cópia do array original

    // Modifica o primeiro elemento do array original
    original[0] = 21;

    // Mostrando os elementos
    for (size_t i = 0; i < copy.size(); i++) {
        std::cout << CYAN << "Elemento original no índice " << i << ": " << RESET << copy[i]
                  << CYAN << " (Elemento copiado no índice " << i << ": " << RESET << original[i] << ")\n";
    }
}

void testInvalidIndexHandling() {
    std::cout << GREEN << "\nTestando o Tratamento de Índices Inválidos:" << RESET << std::endl;
    std::cout << "Tentando acessar elementos em índices fora dos limites do Array." << std::endl;

    Array<int> numbers(10);
    // Testa acesso a um índice negativo
    try {
        numbers[-1] = 0; // Deve lançar uma exceção
    } catch (const std::exception &e) {
        std::cout << RED << "Exceção capturada (tentativa de definir valor no índice -1): " << e.what() << RESET << '\n';
    }

    // Testa acesso a um índice fora dos limites do tamanho do array
    try {
        numbers[numbers.size()] = 0;
    } catch (const std::exception &e) {
        std::cout << RED << "Exceção capturada (tentativa de definir valor no índice " << numbers.size() << "): " << e.what() << RESET << '\n';
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Uso: " << argv[0] << " <número do teste>" << std::endl;
        std::cerr << "0: Teste de Criação Padrão" << std::endl;
        std::cerr << "1: Teste de Cópia de Array" << std::endl;
        std::cerr << "2: Teste de Tratamento de Índices Inválidos" << std::endl;
        return 1;
    }

    int testNumber = std::atoi(argv[1]);

    switch (testNumber) {
        case 0:
            testDefaultArrayCreation();
            break;
        case 1:
            testArrayCopy();
            break;
        case 2:
            testInvalidIndexHandling();
            break;
        default:
            std::cerr << "Número de teste inválido. Por favor, escolha entre 0, 1, ou 2." << std::endl;
            return 1;
    }

    return 0;
}


