/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <firibeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:08:14 by firibeir          #+#    #+#             */
/*   Updated: 2024/04/06 16:08:15 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <sstream>
# include <limits>
# include <ctime>
# include <algorithm>
# include <vector>

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define RESET	"\033[0m"

class Span
{
	private:
		unsigned int N;
		std::vector<int> storage;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span& copy);
		~Span();

		Span& operator=(const Span& newcopy);

		void addNumber(int number);
		int shortestSpan(void);
		int longestSpan(void);
		void fillWithRandomNumbers(void);

		unsigned int size(void) const;
		std::vector<int> retrieveStorage(void) const;

		class FullExeption : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class EmptyExeption : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator <<(std::ostream& out, const Span& span);

#endif