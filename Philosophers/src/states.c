#include "../include/philo.h"

u_int64_t	get_current_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (error("gettimeofday() FAILURE\n", NULL));
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}

void	print_message(char *str, t_philo *philo)
{
	u_int64_t	time;

	pthread_mutex_lock(&philo->data->write_mutex);
	time = get_current_time() - philo->data->start_time;
	if (ft_strcmp(DIED, str) == 0 && philo->data->is_dead == 0)
	{
		printf("%llu %d %s\n", time, philo->id, str);
		philo->data->is_dead = 1;
	}
	if (!philo->data->is_dead)
		printf("%llu %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->data->write_mutex);
}

void	grab_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_message(TAKE_FORKS, philo);
	pthread_mutex_lock(philo->left_fork);
	print_message(TAKE_FORKS, philo);
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	print_message(SLEEPING, philo);
	controlled_sleep(philo->data->time_to_sleep);
}

void	eating(t_philo *philo)
{
	grab_forks(philo);
	pthread_mutex_lock(&philo->lock);
	philo->is_eating = 1;
	philo->time_to_die = get_current_time() + philo->data->death_time;
	print_message(EATING, philo);
	philo->meals_eaten++;
	controlled_sleep(philo->data->time_to_eat);
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->lock);
	release_forks(philo);
}
