#include "philo.h"

int	done(t_philo *philo)
{
	pthread_mutex_lock(&philo->common.finish_mutex);
	if (philo->common.is_finish)
		return (1);
	pthread_mutex_unlock(&philo->common.finish_mutex);
	return (0);
}

int	logging(t_philo *philo, int act)
{
	long long timestamp;
	char *message;

	if (done(philo))
		return (0);
	if (act == ACT_TAKE)
		timestamp = philo->last_time - philo->common.start;
	else
		timestamp = get_curr_time() - philo->common.start;
	if (act == ACT_TAKE)
		message = PRINT_TAKE;
	else if (act == ACT_EAT)
		message = PRINT_EAT;
	else if (act == ACT_SLEEP)
		message = PRINT_SLEEP;
	else if (act == ACT_THINK)
		message= PRINT_THINK;
	printf("%lld\t%d\t%s\n", timestamp, philo->seq, message);
	return (1);
}

int	acting(t_philo *philo, int act)
{
	if (done(philo))
		return (0);
	if (act == ACT_TAKE)
	{
		pthread_mutex_lock(philo->left);
		pthread_mutex_lock(philo->right);
		philo->last_time = get_curr_time();
		logging(philo, act);
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
	}
	else
	{
		if (!logging(philo, act))
			return (0);
		if (act == ACT_EAT)
			usleep(philo->common.time_to_eat * MS);
		else if (act == ACT_SLEEP)
			usleep(philo->common.time_to_sleep * MS);
	}
	return (1);	
}

void	*philosopher(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (philo->seq % 2 == 0)
		usleep(philo->common.time_to_eat * MS);
	while (1)
	{
		if (!acting(philo, ACT_TAKE))
			return (0);
		if (!acting(philo, ACT_EAT))
			return (0);
		if (!acting(philo, ACT_SLEEP))
			return (0);
		if (!acting(philo, ACT_THINK))
			return (0);
	}
	return (0);
} 


