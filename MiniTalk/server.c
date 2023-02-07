/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:28:10 by firibeir          #+#    #+#             */
/*   Updated: 2022/12/06 11:28:12 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	decode_binary(int signal, pid_t client_pid)
{
	static unsigned char	c = 0;
	static int				bit = 0;

	if (bit < 8 && signal == SIGUSR1)
		c += 128 >> bit;
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(c, 1);
		if (c == 0)
		{
			kill(client_pid, SIGUSR1);
			usleep(200);
		}
		bit = 0;
		c = 0;
	}
}

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static pid_t	client_pid;

	(void)context;
	client_pid = -1;
	if (signal == SIGUSR1 || signal == SIGUSR2)
	{
		client_pid = info->si_pid;
		decode_binary(signal, client_pid);
	}
}

int	main(void)
{
	struct sigaction	server;

	server.sa_sigaction = &signal_handler;
	server.sa_flags = SA_SIGINFO;
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sigaction(SIGUSR1, &server, NULL);
	sigaction(SIGUSR2, &server, NULL);
	while (1)
		pause();
	return (0);
}
