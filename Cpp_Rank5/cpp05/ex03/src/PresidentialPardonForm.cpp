/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <firibeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:18:16 by firibeir          #+#    #+#             */
/*   Updated: 2024/04/04 11:18:17 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : \
	AForm("Presidential Pardon Form. \n", 25, 5), target("Someone")
{
	
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : \
	AForm("Presidential Pardon Form! \n", 25, 5), target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : \
	AForm(copy), target(copy.target)
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{
	
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& right)
{
	if (this == &right)
		return (*this);
	this->setIsSigned(right.hasBeenSigned());
	return (*this);
}

void PresidentialPardonForm::execute(void) const
{
	std::cout << this->target << " has been pardoned by Filipa de Lencastre." << std::endl;
}