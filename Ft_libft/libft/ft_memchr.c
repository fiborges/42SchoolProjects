/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:51:16 by firibeir          #+#    #+#             */
/*   Updated: 2022/11/05 19:07:23 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

/*int main (void) 
{
   const char str[] = "maria.vieira.borges";
   const char ch = '.';
   char *new;
   char *new2;

   new = memchr(str, ch, strlen(str));
   new2 = ft_memchr(str,  ch, strlen(str));

   printf("String after |%c| is - |%s|\n", ch, new);
   printf("String after |%c| is - |%s|\n", ch, new2);

   return(0);
}*/
