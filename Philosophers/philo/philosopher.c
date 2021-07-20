#include "philo.h"

int	done(t_philo *philo)
{
	int r;
	r = 0;
	pthread_mutex_lock(&philo->common->finish_mutex);
	if (philo->common->is_finish)
		r = 1;
	pthread_mutex_unlock(&philo->common->finish_mutex);
	return (r);
}

void	logging(t_philo *philo, int act)
{
	long long timestamp;
	char *message;

	if (done(philo))
		return ;
	if (act == ACT_EAT)
	{
		pthread_mutex_lock(&philo->last_time_mutex);
		timestamp = philo->last_time - philo->common->start;
		pthread_mutex_unlock(&philo->last_time_mutex);
	}
	else
		timestamp = get_curr_time() - philo->common->start;
	if (act == ACT_TAKE)
		message = PRINT_TAKE;
	else if (act == ACT_EAT)
		message = PRINT_EAT;
	else if (act == ACT_SLEEP)
		message = PRINT_SLEEP;
	else if (act == ACT_THINK)
		message= PRINT_THINK;
	printf("%lld\t%d\t%s\n", timestamp, philo->seq, message);
}

void	acting(t_philo *philo, int act)
{
	if (act == ACT_TAKE)
	{
		pthread_mutex_lock(philo->left);
		pthread_mutex_lock(philo->right);
		logging(philo, act);
	}
	else if (act == ACT_EAT)
	{
		pthread_mutex_lock(&philo->last_time_mutex);
		philo->last_time = get_curr_time();
		pthread_mutex_unlock(&philo->last_time_mutex);
		logging(philo, act);
		usleep(philo->common->time_to_eat * MS);
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
	}
	else
		logging(philo, act);
	if (act == ACT_SLEEP)
		usleep(philo->common->time_to_sleep * MS);
}

void	*philosopher(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (philo->seq % 2 != 0)
		usleep(philo->common->time_to_eat * MS);
	while (!philo->common->is_finish)
	{
		acting(philo, ACT_TAKE);
		acting(philo, ACT_EAT);
		acting(philo, ACT_SLEEP);
		acting(philo, ACT_THINK);
	}
	return (0);
} 


