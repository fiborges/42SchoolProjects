/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:23:28 by firibeir          #+#    #+#             */
/*   Updated: 2022/11/03 11:10:53 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = ft_lstlast(*lst);
	if (!tmp)
		*lst = new;
	else
		tmp->next = new;
}

/*void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;

	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (len > 0)
		{
			((char *)dst)[len - 1] = ((char *)src)[len - 1];
			len--;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
}

t_list			*ft_lstnew(void const *content, size_t content_size)
{
    t_list		*new;
    
    new = (t_list *)malloc(sizeof(t_list) * 1);
    if (new == NULL)
		return (NULL);
    if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
    else
	{
		new->content = malloc(content_size);
		if (new->content == NULL)
			return (NULL);
		ft_memmove(new->content, content, content_size);
		new->content_size = content_size;
	}
    new->next = NULL;
	return (new);
}

int main(void)
{
	char content[20] = "MARIA.";
 	char content2[20] = "ALMEIDA.";
 	t_list *my_tlist;
	t_list *linked_list1;
	t_list *linked_list2;
	
	my_tlist = (t_list *)malloc(sizeof(t_list) * 5);
 	linked_list1 = ft_lstnew((void *)content, 16);
 	linked_list2 = ft_lstnew((void *)content2, 16);
 	ft_lstadd_back(&my_tlist, linked_list1);
 	ft_lstadd_back(&my_tlist, linked_list2);

	
 	printf("The result is %s\n", (char *)my_tlist[0].content);
 	printf("The result is %s\n", (char *)my_tlist[0].next->content);
	return 0;
}*/
