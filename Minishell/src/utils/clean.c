#include "minishell.h"

void	free_data(t_minishell_state *state, int exit_code)
{
	free_env(state->environment_variables);
	free(state->pwd);
	ft_putstr_fd("EXIT\n", 2);
	exit(exit_code);
}

int	clear_input_line(t_minishell_state *shell_state)
{
	tputs(shell_state->termc->key_clear_line, 1, putchar_2);
	tputs(shell_state->termc->key_cariage_return, 1, putchar_2);
	ft_putstr_fd(shell_state->prompt, STDOUT_FILENO);
	return (1);
}

void	delete_last_character(t_minishell_state *shell_state)
{
	if (shell_state->input[0] != '\0')
		shell_state->input[ft_strlen(shell_state->input) - 1] = '\0';
	clear_input_line(shell_state);
	ft_putstr_fd(shell_state->input, STDOUT_FILENO);
}


