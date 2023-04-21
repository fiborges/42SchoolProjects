#include "minishell.h"

extern t_minishell_state g_shell_state;

void	handle_sig(int sig)
{
	if (sig == SIGINT)
	{
		g_shell_state.status = 130;
		if (g_shell_state.input)
		{
			ft_putchar_fd('\n', 2);
			ft_putstr_fd(g_shell_state.prompt, 2);
		}
		if (g_shell_state.input)
			free(g_shell_state.input);
		g_shell_state.input = ft_strdup("\0");
		g_shell_state.history_index = NULL;
	}
}

void	init_signal_handling(void)
{
	if (signal(SIGINT, handle_sig) == SIG_ERR)
		exit(EXIT_FAILURE);
	else if (signal(SIGQUIT, handle_sig) == SIG_ERR)
		exit(EXIT_FAILURE);
}