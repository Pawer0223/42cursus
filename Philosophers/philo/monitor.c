/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 04:18:19 by taesan            #+#    #+#             */
/*   Updated: 2021/07/24 02:48:51 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *arg)
{
	t_philo		*philo;
	long long	wait_time;
	long long	curr;
	long long	timestamp;

	philo = (t_philo *)arg;
	while (!philo->common->is_finish)
	{
		pthread_mutex_lock(&philo->philo_status);
		pthread_mutex_lock(&philo->common->finish_mutex);
		curr = get_curr_time();
		wait_time = curr - philo->last_time;
		if (wait_time >= philo->common->time_to_die \
			 && !philo->common->is_finish)
		{
			philo->common->is_finish = 1;
			timestamp = curr - philo->common->start;
			printf("%lld\t%d\t%s\n", timestamp, philo->seq, PRINT_DIE);
			if (philo->common->num_of_philo == 1)
				pthread_mutex_unlock(philo->left);
		}
		pthread_mutex_unlock(&philo->common->finish_mutex);
		pthread_mutex_unlock(&philo->philo_status);
	}
	return (0);
}
