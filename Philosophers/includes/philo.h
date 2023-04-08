#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define RESET "\033[0m"

# ifndef T_FORK
#  define T_FORK

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	int				is_held;
}	t_fork;

# endif

# ifndef T_PHILO
#  define T_PHILO

typedef struct s_philo
{
	long long		start;
	int				nb;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				to_eat;
	int				sim;
	long long		*since_eat;
	long long		*since_change;
	int				*turn;
	int				*status;
	int				*eat_times;
	int				turn_count;
	pthread_mutex_t	waiter;
	t_fork			**forks;
}	t_philo;

# endif

# ifndef T_INDEXED
#  define T_INDEXED

typedef struct s_indexed
{
	int		index;
	t_philo	*philo;
}	t_indexed;

# endif

enum
{
	THINK = 0,
	EAT	= 1,
	DEATH = 2,
	FORK = 3,
	SLEEP = 4
};

int			ft_atoi(const char *str);
void		*ft_state(void *idx);
long long	now(void);
void		message(int index, t_philo *philo, int status);
void		ft_bzero(void *s, size_t n);
void		turn_update(t_philo *philo);
void		*ft_calloc(size_t count, size_t size);
void		check_eaten_time(t_philo *philo);
void		dinner(t_philo *philo);

#endif
