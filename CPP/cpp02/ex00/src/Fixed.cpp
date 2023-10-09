#include "Fixed.hpp"

Fixed :: Fixed()
{
	std::cout << "Default constructor called." << std::endl;
	this->numberValue = 0;
}

Fixed :: Fixed(Fixed& fixedNumber)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = fixedNumber;
}

Fixed :: ~Fixed()
{
	std::cout << "Destructor called." << std::endl;
}

Fixed& Fixed :: operator=(Fixed& otherCopy)
{
	std::cout << "Copy assignment operator called." << std::endl;
	if (this == &otherCopy)
		return (*this);
	this->numberValue = otherCopy.getRawBits();
	return (*this);
}
 
int Fixed :: getRawBits(void) const
{
	std::cout << "getRawBits member function called." << std::endl;
	return (this->numberValue);
}
 
void Fixed :: setRawBits(int const raw)
{
	this->numberValue = raw;
}