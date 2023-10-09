#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	LOG(PURPLE "WrongCat default constructor called." RESET);
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy)
{
	LOG(PURPLE "WrongCat copy constructor called." RESET);
}

WrongCat::~WrongCat(void)
{
	LOG(RED "WrongCat destroyed." RESET);
}

WrongCat& WrongCat::operator=(const WrongCat& otherCopy)
{
	LOG(PURPLE "WrongCat assigment operator called." RESET);
	if (this == &otherCopy)
		return (*this);
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << CYAN << "WrongCat: DONT Meowww..." << RESET << std::endl;
}