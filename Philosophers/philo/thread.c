#include "philo.h"

void	*thread_main(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	printf("Thread %d\n", philo->seq);
	
	return (0);
}