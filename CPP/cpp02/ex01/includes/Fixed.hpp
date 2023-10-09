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

            ~Fixed();
};
std :: ostream& operator <<(std :: ostream& output, const Fixed &fixedNumber);