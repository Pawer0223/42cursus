#include "philo.h"

int		set_fork(t_philo *philos, int cnt)
{
	int				i;
	pthread_mutex_t	*forks;

	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * cnt);
	if (!forks)
		return (0);
	philos = (t_philo *)malloc(sizeof(t_philo) * cnt);
	if (!philos)
		return (0);
	i = 0;
	while (i < cnt)
		pthread_mutex_init(&forks[i++], NULL);
	i = 0;
	while (i < cnt)
	{
		philos[i].left = &forks[i];
		philos[i].right = &forks[(i + 1) % cnt];
		i++;
	}
	return (1);
}

int		main(int argc, char *argv[])
{
	t_param			common;
	t_philo			*philos;
	
	if (argc < 5)
		return (error_occur(PARAM_ERROR));
	// param error
	if (!init_param(&common, argv))
		return (error_occur(PARAM_ERROR));
	// set fork
	if (!set_fork(philos, common.num_of_philo))
		return (error_occur(MALLOC_ERROR));
	
	
	// destroy fork -> pthread_mutex_destroy(philo[i].left);


	return (0);
}