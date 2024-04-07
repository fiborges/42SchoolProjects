/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <firibeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:07:41 by firibeir          #+#    #+#             */
/*   Updated: 2024/04/06 16:07:59 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <sstream>
#include <ctime>

#define LOG(title) std::cout << GREEN "\n\t===== Testing " << title << " =====\n\n" RESET;

void testShortestSpanFunctionality(void)
{
    LOG("Shortest Span");

    try
    {
        Span span(5);

        std::cout << "Adding numbers: 1, 2, 100, 3, 101\n";
        span.addNumber(1);
        span.addNumber(2);
        span.addNumber(100);
        span.addNumber(3);
        span.addNumber(101);
        std::cout << span;

        std::cout << "Shortest span: " << span.shortestSpan() << "\n";
    }
    catch(const std::exception& e)
    {
        std::cout << RED << e.what() << RESET << "\n";
    }
}

void testLongestSpanFunctionality(void)
{
    LOG("Longest Span");

    try
    {
        Span span(4);

        std::cout << "Adding numbers: 1, 1000, 3, 999\n";
        span.addNumber(1);
        span.addNumber(1000);
        span.addNumber(3);
        span.addNumber(999);
        std::cout << span;

        std::cout << "Longest span: " << span.longestSpan() << "\n";
    }
    catch(const std::exception& e)
    {
        std::cout << RED << e.what() << RESET << "\n";
    }
}

void testAddNumberFunctionality(void)
{
    LOG("Add Number");

    Span span(2);
    std::cout << "Initial span capacity is 2.\n";

    try
    {
        std::cout << "Adding number: 42\n";
        span.addNumber(42);
        std::cout << "Adding number: 21\n";
        span.addNumber(21);
        std::cout << span;

        std::cout << "Trying to add a fourth number (333) to a full span...\n";
        span.addNumber(333);
    } catch (const Span::FullExeption& e) {
    	std::cout << e.what() << "\n";
	} catch (const std::exception& e) {
    	std::cout << "Standard exception: " << e.what() << "\n";
	}
}

void testNoSpanFunctionality(void)
{
    LOG("Empty and One-Element Span");

    try
    {
        Span emptySpan(0);
        std::cout << "Attempting to calculate span in an empty span...\n";
        emptySpan.shortestSpan();
    }
    catch(const std::exception& e)
    {
        std::cout << RED << "Empty span error: " << e.what() << RESET << "\n";
    }

    try
    {
        Span oneElementSpan(1);
        oneElementSpan.addNumber(42);
        std::cout << "Attempting to calculate span in a span with only one element...\n";
        oneElementSpan.shortestSpan();
    }
    catch(const std::exception& e)
    {
        std::cout << RED << "One-element span error: " << e.what() << RESET << "\n";
    }
}

void testLargeSetFunctionality(void)
{
    LOG("Large Span Set");

    try
    {
        Span largeSpan(10000);
        std::cout << "Filling a large span with 10000 random numbers...\n";
        largeSpan.fillWithRandomNumbers();

        const std::vector<int>& numbers = largeSpan.retrieveStorage();

        
		std::cout << "Numbers in the span:\n";
		for (std::vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); ++it) {
    		std::cout << *it << " ";
		}
		std::cout << "\n";

        std::cout << "Calculating shortest and longest spans...\n";
        std::cout << "Shortest span: " << largeSpan.shortestSpan() << "\n";
        std::cout << "Longest span: " << largeSpan.longestSpan() << "\n";
    }
    catch(const std::exception& e)
    {
        std::cout << RED << e.what() << RESET << "\n";
    }
}

int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <test_number>\n";
        return 1;
    }

    std::srand(static_cast<unsigned int>(std::time(NULL)));

    int testNumber = std::atoi(argv[1]);

    switch (testNumber) {
        case 0:
            testShortestSpanFunctionality();
            break;
        case 1:
            testLongestSpanFunctionality();
            break;
        case 2:
            testAddNumberFunctionality();
            break;
        case 3:
            testNoSpanFunctionality();
            break;
        case 4:
            testLargeSetFunctionality();
            break;
        default:
            std::cerr << "Invalid test number. Please provide a valid test number between 0 and 4.\n";
            return 1;
    }

    return 0;
}
