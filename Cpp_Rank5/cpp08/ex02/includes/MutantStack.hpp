/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <firibeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:59:08 by firibeir          #+#    #+#             */
/*   Updated: 2024/04/06 16:59:09 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> 
{
	public:
    	typedef typename Container::iterator iterator;
    	typedef typename Container::const_iterator const_iterator;

    	MutantStack() : std::stack<T, Container>() {}
    	MutantStack(const MutantStack& other) : std::stack<T, Container>(other) {}
    	MutantStack& operator=(const MutantStack& other) 
		{
        	std::stack<T, Container>::operator=(other);
        	return *this;
    	}
    	~MutantStack() {}

    	iterator begin() 
		{ 
			return this->c.begin(); 
		}
    	const_iterator begin() const 
		{ 
			return this->c.begin(); 
		}

    	iterator end() 
		{ 
			return this->c.end(); 
		}
    	const_iterator end() const 
		{ 
			return this->c.end(); 
		}
};


#endif