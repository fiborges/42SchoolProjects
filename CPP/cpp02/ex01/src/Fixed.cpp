#include "Fixed.hpp"


Fixed :: Fixed ()
{
    numberValue = 0;
    std :: cout << "Default constructor called" << std :: endl;
}

Fixed :: Fixed(const Fixed &fixedNumber)
{
    std :: cout << "Copy constructor called" <<  std :: endl;
    *this = fixedNumber;
}

Fixed :: Fixed(const int num):
numberValue (num << fractionalBits)
{
    std :: cout << "Int constructor called" <<  std :: endl;
}

Fixed :: Fixed(const float floating)
:numberValue ((int)(roundf(floating * (1 << fractionalBits))))
{
     std :: cout << "Float constructor called" <<  std :: endl;
}

Fixed &Fixed ::  operator =(const Fixed &otherCopy)
{
    if (this != &otherCopy)
    {
        numberValue = otherCopy.numberValue;
    }
    std :: cout << "Copy assignment operator called" <<  std :: endl;
    return *this;
}

float Fixed :: toFloat(void) const
{
    return ((float)(numberValue) / (1 << fractionalBits));
}

int Fixed :: toInt(void) const
{
    return (numberValue >> fractionalBits);
}

void Fixed :: setRawBits(int const raw)
{
    numberValue = raw;
}

int Fixed ::  getRawBits(void) const
{
    return (numberValue);
}

Fixed :: ~Fixed()
{
    std :: cout << "Destructor called " <<  std :: endl;
}

std :: ostream& operator <<(std :: ostream& output, const Fixed &fixedNumber)
{
    output << fixedNumber.toFloat();
    return (output);
}