#include "Span.hpp"

Span::Span() : N(0)
{
	
}

Span::Span(const Span& otherCopy)
{
	*this = otherCopy;
}

Span::Span(unsigned int N) : N(N)
{

}

Span::~Span()
{
	
}

Span& Span::operator=(const Span& right)
{
	if (this == &right)
		return (*this);
	this->N = right.N;
	this->storage = right.storage;
	return (*this);
}

void Span::addNumber(int number)
{
	if (this->storage.size() == this->N)
		throw FullSpanException();
	this->storage.push_back(number);
}

int Span::calculateShortestSpan(void)
{
	int minDifference;
	std::vector<int>::const_iterator currentElement;

	if (this->storage.size() < 2)
		throw NoSpanException();
	
	std::sort(this->storage.begin(), this->storage.end());
	minDifference = std::numeric_limits<int>::max();
	for (currentElement = this->storage.begin() + 1; currentElement != this->storage.end(); currentElement++)
		if (*currentElement - *(currentElement - 1) < minDifference)
			minDifference = *currentElement - *(currentElement - 1);
	return (minDifference);
}

int Span::calculateLongestSpan(void)
{
	std::vector<int>::const_iterator minElement;
	std::vector<int>::const_iterator maxElement;

	if (this->storage.size() < 2)
		throw NoSpanException();
		
	minElement = std::min_element(this->storage.begin(), this->storage.end());
	maxElement = std::max_element(this->storage.begin(), this->storage.end());
	return (*maxElement - *minElement);
}

int generateRandomNumber(void)
{
	return (rand() % 100); 
}

void Span::fillWithRandomNumbers(void)
{
	this->storage.resize(N);	
	std::generate(this->storage.begin(), this->storage.end(), &generateRandomNumber);
	std::sort(this->storage.begin(), this->storage.end());
}

unsigned int Span::size(void) const
{
	return (this->storage.size());
}

std::vector<int> Span::retrieveStorage(void) const
{
	return (this->storage);
}

const char *Span::FullSpanException::what() const throw()
{
	return (RED "Span Exception: can't add numbers to a full span." RESET);
}

const char *Span::NoSpanException::what() const throw()
{
	return (RED "Span Exception: can't find spans with less than 2 integers." RESET);
}

std::ostream& operator <<(std::ostream& out, const Span& span)
{
	std::vector<int> vec;

	vec = span.retrieveStorage();
	for (unsigned int i = 0; i < span.size(); i++)
		out << "storage[" << i << "] = " << vec[i] << "\n";
	out << std::endl;
	return (out);
}