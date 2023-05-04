#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_p		p;

	if (!(parse_args(argc, argv, &p)))
		return (ft_exit("Invalid Arguments\n"));
	p.ph = malloc(sizeof(t_philo) * p.a.total);
	if (!p.ph)
		return (ft_exit("MALLOC ERROR\n"));
	if (!initialize(&p) || !threading(&p))
	{
		free(p.ph);
		return (0);
	}
	stop(&p);
}
