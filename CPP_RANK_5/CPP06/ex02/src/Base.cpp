# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base::~Base()
{
	
}

Base * generate(void)
{
	switch (std::rand() % 3)
	{
		case 0:
			std::cout << "Generated instance of A*\n";
			return (new A());
		case 1:
			std::cout << "Generated instance of B*\n";
			return (new B());
		case 2:
			std::cout << "Generated instance of C*\n";
			return (new C());
		default:
			return (NULL);
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Identified A *: This is an instance of class A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "Identified B *: This is an instance of class B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "Identified C *: This is an instance of class C\n";
	else
		std::cout << "Unknown pointer: This is not an instance of any known class\n";
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Identified A &: This is an instance of class A\n";
		return ;
	}
	catch(const std::exception& e)
	{
		
	}
	
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Identified B &: This is an instance of class B\n";
		return ;
	}
	catch(const std::exception& e)
	{
		
	}
	
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Identified C &: This is an instance of class C\n";
		return ;
	}
	catch(const std::exception& e)
	{
		std::cout << "Unknown type casting: This is not an instance of any known class\n";
	}
}
