#include "../include/philo.h"

void	write_status(char *str, t_philo *ph, char *color)
{
	long int		time;

	time = -1;
	time = actual_time() - ph->pa->start_t;
	if (time >= 0 && time <= 2147483647 && !check_death(ph, 0))
	{
		printf("%ld ", time);
		printf("Philo %d %s%s%s", ph->id, color, str, COLOR_RESET);
	}
}

void	sleep_think(t_philo *ph)
{
	pthread_mutex_lock(&ph->pa->write_mutex);
	write_status("is sleeping\n", ph, BHMAGENTA);
	pthread_mutex_unlock(&ph->pa->write_mutex);
	ft_usleep(ph->pa->sleep);
	pthread_mutex_lock(&ph->pa->write_mutex);
	write_status("is thinking\n", ph, BHCYAN);
	pthread_mutex_unlock(&ph->pa->write_mutex);
}

void    activity(t_philo *ph)
{
    pthread_mutex_lock(&ph->l_f);
    pthread_mutex_lock(ph->r_f);
    pthread_mutex_lock(&ph->pa->write_mutex);

    write_status("has taken a fork\n", ph, BHYELLOW);
    write_status("has taken a fork\n", ph, BHBLUE);

    write_status("is eating\n", ph, BHGREEN);
    pthread_mutex_lock(&ph->pa->time_eat);
    ph->ms_eat = actual_time();
    pthread_mutex_unlock(&ph->pa->time_eat);

    pthread_mutex_unlock(&ph->pa->write_mutex);
    ft_usleep(ph->pa->eat);
    pthread_mutex_unlock(ph->r_f);
    pthread_mutex_unlock(&ph->l_f);

    sleep_think(ph);
}
