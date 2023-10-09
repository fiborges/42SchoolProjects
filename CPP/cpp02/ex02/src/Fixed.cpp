#include "Fixed.hpp"

Fixed :: Fixed()
{
	// std::cout << "Default constructor called." << std::endl;
	this->numberValue = 0;
}

Fixed :: Fixed(const int num)
{
	this->numberValue = num << Fixed::fractionalBits;
}

Fixed :: Fixed(const float floating)
{
	this->numberValue = (int)(roundf(floating * (1 << Fixed::fractionalBits)));
}

Fixed :: Fixed(const Fixed& fixedNumber)
{
	*this = fixedNumber;
}

Fixed :: ~Fixed()
{
	// std::cout << "Destructor called." << std::endl;
}
 
int Fixed :: getRawBits(void) const
{
	return (this->numberValue);
}
 
void Fixed :: setRawBits(int const raw)
{
	this->numberValue = raw;
}

float Fixed :: toFloat(void) const
{
	return ((float)this->numberValue / (float)(1 << Fixed::fractionalBits));
}

int Fixed :: toInt(void) const
{
	return (this->numberValue >> Fixed::fractionalBits);
}

Fixed& Fixed :: operator=(const Fixed& otherCopy)
{	
	if (this == &otherCopy)
		return (*this);
	this->numberValue = otherCopy.getRawBits();
	return (*this);
}

bool Fixed :: operator>(const Fixed& compareTo) const
{
	return (this->getRawBits() > compareTo.getRawBits());
}

bool Fixed :: operator<(const Fixed& compareTo) const
{
	return (this->getRawBits() < compareTo.getRawBits());
}

bool Fixed :: operator>=(const Fixed& compareTo) const
{
	return (this->getRawBits() >= compareTo.getRawBits());
}

bool Fixed :: operator<=(const Fixed& compareTo) const
{
	return (this->getRawBits() <= compareTo.getRawBits());
}

bool Fixed :: operator==(const Fixed& compareTo) const
{
	return (this->getRawBits() == compareTo.getRawBits());
}

bool Fixed :: operator!=(const Fixed& compareTo) const
{
	return (this->getRawBits() != compareTo.getRawBits());
}

Fixed Fixed :: operator+(const Fixed& otherValue)
{
	return Fixed(this->toFloat() + otherValue.toFloat());
}

Fixed Fixed :: operator-(const Fixed& otherValue)
{
	return Fixed(this->toFloat() - otherValue.toFloat());
}

Fixed Fixed :: operator*(const Fixed& otherValue)
{
	return Fixed(this->toFloat() * otherValue.toFloat());
}

Fixed Fixed :: operator/(const Fixed& otherValue)
{
	return Fixed(this->toFloat() / otherValue.toFloat());
}

Fixed Fixed :: operator++(void)
{	
	this->numberValue++;
	return (*this);
}

Fixed Fixed :: operator--(void)
{
	this->numberValue--;
	return (*this);
}

Fixed Fixed :: operator++(int unusedParameter)
{
	Fixed clone(*this);

	(void) unusedParameter;
	++(*this);
	return (clone);
}

Fixed Fixed :: operator--(int unusedParameter)
{
	Fixed clone(*this);

	(void) unusedParameter;
	--(*this);
	return (clone);	
}

std::ostream& operator<<(std::ostream& output, const Fixed& fixedNumber)
{
	output << fixedNumber.toFloat();
	return (output);
}

Fixed& Fixed :: min(Fixed& firstNumber, Fixed& secondNumber)
{	
	return (firstNumber < secondNumber ? firstNumber : secondNumber); 
}

const Fixed& Fixed :: min(const Fixed& firstNumber, const Fixed& secondNumber)
{
	return (firstNumber < secondNumber ? firstNumber : secondNumber); 
}

Fixed& Fixed :: max(Fixed& firstNumber, Fixed& secondNumber)
{
	return (firstNumber > secondNumber ? firstNumber : secondNumber); 
}

const Fixed& Fixed :: max(const Fixed& firstNumber, const Fixed& secondNumber)
{
	return (firstNumber > secondNumber ? firstNumber : secondNumber); 
}