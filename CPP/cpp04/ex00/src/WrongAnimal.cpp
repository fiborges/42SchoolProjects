#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	LOG(BLUE "WrongAnimal default constructor called." RESET);
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	LOG(BLUE "WrongAnimal copy constructor called." RESET);
	this->type = copy.type;
}

WrongAnimal::~WrongAnimal(void)
{
	LOG(RED "WrongAnimal destroyed." RESET);
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& otherCopy)
{
	LOG(BLUE "WrongAnimal assignment operator called." RESET);
	if (this == &otherCopy)
		return (*this);
	this->type = otherCopy.type;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << CYAN << "WrongAnimal: ..." << RESET << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (this->type);	
}

void WrongAnimal::setType(const std::string& type)
{
	this->type = type;
}