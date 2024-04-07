/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <firibeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:16:06 by firibeir          #+#    #+#             */
/*   Updated: 2024/04/04 11:21:59 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : name(CYAN "default_form" RESET), signGrade(1), execGrade(1)
{
	this->isSigned = false;
}

Form::Form(const Form& copy) : name(copy.name), signGrade(copy.signGrade), \
	execGrade(copy.signGrade)
{
	this->isSigned = copy.isSigned;
}

Form::Form(const std::string& name, int signGrade, int execGrade) : name(name), \
	signGrade(signGrade), execGrade(execGrade)
{
	if (signGrade < Form::MAX_GRADE || execGrade < Form::MAX_GRADE)
		throw Form::GradeTooHighException();
	else if (signGrade > Form::MIN_GRADE || execGrade > Form::MIN_GRADE)
		throw Form::GradeTooLowException();
	this->isSigned = false;
	std::cout << this->name << GREEN << "Form was created."<< RESET << std::endl;
}

Form::~Form(void)
{
	
}

Form& Form::operator=(const Form& right)
{
	if (this == &right)
		return (*this);
	this->isSigned = right.isSigned;
	return (*this);
}

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > this->signGrade)
		throw Form::GradeTooLowException();
	this->isSigned = true;
}

std::string Form::getName(void) const
{
	return (this->name);
}

bool Form::hasBeenSigned(void) const
{
	return (this->isSigned);
}

int Form::getSignGrade(void) const
{
	return (this->signGrade);
}

int Form::getExecutionGrade(void) const
{
	return (this->execGrade);
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
	std::string sign = form.hasBeenSigned() ? " ✅ " : " ❌ ";
	
	out << BLUE "Form: " RESET + form.getName() + "\n";
	out << BLUE "\tSigned? " RESET + sign + "\n";
	out << BLUE "\n Signing Grade: " RESET << form.getSignGrade() << "\n";
	out << BLUE "\tExecution Grade: " RESET << form.getExecutionGrade() << "\n";
	out << std::endl;
	return (out);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return (RED "\n\tForm Exception: grade is too high\n" RESET);
}

const char *Form::GradeTooLowException::what() const throw()
{
	return (RED "\n\tForm Exception: grade is too low\n" RESET);
}