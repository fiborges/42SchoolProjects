/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:03:45 by firibeir          #+#    #+#             */
/*   Updated: 2022/11/06 17:04:13 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_size;
	size_t	i;

	src_size = ft_strlen(src);
	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_size);
}
/*#include <bsd/string.h>
int main() 
{
  char str1[20] = "C programming";
  char str2[20];
  char str3[20] = "C programming";
  char str4[20];

  // copying str1 to str2
  strlcpy(str2, str1, 8);
  puts(str2); // C programming

  ft_strlcpy(str4, str3, 8);
  puts(str4);

  return 0;
}*/
