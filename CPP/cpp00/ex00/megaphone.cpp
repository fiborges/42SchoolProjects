/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <firibeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:48:36 by firibeir          #+#    #+#             */
/*   Updated: 2023/10/02 14:48:37 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	std::string result;
	for (int i = 1; i < argc; i++)
	{
		std::string currentArgument(argv[i]);
		for(int len = 0; currentArgument[len]; len++)
			currentArgument[len] = toupper(currentArgument[len]);
		result += currentArgument;
	}
	if(result.empty())
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		std::cout << result << std::endl;
	return(0);
}
