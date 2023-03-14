/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:32:14 by firibeir          #+#    #+#             */
/*   Updated: 2022/11/05 19:23:32 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

/*int main(void)
{
    int maria;
    int joao;
    
    maria = '\n';
    
    joao = ft_isdigit(maria);
    if(joao > 0)
    {
       printf("É um numero!!");
    }
    else
        printf("não é um numero!!");
    return(0);
}*/
