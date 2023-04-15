#include "../include/philo.h"

int	single_philosopher_simulation(t_data *data)
{
	data->start_time = get_current_time();
	if (pthread_create(&data->thread_ids[0], NULL, &philosopher_behavior, &data->philos[0]))
		return (error(TH_ERR, data));
	pthread_detach(data->thread_ids[0]);
	while (data->is_dead == 0)
		controlled_sleep(0);
	exit_program(data);
	return (0);
}

void	clear_data(t_data	*data)
{
	if (data->thread_ids)
		free(data->thread_ids);
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
}

void	exit_program(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_of_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].lock);
	}
	pthread_mutex_destroy(&data->write_mutex);
	pthread_mutex_destroy(&data->lock);
	clear_data(data);
}

int	error(char *str, t_data *data)
{
	printf("\033[31m%s\033[0m\n", str);
	if (data)
		exit_program(data);
	return (1);
}