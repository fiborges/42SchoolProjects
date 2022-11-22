/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:09:27 by firibeir          #+#    #+#             */
/*   Updated: 2022/11/05 19:21:53 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
	i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
		{
			sign = -1;
		}
	i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) +(nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

/*int main(void)
{
    char *str;
    str = " -21324323255730as2875";
    int love;
    int maria;

    love = atoi(str);
    printf ("original: %d\n", love);

    maria = ft_atoi(str);
    printf( "meu: %d\n", maria);
    return (0);
}*/
