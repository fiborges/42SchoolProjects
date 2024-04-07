/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <firibeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:59:16 by firibeir          #+#    #+#             */
/*   Updated: 2024/04/06 16:59:17 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <string>

#define LOG(x) std::cout << GREEN << "\n=== Testing " << x << " ===\n" << RESET

template<typename Iterable>
void printContainer(const Iterable& container, const std::string& message = "") {
    std::cout << CYAN << message << RESET;
    for (typename Iterable::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void testPushAndTop() {
    LOG("Push and Top");
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    printContainer(mstack, "Stack elements after push: ");
    std::cout << "Top element: " << mstack.top() << std::endl;
}

void testPopAndSize() {
    LOG("Pop and Size");
    MutantStack<int> mstack;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);

    printContainer(mstack, "Stack elements before pop: ");
    mstack.pop();
    printContainer(mstack, "Stack elements after pop: ");
    std::cout << "Stack size: " << mstack.size() << std::endl;
}

void testIteration() {
    LOG("Iteration");
    MutantStack<int> mstack;
    for (int i = 0; i < 5; ++i) {
        mstack.push(i);
    }

    printContainer(mstack, "Iterating through stack elements: ");
}

void testCopyConstructorAndAssignment() {
    LOG("Copy Constructor and Assignment Operator");
    MutantStack<int> original;
    for (int i = 0; i < 5; ++i) {
        original.push(i);
    }

    MutantStack<int> copyConstructed(original);
    printContainer(copyConstructed, "Copy constructed stack: ");

    MutantStack<int> assigned;
    assigned = original;
    printContainer(assigned, "Assigned stack: ");
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <test_number>\n";
        return 1;
    }

    int testNumber = std::atoi(argv[1]);

    switch (testNumber) {
        case 1:
            testPushAndTop();
            break;
        case 2:
            testPopAndSize();
            break;
        case 3:
            testIteration();
            break;
        case 4:
            testCopyConstructorAndAssignment();
            break;
        default:
            std::cerr << "Invalid test number. Please provide a valid test number between 1 and 4.\n";
            return 1;
    }

    return 0;
}

