/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:31:11 by firibeir          #+#    #+#             */
/*   Updated: 2022/11/05 19:24:29 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if ((c >= 0 && c <= 127))
		return (1);
	return (0);
}

/*int main(void)
{
    int maria;
    int joao;
    
    maria = '\n';
    
    joao = ft_isascii(maria);
    if(joao > 0)
    {
       printf("Ésta na tabela ascii!!");
    }
    else
        printf("não esta na tabela ascii!!");
    return(0);
}*/
