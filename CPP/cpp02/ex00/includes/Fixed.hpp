#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int numberValue;
		static const int fractionalBits = 8;
		
	public:
		//construtor padrão
		Fixed();
        //construtor por cópia
		Fixed(Fixed &fixedNumber);
        //destrutor padrão
		~Fixed();

		//operador de atribuição por copia
		Fixed& operator=(Fixed &otherCopy);

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif