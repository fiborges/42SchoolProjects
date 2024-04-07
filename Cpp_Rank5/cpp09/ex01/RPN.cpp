/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <firibeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 12:50:59 by firibeir          #+#    #+#             */
/*   Updated: 2024/04/07 12:50:59 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN( void ) {}

RPN::RPN( RPN const & src ) { *this = src; }

RPN::~RPN( void ) {}

RPN & RPN::operator=(RPN const & src)
{
	this->_stack = src._stack;
	return *this;
}

bool	RPN::calculation(const char operador)
{
	int a;
	int b;

	if (this->_stack.size() < 2)
	{
		std::cout << "Error" << std::endl;
		return (false);
	}
	a = this->_stack.top();
	this->_stack.pop();
	b = this->_stack.top();
	this->_stack.pop();
	switch (operador)
	{
		case '+':
			this->_stack.push(b + a);
			break;
		case '-':
			this->_stack.push(b - a);
			break;
		case '*':
			this->_stack.push(b * a);
			break;
		case '/':
			this->_stack.push(b / a);
			break;
	}
	return (true);
}

void RPN::pushNumber(const int number)
{
	this->_stack.push(number);
}

int		RPN::topStack(void) const
{
	return (this->_stack.top());
}
