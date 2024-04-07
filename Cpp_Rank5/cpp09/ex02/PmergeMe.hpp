/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <firibeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 12:55:58 by firibeir          #+#    #+#             */
/*   Updated: 2024/04/07 12:55:58 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <deque>
# include <vector>
# include <string>
# include <climits>
# include <ctime>

class PmergeMe
{
	private:
		std::deque<int>		deqconteiner;
		std::vector<int>	vectconteiner;

		PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &src);

	public:
		PmergeMe(char **argv);
		~PmergeMe();
		const std::deque<int> &getDeq() const;
		const std::vector<int> &getVec() const;
		void	printVec() const;
		void	printDeq() const;
		void	throwException(void);
		void	algorithm(void);
		void	insertVec(std::vector<int> &vectconteiner);
		void	insertDeq(std::deque<int> &deqconteiner);
		void	mergeVec(std::vector<int> &vectconteiner);
		void	mergeDeq(std::deque<int> &deqconteiner);
};

#endif
