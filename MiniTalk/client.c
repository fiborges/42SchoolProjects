/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <firibeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:28:00 by firibeir          #+#    #+#             */
/*   Updated: 2022/12/21 17:39:23 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

pid_t				g_server_pid;

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
	i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
		{
			sign = -1;
		}
	i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) +(nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

void	client_handler(int signal, siginfo_t *info, void *context)
{
	(void)context;
	if (g_server_pid == info->si_pid && signal == SIGUSR1)
		ft_putstr_color_fd(ANSI_COLOR_GREEN, "msg received\n", 1);
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
				kill(g_server_pid, SIGUSR1);
			else
				kill(g_server_pid, SIGUSR2);
			usleep(200);
			bit++;
		}
	str++;
	}
	while (bit--)
	{
		kill(g_server_pid, SIGUSR2);
		usleep(200);
	}
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = (unsigned char )c;
	return (s);
}

int	main(int argc, char *argv[])
{
	struct sigaction			client;

	ft_memset(&client, 0, sizeof(struct sigaction));
	client.sa_sigaction = &client_handler;
	client.sa_flags |= SA_SIGINFO;
	g_server_pid = ft_atoi(argv[1]);
	if (argc != 3 || argv[2][0] == '\0' || g_server_pid < 1)
	{
		ft_putstr_color_fd(ANSI_COLOR_RED,
			"client: invalid arguments.\n", 2);
		ft_putstr_color_fd(ANSI_COLOR_YELLOW,
			"correct format: [./client <PID> <Msg>].\n", 2);
		exit(EXIT_FAILURE);
	}
	sigaction(SIGUSR1, &client, NULL);
	transfer_signal(argv[2]);
}
