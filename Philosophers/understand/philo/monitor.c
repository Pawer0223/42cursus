/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 04:18:19 by taesan            #+#    #+#             */
/*   Updated: 2021/07/28 02:40:57 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		over_time(t_philo *philo, long long curr)
{
	long long	wait_time;

	wait_time = curr - philo->last_time;
	if (wait_time >= philo->common->time_to_die)
	{
		if (philo->common->num_of_philo == 1)
			pthread_mutex_unlock(philo->left);
		return (1);
	}
	return (0);
}

int		all_must_eat(t_philo *philo)
{
	if (philo->common->must_eat_cnt == -1)
		return (0);
	if (philo->common->must_eat_cnt == philo->common->num_of_philo)
		return (1);
	return (0);
}

void	*monitor(void *arg)
{
	t_philo		*philo;
	long long	curr;
	long long	timestamp;

	philo = (t_philo *)arg;
	while (!philo->common->is_finish)
	{
		pthread_mutex_lock(&philo->philo_status);
		curr = get_curr_time();
		timestamp = curr - philo->start;
		pthread_mutex_lock(&philo->common->finish_mutex);
		if (!philo->common->is_finish && (over_time(philo, curr) || all_must_eat(philo)))
		{
			philo->common->is_finish = 1;
			printf("%lld\t%d\t%s\n", timestamp, philo->seq, PRINT_DIE);
		}
		pthread_mutex_unlock(&philo->common->finish_mutex);
		pthread_mutex_unlock(&philo->philo_status);
		usleep(1000);
	}
	return (0);
}
