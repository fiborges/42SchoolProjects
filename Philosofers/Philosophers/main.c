#include "include/philo.h"
# include <pthread.h>

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
		return (1);
	if (validate_numeric_arguments(argv))
		return (1);
	if (initialize_simulation(&data, argv, argc))
		return (1);
	if (data.nb_of_philos == 1)
		return (single_philosopher_simulation(&data));
	if (initialize_threads(&data))
		return (1);
	exit_program(&data);
	return (0);
}
