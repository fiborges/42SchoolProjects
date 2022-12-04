#include "minitalk.h"

pid_t				get_server_pid;

void	client_handler(int signal, siginfo_t *info, void *context)
{
	(void)context;
	if (get_server_pid == info->si_pid && signal == SIGUSR1)
		ft_putstr_color_fd(ANSI_COLOR_GREEN, "server to client: message received\n", 1);
}

void	transfer_signal(char *str)
{
	int				bit;
	unsigned char	c;

	while (*str)
	{
		c = *str;
		bit = 0;
		while (bit < 8)
		{
			if (c << bit & 128)
				kill(get_server_pid, SIGUSR1);
			else
				kill(get_server_pid, SIGUSR2);
			usleep(200);
			bit++;
		}
	str++;
	}
	while (bit--)
	{
		kill(get_server_pid, SIGUSR2);
		usleep(200);
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction			client;

	client.sa_sigaction = &client_handler;
	get_server_pid = ft_atoi(argv[1]);
	if (argc != 3 || argv[2][0] == '\0' || get_server_pid < 1)
		{
			ft_putstr_color_fd(ANSI_COLOR_RED,
				"client: invalid arguments.\n", 2);
			ft_putstr_color_fd(ANSI_COLOR_YELLOW,
				"correct format: [./client <PID> <STR>].\n", 2);
			exit(EXIT_FAILURE);
		}
	sigaction(SIGUSR1, &client, NULL);
	transfer_signal(argv[2]);
}
