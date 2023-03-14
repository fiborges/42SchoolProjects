/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:34:42 by firibeir          #+#    #+#             */
/*   Updated: 2022/11/06 20:22:51 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_size;

	if ((!big || !little) && len == 0)
		return (NULL);
	little_size = ft_strlen(little);
	if (!little_size)
		return ((char *)big);
	while (*big && little_size <= len--)
	{
		if (!ft_memcmp(big, little, little_size))
			return ((char *)big);
		big++;
	}
	return (0);
}

/*int main () 
{
   const char s1[8] = "Bazinga";
   const char s2[3] = "zi";
   char *maria;
   char *joao;

   maria = strnstr(s1, s2, 3);
   printf("original - The substring is: %s\n", maria);

   joao = ft_strnstr(s1, s2, 3);
   printf("meu - The substring is: %s\n", joao);
   
   return(0);
}*/
