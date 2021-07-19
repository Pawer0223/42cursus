/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 01:32:00 by taesan            #+#    #+#             */
/*   Updated: 2021/07/19 22:12:55 by taesan           ###   ########.fr       */
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