/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:39:35 by firibeir          #+#    #+#             */
/*   Updated: 2022/11/03 19:22:44 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
	lst = NULL;
}
/*#include <stdio.h>
void del(void *a)
{
	printf("remove: %s\n",(char *)a);
}

int main ()
{
	t_list *lst;
	t_list *lst1;

	lst = ft_lstnew("word 1");
	lst->next = ft_lstnew("word 2");
	lst->next->next = ft_lstnew("word 3");
	lst->next->next->next = ft_lstnew("word 4");
		
	lst1 = lst;
	while (lst)
	{
		printf("%s\n",((char *)lst->content));
		lst = lst -> next;
	}
	ft_lstdelone(lst1, del);
}*/
