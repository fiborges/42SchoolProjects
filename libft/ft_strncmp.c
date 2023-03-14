/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:15:34 by firibeir          #+#    #+#             */
/*   Updated: 2022/11/02 18:34:16 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		if (i < (n - 1))
			i++;
		else
			return (0);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*int main(void)
{
    char *maria;
    char *joao;
    int m;
    int j;

    maria = "amote";
    joao = "amotetb";

    m = strncmp(maria, joao, 5);
    printf("se o numero for = 0 são iguais \n se o numero 
    for < 0 s1 é menor que s2 \n se o numero for > 0 s1 é 
    maior que s2 \n %d \n", m);
    
    j = ft_strncmp(maria, joao, 5);
    printf("se o numero for = 0 são iguais \n se o numero 
    for < 0 s1 é menor que s2 \n se o numero for > 0 s1 é 
    maior que s2 \n %d \n", j);
    return (0);
}*/
