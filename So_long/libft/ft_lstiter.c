/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:41:26 by firibeir          #+#    #+#             */
/*   Updated: 2022/11/03 12:48:53 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*#include <stdio.h>

void	f(void *first_char)
{
	((char *)first_char)[0] = 'W';
}

int main()
{
	t_list	*lst;
	t_list	*lst1;
	char	*a1;
	int	size_list;

	size_list = 2;
	a1 = malloc(sizeof(char) * 6);
	ft_strlcpy(a1, "word1", 6);
	lst = ft_lstnew(a1);

	lst1 = lst;

	while (size_list <= 13)
	{
		a1 = malloc(sizeof(char) * 6);
        	ft_strlcpy(a1, "word1", 6);
		a1[4] = (size_list % 10) + '0';
		lst->next = ft_lstnew(a1);
		lst = lst->next;
		size_list++;
	}

	ft_lstiter(lst1, &f);
	while (lst1)
	{
		printf("%s\n",((char *)lst1->content));
		lst1 = lst1->next;
	}
}


//Iterates the list ’lst’ and applies the function ’f’ to the content of
//each element.*/
