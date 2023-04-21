#include "minishell.h"

t_minishell_state g_shell_state;

void	initialize_minishell_state(t_minishell_state *shell_state, char **env)
{
	shell_state->prompt = "\x1b[32m[\x1b[33mFI&MA_Minishell\x1b[32m]~>\x1b[0m ";
	shell_state->status = 0;
	shell_state->status_signal = 0;
	shell_state->input = NULL;
	shell_state->environment_variables = copy_envr_var(env);
	if (!shell_state->environment_variables)
		exit(EXIT_FAILURE);
	shell_state->pwd = getcwd(NULL, 0);
	shell_state->fd_in = 0;
	shell_state->fd_out = 1;
	shell_state->any_redirection = 1;
	shell_state->history_head = NULL;
	shell_state->history_index = NULL;
}

int	main(int argc, char **argv, char **environment_vars)
{
	shell_image();
	(void)argc;
	(void)argv;
	initialize_minishell_state(&g_shell_state, environment_vars);
	load_history_from_file(&g_shell_state);
	initialize_history_mode(&g_shell_state);
	init_signal_handling();
	while (1)
	{
		tcsetattr(STDIN_FILENO, TCSAFLUSH, &g_shell_state.modified);
		ft_putstr_fd(g_shell_state.prompt, 2);
		g_shell_state.input = ft_strdup("");
		handle_history_input(&g_shell_state);
		tcsetattr(STDIN_FILENO, TCSAFLUSH, &g_shell_state.origin);
		execute_commands_from_input(g_shell_state.input, &g_shell_state);
	}
	return (0);
}/*
Imagine that your computer is a big toy box, and each toy is a program. The toys need some 
information to work properly, like instructions on how to play with them or some special settings. 
These pieces of information are called environment variables.

When you start a program (take a toy out of the box), it gets a list of these environment variables 
so it knows how to work correctly. This list of variables is called envp. It's like a small note that 
comes with the toy, telling you how to play with it or set it up.

In your minishell program, envp is a list of these notes that you can use to make your program work 
correctly and do things like remember where other programs are or how to set up special features.
*/