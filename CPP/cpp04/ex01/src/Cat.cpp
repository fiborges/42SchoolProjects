#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(void)
{
	LOG(MAGENTA "Cat default constructor called." RESET);
	this->type = "Cat";
}

Cat::Cat(const Cat& cat) : Animal(cat)
{
	LOG(MAGENTA "Cat copy constructor called." RESET);
}

Cat::~Cat(void)
{
	LOG(RED "Cat destroyed." RESET);
}

Cat& Cat::operator=(const Cat& cat)
{
	LOG(MAGENTA "Cat assigment operator called." RESET);
	if (this == &cat)
		return (*this);
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << CYAN << "Meowww...Meowww..." << RESET << std::endl;
}

Brain *Cat::getBrain(void) const
{
	return (this->brain);
}