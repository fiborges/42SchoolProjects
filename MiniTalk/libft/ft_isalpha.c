/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:29:49 by firibeir          #+#    #+#             */
/*   Updated: 2022/11/05 19:22:46 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

/*int main(void)
{
    int maria;
    int joao;
    
    maria = '4';
    
    joao = ft_isalpha(maria);
    if(joao > 0)
    {
       printf("É alfabetico!!");
    }
    else
        printf("não é alfabetico");
    return(0);
}*/
