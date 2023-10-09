#include <iostream>
# include <fstream>
#include <cmath>

class Fixed
{
        private :
            int  numberValue;
            const static  int fractionalBits = 8;
        
        public :
            Fixed();
            Fixed(const Fixed &fixedNumber);
            Fixed(const int num);
            Fixed(const float floating);

            Fixed &operator =(const Fixed &otherCopy);

            int getRawBits(void) const;
            void setRawBits(int const raw);
            float toFloat( void ) const;
            int toInt( void ) const;

            bool operator>(const Fixed& compareTo) const;
		    bool operator<(const Fixed& compareTo) const;
		    bool operator>=(const Fixed& compareTo) const;
		    bool operator<=(const Fixed& compareTo) const;
		    bool operator==(const Fixed& compareTo) const;
		    bool operator!=(const Fixed& compareTo) const;

		    Fixed operator+(const Fixed& otherValue);
		    Fixed operator-(const Fixed& otherValue);
		    Fixed operator*(const Fixed& otherValue);
		    Fixed operator/(const Fixed& otherValue);

		    Fixed operator++(void);
		    Fixed operator--(void);
		    Fixed operator++(int unusedParameter);
		    Fixed operator--(int unusedParameter);

		    static Fixed& min(Fixed& firstNumber, Fixed& secondNumber);
		    static Fixed& max(Fixed& firstNumber, Fixed& secondNumber);
		    static const Fixed& min(const Fixed& firstNumber, const Fixed& secondNumber);
		    static const Fixed& max(const Fixed& firstNumber, const Fixed& secondNumber);

            ~Fixed();
};
std :: ostream& operator <<(std :: ostream& output, const Fixed &fixedNumber);