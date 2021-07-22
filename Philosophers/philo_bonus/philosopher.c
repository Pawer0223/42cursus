#include "philo.h"

void	print_log(t_philo *philo, long long timestamp, char *message)
{
	printf("%lld\t%d\t%s\n", timestamp, philo->seq, message);
}

long long	logging(t_philo *philo, int act)
{
	long long	timestamp;
	long long	curr;

	curr = get_curr_time();
	if (act == ACT_EAT)
	{
		sem_wait(philo->status);
		timestamp = philo->last_time - philo->common->start;
		curr = philo->last_time;
		sem_post(philo->status);
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

	sem_wait(philo->status);
	curr = get_curr_time();
	philo->last_time = curr;
	sem_post(philo->status);
	if (philo->common->time_each_must_eat != -1)
		philo->eat_cnt++;
	if (philo->eat_cnt == philo->common->time_each_must_eat)
		sem_post(philo->common->muset_eat_sem);
}

void	acting(t_philo *philo, int act)
{
	long long	sleep_end_time;
	long long	curr;

	if (act == ACT_TAKE)
	{
		sem_wait(philo->common->forks);
		sem_wait(philo->common->forks);
		logging(philo, act);
	}
	else if (act == ACT_EAT)
	{
		change_status(philo);
		curr = logging(philo, act);
		sleep_end_time = curr + philo->common->time_to_eat;
		ft_usleep(sleep_end_time);
		sem_post(philo->common->forks);
		sem_post(philo->common->forks);
	}
	else
		sleep_end_time = logging(philo, act) + philo->common->time_to_sleep;
	if (act == ACT_SLEEP)
		ft_usleep(sleep_end_time);
}

void	philosopher(t_philo *philo)
{
	pthread_t	monitor_th;

	pthread_create(&monitor_th, NULL, monitor, philo);
	if (philo->seq % 2 != 0)
		usleep(philo->common->time_to_eat * MS);
	while (1)
	{
		acting(philo, ACT_TAKE);
		acting(philo, ACT_EAT);
		acting(philo, ACT_SLEEP);
		acting(philo, ACT_THINK);
	}
	exit(0);
}
