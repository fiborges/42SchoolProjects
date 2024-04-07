/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <firibeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:18:07 by firibeir          #+#    #+#             */
/*   Updated: 2024/04/04 11:18:08 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	
}

Intern::Intern(const Intern& copy)
{
	*this = copy;
}

Intern::~Intern()
{
	
}

Intern& Intern::operator=(const Intern& right)
{
	if (this == &right)
		return (*this);
	return (*this);
}

AForm *Intern::makeForm(const std::string& name, const std::string& target)
{
	AForm *(Intern::*factory[3])(const std::string&) =
	{
		&Intern::makePresidentialForm,
		&Intern::makeRobotomyForm,
		&Intern::makeShrubberyForm
	};
	std::string names[3] =
	{
		"Presidential Pardon",
		"Robotomy Request",
		"Shrubbery Creation"
	};

	for (int i = 0; i < 3; i++)
		if (name == names[i])
			return ((this->*factory[i])(target));
	throw FormNotFoundException();
}

AForm *Intern::makePresidentialForm(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeRobotomyForm(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makeShrubberyForm(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

const char* Intern::FormNotFoundException::what() const throw()
{
	return ("\n\tIntern: Unknown form name\n");
}