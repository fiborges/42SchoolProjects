#include "minishell.h"

t_history_node	*ft_lstnew_2(void *content)
{
	struct s_history_node	*new;

	new = (struct s_history_node *)malloc(sizeof(struct s_history_node));
	ft_memset(new, 0, sizeof(t_history_node));
	if (new)
		new->content = content;
	new->previous = NULL;
	return (new);
}

int	putchar_2(int c)
{
	return (write(2, &c, 1));
}

int	is_printable_character(char c)
{
	if ((c >= 32 && c <= 126) || c == 9)
		return (1);
	return (0);
}

