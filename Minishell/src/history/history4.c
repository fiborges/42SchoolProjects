#include "minishell.h"

char	*get_previous_history_entry(t_history_node **current_history_node, t_history_node **history_head)
{
	char	*tmp;

	tmp = NULL;
	if (*current_history_node)
	{
		if ((*current_history_node)->next != NULL)
			(*current_history_node) = (*current_history_node)->next;
		tmp = (*current_history_node)->content;
		return (tmp);
	}
	if (*history_head)
	{
		*current_history_node = *history_head;
		tmp = (*current_history_node)->content;
	}
	return (tmp);
}

char	*get_next_history_entry(t_history_node **current_history_node)
{
	char	*tmp;

	tmp = NULL;
	if (*current_history_node)
	{
		(*current_history_node) = (*current_history_node)->previous;
		if (*current_history_node)
			tmp = (*current_history_node)->content;
	}
	return (tmp);
}

void	browse_history_previous(t_minishell_state *shell_state)
{
	char	*tmp;

	if (shell_state->history_head && shell_state->history_head->next == NULL)
	{
		free(shell_state->input);
		shell_state->input = ft_strdup(shell_state->history_head->content);
		clear_input_line(shell_state);
		ft_putstr_fd(shell_state->input, 2);
	}
	else
	{
		tmp = get_previous_history_entry(&(shell_state->history_index), &(shell_state->history_head));
		if (tmp)
		{
			free(shell_state->input);
			shell_state->input = ft_strdup(tmp);
			clear_input_line(shell_state);
			ft_putstr_fd(shell_state->input, 2);
		}
	}
}

void	browse_history_next(t_minishell_state *shell_state)
{
	char	*tmp;

	tmp = get_next_history_entry(&(shell_state->history_index));
	free(shell_state->input);
	if (tmp)
		shell_state->input = ft_strdup(tmp);
	else
		shell_state->input = ft_strdup("");
	clear_input_line(shell_state);
	if (tmp)
		ft_putstr_fd(shell_state->input, 2);
}

void	save_command_history(t_minishell_state *shell_state)
{
	int		fd;
	char	*tmp;

	fd = open(HIST_FILE, O_APPEND | O_CREAT | O_RDWR, 0666);
	if (fd >= 0)
	{
		set_history_tail(shell_state);
		while (shell_state->history_index)
		{
			tmp = ft_strjoin(shell_state->history_index->content, "\n");
			ft_putstr_fd(tmp, fd);
			free(tmp);
			shell_state->history_index = shell_state->history_index->previous;
		}
		close(fd);
	}
}

