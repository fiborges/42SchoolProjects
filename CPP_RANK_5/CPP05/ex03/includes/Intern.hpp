#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <sstream>

# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& copy);
		~Intern();

		Intern& operator=(const Intern& right);

		AForm *makeForm(const std::string& name, const std::string& target);
		AForm *makePresidentialForm(const std::string &target);
		AForm *makeRobotomyForm(const std::string &target);
		AForm *makeShrubberyForm(const std::string &target);

		class FormNotFoundException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif