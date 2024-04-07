/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <firibeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:09:55 by firibeir          #+#    #+#             */
/*   Updated: 2024/04/06 14:14:06 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
int easyfind(T collection, int tofind)
{
	typename T::iterator matchIter;

	matchIter = std::find(collection.begin(), collection.end(), tofind);
	if (matchIter == collection.end())
		throw std::exception();
	return (std::distance(collection.begin(), matchIter));
}