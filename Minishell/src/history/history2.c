#include "minishell.h"

void	initialize_terminal_capabilities(t_minishell_state *shell_status)
{
	shell_status->termc->start_key = tgetstr("ks", 0);
	shell_status->termc->key_clear_line = tgetstr("dl", 0);
	shell_status->termc->up_key = tgetstr("ku", 0);
	shell_status->termc->down_key = tgetstr("kd", 0);
	shell_status->termc->key_cariage_return = tgetstr("cr", 0);
	shell_status->termc->end_key = tgetstr("ke", 0);
	if (!shell_status->termc->start_key
		|| !shell_status->termc->key_clear_line
		|| !shell_status->termc->up_key
		|| !shell_status->termc->down_key
		|| !shell_status->termc->key_cariage_return
		|| !shell_status->termc->end_key)
		free_data(shell_status, EXIT_FAILURE);
}

int	initialize_history_mode(t_minishell_state *shell_state)
{
	char	*terminal_type;
	int		i;

	if (isatty(STDIN_FILENO))
	{
		terminal_type = getenv("TERM");
		if (!terminal_type)
		{
			write(STDOUT_FILENO, "TERM config not set, exiting...\n", 34);
			free_data(shell_state, EXIT_FAILURE);
		}
		i = tgetent(0, terminal_type);
		shell_state->termc = ft_calloc(1, sizeof(t_terminal_control));
		if (i != 1 || !shell_state->termc)
			free_data(shell_state, EXIT_FAILURE);
		bzero(&shell_state->modified, sizeof(struct termios));
		tcgetattr(0, &shell_state->origin);
		tcgetattr(0, &shell_state->modified);
		shell_state->modified.c_iflag &= ~(IGNBRK | BRKINT | ICRNL
				| INLCR | PARMRK | INPCK | ISTRIP | IXON);
		shell_state->modified.c_lflag &= ~(ICANON | ECHO);
		initialize_terminal_capabilities(shell_state);
	}
	return (1);
}

