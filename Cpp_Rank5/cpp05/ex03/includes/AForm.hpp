/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <firibeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:17:28 by firibeir          #+#    #+#             */
/*   Updated: 2024/04/04 11:17:29 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

# define PRINT_ERROR(x) 		std::cout << x << std::endl
# define ERROR_MESSAGE(e)	PRINT_ERROR("Usage: " << e << " test_number")
# define ERROR_NOT_INTEGER	PRINT_ERROR("Error: test number must be a number")
# define ERROR_OUT_OF_RANGE	PRINT_ERROR("Error: test number must be bounded between 0 and 3")

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool isSigned;
		const int signGrade;
		const int execGrade;
		static const int MAX_GRADE = 1;
		static const int MIN_GRADE = 150;
	
	public:
		AForm(void);
		AForm(const AForm& copy);
		AForm(const std::string& name, int signGrade, int execGrade);
		AForm& operator=(const AForm& right);
		virtual ~AForm(void);

		void beSigned(const Bureaucrat& b);
		void execute(Bureaucrat const& executor) const;
		virtual void execute(void) const = 0;

		std::string getName(void) const;
		bool hasBeenSigned(void) const;
		int getSignGrade(void) const;
		int getExecutionGrade(void) const;

		void setIsSigned(bool isSigned);

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
	class UnsignedFormException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class BureaucratGradeTooLow : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif