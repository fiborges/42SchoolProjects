/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:04:54 by firibeir          #+#    #+#             */
/*   Updated: 2022/11/05 18:55:10 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*memory_d;
	char	*memory_s;

	i = 0;
	memory_d = (char *)dest;
	memory_s = (char *)src;
	if (src == NULL && dest == NULL)
		return (0);
	while (i < n)
	{
		memory_d[i] = memory_s[i];
		i++;
	}
	return (dest);
}
/*int main (void) 
{
   const char src[31] = "maria vieira borges de almeida";
   char dest[31];
   
   strcpy(dest,"Heloooo!!");
   printf("Before memcpy dest = %s\n", dest);
   memcpy(dest, src, strlen(src)+1);
   printf("After memcpy dest = %s\n", dest);

   strcpy(dest,"Heloooo!!");
   printf("Before memcpy dest = %s\n", dest);
   ft_memcpy(dest, src, strlen(src)+1);
   printf("After memcpy dest = %s\n", dest);
   
   return(0);
}*/
