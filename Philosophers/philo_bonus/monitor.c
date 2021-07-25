/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 04:18:19 by taesan            #+#    #+#             */
/*   Updated: 2021/07/23 02:49:43 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*must_eat_monitor(void *arg)
{
	t_program_data	*data;
	int				i;

	data = (t_program_data *)arg;
	i = 0;
	while (i < data->common.num_of_philo)
	{
		sem_wait(data->common.must_eat_sem);
		i++;
	}
	sem_post(data->common.finish_sem);
	return (0);
}

void	*philosopher_died(void *arg)
{
	t_program_data	*data;
	int				i;

	data = (t_program_data *)arg;
	sem_wait(data->common.finish_sem);
	i = 0;
	while (i < data->common.num_of_philo)
		kill(data->philos[i++].pid, SIGINT);
	return (0);
}

void	*monitor(void *arg)
{
	t_philo		*philo;
	long long	wait_time;
	long long	curr;
	long long	timestamp;

	philo = (t_philo *)arg;
	while (1)
	{
		sem_wait(philo->status);
		curr = get_curr_time();
		wait_time = curr - philo->last_time;
		if (wait_time >= philo->common->time_to_die)
		{
			timestamp = curr - philo->common->start;
			printf("%lld\t%d\t%s\n", timestamp, philo->seq, PRINT_DIE);
			sem_post(philo->common->finish_sem);
			return (0);
		}
		sem_post(philo->status);
	}
	return (0);
}