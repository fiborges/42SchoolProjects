#ifndef PHILO_H
# define PHILO_H

/*
**COLORS
*/

//Bold high intensity text
# define BHBLACK   "\001\e[1;90m\002"
# define BHRED     "\001\e[1;91m\002"
# define BHGREEN   "\001\e[1;92m\002"
# define BHYELLOW  "\001\e[1;93m\002"
# define BHBLUE    "\001\e[1;94m\002"
# define BHMAGENTA "\001\e[1;95m\002"
# define BHCYAN    "\001\e[1;96m\002"
# define BHWHITE   "\001\e[1;97m\002"

//Reset
# define RESET       "\001\e[0m\002"
# define CRESET      "\001\e[0m\002"
# define COLOR_RESET "\001\e[0m\002"

/*
** libraries
*/

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

/*
** structers
*/

typedef struct s_arg
{
	int						total;
	int						die;
	int						eat;
	int						sleep;
	int						m_eat;
	long int				start_t;
	pthread_mutex_t			write_mutex;
	pthread_mutex_t			dead;
	pthread_mutex_t			time_eat;
	pthread_mutex_t			finish;
	int						nb_p_finish;
	int						stop;
}							t_arg;

typedef struct s_philo
{
	int						id;
	pthread_t				thread_id;
	pthread_t				thread_death_id;
	pthread_mutex_t			*r_f;
	pthread_mutex_t			l_f;
	t_arg					*pa;
	long int				ms_eat;
	unsigned int			nb_eat;
	int						finish;
}							t_philo;

typedef struct s_p
{
	t_philo					*ph;
	t_arg					a;
}							t_p;

/*
** functions
*/

int				parse_args(int argc, char **argv, t_p *p);
int				initialize(t_p *p);
int				ft_exit(char *str);
void			write_status(char *str, t_philo *ph, char *color);
long int		actual_time(void);
int				ft_exit(char *str);
int				check_death2(t_p *p);
void			stop(t_p *p);
void			ft_putstr_fd(char *s, int fd);
void			ft_usleep(long int time_in_ms);
int				threading(t_p *p);
void			activity(t_philo *ph);
int				check_death(t_philo *ph, int i);
int				ft_strlen(char *str);

#endif