#include "../includes/philo.h"

void	check_eaten_time(t_philo *philo)
{
	int	all_philo_eat;
	int	i;

	all_philo_eat = 1;
	i = 0;
	while (i < philo->nb)
		all_philo_eat &= (philo->eat_times[i++] >= philo->to_eat);
	if (all_philo_eat)
		philo->sim = 0;
}

void	dinner(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->nb / 2)
		philo->turn[2 * i++] = 1;
}
