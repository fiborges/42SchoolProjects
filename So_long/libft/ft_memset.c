/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:18:21 by firibeir          #+#    #+#             */
/*   Updated: 2022/11/05 18:51:58 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	counter;
	unsigned char	*memory;

	counter = 0;
	memory = s;
	while (n > counter)
	{
		memory[counter] = c;
		counter++;
	}
	return (memory);
}

/*int main(void)
{
    char str[50];
    char str1[50];
    strcpy(str, "this is a string");
    puts(str);
    strcpy(str1, "this is a string");
    puts(str1);

    memset(str, '@', 5);
    puts(str);
    ft_memset(str1, '@', 5);
    puts(str1);

    return(0);
}*/
