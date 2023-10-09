#include "Animal.hpp"

Animal::Animal(void)
{
	LOG(GREEN "Animal default constructor called." RESET);
}

Animal::Animal(const Animal& copy)
{
	LOG(GREEN "Animal copy constructor called." RESET);
	this->type = copy.type;
}

Animal::~Animal(void)
{
	LOG(RED "Animal destroyed." RESET);
}

Animal& Animal::operator=(const Animal& otherCopy)
{
	LOG(GREEN "Animal assignment operator called." RESET);
	if (this == &otherCopy)
		return (*this);
	this->type = otherCopy.type;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << CYAN << "Animal: ..." << RESET << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->type);	
}

void Animal::setType(const std::string& type)
{
	this->type = type;
}