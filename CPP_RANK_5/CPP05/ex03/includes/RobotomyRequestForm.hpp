#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include <iostream>

# include <fstream>

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		const std::string target;

	public:
		//! Constructors and destructor
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		~RobotomyRequestForm();

		//! Operator overloading
		RobotomyRequestForm& operator=(const RobotomyRequestForm& right);

		//! Others
		void execute(void) const;
};

#endif