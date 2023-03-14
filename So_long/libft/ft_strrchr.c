/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:38:55 by firibeir          #+#    #+#             */
/*   Updated: 2022/11/10 11:13:14 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (c == 0)
		return ((char *)s + i);
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *)s + i);
	i--;
	}
	return (NULL);
}
/*int main () 
{
   const char filipa[] = "Filipa.Borges.maria";
   const char c = '.';
   char *maria;
   char *joao;

   maria = strrchr(filipa, c);
    printf("String after |%c| is - |%s|\n", c, maria);
    joao = ft_strrchr(filipa, c);
    printf("String after |%c| is - |%s|\n", c, maria);
    
   return(0);
}*/
