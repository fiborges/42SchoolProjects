/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <firibeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:15:50 by firibeir          #+#    #+#             */
/*   Updated: 2024/04/04 11:15:52 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool isSigned;
		const int signGrade;
		const int execGrade;
		static const int MAX_GRADE = 1;
		static const int MIN_GRADE = 150;
	
	public:
		Form(void);
		Form(const Form& copy);
		Form(const std::string& name, int signGrade, int execGrade);
		Form& operator=(const Form& right);
		~Form(void);

		void beSigned(const Bureaucrat& b);

		std::string getName(void) const;
		bool hasBeenSigned(void) const;
		int getSignGrade(void) const;
		int getExecutionGrade(void) const;

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();

	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif