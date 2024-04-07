/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <firibeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:18:19 by firibeir          #+#    #+#             */
/*   Updated: 2024/04/04 11:18:20 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : \
	AForm("Robotomy Request Form. \n", 72, 45), target("Someone")
{
	
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : \
	AForm("Robotomy Request Form! \n", 72, 45), target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : \
	AForm(copy), target(copy.target)
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{
	
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& right)
{
	if (this == &right)
		return (*this);
	this->setIsSigned(right.hasBeenSigned());
	return (*this);
}

void RobotomyRequestForm::execute(void) const
{
	std::string message;

	std::cout << "...VVVrrrVVVrrr... *robotic drilling noise* ...VVrrrVvvrr..." << std::endl;
	if (std::rand() % 2 == 0)
		message = this->target + " has been robotomized successfully. \n";
	else
		message = "Robotomy on " + this->target + " failed.";
	std::cout << message << std::endl;
}