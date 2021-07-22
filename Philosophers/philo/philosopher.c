#include "philo.h"

void	print_log(t_philo *philo, long long timestamp, char *message)
{
	pthread_mutex_lock(&philo->common->finish_mutex);
	if (!philo->common->is_finish)
		printf("%lld\t%d\t%s\n", timestamp, philo->seq, message);
	pthread_mutex_unlock(&philo->common->finish_mutex);
}

long long	logging(t_philo *philo, int act)
{
	long long	timestamp;
	long long	curr;

	curr = get_curr_time();
	if (act == ACT_EAT)
	{
		pthread_mutex_lock(&philo->philo_status);
		timestamp = philo->last_time - philo->common->start;
		curr = philo->last_time;
		pthread_mutex_unlock(&philo->philo_status);
	}
	else
		timestamp = curr - philo->common->start;
	if (act == ACT_TAKE)
		print_log(philo, timestamp, PRINT_TAKE);
	else if (act == ACT_EAT)
		print_log(philo, timestamp, PRINT_EAT);
	else if (act == ACT_SLEEP)
		print_log(philo, timestamp, PRINT_SLEEP);
	else if (act == ACT_THINK)
		print_log(philo, timestamp, PRINT_THINK);
	return (curr);
}

void	change_status(t_philo *philo)
{
	long long	curr;
	long long	timestamp;

	pthread_mutex_lock(&philo->philo_status);
	curr = get_curr_time();
	philo->last_time = curr;
	if (philo->common->time_each_must_eat != -1)
		philo->eat_cnt++;
	if (philo->eat_cnt == philo->common->time_each_must_eat)
		philo->common->must_eat_cnt++;
	pthread_mutex_lock(&philo->common->finish_mutex);
	if (philo->common->must_eat_cnt == philo->common->num_of_philo)
	{
		timestamp = curr - philo->common->start;
		printf("%lld\t%d\t%s\n", timestamp, philo->seq, PRINT_EAT);
		philo->common->is_finish = 1;
	}
	pthread_mutex_unlock(&philo->common->finish_mutex);
	pthread_mutex_unlock(&philo->philo_status);
}

void	acting(t_philo *philo, int act)
{
	long long	sleep_end_time;
	long long	curr;

	if (act == ACT_TAKE)
	{
		pthread_mutex_lock(philo->left);
		pthread_mutex_lock(philo->right);
		logging(philo, act);
	}
	else if (act == ACT_EAT)
	{
		change_status(philo);
		curr = logging(philo, act);
		sleep_end_time = curr + philo->common->time_to_eat;
		ft_usleep(sleep_end_time);
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
	}
	else
		sleep_end_time = logging(philo, act) + philo->common->time_to_sleep;
	if (act == ACT_SLEEP)
		ft_usleep(sleep_end_time);
}

void	*philosopher(void *arg)
{
	t_philo	*philo;

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
