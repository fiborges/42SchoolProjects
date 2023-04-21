#include "minishell.h"

void	add_command_to_history(t_history_node **head_node, char *input_command)
{
	t_history_node	*new;

	new = NULL;
	if (*input_command)
	{
		if (((*head_node) && ft_strcmp((*head_node)->content, input_command)) \
				|| !(*head_node))
			new = ft_lstnew_2(ft_strdup(input_command));
		if (new)
		{
			if (!(*head_node))
				*head_node = new;
			else
			{
				new->next = *head_node;
				(*head_node)->previous = new;
				*head_node = new;
			}
		}
	}
}

void	read_history_from_file(int fd, t_minishell_state *shell_state)
{
	char	*line;
	int		read_status;

	line = NULL;
	read_status = get_next_line(fd, &line);
	while (read_status >= 0)
	{
		if (*line != '\0')
			add_command_to_history(&shell_state->history_head, line);
		free(line);
		if (read_status == 0)
			break ;
		read_status = get_next_line(fd, &line);
	}
}

void	load_history_from_file(t_minishell_state *shell_state)
{
	int		fd;

	fd = open(HIST_FILE, O_RDONLY);
	if (fd >= 0)
	{
		read_history_from_file(fd, shell_state);
		close(fd);
	}
}

void	set_history_tail(t_minishell_state *shell_state)
{
	int		i;

	i = 0;
	shell_state->history_index = shell_state->history_head;
	while (i < HIST_SIZE && shell_state->history_index)
	{
		if (!shell_state->history_index->next)
			break ;
		shell_state->history_index = shell_state->history_index->next;
		i++;
	}
}

