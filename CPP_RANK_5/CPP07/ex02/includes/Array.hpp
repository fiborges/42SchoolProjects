#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <sstream>

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define CYAN	"\033[1;36m"
# define RESET	"\033[0m"

template <class T>
class Array
{
	private:
		T *array;
		unsigned int n;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& copy);
		~Array();

		unsigned int size(void) const;

		Array& operator=(const Array& right);
		T& operator[](unsigned int index);

	class IndexOutOfBoundsException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
		
};

#include "Array.tpp"

#endif