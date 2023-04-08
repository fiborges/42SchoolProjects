#include "../includes/philo.h"

long long	now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	message(int index, t_philo *philo, int status)
{
	int display_index;
	
	display_index = index + 1;
	if (status == THINK)
		printf("%s Time: %lld Philosopher n* %d is Thinking%s\n", CYAN, now() - philo->start, display_index, RESET);
	else if (status == EAT)
		printf("%s Time: %lld Philosopher n* %d is Eating%s\n", GREEN, now() - philo->start, display_index, RESET);
	else if (status == DEATH)
		printf("%s Time: %lld Philosopher n* %d DIED %s\n", RED, now() - philo->start, display_index, RESET);
	else if (status == FORK)
		printf("%s Time: %lld Philosopher n* %d Has Taken a Fork%s\n", YELLOW, now() - philo->start, display_index, RESET);
	else if (status == SLEEP)
		printf("%s Time: %lld Philosopher n* %d Is Sleeping%s\n", MAGENTA, now() - philo->start, display_index, RESET);
}


void	turn_update(t_philo *philo)
{
	int	i;
	int	last;
	int	eat_late;

	eat_late = 1;
	i = 0;
	while (i < philo->nb)
		eat_late &= (philo->status[i++] != EAT);
	if (eat_late)
	{
		i = philo->nb - 1;
		last = philo->turn[i];
		while (i >= 1)
		{
			philo->turn[i] = philo->turn[i - 1];
			i--;
		}
		philo->turn[0] = last;
	}
}
