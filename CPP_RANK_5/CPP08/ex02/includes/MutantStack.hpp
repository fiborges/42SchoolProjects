#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <iostream>
# include <iomanip>
# include <stack>
# include <vector>
# include <list>
# include <deque>
# include <algorithm>

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define BLUE	"\033[1;34m"
# define CYAN	"\033[1;36m"
# define RESET	"\033[0m"

template <typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C>
{
	public:
		MutantStack() {}
		MutantStack(const MutantStack& copy) { *this = copy; }
		~MutantStack() {}

		MutantStack& operator=(const MutantStack& right) 
		{
			if (*this == right)
				return (*this);
			std::stack<T, C>::operator=(this, right);
			return (*this);
		}

		typedef typename C::iterator iterator;

		iterator begin(void) { return (this->c.begin()); }
		iterator end(void) { return (this->c.end()); }
};

#endif