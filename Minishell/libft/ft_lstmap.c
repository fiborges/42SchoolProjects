/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:45:24 by firibeir          #+#    #+#             */
/*   Updated: 2022/11/03 13:13:20 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*beg;
	t_list	*newlist;

	if (lst == NULL)
		return (NULL);
	beg = NULL;
	while (lst != NULL)
	{
		newlist = ft_lstnew(f(lst->content));
		if (newlist == NULL)
		{
			ft_lstclear(&beg, del);
			return (NULL);
		}
		ft_lstadd_back(&beg, newlist);
		lst = lst->next;
	}
	return (beg);
}
/*#include <stdio.h>

void	*f(void *first_char)
{
	int len;
	char *a;

	len = ft_strlen((char *)first_char);
	a = malloc(sizeof(char) * len + 1);
	ft_strlcpy(a, (char * )first_char, len +1);
	a[0] = 'W';
	return (a);
}

void	del(void *cont)
{
	free(cont);
}

int main()
{
	t_list	*lst;
	t_list	*lst0;
	char	*a1;
	int	size_list;

	size_list = 2;
	a1 = malloc(sizeof(char) * 6);
	ft_strlcpy(a1, "word1", 6);
	lst = ft_lstnew(a1);

	lst0 = lst;

	while (size_list <= 4)
	{
		a1 = malloc(sizeof(char) * 6);
        	ft_strlcpy(a1, "word1", 6);
		a1[4] = (size_list % 10) + '0';
		lst->next = ft_lstnew(a1);
		lst = lst->next;
		size_list++;
	}

	lst0 = ft_lstmap(lst0, f, del);
	while (lst0)
	{
		printf("%s\n",((char *)lst0->content));
		lst0 = lst0->next;
	}
}*/
