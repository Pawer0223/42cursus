#include "philo.h"

void	logging(t_philo *philo, int act)
{
	long long timestamp;
	char *message;

	if (act == ACT_EAT)
	{
		pthread_mutex_lock(&philo->philo_status);
		timestamp = philo->last_time - philo->common->start;
		pthread_mutex_unlock(&philo->philo_status);
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
	pthread_mutex_lock(&philo->common->finish_mutex);
	if (!philo->common->is_finish)
		printf("%lld\t%d\t%s\n", timestamp, philo->seq, message);
	pthread_mutex_unlock(&philo->common->finish_mutex);
}

void	change_status(t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_status);
	philo->last_time = get_curr_time();
	if (philo->common->time_each_must_eat != -1)
		philo->eat_cnt++;
	if (philo->eat_cnt == philo->common->time_each_must_eat)
		philo->common->must_eat_cnt++;
	pthread_mutex_unlock(&philo->philo_status);
	pthread_mutex_lock(&philo->common->finish_mutex);
	if (philo->common->must_eat_cnt == philo->common->num_of_philo)
		philo->common->is_finish = 1;
	pthread_mutex_unlock(&philo->common->finish_mutex);
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
		change_status(philo);
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
