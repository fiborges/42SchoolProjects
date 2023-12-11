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