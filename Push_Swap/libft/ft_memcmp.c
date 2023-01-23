/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:55:00 by firibeir          #+#    #+#             */
/*   Updated: 2022/11/02 15:59:22 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*str1;
	char	*str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}

/*int main(void)
{
    char *maria;
    char *joao;
    int m;
    int j;

    maria = "amote\0\0";
    joao = "amotetb\0";

    m = ft_memcmp(maria, joao, 7);
    printf("se o numero for = 0 são iguais \n 
    se o numero for < 0 s1 é menor que s2 \n se o numero 
    for > 0 s1 é maior que s2 \n %d \n", m);
    j = memcmp(maria, joao, 7);
    printf("se o numero for = 0 são iguais \n se o numero 
    for < 0 s1 é menor que s2 \n 
    se o numero for > 0 s1 é maior que s2 \n %d \n", m);
    return (0);
}*/
