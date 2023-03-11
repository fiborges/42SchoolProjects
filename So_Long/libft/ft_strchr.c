/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipa <filipa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:44:40 by firibeir          #+#    #+#             */
/*   Updated: 2023/03/10 15:43:30 by filipa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	if (!c && s[i] == '\0')
		return ((char *)s + i);
	return (NULL);
}

/*#include <bsd/string.h>
int main () 
{
   const char filipa[] = "Filipa.Borges.maria";
   const char c = '.';
   char *maria;
   char *joao;

   maria = strchr(filipa, c);
    printf("String after |%c| is - |%s|\n", c, maria);
    joao = ft_strchr(filipa, c);
    printf("String after |%c| is - |%s|\n", c, maria);
    
   return(0);
}*/
