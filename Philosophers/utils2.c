/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <firibeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:29:21 by firibeir          #+#    #+#             */
/*   Updated: 2023/05/08 14:31:11 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	philo_atoi(char *str)
{
	long long int			nb;
	int						i;

	i = 0;
	nb = 0;
	if (ft_strlen(str) > 18)
		return (-1);
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (nb > 2147483647)
		return (-1);
	return ((int)nb);
}

static int	is_only_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_wrong_input(int argc, char **argv)
{
	int	i;
	int	nb;

	i = 1;
	while (i < argc)
	{
		if (!is_only_digit(argv[i]))
			return (error_handler("Wrong!! Only Numbers!!", 1));
		nb = philo_atoi(argv[i]);
		if (i == 1 && (nb <= 0 || nb > 250))
			return (error_handler("Incorrect number of philosphers!!", 1));
		if (i != 1 && nb == -1)
			return (error_handler("Invalid values!!", 1));
		i++;
	}
	return (0);
}
