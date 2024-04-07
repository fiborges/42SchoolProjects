/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <firibeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:18:03 by firibeir          #+#    #+#             */
/*   Updated: 2024/04/04 11:19:39 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
	
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
{
    *this = copy;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
	if (grade < Bureaucrat::MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > Bureaucrat::MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	
}

std::string Bureaucrat::getName(void) const
{
	return (this->name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void Bureaucrat::incrementGrade(void)
{
	LOG(GREEN "\nIncrementing grade..." RESET);
	if (this->grade - 1 < Bureaucrat::MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrementGrade(void)
{	
	LOG(RED "\nDecrementing grade..." RESET);
	if (this->grade + 1 > Bureaucrat::MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

void Bureaucrat::signForm(AForm& form)
{
	if (this->grade <= form.getExecutionGrade())
		std::cout << this->name + " signed " + form.getName() << std::endl;
	else
		std::cout << this->name + " couldn't sign " + form.getName() \
			+ "(" << form.getSignGrade() << ") because their grade(" \
			<< this->grade << ") was too low" << std::endl;	
	form.beSigned(*this);
}

void Bureaucrat::executeForm(AForm const& form)
{
	form.execute(*this);
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& right)
{
	if (this == &right)
		return (*this);
	this->grade = right.grade;
	return (*this);
}

std::ostream& operator<<(std::ostream& output, const Bureaucrat& fixedNumber)
{
	output << "\n" << fixedNumber.getName() << ", bureaucrat grade ";
	output << fixedNumber.getGrade() << "." << std::endl;
	return (output);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("\n\tThe grade is too high.\n");
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("\n\tThe grade is too low.\n");
}