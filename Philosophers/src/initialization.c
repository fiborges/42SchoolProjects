#include "../include/philo.h"

int	allocate_memory(t_data *data)
{
	data->thread_ids = malloc(sizeof(pthread_t) * data->nb_of_philos);
	if (!data->thread_ids)
		return (error(ALLOC_ERR_1, data));
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_of_philos);
	if (!data->forks)
		return (error(ALLOC_ERR_2, data));
	data->philos = malloc(sizeof(t_philo) * data->nb_of_philos);
	if (!data->philos)
		return (error(ALLOC_ERR_3, data));
	return (0);
}

int	initialize_forks(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_of_philos)
		pthread_mutex_init(&data->forks[i], NULL);
	i = 0;
	data->philos[0].left_fork = &data->forks[0];
	data->philos[0].right_fork = &data->forks[data->nb_of_philos - 1];
	i = 1;
	while (i < data->nb_of_philos)
	{
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[i - 1];
		i++;
	}
	return (0);
}

void	initialize_philosophers(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_of_philos)
	{
		data->philos[i].data = data;
		data->philos[i].id = i + 1;
		data->philos[i].time_to_die = data->death_time;
		data->philos[i].meals_eaten = 0;
		data->philos[i].is_eating = 0;
		data->philos[i].is_alive = 0;
		pthread_mutex_init(&data->philos[i].lock, NULL);
		i++;
	}
}

int	initialize_data(t_data *data, char **argv, int argc)
{
	data->nb_of_philos = (int) ft_atoi(argv[1]);
	data->death_time = (u_int64_t) ft_atoi(argv[2]);
	data->time_to_eat= (u_int64_t) ft_atoi(argv[3]);
	data->time_to_sleep = (u_int64_t) ft_atoi(argv[4]);
	if (argc == 6)
		data->nb_of_meals = (int) ft_atoi(argv[5]);
	else
		data->nb_of_meals = -1;
	if (data->nb_of_philos <= 0 || data->nb_of_philos > 200 || data->death_time < 0
		|| data->time_to_eat < 0 || data->time_to_sleep < 0)
		return (error(ERR_IN_2, NULL));
	data->is_dead = 0;
	data->finished = 0;
	pthread_mutex_init(&data->write_mutex, NULL);
	pthread_mutex_init(&data->lock, NULL);
	return (0);
}

int	initialize_simulation(t_data *data, char **argv, int argc)
{
	if (initialize_data(data, argv, argc))
		return (1);
	if (allocate_memory(data))
		return (1);
	if (initialize_forks(data))
		return (1);
	initialize_philosophers(data);
	return (0);
}
