#include "Dog.hpp"

Dog::Dog(void)
{
	LOG(YELLOW "Dog default constructor called." RESET);
	this->type = "Dog";
}

Dog::Dog(const Dog& dog) : Animal(dog)
{
	LOG(YELLOW "Dog copy constructor called." RESET);
}

Dog::~Dog(void)
{
	LOG(RED "Dog destroyed." RESET);
}

Dog& Dog::operator=(const Dog& dog)
{
	LOG( YELLOW "Dog assigment operator called." RESET);
	if (this == &dog)
		return (*this);
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << CYAN << "BARK!!! BARK!!!" << RESET << std::endl;
}