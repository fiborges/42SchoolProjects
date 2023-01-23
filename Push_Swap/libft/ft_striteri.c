/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:44:53 by firibeir          #+#    #+#             */
/*   Updated: 2022/11/11 19:24:50 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*#include <stdio.h>
void	f(unsigned int i, char *s)
{
	 i = 0;
	 while (s[i])
	{
		s[i] = 'w';
		i++;
	}
}

int main()
{
	char str[] = "Maria";
	printf("%s \n", str);
	ft_striteri(str,f);
	 printf("%s \n", str);

	 return(0);
}*/
