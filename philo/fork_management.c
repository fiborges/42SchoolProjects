#include "philo.h"

void	get_left_fork(t_philo *philo, time_t time)
{
	pthread_mutex_lock(philo->l_fork);
	if (has_philosopher_finished(philo))
		return ;
	time = (get_time_in_ms()) - philo->data->start_time;
	pthread_mutex_lock(&philo->data->printf_mutex);
	//printf("%ld Philosopher %u has taken a fork\n", time, philo->id);
	printf("\033[1;33m%ld Philosopher %u has taken a left fork\033[0m\n", time, philo->id);
	pthread_mutex_unlock(&philo->data->printf_mutex);
	if (has_philosopher_finished(philo))
		return ;
}

void	get_right_fork(t_philo *philo, time_t time)
{
	pthread_mutex_lock(philo->r_fork);
	if (has_philosopher_finished(philo))
		return ;
	time = (get_time_in_ms()) - philo->data->start_time;
	pthread_mutex_lock(&philo->data->printf_mutex);
	//printf("%ld Philosopher %u has taken a fork\n", time, philo->id);
	printf("\033[1;35m%ld Philosopher %u has taken a right fork\033[0m\n", time, philo->id);
	pthread_mutex_unlock(&philo->data->printf_mutex);
	if (has_philosopher_finished(philo))
		return ;
}

void	get_last_meal(t_philo *philos, time_t *time, time_t *meal, int i)
{
	*time = (get_time_in_ms()) - philos->data->start_time;
	pthread_mutex_lock(&philos->data->meal_mutex);
	*meal = philos[i].last_meal;
	pthread_mutex_unlock(&philos->data->meal_mutex);
}

void	print_philosopher_death(t_philo *philos, time_t time)
{
	pthread_mutex_lock(&philos->data->printf_mutex);
	//printf("%ld Philosopher %u died\n", time, philos->id);
	printf("\033[1;31m%ld Philosopher %u died\033[0m\n", time, philos->id);
	pthread_mutex_unlock(&philos->data->printf_mutex);
}
