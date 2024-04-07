/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <firibeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:18:12 by firibeir          #+#    #+#             */
/*   Updated: 2024/04/04 11:18:13 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "Intern.hpp"

void testMakingInvalidForm(void)
{
	try
	{
		AForm* rrf;
		Intern someRandomIntern;
		
		rrf = someRandomIntern.makeForm(GREEN "presidential form" RESET, CYAN "Bender" RESET);
		std::cout << *rrf << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << '\n';
	}
}

void testMakingValidForm(const std::string &name, const std::string &target)
{
	try
	{
		AForm* rrf;
		Intern someRandomIntern;
		Bureaucrat b(MAGENTA "Dumbledore" RESET, 1);
		
		rrf = someRandomIntern.makeForm(name, target);
		std::cout << *rrf << std::endl;

		b.signForm(*rrf);
		std::cout << *rrf << std::endl;
		b.executeForm(*rrf);
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << '\n';
	}
}

int main(int argc, char **argv)
{
	int					test_number;
	std::stringstream	output;

	std::srand(time(NULL));
	if (argc < 2)
		return (ERROR_MESSAGE(argv[0]), 1);
	output << argv[1];
	if (!(output >> test_number))
		return (ERROR_NOT_INTEGER, 1);
	if (test_number < 0 || test_number > 3)
		return (ERROR_OUT_OF_RANGE, 1);
	if (test_number == 0)
		testMakingValidForm("Presidential Pardon", "Tomas Edison");
	else if (test_number == 1)
		testMakingValidForm("Robotomy Request", "HUMAN BRAIN");
	else if (test_number == 2)
		testMakingValidForm("Shrubbery Creation", "drawing");
	else
		testMakingInvalidForm();
	return (0);
}






