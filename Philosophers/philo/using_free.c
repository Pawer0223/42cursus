/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 01:32:00 by taesan            #+#    #+#             */
/*   Updated: 2021/07/20 17:59:03 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	clear_data(t_program_data data)
{
	int	i;

	i = 0;
	while (i < data.common.num_of_philo)
	{
		pthread_mutex_destroy(&data.forks[i]);
		pthread_mutex_destroy(&data.philos[i].last_time_mutex);
		i++;
	}
	pthread_mutex_destroy(&data.common.finish_mutex);
	if (data.forks)
		free(data.forks);
	if (data.philos)
		free(data.philos);
	if (data.threads)
		free(data.threads);
	data.forks = 0;
	data.philos = 0;
	data.threads = 0;
	return (0);
}