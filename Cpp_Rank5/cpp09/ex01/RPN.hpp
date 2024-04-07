/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <firibeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 12:51:04 by firibeir          #+#    #+#             */
/*   Updated: 2024/04/07 12:51:04 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>

class RPN
{
	private:
		std::stack<int> _stack;

	public:
		RPN( void );
		RPN( RPN const & src);
		~RPN( void );

		RPN & operator=(RPN const & src);

		bool	calculation(const char operador);
		
		void 	pushNumber(const int number);
		int		topStack(void) const;
		
};



#endif

