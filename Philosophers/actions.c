/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <firibeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:28:19 by firibeir          #+#    #+#             */
/*   Updated: 2023/05/08 14:57:06 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->meal_mutex);
	philo->last_meal = get_time_in_ms() - philo->data->start_time;
	pthread_mutex_unlock(&philo->data->meal_mutex);
}

void	new_sleep(t_philo *philo, time_t amount)
{
	time_t	time;
	time_t	total;

	time = get_time_in_ms();
	total = time + amount;
	while (time < total)
	{
		usleep(100);
		time = get_time_in_ms();
		pthread_mutex_lock(&philo->data->end_mutex);
		if (philo->data->is_over)
		{
			pthread_mutex_unlock(&philo->data->end_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->data->end_mutex);
	}
}

void	philo_eat(t_philo *philo, time_t time)
{
	if (has_philosopher_finished(philo))
		return ;
	time = (get_time_in_ms()) - philo->data->start_time;
	get_right_fork(philo, time);
	get_left_fork(philo, time);
	set_last_meal(philo);
	pthread_mutex_lock(&philo->data->printf_mutex);
	if (has_philosopher_finished(philo))
	{
		pthread_mutex_unlock(&philo->data->printf_mutex);
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	time = (get_time_in_ms()) - philo->data->start_time;
	printf("\033[1;34m%ld Philosopher %u is eating\033[0m\n", time, philo->id);
	pthread_mutex_unlock(&philo->data->printf_mutex);
	new_sleep(philo, philo->time_eat);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	philo_sleep(t_philo *philo)
{
	time_t	time;

	if (has_philosopher_finished(philo))
		return ;
	time = (get_time_in_ms()) - philo->data->start_time;
	pthread_mutex_lock(&philo->data->printf_mutex);
	if (has_philosopher_finished(philo))
	{
		pthread_mutex_unlock(&philo->data->printf_mutex);
		return ;
	}
	printf("\033[1;32m%ld Philosopher %u is sleeping\033[0m\n", time, philo->id);
	pthread_mutex_unlock(&philo->data->printf_mutex);
	if (has_philosopher_finished(philo))
		return ;
	new_sleep(philo, philo->time_sleep);
}

void	philo_think(t_philo *philo)
{
	time_t	time;

	if (has_philosopher_finished(philo))
		return ;
	pthread_mutex_lock(&philo->data->printf_mutex);
	if (has_philosopher_finished(philo))
	{
		pthread_mutex_unlock(&philo->data->printf_mutex);
		return ;
	}
	time = (get_time_in_ms()) - philo->data->start_time;
	printf("\033[38;5;208m%ld Philosopher %u is thinking\033[0m\n", \
			time, philo->id);
	pthread_mutex_unlock(&philo->data->printf_mutex);
	new_sleep(philo, 1);
	time = (get_time_in_ms()) - philo->data->start_time;
}
