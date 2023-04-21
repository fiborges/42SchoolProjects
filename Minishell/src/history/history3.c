#include "minishell.h"

int	check_special_status(t_minishell_state *shell_status)
{
	int	should_exit_loop;

	should_exit_loop = 0;
	if (shell_status->status == -2)
		shell_status->status = 0;
	if (shell_status->status == -1)
	{
		shell_status->status = 0;
		free(shell_status->input);
		shell_status->input = ft_strdup("");
		should_exit_loop = 1;
	}
	return (should_exit_loop);
}

void	add_to_input_buffer(char *buffer, t_minishell_state *shell_state)
{
	char	*tmp;

	tmp = shell_state->input;
	shell_state->input = ft_strjoin(shell_state->input, buffer);
	free(tmp);
	ft_putchar_fd(shell_state->input[ft_strlen(shell_state->input) - 1], STDOUT_FILENO);
}

void	submit_input(t_minishell_state *shell_state)
{
	write(2, "\n", 1);
	add_history(&(shell_state->history_head), shell_state->input);
	shell_state->history_index = NULL;
}

void	handle_history_input(t_minishell_state *shell_status)
{
	char	buffer[4];

	while (1)
	{
		tputs(shell_status->termc->start_key, 1, putchar_2);
		ft_memset(buffer, 0, 4);
		read(0, buffer, 3);
		if (check_special_status(shell_status))
			return ;
		if (!ft_strcmp(buffer, shell_status->termc->up_key))
			browse_history_previous(shell_status);
		else if (!ft_strcmp(shell_status->termc->down_key, buffer))
			browse_history_next(shell_status);
		else if (buffer[0] == '\x04')
			end_of_file(shell_status);
		else if (buffer[0] == 127)
			delete_last_character(shell_status);
		else if (is_printable_character(buffer[0]) && buffer[1] == '\0')
			add_to_input_buffer(buffer, shell_status);
		else if (buffer[0] == '\n' || buffer[0] == '\r')
		{
			submit_input(shell_status);
			return ;
		}
	}
}

void	end_of_file(t_minishell_state *data)
{
	if (data->input[0] == '\0')
	{
		ft_putstr_fd("exit\n", STDOUT_FILENO);
		tcsetattr(0, TCSAFLUSH, &data->origin);
		save_command_history(data);
		exit(0);
	}
}


