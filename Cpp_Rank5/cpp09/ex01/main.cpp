/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <firibeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 12:50:53 by firibeir          #+#    #+#             */
/*   Updated: 2024/04/07 12:50:53 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cctype>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage example: ./RPN \"2 3 + 4*\"" << std::endl;
		return (-1);
	}
	RPN inst;
	std::string str(argv[1]);
	std::string check = "0123456789+-*/ ";
	int i = 0;
	while (str[i])
	{
		if (check.find(str[i]) == std::string::npos)
		{
			std::cout << "Error" << std::endl;
			return (-1);
		}
		if (isdigit(str[i]))
		{
			if (str[i + 1] && str[i + 1] != ' ')
			{
				std::cout << "Error" << std::endl;
				return (-1);
			}
			inst.pushNumber(atoi(&str[i]));
		}
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			if (!inst.calculation(str[i]))
				return (-1);
		}
		i++;
	}
	std::cout << inst.topStack() << std::endl;
	return (0);
}