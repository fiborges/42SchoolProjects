/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <firibeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 12:55:46 by firibeir          #+#    #+#             */
/*   Updated: 2024/04/07 12:55:46 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "Error" << std::endl;
	else
	{
		try
		{
			PmergeMe pmalgoritm(argv);
			std::cout << "Before: ";
			pmalgoritm.printVec();
			pmalgoritm.algorithm();
		}
		catch(const std::exception &exept)
		{
			std::cerr << exept.what() << std::endl;
		}
	}
	return 0;
}
