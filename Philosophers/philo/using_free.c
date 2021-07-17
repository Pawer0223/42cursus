#include "philo.h"

void	clear_philo(t_philo *p)
{
	if (!p)
		return ;
	if (p->common)
	{
		free(p->common);
		p->common = 0;
	}
	ft_bzero(p, sizeof(p));
	free(p);
	p = 0;
}

void	clear_fork(pthread_mutex_t *fork)
{
	if (fork)
	{
		pthread_mutex_destroy(fork);
		free(fork);
	}
	fork = 0;
}

void	clear_thread(pthread_t *thread)
{
	if (thread)
		free(thread);
	thread = 0;
}

int	clear_data(t_program_data data, int end)
{
	int	i;

	i = 0;
	while (i < end)
	{
		clear_philo(data.philos[i]);
		clear_fork(data.forks[i]);
		clear_thread(data.threads[i]);
		i++;
	}
	if (data.philos)
		free(data.philos);
	if (data.forks)
		free(data.forks);
	if (data.threads)
		free(data.threads);
	data.philos = 0;
	data.forks = 0;
	data.threads = 0;
	return (0);
}