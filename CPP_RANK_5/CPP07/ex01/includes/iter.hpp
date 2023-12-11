#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <sstream>

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define RESET	"\033[0m"

template <class T>
void iter(T *array, int len, void (*f)(T&))
{
	for (int i = 0; i < len; i++)
		(*f)(array[i]);	
}

template <class T>
void print(T& val)
{
	std::cout << val << std::endl;
}

#endif