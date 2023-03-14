/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:04:07 by firibeir          #+#    #+#             */
/*   Updated: 2022/11/06 20:21:12 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		str[1] = '\0';
		str = ft_strjoin(str, ft_itoa(-n));
	}
	else if (n >= 10)
		str = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
	else if (n < 10 && n >= 0)
	{
		str[0] = n + '0';
		str[1] = '\0';
	}
	return (str);
}

/*int      main(void)
{
	int d = INT_MIN;
    printf("%d = %s\n", d, ft_itoa(d));
 
    d = -13;
    printf("%d = %s\n", d, ft_itoa(d));
 
    d = 0;
    printf("%d = %s\n", d, ft_itoa(d));
 
    d = 5;
    printf("%d = %s\n", d, ft_itoa(d));
 
    d = INT_MAX;
    printf("%d = %s\n", d, ft_itoa(d));
}*/
