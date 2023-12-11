#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <sstream>
# include <cstdlib>

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define RESET	"\033[0m"

# define ERROR(x) 		std::cout << x << std::endl
# define ERROR_USAGE(e)	ERROR("Usage: " << e << " test_number")
# define ERROR_NOT_INT	ERROR("Error: test number must be a number")
# define ERROR_TESTNO	ERROR("Error: test number must be bounded between 0 and 1")

class Base
{
	public:
		virtual ~Base();
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif