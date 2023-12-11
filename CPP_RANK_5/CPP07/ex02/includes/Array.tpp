#include "Array.hpp"

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define RESET	"\033[0m"

template <class T>
Array<T>::Array() : n(0)
{
	this->array = new T[0];
}

template <class T>
Array<T>::Array(unsigned int n) : n(n)
{
	this->array = new T[this->n];
	for (unsigned int i = 0; i < this->n; i++)
		this->array[i] = T();
}

template <class T>
Array<T>::Array(const Array& copy)
{
	this->array = NULL;
	*this = copy;	
}

template <class T>
Array<T>::~Array()
{
	delete [] array;
}

template <class T>
unsigned int Array<T>::size(void) const
{
	return (this->n);
}

template <class T>
Array<T>& Array<T>::operator =(const Array<T>& right)
{
	if (this == &right)
		return (*this);
	delete [] this->array;
	this->n = right.n;
	this->array = new T[this->n];
	for (unsigned int i = 0; i < this->n; i++)
		this->array[i] = right.array[i];
	return (*this);
}

template <class T>
T& Array<T>::operator [](unsigned int index)
{
	if (index < 0 || index >= this->n)
		throw Array<T>::IndexOutOfBoundsException();
	return (this->array[index]);
}

template <class T>
const char* Array<T>::IndexOutOfBoundsException::what() const throw()
{
	return (RED "Array Exception: index is out of bounds" RESET);
}