#include "philo.h"

int	clear_data(t_program_data data)
{
	int	i;

	i = 0;
	while (i < data.common.num_of_philo)
	{
		pthread_mutex_destroy(&data.forks[i]);
		pthread_mutex_destroy(&data.philos[i].philo_status);
		i++;
	}
	pthread_mutex_destroy(&data.common.finish_mutex);
	if (data.forks)
		free(data.forks);
	if (data.philos)
		free(data.philos);
	if (data.threads)
		free(data.threads);
	data.forks = 0;
	data.philos = 0;
	data.threads = 0;
	return (0);
}

void	make_thread(t_program_data data, int cnt)
{
	int	i;
	pthread_t monitor_th;

	i = 0;
	while (i < cnt)
	{
		pthread_create(&data.threads[i], NULL, philosopher, &data.philos[i]);
		pthread_create(&monitor_th, NULL, monitor, &data.philos[i]);
		pthread_detach(monitor_th);
		i++;
	}
	i = 0;
	while (i < cnt)
		pthread_join(data.threads[i++], NULL);
}

int	main(int argc, char *argv[])
{
	t_program_data	data;

	memset(&data, 0, sizeof(data));
	if (argc == 5 || argc == 6)
	{
		if (!init(&data, argv))
			return (0);
		make_thread(data, data.common.num_of_philo);
		clear_data(data);
	}
	else
		return (error_occur(PARAM_ERROR));
	return (0);
}