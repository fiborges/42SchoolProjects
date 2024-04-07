/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <firibeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:43:08 by firibeir          #+#    #+#             */
/*   Updated: 2024/04/06 14:43:09 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <limits>
#include <iterator>

template <typename T>
void printContainer(const T& container, const std::string& name)
{
    std::cout << name << " contains:";
    for(typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << std::endl;
}

template <typename T>
void testContainerFind(T& container, const std::string& name, int tofind)
{
    try
    {
        container.clear();
        container.push_back(91);
        container.push_back(42);
        container.push_back(32768);
        container.push_back(std::numeric_limits<int>::max());
        container.push_back(-3);

        // Print container contents before searching
        printContainer(container, name);

        int pos = easyfind(container, tofind);
        std::cout << GREEN << "Value " << tofind << " found in " << name << " at position " << pos << RESET << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << RED << "Value " << tofind << " not found in " << name << RESET << std::endl;
    }
    std::cout << std::endl;
}

int main(void)
{
    std::vector<int> vectorContainer;
    std::list<int> listContainer;
    std::deque<int> dequeContainer;

    int testValues[] = {91, 42, -3, 100, std::numeric_limits<int>::max()};
    size_t numValues = sizeof(testValues) / sizeof(testValues[0]);

    for (size_t i = 0; i < numValues; ++i)
    {
        testContainerFind(vectorContainer, "Vector", testValues[i]);
        testContainerFind(listContainer, "List", testValues[i]);
        testContainerFind(dequeContainer, "Deque", testValues[i]);
    }

    return 0;
}






