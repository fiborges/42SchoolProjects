#include "../include/philo.h"

void	*check_completion(void *data_pointer)
{
	t_philo	*philo;

	philo = (t_philo *) data_pointer;
	pthread_mutex_lock(&philo->data->write_mutex);
	printf("data val: %d", philo->data->is_dead);
	pthread_mutex_unlock(&philo->data->write_mutex);
	while (philo->data->is_dead == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (philo->data->finished >= philo->data->nb_of_philos)
			philo->data->is_dead = 1;
		pthread_mutex_unlock(&philo->lock);
	}
	return ((void *)0);
}

void	*monitor_philosopher(void *philo_pointer)
{
	t_philo	*philo;

	philo = (t_philo *) philo_pointer;
	while (philo->data->is_dead == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (get_current_time() >= philo->time_to_die && philo->is_eating == 0)
			print_message(DIED, philo);
		if (philo->meals_eaten == philo->data->nb_of_meals)
		{
			pthread_mutex_lock(&philo->data->lock);
			philo->data->finished++;
			philo->meals_eaten++;
			pthread_mutex_unlock(&philo->data->lock);
		}
		pthread_mutex_unlock(&philo->lock);
	}
	return ((void *)0);
}

void	*philosopher_behavior(void *philo_pointer)
{
	t_philo	*philo;

	philo = (t_philo *) philo_pointer;
	philo->time_to_die = philo->data->death_time + get_current_time();
	if (pthread_create(&philo->thread, NULL, &monitor_philosopher, (void *)philo))
		return ((void *)1);
	while (philo->data->is_dead == 0)
	{
		eating(philo);
		print_message(THINKING, philo);
	}
	if (pthread_join(philo->thread, NULL))
		return ((void *)1);
	return ((void *)0);
}

int	initialize_threads(t_data *data)
{
	int			i;
	pthread_t	t0;

	i = -1;
	data->start_time = get_current_time();
	if (data->nb_of_meals > 0)
	{
		if (pthread_create(&t0, NULL, &check_completion, &data->philos[0]))
			return (error(TH_ERR, data));
	}
	while (++i < data->nb_of_philos)
	{
		if (pthread_create(&data->thread_ids[i], NULL, &philosopher_behavior, &data->philos[i]))
			return (error(TH_ERR, data));
		controlled_sleep(1);
	}
	i = -1;
	while (++i < data->nb_of_philos)
	{
		if (pthread_join(data->thread_ids[i], NULL))
			return (error(JOIN_ERR, data));
	}
	return (0);
}
