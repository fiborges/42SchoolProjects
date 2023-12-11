#include "MutantStack.hpp"

#define LOG(x) std::cout << GREEN << "\n\t0.0.0.0.0.0.0.0.0.0 TESTING " << x << " 0.0.0.0.0.0.0.0.0.0.0\n\n" << RESET

void testMutantStackFunctionality(void)	
{
	LOG("-.-.-.-.-.-Mutant Stack-.-.-.-.-.-.-.-");
	MutantStack<int> mstack;

	std::cout << BLUE << "Pushing 10 and 20 to the container...\n" << RESET;
	mstack.push(10);
	mstack.push(20);
	std::cout << CYAN << "Stack top: " << RESET << mstack.top() << std::endl;

	std::cout << BLUE << "Removing 10 and 20 from the container\n" RESET;
	mstack.pop();
	mstack.pop();
	std::cout << CYAN << "Stack size: " << RESET << mstack.size() << std::endl;

	std::cout << BLUE << "Pushing 4 values into the container\n" << RESET;
	mstack.push(-10);
	mstack.push(42);
	mstack.push(35);
	mstack.push(2);

	MutantStack<int>::iterator begin = mstack.begin();
	MutantStack<int>::iterator end = mstack.end();

	++begin;
	--begin;

	std::cout << GREEN << "\n Stack contents:" << std::endl << RESET;
	while (begin != end)
	{
		std::cout << *begin << std::endl;
		++begin;
	}

	std::stack<int> s(mstack);
}

void	testListContainerFunctionality(void)
{
	LOG("Lists");
	std::list<int> list;

	std::cout << BLUE << "Pushing 2 and 35 to the container...\n" << RESET;
	list.push_back(2);
	list.push_back(35);
	std::cout << CYAN << "Stack top: " << list.back() << std::endl << RESET;

	std::cout << BLUE << "Removing 2 and 35 from the container\n" << RESET;
	list.pop_back();
	list.pop_back();
	std::cout << CYAN << "Stack size: " << list.size() << std::endl << RESET;

	std::cout << GREEN << "Pushing 4 values into the container\n" << RESET;
	list.push_back(-13);
	list.push_back(42);
	list.push_back(36);
	list.push_back(4);

	std::list<int>::iterator begin = list.begin();
	std::list<int>::iterator end = list.end();

	++begin;
	--begin;

	std::cout << GREEN << "Stack contents:" << std::endl << RESET;
	while (begin != end)
	{
		std::cout << *begin << std::endl;
		++begin;
	}

	std::list<int> s(list);
}

int main()
{
	testListContainerFunctionality();
	testMutantStackFunctionality();
	return 0;
}