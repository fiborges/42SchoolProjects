#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include <iostream>

# include <fstream>

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string target;

	public:
		//! Constructors and destructor
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		~ShrubberyCreationForm();

		//! Operator overloading
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& right);

		//! Others
		void execute(void) const;

};

#endif