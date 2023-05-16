/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_condition.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <firibeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:28:32 by firibeir          #+#    #+#             */
/*   Updated: 2023/05/08 14:28:37 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	end_simulation(t_data *data)
{
	int	flag;

	flag = 0;
	pthread_mutex_lock(&data->end_mutex);
	flag = data->is_over;
	pthread_mutex_unlock(&data->end_mutex);
	return (flag);
}

void	change_flag_end(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->end_mutex);
	philo->data->is_over = 1;
	pthread_mutex_unlock(&philo->data->end_mutex);
}

int	has_philosopher_finished(t_philo *philo)
{
	int	flag;

	flag = 0;
	pthread_mutex_lock(&philo->data->end_mutex);
	flag = philo->data->is_over;
	pthread_mutex_unlock(&philo->data->end_mutex);
	if (flag)
		return (flag);
	return (0);
}

int	check_meals(t_philo *philo, int i)
{
	pthread_mutex_lock(&philo->data->end_mutex);
	if (i != philo->to_take)
	{
		philo->taken++;
		pthread_mutex_unlock(&philo->data->end_mutex);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->end_mutex);
	return (1);
}

int	meals_done(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->end_mutex);
	if (philo->taken == philo->to_take)
	{
		pthread_mutex_unlock(&philo->data->end_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->end_mutex);
	return (0);
}
