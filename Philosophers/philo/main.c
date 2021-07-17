#include "philo.h"

int	make_thread(t_philo **philos, pthread_t	**threads, t_param common)
{
	int	i;

	i = 0;
	while (i < common.num_of_philo)
	{
		threads[i] = (pthread_t *)malloc(sizeof(pthread_t));
		printf("philos[%d]->seq : %d\n", i, philos[i]->seq);
		pthread_create(threads[i], NULL, thread_main, philos[i]);
		i++;
	}

	i = 0;
	while (i < common.num_of_philo)
		pthread_join(*threads[i++], NULL);
	return (1);
	
}

int	main(int argc, char *argv[])
{
	t_param	common;
	t_philo	**philos;
	pthread_mutex_t **forks;
	pthread_t	**threads;
	int			i;

	if (argc < 5)
		return (error_occur(PARAM_ERROR));
	// param error
	if (!init_param(&common, argv))
		return (error_occur(PARAM_ERROR));


	philos = (t_philo **)malloc(sizeof(t_philo *) * common.num_of_philo);
	if (!philos)
		return (error_occur(MALLOC_ERROR));
	forks = (pthread_mutex_t **)malloc(sizeof(pthread_mutex_t *) * common.num_of_philo);
	if (!forks)
	{
		free(philos);
		return (error_occur(MALLOC_ERROR));
	}
	threads = (pthread_t **)malloc(sizeof(pthread_t *) * common.num_of_philo);
	if (!threads)
		return (0);
	// set fork
	if (!init_philos(philos, forks, common))
		return (error_occur(MALLOC_ERROR));
	// make thread
	if (!make_thread(philos, threads, common))
		return (error_occur(MALLOC_ERROR));
	// to_string_common(common);
	// destroy fork -> pthread_mutex_destroy(philo[i].left);
	clear_data(philos, forks, threads, common.num_of_philo);


	return (0);
}